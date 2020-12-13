/*
 * Reset-time implicit initialization
 */

#ifndef _STM32_RESET_H
#define _STM32_RESET_H

/** Reset handler */
extern void reset_handler(void) __attribute__ ((isr))
                                __attribute__ ((weak));

#endif /* _STM32_RESET_H */
