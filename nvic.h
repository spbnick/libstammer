/*
 * NVIC (Nested Vectored Interrupt Controller)
 */

#ifndef _NVIC_H
#define _NVIC_H

/** NVIC (Nested Vectored Interrupt Controller) */
struct nvic {
    unsigned int iser[8];           /**< Interrupt set-enable registers */
    unsigned int hole1[24];
    unsigned int icer[8];           /**< Interrupt clear-enable registers */
    unsigned int hole2[24];
    unsigned int ispr[8];           /**< Interrupt set-pending registers */
    unsigned int hole3[24];
    unsigned int icpr[8];           /**< Interrupt clear-pending registers */
    unsigned int hole4[24];
    unsigned int iabr[8];           /**< Interrupt active bit registers */
    unsigned int hole5[56];
    union {
        unsigned int    ipr[60];    /**< Interrupt priority registers */
        unsigned char   iprb[240];  /**< Interrupt priority register bytes */
    };
};

/** The NVIC instance */
#define NVIC ((volatile struct nvic *)0xe000e100)

/** Interrupt positions */
enum nvic_int {
    NVIC_INT_WWDG,
    NVIC_INT_PVD,
    NVIC_INT_TAMPER,
    NVIC_INT_RTC,
    NVIC_INT_FLASH,
    NVIC_INT_RCC,
    NVIC_INT_EXTI0,
    NVIC_INT_EXTI1,
    NVIC_INT_EXTI2,
    NVIC_INT_EXTI3,
    NVIC_INT_EXTI4,
    NVIC_INT_DMA1_CHANNEL1,
    NVIC_INT_DMA1_CHANNEL2,
    NVIC_INT_DMA1_CHANNEL3,
    NVIC_INT_DMA1_CHANNEL4,
    NVIC_INT_DMA1_CHANNEL5,
    NVIC_INT_DMA1_CHANNEL6,
    NVIC_INT_DMA1_CHANNEL7,
    NVIC_INT_ADC1_2,
    NVIC_INT_USB_HP_CAN_TX,
    NVIC_INT_USB_LP_CAN_RX0,
    NVIC_INT_CAN_RX1,
    NVIC_INT_CAN_SCE,
    NVIC_INT_EXTI9_5,
    NVIC_INT_TIM1_BRK,
    NVIC_INT_TIM1_UP,
    NVIC_INT_TIM1_TRG_COM,
    NVIC_INT_TIM1_CC,
    NVIC_INT_TIM2,
    NVIC_INT_TIM3,
    NVIC_INT_TIM4,
    NVIC_INT_I2C1_EV,
    NVIC_INT_I2C1_ER,
    NVIC_INT_I2C2_EV,
    NVIC_INT_I2C2_ER,
    NVIC_INT_SPI1,
    NVIC_INT_SPI2,
    NVIC_INT_USART1,
    NVIC_INT_USART2,
    NVIC_INT_USART3,
    NVIC_INT_EXTI15_10,
    NVIC_INT_RTCALARM,
    NVIC_INT_USBWAKEUP,
    NVIC_INT_TIM8_BRK,
    NVIC_INT_TIM8_UP,
    NVIC_INT_TIM8_TRG_COM,
    NVIC_INT_TIM8_CC,
    NVIC_INT_ADC3,
    NVIC_INT_FSMC,
    NVIC_INT_SDIO,
    NVIC_INT_TIM5,
    NVIC_INT_SPI3,
    NVIC_INT_UART4,
    NVIC_INT_UART5,
    NVIC_INT_TIM6,
    NVIC_INT_TIM7,
    NVIC_INT_DMA2_CHANNEL1,
    NVIC_INT_DMA2_CHANNEL2,
    NVIC_INT_DMA2_CHANNEL3,
    NVIC_INT_DMA2_CHANNEL4_5
};

#endif /* _NVIC_H */
