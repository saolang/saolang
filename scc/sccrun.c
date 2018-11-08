#include "scc.h"

/* only native compiler supports -run */
#ifdef SCC_IS_NATIVE

//TODO redo the backtrace again...
//using debug backtrace trick for the scc-run
#include "sccrun_debug_bt.c"

static void set_pages_executable(void *ptr, unsigned long length);
static int scc_relocate_ex(SCCState *s1, void *ptr, addr_t ptr_diff);

#ifdef _WIN64
static void *win64_add_function_table(SCCState *s1);
static void win64_del_function_table(void *);
#endif

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using scc_get_symbol())
   Returns -1 on error. */
//@ref scc_run()
LIBSCCAPI int scc_relocate(SCCState *s1, void *ptr)
{
    int size;
    addr_t ptr_diff = 0;

    if (SCC_RELOCATE_AUTO != ptr)
        return scc_relocate_ex(s1, ptr, 0);

    size = scc_relocate_ex(s1, NULL, 0);
    if (size < 0)
        return -1;

#ifdef HAVE_SELINUX
{
    /* Using mmap instead of malloc */
    void *prx;
    char tmpfname[] = "/tmp/.sccrunXXXXXX";
    int fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap (NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    prx = mmap (NULL, size, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED || prx == MAP_FAILED)
	scc_error("sccrun: could not map memory");
    dynarray_add(&s1->runtime_mem, &s1->nb_runtime_mem, (void*)(addr_t)size);
    dynarray_add(&s1->runtime_mem, &s1->nb_runtime_mem, prx);
    ptr_diff = (char*)prx - (char*)ptr;
}
#else
    ptr = scc_malloc(size);
#endif
    scc_relocate_ex(s1, ptr, ptr_diff); /* no more errors expected */
    dynarray_add(&s1->runtime_mem, &s1->nb_runtime_mem, ptr);
    return 0;
}

//@ref scc_delete()
ST_FUNC void scc_run_free(SCCState *s1)
{
    int i;

    for (i = 0; i < s1->nb_runtime_mem; ++i) {
#ifdef HAVE_SELINUX
        unsigned size = (unsigned)(addr_t)s1->runtime_mem[i++];
        munmap(s1->runtime_mem[i++], size);
        munmap(s1->runtime_mem[i], size);
#else
#ifdef _WIN64
        win64_del_function_table(*(void**)s1->runtime_mem[i]);
#endif
        scc_free(s1->runtime_mem[i]);
#endif
    }
    scc_free(s1->runtime_mem);
}

/* launch the compiled program with the given arguments */
//@ref scc.c::main()
LIBSCCAPI int scc_run(SCCState *s1, int argc, char **argv)
{
    int (*prog_main)(int, char **);

    s1->runtime_main = "main";
    if ((s1->dflag & 16) && !find_elf_sym(s1->symtab, s1->runtime_main))
        return 0;
    if (scc_relocate(s1, SCC_RELOCATE_AUTO) < 0)
        return -1;
    prog_main = scc_get_symbol_err(s1, s1->runtime_main);

#ifdef CONFIG_SCC_BACKTRACE
    if (s1->do_debug) {
        set_exception_handler();
        rt_prog_main = prog_main;
    }
#endif

    //errno = 0; /* clean errno value */
		scc_errno(0);

    return (*prog_main)(argc, argv);
}

#if __SCC_TARGET_CPU_ID__==__SCC_CPU_X86__ //{
/* To avoid that x86 processors would reload cached instructions
	 each time when data is written in the near, we need to make
	 sure that code and data do not share the same 64 byte unit */
#define RUN_SECTION_ALIGNMENT 63
#else //}:{
#define RUN_SECTION_ALIGNMENT 0
#endif //}

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
//@ref scc_relocate()
static int scc_relocate_ex(SCCState *s1, void *ptr, addr_t ptr_diff)
{
	Section *s;
	unsigned offset, length, align, max_align, i, k, f;
	addr_t mem, addr;

	if (NULL == ptr) {
		s1->nb_errors = 0;
#ifdef SCC_TARGET_PE
		pe_output_file(s1, NULL);
#else
		scc_add_runtime(s1);
		resolve_common_syms(s1);
		build_got_entries(s1);
#endif
		if (s1->nb_errors)
			return -1;
	}

	offset = max_align = 0, mem = (addr_t)ptr;
#ifdef _WIN64
	offset += sizeof (void*); /* space for function_table pointer */
#endif
	for (k = 0; k < 2; ++k) {
		f = 0, addr = k ? mem : mem + ptr_diff;
		for(i = 1; i < s1->nb_sections; i++) {
			s = s1->sections[i];
			if (0 == (s->sh_flags & SHF_ALLOC))
				continue;
			if (k != !(s->sh_flags & SHF_EXECINSTR))
				continue;
			align = s->sh_addralign - 1;
			if (++f == 1 && align < RUN_SECTION_ALIGNMENT)
				align = RUN_SECTION_ALIGNMENT;
			if (max_align < align)
				max_align = align;
			offset += -(addr + offset) & align;
			s->sh_addr = mem ? addr + offset : 0;
			offset += s->data_offset;
#if 0
			if (mem)
				printf("%-16s %p  len %04x  align %2d\n",
						s->name, (void*)s->sh_addr, (unsigned)s->data_offset, align + 1);
#endif
		}
	}

	/* relocate symbols */
	relocate_syms(s1, s1->symtab, 1);
	if (s1->nb_errors)
		return -1;

	if (0 == mem)
		return offset + max_align;

#ifdef SCC_TARGET_PE
	s1->pe_imagebase = mem;
#endif

	/* relocate each section */
	for(i = 1; i < s1->nb_sections; i++) {
		s = s1->sections[i];
		if (s->reloc)
			relocate_section(s1, s);
	}
	relocate_plt(s1);

	for(i = 1; i < s1->nb_sections; i++) {
		s = s1->sections[i];
		if (0 == (s->sh_flags & SHF_ALLOC))
			continue;
		length = s->data_offset;
		ptr = (void*)s->sh_addr;
		if (s->sh_flags & SHF_EXECINSTR)
			ptr = (char*)ptr - ptr_diff;
		if (NULL == s->data || s->sh_type == SHT_NOBITS)
			SCC(memset)(ptr, 0, length);
		else
			SCC(memcpy)(ptr, s->data, length);
		/* mark executable sections as executable in memory */
		if (s->sh_flags & SHF_EXECINSTR)
			set_pages_executable((char*)ptr + ptr_diff, length);
	}

#ifdef _WIN64
	*(void**)mem = win64_add_function_table(s1);
#endif

	return 0;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

static void set_pages_executable(void *ptr, unsigned long length)
{
#ifdef _WIN32
    unsigned long old_protect;
    SCC(VirtualProtect)(ptr, length, 0x40//PAGE_EXECUTE_READWRITE
				, &old_protect);
#else
    void __clear_cache(void *beginning, void *end);
# ifndef HAVE_SELINUX
    addr_t start, end;
#  ifndef PAGESIZE
#   define PAGESIZE 4096
#  endif
    start = (addr_t)ptr & ~(PAGESIZE - 1);
    end = (addr_t)ptr + length;
    end = (end + PAGESIZE - 1) & ~(PAGESIZE - 1);
    if (SCC(mprotect,int)((void *)start, end - start, PROT_READ | PROT_WRITE | PROT_EXEC))
        scc_error("mprotect failed: did you mean to configure --with-selinux?");
# endif
# if defined SCC_TARGET_ARM || defined SCC_TARGET_ARM64
    __clear_cache(ptr, (char *)ptr + length);
# endif
#endif
}

#ifdef _WIN64
static void *win64_add_function_table(SCCState *s1)
{
    void *p = NULL;
    if (s1->uw_pdata) {
        p = (void*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / sizeof (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = NULL;
    }
    return p;
}

static void win64_del_function_table(void *p)
{
    if (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

/* ------------------------------------------------------------- */
#ifdef CONFIG_SCC_STATIC

/* dummy function for profiling */
ST_FUNC void *dlopen(const char *filename, int flag)
{
    return NULL;
}

ST_FUNC void dlclose(void *p)
{
}

ST_FUNC const char *dlerror(void)
{
    return "error";
}

typedef struct SCCSyms {
    char *str;
    void *ptr;
} SCCSyms;


/* add the symbol you want here if no dynamic linking is done */
static SCCSyms scc_syms[] = {
#if !defined(CONFIG_SCCBOOT)
#define SCCSYM(a) { #a, &a, },
    SCCSYM(printf)
    SCCSYM(fprintf)
    SCCSYM(fopen)
    SCCSYM(fclose)
#undef SCCSYM
#endif
    { NULL, NULL },
};

//TODO improve later.
ST_FUNC void *dlsym(void *handle, const char *symbol)
{
    SCCSyms *p;
    p = scc_syms;
    while (p->str != NULL) {
        if (!strcmp(p->str, symbol))
            return p->ptr;
        p++;
    }
    return NULL;
}

#endif /* CONFIG_SCC_STATIC */
#endif /* SCC_IS_NATIVE */
/* ------------------------------------------------------------- */
