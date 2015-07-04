/*
 * Say hello on USART2
 */
#include "init.h"
#include "rcc.h"
#include "usart.h"

#define STOP \
    do {                \
        asm ("wfi");    \
    } while (1)

void
reset(void)
{
    volatile struct usart *usart = USART2;
    const char *message = "Hello, world!\r\n";
    const char *p;
    unsigned int c;
    /* Basic init */
    init();

    /* Enable clock to USART2 */
    RCC->apb1enr |= RCC_APB1ENR_USART2EN_MASK;

    /* Set baud rate based on PCLK1 at 36MHz */
    usart->brr = usart_brr_val(36 * 1000 * 1000, 115200);

    /* Enable USART, receiver and transmitter */
    usart->cr1 |= USART_CR1_UE_MASK | USART_CR1_RE_MASK | USART_CR1_TE_MASK;

    /* Wait for Enter to be pressed */
    do {
        /* Wait for receive register to fill */
        while (!(usart->sr & USART_SR_RXNE_MASK));
        /* Read the byte */
        c = usart->dr;
    } while (0);

    /* Output the message */
    for (p = message; *p != 0; p++) {
        /* Wait for transmit register to empty */
        while (!(usart->sr & USART_SR_TXE_MASK));
        /* Write the byte */
        usart->dr = *p;
    }

    STOP;
}
