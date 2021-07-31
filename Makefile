export BASEDIR
export BINDIR
export OUTDIR

BASEDIR=$(PWD)

LIST_PARTS_TO_BUILD=\
	libs/libc \
	kernel

include $(BASEDIR)/makefiles/config.Makefile

.PHONY: all build run image clean
all: build

image: build
	$(ECHO) IMAGE
	$(MKDIR) $(dir $(IMG))
	@./scripts/create-grub-iso.sh $(OUTDIR) $(IMG)

toolchain: scripts/build-toolchain.sh
	$(ECHO) BUILD toolchain
	@./scripts/build-toolchain.sh $(TOOLCHAIN_TARGET) $(TOOLCHAINDIR) 

run: image
	$(ECHO) RUN
	$(MKDIR) $(dir $(LOG))
	@./scripts/$(BUILD_TARGET)/run-$(EMULATOR).sh $(IMG) $(BUILD_TYPE) $(LOG) $(BUILDDIR) $(BUILD_TARGET_MACHINE)

clean:
	$(DEL) $(BINDIR)
	$(DEL) $(OUTDIR)

%-build: %/Makefile
	$(ECHO) BUILD $(patsubst %-build,%,$@)
	@(cd $(BASEDIR)/$(patsubst %-build,%,$@); make build)

build: $(patsubst %,%-build,$(LIST_PARTS_TO_BUILD))
