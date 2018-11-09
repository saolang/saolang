/* probes for platforms */

#ifndef _SCC_PLATFORM_H
#define _SCC_PLATFORM_H

#include "scc_macro.h"

///////////////////////////////////////////////////////////////////////////
#define __SCC_CPU_X86__  1
#define __SCC_CPU_PPC__  2
#define __SCC_CPU_MIPS__ 3
#define __SCC_CPU_SH__   4
#define __SCC_CPU_ARM__  5

//probe CPU CPU_ID CPU_BIT

#if !defined(__SCC_CPU__)||!defined(__SCC_CPU_BIT__)//{

#if defined(__X86__)||defined(_X86_)||defined(__i386__)||defined(__x86_64__)||defined(_AMD64_)
# if (defined __x86_64__ || defined _AMD64_)
#  define __SCC_CPU_BIT__ 64
# else
#  define __SCC_CPU_BIT__ 32
# endif
#	define __SCC_CPU__  X86
#elif defined(__PPC__)
#	define __SCC_CPU__  PPC
#elif defined(__MIPS__)
#	define __SCC_CPU__  MIPS
#elif defined(__SH__)
#	define __SCC_CPU__  SH
#elif defined(__arm__) || defined(__aarch64__)
# if defined(__aarch64__)
#  define __SCC_CPU_BIT__ 64
# else
#  define __SCC_CPU_BIT__ 32
# endif
#	define __SCC_CPU__  ARM
#else
# error "unknown cpu type"
#endif

// __SCC_CPU_BIT__ : current cpu bits
#ifndef __SCC_CPU_BIT__
# ifdef __SCC_CPU_BIT_DEFAULT__
#  define __SCC_CPU_BIT__ __SCC_CPU_BIT_DEFAULT__
# else
#  warning "unknown CPU BIT" //TODO
# endif
#endif

#endif //}

# define __SCC_CPU_ID__  SCC_MCAT(__SCC_CPU_,__SCC_CPU__,__)

///////////////////////////////////////////////////////////////////////////

#define __SCC_OS_WIN__     1
#define __SCC_OS_LNX__     2
#define __SCC_OS_OSX__     3
#define __SCC_OS_FREEBSD__ 4
#define __SCC_OS_NETBSD__  5
#define __SCC_OS_QNXNTO__  6
#define __SCC_OS_QNX__     7
#define __SCC_OS_SAO__     8

#define __SCC_OS_FORMAT_PE__     1
#define __SCC_OS_FORMAT_MACHO__  2
#define __SCC_OS_FORMAT_ELF__    3

/* probe runtime */
#ifndef __SCC_OS__//{

#if defined(_WIN32)||defined(_WIN64)
#	define __SCC_OS__  WIN
# define __SCC_OS_FORMAT__  PE
#elif defined(__APPLE__)
#	define __SCC_OS__  OSX
# define __SCC_OS_FORMAT__  MACHO
#elif defined(__linux__)||defined(__LINUX__)
#	define __SCC_OS__  LNX
# define __SCC_OS_FORMAT__  ELF
#elif defined(__FreeBSD__)
#	define __SCC_OS__  FREEBSD
# define __SCC_OS_FORMAT__  ELF
#elif defined(__NetBSD__)
#	define __SCC_OS__  NETBSD
# define __SCC_OS_FORMAT__  ELF
#elif defined(__QNXNTO__)
#	define __SCC_OS__  QNXNTO
# define __SCC_OS_FORMAT__  ELF
#elif defined(__QNX__)
#	define __SCC_OS__  QNX
# define __SCC_OS_FORMAT__  ELF
#elif defined(__SaoOS__)//SaoOS
#	define __SCC_OS__  SAO
# define __SCC_OS_FORMAT__  ELF
#else
//#  warning "TODO unknown current os"
#  error "TODO unknown current os"
#endif

#endif //}__SCC_OS__

# define __SCC_OS_FORMAT_ID__  SCC_MCAT(__SCC_OS_FORMAT_,__SCC_OS_FORMAT__,__)
# define __SCC_OS_ID__  SCC_MCAT(__SCC_OS_,__SCC_OS__,__)

///////////////////////////////////////////////////////////////////////////
#ifndef __SCC_CC__//{

#if defined(__MWERKS__)
# define __SCC_CC__  MWERKS
#elif defined(__WATCOMC__)
# define __SCC_CC__  WATCOMC
#elif defined(__GNUC__)
# define __SCC_CC__  GNUC
#elif defined(__HIGHC__)
# define __SCC_CC__  HIGHC
#elif defined(__INTEL_COMPILER)
# define __SCC_CC__  INTEL
#elif defined(__SAOCC__)
# define __SCC_CC__  SAOCCC
#else
# define __SCC_CC__
#endif

#endif //}__SCC_CC__

///////////////////////////////////////////////////////////////////////////
#ifndef __SCC_TARGET_CPU__
# ifdef __SCC_CPU__
# define __SCC_TARGET_CPU__ __SCC_CPU__
# endif
#endif

#ifndef __SCC_TARGET_CPU__
# error __SCC_TARGET_CPU__ unknown
#else
#endif

# define __SCC_TARGET_CPU_ID__  SCC_MCAT(__SCC_CPU_,__SCC_TARGET_CPU__,__)

#ifndef __SCC_TARGET_CPU_BIT__
# ifdef __SCC_CPU_BIT__
#  define __SCC_TARGET_CPU_BIT__ __SCC_CPU_BIT__
# else
#  error "unprobe __SCC_TARGET_CPU_BIT__"
# endif
#endif

///////////////////////////////////////////////////////////////////////////

#ifndef __SCC_TARGET_FORMAT__//{
# ifdef __SCC_OS_FORMAT__
#  define __SCC_TARGET_FORMAT__ __SCC_OS_FORMAT__
# else
#  error "unknown __SCC_TARGET_FORMAT__"
# endif
#endif //}

# define __SCC_TARGET_FORMAT_ID__  SCC_MCAT(__SCC_OS_FORMAT_,__SCC_TARGET_FORMAT__,__)

///////////////////////////////////////////////////////////////////////////
//TODO not good, need to adjust Makefile better?
#ifndef __SCC_TARGET_OS__
# ifdef __SCC_OS__
# define __SCC_TARGET_OS__ __SCC_OS__
# define __SCC_TARGET_OS_ID__ __SCC_OS_ID__
# else
# warning "unknown __SCC_TARGET_OS__"
# endif
#else
#endif

///////////////////////////////////////////////////////////////////////////

//#warning "CPU/BIT/OS/FMT/PTR_SIZE:" SCC_QUOTE(__SCC_TARGET_CPU__,__SCC_TARGET_CPU_BIT__,__SCC_TARGET_OS__,__SCC_TARGET_FORMAT__,PTR_SIZE)
//#pragma message "WJC.DEBUG=" SCC_QUOTE(__SCC_TARGET_CROSS__,__SCC_TARGET_CPU__,__SCC_TARGET_CPU_ID__,__SCC_TARGET_CPU_BIT__)
//#warning "__SCC_TARGET_FORMAT__=" SCC_QUOTE(__SCC_TARGET_FORMAT__)

//regards native if cpu arch and bits remain same:
#if (__SCC_CPU_ID__ == __SCC_TARGET_CPU_ID__) \
										 && (__SCC_CPU_BIT__==__SCC_TARGET_CPU_BIT__) \
										 && (__SCC_OS_FORMAT_ID__==__SCC_TARGET_FORMAT_ID__) \
										 && (__SCC_OS_ID__==__SCC_TARGET_OS_ID__)
#  define SCC_IS_NATIVE
#endif

#ifdef SCC_IS_NATIVE
# define __SCC_TARGET_CROSS__ 0
#else
# define __SCC_TARGET_CROSS__ 1
#endif

#endif//_SCC_PLATFORM_H
