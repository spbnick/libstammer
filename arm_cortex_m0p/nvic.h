/*
 * NVIC (Nested Vectored Interrupt Controller)
 */

#ifndef _ARM_CORTEX_M0P_NVIC_H
#define _ARM_CORTEX_M0P_NVIC_H

#include <../arm/misc.h>

/** NVIC (Nested Vectored Interrupt Controller) */
struct nvic {
    unsigned int iser;          /**< Interrupt set-enable register */
    unsigned int reserved1[31];
    unsigned int icer;          /**< Interrupt clear-enable register */
    unsigned int reserved2[31];
    unsigned int ispr;          /**< Interrupt set-pending register */
    unsigned int reserved3[31];
    unsigned int icpr;          /**< Interrupt clear-pending register */
    unsigned int reserved4[95];
    unsigned int ipr[8];        /**< Interrupt priority registers */
    unsigned int reserved5[8];
};

/** The NVIC instance */
#define NVIC ((volatile struct nvic *)0xe000e100)

/** Maximum possible number of interrupts */
#define NVIC_INT_NUM_MAX    (sizeof(((struct nvic *)NULL)->iser) * 8)

/**
 * Enable an interrupt.
 *
 * @param num   Number of the interrupt to enable.
 */
static inline void
nvic_int_set_enable(unsigned int num)
{
    assert(num < NVIC_INT_NUM_MAX);
    NVIC->iser |= 1 << (num & 0x1f);
}

/**
 * Disable an interrupt.
 *
 * @param num   Number of the interrupt to disable.
 */
static inline void
nvic_int_clear_enable(unsigned int num)
{
    assert(num < NVIC_INT_NUM_MAX);
    NVIC->icer |= 1 << (num & 0x1f);
}

/**
 * Set an interrupt "pending" status.
 *
 * @param num   Number of the interrupt to set the "pending" status for.
 */
static inline void
nvic_int_set_pending(unsigned int num)
{
    assert(num < NVIC_INT_NUM_MAX);
    NVIC->ispr |= 1 << (num & 0x1f);
}

/**
 * Clear an interrupt "pending" status.
 *
 * @param num   Number of the interrupt to clear the "pending" status for.
 */
static inline void
nvic_int_clear_pending(unsigned int num)
{
    assert(num < NVIC_INT_NUM_MAX);
    NVIC->icpr |= 1 << (num & 0x1f);
}

#endif /* _ARM_CORTEX_M0P_NVIC_H */
