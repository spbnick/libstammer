/*
 * USART (Universal Synchronous/Asynchronous Receiver/Transmitter)
 */

#include <usart.h>
#include <stdint.h>

void
usart_init(volatile struct usart *usart,
           unsigned int fck, unsigned int baud)
{
    assert(usart != NULL);
    assert(baud != 0);

    /* Enable USART, leave the default mode of 8N1 */
    usart->cr1 |= USART_CR1_UE_MASK;

    /* Set baud rate */
    usart->brr = usart_brr_val(fck, baud);

    /* Enable receiver and transmitter */
    usart->cr1 |= USART_CR1_RE_MASK | USART_CR1_TE_MASK;

    /* TODO Explicitly initialize the rest of device parameters */
}

void
usart_transmit(volatile struct usart *usart, const void *ptr, size_t len)
{
    const uint8_t *p = ptr;
    assert(usart != NULL);
    assert(ptr != NULL || len == 0);

    for (; len > 0; p++, len--) {
        while (!(usart->sr & USART_SR_TXE_MASK));
        usart->dr = *p;
    }
}
