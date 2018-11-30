# TODO -Wno-unused-result

#../configure --prefix=. --cc=clang --config-musl --extra-cflags="-Wall -g -O2 -I ../include"
# --extra-cflags="-Wall -g -O2 -DMAKE_DEBUG"

#../configure --prefix=. --cc=clang --config-musl

arch=$(uname -s)_$(uname -m)
echo arch=$arch
mkdir -p build_$arch/
cd build_$arch/
../configure --cc=clang --config-musl
make clean
make makedebug
make libscc.so
make 
make cross

ls -al

echo test1
./scc -vv

cd ..

echo ./build_Darwin_x86_64/scc -run -B build_Darwin_x86_64/ -I build_Darwin_x86_64/ -I include -I. -D __APPLE__ examples/eg_scc_dl.c 30
./build_Darwin_x86_64/scc -run -B build_Darwin_x86_64/ -I build_Darwin_x86_64/ -I include -I. -D __APPLE__ examples/eg_scc_dl.c 30

#echo ./build_Darwin_x86_64/scc -run -B build_Darwin_x86_64/ -I include -I. -D __APPLE__ scc.c -v
#./build_Darwin_x86_64/scc -run -B build_Darwin_x86_64/ -I include -I. -D __APPLE__ scc.c -v

echo ./build_Darwin_x86_64/scc -run -B build_Darwin_x86_64/ -I. -I build_Darwin_x86_64 scc.c -vv
./build_Darwin_x86_64/scc -run -B build_Darwin_x86_64/ -I. -I build_Darwin_x86_64 scc.c -vv

#echo ./build_Darwin_x86_64/scc -run -B build_Darwin_x86_64/ -I. examples/test_scc_error_internal.c
#./build_Darwin_x86_64/scc -run -B build_Darwin_x86_64/ -I. examples/test_scc_error_internal.c

echo ./build_Darwin_x86_64/scc -run -B build_Darwin_x86_64/ -I. examples/test_scc_h.c
./build_Darwin_x86_64/scc -run -B build_Darwin_x86_64/ -I. -I build_Darwin_x86_64 examples/test_scc_h.c

echo
echo ./build_Darwin_x86_64/scc -B build_Darwin_x86_64/ -I. -I build_Darwin_x86_64 -E -P0 scc.c \> scc.osx.i
./build_Darwin_x86_64/scc -B build_Darwin_x86_64/ -I. -I build_Darwin_x86_64 -E -P0 scc.c > scc.osx.i

# dev OSX ..
#./build_Darwin_x86_64/scc -B build_Darwin_x86_64 -D__APPLE__ -D__SCC_TARGET_FORMAT__=MACHO -I include_osx -I . -DMAKE_DEBUG -run scc.c -I. -Wunsupported -c examples/test_scc_h.c 
#./build_Darwin_x86_64/scc -B build_Darwin_x86_64 -D__APPLE__ -D__SCC_TARGET_FORMAT__=MACHO -I include_osx -I. -run scc.c -I. -Wunsupported -c examples/test_scc_h.c 
#./build_Darwin_x86_64/scc -B build_Darwin_x86_64 -DSCC_TARGET_MACHO -D__APPLE__ -D__SCC_TARGET_FORMAT__=MACHO -I include_osx -I. -run scc.c
#./build_Darwin_x86_64/scc -B build_Darwin_x86_64 -D__APPLE__ -D__SCC_TARGET_FORMAT__=MACHO -I build_Darwin_x86_64 -I include_osx -I. -run scc.c

./build_Darwin_x86_64/scc -B build_Darwin_x86_64 -I build_Darwin_x86_64 -I include_osx -I. -run scc.c
./build_Darwin_x86_64/scc -B build_Darwin_x86_64 -I build_Darwin_x86_64 -I include_osx -I. -D SCC_TARGET_X86_64 -run scc.c

cd build_Darwin_x86_64
./scc -I . -I ..  -run ../scc.c -I. -I.. -run ../test/test_SCC.c
./scc -I . -I ..  -run ../scc.c -I. -I.. -run ../scc.c -I. -I.. -run ../test/test_SCC.c
./scc -I . -I ..  -run ../scc.c -I. -I.. -run ../scc.c -I. -I.. -run ../scc.c -I. -I.. -run ../test/test_SCC.c



