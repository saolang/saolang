# Want

LIR => binary => sljit self...bootstrap

scc => c

saolang => sljit + vm(like jerryscript)
  => design spec first?
	and then, build scc => pure c version of scc(sljit)
	then LIR => vm(like jerryscript)

const/let,var => optimized the oper field of var

low
high leval

how about
using special syntax to oper in low level code?

low: JIT / VM / BYTECODE / ASM etc

/*
*/
@<ASM-X86>{

	INSTRUCTIVE

}

# Plan

```
# syntax
test_base.sao
test_ext.sao
test_c.sao

* void/null/undefined/typeof/typedef/sizeof etc..

//how is this ok? break the kw rules?
* @void,@null,@undefined,@typedef,@sizeof,@this ...

# low level
jit
asm
c/macro
=>
vm
binary

# high (script)
vm=>
js php python
sao-runtime

sao - the SAO console command
	sljit - using stack-less-JIT for the lowlevel
libsao so/dll - shared lib
libsao.a - static lib
libsaoext so/dll - using external cc to get better performance, elf/macho/pe

latex - maths
here document
<<<SSS
SSS


```

libc-dync mode 
nostdc os mode
.sao => (sljit) => binary


## docker

cmptech/saolang-dev

# TODO - VM and JIT improve

jerryscript/jerry-core/parser/js/byte-code.h
 Compact byte code (CBC) is a byte code representation
 of EcmaScript which is designed for low memory
 environments. Most opcodes are only one or sometimes
 two byte long so the CBC provides a small binary size.

 The execution engine of CBC is a stack machine, where
 the maximum stack size is known in advance for each
 function.


SLJIT - http://sljit.sourceforge.net/
sljitLir.h
SL-JIT Disadvantages
Limited (3 machine words) number of arguments for ABI compatible function calls.


https://en.wikipedia.org/wiki/Java_bytecode_instruction_listings
https://en.wikipedia.org/wiki/Java_bytecode

# Sao C Compiler

```
sao-by-c //sao.c
sao-by-sao //sao.sao
c-by-sao //cc.sao
c-by-c //scc.c
```

scc/
	scc_asm.c   - ASM support
	scc_pps.c   - preprocessing macros
	scc_cpl.c   - raw compiler w/- macros
	scc_gen.c   - binary generator
	scc_lkr.c   - linker?
	scc.c       - driver
	scc_macro.h
	libsao.c      - shared lib

# SAO Compiled by C

c/
	sao-asm.c
	sao-pps.c
	sao-clk.c
	sao-gen.c
	sao-lkr.c
	sao.c

# SAO Compiled by SAO

/
	sao-asm.sao
	sao-pps.sao
	sao-clk.sao
	sao-gen.sao
	sao-lkr.sao


# ideas

能否在启动时获得一个半只读但可执行的内存区间??
我想做一个运行包用于执行SLJIT和基础库……类似loader...要很小.

sao runtime dll/bin

sao $prog (in source code or binary, like lua/nodejs)

or $progbin (which have tiny loader packed)

$progbinloader...how?
how about 

* sao script
like jerry:
```
* vm-and-bytecode-loader(mini) for diff arch, like java vm
* bytecode portable => .bc like java class then.
* load things else from bytecode then, i.e. parser is a .bc
* support output binary(not .bc but .$arch) with XXXX.bc
* support load .$arch.bin if necessary as ext.
```
