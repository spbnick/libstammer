ifndef _STM32F103C8T6_MAIN_MK
_STM32F103C8T6_MAIN_MK=1

MODULES += \
    ../stm32f103c8t6/gpio \
    ../stm32f103c8t6/nvic \
    ../stm32f103c8t6/usart

include ../stm32/main.mk

endif # _STM32F103C8T6_MAIN_MK
