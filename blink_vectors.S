.syntax unified

.section ".vectors"

/* Stack top */
.word 0x20001000
/* Handlers */
.word reset             /* Reset */
.word default_handler   /* NMI */
.word default_handler   /* HardFault */
.word default_handler   /* MemManage */
.word default_handler   /* BusFault */
.word default_handler   /* UsageFault */
.word default_handler   /* Reserved1 */
.word default_handler   /* Reserved2 */
.word default_handler   /* Reserved3 */
.word default_handler   /* Reserved4 */
.word default_handler   /* SVCall */
.word default_handler   /* Debug Monitor */
.word default_handler   /* Reserved5 */
.word default_handler   /* PendSV */
.word systick_handler   /* SysTick */
.word default_handler   /* WWDG */
.word default_handler   /* PVD */
.word default_handler   /* TAMPER */
.word default_handler   /* RTC */
.word default_handler   /* FLASH */
.word default_handler   /* RCC */
.word default_handler   /* EXTI0 */
.word default_handler   /* EXTI1 */
.word default_handler   /* EXTI2 */
.word default_handler   /* EXTI3 */
.word default_handler   /* EXTI4 */
.word default_handler   /* DMA1_Channel1 */
.word default_handler   /* DMA1_Channel2 */
.word default_handler   /* DMA1_Channel3 */
.word default_handler   /* DMA1_Channel4 */
.word default_handler   /* DMA1_Channel5 */
.word default_handler   /* DMA1_Channel6 */
.word default_handler   /* DMA1_Channel7 */
.word default_handler   /* ADC1_2 */
.word default_handler   /* USB_HP_CAN_TX */
.word default_handler   /* USB_LP_CAN_RX0 */
.word default_handler   /* CAN_RX1 */
.word default_handler   /* CAN_SCE */
.word default_handler   /* EXTI9_5 */
.word default_handler   /* TIM1_BRK */
.word default_handler   /* TIM1_UP */
.word default_handler   /* TIM1_TRG_COM */
.word default_handler   /* TIM1_CC */
.word default_handler   /* TIM2 */
.word default_handler   /* TIM3 */
.word default_handler   /* TIM4 */
.word default_handler   /* I2C1_EV */
.word default_handler   /* I2C1_ER */
.word default_handler   /* I2C2_EV */
.word default_handler   /* I2C2_ER */
.word default_handler   /* SPI1 */
.word default_handler   /* SPI2 */
.word default_handler   /* USART1 */
.word default_handler   /* USART2 */
.word default_handler   /* USART3 */
.word default_handler   /* EXTI15_10 */
.word default_handler   /* RTCAlarm */
.word default_handler   /* USBWakeup */
.word default_handler   /* TIM8_BRK */
.word default_handler   /* TIM8_UP */
.word default_handler   /* TIM8_TRG_COM */
.word default_handler   /* TIM8_CC */
.word default_handler   /* ADC3 */
.word default_handler   /* FSMC */
.word default_handler   /* SDIO */
.word default_handler   /* TIM5 */
.word default_handler   /* SPI3 */
.word default_handler   /* UART4 */
.word default_handler   /* UART5 */
.word default_handler   /* TIM6 */
.word default_handler   /* TIM7 */
.word default_handler   /* DMA2_Channel1 */
.word default_handler   /* DMA2_Channel2 */
.word default_handler   /* DMA2_Channel3 */
.word default_handler   /* DMA2_Channel4_5 */
