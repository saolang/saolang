python implement_jerry/tools/build.py --profile=es2015-subset --snapshot-exec=ON --snapshot-save=ON --jerry-cmdline-snapshot=ON --saolang=ON --saolang-only=ON --error-messages=ON $*

ls -aln implement_jerry/build/bin/

implement_jerry/build/bin/jerry test/test_ext.sao

