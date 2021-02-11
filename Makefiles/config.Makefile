HOST_OS=linux
EMULATOR=qemu
BUILD_TYPE=debug
BUILD_TARGET=i386
BUILD_TARGET_MACHINE=pc

include $(BASEDIR)/Makefiles/toolchain.Makefile
include $(BASEDIR)/Makefiles/$(HOST_OS).Makefile
