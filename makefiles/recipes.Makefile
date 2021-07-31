include $(BASEDIR)/makefiles/config.Makefile

ifdef LIBDEP
	CCFLAGS+=$(patsubst %,-I$(BASEDIR)/libs/%,$(LIBDEP))
	LIBS+=$(patsubst %,$(OUTDIR)/%.a,$(LIBDEP))
endif

LOCALBINDIR=$(patsubst $(BASEDIR)%,$(BINDIR)%,$(PWD))

DEPS=$(patsubst %,$(LOCALBINDIR)/%.d,$(SRCS))
OBJS=$(patsubst %,$(LOCALBINDIR)/%.o,$(SRCS))

.PRECIOUS: $(OBJS) $(DEPS)

%.a: $(OBJS)
	$(ECHO) AR $(notdir $@)
	$(MKDIR) $(dir $@)
	$(AR) $(ARFLAGS) -o $@ $(OBJS) $(LIBS)

%.elf: $(OBJS)
	$(ECHO) LINK $(notdir $@)
	$(MKDIR) $(dir $@)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)


-include $(DEPS)

$(LOCALBINDIR)/%.s.o: %.s
	$(ECHO) AS $(notdir $@)
	$(MKDIR) $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(LOCALBINDIR)/%.c.o: %.c
	$(ECHO) CC $(notdir $@)
	$(MKDIR) $(dir $@)
	$(CC) $(CCFLAGS) -o $@ $<

$(LOCALBINDIR)/%.c.d: %.c
	$(MKDIR) $(dir $@)
	$(CC) $(CCFLAGS) -M -o $@ $< -MT $(patsubst %.d,%.o,$@)
