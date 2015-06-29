/*
 * Embedded flash control
 */

#ifndef _FLASH_H
#define _FLASH_H

/* Embedded flash control */
struct flash {
    unsigned int acr;       /* Access control register */
    unsigned int keyr;
    unsigned int optkeyr;
    unsigned int sr;
    unsigned int cr;
    unsigned int ar;
    unsigned int reserved;
    unsigned int obr;
    unsigned int wrpr;
};

/* The embedded flash control instance */
#define FLASH ((volatile struct flash *)0x40022000)

#define FLASH_ACR_LATENCY_LSB   0
#define FLASH_ACR_LATENCY_MSB   2
#define FLASH_ACR_LATENCY_MASK  (7 << FLASH_ACR_LATENCY_LSB)

#endif /* _FLASH_H */
