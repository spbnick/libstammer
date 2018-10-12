/*
 * USART (Universal Synchronous/Asynchronous Receiver/Transmitter)
 */

#include <usart.h>
#include <stddef.h>

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
