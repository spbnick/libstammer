/*
 * Reset and clock control
 */

#ifndef _RCC_H
#define _RCC_H

/** Reset and clock control */
struct rcc {
    unsigned int cr;        /**< Clock control register */
    unsigned int icscr;     /**< Internal clock sources calibration register */
    unsigned int crrcr;     /**< Clock recovery RC register */
    unsigned int cfgr;      /**< Clock configuration register */
    unsigned int cier;      /**< Clock interrupt enable register */
    unsigned int cifr;      /**< Clock interrupt flag register */
    unsigned int cicr;      /**< Clock interrupt clear register */
    unsigned int ioprstr;   /**< GPIO reset register */
    unsigned int ahbrstr;   /**< AHB peripheral reset register */
    unsigned int apb2rstr;  /**< APB2 peripheral reset register */
    unsigned int apb1rstr;  /**< APB1 peripheral reset register */
    unsigned int iopenr;    /**< GPIO clock enable register */
    unsigned int ahbenr;    /**< AHB peripheral clock enable register */
    unsigned int apb2enr;   /**< APB2 peripheral clock enable register */
    unsigned int apb1enr;   /**< APB1 peripheral clock enable register */
    unsigned int iopsmenr;  /**< GPIO clock enable in Sleep mode register */
    unsigned int ahbsmenr;  /**< AHB peripheral clock enable in Sleep mode register */
    unsigned int apb2smenr; /**< APB2 peripheral clock enable in Sleep mode register */
    unsigned int apb1smenr; /**< APB1 peripheral clock enable in Sleep mode register */
    unsigned int ccipr;     /**< Clock configuration register */
    unsigned int csr;       /**< Control/status register */
};

/** The RCC instance */
#define RCC ((volatile struct rcc *)0x40021000)

/*
 * Clock control register bits
 */
/* PLL clock ready flag */
#define RCC_CR_PLLRDY_LSB   25
#define RCC_CR_PLLRDY_MASK (1 << RCC_CR_PLLRDY_LSB)
/* PLL enable bit */
#define RCC_CR_PLLON_LSB    24
#define RCC_CR_PLLON_MASK   (1 << RCC_CR_PLLON_LSB)
/* RTC prescaler */
#define RCC_CR_RTCPRE_LSB   20
#define RCC_CR_RTCPRE_MSB   21
#define RCC_CR_RTCPRE_MASK  (0x3 << RCC_CR_RTCPRE_LSB)
/* Clock security system on HSE enable bit */
#define RCC_CR_CSSHSEON_LSB     19
#define RCC_CR_CSSHSEON_MASK    (1 << RCC_CR_CSSHSEON_LSB)
/* HSE clock bypass bit */
#define RCC_CR_HSEBYP_LSB   18
#define RCC_CR_HSEBYP_MASK  (1 << RCC_CR_HSEBYP_LSB)
/* HSE clock ready bit */
#define RCC_CR_HSERDY_LSB   17
#define RCC_CR_HSERDY_MASK  (1 << RCC_CR_HSERDY_LSB)
/* HSE enable bit */
#define RCC_CR_HSEON_LSB    16
#define RCC_CR_HSEON_MASK   (1 << RCC_CR_HSEON_LSB)
/* MSI clock ready bit */
#define RCC_CR_MSIRDY_LSB   9
#define RCC_CR_MSIRDY_MASK  (1 << RCC_CR_MSIRDY_LSB)
/* MSI enable bit */
#define RCC_CR_MSION_LSB    8
#define RCC_CR_MSION_MASK   (1 << RCC_CR_MSION_LSB)
/* 16 MHz high-speed internal clock output enable */
#define RCC_CR_HSI16OUTEN_LSB   5
#define RCC_CR_HSI16OUTEN_MASK  (1 << RCC_CR_HSI16OUTEN_LSB)
/* HSI16 divider flag */
#define RCC_CR_HSI16DIVF_LSB    4
#define RCC_CR_HSI16DIVF_MASK   (1 << RCC_CR_HSI16DIVF_LSB)
/* HSI16 divider enable bit */
#define RCC_CR_HSI16DIVEN_LSB   3
#define RCC_CR_HSI16DIVEN_MASK  (1 << RCC_CR_HSI16DIVEN_LSB)
/* Internal high-speed clock ready flag */
#define RCC_CR_HSI16RDYF_LSB    2
#define RCC_CR_HSI16RDYF_MASK   (1 << RCC_CR_HSI16RDYF_LSB)
/* High-speed internal clock enable bit for some IP kernels */
#define RCC_CR_HSI16KERON_LSB   1
#define RCC_CR_HSI16KERON_MASK  (1 << RCC_CR_HSI16KERON_LSB)
/* 16 MHz high-speed internal clock enable */
#define RCC_CR_HSI16ON_LSB  0
#define RCC_CR_HSI16ON_MASK (1 << RCC_CR_HSI16ON_LSB)
/*
 * Clock configuration register bits
 */
/* Microcontroller clock output prescaler */
#define RCC_CFGR_MCOPRE_LSB   28
#define RCC_CFGR_MCOPRE_MSB   30
#define RCC_CFGR_MCOPRE_MASK (0x7 << RCC_CFGR_MCOPRE_LSB)
enum rcc_cfgr_mcopre_val {
    RCC_CFGR_MCOPRE_VAL_DIV1,
    RCC_CFGR_MCOPRE_VAL_DIV2,
    RCC_CFGR_MCOPRE_VAL_DIV4,
    RCC_CFGR_MCOPRE_VAL_DIV8,
    RCC_CFGR_MCOPRE_VAL_DIV16
};
/* Microcontroller clock output selection */
#define RCC_CFGR_MCOSEL_LSB     24
#define RCC_CFGR_MCOSEL_MSB     27
#define RCC_CFGR_MCOSEL_MASK    (0xf << RCC_CFGR_MCOSEL_LSB)
enum rcc_cfgr_mcosel_val {
    RCC_CFGR_MCOSEL_VAL_NONE,
    RCC_CFGR_MCOSEL_VAL_SYSCLK,
    RCC_CFGR_MCOSEL_VAL_HSI16,
    RCC_CFGR_MCOSEL_VAL_MSI,
    RCC_CFGR_MCOSEL_VAL_HSE,
    RCC_CFGR_MCOSEL_VAL_PLL,
    RCC_CFGR_MCOSEL_VAL_LSI,
    RCC_CFGR_MCOSEL_VAL_LSE,
    RCC_CFGR_MCOSEL_VAL_HSI48,
};
/* PLL output division */
#define RCC_CFGR_PLLDIV_LSB     22
#define RCC_CFGR_PLLDIV_MSB     23
#define RCC_CFGR_PLLDIV_MASK    (0x3 << RCC_CFGR_PLLDIV_LSB)
enum rcc_cfgr_plldiv_val {
    RCC_CFGR_PLLDIV_VAL_DIV2 = 1,
    RCC_CFGR_PLLDIV_VAL_DIV3,
    RCC_CFGR_PLLDIV_VAL_DIV4
};
/* PLL multiplication factor */
#define RCC_CFGR_PLLMUL_LSB     18
#define RCC_CFGR_PLLMUL_MSB     21
#define RCC_CFGR_PLLMUL_MASK    (0xf << RCC_CFGR_PLLMUL_LSB)
enum rcc_cfgr_pllmul_val {
    RCC_CFGR_PLLMUL_VAL_MUL3,
    RCC_CFGR_PLLMUL_VAL_MUL4,
    RCC_CFGR_PLLMUL_VAL_MUL6,
    RCC_CFGR_PLLMUL_VAL_MUL8,
    RCC_CFGR_PLLMUL_VAL_MUL12,
    RCC_CFGR_PLLMUL_VAL_MUL16,
    RCC_CFGR_PLLMUL_VAL_MUL24,
    RCC_CFGR_PLLMUL_VAL_MUL32,
    RCC_CFGR_PLLMUL_VAL_MUL48
};
/* PLL entry clock source */
#define RCC_CFGR_PLLSRC_LSB     16
#define RCC_CFGR_PLLSRC_MASK    (1 << RCC_CFGR_PLLSRC_LSB)
enum rcc_cfgr_pllsrc_val {
    RCC_CFGR_PLLSRC_VAL_HSI16,
    RCC_CFGR_PLLSRC_VAL_HSE
};
/* Wake-up from Stop clock selection */
#define RCC_CFGR_STOPWUCK_LSB   15
#define RCC_CFGR_STOPWUCK_MASK  (1 << RCC_CFGR_STOPWUCK_LSB)
enum rcc_cfgr_stopwuck_val {
    RCC_CFGR_STOPWUCK_VAL_MSI,
    RCC_CFGR_STOPWUCK_VAL_HSI16
};
/* APB high-speed prescaler (APB2) */
#define RCC_CFGR_PPRE2_LSB     11
#define RCC_CFGR_PPRE2_MSB     13
#define RCC_CFGR_PPRE2_MASK    (0x7 << RCC_CFGR_PPRE2_LSB)
enum rcc_cfgr_ppre2_val {
    RCC_CFGR_PPRE2_VAL_DIV1,
    RCC_CFGR_PPRE2_VAL_DIV2,
    RCC_CFGR_PPRE2_VAL_DIV4,
    RCC_CFGR_PPRE2_VAL_DIV8,
    RCC_CFGR_PPRE2_VAL_DIV16,
};
/* APB low-speed prescaler (APB1) */
#define RCC_CFGR_PPRE1_LSB     8
#define RCC_CFGR_PPRE1_MSB     10
#define RCC_CFGR_PPRE1_MASK    (0x7 << RCC_CFGR_PPRE1_LSB)
enum rcc_cfgr_ppre1_val {
    RCC_CFGR_PPRE1_VAL_DIV1,
    RCC_CFGR_PPRE1_VAL_DIV2,
    RCC_CFGR_PPRE1_VAL_DIV4,
    RCC_CFGR_PPRE1_VAL_DIV8,
    RCC_CFGR_PPRE1_VAL_DIV16,
};
/* AHB prescaler */
#define RCC_CFGR_HPRE_LSB     4
#define RCC_CFGR_HPRE_MSB     7
#define RCC_CFGR_HPRE_MASK    (0xf << RCC_CFGR_HPRE_LSB)
enum rcc_cfgr_hpre_val {
    RCC_CFGR_HPRE_VAL_DIV1,
    RCC_CFGR_HPRE_VAL_DIV2,
    RCC_CFGR_HPRE_VAL_DIV4,
    RCC_CFGR_HPRE_VAL_DIV8,
    RCC_CFGR_HPRE_VAL_DIV16,
    RCC_CFGR_HPRE_VAL_DIV64,
    RCC_CFGR_HPRE_VAL_DIV128,
    RCC_CFGR_HPRE_VAL_DIV256,
    RCC_CFGR_HPRE_VAL_DIV512
};
/* System clock switch status */
#define RCC_CFGR_SWS_LSB     2
#define RCC_CFGR_SWS_MSB     3
#define RCC_CFGR_SWS_MASK    (0x3 << RCC_CFGR_SWS_LSB)
enum rcc_cfgr_sws_val {
    RCC_CFGR_SWS_VAL_MSI,
    RCC_CFGR_SWS_VAL_HSI16,
    RCC_CFGR_SWS_VAL_HSE,
    RCC_CFGR_SWS_VAL_PLL
};
/* System clock switch */
#define RCC_CFGR_SW_LSB     0
#define RCC_CFGR_SW_MSB     1
#define RCC_CFGR_SW_MASK    (0x3 << RCC_CFGR_SW_LSB)
enum rcc_cfgr_sw_val {
    RCC_CFGR_SW_VAL_MSI,
    RCC_CFGR_SW_VAL_HSI16,
    RCC_CFGR_SW_VAL_HSE,
    RCC_CFGR_SW_VAL_PLL
};
/*
 * GPIO clock enable register bits
 */
/* I/O port H clock enable bit */
#define RCC_IOPENR_IOPHEN_LSB   7
#define RCC_IOPENR_IOPHEN_MASK  (1 << RCC_IOPENR_IOPHEN_LSB)
/* I/O port E clock enable bit */
#define RCC_IOPENR_IOPEEN_LSB   4
#define RCC_IOPENR_IOPEEN_MASK  (1 << RCC_IOPENR_IOPEEN_LSB)
/* I/O port D clock enable bit */
#define RCC_IOPENR_IOPDEN_LSB   3
#define RCC_IOPENR_IOPDEN_MASK  (1 << RCC_IOPENR_IOPDEN_LSB)
/* I/O port C clock enable bit */
#define RCC_IOPENR_IOPCEN_LSB   2
#define RCC_IOPENR_IOPCEN_MASK  (1 << RCC_IOPENR_IOPCEN_LSB)
/* I/O port B clock enable bit */
#define RCC_IOPENR_IOPBEN_LSB   1
#define RCC_IOPENR_IOPBEN_MASK  (1 << RCC_IOPENR_IOPBEN_LSB)
/* I/O port A clock enable bit */
#define RCC_IOPENR_IOPAEN_LSB   0
#define RCC_IOPENR_IOPAEN_MASK  (1 << RCC_IOPENR_IOPAEN_LSB)
/*
 * AHB peripheral clock enable register
 */
/* Crypto clock enable bit */
#define RCC_AHBENR_CRYPEN_LSB   24
#define RCC_AHBENR_CRYPEN_MASK  (1 << RCC_AHBENR_CRYPEN_LSB)
/* Random Number Generator clock enable bit */
#define RCC_AHBENR_RNGEN_LSB    20
#define RCC_AHBENR_RNGEN_MASK   (1 << RCC_AHBENR_RNGEN_LSB)
/* Touch Sensing clock enable bit */
#define RCC_AHBENR_TSCEN_LSB    16
#define RCC_AHBENR_TSCEN_MASK   (1 << RCC_AHBENR_TSCEN_LSB)
/* CRC clock enable bit */
#define RCC_AHBENR_CRCEN_LSB    12
#define RCC_AHBENR_CRCEN_MASK   (1 << RCC_AHBENR_CRCEN_LSB)
/* NVM interface clock enable bit */
#define RCC_AHBENR_MIFEN_LSB    8
#define RCC_AHBENR_MIFEN_MASK   (1 << RCC_AHBENR_MIFEN_LSB)
/* DMA clock enable bit */
#define RCC_AHBENR_DMAEN_LSB    0
#define RCC_AHBENR_DMAEN_MASK   (1 << RCC_AHBENR_DMAEN_LSB)
/*
 * APB2 peripheral clock enable register
 */
/* DBG clock enable bit */
#define RCC_APB2ENR_DBGEN_LSB   22
#define RCC_APB2ENR_DBGEN_MASK  (1 << RCC_APB2ENR_DBGEN_LSB)
/* USART1 clock enable bit */
#define RCC_APB2ENR_USART1EN_LSB    14
#define RCC_APB2ENR_USART1EN_MASK   (1 << RCC_APB2ENR_USART1EN_LSB)
/* SPI1 clock enable bit */
#define RCC_APB2ENR_SPI1EN_LSB    12
#define RCC_APB2ENR_SPI1EN_MASK   (1 << RCC_APB2ENR_SPI1EN_LSB)
/* ADC clock enable bit */
#define RCC_APB2ENR_ADCEN_LSB   9
#define RCC_APB2ENR_ADCEN_MASK  (1 << RCC_APB2ENR_ADCEN_LSB)
/* FW clock enable bit */
#define RCC_APB2ENR_FWEN_LSB    7
#define RCC_APB2ENR_FWEN_MASK   (1 << RCC_APB2ENR_FWEN_LSB)
/* TIM22 clock enable bit */
#define RCC_APB2ENR_TIM22EN_LSB     5
#define RCC_APB2ENR_TIM22EN_MASK    (1 << RCC_APB2ENR_TIM22EN_LSB)
/* TIM21 clock enable bit */
#define RCC_APB2ENR_TIM21EN_LSB     2
#define RCC_APB2ENR_TIM21EN_MASK    (1 << RCC_APB2ENR_TIM21EN_LSB)
/* System configuration controller clock enable bit */
#define RCC_APB2ENR_SYSCFGEN_LSB    0
#define RCC_APB2ENR_SYSCFGEN_MASK   (1 << RCC_APB2ENR_SYSCFGEN_LSB)
/*
 * APB1 peripheral clock enable register
 */
/* Low-power timer clock enable bit */
#define RCC_APB1ENR_LPTIM1EN_LSB    31
#define RCC_APB1ENR_LPTIM1EN_MASK   (1 << RCC_APB1ENR_LPTIM1EN_LSB)
/* I2C3 clock enable bit */
#define RCC_APB1ENR_I2C3EN_LSB  30
#define RCC_APB1ENR_I2C3EN_MASK (1 << RCC_APB1ENR_I2C3EN_LSB)
/* DAC interface clock enable bit */
#define RCC_APB1ENR_DACEN_LSB   29
#define RCC_APB1ENR_DACEN_MASK  (1 << RCC_APB1ENR_DACEN_LSB)
/* PWR interface clock enable bit */
#define RCC_APB1ENR_PWREN_LSB   28
#define RCC_APB1ENR_PWREN_MASK  (1 << RCC_APB1ENR_PWREN_LSB)
/* Clock recovery system clock enable bit */
#define RCC_APB1ENR_CRSEN_LSB   27
#define RCC_APB1ENR_CRSEN_MASK  (1 << RCC_APB1ENR_CRSEN_LSB)
/* USB clock enable bit */
#define RCC_APB1ENR_USBEN_LSB   23
#define RCC_APB1ENR_USBEN_MASK  (1 << RCC_APB1ENR_USBEN_LSB)
/* I2C2 clock enable bit */
#define RCC_APB1ENR_I2C2EN_LSB  22
#define RCC_APB1ENR_I2C2EN_MASK (1 << RCC_APB1ENR_I2C2EN_LSB)
/* I2C1 clock enable bit */
#define RCC_APB1ENR_I2C1EN_LSB  21
#define RCC_APB1ENR_I2C1EN_MASK (1 << RCC_APB1ENR_I2C1EN_LSB)
/* USART5 clock enable bit */
#define RCC_APB1ENR_USART5EN_LSB    20
#define RCC_APB1ENR_USART5EN_MASK   (1 << RCC_APB1ENR_USART5EN_LSB)
/* USART4 clock enable bit */
#define RCC_APB1ENR_USART4EN_LSB    19
#define RCC_APB1ENR_USART4EN_MASK   (1 << RCC_APB1ENR_USART4EN_LSB)
/* LPUART1 clock enable bit */
#define RCC_APB1ENR_LPUART1EN_LSB   18
#define RCC_APB1ENR_LPUART1EN_MASK  (1 << RCC_APB1ENR_LPUART1EN_LSB)
/* USART2 clock enable bit */
#define RCC_APB1ENR_USART2EN_LSB    17
#define RCC_APB1ENR_USART2EN_MASK   (1 << RCC_APB1ENR_USART2EN_LSB)
/* SPI2 clock enable bit */
#define RCC_APB1ENR_SPI2EN_LSB  14
#define RCC_APB1ENR_SPI2EN_MASK (1 << RCC_APB1ENR_SPI2EN_LSB)
/* Window watchdog clock enable bit */
#define RCC_APB1ENR_WWDGEN_LSB  11
#define RCC_APB1ENR_WWDGEN_MASK (1 << RCC_APB1ENR_WWDGEN_LSB)
/* Timer 7 clock enable bit */
#define RCC_APB1ENR_TIM7EN_LSB  5
#define RCC_APB1ENR_TIM7EN_MASK (1 << RCC_APB1ENR_TIM7EN_LSB)
/* Timer 6 clock enable bit */
#define RCC_APB1ENR_TIM6EN_LSB  4
#define RCC_APB1ENR_TIM6EN_MASK (1 << RCC_APB1ENR_TIM6EN_LSB)
/* Timer 3 clock enable bit */
#define RCC_APB1ENR_TIM3EN_LSB  1
#define RCC_APB1ENR_TIM3EN_MASK (1 << RCC_APB1ENR_TIM3EN_LSB)
/* Timer 2 clock enable bit */
#define RCC_APB1ENR_TIM2EN_LSB  1
#define RCC_APB1ENR_TIM2EN_MASK (1 << RCC_APB1ENR_TIM2EN_LSB)
#endif /* _RCC_H */
