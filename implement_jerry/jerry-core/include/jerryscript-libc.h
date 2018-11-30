//libc deps improves.
#if 0
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

typedef struct TCCSyms {
    char *str;
    void *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
static TCCSyms tcc_syms[] = {
#if !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(printf)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#undef TCCSYM
#endif
    { NULL, NULL },
};

ST_FUNC void *dlsym(void *handle, const char *symbol)
{
    TCCSyms *p;
    p = tcc_syms;
    while (p->str != NULL) {
        if (!strcmp(p->str, symbol))
            return p->ptr;
        p++;
    }
    return NULL;
}

#ifdef HAVE_TM_GMTOFF
#include <time.h>
#endif /* HAVE_TM_GMTOFF */
#ifdef __GNUC__
#include <sys/time.h>
#endif /* __GNUC__ */

#ifdef HAVE_TIME_H
#include <time.h>
#elif defined (HAVE_UNISTD_H)
#include <unistd.h>
#endif /* HAVE_TIME_H */

#endif

//TODO if using libc static, do below, otherwise do dlsym + macro later.
#ifndef _JERRY_LIBC_H
#define _JERRY_LIBC_H

#if defined JERRY_USING_LIBDL && JERRY_USING_LIBDL

#define LIBC(sym) jerry_syms[JERY_SYM_##sym];

#else

#define LIBC(sym) sym

//#include <stddef.h>
//#include <stdio.h>
//void *memcpy(void *dest, const void *src, size_t n);
//size_t strlen(const char *s);

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

//#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <inttypes.h>
#include <setjmp.h>

#include <float.h>
//#include <stdbool.h>
//#include <stddef.h>
//#include <stdint.h>


#include <ctype.h>
//#include <setjmp.h>
#include <stdarg.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

#include <math.h>

#ifdef JERRY_DEBUGGER

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

#endif

#include <assert.h>

#ifdef HAVE_TIME_H
#include <time.h>
#elif defined (HAVE_UNISTD_H)
#include <unistd.h>
#endif /* HAVE_TIME_H */

//default-date.c
#ifdef HAVE_TM_GMTOFF
#include <time.h>
#endif /* HAVE_TM_GMTOFF */
#ifdef __GNUC__
#include <sys/time.h>
#endif /* __GNUC__ */

#if 0
//syn benchmarking.c
#ifndef DEFINED_benchmarking
#define DEFINED_benchmarking
#ifdef __GNUC__
/*
 * Note:
 *      This is nasty and dangerous. However, we only need the timeval structure
 *      from sys/time.h. Unfortunately, the same header also declares
 *      gettimeofday, which has different declarations on different platforms
 *      (e.g., macOS, Linux). So, instead of #ifdef'ing for platforms, we simply
 *      tweak the header to declare another function. Don't try this at home.
 */
#define gettimeofday __prevent_conflicting_gettimeofday_declarations__
#include <sys/time.h>
#undef gettimeofday

int gettimeofday (struct timeval *, void *);

/**
 * Useless but stable gettimeofday implementation. Returns Epoch. Ensures that
 * test cases relying on "now" yield stable results.
 */
int gettimeofday (struct timeval *tv,
                  void *tz)
{
  (void) tz;
  tv->tv_sec = 0;
  tv->tv_usec = 0;
  return 0;
} /* gettimeofday */
#endif /* __GNUC__ */
#endif//DEFINED_benchmarking
#endif

#endif//JERRY_USING_LIBDL
#endif//_JERRY_LIBC_H
