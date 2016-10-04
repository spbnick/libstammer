/*
 * NVIC (Nested Vectored Interrupt Controller)
 */

#ifndef _NVIC_H
#define _NVIC_H

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

#endif /* _NVIC_H */
