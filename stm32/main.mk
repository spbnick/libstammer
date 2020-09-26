CCPFX=arm-none-eabi-

COMMON_CFLAGS = $(TARGET_CFLAGS) -Wall -Wextra -Werror -O2 -g3 -I. $(CFLAGS)

MODULES += \
    ../stm32/test \
    ../stm32/misc \
    ../stm32/prng \
    ../stm32/reset \
    ../stm32/semihosting

all: libstammer.a

%.o: %.c
	$(CCPFX)gcc $(COMMON_CFLAGS) -c -o $@ $<
	$(CCPFX)gcc $(COMMON_CFLAGS) -MM $< > $*.d

%.o: %.S
	$(CCPFX)gcc $(COMMON_CFLAGS) -D__ASSEMBLY__ -c -o $@ $<
	$(CCPFX)gcc $(COMMON_CFLAGS) -D__ASSEMBLY__ -MM $< > $*.d

OBJS = $(addsuffix .o, $(MODULES))
DEPS = $(addsuffix .d, $(MODULES))
-include $(DEPS)

libstammer.a: $(OBJS)
	$(CCPFX)ar rcs $@ $?

clean:
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -f libstammer.a
