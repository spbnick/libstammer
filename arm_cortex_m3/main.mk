ifndef _ARM_CORTEX_M3_MAIN_MK
_ARM_CORTEX_M3_MAIN_MK=1

include ../arm/main.mk

TARGET_CFLAGS=-mcpu=cortex-m3 -mthumb

endif # _ARM_CORTEX_M3_MAIN_MK
