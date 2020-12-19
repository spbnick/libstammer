ifndef _ARM_CORTEX_M0P_MAIN_MK
_ARM_CORTEX_M0P_MAIN_MK=1

include ../arm/main.mk

TARGET_CFLAGS=-mcpu=cortex-m0plus -mthumb

endif # _ARM_CORTEX_M0P_MAIN_MK
