/*
 * I2C interface
 */

#ifndef _I2C_H
#define _I2C_H

/* I2C interface */
struct i2c {
    unsigned int cr1;       /* Control register 1 */
    unsigned int cr2;       /* Control register 2 */
    unsigned int oar1;      /* Own address 1 register */
    unsigned int oar2;      /* Own address 2 register */
    unsigned int timingr;   /* Timing register */
    unsigned int timeoutr;  /* Timeout register */
    unsigned int isr;       /* Interrupt and status register */
    unsigned int icr;       /* Interrupt clear register */
    unsigned int pecr;      /* PEC register */
    unsigned int rxdr;      /* Receive data register */
    unsigned int txdr;      /* Receive data register */
};

/** The I2C1 instance */
#define I2C1 ((volatile struct spi *)0x40005400)
/** The I2C2 instance */
#define I2C2 ((volatile struct spi *)0x40005800)
/** The I2C3 instance */
#define I2C3 ((volatile struct spi *)0x40007800)

/*
 * Control register 1 bits
 */
/* PEC enable */
#define I2C_CR1_PECEN_LSB       23
#define I2C_CR1_PECEN_MASK      (1 << I2C_CR1_PECEN_LSB)
/* SMBus alert enable */
#define I2C_CR1_ALERTEN_LSB     22
#define I2C_CR1_ALERTEN_MASK    (1 << I2C_CR1_ALERTEN_LSB)
/* SMBus Device Default address enable */
#define I2C_CR1_SMBDEN_LSB      21
#define I2C_CR1_SMBDEN_MASK     (1 << I2C_CR1_SMBDEN_LSB)
/* SMBus Host address enable */
#define I2C_CR1_SMBHEN_LSB      20
#define I2C_CR1_SMBHEN_MASK     (1 << I2C_CR1_SMBHEN_LSB)
/* General call enable */
#define I2C_CR1_GCEN_LSB        19
#define I2C_CR1_GCEN_MASK       (1 << I2C_CR1_GCEN_LSB)
/* Wakeup from Stop mode enable */
#define I2C_CR1_WUPEN_LSB       18
#define I2C_CR1_WUPEN_MASK      (1 << I2C_CR1_WUPEN_LSB)
/* Clock stretching disable */
#define I2C_CR1_NOSTRETCH_LSB   17
#define I2C_CR1_NOSTRETCH_MASK  (1 << I2C_CR1_NOSTRETCH_LSB)
/* Slave byte control */
#define I2C_CR1_SBC_LSB         16
#define I2C_CR1_SBC_MASK        (1 << I2C_CR1_SBC_LSB)
/* DMA reception request enable */
#define I2C_CR1_RXDMAEN_LSB     15
#define I2C_CR1_RXDMAEN_MASK    (1 << I2C_CR1_RXDMAEN_LSB)
/* DMA transmission request enable */
#define I2C_CR1_TXDMAEN_LSB     14
#define I2C_CR1_TXDMAEN_MASK    (1 << I2C_CR1_TXDMAEN_LSB)
/* Analog noise filter OFF */
#define I2C_CR1_ANFOFF_LSB      12
#define I2C_CR1_ANFOFF_MASK     (1 << I2C_CR1_ANFOFF_LSB)
/* Digital noise filter */
#define I2C_CR1_DNF_LSB         8
#define I2C_CR1_DNF_MSB         11
#define I2C_CR1_DNF_MASK        (0xf << I2C_CR1_DNF_LSB)
/* Error interrupts enable */
#define I2C_CR1_ERRIE_LSB       7
#define I2C_CR1_ERRIE_MASK      (1 << I2C_CR1_ERRIE_LSB)
/* Transfer Complete interrupt enable */
#define I2C_CR1_TCIE_LSB        6
#define I2C_CR1_TCIE_MASK       (1 << I2C_CR1_TCIE_LSB)
/* STOP detection interrupt enable */
#define I2C_CR1_STOPIE_LSB      5
#define I2C_CR1_STOPIE_MASK     (1 << I2C_CR1_STOPIE_LSB)
/* Not acknowledge received interrupt enable */
#define I2C_CR1_NACKIE_LSB      4
#define I2C_CR1_NACKIE_MASK     (1 << I2C_CR1_NACKIE_LSB)
/* Address match interrupt enable */
#define I2C_CR1_ADDRIE_LSB      3
#define I2C_CR1_ADDRIE_MASK     (1 << I2C_CR1_ADDRIE_LSB)
/* RX interrupt enable */
#define I2C_CR1_RXIE_LSB        2
#define I2C_CR1_RXIE_MASK       (1 << I2C_CR1_RXIE_LSB)
/* TX interrupt enable */
#define I2C_CR1_TXIE_LSB        1
#define I2C_CR1_TXIE_MASK       (1 << I2C_CR1_TXIE_LSB)
/* Peripheral enable */
#define I2C_CR1_PE_LSB          0
#define I2C_CR1_PE_MASK         (1 << I2C_CR1_PE_LSB)

/*
 * Control register 2 bits
 */
/* Packet error checking byte */
#define I2C_CR2_PECBYTE_LSB     26
#define I2C_CR2_PECBYTE_MASK    (1 << I2C_CR2_PECBYTE_LSB)
/* Automatic end mode */
#define I2C_CR2_AUTOEND_LSB     25
#define I2C_CR2_AUTOEND_MASK    (1 << I2C_CR2_AUTOEND_LSB)
/* NBYTES reload mode */
#define I2C_CR2_RELOAD_LSB      24
#define I2C_CR2_RELOAD_MASK     (1 << I2C_CR2_RELOAD_LSB)
/* Number of bytes */
#define I2C_CR2_NBYTES_LSB      16
#define I2C_CR2_NBYTES_MSB      23
#define I2C_CR2_NBYTES_MASK     (0xff << I2C_CR2_NBYTES_LSB)
/* NACK generation */
#define I2C_CR2_NACK_LSB        15
#define I2C_CR2_NACK_MASK       (1 << I2C_CR2_NACK_LSB)
/* STOP generation */
#define I2C_CR2_STOP_LSB        14
#define I2C_CR2_STOP_MASK       (1 << I2C_CR2_STOP_LSB)
/* START generation */
#define I2C_CR2_START_LSB       13
#define I2C_CR2_START_MASK      (1 << I2C_CR2_START_LSB)
/* 10-bit address header only read direction */
#define I2C_CR2_HEAD10R_LSB     12
#define I2C_CR2_HEAD10R_MASK    (1 << I2C_CR2_HEAD10R_LSB)
/* 10-bit addressing mode */
#define I2C_CR2_ADD10R_LSB      11
#define I2C_CR2_ADD10R_MASK     (1 << I2C_CR2_ADD10R_LSB)
/* Transfer direction */
#define I2C_CR2_RD_WRN_LSB      10
#define I2C_CR2_RD_WRN_MASK     (1 << I2C_CR2_RD_WRN_LSB)
/* Slave address */
#define I2C_CR2_SADD_LSB        0
#define I2C_CR2_SADD_MSB        9
#define I2C_CR2_SADD_MASK       (0x3ff << I2C_CR2_SADD_LSB)

/*
 * Own address 1 register bits
 */
/* Own Address 1 enable */
#define I2C_OAR1_OA1EN_LSB      15
#define I2C_OAR1_OA1EN_MASK     (1 << I2C_OAR1_OA1EN_LSB)
/* Own Address 1 10-bit mode */
#define I2C_OAR1_OA1MODE_LSB    10
#define I2C_OAR1_OA1MODE_MASK   (1 << I2C_OAR1_OA1MODE_LSB)
/* Interface address */
#define I2C_OAR1_OA1_LSB        0
#define I2C_OAR1_OA1_MSB        9
#define I2C_OAR1_OA1_MASK       (0x3ff << I2C_OAR1_OA1_LSB)

/*
 * Own address 2 register bits
 */
/* Own Address 2 enable */
#define I2C_OAR2_OA2EN_LSB      15
#define I2C_OAR2_OA2EN_MASK     (1 << I2C_OAR2_OA2EN_LSB)
/* Own Address 2 masks */
#define I2C_OAR2_OA2MSK_LSB     8
#define I2C_OAR2_OA2MSK_MSB     10
#define I2C_OAR2_OA2MSK_MASK    (0x7 << I2C_OAR2_OA2MSK_LSB)
/* 7-bit interface address >>1 */
#define I2C_OAR2_OA2_LSB        1
#define I2C_OAR2_OA2_MSB        7
#define I2C_OAR2_OA2_MASK       (0x7f << I2C_OAR2_OA2_LSB)

/*
 * Timing register bits
 */
/* Timing prescaler */
#define I2C_TIMINGR_PRESC_LSB   28
#define I2C_TIMINGR_PRESC_MSB   31
#define I2C_TIMINGR_PRESC_MASK  (0xf << I2C_TIMINGR_PRESC_LSB)
/* Data setup time */
#define I2C_TIMINGR_SCLDEL_LSB  20
#define I2C_TIMINGR_SCLDEL_MSB  23
#define I2C_TIMINGR_SCLDEL_MASK (0xf << I2C_TIMINGR_SCLDEL_LSB)
/* Data hold time */
#define I2C_TIMINGR_SDADEL_LSB  16
#define I2C_TIMINGR_SDADEL_MSB  19
#define I2C_TIMINGR_SDADEL_MASK (0xf << I2C_TIMINGR_SDADEL_LSB)
/* SCL high period (master mode) */
#define I2C_TIMINGR_SCLH_LSB    8
#define I2C_TIMINGR_SCLH_MSB    15
#define I2C_TIMINGR_SCLH_MASK   (0xff << I2C_TIMINGR_SCLH_LSB)
/* SCL low period (master mode) */
#define I2C_TIMINGR_SCLL_LSB    0
#define I2C_TIMINGR_SCLL_MSB    7
#define I2C_TIMINGR_SCLL_MASK   (0xff << I2C_TIMINGR_SCLL_LSB)

/*
 * Timeout register bits
 */
/* Extended clock timeout enable */
#define I2C_TIMEOUTR_TEXTEN_LSB     31
#define I2C_TIMEOUTR_TEXTEN_MASK    (1 << I2C_TIMEOUTR_TEXTEN_LSB)
/* Bus timeout B */
#define I2C_TIMEOUTR_TIMEOUTB_LSB   16
#define I2C_TIMEOUTR_TIMEOUTB_MSB   27
#define I2C_TIMEOUTR_TIMEOUTB_MASK  (0xfff << I2C_TIMEOUTR_TIMEOUTB_LSB)
/* Clock timeout enable */
#define I2C_TIMEOUTR_TIMOUTEN_LSB   15
#define I2C_TIMEOUTR_TIMOUTEN_MASK  (1 << I2C_TIMEOUTR_TIMOUTEN_LSB)
/* Idle clock timeout detection */
#define I2C_TIMEOUTR_TIDLE_LSB   12
#define I2C_TIMEOUTR_TIDLE_MASK  (1 << I2C_TIMEOUTR_TIDLE_LSB)
/* Bus timeout A */
#define I2C_TIMEOUTR_TIMEOUTA_LSB   0
#define I2C_TIMEOUTR_TIMEOUTA_MSB   11
#define I2C_TIMEOUTR_TIMEOUTA_MASK  (0xfff << I2C_TIMEOUTR_TIMEOUTA_LSB)

/*
 * Interrupt and status register bits
 */
/* Address match code (slave mode) */
#define I2C_ISR_ADDCODE_LSB     17
#define I2C_ISR_ADDCODE_MSB     23
#define I2C_ISR_ADDCODE_MASK    (0x7f << I2C_ISR_ADDCODE_LSB)
/* Transfer direction (slave mode) */
#define I2C_ISR_DIR_LSB         16
#define I2C_ISR_DIR_MASK        (1 << I2C_ISR_DIR_LSB)
/* Bus busy */
#define I2C_ISR_BUSY_LSB        15
#define I2C_ISR_BUSY_MASK       (1 << I2C_ISR_BUSY_LSB)
/* SMBus alert */
#define I2C_ISR_ALERT_LSB       13
#define I2C_ISR_ALERT_MASK      (1 << I2C_ISR_ALERT_LSB)
/* Timeout or tLOW detection flag */
#define I2C_ISR_TIMEOUT_LSB     12
#define I2C_ISR_TIMEOUT_MASK    (1 << I2C_ISR_TIMEOUT_LSB)
/* PEC Error in reception */
#define I2C_ISR_PECERR_LSB      11
#define I2C_ISR_PECERR_MASK     (1 << I2C_ISR_PECERR_LSB)
/* Overrun/Underrun (slave mode) */
#define I2C_ISR_OVR_LSB         10
#define I2C_ISR_OVR_MASK        (1 << I2C_ISR_OVR_LSB)
/* Arbitration lost */
#define I2C_ISR_ARLO_LSB        9
#define I2C_ISR_ARLO_MASK       (1 << I2C_ISR_ARLO_LSB)
/* Bus error */
#define I2C_ISR_BERR_LSB        8
#define I2C_ISR_BERR_MASK       (1 << I2C_ISR_BERR_LSB)
/* Transfer Complete Reload */
#define I2C_ISR_TCR_LSB         7
#define I2C_ISR_TCR_MASK        (1 << I2C_ISR_TCR_LSB)
/* Transfer Complete (master mode) */
#define I2C_ISR_TC_LSB          6
#define I2C_ISR_TC_MASK         (1 << I2C_ISR_TC_LSB)
/* Stop detection flag */
#define I2C_ISR_STOPF_LSB       5
#define I2C_ISR_STOPF_MASK      (1 << I2C_ISR_STOPF_LSB)
/* Not Acknowledge received flag */
#define I2C_ISR_NACKF_LSB       4
#define I2C_ISR_NACKF_MASK      (1 << I2C_ISR_NACKF_LSB)
/* Address matched (slave mode) */
#define I2C_ISR_ADDR_LSB        3
#define I2C_ISR_ADDR_MASK       (1 << I2C_ISR_ADDR_LSB)
/* Receive data register not empty (receivers) */
#define I2C_ISR_RXNE_LSB        2
#define I2C_ISR_RXNE_MASK       (1 << I2C_ISR_RXNE_LSB)
/* Transmit interrupt status (transmitters) */
#define I2C_ISR_TXIS_LSB        1
#define I2C_ISR_TXIS_MASK       (1 << I2C_ISR_TXIS_LSB)
/* Transmit data register empty (transmitters) */
#define I2C_ISR_TXE_LSB         0
#define I2C_ISR_TXE_MASK        (1 << I2C_ISR_TXE_LSB)

/*
 * Interrupt clear register bits
 */
/* Alert flag clear */
#define I2C_ICR_ALERTCF_LSB     13
#define I2C_ICR_ALERTCF_MASK    (1 << I2C_ICR_ALERTCF_LSB)
/* Timeout detection flag clear */
#define I2C_ICR_TIMOUTCF_LSB    12
#define I2C_ICR_TIMOUTCF_MASK   (1 << I2C_ICR_TIMOUTCF_LSB)
/* PEC error flag clear */
#define I2C_ICR_PECCF_LSB       11
#define I2C_ICR_PECCF_MASK      (1 << I2C_ICR_PECCF_LSB)
/* Overrun/Underrun flag clear */
#define I2C_ICR_OVRCF_LSB       10
#define I2C_ICR_OVRCF_MASK      (1 << I2C_ICR_OVRCF_LSB)
/* Arbitration Lost flag clear */
#define I2C_ICR_ARLOCF_LSB      9
#define I2C_ICR_ARLOCF_MASK     (1 << I2C_ICR_ARLOCF_LSB)
/* Bus error flag clear */
#define I2C_ICR_BERRCF_LSB      8
#define I2C_ICR_BERRCF_MASK     (1 << I2C_ICR_BERRCF_LSB)
/* Stop detection flag clear */
#define I2C_ICR_STOPCF_LSB      5
#define I2C_ICR_STOPCF_MASK     (1 << I2C_ICR_STOPCF_LSB)
/* Not Acknowledge flag clear */
#define I2C_ICR_NACKCF_LSB      4
#define I2C_ICR_NACKCF_MASK     (1 << I2C_ICR_NACKCF_LSB)
/* Address matched flag clear */
#define I2C_ICR_ADDRCF_LSB      3
#define I2C_ICR_ADDRCF_MASK     (1 << I2C_ICR_ADDRCF_LSB)

/*
 * PEC register bits
 */
/* Packet error checking register */
#define I2C_PEC_PEC_LSB     0
#define I2C_PEC_PEC_MSB     7
#define I2C_PEC_PEC_MASK    (0xff << I2C_PEC_PEC_LSB)

/*
 * Receive data register bits
 */
/* 8-bit receive data */
#define I2C_RXDR_RXDATA_LSB     0
#define I2C_RXDR_RXDATA_MSB     7
#define I2C_RXDR_RXDATA_MASK    (0xff << I2C_RXDR_RXDATA_LSB)

/*
 * Transmit data register bits
 */
/* 8-bit transmit data */
#define I2C_TXDR_TXDATA_LSB     0
#define I2C_TXDR_TXDATA_MSB     7
#define I2C_TXDR_TXDATA_MASK    (0xff << I2C_TXDR_TXDATA_LSB)

#endif /* _I2C_H */
