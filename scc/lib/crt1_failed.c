// =============================================
// crt1.c

/*  mingw.h */
//#ifdef _WIN64
//#define __stdcall
//#define _AMD64_ 1
//#define __x86_64 1
//#define _M_X64 100 /* Visual Studio */
//#define _M_AMD64 100 /* Visual Studio */
//#define USE_MINGW_SETJMP_TWO_ARGS
//#define mingw_getsp tinyc_getbp
//#define __TRY__
//#else
//#define __stdcall __attribute__((__stdcall__))
//#define _X86_ 1
//#define _M_IX86 300 /* Visual Studio */
//#define WIN32 1
//#define _USE_32BIT_TIME_T
//#ifdef __arm__
//#define __TRY__
//#else
//#define __TRY__ void __try__(void**), *_sehrec[6]; __try__(_sehrec);
//#endif
//#endif

//TODO _UNICODE
// _UNICODE for tchar.h, UNICODE for API
#include <tchar.h>

//#define __cdecl

//#include <stdio.h>
#include <stdlib.h>

///* stdlib.h */
//#ifndef __argc
//#ifdef _MSVCRT_
//  extern int __argc;
//#else
//#define __argc (*_imp____argc)
//  extern int *_imp____argc;
//#endif
//#endif
//#ifndef __argv
//#ifdef _MSVCRT_
//  extern char **__argv;
//#else
//#define __argv  (*_imp____argv)
//  extern char ***_imp____argv;
//#endif
//#endif
//
//#ifdef _UNICODE
////#define __targv __wargv
//#define __targv wchar_t**
//#else//_UNICODE
////#define __targv __argv
//#define __targv char**
//#endif
//
////#ifndef __wargv
////#ifdef _MSVCRT_
////  extern wchar_t **__wargv;
////#else
////#define __wargv (*_imp____wargv)
////  extern wchar_t ***_imp____wargv;
////#endif
////#endif
//	
#include "scc_dl.h"
//#include "scc.h"//TODO to replace the dependency of tchar.h/stdlib.h

#define _UNKNOWN_APP    0
#define _CONSOLE_APP    1
#define _GUI_APP        2

#define _MCW_PC         0x00030000 // Precision Control
#define _PC_24          0x00020000 // 24 bits
#define _PC_53          0x00010000 // 53 bits
#define _PC_64          0x00000000 // 64 bits

#ifdef _UNICODE
#define __tgetmainargs __wgetmainargs
#define _tstart _wstart
#define _tmain wmain
#define _runtmain _runwmain
#else
#define __tgetmainargs __getmainargs
#define _tstart _start
#define _tmain main
#define _runtmain _runmain
#endif

typedef struct { int newmode; } _startupinfo;

//int __cdecl __tgetmainargs(int *pargc, _TCHAR ***pargv, _TCHAR ***penv, int globb, _startupinfo*);
//void __cdecl __set_app_type(int apptype);
//unsigned int __cdecl _controlfp(unsigned int new_value, unsigned int mask);
//extern int _tmain(int argc, _TCHAR * argv[], _TCHAR * env[]);

/* Allow command-line globbing with "int _dowildcard = 1;" in the user source */
int _dowildcard;

void _tstart(void)
{
    __TRY__
    _startupinfo start_info = {0};

    // Sets the current application type
    SCC(__set_app_type)(_CONSOLE_APP);

    // Set default FP precision to 53 bits (8-byte double)
    // _MCW_PC (Precision control) is not supported on ARM
#if defined __i386__ || defined __x86_64__
    SCC(_controlfp)(_PC_53, _MCW_PC);
#endif

    SCC(__tgetmainargs)( &__argc, &__targv, &_tenviron, _dowildcard, &start_info);
    SCC(exit)(SCC(_tmain,int)(__argc, __targv, _tenviron));
}

int _runtmain(int argc, /* as scc passed in */ char **argv)
{
#ifdef UNICODE
    _startupinfo start_info = {0};

    SCC(__tgetmainargs)(&__argc, &__targv, &_tenviron, _dowildcard, &start_info);
    /* may be wrong when scc has received wildcards (*.c) */
    if (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#else
    __argc = argc;
    __targv = argv;
#endif
#if defined __i386__ || defined __x86_64__
    SCC(_controlfp)(_PC_53, _MCW_PC);
#endif
    return SCC(_tmain,int)(__argc, __targv, _tenviron);
}

// =============================================
