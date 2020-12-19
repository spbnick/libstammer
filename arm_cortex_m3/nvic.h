/*
 * NVIC (Nested Vectored Interrupt Controller)
 */

#ifndef _ARM_CORTEX_M3_NVIC_H
#define _ARM_CORTEX_M3_NVIC_H

#include <../arm_cortex_m3/misc.h>

/** NVIC (Nested Vectored Interrupt Controller) */
struct nvic {
    unsigned int iser[8];           /**< Interrupt set-enable registers */
    unsigned int hole1[24];
    unsigned int icer[8];           /**< Interrupt clear-enable registers */
    unsigned int hole2[24];
    unsigned int ispr[8];           /**< Interrupt set-pending registers */
    unsigned int hole3[24];
    unsigned int icpr[8];           /**< Interrupt clear-pending registers */
    unsigned int hole4[24];
    unsigned int iabr[8];           /**< Interrupt active bit registers */
    unsigned int hole5[56];
    union {
        unsigned int    ipr[60];    /**< Interrupt priority registers */
        unsigned char   iprb[240];  /**< Interrupt priority register bytes */
    };
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
    NVIC->iser[num >> 5] |= 1 << (num & 0x1f);
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
    NVIC->icer[num >> 5] |= 1 << (num & 0x1f);
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
    NVIC->ispr[num >> 5] |= 1 << (num & 0x1f);
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
    NVIC->icpr[num >> 5] |= 1 << (num & 0x1f);
}

#endif /* _ARM_CORTEX_M3_NVIC_H */
