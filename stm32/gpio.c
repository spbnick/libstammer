/*
 * GPIO
 */

#include <stm32/gpio.h>

void
gpio_pin_conf(volatile struct gpio *gpio,
              unsigned int pin,
              enum gpio_mode mode,
              unsigned int cnf)
{
    /* Configuration register */
    volatile unsigned int *cr;
    unsigned int shift;
    unsigned int mask;
    unsigned int bits;

    if (pin < GPIO_PIN_IDX_HIGH) {
        cr = &gpio->crl;
        shift = pin;
    } else {
        cr = &gpio->crh;
        shift = pin - GPIO_PIN_IDX_HIGH;
    }

    shift *= (GPIO_CRL_CNF0_MSB - GPIO_CRL_MODE0_LSB + 1);
    mask = ~((GPIO_CRL_MODE0_MASK | GPIO_CRL_CNF0_MASK) << shift);
    bits = ((cnf << GPIO_CRL_CNF0_LSB) |
            (mode << GPIO_CRL_MODE0_LSB)) << shift;
    *cr = (*cr & mask) | bits;
}
