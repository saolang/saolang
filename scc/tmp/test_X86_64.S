//gcc -c test_X86_64.s && ld -e _main -macosx_version_min 10.13 test_X86_64.o -o test_X86_64 -lSystem && ./test_X86_64
	.globl	_main                   ## -- Begin function main
_main:                                  ## @main
	pushq	%rbx
	leaq	message(%rip), %rdi
	callq	_puts
	popq	%rbx
	retq
message:                                 ## @.str
	.asciz	"hola \344\275\240\346\203\263\346\216\202?\0"
