# --------------------------------------------------------------------------
# Sao C Compiler Makefile

ifndef TOP
 TOP = .
 INCLUDED = no
endif

ENV_MAK=Makefile.env
ifeq ($(ENV_MAK), $(wildcard $(ENV_MAK)))
include $(ENV_MAK)
endif
ENV_MAK=../Makefile.env
ifeq ($(ENV_MAK), $(wildcard $(ENV_MAK)))
include $(ENV_MAK)
endif

CONFIG_MAK = $(TOP)/config.mak
ifeq ($(CONFIG_MAK), $(wildcard $(CONFIG_MAK)))
include $(CONFIG_MAK)
else
NEED_CONFIG=1
endif

ifeq (-$(CC)-$(GCC_MAJOR)-$(findstring $(GCC_MINOR),56789)-,-gcc-4--)
 CFLAGS += -D_FORTIFY_SOURCE=0
endif

LIBSCC = libscc.a
LIBSCC1 = libscc1.a
LINK_LIBSCC =
LIBS =
CFLAGS += -I$(TOP)
CFLAGS += $(CPPFLAGS)
VPATH = $(TOPSRC)

ifdef CONFIG_WIN32

 ifneq ($(CONFIG_static),yes)
  LIBSCC = libscc$(DLLSUF)
  LIBSCCDEF = libscc.def
 endif
 CFGWIN = -win
 NATIVE_TARGET = $(SCC_ARCH)-WIN$(if $(findstring ARM,$(SCC_ARCH)),CE,32)

else

ifdef CONFIG_OSX
else
 LIBS=-lm
 ifneq ($(CONFIG_ldl),no)
  LIBS+=-ldl
 endif
endif

 # make libscc as static or dynamic library?
 ifeq ($(CONFIG_static),no)
  LIBSCC=libscc$(DLLSUF)
  export LD_LIBRARY_PATH := $(CURDIR)/$(TOP)
  ifneq ($(CONFIG_rpath),no)
   LINK_LIBSCC += -Wl,-rpath,"$(libdir)"
  endif
 endif
 CFGWIN =-unx

 NATIVE_TARGET = $(SCC_ARCH)-$(SCC_OS)
 
 ifdef CONFIG_OSX
  ifeq (-$(findstring $(CC),scc)-,-scc-)
    LDFLAGS += -flat_namespace
  endif
  export MACOSX_DEPLOYMENT_TARGET := 10.2
 endif
endif

# run local version of scc with local libraries and includes
SCCFLAGS-unx = -B$(TOP) -I$(TOPSRC)/include -I$(TOPSRC) -I$(TOP)
SCCFLAGS-win = -B$(TOPSRC)/win32 -I$(TOPSRC)/include -I$(TOPSRC) -I$(TOP) -L$(TOP)
SCCFLAGS = $(SCCFLAGS$(CFGWIN))
SCC = $(TOP)/scc$(EXESUF) $(SCCFLAGS)
ifdef CONFIG_OSX
 SCCFLAGS += -D_ANSI_SOURCE
endif

CFLAGS_P = $(CFLAGS) -pg -static -DCONFIG_SCC_STATIC -DSCC_PROFILE
LIBS_P = $(LIBS)
LDFLAGS_P = $(LDFLAGS)

CONFIG_$(SCC_ARCH) = yes

##NATIVE_DEFINES_$(CONFIG_i386) += -DSCC_TARGET_I386
##NATIVE_DEFINES_$(CONFIG_X86-64) += -DSCC_TARGET_X86_64
##NATIVE_DEFINES_$(CONFIG_WIN32) += -DSCC_TARGET_PE
##NATIVE_DEFINES_$(CONFIG_OSX) += -DSCC_TARGET_MACHO

##NATIVE_DEFINES_$(CONFIG_uClibc) += -DSCC_UCLIBC
#TODO
NATIVE_DEFINES_$(CONFIG_musl) += -DSCC_MUSL
##NATIVE_DEFINES_$(CONFIG_libgcc) += -DCONFIG_USE_LIBGCC
##NATIVE_DEFINES_$(CONFIG_selinux) += -DHAVE_SELINUX

##NATIVE_DEFINES_$(CONFIG_X86-32-LNX) += -DSCC_TARGET_I386
##NATIVE_DEFINES_$(CONFIG_X86-64-LNX) += -DSCC_TARGET_X86_64
##NATIVE_DEFINES_$(CONFIG_X86-64-OSX) += -DSCC_TARGET_MACHO
##NATIVE_DEFINES_$(CONFIG_ARM-32-LNX) += -DSCC_TARGET_ARM
##NATIVE_DEFINES_$(CONFIG_ARM-32-LNX_EABIHF) += -DSCC_ARM_EABI -DSCC_ARM_HARDFLOAT
##NATIVE_DEFINES_$(CONFIG_ARM-32-LNX_EABI) += -DSCC_ARM_EABI
##NATIVE_DEFINES_$(CONFIG_ARM-32-LNX_VFP) += -DSCC_ARM_VFP
##NATIVE_DEFINES_$(CONFIG_ARM-64-LNX) += -DSCC_TARGET_ARM64
NATIVE_DEFINES += $(NATIVE_DEFINES_yes)

ifeq ($(INCLUDED),no)
# --------------------------------------------------------------------------
# running top Makefile

PROGS = scc$(EXESUF)
SCCLIBS = $(LIBSCC1) $(LIBSCC) $(LIBSCCDEF)


# --------------------------------------------------------------------------
ifdef NEED_CONFIG

default:env
	@echo ERROR: not found config.mak, maybe need ./configure
everything:env
	@echo ERROR: not found config.mak, maybe need ./configure

else #NEED_CONFIG

default:env $(PROGS) $(SCCLIBS)

ifeq ($(CONFIG_WIN32),yes)
everything:env clean $(PROGS) $(SCCLIBS) cross libscc.dll
else
everything:env clean $(PROGS) $(SCCLIBS) cross libscc.so
endif

ifdef CONFIG_cross
default:cross
endif

all:default

endif #NEED_CONFIG
# --------------------------------------------------------------------------

env:
	$(eval export SCC_ARCH=$(SCC_ARCH))
	$(eval export SCC_OS=$(SCC_OS))
	@echo ${SCC_OS},${SCC_ARCH}

# cross compiler targets to build
SCC_X     = X86-32-LNX X86-64-LNX X86-32-WIN X86-64-WIN X86-64-OSX ARM-64-LNX ARM-32-LNX

# cross libscc1.a targets to build
#LIBSCC1_X = X86-32-LNX X86-64-LNX X86-32-WIN X86-64-WIN X86-64-OSX ARM-64-LNX ARM-32-LNX
LIBSCC1_X = $(SCC_X)
PROGS_CROSS = $(foreach X,$(SCC_X),$X-scc$(EXESUF))
LIBSCC1_CROSS = $(foreach X,$(LIBSCC1_X),$X-libscc1.a)

# build cross compilers & libs
cross: $(LIBSCC1_CROSS) $(PROGS_CROSS)

# build specific cross compiler & lib
cross-%: %-scc$(EXESUF) %-libscc1.a ;

install: all
	@$(MAKE) --no-print-directory install$(CFGWIN)
install-strip: ; @$(MAKE) --no-print-directory install$(CFGWIN) CONFIG_strip=yes
uninstall: ; @$(MAKE) --no-print-directory uninstall$(CFGWIN)

# --------------------------------------------

T = $(or $(CROSS_TARGET),$(NATIVE_TARGET),unknown)
X = $(if $(CROSS_TARGET),$(CROSS_TARGET)-)

DEF-X86-32-LNX         = -D __SCC_TARGET_OS__=LNX -D__SCC_TARGET_FORMAT__=ELF   -D __SCC_TARGET_CPU__=X86 -D __SCC_TARGET_CPU_BIT__=32
DEF-X86-64-LNX         = -D __SCC_TARGET_OS__=LNX -D__SCC_TARGET_FORMAT__=ELF   -D __SCC_TARGET_CPU__=X86 -D __SCC_TARGET_CPU_BIT__=64

DEF-X86-32-WIN         = -D __SCC_TARGET_OS__=WIN -D__SCC_TARGET_FORMAT__=PE    -D __SCC_TARGET_CPU__=X86 -D __SCC_TARGET_CPU_BIT__=32
DEF-X86-64-WIN         = -D __SCC_TARGET_OS__=WIN -D__SCC_TARGET_FORMAT__=PE    -D __SCC_TARGET_CPU__=X86 -D __SCC_TARGET_CPU_BIT__=64

DEF-X86-64-OSX         = -D __SCC_TARGET_OS__=OSX -D__SCC_TARGET_FORMAT__=MACHO -D __SCC_TARGET_CPU__=X86 -D __SCC_TARGET_CPU_BIT__=64

DEF-ARM-64-LNX         = -D __SCC_TARGET_OS__=LNX -D__SCC_TARGET_FORMAT__=ELF   -D __SCC_TARGET_CPU__=ARM -D __SCC_TARGET_CPU_BIT__=64
DEF-ARM-32-LNX-FPA     = -D __SCC_TARGET_OS__=LNX -D__SCC_TARGET_FORMAT__=ELF   -D __SCC_TARGET_CPU__=ARM -D __SCC_TARGET_CPU_BIT__=32
DEF-ARM-32-LNX-FPA-LD  = -D __SCC_TARGET_OS__=LNX -D__SCC_TARGET_FORMAT__=ELF   -D __SCC_TARGET_CPU__=ARM -D __SCC_TARGET_CPU_BIT__=32 -DLDOUBLE_SIZE=12
DEF-ARM-32-LNX-VFP     = -D __SCC_TARGET_OS__=LNX -D__SCC_TARGET_FORMAT__=ELF   -D __SCC_TARGET_CPU__=ARM -D __SCC_TARGET_CPU_BIT__=32 -DSCC_ARM_VFP
DEF-ARM-32-LNX-EABI    = -D __SCC_TARGET_OS__=LNX -D__SCC_TARGET_FORMAT__=ELF   -D __SCC_TARGET_CPU__=ARM -D __SCC_TARGET_CPU_BIT__=32 -DSCC_ARM_VFP -DSCC_ARM_EABI
DEF-ARM-32-LNX-EABIHF  = -D __SCC_TARGET_OS__=LNX -D__SCC_TARGET_FORMAT__=ELF   -D __SCC_TARGET_CPU__=ARM -D __SCC_TARGET_CPU_BIT__=32 -DSCC_ARM_VFP -DSCC_ARM_EABI -DSCC_ARM_HARDFLOAT

DEF-ARM-32-WIN         = -D __SCC_TARGET_OS__=WIN -D__SCC_TARGET_FORMAT__=PE    -D __SCC_TARGET_CPU__=ARM -D __SCC_TARGET_CPU_BIT__=32 -DSCC_ARM_VFP -DSCC_ARM_EABI -DSCC_ARM_HARDFLOAT

#//default arm 32:
DEF-ARM-32-LNX         = $(DEF-ARM-32-LNX-EABIHF)
#DEF-$(NATIVE_TARGET)   = $(NATIVE_DEFINES)
DEF-$(NATIVE_TARGET)   += $(NATIVE_DEFINES)

DEFINES += $(DEF-$T) $(DEF-all)
DEFINES += $(if $(ROOT-$T),-DCONFIG_SYSROOT="\"$(ROOT-$T)\"")
DEFINES += $(if $(CRT-$T),-DCONFIG_SCC_CRTPREFIX="\"$(CRT-$T)\"")
DEFINES += $(if $(LIB-$T),-DCONFIG_SCC_LIBPATHS="\"$(LIB-$T)\"")
DEFINES += $(if $(INC-$T),-DCONFIG_SCC_SYSINCLUDEPATHS="\"$(INC-$T)\"")
DEFINES += $(DEF-$(or $(findstring win,$T),unx))

# include custom configuration (see make help)
-include config-extra.mak

CORE_FILES = scc.c scctools.c libscc.c sccpp.c sccgen.c sccasm.c sccrun.c libsao.c
CORE_FILES += scc.h config.h libscc.h scctok.h

#X86-32-LNX_FILES = $(CORE_FILES) scc-ELF.c   gen-X86-32.c link-X86.c    asm-X86.c asm-X86-32.h tok-X86.h
#X86-32-WIN_FILES = $(CORE_FILES) scc-PE.c    gen-X86-32.c link-X86.c    asm-X86.c asm-X86-32.h tok-X86.h
#X86-32-LNX_FILES = $(CORE_FILES) scc-ELF.c   gen-X86-32.c link-X86.c    asm-X86.c asm-X86-32.h
#X86-32-WIN_FILES = $(CORE_FILES) scc-PE.c    gen-X86-32.c link-X86.c    asm-X86.c asm-X86-32.h
#X86-64-LNX_FILES = $(CORE_FILES) scc-ELF.c   gen-X86-64.c link-X86-64.c asm-X86.c asm-X86-64.h
#X86-64-WIN_FILES = $(CORE_FILES) scc-PE.c    gen-X86-64.c link-X86-64.c asm-X86.c asm-X86-64.h
#X86-64-OSX_FILES = $(CORE_FILES) scc-MACHO.c gen-X86-64.c link-X86-64.c asm-X86.c asm-X86-64.h
X86-32-LNX_FILES = $(CORE_FILES) scc-ELF.c   gen-X86-32.c link-X86.c    asm-X86.c
X86-32-WIN_FILES = $(CORE_FILES) scc-PE.c    gen-X86-32.c link-X86.c    asm-X86.c
X86-64-LNX_FILES = $(CORE_FILES) scc-ELF.c   gen-X86-64.c link-X86-64.c asm-X86.c
X86-64-WIN_FILES = $(CORE_FILES) scc-PE.c    gen-X86-64.c link-X86-64.c asm-X86.c
X86-64-OSX_FILES = $(CORE_FILES) scc-MACHO.c gen-X86-64.c link-X86-64.c asm-X86.c
ARM-32-LNX_FILES = $(CORE_FILES) scc-ELF.c   gen-ARM-32.c link-ARM-32.c asm-ARM-32.c
ARM-32-WIN_FILES = $(CORE_FILES) scc-PE.c    gen-ARM-32.c link-ARM-32.c asm-ARM-32.c
ARM-64-LNX_FILES = $(CORE_FILES) scc-ELF.c   gen-ARM-64.c link-ARM-64.c

# libscc sources
LIBSCC_SRC = $(filter-out scc.c scctools.c,$(filter %.c,$($T_FILES)))

ifeq ($(ONE_SOURCE),yes)
LIBSCC_OBJ = $(X)libscc.o
LIBSCC_INC = $($T_FILES)
SCC_FILES = $(X)scc.o
scc.o : DEFINES += -D ONE_SOURCE=0
else
LIBSCC_OBJ = $(patsubst %.c,$(X)%.o,$(LIBSCC_SRC))
LIBSCC_INC = $(filter %.h gen-%.c link-%.c,$($T_FILES))
SCC_FILES = $(X)scc.o $(LIBSCC_OBJ)
$(SCC_FILES) : DEFINES += -D ONE_SOURCE=0
endif

# target specific object rule
$(X)%.o : %.c $(LIBSCC_INC)
	$(CC) -o $@ -c $< $(DEFINES) $(CFLAGS)

# additional dependencies
$(X)scc.o : scctools.c

# Host Sao C Compiler
scc$(EXESUF): scc.o $(LIBSCC)
	$(CC) -o $@ $^ $(LIBS) $(LDFLAGS) $(LINK_LIBSCC)

# Cross Sao C Compilers
%-scc$(EXESUF): FORCE
	@$(MAKE) --no-print-directory $@ CROSS_TARGET=$* ONE_SOURCE=$(or $(ONE_SOURCE),yes)

$(CROSS_TARGET)-scc$(EXESUF): $(SCC_FILES)
	$(CC) -o $@ $^ $(LIBS) $(LDFLAGS)

# profiling version
scc_p$(EXESUF): $($T_FILES)
	$(CC) -o $@ $< $(DEFINES) $(CFLAGS_P) $(LIBS_P) $(LDFLAGS_P)

# static libscc library
libscc.a: $(LIBSCC_OBJ)
	$(AR) rcs $@ $^

# dynamic libscc library
libscc.so: $(LIBSCC_OBJ)
ifdef CONFIG_OSX
	$(CC) -shared -Wl,-install_name,$@ -o $@ $^ $(LDFLAGS)
else
	$(CC) -shared -Wl,-soname,$@ -o $@ $^ $(LDFLAGS)
endif

libscc.so: CFLAGS+=-fPIC
libscc.so: LDFLAGS+=-fPIC

# windows dynamic libscc library
libscc.dll : $(LIBSCC_OBJ)
	$(CC) -shared -o $@ $^ $(LDFLAGS)
libscc.dll : DEFINES += -DLIBSCC_AS_DLL

# import file for windows libscc.dll
libscc.def : libscc.dll scc$(EXESUF)
	$(XSCC) -impdef $< -o $@
XSCC ?= ./scc$(EXESUF)

# SaoCC runtime libraries
libscc1.a : scc$(EXESUF) FORCE
	@echo libscc1.a =: $(MAKE) -C lib DEFINES='$(DEF-$T)'
	@$(MAKE) -C lib DEFINES='$(DEF-$T)'
# Cross libscc1.a
%-libscc1.a : %-scc$(EXESUF) FORCE
	@echo *-libscc1.a =: $(MAKE) -C lib DEFINES='$(DEF-$*)' CROSS_TARGET=$*
	@$(MAKE) -C lib DEFINES='$(DEF-$*)' CROSS_TARGET=$*
FORCE:
# --------------------------------------------------------------------------
# install

INSTALL = install -m644
INSTALLBIN = install -m755 $(STRIP_$(CONFIG_strip))
STRIP_yes = -s

IB = $(if $1,mkdir -p $2 && $(INSTALLBIN) $1 $2)
IBw = $(call IB,$(wildcard $1),$2)
IF = $(if $1,mkdir -p $2 && $(INSTALL) $1 $2)
IFw = $(call IF,$(wildcard $1),$2)
IR = mkdir -p $2 && cp -r $1/. $2

# install progs & libs
install-unx:
	$(call IBw,$(PROGS) $(PROGS_CROSS),"$(bindir)")
	#$(call IF,$(TOPSRC)/include/*.h,"$(sccdir)/include")
	$(call $(if $(findstring .so,$(LIBSCC)),IBw,IFw),$(LIBSCC),"$(libdir)")
	$(call IF,$(TOPSRC)/libscc.h,"$(includedir)")
	#$(call IFw,scc-doc.info,"$(infodir)")
	#$(call IFw,scc-doc.html,"$(docdir)")

# uninstall
uninstall-unx:
	@rm -fv $(foreach P,$(PROGS) $(PROGS_CROSS),"$(bindir)/$P")
	@rm -fv "$(libdir)/libscc.a" "$(libdir)/libscc.so" "$(includedir)/libscc.h"
	rm -r "$(sccdir)"

# install progs & libs on windows
install-win:
	$(call IBw,$(PROGS) $(PROGS_CROSS) $(subst libscc.a,,$(LIBSCC)),"$(bindir)")
	$(call IF,$(TOPSRC)/lib/*.def,"$(sccdir)")
	$(call IFw,$(TOPSRC)/libscc.h $(subst .dll,.def,$(LIBSCC)),"$(libdir)")

# the msys-git shell works to configure && make except it does not have install
ifeq "$(and $(CONFIG_WIN32),$(shell which install >/dev/null 2>&1 || echo no))" "no"
install-win : INSTALL = cp
install-win : INSTALLBIN = cp
endif

# uninstall on windows
uninstall-win:
	@rm -fv $(foreach P,$(PROGS) $(PROGS_CROSS) libscc.dll,"$(bindir)/$P")
	@rm -fv $(foreach F,scc-doc.html scc-win32.txt,"$(docdir)/$F")
	@rm -fv $(foreach F,libscc.h libscc.def libscc.a,"$(libdir)/$F")
	rm -r "$(sccdir)"

# --------------------------------------------------------------------------
SCC-VERSION = scc-$(VERSION)

config.mak:
	$(if $(wildcard $@),,@echo "Please run ./configure." && exit 1)

# run all tests
test:
	$(MAKE) -C tests
tests2.%:
	$(MAKE) -C tests/tests2 $@

testspp.%:
	$(MAKE) -C tests/pp $@

clean:
	rm -f scc$(EXESUF) scc_p$(EXESUF) *-scc$(EXESUF) scc.pod
	rm -f  *~ *.o *.a *.so* *.out *.log lib*.def *.exe *.dll a.out tags TAGS
	@$(MAKE) -C lib $@
	cd ..
	rm -f  *~ *.o *.a *.so* *.out *.log lib*.def *.exe *.dll a.out tags TAGS

distclean: clean
	rm -f config.h config.mak config.texi scc.1 scc-doc.info scc-doc.html

#.PHONY: all clean test tar tags ETAGS distclean install uninstall FORCE

help:
	@echo "make"
	@echo "make default"
	@echo "make all"
	@echo "   build native compiler (from separate objects)"
	@echo ""
	@echo "make everything"
	@echo "   clean and make everything can be make..."
	@echo ""
	@echo "make cross"
	@echo "   build cross compilers (from one source)"
	@echo ""
	@echo "make ONE_SOURCE=yes / no"
	@echo "   force building from one source / separate objects"
	@echo ""
	@echo "make cross-TARGET"
	@echo "   build one specific cross compiler for 'TARGET', as in"
	@echo "   $(SCC_X)"
	@echo ""
	@echo "Custom configuration:"
	@echo "   The makefile includes a file 'config-extra.mak' if it is present."
	@echo "   This file may contain some custom configuration.  For example:"
	@echo ""
	@echo "      NATIVE_DEFINES += -D..."
	@echo ""
	@echo "   Or for example to configure the search paths for a cross-compiler"
	@echo "   that expects the linux files in <sccdir>/i386-linux:"
	@echo ""
	@echo "      ROOT-i386 = {B}/i386-linux"
	@echo "      CRT-i386  = {B}/i386-linux/usr/lib"
	@echo "      LIB-i386  = {B}/i386-linux/lib:{B}/i386-linux/usr/lib"
	@echo "      INC-i386  = {B}/lib/include:{B}/i386-linux/usr/include"
	@echo "      DEF-i386  += -D__linux__"
	@echo ""
	@echo "make test"
	@echo "   run all tests"
	@echo ""
	@echo "make tests2.all / make tests2.37 / make tests2.37+"
	@echo "   run all/single test(s) from tests2, optionally update .expect"
	@echo "make testspp.all / make testspp.17"
	@echo "   run all/single test(s) from tests/pp"
	@echo ""
	@echo "Other supported make targets:"
	@echo "   install install-strip tags ETAGS tar clean distclean help"
	@echo ""

makedebug:
	@echo T=$(T),X=$(X)
	@echo DEF-T=$(DEF-$T)
	@echo T_FILES=$($T_FILES)
	@echo SCCLIBS=$(SCCLIBS)
	@echo LIBSCC=$(LIBSCC)
	@echo SCCFLAGS=$(SCCFLAGS)
	@echo CFGWIN=$(CFGWIN)
	@echo SCC_ARCH=$(SCC_ARCH)
	@echo CROSS_TARGET=$(CROSS_TARGET)
	@echo NATIVE_TARGET=$(NATIVE_TARGET)
	@echo DEFINES=$(DEFINES)
	@echo LIBSCC_SRC=$(LIBSCC_SRC)
	@echo CONFIG_OSX=$(CONFIG_OSX)
	@echo ONE_SOURCE=$(ONE_SOURCE)
	@echo LIBSCC_OBJ=$(LIBSCC_OBJ)
	@echo LIBSCC_INC=$(LIBSCC_INC)

# --------------------------------------------------------------------------
endif # ($(INCLUDED),no)
