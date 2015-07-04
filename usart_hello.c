/*
 * Say hello on USART2
 */
#include "init.h"
#include "rcc.h"
#include "gpio.h"
#include "usart.h"

void
reset(void)
{
    volatile struct usart *usart = USART2;
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

    /* Configure TX pin (PA2) */
    GPIO_A->crl =
        (GPIO_A->crl & (~GPIO_CRL_MODE2_MASK) & (~GPIO_CRL_CNF2_MASK)) |
        (GPIO_MODE_OUTPUT_50MHZ << GPIO_CRL_MODE2_LSB) |
        (GPIO_CNF_OUTPUT_AF_PUSH_PULL << GPIO_CRL_CNF2_LSB);

    /* Configure RX pin (PA3) */
    GPIO_A->crl =
        (GPIO_A->crl & (~GPIO_CRL_MODE3_MASK) & (~GPIO_CRL_CNF3_MASK)) |
        (GPIO_MODE_INPUT << GPIO_CRL_MODE3_LSB) |
        (GPIO_CNF_INPUT_FLOATING << GPIO_CRL_CNF3_LSB);

    /*
     * Configure USART
     */
    /* Enable clock to USART2 */
    RCC->apb1enr |= RCC_APB1ENR_USART2EN_MASK;

    /* Enable USART, leave the default mode of 8N1 */
    usart->cr1 |= USART_CR1_UE_MASK;

    /* Set baud rate of 115200 based on PCLK1 at 36MHz */
    usart->brr = usart_brr_val(36 * 1000 * 1000, 115200);

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
