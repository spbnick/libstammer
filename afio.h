/*
 * AFIO (Alternate function I/O)
 */

#ifndef _AFIO_H
#define _AFIO_H

#include <misc.h>

/** AFIO */
struct afio {
    /** Event control register */
    unsigned int evcr;
    /** AF remap and debug I/O configuration register */
    unsigned int mapr;
    /** External interrupt configuration registers */
    unsigned int exticr[4];
    /** AF remap and debug I/O configuration register 2 */
    unsigned int mapr2;
};

/** AFIO instance */
#define AFIO  ((volatile struct afio *)0x40010000)

/*
 * Event control register low bits
 */
/* Pin selection */
#define AFIO_EVCR_PIN_LSB   0
#define AFIO_EVCR_PIN_MSB   3
#define AFIO_EVCR_PIN_MASK  (0xf << AFIO_EVCR_PIN_LSB)
/* Port selection */
#define AFIO_EVCR_PORT_LSB  4
#define AFIO_EVCR_PORT_MSB  6
#define AFIO_EVCR_PORT_MASK (0x3 << AFIO_EVCR_PORT_LSB)
enum afio_evcr_port_val {
    AFIO_EVCR_PORT_VAL_A,
    AFIO_EVCR_PORT_VAL_B,
    AFIO_EVCR_PORT_VAL_C,
    AFIO_EVCR_PORT_VAL_D,
    AFIO_EVCR_PORT_VAL_E
};
/* Event output enable */
#define AFIO_EVCR_EVOE_LSB  7
#define AFIO_EVCR_EVOE_MASK (1 << AFIO_EVCR_EVOE_LSB)

/*
 * AF remap and debug I/O configuration register bits
 */
/* SPI1 remapping */
#define AFIO_MAPR_SPI1_REMAP_LSB    0
#define AFIO_MAPR_SPI1_REMAP_MASK   (1 << AFIO_MAPR_SPI1_REMAP_LSB)
/* I2C1 remapping */
#define AFIO_MAPR_I2C1_REMAP_LSB    1
#define AFIO_MAPR_I2C1_REMAP_MASK   (1 << AFIO_MAPR_I2C1_REMAP_LSB)
/* USART1 remapping */
#define AFIO_MAPR_USART1_REMAP_LSB  2
#define AFIO_MAPR_USART1_REMAP_MASK (1 << AFIO_MAPR_USART1_REMAP_LSB)
/* USART2 remapping */
#define AFIO_MAPR_USART2_REMAP_LSB  3
#define AFIO_MAPR_USART2_REMAP_MASK (1 << AFIO_MAPR_USART2_REMAP_LSB)
/* USART3 remapping */
#define AFIO_MAPR_USART3_REMAP_LSB          4
#define AFIO_MAPR_USART3_REMAP_MSB          5
#define AFIO_MAPR_USART3_REMAP_MASK         (0x3 << AFIO_MAPR_USART3_REMAP_LSB)
#define AFIO_MAPR_USART3_REMAP_VAL_NO       0
#define AFIO_MAPR_USART3_REMAP_VAL_PARTIAL  1
#define AFIO_MAPR_USART3_REMAP_VAL_FULL     3
/* TIM1 remapping */
#define AFIO_MAPR_TIM1_REMAP_LSB            6
#define AFIO_MAPR_TIM1_REMAP_MSB            7
#define AFIO_MAPR_TIM1_REMAP_MASK           (0x3 << AFIO_MAPR_TIM1_REMAP_LSB)
#define AFIO_MAPR_TIM1_REMAP_VAL_NO         0
#define AFIO_MAPR_TIM1_REMAP_VAL_PARTIAL    1
#define AFIO_MAPR_TIM1_REMAP_VAL_FULL       3
/* TIM2 remapping */
#define AFIO_MAPR_TIM2_REMAP_LSB            8
#define AFIO_MAPR_TIM2_REMAP_MSB            9
#define AFIO_MAPR_TIM2_REMAP_MASK           (0x3 << AFIO_MAPR_TIM2_REMAP_LSB)
#define AFIO_MAPR_TIM2_REMAP_VAL_NO         0
#define AFIO_MAPR_TIM2_REMAP_VAL_PARTIAL1   1
#define AFIO_MAPR_TIM2_REMAP_VAL_PARTIAL2   2
#define AFIO_MAPR_TIM2_REMAP_VAL_FULL       3
/* TIM3 remapping */
#define AFIO_MAPR_TIM3_REMAP_LSB            10
#define AFIO_MAPR_TIM3_REMAP_MSB            11
#define AFIO_MAPR_TIM3_REMAP_MASK           (0x3 << AFIO_MAPR_TIM3_REMAP_LSB)
#define AFIO_MAPR_TIM3_REMAP_VAL_NO         0
#define AFIO_MAPR_TIM3_REMAP_VAL_PARTIAL    2
#define AFIO_MAPR_TIM3_REMAP_VAL_FULL       3
/* TIM4 remapping */
#define AFIO_MAPR_TIM4_REMAP_LSB    12
#define AFIO_MAPR_TIM4_REMAP_MASK   (1 << AFIO_MAPR_TIM4_REMAP_LSB)
/* CAN alternate function remapping */
#define AFIO_MAPR_CAN_REMAP_LSB         13
#define AFIO_MAPR_CAN_REMAP_MSB         14
#define AFIO_MAPR_CAN_REMAP_MASK        (0x3 << AFIO_MAPR_CAN_REMAP_LSB)
#define AFIO_MAPR_CAN_REMAP_VAL_RX_PA11_TX_PA12 0
#define AFIO_MAPR_CAN_REMAP_VAL_RX_PB8_TX_PB9   2
#define AFIO_MAPR_CAN_REMAP_VAL_RX_PD0_TX_PD1   3
/* Port D0/Port D1 mapping on OSC_IN/OSC_OUT */
#define AFIO_MAPR_PD01_REMAP_LSB    15
#define AFIO_MAPR_PD01_REMAP_MASK   (1 << AFIO_MAPR_PD01_REMAP_LSB)
/* TIM5 channel4 internal remap */
#define AFIO_MAPR_TIM5CH4_IREMAP_LSB    16
#define AFIO_MAPR_TIM5CH4_IREMAP_MASK   (1 << AFIO_MAPR_TIM5CH4_IREMAP_LSB)
#define AFIO_MAPR_TIM5CH4_IREMAP_VAL_PA3    0
#define AFIO_MAPR_TIM5CH4_IREMAP_VAL_LSI_CK 1
/* ADC 1 external trigger injected conversion remapping */
#define AFIO_MAPR_ADC1_ETRGINJ_REMAP_LSB     17
#define AFIO_MAPR_ADC1_ETRGINJ_REMAP_MASK    (1 << AFIO_MAPR_ADC1_ETRGINJ_REMAP_LSB)
#define AFIO_MAPR_ADC1_ETRGINJ_REMAP_VAL_EXTI15  0
#define AFIO_MAPR_ADC1_ETRGINJ_REMAP_VAL_TIM8CH4 1
/* ADC 1 external trigger regular conversion remapping */
#define AFIO_MAPR_ADC1_ETRGREG_REMAP_LSB     18
#define AFIO_MAPR_ADC1_ETRGREG_REMAP_MASK    (1 << AFIO_MAPR_ADC1_ETRGREG_REMAP_LSB)
#define AFIO_MAPR_ADC1_ETRGREG_REMAP_VAL_EXTI11      0
#define AFIO_MAPR_ADC1_ETRGREG_REMAP_VAL_TIM8TRG0    1
/* ADC 2 external trigger injected conversion remapping */
#define AFIO_MAPR_ADC2_ETRGINJ_REMAP_LSB     19
#define AFIO_MAPR_ADC2_ETRGINJ_REMAP_MASK    (1 << AFIO_MAPR_ADC2_ETRGINJ_REMAP_LSB)
#define AFIO_MAPR_ADC2_ETRGINJ_REMAP_VAL_EXTI15  0
#define AFIO_MAPR_ADC2_ETRGINJ_REMAP_VAL_TIM8CH4 1
/* ADC 2 external trigger regular conversion remapping */
#define AFIO_MAPR_ADC2_ETRGREG_REMAP_LSB     20
#define AFIO_MAPR_ADC2_ETRGREG_REMAP_MASK    (1 << AFIO_MAPR_ADC2_ETRGREG_REMAP_LSB)
#define AFIO_MAPR_ADC2_ETRGREG_REMAP_VAL_EXTI11      0
#define AFIO_MAPR_ADC2_ETRGREG_REMAP_VAL_TIM8TRG0    1
/* Serial wire JTAG configuration */
#define AFIO_MAPR_SWJ_CFG_LSB                   24
#define AFIO_MAPR_SWJ_CFG_MSB                   26
#define AFIO_MAPR_SWJ_CFG_MASK                  (0x7 << AFIO_MAPR_SWJ_CFG_LSB)
#define AFIO_MAPR_SWJ_CFG_VAL_FULL_SWJ              0
#define AFIO_MAPR_SWJ_CFG_VAL_FULL_SWJ_NO_NJTRST    1
#define AFIO_MAPR_SWJ_CFG_VAL_JTAG_DP_OFF_SW_DP_ON  2
#define AFIO_MAPR_SWJ_CFG_VAL_JTAG_DP_OFF_SW_DP_OFF 4

/*
 * AF remap and debug I/O configuration register 2 bits
 */
/* TIM9 remapping */
#define AFIO_MAPR2_TIM9_REMAP_LSB   5
#define AFIO_MAPR2_TIM9_REMAP_MASK  (1 << AFIO_MAPR2_TIM9_REMAP_LSB)
/* TIM10 remapping */
#define AFIO_MAPR2_TIM10_REMAP_LSB  6
#define AFIO_MAPR2_TIM10_REMAP_MASK (1 << AFIO_MAPR2_TIM10_REMAP_LSB)
/* TIM11 remapping */
#define AFIO_MAPR2_TIM11_REMAP_LSB  7
#define AFIO_MAPR2_TIM11_REMAP_MASK (1 << AFIO_MAPR2_TIM11_REMAP_LSB)
/* TIM13 remapping */
#define AFIO_MAPR2_TIM13_REMAP_LSB  8
#define AFIO_MAPR2_TIM13_REMAP_MASK (1 << AFIO_MAPR2_TIM13_REMAP_LSB)
/* TIM14 remapping */
#define AFIO_MAPR2_TIM14_REMAP_LSB  9
#define AFIO_MAPR2_TIM14_REMAP_MASK (1 << AFIO_MAPR2_TIM14_REMAP_LSB)
/* NADV connect/disconnect */
#define AFIO_MAPR2_FSMC_NADV_LSB    10
#define AFIO_MAPR2_FSMC_NADV_MASK   (1 << AFIO_MAPR2_FSMC_NADV_LSB)
#define AFIO_MAPR2_FSMC_NADV_VAL_CONN   0
#define AFIO_MAPR2_FSMC_NADV_VAL_NOCONN 1

/**
 * External interrupt port
 */
enum afio_exti_port {
    AFIO_EXTI_PORT_A,
    AFIO_EXTI_PORT_B,
    AFIO_EXTI_PORT_C,
    AFIO_EXTI_PORT_D,
    AFIO_EXTI_PORT_E,
    AFIO_EXTI_PORT_F,
    AFIO_EXTI_PORT_G,
    /** Number of possible ports, not an actual port */
    AFIO_EXTI_PORT_NUM
};

/**
 * Select the source port for an external interrupt line/pin number.
 *
 * @param num   The port pin/interrupt line number to assign the port to.
 *              Must be less than 16.
 * @param port  The port to route the interrupt from.
 */
static inline void
afio_exti_set_port(uint8_t num, enum afio_exti_port port)
{
    size_t reg = num >> 2;
    size_t lsb = (num & 3) << 2;
    assert(num < 16);
    assert(port < AFIO_EXTI_PORT_NUM);
    AFIO->exticr[reg] = (AFIO->exticr[reg] & (0x7 << lsb)) | (port << lsb);
}

#endif /* _AFIO_H */
