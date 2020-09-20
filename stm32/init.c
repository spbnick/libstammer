/*
 * Common initialization
 */

#include <stm32/rcc.h>
#include <stm32/flash.h>
#include <stm32/init.h>

void
init(void)
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
                 (FLASH_ACR_LATENCY_VAL_2WS << FLASH_ACR_LATENCY_LSB);

    /*
     * Configure and enable the PLL
     */
    /* Set PLL pre-divisor to 1, so PLL gets 8MHz from HSE */
    RCC->cfgr &= ~RCC_CFGR_PLLXTPRE_MASK;
    /* Switch PLL input to HSE */
    RCC->cfgr |= RCC_CFGR_PLLSRC_MASK;
    /* Set PLL multiplier to 9 (so output is 72MHz) */
    RCC->cfgr = (RCC->cfgr & (~RCC_CFGR_PLLMUL_MASK)) |
                (RCC_CFGR_PLLMUL_VAL_MUL9 << RCC_CFGR_PLLMUL_LSB);
    /* Turn PLL on */
    RCC->cr |= RCC_CR_PLLON_MASK;
    /* Wait for PLL to lock */
    while (!(RCC->cr & RCC_CR_PLLRDY_MASK));

    /* Set APB1 prescaler divisor to 2, to get the maximum 36MHz clock */
    RCC->cfgr = (RCC->cfgr & (~RCC_CFGR_PPRE1_MASK)) |
                (RCC_CFGR_PPRE1_VAL_DIV2 << RCC_CFGR_PPRE1_LSB);

    /* Switch SYSCLK to PLL input */
    RCC->cfgr = (RCC->cfgr & (~RCC_CFGR_SW_MASK)) |
                (RCC_CFGR_SW_VAL_PLL << RCC_CFGR_SW_LSB);
    /* Wait for SYSCLK to switch to PLL input */
    while (((RCC->cfgr & RCC_CFGR_SWS_MASK) >> RCC_CFGR_SWS_LSB) !=
            RCC_CFGR_SW_VAL_PLL);
}
