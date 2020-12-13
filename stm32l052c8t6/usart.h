/*
 * USART (Universal Synchronous/Asynchronous Receiver/Transmitter)
 */

#ifndef _USART_H
#define _USART_H

#include <../stm32/misc.h>
#include <stddef.h>

/** USART structure */
struct usart {
    unsigned int cr1;   /**< Control register 1 */
    unsigned int cr2;   /**< Control register 2 */
    unsigned int cr3;   /**< Control register 3 */
    unsigned int brr;   /**< Baud rate register */
    unsigned int gtpr;  /**< Guard time and prescaler register */
    unsigned int rtor;  /**< Receiver timeout register */
    unsigned int rqr;   /**< Request register */
    unsigned int isr;   /**< Interrupt and status register */
    unsigned int icr;   /**< Interrupt flag clear register */
    unsigned int rdr;   /**< Receive data register */
    unsigned int tdr;   /**< Transmit data register */
};

/** The USART1 instance */
#define USART1 ((volatile struct usart *)0x40013800)
/** The USART2 instance */
#define USART2 ((volatile struct usart *)0x40004400)
/** The USART4 instance */
#define USART4 ((volatile struct usart *)0x40004C00)
/** The USART5 instance */
#define USART5 ((volatile struct usart *)0x40005C00)

/*
 * Control register 1 bits
 */
/* Word length bit 1 */
#define USART_CR1_M1_LSB    28
#define USART_CR1_M1_MASK   (1 << USART_CR1_M1_LSB)
/* End of Block interrupt enable */
#define USART_CR1_EOBIE_LSB     27
#define USART_CR1_EOBIE_MASK    (1 << USART_CR1_EOBIE_LSB)
/* Receiver timeout interrupt enable */
#define USART_CR1_RTOIE_LSB     26
#define USART_CR1_RTOIE_MASK    (1 << USART_CR1_RTOIE_LSB)
/* Driver Enable assertion time */
#define USART_CR1_DEAT_LSB      21
#define USART_CR1_DEAT_MSB      25
#define USART_CR1_DEAT_MASK     (0x1f << USART_CR1_DEAT_LSB)
/* Driver Enable deassertion time */
#define USART_CR1_DEDT_LSB      16
#define USART_CR1_DEDT_MSB      20
#define USART_CR1_DEDT_MASK     (0x1f << USART_CR1_DEDT_LSB)
/* Oversampling mode */
#define USART_CR1_OVER8_LSB     15
#define USART_CR1_OVER8_MASK    (1 << USART_CR1_OVER8_LSB)
/* Oversampling mode value */
enum usart_cr1_over8_val {
    USART_CR1_OVER8_VAL_BY_16 = 0,
    USART_CR1_OVER8_VAL_BY_8
};
/* Character match interrupt enable */
#define USART_CR1_CMIE_LSB      14
#define USART_CR1_CMIE_MASK     (1 << USART_CR1_CMIE_LSB)
/* Mute mode enable */
#define USART_CR1_MME_LSB       13
#define USART_CR1_MME_MASK      (1 << USART_CR1_MME_LSB)
/* Word length bit 0 */
#define USART_CR1_M0_LSB        12
#define USART_CR1_M0_MASK       (1 << USART_CR1_M0_LSB)
/* Receiver wakeup method */
#define USART_CR1_WAKE_LSB      11
#define USART_CR1_WAKE_MASK     (1 << USART_CR1_WAKE_LSB)
/* Receiver wakeup method value */
enum usart_cr1_wake_val {
    USART_CR1_WAKE_VAL_IDLE_LINE = 0,
    USART_CR1_WAKE_VAL_ADDRESS_MARK
};
/* Parity control enable */
#define USART_CR1_PCE_LSB       10
#define USART_CR1_PCE_MASK      (1 << USART_CR1_PCE_LSB)
/* Parity selection */
#define USART_CR1_PS_LSB        9
#define USART_CR1_PS_MASK       (1 << USART_CR1_PS_LSB)
/* Parity selection value */
enum usart_cr1_ps_val {
    USART_CR1_PS_VAL_EVEN = 0,
    USART_CR1_PS_VAL_ODD
};
/* PE interrupt enable */
#define USART_CR1_PEIE_LSB      8
#define USART_CR1_PEIE_MASK     (1 << USART_CR1_PEIE_LSB)
/* TX empty (TXE) interrupt enable */
#define USART_CR1_TXEIE_LSB     7
#define USART_CR1_TXEIE_MASK    (1 << USART_CR1_TXEIE_LSB)
/* Transmission complete interrupt enable */
#define USART_CR1_TCIE_LSB      6
#define USART_CR1_TCIE_MASK     (1 << USART_CR1_TCIE_LSB)
/* RX not-empty (RXNE) interrupt enable */
#define USART_CR1_RXNEIE_LSB    5
#define USART_CR1_RXNEIE_MASK   (1 << USART_CR1_RXNEIE_LSB)
/* IDLE interrupt enable */
#define USART_CR1_IDLEIE_LSB    4
#define USART_CR1_IDLEIE_MASK   (1 << USART_CR1_IDLEIE_LSB)
/* Transmitter enable */
#define USART_CR1_TE_LSB        3
#define USART_CR1_TE_MASK       (1 << USART_CR1_TE_LSB)
/* Receiver enable */
#define USART_CR1_RE_LSB        2
#define USART_CR1_RE_MASK       (1 << USART_CR1_RE_LSB)
/* USART enable in Stop mode */
#define USART_CR1_UESM_LSB      1
#define USART_CR1_UESM_MASK     (1 << USART_CR1_UESM_LSB)
/* USART enable */
#define USART_CR1_UE_LSB        0
#define USART_CR1_UE_MASK       (1 << USART_CR1_UE_LSB)

/*
 * Control register 2 bits
 */
/* Address of the USART node */
#define USART_CR2_ADD_LSB       24
#define USART_CR2_ADD_MSB       31
#define USART_CR2_ADD_MASK      (0xff << USART_CR2_ADD_LSB)
/* Receiver timeout enable */
#define USART_CR2_RTOEN_LSB     23
#define USART_CR2_RTOEN_MASK    (1 << USART_CR2_RTOEN_LSB)
/* Auto baud rate mode */
#define USART_CR2_ABRMOD_LSB    21
#define USART_CR2_ABRMOD_MSB    22
#define USART_CR2_ABRMOD_MASK   (0x3 << USART_CR2_ABRMOD_LSB)
/* Auto baud rate mode value */
enum usart_cr2_abrmod_val {
    USART_CR2_ABRMOD_VAL_START_BIT = 0,
    USART_CR2_ABRMOD_VAL_EDGE_TO_EDGE,
    USART_CR2_ABRMOD_VAL_7F_FRAME,
    USART_CR2_ABRMOD_VAL_55_FRAME
};
/* Auto baud rate enable */
#define USART_CR2_ABREN_LSB     20
#define USART_CR2_ABREN_MASK    (1 << USART_CR2_ABREN_LSB)
/* Most significant bit first */
#define USART_CR2_MSBFIRST_LSB  19
#define USART_CR2_MSBFIRST_MASK (1 << USART_CR2_MSBFIRST_LSB)
/* Binary data inversion */
#define USART_CR2_DATAINV_LSB   18
#define USART_CR2_DATAINV_MASK  (1 << USART_CR2_DATAINV_LSB)
/* TX pin active level inversion */
#define USART_CR2_TXINV_LSB     17
#define USART_CR2_TXINV_MASK    (1 << USART_CR2_TXINV_LSB)
/* RX pin active level inversion */
#define USART_CR2_RXINV_LSB     16
#define USART_CR2_RXINV_MASK    (1 << USART_CR2_RXINV_LSB)
/* Swap TX/RX pins */
#define USART_CR2_SWAP_LSB      15
#define USART_CR2_SWAP_MASK     (1 << USART_CR2_SWAP_LSB)
/* LIN mode enable */
#define USART_CR2_LINEN_LSB     14
#define USART_CR2_LINEN_MASK    (1 << USART_CR2_LINEN_LSB)
/* STOP bits */
#define USART_CR2_STOP_LSB      12
#define USART_CR2_STOP_MSB      13
#define USART_CR2_STOP_MASK     (0x3 << USART_CR2_STOP_LSB)
/* STOP bits value */
enum usart_cr2_stop_val {
    USART_CR2_STOP_VAL_1 = 0,
    USART_CR2_STOP_VAL_0_5,
    USART_CR2_STOP_VAL_2,
    USART_CR2_STOP_VAL_1_5
};
/* Clock enable */
#define USART_CR2_CLKEN_LSB     11
#define USART_CR2_CLKEN_MASK    (1 << USART_CR2_CLKEN_LSB)
/* Clock polarity */
#define USART_CR2_CPOL_LSB      10
#define USART_CR2_CPOL_MASK     (1 << USART_CR2_CPOL_LSB)
/* Clock phase */
#define USART_CR2_CPHA_LSB      9
#define USART_CR2_CPHA_MASK     (1 << USART_CR2_CPHA_LSB)
/* Last bit clock pulse */
#define USART_CR2_LBCL_LSB      8
#define USART_CR2_LBCL_MASK     (1 << USART_CR2_LBCL_LSB)
/* LIN break detection interrupt enable */
#define USART_CR2_LBDIE_LSB     6
#define USART_CR2_LBDIE_MASK    (1 << USART_CR2_LBDIE_LSB)
/* LIN break detection length */
#define USART_CR2_LBDL_LSB      5
#define USART_CR2_LBDL_MASK     (1 << USART_CR2_LBDL_LSB)
/* 7-bit Address Detection / 4-bit Address Detection */
#define USART_CR2_ADDM7_LSB     4
#define USART_CR2_ADDM7_MASK    (1 << USART_CR2_ADDM7_LSB)

/*
 * Control register 3 bits
 */
/* USART Clock Enable in Stop mode */
#define USART_CR3_UCESM_LSB     23
#define USART_CR3_UCESM_MASK    (1 << USART_CR3_UCESM_LSB)
/* Wakeup from Stop mode interrupt enable */
#define USART_CR3_WUFIE_LSB     22
#define USART_CR3_WUFIE_MASK    (1 << USART_CR3_WUFIE_LSB)
/* Wakeup from Stop mode interrupt flag selection */
#define USART_CR3_WUS_LSB       20
#define USART_CR3_WUS_MSB       21
#define USART_CR3_WUS_MASK      (3 << USART_CR3_WUS_LSB)
/* Wakeup from Stop mode interrupt flag selection value */
enum usart_cr3_wus_val {
    USART_CR3_WUS_VAL_ADDRESS_MATCH = 0,
    USART_CR3_WUS_VAL_START_BIT = 2,
    USART_CR3_WUS_VAL_RXNE = 3,
};
/* Smartcard auto-retry count */
#define USART_CR3_SCARCNT_LSB   17
#define USART_CR3_SCARCNT_MSB   19
#define USART_CR3_SCARCNT_MASK  (7 << USART_CR3_SCARCNT_LSB)
/* Driver enable polarity selection */
#define USART_CR3_DEP_LSB       15
#define USART_CR3_DEP_MASK      (1 << USART_CR3_DEP_LSB)
/* Driver enable polarity selection value */
enum usart_cr3_dep_val {
    USART_CR3_DEP_VAL_ACTIVE_HIGH = 0,
    USART_CR3_DEP_VAL_ACTIVE_LOW
};
/* Driver enable mode */
#define USART_CR3_DEM_LSB       14
#define USART_CR3_DEM_MASK      (1 << USART_CR3_DEM_LSB)
/* DMA Disable on Reception Error */
#define USART_CR3_DDRE_LSB      13
#define USART_CR3_DDRE_MASK     (1 << USART_CR3_DDRE_LSB)
/* Overrun Disable */
#define USART_CR3_OVRDIS_LSB    12
#define USART_CR3_OVRDIS_MASK   (1 << USART_CR3_OVRDIS_LSB)
/* One sample bit method enable */
#define USART_CR3_ONEBIT_LSB    11
#define USART_CR3_ONEBIT_MASK   (1 << USART_CR3_ONEBIT_LSB)
/* CTS interrupt enable */
#define USART_CR3_CTSIE_LSB     10
#define USART_CR3_CTSIE_MASK    (1 << USART_CR3_CTSIE_LSB)
/* CTS enable */
#define USART_CR3_CTSE_LSB      9
#define USART_CR3_CTSE_MASK     (1 << USART_CR3_CTSE_LSB)
/* RTS enable */
#define USART_CR3_RTSE_LSB      8
#define USART_CR3_RTSE_MASK     (1 << USART_CR3_RTSE_LSB)
/* DMA enable transmitter */
#define USART_CR3_DMAT_LSB      7
#define USART_CR3_DMAT_MASK     (1 << USART_CR3_DMAT_LSB)
/* DMA enable receiver */
#define USART_CR3_DMAR_LSB      6
#define USART_CR3_DMAR_MASK     (1 << USART_CR3_DMAR_LSB)
/* Smartcard mode enable */
#define USART_CR3_SCEN_LSB      5
#define USART_CR3_SCEN_MASK     (1 << USART_CR3_SCEN_LSB)
/* Smartcard NACK enable */
#define USART_CR3_NACK_LSB      4
#define USART_CR3_NACK_MASK     (1 << USART_CR3_NACK_LSB)
/* Half-duplex selection */
#define USART_CR3_HDSEL_LSB     3
#define USART_CR3_HDSEL_MASK    (1 << USART_CR3_HDSEL_LSB)
/* IrDA low-power */
#define USART_CR3_IRLP_LSB      2
#define USART_CR3_IRLP_MASK     (1 << USART_CR3_IRLP_LSB)
/* IrDA mode enable-power */
#define USART_CR3_IREN_LSB      1
#define USART_CR3_IREN_MASK     (1 << USART_CR3_IREN_LSB)
/* Error interrupt enable */
#define USART_CR3_EIE_LSB       0
#define USART_CR3_EIE_MASK      (1 << USART_CR3_EIE_LSB)

/*
 * Baud rate register bits
 */
/* Baud rate register */
#define USART_BRR_BRR_LSB       0
#define USART_BRR_BRR_MSB       15
#define USART_BRR_BRR_MASK      (0xffff << USART_BRR_BRR_LSB)

/*
 * Guard time and prescaler register bits
 */
/* Guard time value */
#define USART_GTPR_GT_LSB       8
#define USART_GTPR_GT_MSB       15
#define USART_GTPR_GT_MASK      (0xff << USART_GTPR_GT_LSB)
/* Prescaler value */
#define USART_GTPR_PSC_LSB      0
#define USART_GTPR_PSC_MSB      7
#define USART_GTPR_PSC_MASK     (0xff << USART_GTPR_PSC_LSB)

/*
 * Receiver timeout register bits
 */
/* Block length */
#define USART_RTOR_BLEN_LSB     24
#define USART_RTOR_BLEN_MSB     31
#define USART_RTOR_BLEN_MASK    (0xff << USART_RTOR_BLEN_LSB)
/* Receiver timeout value */
#define USART_RTOR_RTO_LSB      23
#define USART_RTOR_RTO_MSB      0
#define USART_RTOR_RTO_MASK     (0xffffff << USART_RTOR_RTO_LSB)

/*
 * Request register bits
 */
/* Transmit data flush request */
#define USART_RQR_TXFRQ_LSB     4
#define USART_RQR_TXFRQ_MASK    (1 << USART_RQR_TXFRQ_LSB)
/* Receive data flush request */
#define USART_RQR_RXFRQ_LSB     3
#define USART_RQR_RXFRQ_MASK    (1 << USART_RQR_RXFRQ_LSB)
/* Mute mode request */
#define USART_RQR_MMRQ_LSB      2
#define USART_RQR_MMRQ_MASK     (1 << USART_RQR_MMRQ_LSB)
/* Send break request */
#define USART_RQR_SBKRQ_LSB     1
#define USART_RQR_SBKRQ_MASK    (1 << USART_RQR_SBKRQ_LSB)
/* Auto baud rate request */
#define USART_RQR_ABRRQ_LSB     0
#define USART_RQR_ABRRQ_MASK    (1 << USART_RQR_ABRRQ_LSB)

/*
 * Interrupt and status register bits
 */
/* Receive enable acknowledge flag */
#define USART_ISR_REACK_LSB     22
#define USART_ISR_REACK_MASK    (1 << USART_ISR_REACK_LSB)
/* Transmit enable acknowledge flag */
#define USART_ISR_TEACK_LSB     21
#define USART_ISR_TEACK_MASK    (1 << USART_ISR_TEACK_LSB)
/* Wakeup from Stop mode flag */
#define USART_ISR_WUF_LSB       20
#define USART_ISR_WUF_MASK      (1 << USART_ISR_WUF_LSB)
/* Receiver wakeup from Mute mode flag */
#define USART_ISR_RWU_LSB       19
#define USART_ISR_RWU_MASK      (1 << USART_ISR_RWU_LSB)
/* Send break flag */
#define USART_ISR_SBKF_LSB      18
#define USART_ISR_SBKF_MASK     (1 << USART_ISR_SBKF_LSB)
/* Character match flag */
#define USART_ISR_CMF_LSB       17
#define USART_ISR_CMF_MASK      (1 << USART_ISR_CMF_LSB)
/* Busy flag */
#define USART_ISR_BUSY_LSB      16
#define USART_ISR_BUSY_MASK     (1 << USART_ISR_BUSY_LSB)
/* Auto baud rate flag */
#define USART_ISR_ABRF_LSB      15
#define USART_ISR_ABRF_MASK     (1 << USART_ISR_ABRF_LSB)
/* Auto baud rate error */
#define USART_ISR_ABRE_LSB      14
#define USART_ISR_ABRE_MASK     (1 << USART_ISR_ABRE_LSB)
/* End of block flag */
#define USART_ISR_EOBF_LSB      12
#define USART_ISR_EOBF_MASK     (1 << USART_ISR_EOBF_LSB)
/* Receiver timeout */
#define USART_ISR_RTOF_LSB      11
#define USART_ISR_RTOF_MASK     (1 << USART_ISR_RTOF_LSB)
/* CTS flag */
#define USART_ISR_CTS_LSB       10
#define USART_ISR_CTS_MASK      (1 << USART_ISR_CTS_LSB)
/* CTS interrupt flag */
#define USART_ISR_CTSIF_LSB     9
#define USART_ISR_CTSIF_MASK    (1 << USART_ISR_CTSIF_LSB)
/* LIN break detection flag */
#define USART_ISR_LBDF_LSB      8
#define USART_ISR_LBDF_MASK     (1 << USART_ISR_LBDF_LSB)
/* Transmit data register empty */
#define USART_ISR_TXE_LSB       7
#define USART_ISR_TXE_MASK      (1 << USART_ISR_TXE_LSB)
/* Transmision complete */
#define USART_ISR_TC_LSB        6
#define USART_ISR_TC_MASK       (1 << USART_ISR_TC_LSB)
/* Read data register not empty */
#define USART_ISR_RXNE_LSB      5
#define USART_ISR_RXNE_MASK     (1 << USART_ISR_RXNE_LSB)
/* Idle line detected */
#define USART_ISR_IDLE_LSB      4
#define USART_ISR_IDLE_MASK     (1 << USART_ISR_IDLE_LSB)
/* Overrun error */
#define USART_ISR_ORE_LSB       3
#define USART_ISR_ORE_MASK      (1 << USART_ISR_ORE_LSB)
/* START bit Noise detection flag */
#define USART_ISR_NF_LSB        2
#define USART_ISR_NF_MASK       (1 << USART_ISR_NF_LSB)
/* Framing error */
#define USART_ISR_FE_LSB        1
#define USART_ISR_FE_MASK       (1 << USART_ISR_FE_LSB)
/* Parity error */
#define USART_ISR_PE_LSB        0
#define USART_ISR_PE_MASK       (1 << USART_ISR_PE_LSB)

/*
 * Interrupt flag clear register bits
 */
/* Wakeup from Stop mode clear flag */
#define USART_ISR_WUCF_LSB      20
#define USART_ISR_WUCF_MASK     (1 << USART_ISR_WUCF_LSB)
/* Character match clear flag */
#define USART_ISR_CMCF_LSB      17
#define USART_ISR_CMCF_MASK     (1 << USART_ISR_CMCF_LSB)
/* End of block clear flag */
#define USART_ISR_EOBCF_LSB     12
#define USART_ISR_EOBCF_MASK    (1 << USART_ISR_EOBCF_LSB)
/* Receiver timeout clear flag */
#define USART_ISR_RTOCF_LSB     11
#define USART_ISR_RTOCF_MASK    (1 << USART_ISR_RTOCF_LSB)
/* CTS clear flag */
#define USART_ISR_CTSCF_LSB     9
#define USART_ISR_CTSCF_MASK    (1 << USART_ISR_CTSCF_LSB)
/* LIN break detection clear flag */
#define USART_ISR_LBDCF_LSB     8
#define USART_ISR_LBDCF_MASK    (1 << USART_ISR_LBDCF_LSB)
/* Transmission complete clear flag */
#define USART_ISR_TCCF_LSB      6
#define USART_ISR_TCCF_MASK     (1 << USART_ISR_TCCF_LSB)
/* Idle line detected clear flag */
#define USART_ISR_IDLECF_LSB    4
#define USART_ISR_IDLECF_MASK   (1 << USART_ISR_IDLECF_LSB)
/* Overrun error clear flag */
#define USART_ISR_ORECF_LSB     3
#define USART_ISR_ORECF_MASK    (1 << USART_ISR_ORECF_LSB)
/* Noise detected clear flag */
#define USART_ISR_NCF_LSB       2
#define USART_ISR_NCF_MASK      (1 << USART_ISR_NCF_LSB)
/* Framing error clear flag */
#define USART_ISR_FECF_LSB      1
#define USART_ISR_FECF_MASK     (1 << USART_ISR_FECF_LSB)
/* Parity error clear flag */
#define USART_ISR_PECF_LSB      0
#define USART_ISR_PECF_MASK     (1 << USART_ISR_PECF_LSB)

/*
 * Receive data register bits
 */
/* Receive data value */
#define USART_RDR_RDR_LSB       0
#define USART_RDR_RDR_MSB       8
#define USART_RDR_RDR_MASK      (0x1ff << USART_RDR_RDR_LSB)

/*
 * Transmit data register bits
 */
/* Transmit data value */
#define USART_TDR_TDR_LSB       0
#define USART_TDR_TDR_MSB       8
#define USART_TDR_TDR_MASK      (0x1ff << USART_TDR_TDR_LSB)

#endif /* _USART_H */
