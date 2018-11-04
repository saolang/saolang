gcc -c test_X86_64.s && ld -e _main -macosx_version_min 10.13 test_X86_64.o -o test_X86_64 -lSystem && ./test_X86_64
