/*
 * Say hello on USART1
 */
#include "init.h"
#include "rcc.h"
#include "gpio.h"
#include "usart.h"

void
reset(void)
{
    volatile struct usart *usart = USART1;
    const char *message = "Hello, world!\r\n";
    const char *p;
    unsigned int c;
    unsigned int sr;
    /* Basic init */
    init();

    /*
     * Configure pins
     */
    /* Enable clock to I/O port A */
    RCC->apb2enr |= RCC_APB2ENR_IOPAEN_MASK;

    /* Configure TX pin (PA9) */
    GPIO_A->crh =
        (GPIO_A->crh & (~GPIO_CRH_MODE9_MASK) & (~GPIO_CRH_CNF9_MASK)) |
        (GPIO_MODE_OUTPUT_50MHZ << GPIO_CRH_MODE9_LSB) |
        (GPIO_CNF_OUTPUT_AF_PUSH_PULL << GPIO_CRH_CNF9_LSB);

    /* Configure RX pin (PA10) */
    GPIO_A->crh =
        (GPIO_A->crh & (~GPIO_CRH_MODE10_MASK) & (~GPIO_CRH_CNF10_MASK)) |
        (GPIO_MODE_INPUT << GPIO_CRH_MODE10_LSB) |
        (GPIO_CNF_INPUT_FLOATING << GPIO_CRH_CNF10_LSB);

    /*
     * Configure USART
     */
    /* Enable clock to USART2 */
    RCC->apb2enr |= RCC_APB2ENR_USART1EN_MASK;

    /* Enable USART, leave the default mode of 8N1 */
    usart->cr1 |= USART_CR1_UE_MASK;

    /* Set baud rate of 115200 based on PCLK1 at 36MHz */
    usart->brr = usart_brr_val(72 * 1000 * 1000, 115200);

    /* Enable receiver and transmitter */
    usart->cr1 |= USART_CR1_RE_MASK | USART_CR1_TE_MASK;

    /*
     * Transfer
     */
    while (1) {
        /* Wait for Enter to be pressed */
        do {
            /* Wait for receive register to fill */
            while (!(usart->sr & USART_SR_RXNE_MASK));
            /* Read the byte */
            c = usart->dr;
        } while (c != '\r');

        /* Output the message */
        for (p = message; *p != 0; p++) {
            /* Wait for transmit register to empty */
            while (!(usart->sr & USART_SR_TXE_MASK));
            /* Write the byte */
            usart->dr = *p;
        }
        /* Wait for transfer to complete, if any */
        if (p > message)
            while (!(usart->sr & USART_SR_TC_MASK));
    }
}
