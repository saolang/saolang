#

./build_Darwin_x86_64/scc -I. -I build_Darwin_x86_64 scc.c

In file included from scc.c:4:
In file included from libscc.c:22:
In file included from sccrun.c:8:
In file included from sccrun_debug_bt.c:10:
In file included from /usr/include/signal.h:61:
/usr/include/sys/cdefs.h:81: warning: #warning Unsupported compiler detected
/usr/lib/libc.dylib: error: scc_load_dll(): bad architecture /usr/lib/libc.dylib (16,0)
scc: error: library 'c' not found
scc: error: file 'crtn.o' not found
scc: error: undefined symbol 'memmove'
scc: error: undefined symbol '__floatundixf'
scc: error: undefined symbol '__fixunsxfdi'
scc: error: undefined symbol 'dlclose'
scc: error: undefined symbol 'memset'
scc: error: undefined symbol 'dlsym'
scc: error: undefined symbol 'dlopen'
scc: error: undefined symbol '__stdinp'
scc: error: undefined symbol '__stdoutp'
scc: error: undefined symbol '__stderrp'
scc: error: undefined symbol '__error'

#

dkrun build_in_dkr_gcc_musl/scc -DSCC_MUSL -I. -I build_in_dkr_gcc_musl scc.c
scc: error: undefined symbol '__floatundixf'
scc: error: undefined symbol '__fixunsxfdi'

#

dkrun build_in_dkr_gcc_musl/scc -I. -I build_in_dkr_gcc_musl scc.c

/*
gcc -o examples/scc_libdl.o -c scc_libdl.c -DSCC_TARGET_X86_64 -DSCC_TARGET_MACHO -DSCC_MUSL -DONE_SOURCE=0 -Wall -g -O2 -Wdeclaration-after-statement -fno-strict-aliasing -Wno-pointer-sign -Wno-sign-compare -Wno-unused-result -Wno-unused-function -D_FORTIFY_SOURCE=0 -I.-fPIC
gcc -shared -Wl,-install_name,scc_libdl.so -o examples/scc_libdl.so examples/scc_libdl.o -flat_namespace -fPIC
gcc -shared -export-symbols -Wl,-install_name,scc_libdl.so -o examples/scc_libdl.so examples/scc_libdl.o -flat_namespace -fPIC
#gcc -static -o scc_libdl.a examples/scc_libdl.o -flat_namespace -fPIC

gcc -I. examples/test_gcc_libdl.c examples/scc_libdl.so -o test_gcc_libdl
./test_gcc_libdl 
dyld: Library not loaded: scc_libdl.so
  Referenced from: test_gcc_libdl
  Reason: image not found
Abort trap: 6

clang -o examples/scc_libdl.o -c scc_libdl.c -DSCC_TARGET_X86_64 -DSCC_TARGET_MACHO -DSCC_MUSL -DONE_SOURCE=0 -Wall -g -O2 -Wdeclaration-after-statement -fno-strict-aliasing -fheinous-gnu-extensions -Wno-pointer-sign -Wno-sign-compare -Wno-unused-result -Wno-unused-function -Wno-string-plus-int -I.  -fPIC
clang -shared -Wl,-install_name,scc_libdl.so -o examples/scc_libdl.so examples/scc_libdl.o -flat_namespace -fPIC
#clang -static -o scc_libdl.a examples/scc_libdl.o -flat_namespace -fPIC

ar rcs examples/scc_libdl.a examples/scc_libdl.o

#
gcc -I. examples/test_gcc_libdl.c examples/scc_libdl.a
./a.out
clang -I. examples/test_gcc_libdl.c examples/scc_libdl.a

gcc -I. examples/test_gcc_libdl.c examples/scc_libdl.a
DYLD_LIBRARY_PATH=examples ./test_gcc_libdl

# WORK: OSX/scc
DYLD_INSERT_LIBRARIES=examples/scc_libdl.so ./build_Darwin_x86_64/scc -run -B build_Darwin_x86_64 -I. examples/test_gcc_libdl.c

#
scc -run  -B build_Darwin_x86_64 -I. examples/test_gcc_libdl.c examples/scc_libdl.a 
./build_Darwin_x86_64/scc -run -B build_Darwin_x86_64 -I. examples/test_gcc_libdl.c examples/scc_libdl.so
error: sccelf: undefined symbol 'scc_libdl_open'

*/

//#include <dlfcn.h>

