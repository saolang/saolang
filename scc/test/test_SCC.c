#if 0
../build_Darwin_x86_64/scc -I.. -B ../build_Darwin_x86_64 -run test_SCC.c
./build_Darwin_x86_64/scc -I. -B build_Darwin_x86_64 -run test/test_SCC.c
#endif

#include "scc_libc.h"
//#include "scc.h"

int main(){
	SCC(printf)("%s = %s\n", "__SCC_TARGET_CPU__", SCC_QUOTE(__SCC_TARGET_CPU__));
	SCC(printf)("%s = %s\n", "__SCC_TARGET_OS__", SCC_QUOTE(__SCC_TARGET_OS__));
	SCC(printf)("%s = %s\n", "__SCC_TARGET_FORMAT__", SCC_QUOTE(__SCC_TARGET_FORMAT__));
	SCC(printf)("%s = %s\n", "__SCC_TARGET_CPU_BIT__", SCC_QUOTE(__SCC_TARGET_CPU_BIT__));

	SCC(printf)("%s = %s\n", "__SCC_CPU__", SCC_QUOTE(__SCC_CPU__));
	SCC(printf)("%s = %s\n", "__SCC_OS__", SCC_QUOTE(__SCC_OS__));
	SCC(printf)("%s = %s\n", "__SCC_OS_FORMAT__", SCC_QUOTE(__SCC_OS_FORMAT__));
	SCC(printf)("%s = %s\n", "__SCC_CPU_BIT__", SCC_QUOTE(__SCC_CPU_BIT__));

	SCC(printf)("%s,%s,%s,%s\n", "__SCC_OS_ID__,__SCC_TARGET_OS_ID__", SCC_QUOTE(__SCC_OS_ID__),SCC_QUOTE(__SCC_TARGET_OS_ID__));
	SCC(printf)("%s,%s,%s,%s\n", "__SCC_CPU_ID__,__SCC_TARGET_CPU_ID__", SCC_QUOTE(__SCC_CPU_ID__),SCC_QUOTE(__SCC_TARGET_CPU_ID__));
	SCC(printf)("%s,%s,%s,%s\n", "__SCC_OS_FORMAT_ID__,__SCC_TARGET_FORMAT_ID__", SCC_QUOTE(__SCC_OS_FORMAT_ID__),SCC_QUOTE(__SCC_TARGET_FORMAT_ID__));

	SCC(printf)("%s = %s\n", "__SCC_TARGET_CROSS__", SCC_QUOTE(__SCC_TARGET_CROSS__));

	SCC(printf)("%s = %s\n", "__APPLE__", SCC_QUOTE(__APPLE__));
#ifdef SCC_IS_NATIVE
	SCC(printf)("%s = %s\n", "SCC_IS_NATIVE", SCC_QUOTE(SCC_IS_NATIVE));
#endif
	/*
#define _OUTPUT_M(m) SCC(printf)("%s=%s\n", SCC_EXPAND(#m), SCC_EXPAND(#m));
	SCC_ITR1( _OUTPUT_M,
			__APPLE__,
			__X86__,
			_X86_,
			__i386__,
			__x86_64__,
			_AMD64_
			);
			*/
	
	// IS IT CROSS BUILD TODO USE strcmp in program later??
	//SCC(printf)("%s = %s\n", "__SCC_TARGET_CROSS__", SCC_QUOTE(__SCC_TARGET_CROSS__));

	//SCC(printf)("%s = %s\n", "TEST", SCC_QUOTE(xxx-__SCC_TARGET_CPU_BIT__-__SCC_TARGET_CPU__-__SCC_TARGET_OS__-__SCC_TARGET_FORMAT__));


#ifdef PTR_SIZE
	//SCC(printf)("PTR_SIZE=%d\n",PTR_SIZE);//only in scc.h => gen-*
#endif

	SCC(printf)("%s=%d\n", "5 % 3",5 % 3);
	return 42;
}

