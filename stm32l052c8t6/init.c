/*
 * Common initialization
 */

#include <../stm32l052c8t6/rcc.h>
#include <../stm32l052c8t6/flash.h>
#include <../stm32l052c8t6/init.h>

void
init(void)
{
    /* Enable HSE */
    RCC->cr |= RCC_CR_HSEON_MASK;
    /* Wait for HSE to stabilize */
    while (!(RCC->cr & RCC_CR_HSERDY_MASK));
    /* Set PLL to multiply 8MHz HSE by eight and divide by two to get 32MHz */
    RCC->cfgr = (RCC->cfgr &
                 ~(RCC_CFGR_PLLSRC_MASK |
                   RCC_CFGR_PLLMUL_MASK |
                   RCC_CFGR_PLLDIV_MASK)) |
                RCC_CFGR_PLLSRC_VAL_HSE << RCC_CFGR_PLLSRC_LSB |
                RCC_CFGR_PLLMUL_VAL_MUL8 << RCC_CFGR_PLLMUL_LSB |
                RCC_CFGR_PLLDIV_VAL_DIV2 << RCC_CFGR_PLLDIV_LSB;
    /* Enable the PLL */
    RCC->cr |= RCC_CR_PLLON_MASK;
    /* Wait for the PLL to be ready */
    while (!(RCC->cr & RCC_CR_PLLRDY_MASK));
    /* Set flash to one wait state as required for Range 1 at 32MHz */
    FLASH->acr |= FLASH_ACR_LATENCY_MASK;
    /* Switch the system clock to PLL */
    RCC->cfgr = (RCC->cfgr & ~RCC_CFGR_SW_MASK) |
                (RCC_CFGR_SW_VAL_PLL << RCC_CFGR_SW_LSB);
    /* Wait for the system clock to switch to PLL */
    while ((RCC->cfgr & RCC_CFGR_SWS_MASK) !=
           (RCC_CFGR_SWS_VAL_PLL << RCC_CFGR_SWS_LSB));
}
