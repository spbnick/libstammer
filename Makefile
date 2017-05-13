CC=arm-none-eabi-

TARGET_CFLAGS=-mcpu=cortex-m3 -mthumb
COMMON_CFLAGS = $(TARGET_CFLAGS) -Wall -Wextra -Werror -O2 -g3

all: libstammer.a

%.o: %.c
	$(CC)gcc $(COMMON_CFLAGS) $(CFLAGS) -c -o $@ $<
	$(CC)gcc $(COMMON_CFLAGS) $(CFLAGS) -MM $< > $*.d

%.o: %.S
	$(CC)gcc $(COMMON_CFLAGS) $(CFLAGS) -D__ASSEMBLY__ -c -o $@ $<
	$(CC)gcc $(COMMON_CFLAGS) $(CFLAGS) -D__ASSEMBLY__ -MM $< > $*.d

MODULES = \
    gpio \
    prng \
    init \
    vectors

OBJS = $(addsuffix .o, $(MODULES))
DEPS = $(addsuffix .d, $(MODULES))
-include $(DEPS)

libstammer.a: $(OBJS)
	$(CC)ar rcs $@ $?

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -f libstammer.a
