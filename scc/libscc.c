#include "scc.h"

/********************************************************/
/* global variables */

/* use GNU C extensions */
ST_DATA int gnu_ext = 1;

/* use SaoCC extensions */
ST_DATA int scc_ext = 1;

/* XXX: get rid of this ASAP */
ST_DATA struct SCCState *scc_state;

static int nb_states;

/********************************************************/
#if ONE_SOURCE//{ONE_SOURCE

#include "sccpp.c"
#include "sccgen.c"
#include "sccrun.c"

//TEST
//#ifdef INCLIBSCC1
////SKIP
//#else
//#define INCLIBSCC1 1
//#include "lib/libscc1.c"
//#endif

#include "lib/libscc1.c"

////TODO X86-32-LNX //{
////#include "lib/alloca86.S"
//__asm__(
//".globl alloca\n"
//"alloca:\n"
//"    pop     edx\n"
//"    pop     eax\n"
//"    push    edx\n"
//"    push    edx\n"
//
////"    pop     %edx\n"
////"    pop     %eax\n"
////"    add     $3,%eax\n"
////"    and     $-4,%eax\n"
////"    jz      p3\n"
////"\n"
////#ifdef _WIN32
////"p1:\n"
////"    cmp     $4096,%eax\n"
////"    jbe     p2\n"
////"    test    %eax,-4096(%esp)\n"
////"    sub     $4096,%esp\n"
////"    sub     $4096,%eax\n"
////"    jmp p1\n"
////"p2:\n"
////#endif
////"    sub     %eax,%esp\n"
////"    mov     %esp,%eax\n"
////"p3:\n"
////"    push    %edx\n"
////"    push    %edx\n"
//"    ret\n"
//	 );
////TODO X86-32-LNX //}

#include SCC_QUOTE(gen-__SCC_TARGET_CPU__-__SCC_TARGET_CPU_BIT__-__SCC_TARGET_OS__-__SCC_TARGET_FORMAT__.c)
#include SCC_QUOTE(link-__SCC_TARGET_CPU__-__SCC_TARGET_CPU_BIT__-__SCC_TARGET_OS__-__SCC_TARGET_FORMAT__.c)
#include SCC_QUOTE(asm-__SCC_TARGET_CPU__-__SCC_TARGET_CPU_BIT__.c)
#include SCC_QUOTE(scc-__SCC_TARGET_FORMAT__.c)

#endif//}ONE_SOURCE

/********************************************************/
#include "sccasm.c"

#ifndef CONFIG_SCC_ASM//{
ST_FUNC void asm_instr(void)
{
    scc_error("inline asm() not supported for this arch yet "__SCC_TARGET_CPU__"-"__SCC_TARGET_CPU_BIT__"-"__SCC_TARGET_OS__"-"__SCC_TARGET_FORMAT__);//TODO add %s to show arch
}
ST_FUNC void asm_global_instr(void)
{
    scc_error("inline asm() not supported for this arch yet "__SCC_TARGET_CPU__"-"__SCC_TARGET_CPU_BIT__"-"__SCC_TARGET_OS__"-"__SCC_TARGET_FORMAT__);//TODO to show arch
}
#endif//}CONFIG_SCC_ASM

/********************************************************/
#ifdef _WIN32//{
ST_FUNC char *normalize_slashes(char *path)
{
		for (char *p = path; *p; ++p){
			if (*p == '\\') *p = '/';
		}
    return path;
}

static HMODULE scc_module;

//TODO 
///* on win32, we suppose the lib and includes are at the location of 'scc.exe' */
//static void scc_set_lib_path_w32(SCCState *s)
//{
//    char path[1024], *p;
//    GetModuleFileNameA(scc_module, path, sizeof path);
//    p = scc_basename(normalize_slashes(strlwr(path)));
//    if (p > path)
//        --p;
//    *p = 0;
//    scc_set_lib_path(s, path);
//}

#if __SCC_TARGET_FORMAT_ID__==__SCC_TARGET_FORMAT_PE__ //{
static void scc_add_systemdir(SCCState *s)
{
    char buf[1000];
		//TODO GetSystemDirectoryA,GetSystemDirectoryW
    SCC(GetSystemDirectory)(buf, sizeof buf);
    scc_add_library_path(s, normalize_slashes(buf));
}
#endif//}

#ifdef LIBSCC_AS_DLL
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    if (DLL_PROCESS_ATTACH == dwReason)
        scc_module = hDll;
    return TRUE;
}
#endif
#endif//}_WIN32

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC char *pstrcpy(char *buf, int buf_size, const char *s)
{
    char *q, *q_end;
    int c;

    if (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        while (q < q_end) {
            c = *s++;
            if (c == '\0') break;
            *q++ = c;
        }
        *q = '\0';
    }
    return buf;
}

/* strcat and truncate. */
ST_FUNC char *pstrcat(char *buf, int buf_size, const char *s)
{
    int len;
    len = SCC(strlen,int)(buf);
    if (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    return buf;
}

ST_FUNC char *pstrncpy(char *out, const char *in, size_t num)
{
    SCC(memcpy)(out, in, num);
    out[num] = '\0';
    return out;
}

/* extract the basename of a file */
PUB_FUNC char *scc_basename(const char *name)
{
    char *p = SCC(strchr,char*)(name, 0);
    while (p > name && !IS_DIRSEP(p[-1]))
        --p;
    return p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC char *scc_fileextension (const char *name)
{
    char *b = scc_basename(name);
    char *e = SCC(strrchr,char*)(b, '.');
    return e ? e : SCC(strchr,char*)(b, 0);
}

/********************************************************/
/* memory management */

//#undef free
//#undef malloc
//#undef realloc

#ifndef MEM_DEBUG

PUB_FUNC void scc_free(void *ptr)
{
    SCC(free)(ptr);
}

PUB_FUNC void *scc_malloc(unsigned long size)
{
    void *ptr;
    ptr = SCC(malloc)(size);
    if (!ptr && size)
        scc_error("memory full (malloc(%ld))",size);
    return ptr;
}

PUB_FUNC void *scc_mallocz(unsigned long size)
{
    void *ptr;
    ptr = scc_malloc(size);
    SCC(memset)(ptr, 0, size);
    return ptr;
}

PUB_FUNC void *scc_realloc(void *ptr, unsigned long size)
{
    void *ptr1;
    ptr1 =SCC(realloc)(ptr, size);
    if (!ptr1 && size)
        scc_error("memory full (realloc)");
    return ptr1;
}

PUB_FUNC char *scc_strdup(const char *str)
{
    char *ptr;
    ptr = scc_malloc(SCC(strlen,int)(str) + 1);
    SCC(strcpy)(ptr, str);
    return ptr;
}

PUB_FUNC void scc_memcheck(void)
{
}

#else

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    ((mem_debug_header_t*)((char*)header + header->size))->magic3
#define MEM_USER_PTR(header) \
    ((char *)header + offsetof(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((char*)ptr - offsetof(mem_debug_header_t, magic3))

struct mem_debug_header {
    unsigned magic1;
    unsigned size;
    struct mem_debug_header *prev;
    struct mem_debug_header *next;
    int line_num;
    char file_name[MEM_DEBUG_FILE_LEN + 1];
    unsigned magic2;
    ALIGNED(16) unsigned magic3;
};

typedef struct mem_debug_header mem_debug_header_t;

static mem_debug_header_t *mem_debug_chain;
static unsigned mem_cur_size;
static unsigned mem_max_size;

static mem_debug_header_t *malloc_check(void *ptr, const char *msg)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    if (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        MEM_DEBUG_CHECK3(header) != MEM_DEBUG_MAGIC3 ||
        header->size == (unsigned)-1) {
       SCC(fprintf)(SCCSTD(err), "%s check failed\n", msg);
        if (header->magic1 == MEM_DEBUG_MAGIC1)
           SCC(fprintf)(SCCSTD(err), "%s:%u: block allocated here.\n",
                header->file_name, header->line_num);
        SCC(exit)(1);
    }
    return header;
}

PUB_FUNC void *scc_malloc_debug(unsigned long size, const char *file, int line)
{
    int ofs;
    mem_debug_header_t *header;

    header = SCC(malloc)(sizeof(mem_debug_header_t) + size);
    if (!header)
        scc_error("memory full (malloc)");

    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    MEM_DEBUG_CHECK3(header) = MEM_DEBUG_MAGIC3;
    header->line_num = line;
    ofs = SCC(strlen,int)(file) - MEM_DEBUG_FILE_LEN;
    SCC(strncpy)(header->file_name, file + (ofs > 0 ? ofs : 0), MEM_DEBUG_FILE_LEN);
    header->file_name[MEM_DEBUG_FILE_LEN] = 0;

    header->next = mem_debug_chain;
    header->prev = NULL;
    if (header->next)
        header->next->prev = header;
    mem_debug_chain = header;

    mem_cur_size += size;
    if (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;

    return MEM_USER_PTR(header);
}

PUB_FUNC void scc_free_debug(void *ptr)
{
    mem_debug_header_t *header;
    if (!ptr)
        return;
    header = malloc_check(ptr, "scc_free");
    mem_cur_size -= header->size;
    header->size = (unsigned)-1;
    if (header->next)
        header->next->prev = header->prev;
    if (header->prev)
        header->prev->next = header->next;
    if (header == mem_debug_chain)
        mem_debug_chain = header->next;
    SCC(free)(header);
}

PUB_FUNC void *scc_mallocz_debug(unsigned long size, const char *file, int line)
{
    void *ptr;
    ptr = scc_malloc_debug(size,file,line);
    SCC(memset)(ptr, 0, size);
    return ptr;
}

PUB_FUNC void *scc_realloc_debug(void *ptr, unsigned long size, const char *file, int line)
{
    mem_debug_header_t *header;
    int mem_debug_chain_update = 0;
    if (!ptr)
        return scc_malloc_debug(size, file, line);
    header = malloc_check(ptr, "scc_realloc");
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header =SCC(realloc)(header, sizeof(mem_debug_header_t) + size);
    if (!header)
        scc_error("memory full (realloc)");
    header->size = size;
    MEM_DEBUG_CHECK3(header) = MEM_DEBUG_MAGIC3;
    if (header->next)
        header->next->prev = header;
    if (header->prev)
        header->prev->next = header;
    if (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    if (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    return MEM_USER_PTR(header);
}

PUB_FUNC char *scc_strdup_debug(const char *str, const char *file, int line)
{
    char *ptr;
    ptr = scc_malloc_debug(SCC(strlen,int)(str) + 1, file, line);
    SCC(strcpy)(ptr, str);
    return ptr;
}

PUB_FUNC void scc_memcheck(void)
{
    if (mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
       SCC(fprintf)(SCCSTD(err), "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        while (header) {
           SCC(fprintf)(SCCSTD(err), "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->line_num, header->size);
            header = header->next;
        }
#if MEM_DEBUG-0 == 2
        SCC(exit)(2);
#endif
    }
}
#endif /* MEM_DEBUG */

//TODO
//#define free(p) use_scc_free(p)
//#define malloc(s) use_scc_malloc(s)
//#define realloc(p, s) use_scc_realloc(p, s)

/********************************************************/
/* dynarrays */

ST_FUNC void dynarray_add(void *ptab, int *nb_ptr, void *data)
{
    int nb, nb_alloc;
    void **pp;

    nb = *nb_ptr;
    pp = *(void ***)ptab;
    /* every power of two we double array size */
    if ((nb & (nb - 1)) == 0) {
        if (!nb)
            nb_alloc = 1;
        else
            nb_alloc = nb * 2;
        pp = scc_realloc(pp, nb_alloc * sizeof(void *));
        *(void***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC void dynarray_reset(void *pp, int *n)
{
    void **p;
    for (p = *(void***)pp; *n; ++p, --*n)
        if (*p)
            scc_free(*p);
    scc_free(*(void**)pp);
    *(void**)pp = NULL;
}

static void scc_split_path(SCCState *s, void *p_ary, int *p_nb_ary, const char *in)
{
    const char *p;
    do {
        int c;
        CString str;

        cstr_new(&str);
        for (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            if (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                if (c == 'B')
                    cstr_cat(&str, s->scc_lib_path, -1);
            } else {
                cstr_ccat(&str, c);
            }
        }
        if (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, scc_strdup(str.data));
        }
        cstr_free(&str);
        in = p+1;
    } while (*p);
}

/********************************************************/

static inline void strcat_vprintf(char *buf, int buf_size, const char *fmt, va_list ap)
{
	int len;
	len = SCC(strlen,int)(buf);
	SCC(vsnprintf)(buf + len, buf_size - len, fmt, ap);
}

static inline void strcat_printf(char *buf, int buf_size, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	strcat_vprintf(buf, buf_size, fmt, ap);
	va_end(ap);
}

PUB_FUNC void scc_error_internal_v(SCCState *s1, int is_warning, const char *fmt, va_list ap)
{
	char buf[2048]={'\0'};
	BufferedFile **pf, *f;

	buf[0] = '\0';
	/* use upper file if inline ":asm:" or token ":paste:" */
	for (f = file; f && f->filename[0] == ':'; f = f->prev)
		;
	if (f) {
		for(pf = s1->include_stack; pf < s1->include_stack_ptr; pf++)
			strcat_printf(buf, sizeof(buf), "In file included from %s:%d:\n",(*pf)->filename, (*pf)->line_num);
		if (s1->error_set_jmp_enabled) {
			strcat_printf(buf, sizeof(buf), "%s:%d: ", f->filename, f->line_num - !!(tok_flags & TOK_FLAG_BOL));
		} else {
			strcat_printf(buf, sizeof(buf), "%s: ", f->filename);
		}
	} else {
		strcat_printf(buf, sizeof(buf), "scc: ");
	}
	if (is_warning) strcat_printf(buf, sizeof(buf), "warning: ");
	else strcat_printf(buf, sizeof(buf), "error: ");

	strcat_vprintf(buf, sizeof(buf), fmt, ap);

	if (!s1->error_func) {
		if (s1->output_type == SCC_OUTPUT_PREPROCESS && s1->ppfp == SCCSTD(out)){
			SCC(printf)("\n"), SCC(fflush)(SCCSTD(out));
		}
		SCC(fflush)(SCCSTD(out));
		SCC(fprintf)(SCCSTD(err), "%s\n", buf);
		SCC(fflush)(SCCSTD(err));
	} else { s1->error_func(s1->error_opaque, buf); }
	if (!is_warning || s1->warn_error) s1->nb_errors++;
}

PUB_FUNC void scc_error_noabort(const char *fmt, ...)
{
    SCCState *s1 = scc_state;
    va_list ap;

    va_start(ap, fmt);
    scc_error_internal_v(s1, 0, fmt, ap);
    va_end(ap);
}

PUB_FUNC void scc_error(const char *fmt, ...)
{
    SCCState *s1 = scc_state;
    va_list ap;

    va_start(ap, fmt);
    scc_error_internal_v(s1, 0, fmt, ap);
    va_end(ap);
    /* better than nothing: in some cases, we accept to handle errors */
    if (s1->error_set_jmp_enabled) {
        SCC(longjmp)(s1->error_jmp_buf, 1);
    } else {
        SCC(exit)(1);
    }
}
PUB_FUNC void scc_warning(const char *fmt, ...)
{
    SCCState *s1 = scc_state;
    va_list ap;

    if (s1->warn_none) return;

    va_start(ap, fmt);
    scc_error_internal_v(s1, 1, fmt, ap);
    va_end(ap);
}

LIBSCCAPI void scc_set_error_func(SCCState *s, void *error_opaque,
                        void (*error_func)(void *opaque, const char *msg))
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/********************************************************/
/* I/O layer */

ST_FUNC void scc_open_buf(SCCState *s1, const char *filename, int initlen)
{
    BufferedFile *buf;
    int buflen = initlen ? initlen : IO_BUF_SIZE;

    buf = scc_mallocz(sizeof(BufferedFile) + buflen);
    buf->buf_ptr = buf->buffer;
    buf->buf_end = buf->buffer + initlen;
    buf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(buf->filename, sizeof(buf->filename), filename);
    buf->true_filename = buf->filename;
    buf->line_num = 1;
    buf->ifdef_stack_ptr = s1->ifdef_stack_ptr;
    buf->fd = -1;
    buf->prev = file;
    file = buf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC void scc_close(void)
{
    BufferedFile *buf = file;
    if (buf->fd > 0) {
        SCC(close)(buf->fd);
        total_lines += buf->line_num;
    }
    if (buf->true_filename != buf->filename)
        scc_free(buf->true_filename);
    file = buf->prev;
    scc_free(buf);
}

ST_FUNC int scc_open(SCCState *s1, const char *filename)
{
    int fd;
    if (SCC(strcmp,int)(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    else
        fd = SCC(open,int)(filename, O_RDONLY | O_BINARY);

    if ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
       SCC(printf)("%s %*s%s\n", fd < 0 ? "nf":"->",
               (s1->include_stack_ptr - s1->include_stack), "", filename);

    if (fd < 0) return -1;

    scc_open_buf(s1, filename, 0);
#ifdef _WIN32
    normalize_slashes(file->filename);
#endif
    file->fd = fd;
    return fd;
}

/* compile the file opened in 'file'. Return non zero if errors. */
static int scc_compile(SCCState *s1, int filetype)
{
	Sym *define_start;
	int is_asm;
	int is_sao;//TMP

	define_start = define_stack;
	is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));
	is_sao = !!(filetype & (AFF_TYPE_SAO));
	scc_format_begin_file(s1);

	if (SCC(setjmp,int)(s1->error_jmp_buf) == 0) {

		s1->nb_errors = 0;
		s1->error_set_jmp_enabled = 1;

		preprocess_start(s1, is_asm);

		if (s1->output_type == SCC_OUTPUT_PREPROCESS) {
			scc_preprocess(s1);
		} else if (is_asm) {
#ifdef CONFIG_SCC_ASM
			scc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
#else
			scc_error_noabort("asm not supported");
#endif
		} else if (is_sao) {
			//TODO find handler to handle !!
			sao_compile(s1);
		} else {
			sccgen_compile(s1);
		}
	}

	s1->error_set_jmp_enabled = 0;

	preprocess_end(s1);

	free_inline_functions(s1);

	/* reset define stack, but keep -D and built-ins */
	free_defines(define_start);

	sym_pop(&global_stack, NULL, 0);
	sym_pop(&local_stack, NULL, 0);

	scc_format_end_file(s1);
	return s1->nb_errors != 0 ? -1 : 0;
}

LIBSCCAPI int scc_compile_string(SCCState *s, const char *str)
{
	int len, ret;

	len = SCC(strlen,int)(str);
	scc_open_buf(s, "<string>", len);
	SCC(memcpy)(file->buffer, str, len);
	ret = scc_compile(s, s->filetype);
	scc_close();
	return ret;
}

/* define a preprocessor symbol. A value can also be provided with the '=' operator */
LIBSCCAPI void scc_define_symbol(SCCState *s1, const char *sym, const char *value)
{
    int len1, len2;
    /* default value */
    if (!value)
        value = "1";
    len1 = SCC(strlen,int)(sym);
    len2 = SCC(strlen,int)(value);

    /* init file structure */
    scc_open_buf(s1, "<define>", len1 + len2 + 1);
    SCC(memcpy)(file->buffer, sym, len1);
    file->buffer[len1] = ' ';
    SCC(memcpy)(file->buffer + len1 + 1, value, len2);

    /* parse with define parser */
    next_nomacro();
    parse_define();
    scc_close();
}

/* undefine a preprocessor symbol */
LIBSCCAPI void scc_undefine_symbol(SCCState *s1, const char *sym)
{
    TokenSym *ts;
    Sym *s;
    ts = tok_alloc(sym, SCC(strlen,int)(sym));
    s = define_find(ts->tok);
    /* undefine symbol by putting an invalid name */
    if (s)
        define_undef(s);
}

/* cleanup all static data used during compilation */
static void scc_cleanup(void)
{
    if (NULL == scc_state)
        return;
    while (file)
        scc_close();
    sccpp_delete(scc_state);
    scc_state = NULL;
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    /* reset symbol stack */
    sym_free_first = NULL;
}

LIBSCCAPI SCCState *scc_new(void)
{
	SCCState *s;

	scc_cleanup();

	s = scc_mallocz(sizeof(SCCState));
	if (!s)
		return NULL;
	scc_state = s;
	++nb_states;

	s->nocommon = 1;
	s->warn_implicit_function_declaration = 1;
	s->ms_extensions = 1;

#ifdef CHAR_IS_UNSIGNED
	s->char_is_unsigned = 1;
#endif
#if __SCC_TARGET_CPU_ID__==__SCC_CPU_X86__ //{
# if __SCC_TARGET_CPU_BIT__==32
	s->seg_size = 32;
# elif __SCC_TARGET_CPU_BIT__==64
	//s->seg_size = 64;//TODO
# endif
#endif //}
	/* enable this if you want symbols with leading underscore on windows: */

	//TODO PE?
//	s->leading_underscore = 1;

	//#ifdef _WIN32
	//    scc_set_lib_path_w32(s);
	//#else
	//    scc_set_lib_path(s, CONFIG_SCCDIR);
	//#endif

	scc_set_lib_path(s, CONFIG_SCCDIR);

	//TODO ELF/PE/MACHO divide
	scc_format_new(s);

	sccpp_new(s);

	/* we add dummy defines for some special macros to speed up tests
		 and to have working defined() */
	define_push(TOK___LINE__, MACRO_OBJ, NULL, NULL);
	define_push(TOK___FILE__, MACRO_OBJ, NULL, NULL);
	define_push(TOK___DATE__, MACRO_OBJ, NULL, NULL);
	define_push(TOK___TIME__, MACRO_OBJ, NULL, NULL);

	define_push(TOK___COUNTER__, MACRO_OBJ, NULL, NULL);
	{
		char buffer[32]; int a,b,c;
		SCC(sscanf)(SCC_VERSION, "%d.%d.%d", &a, &b, &c);
		SCC(sprintf)(buffer, "%d", a*10000 + b*100 + c);
		scc_define_symbol(s, "__SAOCC__", buffer);
	}

	//TODO forward symbol from current compiler to new compile env if not cross compile.
	//how to say a cross compile? diff os/cpu-type/cpu-bit....

	/* standard defines */
	scc_define_symbol(s, "__STDC__", NULL);
	scc_define_symbol(s, "__STDC_VERSION__", "199901L");
	scc_define_symbol(s, "__STDC_HOSTED__", NULL);

	//copy the config if not cross build...
#if __SCC_TARGET_CROSS__==0
# ifdef __SCC_TARGET_CPU__
   scc_define_symbol(s, "__SCC_TARGET_CPU__", SCC_QUOTE(__SCC_TARGET_CPU__));
# endif
# ifdef __SCC_TARGET_CPU_BIT__
   scc_define_symbol(s, "__SCC_TARGET_CPU_BIT__", SCC_QUOTE(__SCC_TARGET_CPU_BIT__));
# endif
# ifdef __SCC_TARGET_FORMAT__
   scc_define_symbol(s, "__SCC_TARGET_FORMAT__", SCC_QUOTE(__SCC_TARGET_FORMAT__));
# endif
# ifdef __SCC_TARGET_OS__
   scc_define_symbol(s, "__SCC_TARGET_OS__", SCC_QUOTE(__SCC_TARGET_OS__));
# endif
#endif
	
	/* target defines */
#if __SCC_TARGET_CPU_ID__==__SCC_CPU_X86__
# if __SCC_TARGET_CPU_BIT__==32
	scc_define_symbol(s, "__i386__", NULL);
	scc_define_symbol(s, "__i386", NULL);
	scc_define_symbol(s, "i386", NULL);
# elif __SCC_TARGET_CPU_BIT__==64
	scc_define_symbol(s, "__x86_64__", NULL);
# endif
#endif

#if (__SCC_TARGET_CPU_ID__==__SCC_CPU_ARM__ && __SCC_TARGET_CPU_BIT__==32)
	scc_define_symbol(s, "__ARM_ARCH_4__", NULL);
	scc_define_symbol(s, "__arm_elf__", NULL);
	scc_define_symbol(s, "__arm_elf", NULL);
	scc_define_symbol(s, "arm_elf", NULL);
	scc_define_symbol(s, "__arm__", NULL);
	scc_define_symbol(s, "__arm", NULL);
	scc_define_symbol(s, "arm", NULL);
	scc_define_symbol(s, "__APCS_32__", NULL);
	scc_define_symbol(s, "__ARMEL__", NULL);
#if defined(SCC_ARM_EABI)
	scc_define_symbol(s, "__ARM_EABI__", NULL);
#endif
#if defined(SCC_ARM_HARDFLOAT)
	s->float_abi = ARM_HARD_FLOAT;
	scc_define_symbol(s, "__ARM_PCS_VFP", NULL);
#else
	s->float_abi = ARM_SOFTFP_FLOAT;
#endif
#elif (__SCC_TARGET_CPU_ID__==__SCC_CPU_ARM__ && __SCC_TARGET_CPU_BIT__==64)
	scc_define_symbol(s, "__aarch64__", NULL);
#endif

#if __SCC_OS_ID__==__SCC_OS_OSX__
	scc_define_symbol(s, "__APPLE__", NULL);
#endif

#if __SCC_TARGET_FORMAT_ID__==__SCC_TARGET_FORMAT_PE__
	scc_define_symbol(s, "_WIN32", NULL);
# if (__SCC_TARGET_CPU_ID__==__SCC_CPU_X86__ && __SCC_TARGET_CPU_BIT__==64)
	scc_define_symbol(s, "_WIN64", NULL);
# endif
#else
	scc_define_symbol(s, "__unix__", NULL);
	scc_define_symbol(s, "__unix", NULL);
	scc_define_symbol(s, "unix", NULL);

	//TODO should do it only when in run mode..!!!!
# if defined(__linux__)
	scc_define_symbol(s, "__linux__", NULL);
	scc_define_symbol(s, "__linux", NULL);
# endif

# if defined(__FreeBSD__)
	scc_define_symbol(s, "__FreeBSD__", "__FreeBSD__");
	/* No 'Thread Storage Local' on FreeBSD with scc */
	scc_define_symbol(s, "__NO_TLS", NULL);
# endif
# if defined(__FreeBSD_kernel__)
	scc_define_symbol(s, "__FreeBSD_kernel__", NULL);
# endif
# if defined(__NetBSD__)
	scc_define_symbol(s, "__NetBSD__", "__NetBSD__");
# endif
# if defined(__OpenBSD__)
	scc_define_symbol(s, "__OpenBSD__", "__OpenBSD__");
# endif
#endif

	/* SaoCC & gcc defines */
#if PTR_SIZE == 4
	/* 32bit systems. */
	scc_define_symbol(s, "__SIZE_TYPE__", "unsigned int");
	scc_define_symbol(s, "__PTRDIFF_TYPE__", "int");
	scc_define_symbol(s, "__ILP32__", NULL);
#elif LONG_SIZE == 4
	/* 64bit Windows. */
	scc_define_symbol(s, "__SIZE_TYPE__", "unsigned long long");
	scc_define_symbol(s, "__PTRDIFF_TYPE__", "long long");
	scc_define_symbol(s, "__LLP64__", NULL);
#else
	/* Other 64bit systems. */
	scc_define_symbol(s, "__SIZE_TYPE__", "unsigned long");
	scc_define_symbol(s, "__PTRDIFF_TYPE__", "long");
	scc_define_symbol(s, "__LP64__", NULL);
#endif

#if __SCC_TARGET_FORMAT_ID__==__SCC_TARGET_FORMAT_PE__ //{
	scc_define_symbol(s, "__WCHAR_TYPE__", "unsigned short");
	scc_define_symbol(s, "__WINT_TYPE__", "unsigned short");
#else //}:{
	scc_define_symbol(s, "__WCHAR_TYPE__", "int");
	/* wint_t is unsigned int by default, but (signed) int on BSDs
		 and unsigned short on windows.  Other OSes might have still
		 other conventions, sigh.  */
# if defined(__FreeBSD__) || defined (__FreeBSD_kernel__) \
	|| defined(__NetBSD__) || defined(__OpenBSD__)
	scc_define_symbol(s, "__WINT_TYPE__", "int");
#  ifdef __FreeBSD__
	/* define __GNUC__ to have some useful stuff from sys/cdefs.h
		 that are unconditionally used in FreeBSDs other system headers :/ */
	scc_define_symbol(s, "__GNUC__", "2");
	scc_define_symbol(s, "__GNUC_MINOR__", "7");
	scc_define_symbol(s, "__builtin_alloca", "alloca");
#  endif
# else
	scc_define_symbol(s, "__WINT_TYPE__", "unsigned int");
	/* glibc defines */
	scc_define_symbol(s, "__REDIRECT(name, proto, alias)",
			"name proto __asm__ (#alias)");
	scc_define_symbol(s, "__REDIRECT_NTH(name, proto, alias)",
			"name proto __asm__ (#alias) __THROW");
# endif
# if defined(SCC_MUSL)
	scc_define_symbol(s, "__DEFINED_va_list", "");
	scc_define_symbol(s, "__DEFINED___isoc_va_list", "");
	scc_define_symbol(s, "__isoc_va_list", "void *");
# endif /* SCC_MUSL */
	/* Some GCC builtins that are simple to express as macros.  */
	scc_define_symbol(s, "__builtin_extract_return_addr(x)", "x");
#endif //}
	return s;
}

LIBSCCAPI void scc_delete(SCCState *s1)
{
    scc_cleanup();

    /* free sections */
    scc_format_delete(s1);

    /* free library paths */
    dynarray_reset(&s1->library_paths, &s1->nb_library_paths);
    dynarray_reset(&s1->crt_paths, &s1->nb_crt_paths);

    /* free include paths */
    dynarray_reset(&s1->cached_includes, &s1->nb_cached_includes);
    dynarray_reset(&s1->include_paths, &s1->nb_include_paths);
    dynarray_reset(&s1->sysinclude_paths, &s1->nb_sysinclude_paths);
    dynarray_reset(&s1->cmd_include_files, &s1->nb_cmd_include_files);

    scc_free(s1->scc_lib_path);
    scc_free(s1->soname);
    scc_free(s1->rpath);
    scc_free(s1->init_symbol);
    scc_free(s1->fini_symbol);
    scc_free(s1->outfile);
    scc_free(s1->deps_outfile);
    dynarray_reset(&s1->files, &s1->nb_files);
    dynarray_reset(&s1->target_deps, &s1->nb_target_deps);
    dynarray_reset(&s1->pragma_libs, &s1->nb_pragma_libs);
    dynarray_reset(&s1->argv, &s1->argc);

#if __SCC_TARGET_CROSS__==0
    /* free runtime memory */
    scc_run_free(s1);
#endif

    scc_free(s1);
    if (0 == --nb_states)
        scc_memcheck();
}

LIBSCCAPI int scc_set_output_type(SCCState *s, int output_type)
{
	s->output_type = output_type;

	/* always elf for objects */
	if (output_type == SCC_OUTPUT_OBJ)
		s->output_format = SCC_OUTPUT_FORMAT_ELF;

	if (s->char_is_unsigned)
		scc_define_symbol(s, "__CHAR_UNSIGNED__", NULL);

	if (!s->nostdinc) {
		/* default include paths */
		/* -isystem paths have already been handled */
		scc_add_sysinclude_path(s, CONFIG_SCC_SYSINCLUDEPATHS);
	}

	if (s->do_debug) {
		/* add debug sections */
		scc_format_stab_new(s);
	}

	scc_add_library_path(s, CONFIG_SCC_LIBPATHS);

#if __SCC_TARGET_FORMAT_ID__==__SCC_TARGET_FORMAT_PE__
# ifdef _WIN32
	if (!s->nostdlib && output_type != SCC_OUTPUT_OBJ)
	{
		scc_add_systemdir(s);
	}
# endif
#else
	/* paths for crt objects */
	scc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_SCC_CRTPREFIX);
	/* add libc crt1/crti objects */
#if __SCC_OS_ID__==__SCC_OS_OSX__ //{
	//TODO
#else
	if ((output_type == SCC_OUTPUT_EXE || output_type == SCC_OUTPUT_DLL) &&
			!s->nostdlib)
	{
		if (output_type != SCC_OUTPUT_DLL){
			scc_add_crt(s, "crt1.o");
		}
		scc_add_crt(s, "crti.o");
	}
#endif//}
#endif
	return 0;
}

LIBSCCAPI int scc_add_include_path(SCCState *s, const char *pathname)
{
    scc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    return 0;
}

LIBSCCAPI int scc_add_sysinclude_path(SCCState *s, const char *pathname)
{
    scc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    return 0;
}

//@ref ld_add_file()
ST_FUNC int scc_add_file_internal(SCCState *s1, const char *filename, int flags)
{
	int ret;

	ret = scc_open(s1, filename);
	if (ret < 0) {
		if (flags & AFF_PRINT_ERROR)
			scc_error_noabort("scc_add_file_internal() file '%s' not found", filename);
		return ret;
	}

	//dependence
	dynarray_add(&s1->target_deps, &s1->nb_target_deps, scc_strdup(filename));

	if (flags & AFF_TYPE_BIN) {
		ElfW(Ehdr) ehdr;
		int fd, obj_type;

		fd = file->fd;
		obj_type = scc_object_type(fd, &ehdr);
		SCC(lseek)(fd, 0, SEEK_SET);

#if __SCC_OS_ID__==__SCC_OS_OSX__ //{
		if (0 == obj_type && 0 == SCC(strcmp,int)(scc_fileextension(filename), ".dylib"))
			obj_type = AFF_BINTYPE_DYN;
#endif //}

		switch (obj_type) {
			case AFF_BINTYPE_REL:
				ret = scc_load_object_file(s1, fd, 0);
				break;
#if __SCC_TARGET_FORMAT_ID__==__SCC_TARGET_FORMAT_PE__
#else
			case AFF_BINTYPE_DYN://NOTES: mostly .dylib from above, .so from scc_object_type()
				if (s1->output_type == SCC_OUTPUT_MEMORY) {
					ret = 0;
#if __SCC_TARGET_CROSS__==0
					//using libdl directly for sccrun...
					if (NULL == scc_dlopen(filename))
						ret = -1;
#endif
				} else {
					//scc_load_dylib or support MACHO ...
					//ret = scc_load_dylib(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
					//@ref scc-$FORMAT
					ret = scc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
				}
				break;
#endif
			case AFF_BINTYPE_AR:
				ret = scc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
				break;
			default:
#if __SCC_TARGET_FORMAT_ID__==__SCC_TARGET_FORMAT_PE__
				ret = pe_load_file(s1, filename, fd);
#else
				/* as GNU ld, consider it is an ld script if not recognized */
				ret = scc_load_ldscript(s1);
#endif
				if (ret < 0)
					scc_error_noabort("unrecognized file type");
				break;
		}
	} else {
		ret = scc_compile(s1, flags);
	}
	scc_close();
	return ret;
}//scc_add_file_internal()

LIBSCCAPI int scc_add_file(SCCState *s, const char *filename)
{
	int filetype = s->filetype;
	if (0 == (filetype & AFF_TYPE_MASK)) {
		//if not indicated by the caller, then try guessing from file extension
		const char *ext = scc_fileextension(filename);
		if (ext[0]) {
			ext++;
			if (!SCC(strcmp,int)(ext, "S")) {
				filetype = AFF_TYPE_ASMPP;
			} else if (!SCC(strcmp,int)(ext, "s")) {
				filetype = AFF_TYPE_ASM;
			}else if(!PATHCMP(ext, "c")|| !PATHCMP(ext, "h")|| !PATHCMP(ext, "i")){
				//The .i files are also called as "Pure C files
				filetype = AFF_TYPE_C;
			} else if (!SCC(strcmp,int)(ext, "sao")){
				//default using sao-lang-handler
				filetype = AFF_TYPE_SAO;
			} else
				filetype |= AFF_TYPE_BIN;
		} else { //default as c
			filetype = AFF_TYPE_C;
		}
	}
	return scc_add_file_internal(s, filename, filetype | AFF_PRINT_ERROR);
}

LIBSCCAPI int scc_add_library_path(SCCState *s, const char *pathname)
{
    scc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    return 0;
}

static int scc_add_library_internal(SCCState *s, const char *fmt,
    const char *filename, int flags, char **paths, int nb_paths)
{
    char buf[1024];
    int i;

    for(i = 0; i < nb_paths; i++) {
        SCC(snprintf)(buf, sizeof(buf), fmt, paths[i], filename);
        if (scc_add_file_internal(s, buf, flags | AFF_TYPE_BIN) == 0)
            return 0;
    }
    return -1;
}

/* find and load a dll. Return non zero if not found */
/* XXX: add '-rpath' option support ? */
ST_FUNC int scc_add_dll(SCCState *s, const char *filename, int flags)
{
    return scc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

ST_FUNC int scc_add_crt(SCCState *s, const char *filename)
{
    if (-1 == scc_add_library_internal(s, "%s/%s",
        filename, 0, s->crt_paths, s->nb_crt_paths))
        scc_error_noabort("file '%s' not found", filename);
    return 0;
}

/* the library name is the same as the argument of the '-l' option */
LIBSCCAPI int scc_add_library(SCCState *s, const char *libraryname)
{
#if __SCC_TARGET_FORMAT_ID__==__SCC_TARGET_FORMAT_PE__
    const char *libs[] = { "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll", "%s/lib%s.a", NULL };
    const char **pp = s->static_link ? libs + 4 : libs;
#elif __SCC_OS_ID__==__SCC_OS_OSX__
    const char *libs[] = { "%s/lib%s.dylib", "%s/lib%s.a", NULL };
    const char **pp = s->static_link ? libs + 1 : libs;
#else
    const char *libs[] = { "%s/lib%s.so", "%s/lib%s.a", NULL };
    const char **pp = s->static_link ? libs + 1 : libs;
#endif
    int flags = s->filetype & AFF_WHOLE_ARCHIVE;
    while (*pp) {
        if (0 == scc_add_library_internal(s, *pp,
            libraryname, flags, s->library_paths, s->nb_library_paths))
            return 0;
        ++pp;
    }
    return -1;
}

PUB_FUNC int scc_add_library_err(SCCState *s, const char *libname)
{
    int ret = scc_add_library(s, libname);
    if (ret < 0)
        scc_error_noabort("library '%s' not found", libname);
    return ret;
}

/* handle #pragma comment(lib,) */
ST_FUNC void scc_add_pragma_libs(SCCState *s1)
{
    int i;
    for (i = 0; i < s1->nb_pragma_libs; i++)
        scc_add_library_err(s1, s1->pragma_libs[i]);
}

LIBSCCAPI int scc_add_symbol(SCCState *s, const char *name, const void *val)
{
#if __SCC_TARGET_FORMAT_ID__==__SCC_TARGET_FORMAT_PE__
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s, 0, name, (uintptr_t)val);
#else
    set_elf_sym(symtab_section, (uintptr_t)val, 0,
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0,
        SHN_ABS, name);
#endif
    return 0;
}

LIBSCCAPI void scc_set_lib_path(SCCState *s, const char *path)
{
    scc_free(s->scc_lib_path);
    s->scc_lib_path = scc_strdup(path);
}

#define WD_ALL    0x0001 /* warning is activated when using -Wall */
#define FD_INVERT 0x0002 /* invert value before storing */

typedef struct FlagDef {
    uint16_t offset;
    uint16_t flags;
    const char *name;
} FlagDef;

static int no_flag(const char **pp)
{
    const char *p = *pp;
    if (*p != 'n' || *++p != 'o' || *++p != '-')
        return 0;
    *pp = p + 1;
    return 1;
}

ST_FUNC int set_flag(SCCState *s, const FlagDef *flags, const char *name)
{
    int value, ret;
    const FlagDef *p;
    const char *r;

    value = 1;
    r = name;
    if (no_flag(&r))
        value = 0;

    for (ret = -1, p = flags; p->name; ++p) {
        if (ret) {
            if (SCC(strcmp,int)(r, p->name))
                continue;
        } else {
            if (0 == (p->flags & WD_ALL))
                continue;
        }
        if (p->offset) {
            *(int*)((char *)s + p->offset) =
                p->flags & FD_INVERT ? !value : value;
            if (ret)
                return 0;
        } else {
            ret = 0;
        }
    }
    return ret;
}

static int strstart(const char *val, const char **str)
{
    const char *p, *q;
    p = *str;
    q = val;
    while (*q) {
        if (*p != *q)
            return 0;
        p++;
        q++;
    }
    *str = p;
    return 1;
}

/* Like strstart, but automatically takes into account that ld options can
 *
 * - start with double or single dash (e.g. '--soname' or '-soname')
 * - arguments can be given as separate or after '=' (e.g. '-Wl,-soname,x.so'
 *   or '-Wl,-soname=x.so')
 *
 * you provide `val` always in 'option[=]' form (no leading -)
 */
static int link_option(const char *str, const char *val, const char **ptr)
{
    const char *p, *q;
    int ret;

    /* there should be 1 or 2 dashes */
    if (*str++ != '-')
        return 0;
    if (*str == '-')
        str++;

    /* then str & val should match (potentially up to '=') */
    p = str;
    q = val;

    ret = 1;
    if (q[0] == '?') {
        ++q;
        if (no_flag(&p))
            ret = -1;
    }

    while (*q != '\0' && *q != '=') {
        if (*p != *q)
            return 0;
        p++;
        q++;
    }

    /* '=' near eos means ',' or '=' is ok */
    if (*q == '=') {
        if (*p == 0)
            *ptr = p;
        if (*p != ',' && *p != '=')
            return 0;
        p++;
    } else if (*p) {
        return 0;
    }
    *ptr = p;
    return ret;
}

static const char *skip_linker_arg(const char **str)
{
    const char *s1 = *str;
    const char *s2 = SCC(strchr,char*)(s1, ',');
    *str = s2 ? s2++ : (s2 = s1 + SCC(strlen,int)(s1));
    return s2;
}

static void copy_linker_arg(char **pp, const char *s, int sep)
{
    const char *q = s;
    char *p = *pp;
    int l = 0;
    if (p && sep)
        p[l = SCC(strlen,int)(p)] = sep, ++l;
    skip_linker_arg(&q);
    pstrncpy(l + (*pp = scc_realloc(p, q - s + l + 1)), s, q - s);
}

/* set linker options */
static int scc_set_linker(SCCState *s, const char *option)
{
	while (*option) {

		const char *p = NULL;
		char *end = NULL;
		int ignoring = 0;
		int ret;

		if (link_option(option, "Bsymbolic", &p)) {
			s->symbolic = 1;
		} else if (link_option(option, "nostdlib", &p)) {
			s->nostdlib = 1;
		} else if (link_option(option, "fini=", &p)) {
			copy_linker_arg(&s->fini_symbol, p, 0);
			ignoring = 1;
		} else if (link_option(option, "image-base=", &p)
				|| link_option(option, "Ttext=", &p)) {
			s->text_addr = SCC(strtoull,unsigned long long)(p, &end, 16);
			s->has_text_addr = 1;
		} else if (link_option(option, "init=", &p)) {
			copy_linker_arg(&s->init_symbol, p, 0);
			ignoring = 1;
		} else if (link_option(option, "oformat=", &p)) {
			if(
#if __SCC_TARGET_FORMAT_ID__==__SCC_TARGET_FORMAT_PE__
					strstart("pe-", &p)
#elif PTR_SIZE == 8
					strstart("elf64-", &p)
#else
					strstart("elf32-", &p)
#endif
				){ 
				s->output_format = SCC_OUTPUT_FORMAT_ELF;
			} else if (!SCC(strcmp,int)(p, "binary")) {
				s->output_format = SCC_OUTPUT_FORMAT_BINARY;
			} else
				goto err;

		} else if (link_option(option, "as-needed", &p)) {
			ignoring = 1;
		} else if (link_option(option, "O", &p)) {
			ignoring = 1;
		} else if (link_option(option, "export-all-symbols", &p)) {
			s->rdynamic = 1;
		} else if (link_option(option, "export-dynamic", &p)) {
			s->rdynamic = 1;
		} else if (link_option(option, "rpath=", &p)) {
			copy_linker_arg(&s->rpath, p, ':');
		} else if (link_option(option, "enable-new-dtags", &p)) {
			s->enable_new_dtags = 1;
		} else if (link_option(option, "section-alignment=", &p)) {
			s->section_align = SCC(strtoul,unsigned)(p, &end, 16);
		} else if (link_option(option, "soname=", &p)) {
			copy_linker_arg(&s->soname, p, 0);
#if __SCC_TARGET_FORMAT_ID__==__SCC_TARGET_FORMAT_PE__
		} else if (link_option(option, "large-address-aware", &p)) {
			s->pe_characteristics |= 0x20;
		} else if (link_option(option, "file-alignment=", &p)) {
			s->pe_file_align = SCC(strtoul,unsigned)(p, &end, 16);
		} else if (link_option(option, "stack=", &p)) {
			s->pe_stack_size = SCC(strtoul,unsigned)(p, &end, 10);
		} else if (link_option(option, "subsystem=", &p)) {
#if __SCC_TARGET_CPU_ID__==__SCC_CPU_X86__ //{
			if (!SCC(strcmp,int)(p, "native")) {
				s->pe_subsystem = 1;
			} else if (!SCC(strcmp,int)(p, "console")) {
				s->pe_subsystem = 3;
			} else if (!SCC(strcmp,int)(p, "gui") || !SCC(strcmp,int)(p, "windows")) {
				s->pe_subsystem = 2;
			} else if (!SCC(strcmp,int)(p, "posix")) {
				s->pe_subsystem = 7;
			} else if (!SCC(strcmp,int)(p, "efiapp")) {
				s->pe_subsystem = 10;
			} else if (!SCC(strcmp,int)(p, "efiboot")) {
				s->pe_subsystem = 11;
			} else if (!SCC(strcmp,int)(p, "efiruntime")) {
				s->pe_subsystem = 12;
			} else if (!SCC(strcmp,int)(p, "efirom")) {
				s->pe_subsystem = 13;
			}
#elif (__SCC_TARGET_CPU_ID__==__SCC_CPU_ARM__ && __SCC_TARGET_CPU_BIT__==32)
			else if (!SCC(strcmp,int)(p, "wince")) {
				s->pe_subsystem = 9;
			}
#endif
			else goto err;
#endif //}
		} else if (ret = link_option(option, "?whole-archive", &p), ret) {
			if (ret > 0)
				s->filetype |= AFF_WHOLE_ARCHIVE;
			else
				s->filetype &= ~AFF_WHOLE_ARCHIVE;
		} else if (p) {
			return 0;
		} else {
err:
			scc_error("unsupported linker option '%s'", option);
		}

		if (ignoring && s->warn_unsupported)
			scc_warning("unsupported linker option '%s'", option);

		option = skip_linker_arg(&p);
	}//while
	return 1;
}//scc_set_linker

typedef struct SCCOption {
    const char *name;
    uint16_t index;
    uint16_t flags;
} SCCOption;

enum {
    SCC_OPTION_HELP,
    SCC_OPTION_HELP2,
    SCC_OPTION_v,
    SCC_OPTION_I,
    SCC_OPTION_D,
    SCC_OPTION_U,
    SCC_OPTION_P,
    SCC_OPTION_L,
    SCC_OPTION_B,
    SCC_OPTION_l,
    SCC_OPTION_bench,
    SCC_OPTION_bt,
    SCC_OPTION_b,
    SCC_OPTION_g,
    SCC_OPTION_c,
    SCC_OPTION_dumpversion,
    SCC_OPTION_d,
    SCC_OPTION_static,
    SCC_OPTION_std,
    SCC_OPTION_shared,
    SCC_OPTION_soname,
    SCC_OPTION_o,
    SCC_OPTION_r,
    SCC_OPTION_s,
    SCC_OPTION_traditional,
    SCC_OPTION_Wl,
    SCC_OPTION_Wp,
    SCC_OPTION_W,
    SCC_OPTION_O,
    SCC_OPTION_mfloat_abi,
    SCC_OPTION_m,
    SCC_OPTION_f,
    SCC_OPTION_isystem,
    SCC_OPTION_iwithprefix,
    SCC_OPTION_include,
    SCC_OPTION_nostdinc,
    SCC_OPTION_nostdlib,
    SCC_OPTION_print_search_dirs,
    SCC_OPTION_rdynamic,
    SCC_OPTION_param,
    SCC_OPTION_pedantic,
    SCC_OPTION_pthread,
    SCC_OPTION_run,
    SCC_OPTION_w,
    SCC_OPTION_pipe,
    SCC_OPTION_E,
    SCC_OPTION_MD,
    SCC_OPTION_MF,
    SCC_OPTION_x,
    SCC_OPTION_ar,
    SCC_OPTION_impdef
};

#define SCC_OPTION_HAS_ARG 0x0001
#define SCC_OPTION_NOSEP   0x0002 /* cannot have space before option and arg */

static const SCCOption scc_options[] = {
    { "h", SCC_OPTION_HELP, 0 },
    { "-help", SCC_OPTION_HELP, 0 },
    { "?", SCC_OPTION_HELP, 0 },
    { "hh", SCC_OPTION_HELP2, 0 },
    { "v", SCC_OPTION_v, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
    { "I", SCC_OPTION_I, SCC_OPTION_HAS_ARG },
    { "D", SCC_OPTION_D, SCC_OPTION_HAS_ARG },
    { "U", SCC_OPTION_U, SCC_OPTION_HAS_ARG },
    { "P", SCC_OPTION_P, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
    { "L", SCC_OPTION_L, SCC_OPTION_HAS_ARG },
    { "B", SCC_OPTION_B, SCC_OPTION_HAS_ARG },
    { "l", SCC_OPTION_l, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
    { "bench", SCC_OPTION_bench, 0 },
#ifdef CONFIG_SCC_BACKTRACE
    { "bt", SCC_OPTION_bt, SCC_OPTION_HAS_ARG },
#endif
    { "g", SCC_OPTION_g, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
    { "c", SCC_OPTION_c, 0 },
    { "dumpversion", SCC_OPTION_dumpversion, 0},
    { "d", SCC_OPTION_d, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
    { "static", SCC_OPTION_static, 0 },
    { "std", SCC_OPTION_std, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
    { "shared", SCC_OPTION_shared, 0 },
    { "soname", SCC_OPTION_soname, SCC_OPTION_HAS_ARG },
    { "o", SCC_OPTION_o, SCC_OPTION_HAS_ARG },
    { "-param", SCC_OPTION_param, SCC_OPTION_HAS_ARG },
    { "pedantic", SCC_OPTION_pedantic, 0},
    { "pthread", SCC_OPTION_pthread, 0},
    { "run", SCC_OPTION_run, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
    { "rdynamic", SCC_OPTION_rdynamic, 0 },
    { "r", SCC_OPTION_r, 0 },
    { "s", SCC_OPTION_s, 0 },
    { "traditional", SCC_OPTION_traditional, 0 },
    { "Wl,", SCC_OPTION_Wl, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
    { "Wp,", SCC_OPTION_Wp, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
    { "W", SCC_OPTION_W, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
    { "O", SCC_OPTION_O, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
#if (__SCC_TARGET_CPU_ID__==__SCC_CPU_ARM__ && __SCC_TARGET_CPU_BIT__==32)
    { "mfloat-abi", SCC_OPTION_mfloat_abi, SCC_OPTION_HAS_ARG },
#endif
    { "m", SCC_OPTION_m, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
    { "f", SCC_OPTION_f, SCC_OPTION_HAS_ARG | SCC_OPTION_NOSEP },
    { "isystem", SCC_OPTION_isystem, SCC_OPTION_HAS_ARG },
    { "include", SCC_OPTION_include, SCC_OPTION_HAS_ARG },
    { "nostdinc", SCC_OPTION_nostdinc, 0 },
    { "nostdlib", SCC_OPTION_nostdlib, 0 },
    { "print-search-dirs", SCC_OPTION_print_search_dirs, 0 },
    { "w", SCC_OPTION_w, 0 },
    { "pipe", SCC_OPTION_pipe, 0},
    { "E", SCC_OPTION_E, 0},
    { "MD", SCC_OPTION_MD, 0},
    { "MF", SCC_OPTION_MF, SCC_OPTION_HAS_ARG },
    { "x", SCC_OPTION_x, SCC_OPTION_HAS_ARG },
    { "ar", SCC_OPTION_ar, 0},
#if __SCC_TARGET_FORMAT_ID__==__SCC_TARGET_FORMAT_PE__
    { "impdef", SCC_OPTION_impdef, 0},
#endif
    { NULL, 0, 0 },
};

static const FlagDef options_W[] = {
    { 0, 0, "all" },
    { offsetof(SCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(SCCState, warn_write_strings), 0, "write-strings" },
    { offsetof(SCCState, warn_error), 0, "error" },
    { offsetof(SCCState, warn_gcc_compat), 0, "gcc-compat" },
    { offsetof(SCCState, warn_implicit_function_declaration), WD_ALL,
      "implicit-function-declaration" },
    { 0, 0, NULL }
};

static const FlagDef options_f[] = {
    { offsetof(SCCState, char_is_unsigned), 0, "unsigned-char" },
    { offsetof(SCCState, char_is_unsigned), FD_INVERT, "signed-char" },
    { offsetof(SCCState, nocommon), FD_INVERT, "common" },
    { offsetof(SCCState, leading_underscore), 0, "leading-underscore" },
    { offsetof(SCCState, ms_extensions), 0, "ms-extensions" },
    { offsetof(SCCState, dollars_in_identifiers), 0, "dollars-in-identifiers" },
    { 0, 0, NULL }
};

static const FlagDef options_m[] = {
    { offsetof(SCCState, ms_bitfields), 0, "ms-bitfields" },
#if (__SCC_TARGET_CPU_ID__==__SCC_CPU_X86__ && __SCC_TARGET_CPU_BIT__==64)
    { offsetof(SCCState, nosse), FD_INVERT, "sse" },
#endif
    { 0, 0, NULL }
};

static void parse_option_D(SCCState *s1, const char *optarg)
{
    char *sym = scc_strdup(optarg);
    char *value = SCC(strchr,char*)(sym, '=');
    if (value)
        *value++ = '\0';
    scc_define_symbol(s1, sym, value);
    scc_free(sym);
}

static void args_parser_add_file(SCCState *s, const char* filename, int filetype)
{
    struct filespec *f = scc_malloc(sizeof *f + SCC(strlen,int)(filename));
    f->type = filetype;
    SCC(strcpy)(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
}

static int args_parser_make_argv(const char *r, int *argc, char ***argv)
{
    int ret = 0, q, c;
    CString str;
    for(;;) {
        while (c = (unsigned char)*r, c && c <= ' ')
	    ++r;
        if (c == 0)
            break;
        q = 0;
        cstr_new(&str);
        while (c = (unsigned char)*r, c) {
            ++r;
            if (c == '\\' && (*r == '"' || *r == '\\')) {
                c = *r++;
            } else if (c == '"') {
                q = !q;
                continue;
            } else if (q == 0 && c <= ' ') {
                break;
            }
            cstr_ccat(&str, c);
        }
        cstr_ccat(&str, 0);
        dynarray_add(argv, argc, scc_strdup(str.data));
        cstr_free(&str);
        ++ret;
    }
    return ret;
}

/* read list file */
static void args_parser_listfile(SCCState *s,
    const char *filename, int optind, int *pargc, char ***pargv)
{
    int fd, i;
    size_t len;
    char *p;
    int argc = 0;
    char **argv = NULL;

    fd = SCC(open,int)(filename, O_RDONLY | O_BINARY);
    if (fd < 0)
        scc_error("listfile '%s' not found", filename);

    len = SCC(lseek,size_t)(fd, 0, SEEK_END);
    p = scc_malloc(len + 1), p[len] = 0;
    SCC(lseek)(fd, 0, SEEK_SET), SCC(read)(fd, p, len), SCC(close)(fd);

    for (i = 0; i < *pargc; ++i)
        if (i == optind)
            args_parser_make_argv(p, &argc, &argv);
        else
            dynarray_add(&argv, &argc, scc_strdup((*pargv)[i]));

    scc_free(p);
    dynarray_reset(&s->argv, &s->argc);
    *pargc = s->argc = argc, *pargv = s->argv = argv;
}

PUB_FUNC int scc_parse_args(SCCState *s, int *pargc, char ***pargv, int optind)
{
	const SCCOption *popt=NULL;
	const char *optarg, *r;
	const char *run = NULL;
	int last_o = -1;
	int x;
	CString linker_arg; /* collect -Wl options */
	int tool = 0, arg_start = 0, noaction = optind;
	char **argv = *pargv;
	int argc = *pargc;

	cstr_new(&linker_arg);

	while (optind < argc) {
		r = argv[optind];
		if (r[0] == '@' && r[1] != '\0') {
			args_parser_listfile(s, r + 1, optind, &argc, &argv);
			continue;
		}
		optind++;
		if (tool) {
			if (r[0] == '-' && r[1] == 'v' && r[2] == 0)
				++s->verbose;
			continue;
		}
reparse:
		if (r[0] != '-' || r[1] == '\0') {
			if (r[0] != '@') /* allow "scc file(s) -run @ args ..." */
				args_parser_add_file(s, r, s->filetype);
			if (run) {
				scc_set_options(s, run);
				arg_start = optind - 1;
				break;
			}
			continue;
		}

		/* find option in table */
		for(popt = scc_options; ; ++popt) {
			const char *p1 = popt->name;
			const char *r1 = r + 1;
			if (p1 == NULL)
				scc_error("invalid option -- '%s'", r);
			if (!strstart(p1, &r1))
				continue;
			optarg = r1;
			if (popt->flags & SCC_OPTION_HAS_ARG) {
				if (*r1 == '\0' && !(popt->flags & SCC_OPTION_NOSEP)) {
					if (optind >= argc)
						arg_err:
							scc_error("argument to '%s' is missing", r);
					optarg = argv[optind++];
				}
			} else if (*r1 != '\0')
				continue;
			break;
		}

		switch(popt->index) {
			case SCC_OPTION_HELP:
				return OPT_HELP;
			case SCC_OPTION_HELP2:
				return OPT_HELP2;
			case SCC_OPTION_I:
				scc_add_include_path(s, optarg);
				break;
			case SCC_OPTION_D:
				parse_option_D(s, optarg);
				break;
			case SCC_OPTION_U:
				scc_undefine_symbol(s, optarg);
				break;
			case SCC_OPTION_L://-L
				scc_add_library_path(s, optarg);
				break;
			case SCC_OPTION_B:
				/* set scc utilities path (mainly for scc development) */
				scc_set_lib_path(s, optarg);
				break;
			case SCC_OPTION_l://-l??
				args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
				s->nb_libraries++;
				break;
			case SCC_OPTION_pthread:
				parse_option_D(s, "_REENTRANT");
				s->option_pthread = 1;
				break;
			case SCC_OPTION_bench:
				s->do_bench = 1;
				break;
#ifdef CONFIG_SCC_BACKTRACE
			case SCC_OPTION_bt:
				scc_set_num_callers(SCC(atoi,int)(optarg));
				break;
#endif
			case SCC_OPTION_g:
				s->do_debug = 1;
				break;
			case SCC_OPTION_c:
				x = SCC_OUTPUT_OBJ;
set_output_type:
				if (s->output_type)
					scc_warning("-%s: overriding compiler action already specified", popt->name);
				s->output_type = x;
				break;
			case SCC_OPTION_d:
				if (*optarg == 'D')
					s->dflag = 3;
				else if (*optarg == 'M')
					s->dflag = 7;
				else if (*optarg == 't')
					s->dflag = 16;
				else if (isnum(*optarg))
					g_debug = SCC(atoi,int)(optarg);
				else
					goto unsupported_option;
				break;
			case SCC_OPTION_static:
				s->static_link = 1;
				break;
			case SCC_OPTION_std:
				/* silently ignore, a current purpose:
					 allow to use a scc as a reference compiler for "make test" */
				break;
			case SCC_OPTION_shared:
				x = SCC_OUTPUT_DLL;
				goto set_output_type;
			case SCC_OPTION_soname:
				s->soname = scc_strdup(optarg);
				break;
			case SCC_OPTION_o:
				if (s->outfile) {
					scc_warning("multiple -o option");
					scc_free(s->outfile);
				}
				s->outfile = scc_strdup(optarg);
				break;
			case SCC_OPTION_r:
				/* generate a .o merging several output files */
				s->option_r = 1;
				x = SCC_OUTPUT_OBJ;
				goto set_output_type;
			case SCC_OPTION_isystem:
				scc_add_sysinclude_path(s, optarg);
				break;
			case SCC_OPTION_include:
				dynarray_add(&s->cmd_include_files,
						&s->nb_cmd_include_files, scc_strdup(optarg));
				break;
			case SCC_OPTION_nostdinc:
				s->nostdinc = 1;
				break;
			case SCC_OPTION_nostdlib:
				s->nostdlib = 1;
				break;
			case SCC_OPTION_run:
#if __SCC_TARGET_CROSS__==1
				scc_warning("%s = %s", "__SCC_TARGET_CPU__", SCC_QUOTE(__SCC_TARGET_CPU__));
				scc_warning("%s = %s", "__SCC_TARGET_OS__", SCC_QUOTE(__SCC_TARGET_OS__));
				scc_warning("%s = %s", "__SCC_TARGET_FORMAT__", SCC_QUOTE(__SCC_TARGET_FORMAT__));
				scc_warning("%s = %s", "__SCC_TARGET_CPU_BIT__", SCC_QUOTE(__SCC_TARGET_CPU_BIT__));

				scc_warning("%s = %s", "__SCC_CPU__", SCC_QUOTE(__SCC_CPU__));
				scc_warning("%s = %s", "__SCC_OS__", SCC_QUOTE(__SCC_OS__));
				scc_warning("%s = %s", "__SCC_OS_FORMAT__", SCC_QUOTE(__SCC_OS_FORMAT__));
				scc_warning("%s = %s", "__SCC_CPU_BIT__", SCC_QUOTE(__SCC_CPU_BIT__));

				scc_warning("%s,%s,%s,%s", "__SCC_OS_ID__,__SCC_TARGET_OS_ID__", SCC_QUOTE(__SCC_OS_ID__),SCC_QUOTE(__SCC_TARGET_OS_ID__));
				scc_warning("%s,%s,%s,%s", "__SCC_CPU_ID__,__SCC_TARGET_CPU_ID__", SCC_QUOTE(__SCC_CPU_ID__),SCC_QUOTE(__SCC_TARGET_CPU_ID__));
				scc_warning("%s,%s,%s,%s", "__SCC_OS_FORMAT_ID__,__SCC_TARGET_FORMAT_ID__", SCC_QUOTE(__SCC_OS_FORMAT_ID__),SCC_QUOTE(__SCC_TARGET_FORMAT_ID__));
				//scc_error("-run is not available in a cross compiler");
				scc_warning("-run might work fail for cross compiler!");
#endif
				run = optarg;
				x = SCC_OUTPUT_MEMORY;
				goto set_output_type;
			case SCC_OPTION_v:
				do ++s->verbose; while (*optarg++ == 'v');
				++noaction;
				break;
			case SCC_OPTION_f:
				if (set_flag(s, options_f, optarg) < 0)
					goto unsupported_option;
				break;
#if (__SCC_TARGET_CPU_ID__==__SCC_CPU_ARM__ && __SCC_TARGET_CPU_BIT__==32)
			case SCC_OPTION_mfloat_abi:
				//TODO doesn't support soft float yet
				if (!SCC(strcmp,int)(optarg, "softfp")) {
					s->float_abi = ARM_SOFTFP_FLOAT;
					scc_undefine_symbol(s, "__ARM_PCS_VFP");
				} else if (!SCC(strcmp,int)(optarg, "hard"))
					s->float_abi = ARM_HARD_FLOAT;
				else
					scc_error("unsupported float abi '%s'", optarg);
				break;
#endif
			case SCC_OPTION_m:
				if (set_flag(s, options_m, optarg) < 0) {
					if (x = SCC(atoi,int)(optarg), x != 32 && x != 64)
						goto unsupported_option;
					if (PTR_SIZE != x/8)
						return x;
					++noaction;
				}
				break;
			case SCC_OPTION_W:
				if (set_flag(s, options_W, optarg) < 0)
					goto unsupported_option;
				break;
			case SCC_OPTION_w:
				s->warn_none = 1;
				break;
			case SCC_OPTION_rdynamic:
				s->rdynamic = 1;
				break;
			case SCC_OPTION_Wl:
				if (linker_arg.size)
					--linker_arg.size, cstr_ccat(&linker_arg, ',');
				cstr_cat(&linker_arg, optarg, 0);
				if (scc_set_linker(s, linker_arg.data))
					cstr_free(&linker_arg);
				break;
			case SCC_OPTION_Wp:
				r = optarg;
				goto reparse;
			case SCC_OPTION_E:
				x = SCC_OUTPUT_PREPROCESS;
				goto set_output_type;
			case SCC_OPTION_P:
				s->Pflag = SCC(atoi,int)(optarg) + 1;
				break;
			case SCC_OPTION_MD:
				s->gen_deps = 1;
				break;
			case SCC_OPTION_MF:
				s->deps_outfile = scc_strdup(optarg);
				break;
			case SCC_OPTION_dumpversion:
				SCC(printf)("%s\n", SCC_VERSION);
				SCC(exit)(0);
				break;
			case SCC_OPTION_x:
				x = 0;
				if (*optarg == 'c')
					x = AFF_TYPE_C;
				else if (*optarg == 'a')
					x = AFF_TYPE_ASMPP;
				else if (*optarg == 'b')
					x = AFF_TYPE_BIN;
				else if (*optarg == 's')
					x = AFF_TYPE_SAO;
				else if (*optarg == 'n')
					x = AFF_TYPE_NONE;
				else
					scc_warning("unsupported language -x '%s'", optarg);
				s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
				break;
			case SCC_OPTION_O:
				last_o = SCC(atoi,int)(optarg);
				break;
			case SCC_OPTION_print_search_dirs:
				x = OPT_PRINT_DIRS;
				goto extra_action;
			case SCC_OPTION_impdef:
				x = OPT_IMPDEF;
				goto extra_action;
			case SCC_OPTION_ar:
				x = OPT_AR;
extra_action:
				arg_start = optind - 1;
				if (arg_start != noaction)
					scc_error("cannot parse %s here", r);
				tool = x;
				break;
			case SCC_OPTION_traditional:
			case SCC_OPTION_pedantic:
			case SCC_OPTION_pipe:
			case SCC_OPTION_s:
				/* ignored */
				break;
			default:
unsupported_option:
				if (s->warn_unsupported)
					scc_warning("unsupported option '%s'", r);
				break;
		}
	}
	if (last_o > 0)
		scc_define_symbol(s, "__OPTIMIZE__", NULL);
	if (linker_arg.size) {
		r = linker_arg.data;
		goto arg_err;
	}
	*pargc = argc - arg_start;
	*pargv = argv + arg_start;
	if (tool)
		return tool;
	if (optind != noaction)
		return 0;
	if (s->verbose == 2)
		return OPT_PRINT_DIRS;
	if (s->verbose)
		return OPT_V;
	return OPT_HELP;
}

LIBSCCAPI void scc_set_options(SCCState *s, const char *r)
{
    char **argv = NULL;
    int argc = 0;
    args_parser_make_argv(r, &argc, &argv);
    scc_parse_args(s, &argc, &argv, 0);
    dynarray_reset(&argv, &argc);
}

PUB_FUNC void scc_print_stats(SCCState *s, unsigned total_time)
{
    if (total_time < 1)
        total_time = 1;
    if (total_bytes < 1)
        total_bytes = 1;
    SCC(fprintf)(SCCSTD(err), "* %d idents, %d lines, %d bytes\n"
                    "* %0.3f s, %u lines/s, %0.1f MB/s\n",
           tok_ident - TOK_IDENT, total_lines, total_bytes,
           (double)total_time/1000,
           (unsigned)total_lines*1000/total_time,
           (double)total_bytes/1000/total_time);
#ifdef MEM_DEBUG
    SCC(fprintf)(SCCSTD(err), "* %d bytes memory used\n", mem_max_size);
#endif
}
