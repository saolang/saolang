#
# Tiny C Compiler Makefile for libscc1.a
#

TOP = ..
include $(TOP)/Makefile

VPATH = $(TOPSRC)/lib $(TOPSRC)/win32/lib
T = $(or $(CROSS_TARGET),$(NATIVE_TARGET),unknown)
X = $(if $(CROSS_TARGET),$(CROSS_TARGET)-)
BIN = $(TOP)/$(X)libscc1.a

XSCC ?= $(TOP)/$(X)scc$(EXESUF)
XCC = $(XSCC)
XAR = $(XSCC) -ar
XFLAGS-unx = -B$(TOPSRC) -I$(TOPSRC)/win32/include -I$(TOPSRC)/include_lib -I$(TOPSRC)
XFLAGS-win = -B$(TOPSRC) -I$(TOPSRC)/win32/include -I$(TOPSRC)/include_lib -I$(TOPSRC)
XFLAGS = $(XFLAGS$(XCFG))
XCFG = $(or $(findstring -win,$T),-unx)

# in order to use gcc, tyoe: make <target>-libscc1-usegcc=yes
arm-libscc1-usegcc ?= no

ifeq "$($(T)-libscc1-usegcc)" "yes"
 XCC = $(CC)
 XAR = $(AR)
 XFLAGS = $(CFLAGS) -fPIC
endif

# wjc not using bcheck, will do again in future...
## only for native compiler
#$(X)BCHECK_O = bcheck.o
#
#ifeq ($(CONFIG_musl)$(CONFIG_uClibc),yes)
# BCHECK_O =
#endif

BCHECK_O =

ifdef CONFIG_OSX
 XFLAGS += -D_ANSI_SOURCE
endif

X86-32_O = libscc1.o alloca86.o alloca86-bt.o
X86-64_O = libscc1.o alloca86_64.o alloca86_64-bt.o

ARM_O = libscc1.o armeabi.o alloca-arm.o armflush.o
ARM-64_O = lib-arm64.o

#TODO
WIN_O = crt1.o crt1w.o wincrt1.o wincrt1w.o dllcrt1.o dllmain.o

OBJ-X86-32-LNX        = $(X86-32_O) $(BCHECK_O)
OBJ-X86-64-LNX        = $(X86-64_O) $(BCHECK_O)
OBJ-X86-64-OSX        = $(X86-64_O) 
OBJ-X86-32-WIN        = $(X86-32_O) chkstk.o $(BCHECK_O) $(WIN_O)
OBJ-X86-64-WIN        = $(X86-64_O) chkstk.o $(BCHECK_O) $(WIN_O)
OBJ-ARM-64-LNX        = $(ARM-64_O)
OBJ-ARM-32-LNX        = $(ARM_O)
OBJ-ARM-32-LNX-FPA    = $(ARM_O)
OBJ-ARM-32-LNX-FPA-LD = $(ARM_O)
OBJ-ARM-32-LNX-VFP    = $(ARM_O)
OBJ-ARM-32-LNX-EABI   = $(ARM_O)
OBJ-ARM-32-LNX-EABIHF = $(ARM_O)
OBJ-ARM-32-WIN = $(ARM_O) $(WIN_O)

$(BIN) :$(patsubst %.o,$(X)%.o,$(OBJ-$T))
	@echo BIN=$(BIN),X=$(X),T=$(T),,,$@,,,$^
	$(XAR) rcs $@ $^

$(X)%.o : %.c
	$(XCC) -c $< -o $@ $(XFLAGS)

$(X)%.o : %.S
	$(XCC) -c $< -o $@ $(XFLAGS)

$(X)crt1w.o : crt1.c
$(X)wincrt1w.o : wincrt1.c

clean :
	rm -f *.a *.o $(BIN)

#makedebuglib:
#	@echo SCC_ARCH=$(SCC_ARCH)
#	@echo T=$(T)
#	@echo OBJ-T=$(OBJ-$T)
#	@echo TOP=$(TOP)
#	@echo SCC_ARCH=$(SCC_ARCH)
#	@echo CROSS_TARGET=$(CROSS_TARGET)
#	@echo NATIVE_TARGET=$(NATIVE_TARGET)
#
