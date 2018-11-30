# fail...
#../configure --prefix=. --cc=gcc --config-musl --extra-cflags='-Wall -g -O2 -I ../include_qnx' &&


#NOTES: using ONE_SOURCE is not good for compiling so

PWD=`pwd`
CCC="mkdir -p build_in_dkr_gcc_musl &&
cd build_in_dkr_gcc_musl &&
../configure --prefix=. --cc=gcc --config-musl &&
make clean &&
make libscc.so &&
make &&
make cross &&
echo test1 &&
./scc -I.. -B. -run ../examples/ex3.c 33
"
#echo $CCC | docker run -v $PWD:/work/ -w /work/ -i cmptech/docker_tinycc_dev bash
DDD="docker run -v $PWD/:/work/ -w /work/ -i cmptech/docker_tinycc_dev"
echo PWD=$PWD
echo CCC=$CCC
echo DDD=$DDD

echo $CCC | $DDD bash

echo $DDD ./build_in_dkr_gcc_musl/scc -I. -B ./build_in_dkr_gcc_musl -run ./test/fib.c 33
$DDD ./build_in_dkr_gcc_musl/scc -I. -B ./build_in_dkr_gcc_musl -run ./test/fib.c 33

echo $DDD build_in_dkr_gcc_musl/scc -I. -B build_in_dkr_gcc_musl -I build_in_dkr_gcc_musl -E -P0 scc.c \> scc.dkr.i
$DDD build_in_dkr_gcc_musl/scc -I. -B build_in_dkr_gcc_musl -I build_in_dkr_gcc_musl -E -P0 scc.c > scc.dkr.i

#echo $DDD ./build_in_dkr_gcc_musl/i386-win32-scc -I. -B build_in_dkr_gcc_musl -o ex3.exe examples/ex3.c
#$DDD ./build_in_dkr_gcc_musl/i386-win32-scc -I. -B build_in_dkr_gcc_musl -o ex3.exe examples/ex3.c


#make libscc.so
#gcc -shared -Wl,-soname,libscc.so -o libscc.so libscc.o sccpp.o sccgen.o sccelf.o sccasm.o sccrun.o x86_64-gen.o x86_64-link.o i386-asm.o -fPIC
#/usr/lib/gcc/x86_64-alpine-linux-musl/6.4.0/../../../../x86_64-alpine-linux-musl/bin/ld: libscc.o: relocation R_X86_64_PC32 against symbol `define_stack' can not be used when making a shared object; recompile with -fPIC
#/usr/lib/gcc/x86_64-alpine-linux-musl/6.4.0/../../../../x86_64-alpine-linux-musl/bin/ld: final link failed: Bad value
