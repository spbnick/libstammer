#include "rcc.h"
#include "gpio.h"
#include "init.h"
#include "stk.h"

#define STOP \
    do {                \
        asm ("wfi");    \
    } while (1)

void
default_handler(void)
{
    STOP;
}

void systick_handler(void) __attribute__ ((isr));
void
systick_handler(void)
{
    /* Toggle the LED */
    GPIO_C->odr ^= GPIO_ODR_ODR13_MASK;
}

void
reset(void)
{
    /* Basic init */
    init();

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
     * Set SysTick timer to fire the interrupt each half-second.
     * NOTE the ST PM0056 says: "When HCLK is programmed at the maximum
     * frequency, the SysTick period is 1ms."
     */
    STK->val = STK->load =
        (((STK->calib & STK_CALIB_TENMS_MASK) >> STK_CALIB_TENMS_LSB) + 1) *
        500 - 1;
    STK->ctrl |= STK_CTRL_ENABLE_MASK | STK_CTRL_TICKINT_MASK;

    STOP;
}
