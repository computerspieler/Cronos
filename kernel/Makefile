SRCS=$(BUILD_TARGET)/$(BUILD_TARGET_MACHINE)/start.s \
	 $(wildcard *.c) \
	 $(wildcard *.s) \
	 $(wildcard $(BUILD_TARGET)/*.c) \
	 $(wildcard $(BUILD_TARGET)/*.s) \
	 $(filter-out $(BUILD_TARGET)/$(BUILD_TARGET_MACHINE)/start.s,$(wildcard $(BUILD_TARGET)/$(BUILD_TARGET_MACHINE)/*.s)) \
	 $(wildcard $(BUILD_TARGET)/$(BUILD_TARGET_MACHINE)/*.c)

LIBDEP=libc
CCFLAGS+=-I$(PWD)/$(BUILD_TARGET)/$(BUILD_TARGET_MACHINE) -I$(PWD)/$(BUILD_TARGET) -I$(PWD)
LDFLAGS+=-T linker.ld -e start 

build: $(OUTDIR)/kernel.elf

include $(BASEDIR)/makefiles/recipes.Makefile
