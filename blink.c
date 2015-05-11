#include "rcc.h"
#include "gpio.h"

#define STOP \
    do {                \
        asm ("wfi");    \
    } while (1)

void
reset(void)
{
    struct gpio *gpio_a = (struct gpio *)0x40010800;
    struct gpio *gpio_c = (struct gpio *)0x40011000;
    struct rcc *rcc     = (struct rcc *)0x40021000;

    /*
     * Set up the clocks
     */
    /* Enable HSE clock */
    rcc->cr |= RCC_CR_HSEON_MASK;
    /* Wait for external high-speed (HSE) clock (8MHz) to be ready */
    while (!(rcc->cr & RCC_CR_HSERDY_MASK));
    /* Set PLL pre-divisor to 1, so PLL gets 8MHz from HSE */
    rcc->cfgr &= ~RCC_CFGR_PLLXTPRE_MASK;
    /* Switch PLL input to HSE */
    rcc->cfgr |= RCC_CFGR_PLLSRC_MASK;
    /* Set PLL multiplier to 9 (so output is 72MHz) */
    rcc->cfgr = (rcc->cfgr & (~RCC_CFGR_PLLMUL_MASK)) | (7 << RCC_CFGR_PLLMUL_LSB);
    /* Turn PLL on */
    rcc->cr |= RCC_CR_PLLON_MASK;
    /* Wait for PLL to lock */
    while (!(rcc->cr & RCC_CR_PLLRDY_MASK));
    /* Set APB1 prescaler divisor to 2, to get the maximum 36MHz clock */
    rcc->cfgr = (rcc->cfgr & (~RCC_CFGR_PPRE1_MASK)) | (4 << RCC_CFGR_PPRE1_LSB);
    /* Switch SYSCLK to PLL input */
    rcc->cfgr = (rcc->cfgr & (~RCC_CFGR_SW_MASK)) | (2 << RCC_CFGR_SW_LSB);
    /* Wait for SYSCLK to switch to PLL input */
    while (((rcc->cr & RCC_CFGR_SWS_MASK) >> RCC_CFGR_SWS_LSB) != 2);
    /* Enable microcontroller clock output of PLL/2 (36MHz) */
    rcc->cfgr = (rcc->cfgr & (~RCC_CFGR_MCO_MASK)) | (7 << RCC_CFGR_MCO_LSB);

    /*
     * Enable I/O ports
     */
    /* Enable APB2 clock to I/O port A */
    rcc->apb2enr |= RCC_APB2ENR_IOPAEN_MASK;
    /* Enable APB2 clock to I/O port C */
    rcc->apb2enr |= RCC_APB2ENR_IOPCEN_MASK;

    /*
     * Enable clock output
     */
    gpio_a->crh = (gpio_a->crh & (~GPIO_CRH_MODE8_MASK) & (~GPIO_CRH_CNF8_MASK)) |
                  (GPIO_MODE_OUTPUT_50MHZ << GPIO_CRH_MODE8_LSB) |
                  (GPIO_CNF_OUTPUT_AF_PUSH_PULL << GPIO_CRH_CNF8_LSB);

    /*
     * Enable LED output
     */
    /* Set PC13 to general purpose open-drain output, max speed 2MHz */
    gpio_c->crh = (gpio_c->crh & (~GPIO_CRH_MODE13_MASK) & (~GPIO_CRH_CNF13_MASK)) |
                  (GPIO_MODE_OUTPUT_2MHZ << GPIO_CRH_MODE13_LSB) |
                  (GPIO_CNF_OUTPUT_GP_OPEN_DRAIN << GPIO_CRH_CNF13_LSB);

    /*
     * Light the LED
     */
    /* Set PC13 output high, connecting the LED to ground */
    gpio_c->bsrr = GPIO_BSRR_BS13_MASK;

    STOP;
}

void
nmi(void)
{
    STOP;
}

void
hard_fault(void)
{
    STOP;
}
