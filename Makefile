CC=arm-none-eabi-

TARGET_CFLAGS=-mcpu=cortex-m3 -mthumb

COMMON_MODULES = init

all: libstammer.a

%.o: %.c
	$(CC)gcc $(TARGET_CFLAGS) $(CFLAGS) -g3 -c -o $@ $<
	$(CC)gcc $(TARGET_CFLAGS) $(CFLAGS) -MM $< > $*.d

%.o: %.S
	$(CC)gcc $(TARGET_CFLAGS) $(CFLAGS) -g3 -D__ASSEMBLY__ -c -o $@ $<
	$(CC)gcc $(TARGET_CFLAGS) $(CFLAGS) -D__ASSEMBLY__ -MM $< > $*.d

MODULES = init

OBJS = $(addsuffix .o, $(MODULES))
DEPS = $(addsuffix .d, $(MODULES))
-include $(DEPS)

libstammer.a: $(OBJS)
	$(CC)ar rcs $@ $<

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -f libstammer.a
