# Plan

sao - the SAO console command
	sljit - stack less JIT for the SAO lang lowlevel
libsao so/dll - shared lib
libsao.a - static lib
libsaoext so/dll - using external cc to get better performance, elf/macho/pe

# C Compiler

cc/
	saocc_asm.c   - ASM support
	saocc_pps.c   - preprocessing macros
	saocc_cpl.c   - raw compiler w/- macros
	saocc_gen.c   - binary generator
	saocc_lkr.c   - linker?
	saocc.c       - driver
	saocc_macro.h
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
