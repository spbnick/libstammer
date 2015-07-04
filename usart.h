/*
 * USART (Universal Synchronous/Asynchronous Receiver/Transmitter)
 */

#ifndef _USART_H
#define _USART_H

/* USART structure */
struct usart {
    unsigned int sr;    /* Status register */
    unsigned int dr;    /* Data register */
    unsigned int brr;   /* Baud rate register */
    unsigned int cr1;   /* Control register 1 */
    unsigned int cr2;   /* Control register 2 */
    unsigned int cr3;   /* Control register 3 */
    unsigned int gtpr;  /* Guard time and prescaler register */
};

/* The USART1 instance */
#define USART1 ((volatile struct usart *)0x40013800)
/* The USART2 instance */
#define USART2 ((volatile struct usart *)0x40004400)
/* The USART3 instance */
#define USART3 ((volatile struct usart *)0x40004800)

/*
 * Status register bits
 */
/* Parity error */
#define USART_SR_PE_LSB     0
#define USART_SR_PE_MASK    (1 << USART_SR_PE_LSB)
/* Framing error */
#define USART_SR_FE_LSB     1
#define USART_SR_FE_MASK    (1 << USART_SR_FE_LSB)
/* Noise error */
#define USART_SR_NE_LSB     2
#define USART_SR_NE_MASK    (1 << USART_SR_NE_LSB)
/* Overrun error */
#define USART_SR_ORE_LSB    3
#define USART_SR_ORE_MASK   (1 << USART_SR_ORE_LSB)
/* Idle line detected */
#define USART_SR_IDLE_LSB   4
#define USART_SR_IDLE_MASK  (1 << USART_SR_IDLE_LSB)
/* Read data register not empty */
#define USART_SR_RXNE_LSB   5
#define USART_SR_RXNE_MASK  (1 << USART_SR_RXNE_LSB)
/* Transmission complete */
#define USART_SR_TC_LSB     6
#define USART_SR_TC_MASK    (1 << USART_SR_TC_LSB)
/* Transmission data register empty */
#define USART_SR_TXE_LSB    7
#define USART_SR_TXE_MASK   (1 << USART_SR_TXE_LSB)
/* LIN break detection flag */
#define USART_SR_LIN_LSB    8
#define USART_SR_LIN_MASK   (1 << USART_SR_LIN_LSB)
/* CTS flag */
#define USART_SR_CTS_LSB    9
#define USART_SR_CTS_MASK   (1 << USART_SR_CTS_LSB)

/*
 * Baud rate register bits
 */
/* Fraction of USARTDIV */
#define USART_BRR_DIV_FRACTION_LSB      0
#define USART_BRR_DIV_FRACTION_MSB      3
#define USART_BRR_DIV_FRACTION_MASK     (0xf << USART_BRR_DIV_FRACTION_LSB)
/* Mantissa of USARTDIV */
#define USART_BRR_DIV_MANTISSA_LSB      4
#define USART_BRR_DIV_MANTISSA_MSB      15
#define USART_BRR_DIV_MANTISSA_MASK     (0x3fff << USART_BRR_DIV_MANTISSA_LSB)

/*
 * Control register 1 bits
 */
/* Send break */
#define USART_CR1_SBK_LSB       0
#define USART_CR1_SBK_MASK      (1 << USART_CR1_SBK_LSB)
/* Receiver wakeup */
#define USART_CR1_RWU_LSB       1
#define USART_CR1_RWU_MASK      (1 << USART_CR1_RWU_LSB)
/* Receiver enable */
#define USART_CR1_RE_LSB        2
#define USART_CR1_RE_MASK       (1 << USART_CR1_RE_LSB)
/* Transmitter enable */
#define USART_CR1_TE_LSB        3
#define USART_CR1_TE_MASK       (1 << USART_CR1_TE_LSB)
/* IDLE interrupt enable */
#define USART_CR1_IDLEIE_LSB    4
#define USART_CR1_IDLEIE_MASK   (1 << USART_CR1_IDLEIE_LSB)
/* RXNE interrupt enable */
#define USART_CR1_RXNEIE_LSB    5
#define USART_CR1_RXNEIE_MASK   (1 << USART_CR1_RXNEIE_LSB)
/* Transmission complete interrupt enable */
#define USART_CR1_TCIE_LSB      6
#define USART_CR1_TCIE_MASK     (1 << USART_CR1_TCIE_LSB)
/* TXE interrupt enable */
#define USART_CR1_TXEIE_LSB     7
#define USART_CR1_TXEIE_MASK    (1 << USART_CR1_TXEIE_LSB)
/* PE interrupt enable */
#define USART_CR1_PEIE_LSB      8
#define USART_CR1_PEIE_MASK     (1 << USART_CR1_PEIE_LSB)
/* Parity selection */
#define USART_CR1_PS_LSB        9
#define USART_CR1_PS_MASK       (1 << USART_CR1_PS_LSB)
/* Parity control enable */
#define USART_CR1_PCE_LSB       10
#define USART_CR1_PCE_MASK      (1 << USART_CR1_PCE_LSB)
/* Wakeup method */
#define USART_CR1_WAKE_LSB      11
#define USART_CR1_WAKE_MASK     (1 << USART_CR1_WAKE_LSB)
/* Word length */
#define USART_CR1_M_LSB         12
#define USART_CR1_M_MASK        (1 << USART_CR1_M_LSB)
/* USART enable */
#define USART_CR1_UE_LSB        13
#define USART_CR1_UE_UEASK      (1 << USART_CR1_UE_LSB)

/*
 * Control register 2 bits
 */
/* Address of the USART node */
#define USART_CR2_ADD_LSB       0
#define USART_CR2_ADD_MSB       3
#define USART_CR2_ADD_MASK      (0xf << USART_CR2_ADD_LSB)
/* LIN break detection length */
#define USART_CR2_LBDL_LSB      5
#define USART_CR2_LBDL_MASK     (1 << USART_CR2_LBDL_LSB)
/* LIN break detection interrupt enable */
#define USART_CR2_LBDIE_LSB     6
#define USART_CR2_LBDIE_MASK    (1 << USART_CR2_LBDIE_LSB)
/* Last bit clock pulse */
#define USART_CR2_LBCL_LSB      8
#define USART_CR2_LBCL_MASK     (1 << USART_CR2_LBCL_LSB)
/* Clock phase */
#define USART_CR2_CPHA_LSB      9
#define USART_CR2_CPHA_MASK     (1 << USART_CR2_CPHA_LSB)
/* Clock polarity */
#define USART_CR2_CPOL_LSB      10
#define USART_CR2_CPOL_MASK     (1 << USART_CR2_CPOL_LSB)
/* Clock enable */
#define USART_CR2_CLKEN_LSB     11
#define USART_CR2_CLKEN_MASK    (1 << USART_CR2_CLKEN_LSB)
/* STOP bits */
#define USART_CR2_STOP_LSB      12
#define USART_CR2_STOP_MSB      13
#define USART_CR2_STOP_MASK     (0x3 << USART_CR2_STOP_LSB)
#define USART_CR2_STOP_VAL_1_0  0x0 /* 1 stop bit */
#define USART_CR2_STOP_VAL_0_5  0x1 /* 0.5 stop bits */
#define USART_CR2_STOP_VAL_2_0  0x2 /* 2 stop bits */
#define USART_CR2_STOP_VAL_1_5  0x3 /* 1.5 stop bits */
/* LIN mode enable */
#define USART_CR2_LINEN_LSB     14
#define USART_CR2_LINEN_MASK    (1 << USART_CR2_LINEN_LSB)

/*
 * Control register 3 bits
 */
/* Error interrupt enable */
#define USART_CR3_EIE_LSB       0
#define USART_CR3_EIE_MASK      (1 << USART_CR3_EIE_LSB)
/* IrDA mode enable */
#define USART_CR3_IREN_LSB      1
#define USART_CR3_IREN_MASK     (1 << USART_CR3_IREN_LSB)
/* IrDA low-power */
#define USART_CR3_IRLP_LSB      2
#define USART_CR3_IRLP_MASK     (1 << USART_CR3_IRLP_LSB)
/* Half-duplex selection */
#define USART_CR3_HDSEL_LSB     3
#define USART_CR3_HDSEL_MASK    (1 << USART_CR3_HDSEL_LSB)
/* Smartcard NACK enable */
#define USART_CR3_NACK_LSB      4
#define USART_CR3_NACK_MASK     (1 << USART_CR3_NACK_LSB)
/* Smartcard mode enable */
#define USART_CR3_SCEN_LSB      5
#define USART_CR3_SCEN_MASK     (1 << USART_CR3_SCEN_LSB)
/* DMA enable receiver */
#define USART_CR3_DMAR_LSB      6
#define USART_CR3_DMAR_MASK     (1 << USART_CR3_DMAR_LSB)
/* DMA enable transmitter */
#define USART_CR3_DMAT_LSB      7
#define USART_CR3_DMAT_MASK     (1 << USART_CR3_DMAT_LSB)
/* RTS enable */
#define USART_CR3_RTSE_LSB      8
#define USART_CR3_RTSE_MASK     (1 << USART_CR3_RTSE_LSB)
/* CTS enable */
#define USART_CR3_CTSE_LSB      9
#define USART_CR3_CTSE_MASK     (1 << USART_CR3_CTSE_LSB)
/* CTS interrupt enable */
#define USART_CR3_CTSIE_LSB     10
#define USART_CR3_CTSIE_MASK    (1 << USART_CR3_CTSIE_LSB)

/*
 * Guard time and prescaler register bits
 */
/* Prescaler value */
#define USART_GTPR_PSC_LSB      0
#define USART_GTPR_PSC_MSB      7
#define USART_GTPR_PSC_MASK     (0xff << USART_GTPR_PSC_LSB)
/* Guard time value */
#define USART_GTPR_GT_LSB       8
#define USART_GTPR_GT_MSB       15
#define USART_GTPR_GT_MASK      (0xff << USART_GTPR_GT_LSB)

#endif /* _USART_H */
