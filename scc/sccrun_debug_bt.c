#ifdef CONFIG_SCC_BACKTRACE

//#warning "TODO sccrun_debug_bt"

# ifndef _WIN32//{

//TODO maybe remove signal.h dependency in future...

#define _GNU_SOURCE //for REG_EIP in singal.h
#  include <signal.h>
#  ifndef __OpenBSD__
//TODO remove ucontext dependency in future..
#   include <sys/ucontext.h>
#  endif

# else//}_WIN32
//TODO
#  define ucontext_t CONTEXT
# endif//_WIN32

ST_DATA int rt_num_callers = 6;
ST_DATA const char **rt_bound_error_msg;
ST_DATA void *rt_prog_main;
static int rt_get_caller_pc(addr_t *paddr, ucontext_t *uc, int level);

//static void rt_error(ucontext_t *uc, const char *fmt, ...);
#define rt_error(uc, ...) \
{\
    addr_t pc;\
    int i;\
    SCC(fprintf)(SCCSTD(err), "Runtime error: ");\
    SCC(vfprintf)(SCCSTD(err), __VA_ARGS__);\
    SCC(fprintf)(SCCSTD(err), "\n");\
    for(i=0;i<rt_num_callers;i++) {\
        if (rt_get_caller_pc(&pc, uc, i) < 0) break;\
        pc = rt_printline(pc, i ? "by" : "at");\
        if (pc == (addr_t)rt_prog_main && pc) break;\
    }\
}

static void set_exception_handler(void);

ST_FUNC void scc_set_num_callers(int n)
{
    rt_num_callers = n;
}

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
static addr_t rt_printline(addr_t wanted_pc, const char *msg)
{
    char func_name[128], last_func_name[128];
    addr_t func_addr, last_pc, pc;
    const char *incl_files[INCLUDE_STACK_SIZE];
    int incl_index, len, last_line_num, i;
    const char *str, *p;

    Stab_Sym *stab_sym = NULL, *stab_sym_end, *sym;
    int stab_len = 0;
    char *stab_str = NULL;

    if (stab_section) {
        stab_len = stab_section->data_offset;
        stab_sym = (Stab_Sym *)stab_section->data;
        stab_str = (char *) stabstr_section->data;
    }

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_func_name[0] = '\0';
    last_pc = (addr_t)-1;
    last_line_num = 1;

    if (!stab_sym)
        goto no_stabs;

    stab_sym_end = (Stab_Sym*)((char*)stab_sym + stab_len);
    for (sym = stab_sym + 1; sym < stab_sym_end; ++sym) {
        switch(sym->n_type) {
            /* function start or end */
        case N_FUN:
            if (sym->n_strx == 0) {
                /* we test if between last line and end of function */
                pc = sym->n_value + func_addr;
                if (wanted_pc >= last_pc && wanted_pc < pc)
                    goto found;
                func_name[0] = '\0';
                func_addr = 0;
            } else {
                str = stab_str + sym->n_strx;
                p = SCC(strchr)(str, ':');
                if (!p) {
                    pstrcpy(func_name, sizeof(func_name), str);
                } else {
                    len = p - str;
                    if (len > sizeof(func_name) - 1)
                        len = sizeof(func_name) - 1;
                    SCC(memcpy)(func_name, str, len);
                    func_name[len] = '\0';
                }
                func_addr = sym->n_value;
            }
            break;
            /* line number info */
        case N_SLINE:
            pc = sym->n_value + func_addr;
            if (wanted_pc >= last_pc && wanted_pc < pc)
                goto found;
            last_pc = pc;
            last_line_num = sym->n_desc;
            /* TODO XXX: slow! */
            SCC(strcpy)(last_func_name, func_name);
            break;
            /* include files */
        case N_BINCL:
            str = stab_str + sym->n_strx;
        add_incl:
            if (incl_index < INCLUDE_STACK_SIZE) {
                incl_files[incl_index++] = str;
            }
            break;
        case N_EINCL:
            if (incl_index > 1)
                incl_index--;
            break;
        case N_SO:
            if (sym->n_strx == 0) {
                incl_index = 0; /* end of translation unit */
            } else {
                str = stab_str + sym->n_strx;
                /* do not add path */
                len = SCC(strlen,int)(str);
                if (len > 0 && str[len - 1] != '/')
                    goto add_incl;
            }
            break;
        }
    }

no_stabs:
    /* second pass: we try symtab symbols (no line number info) */
    incl_index = 0;
    if (symtab_section)
    {
        ElfW(Sym) *sym, *sym_end;
        int type;

        sym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
        for(sym = (ElfW(Sym) *)symtab_section->data + 1;
            sym < sym_end;
            sym++) {
            type = ELFW(ST_TYPE)(sym->st_info);
            if (type == STT_FUNC || type == STT_GNU_IFUNC) {
                if (wanted_pc >= sym->st_value &&
                    wanted_pc < sym->st_value + sym->st_size) {
                    pstrcpy(last_func_name, sizeof(last_func_name),
                            (char *) symtab_section->link->data + sym->st_name);
                    func_addr = sym->st_value;
                    goto found;
                }
            }
        }
    }
    /* did not find any info: */
    SCC(fprintf)(SCCSTD(err), "%s %p ???\n", msg, (void*)wanted_pc);
    SCC(fflush)(SCCSTD(err));
    return 0;
 found:
    i = incl_index;
    if (i > 0)
        SCC(fprintf)(SCCSTD(err), "%s:%d: ", incl_files[--i], last_line_num);
    SCC(fprintf)(SCCSTD(err), "%s %p", msg, (void*)wanted_pc);
    if (last_func_name[0] != '\0')
        SCC(fprintf)(SCCSTD(err), " %s()", last_func_name);
    if (--i >= 0) {
        SCC(fprintf)(SCCSTD(err), " (included from ");
        for (;;) {
            SCC(fprintf)(SCCSTD(err), "%s", incl_files[i]);
            if (--i < 0)
                break;
            SCC(fprintf)(SCCSTD(err), ", ");
        }
        SCC(fprintf)(SCCSTD(err), ")");
    }
    SCC(fprintf)(SCCSTD(err), "\n");
    SCC(fflush)(SCCSTD(err));
    return func_addr;
}

/* emit a run time error at position 'pc' */
//static void rt_error(ucontext_t *uc, const char *fmt, ...)
//{
//    va_list ap;
//    addr_t pc;
//    int i;
//
//    SCC(fprintf)(SCCSTD(err), "Runtime error: ");
//    va_start(ap, fmt);
//    SCC(vfprintf)(SCCSTD(err), fmt, ap);
//    va_end(ap);
//    SCC(fprintf)(SCCSTD(err), "\n");
//
//    for(i=0;i<rt_num_callers;i++) {
//        if (rt_get_caller_pc(&pc, uc, i) < 0)
//            break;
//        pc = rt_printline(pc, i ? "by" : "at");
//        if (pc == (addr_t)rt_prog_main && pc)
//            break;
//    }
//}

/* ------------------------------------------------------------- */
#ifndef _WIN32

/* signal handler for fatal errors */
static void sig_error(int signum, siginfo_t *siginf, void *puc)
{
    ucontext_t *uc = puc;

    switch(signum) {
    case SIGFPE:
        switch(siginf->si_code) {
        case FPE_INTDIV:
        case FPE_FLTDIV:
            rt_error(uc, "division by zero");
            break;
        default:
            rt_error(uc, "floating point exception");
            break;
        }
        break;
    case SIGBUS:
    case SIGSEGV:
        if (rt_bound_error_msg && *rt_bound_error_msg){
            rt_error(uc, *rt_bound_error_msg);
				}else{
            rt_error(uc, "dereferencing invalid pointer");
				}
        break;
    case SIGILL:
        rt_error(uc, "illegal instruction");
        break;
    case SIGABRT:
        rt_error(uc, "abort() called");
        break;
    default:
        rt_error(uc, "caught signal %d", signum);
        break;
    }
    SCC(exit)(255);
}

#ifndef SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#endif

/* Generate a stack backtrace when a CPU exception occurs. */
static void set_exception_handler(void)
{
    struct sigaction sigact;
    /* install SCC signal handlers to print debug info on fatal
       runtime errors */
    sigact.sa_flags = SA_SIGINFO | SA_RESETHAND;
    sigact.sa_sigaction = sig_error;
    SCC(sigemptyset)(&sigact.sa_mask);
    SCC(sigaction)(SIGFPE, &sigact, NULL);
    SCC(sigaction)(SIGILL, &sigact, NULL);
    SCC(sigaction)(SIGSEGV, &sigact, NULL);
    SCC(sigaction)(SIGBUS, &sigact, NULL);
    SCC(sigaction)(SIGABRT, &sigact, NULL);
}

/* ------------------------------------------------------------- */
#ifdef __i386__

/* fix for glibc 2.1 */
#ifndef REG_EIP
#define REG_EIP EIP
#define REG_EBP EBP
#endif

/* return the PC at frame level 'level'. Return negative if not found */
static int rt_get_caller_pc(addr_t *paddr, ucontext_t *uc, int level)
{
    addr_t fp;
    int i;

    if (level == 0) {
#if defined(__APPLE__)
        *paddr = uc->uc_mcontext->__ss.__eip;
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
        *paddr = uc->uc_mcontext.mc_eip;
#elif defined(__dietlibc__)
        *paddr = uc->uc_mcontext.eip;
#elif defined(__NetBSD__)
        *paddr = uc->uc_mcontext.__gregs[_REG_EIP];
#elif defined(__OpenBSD__)
        *paddr = uc->sc_eip;
#else
        *paddr = uc->uc_mcontext.gregs[REG_EIP];
#endif
        return 0;
    } else {
#if defined(__APPLE__)
        fp = uc->uc_mcontext->__ss.__ebp;
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
        fp = uc->uc_mcontext.mc_ebp;
#elif defined(__dietlibc__)
        fp = uc->uc_mcontext.ebp;
#elif defined(__NetBSD__)
        fp = uc->uc_mcontext.__gregs[_REG_EBP];
#elif defined(__OpenBSD__)
        *paddr = uc->sc_ebp;
#else
        fp = uc->uc_mcontext.gregs[REG_EBP];
#endif
        for(i=1;i<level;i++) {
            /* XXX: check address validity with program info */
            if (fp <= 0x1000 || fp >= 0xc0000000)
                return -1;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
        return 0;
    }
}

/* ------------------------------------------------------------- */
#elif defined(__x86_64__)

/* return the PC at frame level 'level'. Return negative if not found */
static int rt_get_caller_pc(addr_t *paddr, ucontext_t *uc, int level)
{
    addr_t fp;
    int i;

    if (level == 0) {
#if defined(__APPLE__)
        *paddr = uc->uc_mcontext->__ss.__rip;
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
        *paddr = uc->uc_mcontext.mc_rip;
#elif defined(__NetBSD__)
        *paddr = uc->uc_mcontext.__gregs[_REG_RIP];
#else//linux
        *paddr = uc->uc_mcontext.gregs[REG_RIP];
#endif
        return 0;
    } else {
#if defined(__APPLE__)
        fp = uc->uc_mcontext->__ss.__rbp;
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
        fp = uc->uc_mcontext.mc_rbp;
#elif defined(__NetBSD__)
        fp = uc->uc_mcontext.__gregs[_REG_RBP];
#else
        fp = uc->uc_mcontext.gregs[REG_RBP];
#endif
        for(i=1;i<level;i++) {
            /* XXX: check address validity with program info */
            if (fp <= 0x1000)
                return -1;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
        return 0;
    }
}

/* ------------------------------------------------------------- */
#elif defined(__arm__)

/* return the PC at frame level 'level'. Return negative if not found */
static int rt_get_caller_pc(addr_t *paddr, ucontext_t *uc, int level)
{
    addr_t fp, sp;
    int i;

    if (level == 0) {
        /* XXX: only supports linux */
#if defined(__linux__)
        *paddr = uc->uc_mcontext.arm_pc;
#else
        return -1;
#endif
        return 0;
    } else {
#if defined(__linux__)
        fp = uc->uc_mcontext.arm_fp;
        sp = uc->uc_mcontext.arm_sp;
        if (sp < 0x1000)
            sp = 0x1000;
#else
        return -1;
#endif
        /* XXX: specific to stack frames */
        if (fp < sp + 12 || fp & 3)
            return -1;
        for(i = 1; i < level; i++) {
            sp = ((addr_t *)fp)[-2];
            if (sp < fp || sp - fp > 16 || sp & 3)
                return -1;
            fp = ((addr_t *)fp)[-3];
            if (fp <= sp || fp - sp < 12 || fp & 3)
                return -1;
        }
        /* XXX: check address validity with program info */
        *paddr = ((addr_t *)fp)[-1];
        return 0;
    }
}

/* ------------------------------------------------------------- */
#elif defined(__aarch64__)

static int rt_get_caller_pc(addr_t *paddr, ucontext_t *uc, int level)
{
    if (level < 0)
        return -1;
    else if (level == 0) {
        *paddr = uc->uc_mcontext.pc;
        return 0;
    }
    else {
        addr_t *fp = (addr_t *)uc->uc_mcontext.regs[29];
        int i;
        for (i = 1; i < level; i++)
            fp = (addr_t *)fp[0];
        *paddr = fp[1];
        return 0;
    }
}

/* ------------------------------------------------------------- */
#else

#warning add arch specific rt_get_caller_pc()
static int rt_get_caller_pc(addr_t *paddr, ucontext_t *uc, int level)
{
    return -1;
}

#endif /* !__i386__ */

/* ------------------------------------------------------------- */
#else /* WIN32 */

static long __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    EXCEPTION_RECORD *er = ex_info->ExceptionRecord;
    CONTEXT *uc = ex_info->ContextRecord;
    switch (er->ExceptionCode) {
    case EXCEPTION_ACCESS_VIOLATION:
        if (rt_bound_error_msg && *rt_bound_error_msg)
            rt_error(uc, *rt_bound_error_msg);
        else
	    rt_error(uc, "access violation");
        break;
    case EXCEPTION_STACK_OVERFLOW:
        rt_error(uc, "stack overflow");
        break;
    case EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(uc, "division by zero");
        break;
    default:
        rt_error(uc, "exception caught");
        break;
    }
    return EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
static void set_exception_handler(void)
{
    SetUnhandledExceptionFilter(cpu_exception_handler);
}

/* return the PC at frame level 'level'. Return non zero if not found */
static int rt_get_caller_pc(addr_t *paddr, CONTEXT *uc, int level)
{
    addr_t fp, pc;
    int i;
#ifdef _WIN64
    pc = uc->Rip;
    fp = uc->Rbp;
#else
    pc = uc->Eip;
    fp = uc->Ebp;
#endif
    if (level > 0) {
        for(i=1;i<level;i++) {
	    /* XXX: check address validity with program info */
	    if (fp <= 0x1000 || fp >= 0xc0000000)
		return -1;
	    fp = ((addr_t*)fp)[0];
	}
        pc = ((addr_t*)fp)[1];
    }
    *paddr = pc;
    return 0;
}

#endif /* _WIN32 */
#endif /* CONFIG_SCC_BACKTRACE */
