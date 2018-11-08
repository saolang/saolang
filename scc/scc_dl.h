#ifndef _SCC_DL_H
#define _SCC_DL_H

/* Dynmaic c libc header for SCC */

#ifdef __cplusplus
extern "C" {
#endif


#include "scc_macro.h"

#ifdef _WIN32

//@ref
//https://github.com/dlfcn-win32/dlfcn-win32

#ifndef __DLFCN_H__
# define __DLFCN_H__

//symbol = GetProcAddress( (HMODULE) handle, name );
	
//#if defined(DLFCN_WIN32_EXPORTS)
//#   define DLFCN_EXPORT __declspec(dllexport)
//#else
//#   define DLFCN_EXPORT
//#endif
//
///* POSIX says these are implementation-defined.
// * To simplify use with Windows API, we treat them the same way.
// */
//
//#define RTLD_LAZY   0
//#define RTLD_NOW    0
//
//#define RTLD_GLOBAL (1 << 1)
//#define RTLD_LOCAL  (1 << 2)
//
///* These two were added in The Open Group Base Specifications Issue 6.
// * Note: All other RTLD_* flags in any dlfcn.h are not standard compliant.
// */
//
//#define RTLD_DEFAULT    0
//#define RTLD_NEXT       0
//
//DLFCN_EXPORT void *dlopen ( const char *file, int mode );
//DLFCN_EXPORT int   dlclose(void *handle);
//DLFCN_EXPORT void *dlsym(void *handle, const char *name);
//DLFCN_EXPORT char *dlerror(void);
//
//make them external because these are provided by sys
extern void *dlopen  (const char *file, int mode);
extern int   dlclose (void *handle);
extern void *dlsym   (void * handle, const char * name);
extern char *dlerror (void);

#define RTLD_NEXT      ((void *) -1l)
#define RTLD_DEFAULT   ((void *) 0)
#define RTLD_LAZY					-1
#define RTLD_NOW					-1
#define RTLD_BINDING_MASK -1
#define RTLD_NOLOAD				-1
#define RTLD_GLOBAL				-1

#endif /* __DLFCN_H__ */
#else//not _WIN32
#ifndef __DLFCN_H__
# define __DLFCN_H__
//# include <dlfcn.h>

//will do later... damn!
////make them external because these are provided by sys
extern void *dlopen  (const char *file, int mode);
extern int   dlclose (void *handle);
extern void *dlsym   (void * handle, const char * name);
extern char *dlerror (void);

#ifdef __APPLE__
//@ref https://opensource.apple.com/source/Libwrappers/Libwrappers-9/dlcompat/dlfcn.h.auto.html
#define RTLD_LAZY	0x1
#define RTLD_NOW	0x2
#define RTLD_LOCAL	0x4
#define RTLD_GLOBAL	0x8

#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#define RTLD_NOLOAD	0x10
#define RTLD_NODELETE	0x80
#define RTLD_FIRST	0x100	/* Mac OS X 10.5 and later */

/*
 * Special handle arguments for dlsym().
 */
#define	RTLD_NEXT	((void *) -1)	/* Search subsequent objects. */
#define	RTLD_DEFAULT	((void *) -2)	/* Use default search algorithm. */
#define	RTLD_SELF	((void *) -3)	/* Search this and subsequent objects (Mac OS X 10.5 and later) */
#define	RTLD_MAIN_ONLY	((void *) -5)	/* Search main executable only (Mac OS X 10.5 and later) */
#endif /* not POSIX */

#else//!__APPLE__

#define RTLD_LAZY     0x1
#define RTLD_NOW      0x2
#define RTLD_NOLOAD   0x4
#define RTLD_GLOBAL   0x100
#define RTLD_NODELETE 0x1000
#define RTLD_LOCAL    0x0

//#define RTLD_LAZY   1
//#define RTLD_NOW    2
//#define RTLD_NOLOAD 4
//#define RTLD_NODELETE 4096
//#define RTLD_GLOBAL 256
//#define RTLD_LOCAL  0

#define RTLD_NEXT    ((void *)-1)
#define RTLD_DEFAULT ((void *)0)
#endif

#endif/* __DLFCN_H__ */
#endif

// SCC( SM, TYPE=void*, LIB=c)
// cast the symbol as a function that returns type-specified or void* as default.
#define SCC(SYM,...) (SCC_IF_ELSE(__VA_ARGS__)((__VA_ARGS__(*)())scc_dlsym(#SYM),scc_dlsym_(#SYM)))

//#ifndef _WIN32
#ifndef __STDIO_H_
typedef struct __FILE FILE;
#endif
//typedef struct __sFILE FILE;
//#endif

//#ifdef __APPLE__
//#define SCC_DL_EXT .dylib
//#else
//#define SCC_DL_EXT .so
//
////TODO WIN32 later
//
//#endif

#ifdef __APPLE__
extern FILE *__stdinp;
extern FILE *__stdoutp;
extern FILE *__stderrp;
#define stdin __stdinp
#define stdout __stdoutp
#define stderr __stderrp

#else//TODO for !__APPLE__

/* Very Standard streams.  */
extern FILE *stdin;		/* Standard input stream.  */
extern FILE *stdout;		/* Standard output stream.  */
extern FILE *stderr;		/* Standard error output stream.  */

/* C89/C99 say they're macros.  Make them happy.  */
#define stdin stdin
#define stdout stdout
#define stderr stderr

#endif//__APPLE__

static inline void* scc_dlsym(const char* sym){return dlsym(RTLD_DEFAULT,sym);}
//static inline scc_func_ptr_void scc_dlsym_(const char* sym){return (scc_func_ptr_void) dlsym(RTLD_DEFAULT,sym);}//OK
static inline typeof(void*(*)()) scc_dlsym_(const char* sym){return (void*(*)())dlsym(RTLD_DEFAULT,sym);}

static inline void* scc_dlopen(const char* lib){return dlopen(lib,RTLD_GLOBAL|RTLD_LAZY);}

#define SCC_C_stdin 1
#define SCC_C_stdout 2
#define SCC_C_stderr 3

//FILE* scc_stdfile[3]={stdin,stdout,stderr};//ERR: initializer element is not a compile-time constant

static inline FILE* scc_std(int std){
	if(SCC_C_stdin==std)return stdin;
	if(SCC_C_stdout==std)return stdout;
	if(SCC_C_stderr==std)return stderr;
	return (FILE*)0;
}

//stdio/stdout/stderr wrapping
//TODO maybe merge to SCC() later
#define SCCSTD(STD) scc_std(SCC_C_std##STD)
//#define SCCSTD(STD) scc_stdfile[SCC_C_std##STD]

#ifdef __cplusplus
}
#endif

#endif//_SCC_DL_H
