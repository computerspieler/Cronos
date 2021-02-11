export BASEDIR
export BINDIR
export OUTDIR

BASEDIR=$(PWD)
BUILD_SUFFIX=.$(BUILD_TYPE).$(BUILD_TARGET).$(BUILD_TARGET_MACHINE)
BINDIR=$(BASEDIR)/binaries$(BUILD_SUFFIX)
OUTDIR=$(BASEDIR)/build$(BUILD_SUFFIX)

IMG=$(BASEDIR)/images/build$(BUILD_SUFFIX)
LOG=$(BASEDIR)/logs/build$(BUILD_SUFFIX)

LIST_PARTS_TO_BUILD=\
	libs/libc-freestanding \
	kernel

include Makefiles/config.Makefile

.PHONY: all build run image clean
all: build

image: build
	$(ECHO) IMAGE
	$(MKDIR) $(dir $(IMG))
	@./scripts/create-grub-iso.sh $(OUTDIR) $(IMG)

run: image
	$(ECHO) RUN
	$(MKDIR) $(dir $(LOG))
	./scripts/$(BUILD_TARGET)/run-$(EMULATOR).sh $(IMG) $(BUILD_TYPE) $(LOG) $(OUTDIR) $(BUILD_TARGET_MACHINE)

clean:
	$(DEL) $(BINDIR)
	$(DEL) $(OUTDIR)

%-build: %/Makefile
	$(ECHO) BUILD $(patsubst %-build,%,$@)
	@(cd $(BASEDIR)/$(patsubst %-build,%,$@); make build)

build: $(patsubst %,%-build,$(LIST_PARTS_TO_BUILD))
