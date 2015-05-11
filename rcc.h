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
 * APB2 peripheral clock enable register bits
 */
/* Alternate function IO clock enable */
#define RCC_APB2ENR_AFIOEN_LSB  0
#define RCC_APB2ENR_AFIOEN_MASK (1 << RCC_APB2ENR_AFIOEN_LSB)
/* IO port A clock enable */
#define RCC_APB2ENR_IOPAEN_LSB  2
#define RCC_APB2ENR_IOPAEN_MASK (1 << RCC_APB2ENR_IOPAEN_LSB)
/* IO port C clock enable */
#define RCC_APB2ENR_IOPCEN_LSB  4
#define RCC_APB2ENR_IOPCEN_MASK (1 << RCC_APB2ENR_IOPCEN_LSB)

#endif /* _RCC_H */
