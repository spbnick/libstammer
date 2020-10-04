/*
 * Touch sensing controller
 */

struct tsc {
    unsigned int cr;        /**< Control register */
    unsigned int ier;       /**< Interrupt enable register */
    unsigned int icr;       /**< Interrupt clear register */
    unsigned int isr;       /**< Interrupt status register */
    unsigned int iohcr;     /**< I/O hysteresis control register */
    unsigned int reserved1;
    unsigned int ioascr;    /**< I/O analog switch control register */
    unsigned int reserved2;
    unsigned int ioscr;     /**< I/O sampling control register */
    unsigned int reserved3;
    unsigned int ioccr;     /**< I/O channel control register */
    unsigned int reserved4;
    unsigned int iogcsr;    /**< I/O group control status register */
    union {
        struct {
            unsigned int iog1cr;    /**< I/O group 1 counter register */
            unsigned int iog2cr;    /**< I/O group 2 counter register */
            unsigned int iog3cr;    /**< I/O group 3 counter register */
            unsigned int iog4cr;    /**< I/O group 4 counter register */
            unsigned int iog5cr;    /**< I/O group 5 counter register */
            unsigned int iog6cr;    /**< I/O group 6 counter register */
            unsigned int iog7cr;    /**< I/O group 7 counter register */
            unsigned int iog8cr;    /**< I/O group 8 counter register */
        };
        unsigned int iogxcr[8];     /**< I/O group X counter registers */
    };
};

/** The TSC instance */
#define TSC ((volatile struct tsc *)0x40024000)

/*
 * Control register bits
 */
/* Charge transfer pulse high bits (PGCLK period * (X + 1)) */
#define TSC_CR_CTPH_LSB     28
#define TSC_CR_CTPH_MSB     31
#define TSC_CR_CTPH_MASK    (0xf << TSC_CR_CTPH_LSB)
/* Charge transfer pulse low bits (PGCLK period * (X + 1)) */
#define TSC_CR_CTPL_LSB     24
#define TSC_CR_CTPL_MSB     27
#define TSC_CR_CTPL_MASK    (0xf << TSC_CR_CTPL_LSB)
/* Spread spectrum deviation bits (SSCLK period * (X + 1)) */
#define TSC_CR_SSD_LSB     17
#define TSC_CR_SSD_MSB     23
#define TSC_CR_SSD_MASK    (0x7f << TSC_CR_SSD_LSB)
/* Spread spectrum enable bit */
#define TSC_CR_SSE_LSB     16
#define TSC_CR_SSE_MASK    (1 << TSC_CR_SSE_LSB)
/* Spread spectrum prescaler bit (HCLK frequency / (X + 1)) */
#define TSC_CR_SSPSC_LSB   15
#define TSC_CR_SSPSC_MASK  (1 << TSC_CR_SSPSC_LSB)
/**< Spread spectrum prescaler value */
enum tsc_cr_sspsc_val {
    TSC_CR_SSPSC_VAL_FHCLK,
    TSC_CR_SSPSC_VAL_FHCLK_DIV2
};
/* Pulse generator prescaler bits (HCLK frequency / 2^X) */
#define TSC_CR_PGPSC_LSB    12
#define TSC_CR_PGPSC_MSB    14
#define TSC_CR_PGPSC_MASK   (0x7 << TSC_CR_PGPSC_LSB)
/* Max count value bits (2^(8+X) - 1) */
#define TSC_CR_MCV_LSB      5
#define TSC_CR_MCV_MSB      7
#define TSC_CR_MCV_MASK     (0x7 << TSC_CR_MCV_LSB)
/**< Max count value */
enum tsc_cr_mcv_val {
    TSC_CR_MCV_VAL_255,
    TSC_CR_MCV_VAL_511,
    TSC_CR_MCV_VAL_1023,
    TSC_CR_MCV_VAL_2047,
    TSC_CR_MCV_VAL_4095,
    TSC_CR_MCV_VAL_8191,
    TSC_CR_MCV_VAL_16383,
    TSC_CR_MCV_VAL_RESERVED
};
/* I/O default mode bit */
#define TSC_CR_IODEF_LSB    4
#define TSC_CR_IODEF_MASK   (1 << TSC_CR_IODEF_LSB)
/**< I/O default mode value */
enum tsc_cr_iodef_val {
    TSC_CR_IODEF_VAL_OUTPUT_PUSH_PULL_LOW,
    TSC_CR_IODEF_VAL_INPUT_FLOATING
};
/* Synchronization pin polarity bit */
#define TSC_CR_SYNCPOL_LSB  3
#define TSC_CR_SYNCPOL_MASK (1 << TSC_CR_SYNCPOL_LSB)
/**< Synchronization pin polarity value */
enum tsc_cr_iodef_val {
    TSC_CR_SYNCPOL_VAL_FALLING_EDGE_ONLY,
    TSC_CR_SYNCPOL_VAL_RISING_EDGE_AND_HIGH_LEVEL
};
/* Acquisition mode bit */
#define TSC_CR_AM_LSB   2
#define TSC_CR_AM_MASK  (1 << TSC_CR_AM_LSB)
/**< Acquisition mode value */
enum tsc_cr_iodef_val {
    TSC_CR_AM_VAL_NORMAL,
    TSC_CR_AM_VAL_SYNC
};
/* Start a new acquisition bit */
#define TSC_CR_AM_LSB   1
#define TSC_CR_AM_MASK  (1 << TSC_CR_AM_LSB)
/* Touch sensing controller enable bit */
#define TSC_CR_TSCE_LSB     0
#define TSC_CR_TSCE_MASK    (1 << TSC_CR_TSCE_LSB)

/*
 * Interrupt enable register bits
 */
/* Max count error interrupt enable bit */
#define TSC_IER_MCEIE_LSB   1
#define TSC_IER_MCEIE_MASK  (1 << TSC_IER_MCEIE_LSB)
/* End of acquisition interrupt enable bit */
#define TSC_IER_EOAIE_LSB   0
#define TSC_IER_EOAIE_MASK  (1 << TSC_IER_EOAIE_LSB)

/*
 * Interrupt clear register bits
 */
/* Max count error interrupt clear bit */
#define TSC_ICR_MCEIC_LSB   1
#define TSC_ICR_MCEIC_MASK  (1 << TSC_ICR_MCEIC_LSB)
/* End of acquisition interrupt clear bit */
#define TSC_ICR_EOAIC_LSB   0
#define TSC_ICR_EOAIC_MASK  (1 << TSC_ICR_EOAIC_LSB)

/*
 * Interrupt status register bits
 */
/* Max count error interrupt status bit */
#define TSC_ISR_MCEF_LSB    1
#define TSC_ISR_MCEF_MASK   (1 << TSC_ISR_MCEF_LSB)
/* End of acquisition interrupt status bit */
#define TSC_ISR_EOAF_LSB    0
#define TSC_ISR_EOAF_MASK   (1 << TSC_ISR_EOAF_LSB)

/*
 * I/O hysteresis control register bits
 */
/* Group 1 I/O 1 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G1_IO1_LSB    0
#define TSC_IOHCR_G1_IO1_MASK   (1 << TSC_IOHCR_G1_IO1_LSB)
/* Group 1 I/O 2 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G1_IO2_LSB    1
#define TSC_IOHCR_G1_IO2_MASK   (1 << TSC_IOHCR_G1_IO2_LSB)
/* Group 1 I/O 3 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G1_IO3_LSB    2
#define TSC_IOHCR_G1_IO3_MASK   (1 << TSC_IOHCR_G1_IO3_LSB)
/* Group 1 I/O 4 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G1_IO4_LSB    3
#define TSC_IOHCR_G1_IO4_MASK   (1 << TSC_IOHCR_G1_IO4_LSB)
/* Group 2 I/O 1 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G2_IO1_LSB    4
#define TSC_IOHCR_G2_IO1_MASK   (1 << TSC_IOHCR_G2_IO1_LSB)
/* Group 2 I/O 2 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G2_IO2_LSB    5
#define TSC_IOHCR_G2_IO2_MASK   (1 << TSC_IOHCR_G2_IO2_LSB)
/* Group 2 I/O 3 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G2_IO3_LSB    6
#define TSC_IOHCR_G2_IO3_MASK   (1 << TSC_IOHCR_G2_IO3_LSB)
/* Group 2 I/O 4 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G2_IO4_LSB    7
#define TSC_IOHCR_G2_IO4_MASK   (1 << TSC_IOHCR_G2_IO4_LSB)
/* Group 3 I/O 1 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G3_IO1_LSB    8
#define TSC_IOHCR_G3_IO1_MASK   (1 << TSC_IOHCR_G3_IO1_LSB)
/* Group 3 I/O 2 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G3_IO2_LSB    9
#define TSC_IOHCR_G3_IO2_MASK   (1 << TSC_IOHCR_G3_IO2_LSB)
/* Group 3 I/O 3 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G3_IO3_LSB    10
#define TSC_IOHCR_G3_IO3_MASK   (1 << TSC_IOHCR_G3_IO3_LSB)
/* Group 3 I/O 4 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G3_IO4_LSB    11
#define TSC_IOHCR_G3_IO4_MASK   (1 << TSC_IOHCR_G3_IO4_LSB)
/* Group 4 I/O 1 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G4_IO1_LSB    12
#define TSC_IOHCR_G4_IO1_MASK   (1 << TSC_IOHCR_G4_IO1_LSB)
/* Group 4 I/O 2 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G4_IO2_LSB    13
#define TSC_IOHCR_G4_IO2_MASK   (1 << TSC_IOHCR_G4_IO2_LSB)
/* Group 4 I/O 3 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G4_IO3_LSB    14
#define TSC_IOHCR_G4_IO3_MASK   (1 << TSC_IOHCR_G4_IO3_LSB)
/* Group 4 I/O 4 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G4_IO4_LSB    15
#define TSC_IOHCR_G4_IO4_MASK   (1 << TSC_IOHCR_G4_IO4_LSB)
/* Group 5 I/O 1 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G5_IO1_LSB    16
#define TSC_IOHCR_G5_IO1_MASK   (1 << TSC_IOHCR_G5_IO1_LSB)
/* Group 5 I/O 2 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G5_IO2_LSB    17
#define TSC_IOHCR_G5_IO2_MASK   (1 << TSC_IOHCR_G5_IO2_LSB)
/* Group 5 I/O 3 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G5_IO3_LSB    18
#define TSC_IOHCR_G5_IO3_MASK   (1 << TSC_IOHCR_G5_IO3_LSB)
/* Group 5 I/O 4 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G5_IO4_LSB    19
#define TSC_IOHCR_G5_IO4_MASK   (1 << TSC_IOHCR_G5_IO4_LSB)
/* Group 6 I/O 1 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G6_IO1_LSB    20
#define TSC_IOHCR_G6_IO1_MASK   (1 << TSC_IOHCR_G6_IO1_LSB)
/* Group 6 I/O 2 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G6_IO2_LSB    21
#define TSC_IOHCR_G6_IO2_MASK   (1 << TSC_IOHCR_G6_IO2_LSB)
/* Group 6 I/O 3 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G6_IO3_LSB    22
#define TSC_IOHCR_G6_IO3_MASK   (1 << TSC_IOHCR_G6_IO3_LSB)
/* Group 6 I/O 4 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G6_IO4_LSB    23
#define TSC_IOHCR_G6_IO4_MASK   (1 << TSC_IOHCR_G6_IO4_LSB)
/* Group 7 I/O 1 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G7_IO1_LSB    24
#define TSC_IOHCR_G7_IO1_MASK   (1 << TSC_IOHCR_G7_IO1_LSB)
/* Group 7 I/O 2 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G7_IO2_LSB    25
#define TSC_IOHCR_G7_IO2_MASK   (1 << TSC_IOHCR_G7_IO2_LSB)
/* Group 7 I/O 3 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G7_IO3_LSB    26
#define TSC_IOHCR_G7_IO3_MASK   (1 << TSC_IOHCR_G7_IO3_LSB)
/* Group 7 I/O 4 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G7_IO4_LSB    27
#define TSC_IOHCR_G7_IO4_MASK   (1 << TSC_IOHCR_G7_IO4_LSB)
/* Group 8 I/O 1 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G8_IO1_LSB    28
#define TSC_IOHCR_G8_IO1_MASK   (1 << TSC_IOHCR_G8_IO1_LSB)
/* Group 8 I/O 2 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G8_IO2_LSB    29
#define TSC_IOHCR_G8_IO2_MASK   (1 << TSC_IOHCR_G8_IO2_LSB)
/* Group 8 I/O 3 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G8_IO3_LSB    30
#define TSC_IOHCR_G8_IO3_MASK   (1 << TSC_IOHCR_G8_IO3_LSB)
/* Group 8 I/O 4 Schmitt trigger hysteresis enable bit */
#define TSC_IOHCR_G8_IO4_LSB    31
#define TSC_IOHCR_G8_IO4_MASK   (1 << TSC_IOHCR_G8_IO4_LSB)

/*
 * I/O analog switch control register bits
 */
/* Group 1 I/O 1 analog switch enable bit */
#define TSC_IOASCR_G1_IO1_LSB    0
#define TSC_IOASCR_G1_IO1_MASK   (1 << TSC_IOASCR_G1_IO1_LSB)
/* Group 1 I/O 2 analog switch enable bit */
#define TSC_IOASCR_G1_IO2_LSB    1
#define TSC_IOASCR_G1_IO2_MASK   (1 << TSC_IOASCR_G1_IO2_LSB)
/* Group 1 I/O 3 analog switch enable bit */
#define TSC_IOASCR_G1_IO3_LSB    2
#define TSC_IOASCR_G1_IO3_MASK   (1 << TSC_IOASCR_G1_IO3_LSB)
/* Group 1 I/O 4 analog switch enable bit */
#define TSC_IOASCR_G1_IO4_LSB    3
#define TSC_IOASCR_G1_IO4_MASK   (1 << TSC_IOASCR_G1_IO4_LSB)
/* Group 2 I/O 1 analog switch enable bit */
#define TSC_IOASCR_G2_IO1_LSB    4
#define TSC_IOASCR_G2_IO1_MASK   (1 << TSC_IOASCR_G2_IO1_LSB)
/* Group 2 I/O 2 analog switch enable bit */
#define TSC_IOASCR_G2_IO2_LSB    5
#define TSC_IOASCR_G2_IO2_MASK   (1 << TSC_IOASCR_G2_IO2_LSB)
/* Group 2 I/O 3 analog switch enable bit */
#define TSC_IOASCR_G2_IO3_LSB    6
#define TSC_IOASCR_G2_IO3_MASK   (1 << TSC_IOASCR_G2_IO3_LSB)
/* Group 2 I/O 4 analog switch enable bit */
#define TSC_IOASCR_G2_IO4_LSB    7
#define TSC_IOASCR_G2_IO4_MASK   (1 << TSC_IOASCR_G2_IO4_LSB)
/* Group 3 I/O 1 analog switch enable bit */
#define TSC_IOASCR_G3_IO1_LSB    8
#define TSC_IOASCR_G3_IO1_MASK   (1 << TSC_IOASCR_G3_IO1_LSB)
/* Group 3 I/O 2 analog switch enable bit */
#define TSC_IOASCR_G3_IO2_LSB    9
#define TSC_IOASCR_G3_IO2_MASK   (1 << TSC_IOASCR_G3_IO2_LSB)
/* Group 3 I/O 3 analog switch enable bit */
#define TSC_IOASCR_G3_IO3_LSB    10
#define TSC_IOASCR_G3_IO3_MASK   (1 << TSC_IOASCR_G3_IO3_LSB)
/* Group 3 I/O 4 analog switch enable bit */
#define TSC_IOASCR_G3_IO4_LSB    11
#define TSC_IOASCR_G3_IO4_MASK   (1 << TSC_IOASCR_G3_IO4_LSB)
/* Group 4 I/O 1 analog switch enable bit */
#define TSC_IOASCR_G4_IO1_LSB    12
#define TSC_IOASCR_G4_IO1_MASK   (1 << TSC_IOASCR_G4_IO1_LSB)
/* Group 4 I/O 2 analog switch enable bit */
#define TSC_IOASCR_G4_IO2_LSB    13
#define TSC_IOASCR_G4_IO2_MASK   (1 << TSC_IOASCR_G4_IO2_LSB)
/* Group 4 I/O 3 analog switch enable bit */
#define TSC_IOASCR_G4_IO3_LSB    14
#define TSC_IOASCR_G4_IO3_MASK   (1 << TSC_IOASCR_G4_IO3_LSB)
/* Group 4 I/O 4 analog switch enable bit */
#define TSC_IOASCR_G4_IO4_LSB    15
#define TSC_IOASCR_G4_IO4_MASK   (1 << TSC_IOASCR_G4_IO4_LSB)
/* Group 5 I/O 1 analog switch enable bit */
#define TSC_IOASCR_G5_IO1_LSB    16
#define TSC_IOASCR_G5_IO1_MASK   (1 << TSC_IOASCR_G5_IO1_LSB)
/* Group 5 I/O 2 analog switch enable bit */
#define TSC_IOASCR_G5_IO2_LSB    17
#define TSC_IOASCR_G5_IO2_MASK   (1 << TSC_IOASCR_G5_IO2_LSB)
/* Group 5 I/O 3 analog switch enable bit */
#define TSC_IOASCR_G5_IO3_LSB    18
#define TSC_IOASCR_G5_IO3_MASK   (1 << TSC_IOASCR_G5_IO3_LSB)
/* Group 5 I/O 4 analog switch enable bit */
#define TSC_IOASCR_G5_IO4_LSB    19
#define TSC_IOASCR_G5_IO4_MASK   (1 << TSC_IOASCR_G5_IO4_LSB)
/* Group 6 I/O 1 analog switch enable bit */
#define TSC_IOASCR_G6_IO1_LSB    20
#define TSC_IOASCR_G6_IO1_MASK   (1 << TSC_IOASCR_G6_IO1_LSB)
/* Group 6 I/O 2 analog switch enable bit */
#define TSC_IOASCR_G6_IO2_LSB    21
#define TSC_IOASCR_G6_IO2_MASK   (1 << TSC_IOASCR_G6_IO2_LSB)
/* Group 6 I/O 3 analog switch enable bit */
#define TSC_IOASCR_G6_IO3_LSB    22
#define TSC_IOASCR_G6_IO3_MASK   (1 << TSC_IOASCR_G6_IO3_LSB)
/* Group 6 I/O 4 analog switch enable bit */
#define TSC_IOASCR_G6_IO4_LSB    23
#define TSC_IOASCR_G6_IO4_MASK   (1 << TSC_IOASCR_G6_IO4_LSB)
/* Group 7 I/O 1 analog switch enable bit */
#define TSC_IOASCR_G7_IO1_LSB    24
#define TSC_IOASCR_G7_IO1_MASK   (1 << TSC_IOASCR_G7_IO1_LSB)
/* Group 7 I/O 2 analog switch enable bit */
#define TSC_IOASCR_G7_IO2_LSB    25
#define TSC_IOASCR_G7_IO2_MASK   (1 << TSC_IOASCR_G7_IO2_LSB)
/* Group 7 I/O 3 analog switch enable bit */
#define TSC_IOASCR_G7_IO3_LSB    26
#define TSC_IOASCR_G7_IO3_MASK   (1 << TSC_IOASCR_G7_IO3_LSB)
/* Group 7 I/O 4 analog switch enable bit */
#define TSC_IOASCR_G7_IO4_LSB    27
#define TSC_IOASCR_G7_IO4_MASK   (1 << TSC_IOASCR_G7_IO4_LSB)
/* Group 8 I/O 1 analog switch enable bit */
#define TSC_IOASCR_G8_IO1_LSB    28
#define TSC_IOASCR_G8_IO1_MASK   (1 << TSC_IOASCR_G8_IO1_LSB)
/* Group 8 I/O 2 analog switch enable bit */
#define TSC_IOASCR_G8_IO2_LSB    29
#define TSC_IOASCR_G8_IO2_MASK   (1 << TSC_IOASCR_G8_IO2_LSB)
/* Group 8 I/O 3 analog switch enable bit */
#define TSC_IOASCR_G8_IO3_LSB    30
#define TSC_IOASCR_G8_IO3_MASK   (1 << TSC_IOASCR_G8_IO3_LSB)
/* Group 8 I/O 4 analog switch enable bit */
#define TSC_IOASCR_G8_IO4_LSB    31
#define TSC_IOASCR_G8_IO4_MASK   (1 << TSC_IOASCR_G8_IO4_LSB)

/*
 * I/O sampling control register bits
 */
/* Group 1 I/O 1 use as sampling capacitor bit */
#define TSC_IOSCR_G1_IO1_LSB    0
#define TSC_IOSCR_G1_IO1_MASK   (1 << TSC_IOSCR_G1_IO1_LSB)
/* Group 1 I/O 2 use as sampling capacitor bit */
#define TSC_IOSCR_G1_IO2_LSB    1
#define TSC_IOSCR_G1_IO2_MASK   (1 << TSC_IOSCR_G1_IO2_LSB)
/* Group 1 I/O 3 use as sampling capacitor bit */
#define TSC_IOSCR_G1_IO3_LSB    2
#define TSC_IOSCR_G1_IO3_MASK   (1 << TSC_IOSCR_G1_IO3_LSB)
/* Group 1 I/O 4 use as sampling capacitor bit */
#define TSC_IOSCR_G1_IO4_LSB    3
#define TSC_IOSCR_G1_IO4_MASK   (1 << TSC_IOSCR_G1_IO4_LSB)
/* Group 2 I/O 1 use as sampling capacitor bit */
#define TSC_IOSCR_G2_IO1_LSB    4
#define TSC_IOSCR_G2_IO1_MASK   (1 << TSC_IOSCR_G2_IO1_LSB)
/* Group 2 I/O 2 use as sampling capacitor bit */
#define TSC_IOSCR_G2_IO2_LSB    5
#define TSC_IOSCR_G2_IO2_MASK   (1 << TSC_IOSCR_G2_IO2_LSB)
/* Group 2 I/O 3 use as sampling capacitor bit */
#define TSC_IOSCR_G2_IO3_LSB    6
#define TSC_IOSCR_G2_IO3_MASK   (1 << TSC_IOSCR_G2_IO3_LSB)
/* Group 2 I/O 4 use as sampling capacitor bit */
#define TSC_IOSCR_G2_IO4_LSB    7
#define TSC_IOSCR_G2_IO4_MASK   (1 << TSC_IOSCR_G2_IO4_LSB)
/* Group 3 I/O 1 use as sampling capacitor bit */
#define TSC_IOSCR_G3_IO1_LSB    8
#define TSC_IOSCR_G3_IO1_MASK   (1 << TSC_IOSCR_G3_IO1_LSB)
/* Group 3 I/O 2 use as sampling capacitor bit */
#define TSC_IOSCR_G3_IO2_LSB    9
#define TSC_IOSCR_G3_IO2_MASK   (1 << TSC_IOSCR_G3_IO2_LSB)
/* Group 3 I/O 3 use as sampling capacitor bit */
#define TSC_IOSCR_G3_IO3_LSB    10
#define TSC_IOSCR_G3_IO3_MASK   (1 << TSC_IOSCR_G3_IO3_LSB)
/* Group 3 I/O 4 use as sampling capacitor bit */
#define TSC_IOSCR_G3_IO4_LSB    11
#define TSC_IOSCR_G3_IO4_MASK   (1 << TSC_IOSCR_G3_IO4_LSB)
/* Group 4 I/O 1 use as sampling capacitor bit */
#define TSC_IOSCR_G4_IO1_LSB    12
#define TSC_IOSCR_G4_IO1_MASK   (1 << TSC_IOSCR_G4_IO1_LSB)
/* Group 4 I/O 2 use as sampling capacitor bit */
#define TSC_IOSCR_G4_IO2_LSB    13
#define TSC_IOSCR_G4_IO2_MASK   (1 << TSC_IOSCR_G4_IO2_LSB)
/* Group 4 I/O 3 use as sampling capacitor bit */
#define TSC_IOSCR_G4_IO3_LSB    14
#define TSC_IOSCR_G4_IO3_MASK   (1 << TSC_IOSCR_G4_IO3_LSB)
/* Group 4 I/O 4 use as sampling capacitor bit */
#define TSC_IOSCR_G4_IO4_LSB    15
#define TSC_IOSCR_G4_IO4_MASK   (1 << TSC_IOSCR_G4_IO4_LSB)
/* Group 5 I/O 1 use as sampling capacitor bit */
#define TSC_IOSCR_G5_IO1_LSB    16
#define TSC_IOSCR_G5_IO1_MASK   (1 << TSC_IOSCR_G5_IO1_LSB)
/* Group 5 I/O 2 use as sampling capacitor bit */
#define TSC_IOSCR_G5_IO2_LSB    17
#define TSC_IOSCR_G5_IO2_MASK   (1 << TSC_IOSCR_G5_IO2_LSB)
/* Group 5 I/O 3 use as sampling capacitor bit */
#define TSC_IOSCR_G5_IO3_LSB    18
#define TSC_IOSCR_G5_IO3_MASK   (1 << TSC_IOSCR_G5_IO3_LSB)
/* Group 5 I/O 4 use as sampling capacitor bit */
#define TSC_IOSCR_G5_IO4_LSB    19
#define TSC_IOSCR_G5_IO4_MASK   (1 << TSC_IOSCR_G5_IO4_LSB)
/* Group 6 I/O 1 use as sampling capacitor bit */
#define TSC_IOSCR_G6_IO1_LSB    20
#define TSC_IOSCR_G6_IO1_MASK   (1 << TSC_IOSCR_G6_IO1_LSB)
/* Group 6 I/O 2 use as sampling capacitor bit */
#define TSC_IOSCR_G6_IO2_LSB    21
#define TSC_IOSCR_G6_IO2_MASK   (1 << TSC_IOSCR_G6_IO2_LSB)
/* Group 6 I/O 3 use as sampling capacitor bit */
#define TSC_IOSCR_G6_IO3_LSB    22
#define TSC_IOSCR_G6_IO3_MASK   (1 << TSC_IOSCR_G6_IO3_LSB)
/* Group 6 I/O 4 use as sampling capacitor bit */
#define TSC_IOSCR_G6_IO4_LSB    23
#define TSC_IOSCR_G6_IO4_MASK   (1 << TSC_IOSCR_G6_IO4_LSB)
/* Group 7 I/O 1 use as sampling capacitor bit */
#define TSC_IOSCR_G7_IO1_LSB    24
#define TSC_IOSCR_G7_IO1_MASK   (1 << TSC_IOSCR_G7_IO1_LSB)
/* Group 7 I/O 2 use as sampling capacitor bit */
#define TSC_IOSCR_G7_IO2_LSB    25
#define TSC_IOSCR_G7_IO2_MASK   (1 << TSC_IOSCR_G7_IO2_LSB)
/* Group 7 I/O 3 use as sampling capacitor bit */
#define TSC_IOSCR_G7_IO3_LSB    26
#define TSC_IOSCR_G7_IO3_MASK   (1 << TSC_IOSCR_G7_IO3_LSB)
/* Group 7 I/O 4 use as sampling capacitor bit */
#define TSC_IOSCR_G7_IO4_LSB    27
#define TSC_IOSCR_G7_IO4_MASK   (1 << TSC_IOSCR_G7_IO4_LSB)
/* Group 8 I/O 1 use as sampling capacitor bit */
#define TSC_IOSCR_G8_IO1_LSB    28
#define TSC_IOSCR_G8_IO1_MASK   (1 << TSC_IOSCR_G8_IO1_LSB)
/* Group 8 I/O 2 use as sampling capacitor bit */
#define TSC_IOSCR_G8_IO2_LSB    29
#define TSC_IOSCR_G8_IO2_MASK   (1 << TSC_IOSCR_G8_IO2_LSB)
/* Group 8 I/O 3 use as sampling capacitor bit */
#define TSC_IOSCR_G8_IO3_LSB    30
#define TSC_IOSCR_G8_IO3_MASK   (1 << TSC_IOSCR_G8_IO3_LSB)
/* Group 8 I/O 4 use as sampling capacitor bit */
#define TSC_IOSCR_G8_IO4_LSB    31
#define TSC_IOSCR_G8_IO4_MASK   (1 << TSC_IOSCR_G8_IO4_LSB)

/*
 * I/O channel control register bits
 */
/* Group 1 I/O 1 use as channel bit */
#define TSC_IOCCR_G1_IO1_LSB    0
#define TSC_IOCCR_G1_IO1_MASK   (1 << TSC_IOCCR_G1_IO1_LSB)
/* Group 1 I/O 2 use as channel bit */
#define TSC_IOCCR_G1_IO2_LSB    1
#define TSC_IOCCR_G1_IO2_MASK   (1 << TSC_IOCCR_G1_IO2_LSB)
/* Group 1 I/O 3 use as channel bit */
#define TSC_IOCCR_G1_IO3_LSB    2
#define TSC_IOCCR_G1_IO3_MASK   (1 << TSC_IOCCR_G1_IO3_LSB)
/* Group 1 I/O 4 use as channel bit */
#define TSC_IOCCR_G1_IO4_LSB    3
#define TSC_IOCCR_G1_IO4_MASK   (1 << TSC_IOCCR_G1_IO4_LSB)
/* Group 2 I/O 1 use as channel bit */
#define TSC_IOCCR_G2_IO1_LSB    4
#define TSC_IOCCR_G2_IO1_MASK   (1 << TSC_IOCCR_G2_IO1_LSB)
/* Group 2 I/O 2 use as channel bit */
#define TSC_IOCCR_G2_IO2_LSB    5
#define TSC_IOCCR_G2_IO2_MASK   (1 << TSC_IOCCR_G2_IO2_LSB)
/* Group 2 I/O 3 use as channel bit */
#define TSC_IOCCR_G2_IO3_LSB    6
#define TSC_IOCCR_G2_IO3_MASK   (1 << TSC_IOCCR_G2_IO3_LSB)
/* Group 2 I/O 4 use as channel bit */
#define TSC_IOCCR_G2_IO4_LSB    7
#define TSC_IOCCR_G2_IO4_MASK   (1 << TSC_IOCCR_G2_IO4_LSB)
/* Group 3 I/O 1 use as channel bit */
#define TSC_IOCCR_G3_IO1_LSB    8
#define TSC_IOCCR_G3_IO1_MASK   (1 << TSC_IOCCR_G3_IO1_LSB)
/* Group 3 I/O 2 use as channel bit */
#define TSC_IOCCR_G3_IO2_LSB    9
#define TSC_IOCCR_G3_IO2_MASK   (1 << TSC_IOCCR_G3_IO2_LSB)
/* Group 3 I/O 3 use as channel bit */
#define TSC_IOCCR_G3_IO3_LSB    10
#define TSC_IOCCR_G3_IO3_MASK   (1 << TSC_IOCCR_G3_IO3_LSB)
/* Group 3 I/O 4 use as channel bit */
#define TSC_IOCCR_G3_IO4_LSB    11
#define TSC_IOCCR_G3_IO4_MASK   (1 << TSC_IOCCR_G3_IO4_LSB)
/* Group 4 I/O 1 use as channel bit */
#define TSC_IOCCR_G4_IO1_LSB    12
#define TSC_IOCCR_G4_IO1_MASK   (1 << TSC_IOCCR_G4_IO1_LSB)
/* Group 4 I/O 2 use as channel bit */
#define TSC_IOCCR_G4_IO2_LSB    13
#define TSC_IOCCR_G4_IO2_MASK   (1 << TSC_IOCCR_G4_IO2_LSB)
/* Group 4 I/O 3 use as channel bit */
#define TSC_IOCCR_G4_IO3_LSB    14
#define TSC_IOCCR_G4_IO3_MASK   (1 << TSC_IOCCR_G4_IO3_LSB)
/* Group 4 I/O 4 use as channel bit */
#define TSC_IOCCR_G4_IO4_LSB    15
#define TSC_IOCCR_G4_IO4_MASK   (1 << TSC_IOCCR_G4_IO4_LSB)
/* Group 5 I/O 1 use as channel bit */
#define TSC_IOCCR_G5_IO1_LSB    16
#define TSC_IOCCR_G5_IO1_MASK   (1 << TSC_IOCCR_G5_IO1_LSB)
/* Group 5 I/O 2 use as channel bit */
#define TSC_IOCCR_G5_IO2_LSB    17
#define TSC_IOCCR_G5_IO2_MASK   (1 << TSC_IOCCR_G5_IO2_LSB)
/* Group 5 I/O 3 use as channel bit */
#define TSC_IOCCR_G5_IO3_LSB    18
#define TSC_IOCCR_G5_IO3_MASK   (1 << TSC_IOCCR_G5_IO3_LSB)
/* Group 5 I/O 4 use as channel bit */
#define TSC_IOCCR_G5_IO4_LSB    19
#define TSC_IOCCR_G5_IO4_MASK   (1 << TSC_IOCCR_G5_IO4_LSB)
/* Group 6 I/O 1 use as channel bit */
#define TSC_IOCCR_G6_IO1_LSB    20
#define TSC_IOCCR_G6_IO1_MASK   (1 << TSC_IOCCR_G6_IO1_LSB)
/* Group 6 I/O 2 use as channel bit */
#define TSC_IOCCR_G6_IO2_LSB    21
#define TSC_IOCCR_G6_IO2_MASK   (1 << TSC_IOCCR_G6_IO2_LSB)
/* Group 6 I/O 3 use as channel bit */
#define TSC_IOCCR_G6_IO3_LSB    22
#define TSC_IOCCR_G6_IO3_MASK   (1 << TSC_IOCCR_G6_IO3_LSB)
/* Group 6 I/O 4 use as channel bit */
#define TSC_IOCCR_G6_IO4_LSB    23
#define TSC_IOCCR_G6_IO4_MASK   (1 << TSC_IOCCR_G6_IO4_LSB)
/* Group 7 I/O 1 use as channel bit */
#define TSC_IOCCR_G7_IO1_LSB    24
#define TSC_IOCCR_G7_IO1_MASK   (1 << TSC_IOCCR_G7_IO1_LSB)
/* Group 7 I/O 2 use as channel bit */
#define TSC_IOCCR_G7_IO2_LSB    25
#define TSC_IOCCR_G7_IO2_MASK   (1 << TSC_IOCCR_G7_IO2_LSB)
/* Group 7 I/O 3 use as channel bit */
#define TSC_IOCCR_G7_IO3_LSB    26
#define TSC_IOCCR_G7_IO3_MASK   (1 << TSC_IOCCR_G7_IO3_LSB)
/* Group 7 I/O 4 use as channel bit */
#define TSC_IOCCR_G7_IO4_LSB    27
#define TSC_IOCCR_G7_IO4_MASK   (1 << TSC_IOCCR_G7_IO4_LSB)
/* Group 8 I/O 1 use as channel bit */
#define TSC_IOCCR_G8_IO1_LSB    28
#define TSC_IOCCR_G8_IO1_MASK   (1 << TSC_IOCCR_G8_IO1_LSB)
/* Group 8 I/O 2 use as channel bit */
#define TSC_IOCCR_G8_IO2_LSB    29
#define TSC_IOCCR_G8_IO2_MASK   (1 << TSC_IOCCR_G8_IO2_LSB)
/* Group 8 I/O 3 use as channel bit */
#define TSC_IOCCR_G8_IO3_LSB    30
#define TSC_IOCCR_G8_IO3_MASK   (1 << TSC_IOCCR_G8_IO3_LSB)
/* Group 8 I/O 4 use as channel bit */
#define TSC_IOCCR_G8_IO4_LSB    31
#define TSC_IOCCR_G8_IO4_MASK   (1 << TSC_IOCCR_G8_IO4_LSB)

/*
 * I/O group control status register bits
 */
/* Analog I/O group 1 enable */
#define TSC_IOGCSR_G1E_LSB  0
#define TSC_IOGCSR_G1E_MASK (1 << TSC_IOGCSR_G1E_LSB)
/* Analog I/O group 2 enable */
#define TSC_IOGCSR_G2E_LSB  1
#define TSC_IOGCSR_G2E_MASK (1 << TSC_IOGCSR_G2E_LSB)
/* Analog I/O group 3 enable */
#define TSC_IOGCSR_G3E_LSB  2
#define TSC_IOGCSR_G3E_MASK (1 << TSC_IOGCSR_G3E_LSB)
/* Analog I/O group 4 enable */
#define TSC_IOGCSR_G4E_LSB  3
#define TSC_IOGCSR_G4E_MASK (1 << TSC_IOGCSR_G4E_LSB)
/* Analog I/O group 5 enable */
#define TSC_IOGCSR_G5E_LSB  4
#define TSC_IOGCSR_G5E_MASK (1 << TSC_IOGCSR_G5E_LSB)
/* Analog I/O group 6 enable */
#define TSC_IOGCSR_G6E_LSB  5
#define TSC_IOGCSR_G6E_MASK (1 << TSC_IOGCSR_G6E_LSB)
/* Analog I/O group 7 enable */
#define TSC_IOGCSR_G7E_LSB  6
#define TSC_IOGCSR_G7E_MASK (1 << TSC_IOGCSR_G7E_LSB)
/* Analog I/O group 8 enable */
#define TSC_IOGCSR_G8E_LSB  7
#define TSC_IOGCSR_G8E_MASK (1 << TSC_IOGCSR_G8E_LSB)

/* Analog I/O group 1 status */
#define TSC_IOGCSR_G1S_LSB  16
#define TSC_IOGCSR_G1S_MASK (1 << TSC_IOGCSR_G1S_LSB)
/* Analog I/O group 2 status */
#define TSC_IOGCSR_G2S_LSB  17
#define TSC_IOGCSR_G2S_MASK (1 << TSC_IOGCSR_G2S_LSB)
/* Analog I/O group 3 status */
#define TSC_IOGCSR_G3S_LSB  18
#define TSC_IOGCSR_G3S_MASK (1 << TSC_IOGCSR_G3S_LSB)
/* Analog I/O group 4 status */
#define TSC_IOGCSR_G4S_LSB  19
#define TSC_IOGCSR_G4S_MASK (1 << TSC_IOGCSR_G4S_LSB)
/* Analog I/O group 5 status */
#define TSC_IOGCSR_G5S_LSB  20
#define TSC_IOGCSR_G5S_MASK (1 << TSC_IOGCSR_G5S_LSB)
/* Analog I/O group 6 status */
#define TSC_IOGCSR_G6S_LSB  21
#define TSC_IOGCSR_G6S_MASK (1 << TSC_IOGCSR_G6S_LSB)
/* Analog I/O group 7 status */
#define TSC_IOGCSR_G7S_LSB  22
#define TSC_IOGCSR_G7S_MASK (1 << TSC_IOGCSR_G7S_LSB)
/* Analog I/O group 8 status */
#define TSC_IOGCSR_G8S_LSB  23
#define TSC_IOGCSR_G8S_MASK (1 << TSC_IOGCSR_G8S_LSB)
