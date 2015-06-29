#include "rcc.h"
#include "gpio.h"
#include "flash.h"

#define STOP \
    do {                \
        asm ("wfi");    \
    } while (1)

void
default_handler(void)
{
    STOP;
}

void
reset(void)
{
    /*
     * Enable the HSE
     */
    /* Enable HSE clock */
    RCC->cr |= RCC_CR_HSEON_MASK;
    /* Wait for external high-speed (HSE) clock (8MHz) to be ready */
    while (!(RCC->cr & RCC_CR_HSERDY_MASK));

    /*
     * Set flash latency to 2 wait states as required for
     * 48MHz < SYSCLK <= 72MHz. Otherwise the CPU wouldn't be able to read
     * the program after switching to 72MHz SYSCLK below.
     */
    FLASH->acr = (FLASH->acr & (~FLASH_ACR_LATENCY_MASK)) |
                 (2 << FLASH_ACR_LATENCY_LSB);

    /*
     * Configure and enable the PLL
     */
    /* Set PLL pre-divisor to 1, so PLL gets 8MHz from HSE */
    RCC->cfgr &= ~RCC_CFGR_PLLXTPRE_MASK;
    /* Switch PLL input to HSE */
    RCC->cfgr |= RCC_CFGR_PLLSRC_MASK;
    /* Set PLL multiplier to 9 (so output is 72MHz) */
    RCC->cfgr = (RCC->cfgr & (~RCC_CFGR_PLLMUL_MASK)) | (7 << RCC_CFGR_PLLMUL_LSB);
    /* Turn PLL on */
    RCC->cr |= RCC_CR_PLLON_MASK;
    /* Wait for PLL to lock */
    while (!(RCC->cr & RCC_CR_PLLRDY_MASK));

    /* Set APB1 prescaler divisor to 2, to get the maximum 36MHz clock */
    RCC->cfgr = (RCC->cfgr & (~RCC_CFGR_PPRE1_MASK)) | (4 << RCC_CFGR_PPRE1_LSB);

    /* Switch SYSCLK to PLL input */
    RCC->cfgr = (RCC->cfgr & (~RCC_CFGR_SW_MASK)) | (2 << RCC_CFGR_SW_LSB);
    /* Wait for SYSCLK to switch to PLL input */
    while (((RCC->cfgr & RCC_CFGR_SWS_MASK) >> RCC_CFGR_SWS_LSB) != 2);

    /*
     * Enable I/O ports
     */
    /* Enable APB2 clock to I/O port A */
    RCC->apb2enr |= RCC_APB2ENR_IOPAEN_MASK;
    /* Enable APB2 clock to I/O port C */
    RCC->apb2enr |= RCC_APB2ENR_IOPCEN_MASK;

    /*
     * Enable clock output on PA8
     */
    GPIO_A->crh = (GPIO_A->crh & (~GPIO_CRH_MODE8_MASK) & (~GPIO_CRH_CNF8_MASK)) |
                  (GPIO_MODE_OUTPUT_50MHZ << GPIO_CRH_MODE8_LSB) |
                  (GPIO_CNF_OUTPUT_AF_PUSH_PULL << GPIO_CRH_CNF8_LSB);
    /* Enable microcontroller clock output of PLL/2 (36MHz) */
    RCC->cfgr = (RCC->cfgr & (~RCC_CFGR_MCO_MASK)) | (7 << RCC_CFGR_MCO_LSB);

    /*
     * Enable LED output
     */
    /* Set PC13 to general purpose open-drain output, max speed 2MHz */
    GPIO_C->crh = (GPIO_C->crh & (~GPIO_CRH_MODE13_MASK) & (~GPIO_CRH_CNF13_MASK)) |
                  (GPIO_MODE_OUTPUT_2MHZ << GPIO_CRH_MODE13_LSB) |
                  (GPIO_CNF_OUTPUT_GP_OPEN_DRAIN << GPIO_CRH_CNF13_LSB);

    /*
     * Light the LED
     */
    /* Set PC13 output low, connecting the LED to ground */
    GPIO_C->bsrr &= ~GPIO_BSRR_BS13_MASK;

    STOP;
}
