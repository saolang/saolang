# Plan

```
sao - the SAO console command
	sljit - using stack-less-JIT for the lowlevel
libsao so/dll - shared lib
libsao.a - static lib
libsaoext so/dll - using external cc to get better performance, elf/macho/pe
```

libc-dync mode 
nostdc os mode
.sao => (sljit) => binary

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
