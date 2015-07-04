/*
 * Reset and clock control
 */

#ifndef _RCC_H
#define _RCC_H

/* Reset and clock control */
struct rcc {
    unsigned int cr;        /* Clock control register */
    unsigned int cfgr;      /* Clock configuration register */
    unsigned int cir;       /* Clock interrupt register */
    unsigned int apb2rstr;  /* APB2 peripheral reset register */
    unsigned int apb1rstr;  /* APB1 peripheral reset register */
    unsigned int ahbenr;    /* AHB peripheral clock enable register */
    unsigned int apb2enr;   /* APB2 peripheral clock enable register */
    unsigned int apb1enr;   /* APB1 peripheral clock enable register */
    unsigned int bdcr;      /* Backup domain control register */
    unsigned int csr;       /* Control/status register */
};

/* The RCC instance */
#define RCC ((volatile struct rcc *)0x40021000)

/*
 * Clock control register bits
 */
/* HSE clock enable */
#define RCC_CR_HSEON_LSB    16
#define RCC_CR_HSEON_MASK   (1 << RCC_CR_HSEON_LSB)
/* External high-speed clock ready flag */
#define RCC_CR_HSERDY_LSB   17
#define RCC_CR_HSERDY_MASK  (1 << RCC_CR_HSERDY_LSB)
/* PLL enable */
#define RCC_CR_PLLON_LSB    24
#define RCC_CR_PLLON_MASK   (1 << RCC_CR_PLLON_LSB)
/* PLL ready */
#define RCC_CR_PLLRDY_LSB   25
#define RCC_CR_PLLRDY_MASK  (1 << RCC_CR_PLLRDY_LSB)

/*
 * Clock configuration register bits
 */
/* System clock switch */
#define RCC_CFGR_SW_LSB         0
#define RCC_CFGR_SW_MSB         1
#define RCC_CFGR_SW_MASK        (0x3 << RCC_CFGR_SW_LSB)
/* System clock switch status */
#define RCC_CFGR_SWS_LSB        2
#define RCC_CFGR_SWS_MSB        3
#define RCC_CFGR_SWS_MASK       (0x3 << RCC_CFGR_SWS_LSB)
/* AHB prescaler */
#define RCC_CFGR_HPRE_LSB       4
#define RCC_CFGR_HPRE_MSB       7
#define RCC_CFGR_HPRE_MASK      (0xf << RCC_CFGR_HPRE_LSB)
/* APB low-speed prescaler (APB1) */
#define RCC_CFGR_PPRE1_LSB      8
#define RCC_CFGR_PPRE1_MSB      10
#define RCC_CFGR_PPRE1_MASK     (0x7 << RCC_CFGR_PPRE1_LSB)
/* APB high-speed prescaler (APB2) */
#define RCC_CFGR_PPRE2_LSB      11
#define RCC_CFGR_PPRE2_MSB      13
#define RCC_CFGR_PPRE2_MASK     (0x7 << RCC_CFGR_PPRE2_LSB)
/* PLL entry clock source */
#define RCC_CFGR_PLLSRC_LSB     16
#define RCC_CFGR_PLLSRC_MASK    (1 << RCC_CFGR_PLLSRC_LSB)
/* HSE divider for PLL entry */
#define RCC_CFGR_PLLXTPRE_LSB   17
#define RCC_CFGR_PLLXTPRE_MASK  (1 << RCC_CFGR_PLLXTPRE_LSB)
/* PLL multiplication factor */
#define RCC_CFGR_PLLMUL_LSB     18
#define RCC_CFGR_PLLMUL_MSB     21
#define RCC_CFGR_PLLMUL_MASK    (0xf << RCC_CFGR_PLLMUL_LSB)
/* Microcontroller clock output */
#define RCC_CFGR_MCO_LSB        24
#define RCC_CFGR_MCO_MSB        26
#define RCC_CFGR_MCO_MASK       (0x7 << RCC_CFGR_MCO_LSB)

/*
 * APB2 peripheral reset register bits
 */
/* Alternate function IO reset */
#define RCC_APB2RSTR_AFIORST_LSB    0
#define RCC_APB2RSTR_AFIORST_MASK   (1 << RCC_APB2RSTR_AFIORST_LSB)
/* IO port A reset */
#define RCC_APB2RSTR_IOPARST_LSB    2
#define RCC_APB2RSTR_IOPARST_MASK   (1 << RCC_APB2RSTR_IOPARST_LSB)
/* IO port B reset */
#define RCC_APB2RSTR_IOPBRST_LSB    3
#define RCC_APB2RSTR_IOPBRST_MASK   (1 << RCC_APB2RSTR_IOPBRST_LSB)
/* IO port C reset */
#define RCC_APB2RSTR_IOPCRST_LSB    4
#define RCC_APB2RSTR_IOPCRST_MASK   (1 << RCC_APB2RSTR_IOPCRST_LSB)
/* IO port D reset */
#define RCC_APB2RSTR_IOPDRST_LSB    5
#define RCC_APB2RSTR_IOPDRST_MASK   (1 << RCC_APB2RSTR_IOPDRST_LSB)
/* IO port E reset */
#define RCC_APB2RSTR_IOPERST_LSB    6
#define RCC_APB2RSTR_IOPERST_MASK   (1 << RCC_APB2RSTR_IOPERST_LSB)
/* IO port F reset */
#define RCC_APB2RSTR_IOPFRST_LSB    7
#define RCC_APB2RSTR_IOPFRST_MASK   (1 << RCC_APB2RSTR_IOPFRST_LSB)
/* IO port G reset */
#define RCC_APB2RSTR_IOPGRST_LSB    8
#define RCC_APB2RSTR_IOPGRST_MASK   (1 << RCC_APB2RSTR_IOPGRST_LSB)
/* ADC1 interface reset */
#define RCC_APB2RSTR_ADC1RST_LSB    9
#define RCC_APB2RSTR_ADC1RST_MASK   (1 << RCC_APB2RSTR_ADC1RST_LSB)
/* ADC2 interface reset */
#define RCC_APB2RSTR_ADC2RST_LSB    10
#define RCC_APB2RSTR_ADC2RST_MASK   (1 << RCC_APB2RSTR_ADC2RST_LSB)
/* TIM1 timer reset */
#define RCC_APB2RSTR_TIM1RST_LSB    11
#define RCC_APB2RSTR_TIM1RST_MASK   (1 << RCC_APB2RSTR_TIM1RST_LSB)
/* SPI1 reset */
#define RCC_APB2RSTR_SPI1RST_LSB    12
#define RCC_APB2RSTR_SPI1RST_MASK   (1 << RCC_APB2RSTR_SPI1RST_LSB)
/* TIM8 timer reset */
#define RCC_APB2RSTR_TIM8RST_LSB    13
#define RCC_APB2RSTR_TIM8RST_MASK   (1 << RCC_APB2RSTR_TIM8RST_LSB)
/* USART1 reset */
#define RCC_APB2RSTR_USART1RST_LSB  14
#define RCC_APB2RSTR_USART1RST_MASK (1 << RCC_APB2RSTR_USART1RST_LSB)
/* ADC3 interface reset */
#define RCC_APB2RSTR_ADC3RST_LSB    15
#define RCC_APB2RSTR_ADC3RST_MASK   (1 << RCC_APB2RSTR_ADC3RST_LSB)
/* TIM9 timer reset */
#define RCC_APB2RSTR_TIM9RST_LSB    19
#define RCC_APB2RSTR_TIM9RST_MASK   (1 << RCC_APB2RSTR_TIM9RST_LSB)
/* TIM10 timer reset */
#define RCC_APB2RSTR_TIM10RST_LSB   20
#define RCC_APB2RSTR_TIM10RST_MASK  (1 << RCC_APB2RSTR_TIM10RST_LSB)
/* TIM11 timer reset */
#define RCC_APB2RSTR_TIM11RST_LSB   21
#define RCC_APB2RSTR_TIM11RST_MASK  (1 << RCC_APB2RSTR_TIM11RST_LSB)

/*
 * APB1 peripheral reset register bits
 */
/* TIM2 timer reset */
#define RCC_APB1RSTR_TIM2RST_LSB    0
#define RCC_APB1RSTR_TIM2RST_MASK   (1 << RCC_APB1RSTR_TIM2RST_LSB)
/* TIM3 timer reset */
#define RCC_APB1RSTR_TIM3RST_LSB    1
#define RCC_APB1RSTR_TIM3RST_MASK   (1 << RCC_APB1RSTR_TIM3RST_LSB)
/* TIM4 timer reset */
#define RCC_APB1RSTR_TIM4RST_LSB    2
#define RCC_APB1RSTR_TIM4RST_MASK   (1 << RCC_APB1RSTR_TIM4RST_LSB)
/* TIM5 timer reset */
#define RCC_APB1RSTR_TIM5RST_LSB    3
#define RCC_APB1RSTR_TIM5RST_MASK   (1 << RCC_APB1RSTR_TIM5RST_LSB)
/* TIM6 timer reset */
#define RCC_APB1RSTR_TIM6RST_LSB    4
#define RCC_APB1RSTR_TIM6RST_MASK   (1 << RCC_APB1RSTR_TIM6RST_LSB)
/* TIM7 timer reset */
#define RCC_APB1RSTR_TIM7RST_LSB    5
#define RCC_APB1RSTR_TIM7RST_MASK   (1 << RCC_APB1RSTR_TIM7RST_LSB)
/* TIM12 timer reset */
#define RCC_APB1RSTR_TIM12RST_LSB   6
#define RCC_APB1RSTR_TIM12RST_MASK  (1 << RCC_APB1RSTR_TIM12RST_LSB)
/* TIM13 timer reset */
#define RCC_APB1RSTR_TIM13RST_LSB   7
#define RCC_APB1RSTR_TIM13RST_MASK  (1 << RCC_APB1RSTR_TIM13RST_LSB)
/* TIM14 timer reset */
#define RCC_APB1RSTR_TIM14RST_LSB   8
#define RCC_APB1RSTR_TIM14RST_MASK  (1 << RCC_APB1RSTR_TIM14RST_LSB)
/* Window watchdog reset */
#define RCC_APB1RSTR_WWDGRST_LSB    11
#define RCC_APB1RSTR_WWDGRST_MASK   (1 << RCC_APB1RSTR_WWDGRST_LSB)
/* SPI2 reset */
#define RCC_APB1RSTR_SPI2RST_LSB    14
#define RCC_APB1RSTR_SPI2RST_MASK   (1 << RCC_APB1RSTR_SPI2RST_LSB)
/* SPI3 reset */
#define RCC_APB1RSTR_SPI3RST_LSB    15
#define RCC_APB1RSTR_SPI3RST_MASK   (1 << RCC_APB1RSTR_SPI3RST_LSB)
/* USART2 reset */
#define RCC_APB1RSTR_USART2RST_LSB  17
#define RCC_APB1RSTR_USART2RST_MASK (1 << RCC_APB1RSTR_USART2RST_LSB)
/* USART3 reset */
#define RCC_APB1RSTR_USART3RST_LSB  18
#define RCC_APB1RSTR_USART3RST_MASK (1 << RCC_APB1RSTR_USART3RST_LSB)
/* USART4 reset */
#define RCC_APB1RSTR_USART4RST_LSB  19
#define RCC_APB1RSTR_USART4RST_MASK (1 << RCC_APB1RSTR_USART4RST_LSB)
/* USART5 reset */
#define RCC_APB1RSTR_USART5RST_LSB  20
#define RCC_APB1RSTR_USART5RST_MASK (1 << RCC_APB1RSTR_USART5RST_LSB)
/* I2C1 reset */
#define RCC_APB1RSTR_I2C1RST_LSB    21
#define RCC_APB1RSTR_I2C1RST_MASK   (1 << RCC_APB1RSTR_I2C1RST_LSB)
/* I2C2 reset */
#define RCC_APB1RSTR_I2C2RST_LSB    22
#define RCC_APB1RSTR_I2C2RST_MASK   (1 << RCC_APB1RSTR_I2C2RST_LSB)
/* USB reset */
#define RCC_APB1RSTR_USBRST_LSB     23
#define RCC_APB1RSTR_USBRST_MASK    (1 << RCC_APB1RSTR_USBRST_LSB)
/* CAN reset */
#define RCC_APB1RSTR_CANRST_LSB     25
#define RCC_APB1RSTR_CANRST_MASK    (1 << RCC_APB1RSTR_CANRST_LSB)
/* Backup interface reset */
#define RCC_APB1RSTR_BKPRST_LSB     27
#define RCC_APB1RSTR_BKPRST_MASK    (1 << RCC_APB1RSTR_BKPRST_LSB)
/* Power interface reset */
#define RCC_APB1RSTR_PWRRST_LSB     28
#define RCC_APB1RSTR_PWRRST_MASK    (1 << RCC_APB1RSTR_PWRRST_LSB)
/* DAC interface reset */
#define RCC_APB1RSTR_DACRST_LSB     29
#define RCC_APB1RSTR_DACRST_MASK    (1 << RCC_APB1RSTR_DACRST_LSB)

/*
 * APB2 peripheral clock enable register bits
 */
/* Alternate function IO clock enable */
#define RCC_APB2ENR_AFIOEN_LSB      0
#define RCC_APB2ENR_AFIOEN_MASK     (1 << RCC_APB2ENR_AFIOEN_LSB)
/* IO port A clock enable */
#define RCC_APB2ENR_IOPAEN_LSB      2
#define RCC_APB2ENR_IOPAEN_MASK     (1 << RCC_APB2ENR_IOPAEN_LSB)
/* IO port B clock enable */
#define RCC_APB2ENR_IOPBEN_LSB      3
#define RCC_APB2ENR_IOPBEN_MASK     (1 << RCC_APB2ENR_IOPBEN_LSB)
/* IO port C clock enable */
#define RCC_APB2ENR_IOPCEN_LSB      4
#define RCC_APB2ENR_IOPCEN_MASK     (1 << RCC_APB2ENR_IOPCEN_LSB)
/* IO port D clock enable */
#define RCC_APB2ENR_IOPDEN_LSB      5
#define RCC_APB2ENR_IOPDEN_MASK     (1 << RCC_APB2ENR_IOPDEN_LSB)
/* IO port E clock enable */
#define RCC_APB2ENR_IOPEEN_LSB      6
#define RCC_APB2ENR_IOPEEN_MASK     (1 << RCC_APB2ENR_IOPEEN_LSB)
/* IO port F clock enable */
#define RCC_APB2ENR_IOPFEN_LSB      7
#define RCC_APB2ENR_IOPFEN_MASK     (1 << RCC_APB2ENR_IOPFEN_LSB)
/* IO port G clock enable */
#define RCC_APB2ENR_IOPGEN_LSB      8
#define RCC_APB2ENR_IOPGEN_MASK     (1 << RCC_APB2ENR_IOPGEN_LSB)
/* ADC1 interface clock enable */
#define RCC_APB2ENR_ADC1EN_LSB      9
#define RCC_APB2ENR_ADC1EN_MASK     (1 << RCC_APB2ENR_ADC1EN_LSB)
/* ADC2 interface clock enable */
#define RCC_APB2ENR_ADC2EN_LSB      10
#define RCC_APB2ENR_ADC2EN_MASK     (1 << RCC_APB2ENR_ADC2EN_LSB)
/* TIM1 timer clock enable */
#define RCC_APB2ENR_TIM1EN_LSB      11
#define RCC_APB2ENR_TIM1EN_MASK     (1 << RCC_APB2ENR_TIM1EN_LSB)
/* SPI1 clock enable */
#define RCC_APB2ENR_SPI1EN_LSB      12
#define RCC_APB2ENR_SPI1EN_MASK     (1 << RCC_APB2ENR_SPI1EN_LSB)
/* TIM8 timer clock enable */
#define RCC_APB2ENR_TIM8EN_LSB      13
#define RCC_APB2ENR_TIM8EN_MASK     (1 << RCC_APB2ENR_TIM8EN_LSB)
/* USART1 clock enable */
#define RCC_APB2ENR_USART1EN_LSB    14
#define RCC_APB2ENR_USART1EN_MASK   (1 << RCC_APB2ENR_USART1EN_LSB)
/* ADC3 interface clock enable */
#define RCC_APB2ENR_ADC3EN_LSB      15
#define RCC_APB2ENR_ADC3EN_MASK     (1 << RCC_APB2ENR_ADC3EN_LSB)
/* TIM9 timer clock enable */
#define RCC_APB2ENR_TIM9EN_LSB      19
#define RCC_APB2ENR_TIM9EN_MASK     (1 << RCC_APB2ENR_TIM9EN_LSB)
/* TIM10 timer clock enable */
#define RCC_APB2ENR_TIM10EN_LSB     20
#define RCC_APB2ENR_TIM10EN_MASK    (1 << RCC_APB2ENR_TIM10EN_LSB)
/* TIM11 timer clock enable */
#define RCC_APB2ENR_TIM11EN_LSB     21
#define RCC_APB2ENR_TIM11EN_MASK    (1 << RCC_APB2ENR_TIM11EN_LSB)

/*
 * APB1 peripheral clock enable register bits
 */
/* TIM2 timer clock enable */
#define RCC_APB1ENR_TIM2EN_LSB      0
#define RCC_APB1ENR_TIM2EN_MASK     (1 << RCC_APB1ENR_TIM2EN_LSB)
/* TIM3 timer clock enable */
#define RCC_APB1ENR_TIM3EN_LSB      1
#define RCC_APB1ENR_TIM3EN_MASK     (1 << RCC_APB1ENR_TIM3EN_LSB)
/* TIM4 timer clock enable */
#define RCC_APB1ENR_TIM4EN_LSB      2
#define RCC_APB1ENR_TIM4EN_MASK     (1 << RCC_APB1ENR_TIM4EN_LSB)
/* TIM5 timer clock enable */
#define RCC_APB1ENR_TIM5EN_LSB      3
#define RCC_APB1ENR_TIM5EN_MASK     (1 << RCC_APB1ENR_TIM5EN_LSB)
/* TIM6 timer clock enable */
#define RCC_APB1ENR_TIM6EN_LSB      4
#define RCC_APB1ENR_TIM6EN_MASK     (1 << RCC_APB1ENR_TIM6EN_LSB)
/* TIM7 timer clock enable */
#define RCC_APB1ENR_TIM7EN_LSB      5
#define RCC_APB1ENR_TIM7EN_MASK     (1 << RCC_APB1ENR_TIM7EN_LSB)
/* TIM12 timer clock enable */
#define RCC_APB1ENR_TIM12EN_LSB     6
#define RCC_APB1ENR_TIM12EN_MASK    (1 << RCC_APB1ENR_TIM12EN_LSB)
/* TIM13 timer clock enable */
#define RCC_APB1ENR_TIM13EN_LSB     7
#define RCC_APB1ENR_TIM13EN_MASK    (1 << RCC_APB1ENR_TIM13EN_LSB)
/* TIM14 timer clock enable */
#define RCC_APB1ENR_TIM14EN_LSB     8
#define RCC_APB1ENR_TIM14EN_MASK    (1 << RCC_APB1ENR_TIM14EN_LSB)
/* Window watchdog clock enable */
#define RCC_APB1ENR_WWDGEN_LSB      11
#define RCC_APB1ENR_WWDGEN_MASK     (1 << RCC_APB1ENR_WWDGEN_LSB)
/* SPI2 clock enable */
#define RCC_APB1ENR_SPI2EN_LSB      14
#define RCC_APB1ENR_SPI2EN_MASK     (1 << RCC_APB1ENR_SPI2EN_LSB)
/* SPI3 clock enable */
#define RCC_APB1ENR_SPI3EN_LSB      15
#define RCC_APB1ENR_SPI3EN_MASK     (1 << RCC_APB1ENR_SPI3EN_LSB)
/* USART2 clock enable */
#define RCC_APB1ENR_USART2EN_LSB    17
#define RCC_APB1ENR_USART2EN_MASK   (1 << RCC_APB1ENR_USART2EN_LSB)
/* USART3 clock enable */
#define RCC_APB1ENR_USART3EN_LSB    18
#define RCC_APB1ENR_USART3EN_MASK   (1 << RCC_APB1ENR_USART3EN_LSB)
/* USART4 clock enable */
#define RCC_APB1ENR_USART4EN_LSB    19
#define RCC_APB1ENR_USART4EN_MASK   (1 << RCC_APB1ENR_USART4EN_LSB)
/* USART5 clock enable */
#define RCC_APB1ENR_USART5EN_LSB    20
#define RCC_APB1ENR_USART5EN_MASK   (1 << RCC_APB1ENR_USART5EN_LSB)
/* I2C1 clock enable */
#define RCC_APB1ENR_I2C1EN_LSB      21
#define RCC_APB1ENR_I2C1EN_MASK     (1 << RCC_APB1ENR_I2C1EN_LSB)
/* I2C2 clock enable */
#define RCC_APB1ENR_I2C2EN_LSB      22
#define RCC_APB1ENR_I2C2EN_MASK     (1 << RCC_APB1ENR_I2C2EN_LSB)
/* USB clock enable */
#define RCC_APB1ENR_USBEN_LSB       23
#define RCC_APB1ENR_USBEN_MASK      (1 << RCC_APB1ENR_USBEN_LSB)
/* CAN clock enable */
#define RCC_APB1ENR_CANEN_LSB       25
#define RCC_APB1ENR_CANEN_MASK      (1 << RCC_APB1ENR_CANEN_LSB)
/* Backup interface clock enable */
#define RCC_APB1ENR_BKPEN_LSB       27
#define RCC_APB1ENR_BKPEN_MASK      (1 << RCC_APB1ENR_BKPEN_LSB)
/* Power interface clock enable */
#define RCC_APB1ENR_PWREN_LSB       28
#define RCC_APB1ENR_PWREN_MASK      (1 << RCC_APB1ENR_PWREN_LSB)
/* DAC interface clock enable */
#define RCC_APB1ENR_DACEN_LSB       29
#define RCC_APB1ENR_DACEN_MASK      (1 << RCC_APB1ENR_DACEN_LSB)

#endif /* _RCC_H */
