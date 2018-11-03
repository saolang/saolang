#ifndef LIBSCC_H
#define LIBSCC_H

#ifndef LIBSCCAPI
# define LIBSCCAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct SCCState;

typedef struct SCCState SCCState;

/* create a new SCC compilation context */
LIBSCCAPI SCCState *scc_new(void);

/* free a SCC compilation context */
LIBSCCAPI void scc_delete(SCCState *s);

/* set CONFIG_SCCDIR at runtime */
LIBSCCAPI void scc_set_lib_path(SCCState *s, const char *path);

/* set error/warning display callback */
LIBSCCAPI void scc_set_error_func(SCCState *s, void *error_opaque,
    void (*error_func)(void *opaque, const char *msg));

/* set options as from command line (multiple supported) */
LIBSCCAPI void scc_set_options(SCCState *s, const char *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBSCCAPI int scc_add_include_path(SCCState *s, const char *pathname);

/* add in system include path */
LIBSCCAPI int scc_add_sysinclude_path(SCCState *s, const char *pathname);

/* define preprocessor symbol 'sym'. Can put optional value */
LIBSCCAPI void scc_define_symbol(SCCState *s, const char *sym, const char *value);

/* undefine preprocess symbol 'sym' */
LIBSCCAPI void scc_undefine_symbol(SCCState *s, const char *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBSCCAPI int scc_add_file(SCCState *s, const char *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBSCCAPI int scc_compile_string(SCCState *s, const char *buf);

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBSCCAPI int scc_set_output_type(SCCState *s, int output_type);
#define SCC_OUTPUT_MEMORY   1 /* output will be run in memory (default) */
#define SCC_OUTPUT_EXE      2 /* executable file */
#define SCC_OUTPUT_DLL      3 /* dynamic library */
#define SCC_OUTPUT_OBJ      4 /* object file */
#define SCC_OUTPUT_PREPROCESS 5 /* only preprocess (used internally) */

/* equivalent to -Lpath option */
LIBSCCAPI int scc_add_library_path(SCCState *s, const char *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBSCCAPI int scc_add_library(SCCState *s, const char *libraryname);

/* add a symbol to the compiled program */
LIBSCCAPI int scc_add_symbol(SCCState *s, const char *name, const void *val);

/* output an executable, library or object file. DO NOT call
   scc_relocate() before. */
LIBSCCAPI int scc_output_file(SCCState *s, const char *filename);

/* link and run main() function and return its value. DO NOT call
   scc_relocate() before. */
LIBSCCAPI int scc_run(SCCState *s, int argc, char **argv);

/* do all relocations (needed before using scc_get_symbol()) */
LIBSCCAPI int scc_relocate(SCCState *s1, void *ptr);
/* possible values for 'ptr':
   - SCC_RELOCATE_AUTO : Allocate and manage memory internally
   - NULL              : return required memory size for the step below
   - memory address    : copy code to memory passed by the caller
   returns -1 if error. */
#define SCC_RELOCATE_AUTO (void*)1

/* return symbol value or NULL if not found */
LIBSCCAPI void *scc_get_symbol(SCCState *s, const char *name);

#ifdef __cplusplus
}
#endif

#endif
