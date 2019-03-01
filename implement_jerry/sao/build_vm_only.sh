#python ../tools/build.py --profile=es2015-subset --all-in-one=ON --snapshot-exec=ON --snapshot-save=ON --jerry-cmdline-snapshot=ON --saolang=ON --error-messages=ON $*

#python tools/build.py --toolchain=cmake/toolchain_mcu_stm32f1.cmake --jerry-cmdline OFF --jerry-libc OFF --jerry-libm OFF --js-parser ON --mem-heap=20 --jerry-port-default OFF --clean

#python ../tools/build.py --jerry-cmdline OFF --jerry-libm OFF --js-parser OFF --jerry-port-default OFF --clean
#python ../tools/build.py --profile=minimal --jerry-cmdline ON --jerry-cmdline-snapshot=ON --jerry-libm OFF --js-parser OFF --clean

#python ../tools/build.py --profile=es2015-subset --error-messages=ON 

python ../tools/build.py --profile=minimal --error-messages=ON  --jerry-libm OFF --js-parser OFF --clean

ls -al ../build/lib/
ls -al ../build/bin/

