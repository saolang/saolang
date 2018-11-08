/* probes for platforms */

#ifndef _SCC_PLATFORM_H
#define _SCC_PLATFORM_H

//TODO if target unclear should throw error to stop
//SCC_TARGET_I386
//  => __SCC_TARGET_CPU__=X86, __SCC_TARGET_CPU_BIT__=32
//SCC_TARGET_X86_64
//  => __SCC_TARGET_CPU__=X86, __SCC_TARGET_CPU_BIT__=64
//SCC_TARGET_ARM
//  => __SCC_TARGET_CPU__=ARM, __SCC_TARGET_CPU_BIT__=32
//SCC_TARGET_ARM64
//  => __SCC_TARGET_CPU__=ARM, __SCC_TARGET_CPU_BIT__=64

#if !defined(SCC_TARGET_I386) && !defined(SCC_TARGET_ARM) && \
    !defined(SCC_TARGET_ARM64) && !defined(SCC_TARGET_X86_64)
# if defined __x86_64__ || defined _AMD64_
#  define SCC_TARGET_X86_64
# elif defined __arm__
#  define SCC_TARGET_ARM
#  define SCC_ARM_EABI
#  define SCC_ARM_HARDFLOAT
# elif defined __aarch64__
#  define SCC_TARGET_ARM64
# else
#  define SCC_TARGET_I386
# endif
#endif

# if defined(_WIN32)
#  undef  SCC_TARGET_PE
#  define SCC_TARGET_PE 1
# endif

///////////////////////////////////////////////////////////////////////////
// __SCC_CPU__ : current cpu type
#if defined(__X86__)||defined(_X86_)||defined(__i386__)||defined(__x86_64__)||defined(_AMD64_)
# if (defined __x86_64__ || defined _AMD64_)
#  define __SCC_CPU_BIT__ 64
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
# endif
#	define __SCC_CPU__  ARM
#else
//TODO getenv ?
# define __SCC_CPU__
#endif

// __SCC_CPU_BIT__ : current cpu bits
#ifndef __SCC_CPU_BIT__
# ifdef __SCC_CPU_BIT_DEFAULT__
#  define __SCC_CPU_BIT__ __SCC_CPU_BIT__
# else
#  define __SCC_CPU_BIT__ 32
# endif
#endif

///////////////////////////////////////////////////////////////////////////
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
#elif defined(__TccOS__)
#	define __SCC_OS__  SCCOS
# define __SCC_OS_FORMAT__  ELF
#else
//# define __SCC_OS__
#endif

#endif //}__SCC_OS__

//TODO iOS@Darwin/Android@Linux..

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
#ifndef __SCC_TARGET_CPU__//{

#if defined(SCC_TARGET_I386)
# define __SCC_TARGET_CPU__ X86
#elif defined(SCC_TARGET_X86_64)
# define __SCC_TARGET_CPU__ X86
#elif defined(SCC_TARGET_ARM)
# define __SCC_TARGET_CPU__ ARM
#elif defined(SCC_TARGET_ARM64)
# define __SCC_TARGET_CPU__ ARM
#elif defined(SCC_TARGET_PPC)
# define __SCC_TARGET_CPU__ PPC
#elif defined(SCC_TARGET_MIPS)
# define __SCC_TARGET_CPU__ MIPS
#elif defined(SCC_TARGET_SH)
# define __SCC_TARGET_CPU__ SH
#else
//# define __SCC_TARGET_CPU__
#endif

#endif//}__SCC_TARGET_CPU__

#ifndef __SCC_TARGET_CPU__
# ifdef __SCC_CPU__
# define __SCC_TARGET_CPU__ __SCC_CPU__
# endif
#endif

#ifndef __SCC_TARGET_CPU__
# error __SCC_TARGET_CPU__ unknown
#endif
///////////////////////////////////////////////////////////////////////////
#ifndef __SCC_TARGET_CPU_BIT__//{

#if defined(SCC_TARGET_I386)
# define __SCC_TARGET_CPU_BIT__ 32
#elif defined(SCC_TARGET_X86_64)
# define __SCC_TARGET_CPU_BIT__ 64
#elif defined(SCC_TARGET_ARM)
# define __SCC_TARGET_CPU_BIT__ 32
#elif defined(SCC_TARGET_ARM64)
# define __SCC_TARGET_CPU_BIT__ 64
#elif defined(SCC_TARGET_PPC)
#elif defined(SCC_TARGET_MIPS)
#elif defined(SCC_TARGET_SH)
#endif

#endif//}__SCC_TARGET_CPU_BIT__

#ifndef __SCC_TARGET_CPU_BIT__
# define __SCC_TARGET_CPU_BIT__ __SCC_CPU_BIT__
#endif

///////////////////////////////////////////////////////////////////////////
#ifndef __SCC_TARGET_FORMAT__//{
# if defined(SCC_TARGET_MACHO)
#  define __SCC_TARGET_FORMAT__  MACHO
#  define __SCC_TARGET_OS__  OSX
# elif defined(SCC_TARGET_PE)
#  define __SCC_TARGET_FORMAT__  PE
#  define __SCC_TARGET_OS__  WIN
# elif defined(SCC_TARGET_ELF)
#  define __SCC_TARGET_FORMAT__  ELF
# endif
#endif//}!__SCC_TARGET_FORMAT__

#ifndef __SCC_TARGET_FORMAT__//{
# warning "unknown __SCC_TARGET_FORMAT__"
#endif//}!__SCC_TARGET_FORMAT__

///////////////////////////////////////////////////////////////////////////
//TODO not good, need to adjust Makefile better?
#ifndef __SCC_TARGET_OS__
# ifdef __SCC_OS__
# define __SCC_TARGET_OS__ __SCC_OS__
# else
//# define __SCC_TARGET_OS__ LNX
# warning "unknown __SCC_TARGET_OS__"
# endif
#else
#endif

///////////////////////////////////////////////////////////////////////////

//probe SCC_IS_NATIVE for -run
#if defined _WIN32 == defined SCC_TARGET_PE
# if (defined __i386__ || defined _X86_) && defined SCC_TARGET_I386
#  define SCC_IS_NATIVE
# elif (defined __x86_64__ || defined _AMD64_) && defined SCC_TARGET_X86_64
#  define SCC_IS_NATIVE
# elif defined __arm__ && defined SCC_TARGET_ARM
#  define SCC_IS_NATIVE
# elif defined __aarch64__ && defined SCC_TARGET_ARM64
#  define SCC_IS_NATIVE
# endif
#endif

#ifdef SCC_IS_NATIVE
# define __SCC_TARGET_CROSS__ 1
#else
# define __SCC_TARGET_CROSS__ 0
#endif

#endif//_SCC_PLATFORM_H
