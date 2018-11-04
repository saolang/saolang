#include "scc.h"

#if ONE_SOURCE
# include "libscc.c"
#endif

#include "scctools.c"

static const char help[] =
    "Sao CC "SCC_VERSION" - \n"
    "   scc [options...] [-o outfile] [-c] infile(s)...\n"
    "   scc [options...] -run infile [arguments...]\n"
    "General:\n"
    "  -c          compile only - generate an object file\n"
    "  -o outfile  set output filename\n"
    "  -run        run compiled source\n"
    "  -fflag      set or reset (with 'no-' prefix) 'flag' (see scc -hh)\n"
    "  -Wwarning   set or reset (with 'no-' prefix) 'warning' (see scc -hh)\n"
    "  -w          disable all warnings\n"
    "  -v -vv      show version, show search paths or loaded files\n"
    "  -h -hh      show this, show more help\n"
    "  -bench      show compilation statistics\n"
    "  -           use stdin pipe as infile\n"
    "  @listfile   read arguments from listfile\n"
    "Preprocessor:\n"
    "  -Idir       add include path 'dir'\n"
    "  -Dsym[=val] define 'sym' with value 'val'\n"
    "  -Usym       undefine 'sym'\n"
    "  -E          preprocess only\n"
    "Linker:\n"
    "  -Ldir       add library path 'dir'\n"
    "  -llib       link with dynamic or static library 'lib'\n"
    "  -r          generate (relocatable) object file\n"
    "  -shared     generate a shared library/dll\n"
    "  -rdynamic   export all global symbols to dynamic linker\n"
    "  -soname     set name for shared library to be used at runtime\n"
    "  -Wl,-opt[=val]  set linker option (see scc -hh)\n"
    "Debugger:\n"
    "  -g          generate runtime debug info\n"
#ifdef CONFIG_SCC_BACKTRACE
    "  -bt N       show N callers in stack traces\n"
#endif
    "Misc. options:\n"
    "  -x[c|a|b|n] specify type of the next infile (C,ASM,BIN,NONE)\n"
    "  -nostdinc   do not use standard system include paths\n"
    "  -nostdlib   do not link with standard crt and libraries\n"
    "  -Bdir       set scc's private include/library dir\n"
    "  -MD         generate dependency file for make\n"
    "  -MF file    specify dependency file name\n"
    "  -m32/64     defer to i386/x86_64 cross compiler\n"
    "Tools:\n"
    "  create library  : scc -ar [rcsv] lib.a files\n"
#ifdef SCC_TARGET_PE
    "  create def file : scc -impdef lib.dll [-v] [-o lib.def]\n"
#endif
    ;

static const char help2[] =
    "Sao C Compiler "SCC_VERSION" - More Options\n"
    "Special options:\n"
    "  -P -P1                        with -E: no/alternative #line output\n"
    "  -dD -dM                       with -E: output #define directives\n"
    "  -pthread                      same as -D_REENTRANT and -lpthread\n"
    "  -On                           same as -D__OPTIMIZE__ for n > 0\n"
    "  -Wp,-opt                      same as -opt\n"
    "  -include file                 include 'file' above each input file\n"
    "  -isystem dir                  add 'dir' to system include path\n"
    "  -static                       link to static libraries (not recommended)\n"
    "  -dumpversion                  print version\n"
    "  -print-search-dirs            print search paths\n"
    "  -dt                           with -run/-E: auto-define 'test_...' macros\n"
    "Ignored options:\n"
    "  --param  -pedantic  -pipe  -s  -std  -traditional\n"
    "-W... warnings:\n"
    "  all                           turn on some (*) warnings\n"
    "  error                         stop after first warning\n"
    "  unsupported                   warn about ignored options, pragmas, etc.\n"
    "  write-strings                 strings are const\n"
    "  implicit-function-declaration warn for missing prototype (*)\n"
    "-f[no-]... flags:\n"
    "  unsigned-char                 default char is unsigned\n"
    "  signed-char                   default char is signed\n"
    "  common                        use common section instead of bss\n"
    "  leading-underscore            decorate extern symbols\n"
    "  ms-extensions                 allow anonymous struct in struct\n"
    "  dollars-in-identifiers        allow '$' in C symbols\n"
    "-m... target specific options:\n"
    "  ms-bitfields                  use MSVC bitfield layout\n"
#ifdef SCC_TARGET_ARM
    "  float-abi                     hard/softfp on arm\n"
#endif
#ifdef SCC_TARGET_X86_64
    "  no-sse                        disable floats on x86_64\n"
#endif
    "-Wl,... linker options:\n"
    "  -nostdlib                     do not link with standard crt/libs\n"
    "  -[no-]whole-archive           load lib(s) fully/only as needed\n"
    "  -export-all-symbols           same as -rdynamic\n"
    "  -export-dynamic               same as -rdynamic\n"
    "  -image-base= -Ttext=          set base address of executable\n"
    "  -section-alignment=           set section alignment in executable\n"
#ifdef SCC_TARGET_PE
    "  -file-alignment=              set PE file alignment\n"
    "  -stack=                       set PE stack reserve\n"
    "  -large-address-aware          set related PE option\n"
    "  -subsystem=[console/windows]  set PE subsystem\n"
    "  -oformat=[pe-* binary]        set executable output format\n"
    "Predefined macros:\n"
    "  scc -E -dM - < nul\n"
#else
    "  -rpath=                       set dynamic library search path\n"
    "  -enable-new-dtags             set DT_RUNPATH instead of DT_RPATH\n"
    "  -soname=                      set DT_SONAME elf tag\n"
    "  -Bsymbolic                    set DT_SYMBOLIC elf tag\n"
    "  -oformat=[elf32/64-* binary]  set executable output format\n"
    "  -init= -fini= -as-needed -O   (ignored)\n"
    "Predefined macros:\n"
    "  scc -E -dM - < /dev/null\n"
#endif
    "See also the manual for more details.\n"
    ;

static const char version[] =
    "scc version "SCC_VERSION" ("
#ifdef SCC_TARGET_I386
        "i386"
#elif defined SCC_TARGET_X86_64
        "x86_64"
#elif defined SCC_TARGET_C67
        "C67"
#elif defined SCC_TARGET_ARM
        "ARM"
#elif defined SCC_TARGET_ARM64
        "AArch64"
#endif
#ifdef SCC_ARM_HARDFLOAT
        " Hard Float"
#endif
#ifdef SCC_TARGET_PE
        " Windows"
#elif defined(SCC_TARGET_MACHO)
        " Darwin"
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
        " FreeBSD"
#else
        " Linux"
#endif
    ")\n"
    ;

static void print_dirs(const char *msg, char **paths, int nb_paths)
{
    int i;
    SCC(printf)("%s:\n%s", msg, nb_paths ? "" : "  -\n");
    for(i = 0; i < nb_paths; i++)
        SCC(printf)("  %s\n", paths[i]);
}

static void print_search_dirs(SCCState *s)
{
	SCC(printf)("install(scc_lib_path): %s\n", s->scc_lib_path);
	/* print_dirs("programs", NULL, 0); */
	print_dirs("include", s->sysinclude_paths, s->nb_sysinclude_paths);
	print_dirs("libraries", s->library_paths, s->nb_library_paths);
#ifdef SCC_TARGET_PE
#ifdef SCC_LIBSCC1
	SCC(printf)("libscc1(win):\n  %s/"SCC_LIBSCC1"\n", s->scc_lib_path);
#endif
#elif defined(SCC_TARGET_MACHO)
#ifdef SCC_LIBSCC1
	SCC(printf)("libscc1(osx):\n  %s/"SCC_LIBSCC1"\n", s->scc_lib_path);
#endif
#else //assume ELF
#ifdef SCC_LIBSCC1
	SCC(printf)("libscc1(elf):\n  %s/"SCC_LIBSCC1"\n", s->scc_lib_path);
#endif
	print_dirs("crt", s->crt_paths, s->nb_crt_paths);
	SCC(printf)("elfinterp:\n  %s\n",  DEFAULT_ELFINTERP(s));
#endif
}

static void set_environment(SCCState *s)
{
    char * path;

    path = SCC(getenv)("C_INCLUDE_PATH");
    if(path != NULL) {
        scc_add_sysinclude_path(s, path);
    }
    path = SCC(getenv)("CPATH");
    if(path != NULL) {
        scc_add_include_path(s, path);
    }
    path = SCC(getenv)("LIBRARY_PATH");
    if(path != NULL) {
        scc_add_library_path(s, path);
    }
}

static char *default_outputfile(SCCState *s, const char *first_file)
{
    char buf[1024];
    char *ext;
    const char *name = "a";

    if (first_file && SCC(strcmp,int)(first_file, "-"))
        name = scc_basename(first_file);
    SCC(snprintf)(buf, sizeof(buf), "%s", name);
    ext = scc_fileextension(buf);
#ifdef SCC_TARGET_PE
    if (s->output_type == SCC_OUTPUT_DLL)
        SCC(strcpy)(ext, ".dll");
    else
    if (s->output_type == SCC_OUTPUT_EXE)
        SCC(strcpy)(ext, ".exe");
    else
#endif
    if (s->output_type == SCC_OUTPUT_OBJ && !s->option_r && *ext)
        SCC(strcpy)(ext, ".o");
    else
        SCC(strcpy)(buf, "a.out");
    return scc_strdup(buf);
}

static unsigned getclock_ms(void)
{
#ifdef _WIN32
    return SCC(GetTickCount,unsigned)();
#else
    struct timeval tv;
    SCC(gettimeofday)(&tv, NULL);
    return tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

#ifndef SCC_DLL
int main(int argc0, char **argv0)
#else
//output as dll/so with scc_main()
#ifdef SCC_TARGET_PE
//#include <windows.h>
__declspec(dllexport) int scc_main(int argc0, char **argv0)
#else
int scc_main(int argc0, char **argv0)
#endif

#endif
{
    SCCState *s;
    int ret, opt, n = 0, t = 0;
    unsigned start_time = 0;
    const char *first_file;
    int argc; char **argv;
    FILE *ppfp = SCCSTD(out);

redo:
    argc = argc0, argv = argv0;
    s = scc_new();
    opt = scc_parse_args(s, &argc, &argv, 1);

    if ((n | t) == 0) {
        if (opt == OPT_HELP)
            return SCC(printf)(help), 1;
        if (opt == OPT_HELP2)
            return SCC(printf)(help2), 1;
        if (opt == OPT_M32 || opt == OPT_M64)
            scc_tool_cross(s, argv, opt); /* never returns */
        if (s->verbose)
            SCC(printf)(version);
        if (opt == OPT_AR)
            return scc_tool_ar(s, argc, argv);
#ifdef SCC_TARGET_PE
        if (opt == OPT_IMPDEF)
            return scc_tool_impdef(s, argc, argv);
#endif
        if (opt == OPT_V)
            return 0;
        if (opt == OPT_PRINT_DIRS) {
            /* initialize search dirs */
            set_environment(s);
            scc_set_output_type(s, SCC_OUTPUT_MEMORY);
            print_search_dirs(s);
            return 0;
        }

        n = s->nb_files;
        if (n == 0)
            scc_error("no input files\n");

        if (s->output_type == SCC_OUTPUT_PREPROCESS) {
            if (s->outfile) {
                ppfp = SCC(fopen)(s->outfile, "w");
                if (!ppfp)
                    scc_error("PREPROCESS: could not write '%s'", s->outfile);
            }
        } else if (s->output_type == SCC_OUTPUT_OBJ && !s->option_r) {
            if (s->nb_libraries)
                scc_error("cannot specify libraries with -c");
            if (n > 1 && s->outfile)
                scc_error("cannot specify output file with -c many files");
        } else {
            if (s->option_pthread) {
                scc_set_options(s, "-lpthread");
		n = s->nb_files;
	    }
        }

        if (s->do_bench)
            start_time = getclock_ms();
    }

    set_environment(s);
    if (s->output_type == 0)
        s->output_type = SCC_OUTPUT_EXE;
    scc_set_output_type(s, s->output_type);
    s->ppfp = ppfp;

    if ((s->output_type == SCC_OUTPUT_MEMORY
      || s->output_type == SCC_OUTPUT_PREPROCESS) && (s->dflag & 16))
        s->dflag |= t ? 32 : 0, s->run_test = ++t, n = s->nb_files;

    /* compile or add each files or library */
    for (first_file = NULL, ret = 0;;) {
        struct filespec *f = s->files[s->nb_files - n];
        s->filetype = f->type;
        if (f->type & AFF_TYPE_LIB) {
            if (scc_add_library_err(s, f->name) < 0)
                ret = 1;
        } else {
            if (1 == s->verbose)
                SCC(printf)("-> %s\n", f->name);
            if (!first_file)
                first_file = f->name;
            if (scc_add_file(s, f->name) < 0)
                ret = 1;
        }
        if (--n == 0 || ret
            || (s->output_type == SCC_OUTPUT_OBJ && !s->option_r))
            break;
    }

    if (s->run_test) {
        t = 0;
    } else if (s->output_type == SCC_OUTPUT_PREPROCESS) {
			//TODO plan to add preprocess-ed .c
        ;
    } else if (0 == ret) {
        if (s->output_type == SCC_OUTPUT_MEMORY) {
#ifdef SCC_IS_NATIVE
            ret = scc_run(s, argc, argv);
#endif
        } else {
            if (!s->outfile)
                s->outfile = default_outputfile(s, first_file);
						//TODO support +macho
            if (scc_output_file(s, s->outfile))
                ret = 1;
            else if (s->gen_deps)
                gen_makedeps(s, s->outfile, s->deps_outfile);
        }
    }

    if (s->do_bench && (n | t | ret) == 0)
        scc_print_stats(s, getclock_ms() - start_time);
    scc_delete(s);
    if (ret == 0 && n)
        goto redo; /* compile more files with -c */
    if (t)
        goto redo; /* run more tests with -dt -run */
    if (ppfp && ppfp != SCCSTD(out))
        SCC(fclose)(ppfp);
    return ret;
}
