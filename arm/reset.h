/*
 * Reset-time implicit initialization
 */

#ifndef _ARM_RESET_H
#define _ARM_RESET_H

/** Reset handler */
extern void reset_handler(void) __attribute__ ((isr))
                                __attribute__ ((weak));

#endif /* _ARM_RESET_H */
