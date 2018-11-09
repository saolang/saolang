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

#

dkrun bash
./build_in_dkr_gcc_musl/scc -I . -I build_in_dkr_gcc_musl -B build_in_dkr_gcc_musl -DSCC_MUSL -run scc.c -I. -I build_in_dkr_gcc_musl -B build_in_dkr_gcc_musl test/test_SCC.c -o test/a.out

#

dkrun bash
./scc -I . -I .. -DSCC_MUSL -run ../scc.c -I. -I.. ../test/test_SCC.c -o ../test/a.out

In file included from ../scc.c:4:
In file included from ../libscc.c:25:
../lib/libscc1.c:495: error: incompatible types for redefinition of '__floatundixf'

# TEST inner SCC1.. TMP OK... 

dkrun bash
cd build_in_dkr_gcc_musl
make
./scc -I . -I ..  ../test/test_SCC.c -o ../test/a.out && ../test/a.out

__SCC_TARGET_CPU__ => X86.  ../test/test_SCC.c -o ../test/a.out && ../test/a.out 
__SCC_TARGET_OS__ => LNX
__SCC_TARGET_FORMAT__ => ELF
__SCC_TARGET_CPU_BIT__ => 64
__SCC_CPU__ => X86
__SCC_TARGET_OS__ => LNX
__SCC_OS__ => LNX
__SCC_CPU_BIT__ => 64
__SCC_OS_ID__ => 2
__SCC_TARGET_OS_ID__ => 2
__SCC_OS_FORMAT_ID__ => 3
__SCC_TARGET_FORMAT_ID__ => 3
__linux__ => 1
__LINUX__ => __LINUX__
__APPLE__ => __APPLE__
DEFAULT_ELFINTERP => DEFAULT_ELFINTERP
DEFAULT_ELFINTERP() => "/lib64/ld-linux-x86-64.so.2"
DEFAULT_ELFINTERP() => /lib64/ld-linux-x86-64.so.2
SCC_MUSL => SCC_MUSL
SCC_IS_NATIVE => SCC_IS_NATIVE
__SCC_TARGET_CROSS__ => 0
5 % 3=2

# BUT

./scc -I . -I ..  -run ../scc.c
In file included from ../scc.c:4:
In file included from ../libscc.c:25:
../lib/libscc1.c:495: error: patch_type(): incompatible types for redefinition of '__floatundixf'

try 1:

./scc -DSCC_MUSL -I . -I ..  -run ../scc.c

## to fix later
In file included from ../scc.c:4:
../libscc.c:29: warning: #warning 999
In file included from ../scc.c:4:
In file included from ../libscc.c:30:
../lib/libscc1.c:495: warning: patch_type(): incompatible types for redefinition of '__floatundixf' (6/6)
In file included from ../scc.c:4:
In file included from ../libscc.c:30:
../lib/libscc1.c:583: warning: patch_type(): incompatible types for redefinition of '__fixunsxfdi' (6/6)
Sao CC 0927-003 - 

try 2: //ok in dkr, with warning to fix later...

./scc -DSCC_MUSL -I . -I ..  -run ../scc.c -I. -I.. ../test/test_SCC.c -o ../test/a.out && ../test/a.out

try 3://still not pass at OSX, but it look like more chance to !!
In file included from ../scc.c:4:
In file included from ../libscc.c:22:
In file included from ../sccrun.c:8:
In file included from ../sccrun_debug_bt.c:10:
In file included from /usr/include/signal.h:61:
/usr/include/sys/cdefs.h:81: warning: #warning Unsupported compiler detected
In file included from ../scc.c:4:
In file included from ../libscc.c:32:
../lib/libscc1.c:495: warning: TODO patch_type(): incompatible types for redefinition of '__floatundixf' (6/6)
In file included from ../scc.c:4:
In file included from ../libscc.c:32:
../lib/libscc1.c:583: warning: TODO patch_type(): incompatible types for redefinition of '__fixunsxfdi' (6/6)
/usr/lib/libc.dylib: error: scc_load_dll(): bad architecture /usr/lib/libc.dylib (16,0)
scc: error: library 'c' not found
scc: error: file 'crtn.o' not found
scc: error: undefined symbol 'dlsym'

try 4:// at lease looking scc run is working now
./scc -DSCC_MUSL -I . -I ..  -run ../scc.c -I. -I.. -run ../test/test_SCC.c
./scc -I . -I ..  -run ../scc.c -I. -I.. -run ../test/test_SCC.c

#


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

