#python ../tools/build.py --snapshot-exec=ON --snapshot-save=ON --jerry-cmdline-snapshot=ON
#python ../tools/build.py --snapshot-exec=ON --snapshot-save=ON --jerry-cmdline-snapshot=ON --saolang=ON --saolang=ON
python ../tools/build.py --profile=es2015-subset --all-in-one=ON --snapshot-exec=ON --snapshot-save=ON --jerry-cmdline-snapshot=ON --saolang=ON --saolang-only=ON --error-messages=ON $*

ls -al ../build/bin/

#../build/bin/jerry sao.js
../build/bin/jerry sao.sao

