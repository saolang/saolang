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

