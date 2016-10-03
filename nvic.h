/*
 * NVIC (Nested Vectored Interrupt Controller)
 */

#ifndef _NVIC_H
#define _NVIC_H

/** NVIC (Nested Vectored Interrupt Controller) */
struct nvic {
    unsigned int iser[16];          /**< Interrupt set-enable registers */
    unsigned int hole1[16];
    unsigned int icer[16];          /**< Interrupt clear-enable registers */
    unsigned int hole2[16];
    unsigned int ispr[16];          /**< Interrupt set-pending registers */
    unsigned int hole3[16];
    unsigned int icpr[16];          /**< Interrupt clear-pending registers */
    unsigned int hole4[16];
    unsigned int iabr[16];          /**< Interrupt active bit registers */
    unsigned int reserved1[48];
    union {
        unsigned int    ipr[124];   /**< Interrupt priority registers */
        unsigned char   iprb[496];  /**< Interrupt priority register bytes */
    };
    unsigned int reserved2[452];
};

/** The NVIC instance */
#define NVIC ((volatile struct nvic *)0xe000e100)

#endif /* _NVIC_H */
