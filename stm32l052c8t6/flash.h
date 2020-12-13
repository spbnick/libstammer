/*
 * Flash program memory and data EEPROM
 */

#ifndef _STM32L052C8T6_FLASH_H
#define _STM32L052C8T6_FLASH_H

/** Flash program memory and data EEPROM */
struct flash {
    unsigned int acr;       /**< Access control register */
    unsigned int peyr;      /**< Program and erase control register */
    unsigned int pdkeyr;    /**< Power-down key register */
    unsigned int pekeyr;    /**< PECR unlock key register */
    unsigned int prgkeyr;   /**< Program and erase key register */
    unsigned int optkeyr;   /**< Option bytes unlock key register */
    unsigned int sr;        /**< Status register */
    unsigned int optr;      /**< Option bytes register */
    unsigned int wrprot1;   /**< Write protection register 1 */
    unsigned int reserved[23];
    unsigned int wrprot2;   /**< Write protection register 2 */
};

/** The embedded flash control instance */
#define FLASH ((volatile struct flash *)0x40022000)

#define FLASH_ACR_LATENCY_LSB   0
#define FLASH_ACR_LATENCY_MASK  (1 << FLASH_ACR_LATENCY_LSB)
/* 0 wait states (SYSCLK R1:16MHz, R2:8MHz, R3:2MHz, R3:4MHz) */
#define FLASH_ACR_LATENCY_VAL_0WS   0x0
/* 1 wait state (SYSCLK R1:32MHz, R2:16MHz) */
#define FLASH_ACR_LATENCY_VAL_1WS   0x1

#endif /* _STM32L052C8T6_FLASH_H */
