CC=arm-none-eabi-

TARGET_CFLAGS=-mcpu=cortex-m3 -mthumb

PROGRAMS = \
    blink

all: $(PROGRAMS:=.bin)

%.o: %.c
	$(CC)gcc $(TARGET_CFLAGS) $(CFLAGS) -g3 -c -o $@ $<
	$(CC)gcc $(TARGET_CFLAGS) $(CFLAGS) -MM $< > $*.d

%.o: %.S
	$(CC)gcc $(TARGET_CFLAGS) $(CFLAGS) -g3 -D__ASSEMBLY__ -c -o $@ $<
	$(CC)gcc $(TARGET_CFLAGS) $(CFLAGS) -D__ASSEMBLY__ -MM $< > $*.d

define ELF_RULE
$(strip $(1))_OBJS = $(1)_vectors.o $$(addsuffix .o, $(1) $$($(strip $(1))_MODULES))
$(1).elf: $$($(strip $(1))_OBJS) flash.ld memory.ld
	$(CC)ld -T flash.ld -o $$@ $$($(strip $(1))_OBJS)
OBJS += $$($(strip $(1))_OBJS)
endef
$(foreach p, $(PROGRAMS), $(eval $(call ELF_RULE, $(p))))
DEPS = $(OBJS:.o=.d)
-include $(DEPS)

%.bin: %.elf
	$(CC)objcopy -O binary $< $@

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -f $(PROGRAMS:=.elf)
	rm -f $(PROGRAMS:=.bin)
