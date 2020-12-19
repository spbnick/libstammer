/*
 * NVIC (Nested Vectored Interrupt Controller)
 */

#ifndef _STM32L052C8T6_NVIC_H
#define _STM32L052C8T6_NVIC_H

#include <../stm32l052c8t6/misc.h>
#include <../arm_cortex_m0p/nvic.h>

/**
 * Interrupt numbers (positions).
 * Source: ST RM0376 Reference Manual, 12.3 Interrupt and exception vectors,
 *         Table 53. List of vectors.
 */
enum nvic_int {
    NVIC_INT_WWDG,
    NVIC_INT_PVD,
    NVIC_INT_RTC,
    NVIC_INT_FLASH,
    NVIC_INT_RCC_CRS,
    NVIC_INT_EXTI_1_0,
    NVIC_INT_EXTI_3_2,
    NVIC_INT_EXTI_15_4,
    NVIC_INT_TSC,
    NVIC_INT_DMA1_CHANNEL_1,
    NVIC_INT_DMA1_CHANNEL_3_2,
    NVIC_INT_DMA1_CHANNEL_7_4,
    NVIC_INT_ADC_COMP,
    NVIC_INT_LPTIM1,
    NVIC_INT_USART4_USART5,
    NVIC_INT_TIM2,
    NVIC_INT_TIM3,
    NVIC_INT_TIM6_DAC,
    NVIC_INT_TIM7,
    NVIC_INT_RESERVED,
    NVIC_INT_TIM21,
    NVIC_INT_I2C3,
    NVIC_INT_TIM22,
    NVIC_INT_I2C1,
    NVIC_INT_I2C2,
    NVIC_INT_SPI1,
    NVIC_INT_SPI2,
    NVIC_INT_USART1,
    NVIC_INT_USART2,
    NVIC_INT_LPUART1_AES_RNG,
    NVIC_INT_MISSING,
    NVIC_INT_USB,
    /** Number of interrupts, not an actual interrupt */
    NVIC_INT_NUM
};

#endif /* _STM32L052C8T6_NVIC_H */
