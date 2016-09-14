/*
 * SPI (SPI and I2S)
 */

#ifndef _SPI_H
#define _SPI_H

/* SPI (SPI and I2S) */
struct tim {
    unsigned int cr1;       /* Control register 1 (SPI-only) */
    unsigned int cr2;       /* Control register 2 */
    unsigned int sr;        /* Status register */
    unsigned int dr;        /* Data register */
    unsigned int crcpr;     /* CRC polynomial register (SPI-only) */
    unsigned int rxcrcr;    /* RX CRC register (SPI-only) */
    unsigned int txcrcr;    /* TX CRC register (SPI-only) */
    unsigned int i2scfgr;   /* I2S configuration register (I2S-only) */
    unsigned int i2spr;     /* I2S prescaler register (I2S-only) */
};

/* The SPI1 instance */
#define SPI1 ((volatile struct spi *)0x40013000)
/* The SPI2 instance */
#define SPI2 ((volatile struct spi *)0x40003800)

/*
 * Control register 1 bits (SPI-only)
 */
/* Clock phase */
#define SPI_CR1_CPHA_LSB        0
#define SPI_CR1_CPHA_MASK       (1 << SPI_CR1_CPHA_LSB)
#define SPI_CR1_CPHA_VAL_FIRST  0   /* First transition = data capture edge */
#define SPI_CR1_CPHA_VAL_SECOND 1   /* Second transition = data capture edge */
/* Clock polarity when idle */
#define SPI_CR1_CPOL_LSB        1
#define SPI_CR1_CPOL_MASK       (1 << SPI_CR1_CPOL_LSB)
/* Master selection */
#define SPI_CR1_MSTR_LSB        2
#define SPI_CR1_MSTR_MASK       (1 << SPI_CR1_MSTR_LSB)
#define SPI_CR1_MSTR_VAL_SLAVE  0
#define SPI_CR1_MSTR_VAL_MASTER 1
/* Baud rate control */
#define SPI_CR1_BR_LSB          3
#define SPI_CR1_BR_MSB          5
#define SPI_CR1_BR_MASK         (0x7 << SPI_CR1_BR_LSB)
#define SPI_CR1_BR_VAL_FPCLK_DIV2   0   /* Fpclk / 2 */
#define SPI_CR1_BR_VAL_FPCLK_DIV4   1   /* Fpclk / 4 */
#define SPI_CR1_BR_VAL_FPCLK_DIV8   2   /* Fpclk / 8 */
#define SPI_CR1_BR_VAL_FPCLK_DIV16  3   /* Fpclk / 16 */
#define SPI_CR1_BR_VAL_FPCLK_DIV32  4   /* Fpclk / 32 */
#define SPI_CR1_BR_VAL_FPCLK_DIV64  5   /* Fpclk / 64 */
#define SPI_CR1_BR_VAL_FPCLK_DIV128 6   /* Fpclk / 128 */
#define SPI_CR1_BR_VAL_FPCLK_DIV256 7   /* Fpclk / 256 */
/* SPI enable */
#define SPI_CR1_SPE_LSB         6
#define SPI_CR1_SPE_MASK        (1 << SPI_CR1_SPE_LSB)
/* Frame format (MSB/LSB-first) */
#define SPI_CR1_LSBFIRST_LSB    7
#define SPI_CR1_LSBFIRST_MASK   (1 << SPI_CR1_LSBFIRST_LSB)
/* Internal slave select */
#define SPI_CR1_SSI_LSB         8
#define SPI_CR1_SSI_MASK        (1 << SPI_CR1_SSI_LSB)
/* Software slave management */
#define SPI_CR1_SSM_LSB         9
#define SPI_CR1_SSM_MASK        (1 << SPI_CR1_SSM_LSB)
/* Receive only */
#define SPI_CR1_RXONLY_LSB      10
#define SPI_CR1_RXONLY_MASK     (1 << SPI_CR1_RXONLY_LSB)
/* Data frame format */
#define SPI_CR1_DFF_LSB         11
#define SPI_CR1_DFF_MASK        (1 << SPI_CR1_DFF_LSB)
#define SPI_CR1_DFF_VAL_8BIT    0
#define SPI_CR1_DFF_VAL_16BIT   1
/* CRC transfer next */
#define SPI_CR1_CRCNEXT_LSB     12
#define SPI_CR1_CRCNEXT_MASK    (1 << SPI_CR1_CRCNEXT_LSB)
/* Hardware CRC calculation enable */
#define SPI_CR1_CRCEN_LSB       13
#define SPI_CR1_CRCEN_MASK      (1 << SPI_CR1_CRCEN_LSB)
/* Output enable in bidirectional mode */
#define SPI_CR1_BIDIOE_LSB      14
#define SPI_CR1_BIDIOE_MASK     (1 << SPI_CR1_BIDIOE_LSB)
/* Bidirectional data mode enable */
#define SPI_CR1_BIDIMODE_LSB            15
#define SPI_CR1_BIDIMODE_MASK           (1 << SPI_CR1_BIDIMODE_LSB)
#define SPI_CR1_BIDIMODE_VAL_2LINE_UNI  0
#define SPI_CR1_BIDIMODE_VAL_1LINE_BI   1

/*
 * Control register 2 bits
 */
/* RX buffer DMA enable */
#define SPI_CR2_RXDMAEN_LSB     0
#define SPI_CR2_RXDMAEN_MASK    (1 << SPI_CR2_RXDMAEN_LSB)
/* TX buffer DMA enable */
#define SPI_CR2_TXDMAEN_LSB     1
#define SPI_CR2_TXDMAEN_MASK    (1 << SPI_CR2_TXDMAEN_LSB)
/* SS output enable */
#define SPI_CR2_SSOE_LSB        2
#define SPI_CR2_SSOE_MASK       (1 << SPI_CR2_SSOE_LSB)
/* Error interrupt enable */
#define SPI_CR2_ERRIE_LSB       5
#define SPI_CR2_ERRIE_MASK      (1 << SPI_CR2_ERRIE_LSB)
/* RX buffer not empty interrupt enable */
#define SPI_CR2_RXNEIE_LSB      6
#define SPI_CR2_RXNEIE_MASK     (1 << SPI_CR2_RXNEIE_LSB)
/* TX buffer empty interrupt enable */
#define SPI_CR2_TXEIE_LSB       7
#define SPI_CR2_TXEIE_MASK      (1 << SPI_CR2_TXEIE_LSB)

/*
 * Status register bits
 */
/* Receive buffer not empty */
#define SPI_SR_RXNE_LSB         0
#define SPI_SR_RXNE_MASK        (1 << SPI_SR_RXNE_LSB)
/* Transmit buffer empty */
#define SPI_SR_TXE_LSB          1
#define SPI_SR_TXE_MASK         (1 << SPI_SR_TXE_LSB)
/* Channel side (I2S-only, not PCM) */
#define SPI_SR_CHSIDE_LSB       2
#define SPI_SR_CHSIDE_MASK      (1 << SPI_SR_CHSIDE_LSB)
#define SPI_SR_CHSIDE_VAL_LEFT  0
#define SPI_SR_CHSIDE_VAL_RIGHT 1
/* Underrun flag */
#define SPI_SR_UDR_LSB          3
#define SPI_SR_UDR_MASK         (1 << SPI_SR_UDR_LSB)
/* CRC error flag (SPI-only) */
#define SPI_SR_CRCERR_LSB       4
#define SPI_SR_CRCERR_MASK      (1 << SPI_SR_CRCERR_LSB)
/* Mode fault (SPI-only) */
#define SPI_SR_MODF_LSB         5
#define SPI_SR_MODF_MASK        (1 << SPI_SR_MODF_LSB)
/* Overrun flag */
#define SPI_SR_OVR_LSB          6
#define SPI_SR_OVR_MASK         (1 << SPI_SR_OVR_LSB)
/* Busy flag */
#define SPI_SR_BSY_LSB          7
#define SPI_SR_BSY_MASK         (1 << SPI_SR_BSY_LSB)

/*
 * I2S configuration register bits (I2S-only)
 */
/* Channel length */
#define SPI_I2SCFGR_CHLEN_LSB       0
#define SPI_I2SCFGR_CHLEN_MASK      (1 << SPI_I2SCFGR_CHLEN_LSB)
#define SPI_I2SCFGR_CHLEN_VAL_16BIT 0
#define SPI_I2SCFGR_CHLEN_VAL_32BIT 1
/* Data length to be transferred */
#define SPI_I2SCFGR_DATLEN_LSB          1
#define SPI_I2SCFGR_DATLEN_MSB          2
#define SPI_I2SCFGR_DATLEN_MASK         (3 << SPI_I2SCFGR_DATLEN_LSB)
#define SPI_I2SCFGR_DATLEN_VAL_16BIT    0
#define SPI_I2SCFGR_DATLEN_VAL_24BIT    1
#define SPI_I2SCFGR_DATLEN_VAL_32BIT    2
/* Steady state clock polarity */
#define SPI_I2SCFGR_CKPOL_LSB       3
#define SPI_I2SCFGR_CKPOL_MASK      (1 << SPI_I2SCFGR_CKPOL_LSB)
#define SPI_I2SCFGR_CKPOL_VAL_LOW   0
#define SPI_I2SCFGR_CKPOL_VAL_HIGH  1
/* I2S standard selection */
#define SPI_I2SCFGR_I2SSTD_LSB          4
#define SPI_I2SCFGR_I2SSTD_MSB          5
#define SPI_I2SCFGR_I2SSTD_MASK         (3 << SPI_I2SCFGR_I2SSTD_LSB)
#define SPI_I2SCFGR_I2SSTD_VAL_PHILIPS          0
#define SPI_I2SCFGR_I2SSTD_VAL_MSB_JUSTIFIED    1
#define SPI_I2SCFGR_I2SSTD_VAL_LSB_JUSTIFIED    2
#define SPI_I2SCFGR_I2SSTD_VAL_PCM              3
/* PCM frame synchronization */
#define SPI_I2SCFGR_PCMSYNC_LSB         7
#define SPI_I2SCFGR_PCMSYNC_MASK        (1 << SPI_I2SCFGR_PCMSYNC_LSB)
#define SPI_I2SCFGR_PCMSYNC_VAL_SHORT   0
#define SPI_I2SCFGR_PCMSYNC_VAL_LONG    1
/* I2S configuration mode */
#define SPI_I2SCFGR_I2SCFG_LSB          8
#define SPI_I2SCFGR_I2SCFG_MSB          9
#define SPI_I2SCFGR_I2SCFG_MASK         (3 << SPI_I2SCFGR_I2SCFG_LSB)
#define SPI_I2SCFGR_I2SCFG_VAL_SLAVE_TX     0
#define SPI_I2SCFGR_I2SCFG_VAL_SLAVE_RX     1
#define SPI_I2SCFGR_I2SCFG_VAL_MASTER_TX    2
#define SPI_I2SCFGR_I2SCFG_VAL_MASTER_RX    3
/* I2S enable */
#define SPI_I2SCFGR_I2SE_LSB        10
#define SPI_I2SCFGR_I2SE_MASK       (1 << SPI_I2SCFGR_I2SE_LSB)
/* I2S mode selection */
#define SPI_I2SCFGR_I2SMOD_LSB      10
#define SPI_I2SCFGR_I2SMOD_MASK     (1 << SPI_I2SCFGR_I2SMOD_LSB)
#define SPI_I2SCFGR_I2SMOD_VAL_SPI  0
#define SPI_I2SCFGR_I2SMOD_VAL_I2S  1

/*
 * I2S prescaler register bits (I2S-only)
 */
/* I2S configuration mode */
#define SPI_I2SPR_I2SDIV_LSB    0
#define SPI_I2SPR_I2SDIV_MSB    7
#define SPI_I2SPR_I2SDIV_MASK   (0xff << SPI_I2SPR_I2SDIV_LSB)
/* Odd factor for the prescaler */
#define SPI_I2SPR_ODD_LSB       8
#define SPI_I2SPR_ODD_MASK      (1 << SPI_I2SPR_ODD_LSB)
/* Master clock output enable */
#define SPI_I2SPR_MCKOE_LSB     9
#define SPI_I2SPR_MCKOE_MASK    (1 << SPI_I2SPR_MCKOE_LSB)

#endif /* _SPI_H */
