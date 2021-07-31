TOOLCHAINDIR=$(BUILDDIR)/toolchain
TOOLCHAIN_PREFIX=@$(TOOLCHAINDIR)/bin/$(TOOLCHAIN_TARGET)-

AS=$(TOOLCHAIN_PREFIX)as
AR=$(TOOLCHAIN_PREFIX)ar
CC=$(TOOLCHAIN_PREFIX)gcc
LD=$(TOOLCHAIN_PREFIX)ld

CCFLAGS=-Wall \
	-Wextra \
	-ffreestanding \
	-fno-exceptions \
	-mgeneral-regs-only \
	-c \
	-finline-functions \
	-DMACHINE_$(BUILD_TARGET_MACHINE)
ASFLAGS=
ARFLAGS=rcs
LDFLAGS=-N

ifeq ($(BUILD_TYPE),debug)
	ASFLAGS+=-g -ggdb
	CCFLAGS+=-g -ggdb -DDEBUG_BUILD
endif
