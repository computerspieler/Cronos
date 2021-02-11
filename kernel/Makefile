SRCS=$(BUILD_TARGET)/$(BUILD_TARGET_MACHINE)/start.s \
	 $(wildcard *.c) \
	 $(wildcard *.s) \
	 $(wildcard $(BUILD_TARGET)/*.c) \
	 $(wildcard $(BUILD_TARGET)/*.s) \
	 $(filter-out $(BUILD_TARGET)/$(BUILD_TARGET_MACHINE)/start.s,$(wildcard $(BUILD_TARGET)/$(BUILD_TARGET_MACHINE)/*.s)) \
	 $(wildcard $(BUILD_TARGET)/$(BUILD_TARGET_MACHINE)/*.c)

LIBDEP=libc-freestanding

build: CCFLAGS+=-Iarch/$(TARGET_ARCHITECTURE)
build: LDFLAGS+=-T linker.ld -e start 
build: $(OUTDIR)/kernel.elf

include $(BASEDIR)/Makefiles/recipes.Makefile
