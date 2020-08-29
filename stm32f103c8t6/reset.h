/*
 * Reset-time implicit initialization
 */

#ifndef _RESET_H
#define _RESET_H

/** Reset handler */
extern void reset_handler(void) __attribute__ ((isr))
                                __attribute__ ((weak));

#endif /* _RESET_H */
