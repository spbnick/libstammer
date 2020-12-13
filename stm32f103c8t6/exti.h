/*
 * EXTI (External interrupt/event controller)
 */

#ifndef _STM32F103C8T6_EXTI_H
#define _STM32F103C8T6_EXTI_H

/** EXTI (External interrupt/event controller) */
struct exti {
    unsigned int imr;   /**< Interrupt mask register */
    unsigned int emr;   /**< Event mask register */
    unsigned int rtsr;  /**< Rising trigger selection register */
    unsigned int ftsr;  /**< Falling trigger selection register */
    unsigned int swier; /**< Software interrupt event register */
    unsigned int pr;    /**< Pending register */
};

/** The EXTI instance */
#define EXTI ((volatile struct exti *)0x40010400)

#endif /* _STM32F103C8T6_EXTI_H */
