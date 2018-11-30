#include "scc_dl.h"

static inline void * scc_libdl_open(const char* lib)
{
	return dlopen(lib, RTLD_GLOBAL | RTLD_LAZY);
}

