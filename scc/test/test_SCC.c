#if 0
../build_Darwin_x86_64/scc -I.. -B ../build_Darwin_x86_64 -run test_SCC.c
./build_Darwin_x86_64/scc -I. -B build_Darwin_x86_64 -run test/test_SCC.c
./scc -DSCC_MUSL -I.. -I. -run ../scc.c -I.. ../test/test_SCC.c && ./a.out
#endif

//#include "scc_libc.h"

//for testing
#include "scc.h"

int main(){
#define _OUTPUT_M(...) SCC(printf)("%s => %s\n",#__VA_ARGS__,SCC_QUOTE(__VA_ARGS__))
//#define _OUTPUT_M(...) SCC_WHEN(#__VA_ARGS__)(SCC(printf)("%s => %s\n",#__VA_ARGS__,SCC_QUOTE(__VA_ARGS__)))

	_OUTPUT_M(__SCC_TARGET_CPU__);
	_OUTPUT_M(__SCC_TARGET_OS__);
	_OUTPUT_M(__SCC_TARGET_FORMAT__);
	_OUTPUT_M(__SCC_TARGET_CPU_BIT__);

	_OUTPUT_M(__SCC_CPU__);
	_OUTPUT_M(__SCC_TARGET_OS__);
	_OUTPUT_M(__SCC_OS__);
	_OUTPUT_M(__SCC_CPU_BIT__);

	_OUTPUT_M(__SCC_OS_ID__);
	_OUTPUT_M(__SCC_TARGET_OS_ID__);

	_OUTPUT_M(__SCC_OS_FORMAT_ID__);
	_OUTPUT_M(__SCC_TARGET_FORMAT_ID__);

	_OUTPUT_M(__linux__);
	_OUTPUT_M(__LINUX__);
	_OUTPUT_M(__APPLE__);
	_OUTPUT_M(DEFAULT_ELFINTERP);
	_OUTPUT_M(DEFAULT_ELFINTERP());
	SCC(printf)("%s => %s\n","DEFAULT_ELFINTERP()",DEFAULT_ELFINTERP());

	_OUTPUT_M(SCC_MUSL);
	_OUTPUT_M(SCC_IS_NATIVE);
	_OUTPUT_M(__SCC_TARGET_CROSS__);

#undef _OUTPUT_M

#ifdef PTR_SIZE
	//SCC(printf)("PTR_SIZE=%d\n",PTR_SIZE);//only in scc.h => gen-*
#endif

	SCC(printf)("%s=%d\n", "5 % 3",5 % 3);
	return 42;
}

