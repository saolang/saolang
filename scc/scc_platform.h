#ifndef _SCC_PLATFORM_H
#define _SCC_PLATFORM_H

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

// __SCC_OS__ : current os

///////////////////////////////////////////////////////////////////////////
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

//TODO iOS@Darwin/Android@Linux?

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
# define __SCC_TARGET_CPU__ __SCC_CPU__
#endif
///////////////////////////////////////////////////////////////////////////
#ifndef __SCC_TARGET_CPU_BIT__//{

#if defined(SCC_TARGET_I386)
# define __SCC_TARGET_CPU_BIT__ 32
#elif defined(SCC_TARGET_X86_64)
# define __SCC_TARGET_CPU_BIT__ 64
#elif defined(SCC_TARGET_X86_ARM)
#elif defined(SCC_TARGET_PPC)
#elif defined(SCC_TARGET_MIPS)
#elif defined(SCC_TARGET_SH)
#endif

#endif//}__SCC_TARGET_CPU_BIT__

#ifndef __SCC_TARGET_CPU_BIT__
# define __SCC_TARGET_CPU_BIT__ __SCC_CPU_BIT__
#endif

///////////////////////////////////////////////////////////////////////////
#ifdef __SCC_TARGET_FORMAT__
//SKIP THEN
#elif defined(SCC_TARGET_MACHO)
# define __SCC_TARGET_FORMAT__  MACHO
# define __SCC_TARGET_OS__  OSX
#elif defined(SCC_TARGET_PE)
# define __SCC_TARGET_FORMAT__  PE
# define __SCC_TARGET_OS__  WIN
#else
//#ifdef __SCC_OS_FORMAT__
//# define __SCC_TARGET_FORMAT__ __SCC_OS_FORMAT__
//#else
//# define __SCC_TARGET_FORMAT__  ELF
//#endif
# define __SCC_TARGET_FORMAT__  ELF
#endif

///////////////////////////////////////////////////////////////////////////
//TODO not good, need to adjust Makefile better?
#ifndef __SCC_TARGET_OS__
//# define __SCC_TARGET_OS__ __SCC_OS__
# define __SCC_TARGET_OS__ LNX
#endif

///////////////////////////////////////////////////////////////////////////
//TODO
//#define SCC_CPU_X86  1
//#define SCC_CPU_ARM  2
//#define SCC_CPU_MIPS 3
//#define SCC_CPU_PPC  4
//#define SCC_CPU_SH   5
//#if (EXPAND(SCC_CPU_##__SCC_TARGET_CPU__)==EXPAND(SCC_CPU_##__SCC_CPU__))
//# define __SCC_TARGET_CROSS__ 0
//#else
//# define __SCC_TARGET_CROSS__ 1
//#endif
# define __SCC_TARGET_CROSS__  TODO

//TODO redefine for cross build... for scc_define_symbol later

#endif//_SCC_PLATFORM_H
