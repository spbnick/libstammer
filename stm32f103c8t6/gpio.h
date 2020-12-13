/*
 * GPIO
 */

#ifndef _STM32F103C8T6_GPIO_H
#define _STM32F103C8T6_GPIO_H

/** GPIO */
struct gpio {
    unsigned int crl;   /**< Configuration register low */
    unsigned int crh;   /**< Configuration register high */
    unsigned int idr;   /**< Input data register */
    unsigned int odr;   /**< Output data register */
    unsigned int bsrr;  /**< Bit set/reset register */
    unsigned int brr;   /**< Bit reset register */
    unsigned int lckr;  /**< Configuration lock register */
};

/** GPIO port A */
#define GPIO_A  ((volatile struct gpio *)0x40010800)
/** GPIO port B */
#define GPIO_B  ((volatile struct gpio *)0x40010c00)
/** GPIO port C */
#define GPIO_C  ((volatile struct gpio *)0x40011000)
/** GPIO port D */
#define GPIO_D  ((volatile struct gpio *)0x40014000)
/** GPIO port E */
#define GPIO_E  ((volatile struct gpio *)0x40018000)

/*
 * Port configuration register low bits
 */
/* Port 0 mode bits */
#define GPIO_CRL_MODE0_LSB  0
#define GPIO_CRL_MODE0_MSB  1
#define GPIO_CRL_MODE0_MASK (3 << GPIO_CRL_MODE0_LSB)
/* Port 0 configuration bits */
#define GPIO_CRL_CNF0_LSB   2
#define GPIO_CRL_CNF0_MSB   3
#define GPIO_CRL_CNF0_MASK  (3 << GPIO_CRL_CNF0_LSB)
/* Port 1 mode bits */
#define GPIO_CRL_MODE1_LSB  4
#define GPIO_CRL_MODE1_MSB  5
#define GPIO_CRL_MODE1_MASK (3 << GPIO_CRL_MODE1_LSB)
/* Port 1 configuration bits */
#define GPIO_CRL_CNF1_LSB   6
#define GPIO_CRL_CNF1_MSB   7
#define GPIO_CRL_CNF1_MASK  (3 << GPIO_CRL_CNF1_LSB)
/* Port 2 mode bits */
#define GPIO_CRL_MODE2_LSB  8
#define GPIO_CRL_MODE2_MSB  9
#define GPIO_CRL_MODE2_MASK (3 << GPIO_CRL_MODE2_LSB)
/* Port 2 configuration bits */
#define GPIO_CRL_CNF2_LSB   10
#define GPIO_CRL_CNF2_MSB   11
#define GPIO_CRL_CNF2_MASK  (3 << GPIO_CRL_CNF2_LSB)
/* Port 3 mode bits */
#define GPIO_CRL_MODE3_LSB  12
#define GPIO_CRL_MODE3_MSB  13
#define GPIO_CRL_MODE3_MASK (3 << GPIO_CRL_MODE3_LSB)
/* Port 3 configuration bits */
#define GPIO_CRL_CNF3_LSB   14
#define GPIO_CRL_CNF3_MSB   15
#define GPIO_CRL_CNF3_MASK  (3 << GPIO_CRL_CNF3_LSB)
/* Port 4 mode bits */
#define GPIO_CRL_MODE4_LSB  16
#define GPIO_CRL_MODE4_MSB  17
#define GPIO_CRL_MODE4_MASK (3 << GPIO_CRL_MODE4_LSB)
/* Port 4 configuration bits */
#define GPIO_CRL_CNF4_LSB   18
#define GPIO_CRL_CNF4_MSB   19
#define GPIO_CRL_CNF4_MASK  (3 << GPIO_CRL_CNF4_LSB)
/* Port 5 mode bits */
#define GPIO_CRL_MODE5_LSB  20
#define GPIO_CRL_MODE5_MSB  21
#define GPIO_CRL_MODE5_MASK (3 << GPIO_CRL_MODE5_LSB)
/* Port 5 configuration bits */
#define GPIO_CRL_CNF5_LSB   22
#define GPIO_CRL_CNF5_MSB   23
#define GPIO_CRL_CNF5_MASK  (3 << GPIO_CRL_CNF5_LSB)
/* Port 6 mode bits */
#define GPIO_CRL_MODE6_LSB  24
#define GPIO_CRL_MODE6_MSB  25
#define GPIO_CRL_MODE6_MASK (3 << GPIO_CRL_MODE6_LSB)
/* Port 6 configuration bits */
#define GPIO_CRL_CNF6_LSB   26
#define GPIO_CRL_CNF6_MSB   27
#define GPIO_CRL_CNF6_MASK  (3 << GPIO_CRL_CNF6_LSB)
/* Port 7 mode bits */
#define GPIO_CRL_MODE7_LSB  28
#define GPIO_CRL_MODE7_MSB  29
#define GPIO_CRL_MODE7_MASK (3 << GPIO_CRL_MODE7_LSB)
/* Port 7 configuration bits */
#define GPIO_CRL_CNF7_LSB   30
#define GPIO_CRL_CNF7_MSB   31
#define GPIO_CRL_CNF7_MASK  (3 << GPIO_CRL_CNF7_LSB)

/*
 * Port configuration register high bits
 */
/* Port 8 mode bits */
#define GPIO_CRH_MODE8_LSB  0
#define GPIO_CRH_MODE8_MSB  1
#define GPIO_CRH_MODE8_MASK (3 << GPIO_CRH_MODE8_LSB)
/* Port 8 configuration bits */
#define GPIO_CRH_CNF8_LSB   2
#define GPIO_CRH_CNF8_MSB   3
#define GPIO_CRH_CNF8_MASK  (3 << GPIO_CRH_CNF8_LSB)
/* Port 9 mode bits */
#define GPIO_CRH_MODE9_LSB  4
#define GPIO_CRH_MODE9_MSB  5
#define GPIO_CRH_MODE9_MASK (3 << GPIO_CRH_MODE9_LSB)
/* Port 9 configuration bits */
#define GPIO_CRH_CNF9_LSB   6
#define GPIO_CRH_CNF9_MSB   7
#define GPIO_CRH_CNF9_MASK  (3 << GPIO_CRH_CNF9_LSB)
/* Port 10 mode bits */
#define GPIO_CRH_MODE10_LSB     8
#define GPIO_CRH_MODE10_MSB     9
#define GPIO_CRH_MODE10_MASK    (3 << GPIO_CRH_MODE10_LSB)
/* Port 10 configuration bits */
#define GPIO_CRH_CNF10_LSB      10
#define GPIO_CRH_CNF10_MSB      11
#define GPIO_CRH_CNF10_MASK     (3 << GPIO_CRH_CNF10_LSB)
/* Port 11 mode bits */
#define GPIO_CRH_MODE11_LSB     12
#define GPIO_CRH_MODE11_MSB     13
#define GPIO_CRH_MODE11_MASK    (3 << GPIO_CRH_MODE11_LSB)
/* Port 11 configuration bits */
#define GPIO_CRH_CNF11_LSB      14
#define GPIO_CRH_CNF11_MSB      15
#define GPIO_CRH_CNF11_MASK     (3 << GPIO_CRH_CNF11_LSB)
/* Port 12 mode bits */
#define GPIO_CRH_MODE12_LSB     16
#define GPIO_CRH_MODE12_MSB     17
#define GPIO_CRH_MODE12_MASK    (3 << GPIO_CRH_MODE12_LSB)
/* Port 12 configuration bits */
#define GPIO_CRH_CNF12_LSB      18
#define GPIO_CRH_CNF12_MSB      19
#define GPIO_CRH_CNF12_MASK     (3 << GPIO_CRH_CNF12_LSB)
/* Port 13 mode bits */
#define GPIO_CRH_MODE13_LSB     20
#define GPIO_CRH_MODE13_MSB     21
#define GPIO_CRH_MODE13_MASK    (3 << GPIO_CRH_MODE13_LSB)
/* Port 13 configuration bits */
#define GPIO_CRH_CNF13_LSB      22
#define GPIO_CRH_CNF13_MSB      23
#define GPIO_CRH_CNF13_MASK     (3 << GPIO_CRH_CNF13_LSB)
/* Port 14 mode bits */
#define GPIO_CRH_MODE14_LSB     24
#define GPIO_CRH_MODE14_MSB     25
#define GPIO_CRH_MODE14_MASK    (3 << GPIO_CRH_MODE14_LSB)
/* Port 14 configuration bits */
#define GPIO_CRH_CNF14_LSB      26
#define GPIO_CRH_CNF14_MSB      27
#define GPIO_CRH_CNF14_MASK     (3 << GPIO_CRH_CNF14_LSB)
/* Port 15 mode bits */
#define GPIO_CRH_MODE15_LSB     28
#define GPIO_CRH_MODE15_MSB     29
#define GPIO_CRH_MODE15_MASK    (3 << GPIO_CRH_MODE15_LSB)
/* Port 15 configuration bits */
#define GPIO_CRH_CNF15_LSB      30
#define GPIO_CRH_CNF15_MSB      31
#define GPIO_CRH_CNF15_MASK     (3 << GPIO_CRH_CNF15_LSB)

/** GPIO pin mode */
enum gpio_mode {
    /** Input mode */
    GPIO_MODE_INPUT         = 0x0,
    /** Output mode, max speed 10 MHz */
    GPIO_MODE_OUTPUT_10MHZ  = 0x1,
    /** Output mode, max speed 2 MHz */
    GPIO_MODE_OUTPUT_2MHZ   = 0x2,
    /** Output mode, max speed 50 MHz */
    GPIO_MODE_OUTPUT_50MHZ  = 0x3
};

/** GPIO pin input configuration */
enum gpio_cnf_input {
    /** Input mode, analog configuration */
    GPIO_CNF_INPUT_ANALOG   = 0x0,
    /** Input mode, floating input (reset state) configuration */
    GPIO_CNF_INPUT_FLOATING = 0x1,
    /** Input mode, pull-up / pull-down configuration */
    GPIO_CNF_INPUT_PULL     = 0x2,
};

/** GPIO pin output configuration */
enum gpio_cnf_output {
    /** Output mode, general purpose push-pull configuration */
    GPIO_CNF_OUTPUT_GP_PUSH_PULL    = 0x0,
    /** Output mode, general purpose open-drain configuration */
    GPIO_CNF_OUTPUT_GP_OPEN_DRAIN   = 0x1,
    /** Output mode, alternate function push-pull configuration */
    GPIO_CNF_OUTPUT_AF_PUSH_PULL    = 0x2,
    /** Output mode, alternate function open-drain configuration */
    GPIO_CNF_OUTPUT_AF_OPEN_DRAIN   = 0x3,
};

/*
 * Port input data register bits
 */
/* Port 0 input data */
#define GPIO_IDR_IDR0_LSB  0
#define GPIO_IDR_IDR0_MASK (1 << GPIO_IDR_IDR0_LSB)
/* Port 1 input data */
#define GPIO_IDR_IDR1_LSB  1
#define GPIO_IDR_IDR1_MASK (1 << GPIO_IDR_IDR1_LSB)
/* Port 2 input data */
#define GPIO_IDR_IDR2_LSB  2
#define GPIO_IDR_IDR2_MASK (1 << GPIO_IDR_IDR2_LSB)
/* Port 3 input data */
#define GPIO_IDR_IDR3_LSB  3
#define GPIO_IDR_IDR3_MASK (1 << GPIO_IDR_IDR3_LSB)
/* Port 4 input data */
#define GPIO_IDR_IDR4_LSB  4
#define GPIO_IDR_IDR4_MASK (1 << GPIO_IDR_IDR4_LSB)
/* Port 5 input data */
#define GPIO_IDR_IDR5_LSB  5
#define GPIO_IDR_IDR5_MASK (1 << GPIO_IDR_IDR5_LSB)
/* Port 6 input data */
#define GPIO_IDR_IDR6_LSB  6
#define GPIO_IDR_IDR6_MASK (1 << GPIO_IDR_IDR6_LSB)
/* Port 7 input data */
#define GPIO_IDR_IDR7_LSB  7
#define GPIO_IDR_IDR7_MASK (1 << GPIO_IDR_IDR7_LSB)
/* Port 8 input data */
#define GPIO_IDR_IDR8_LSB  8
#define GPIO_IDR_IDR8_MASK (1 << GPIO_IDR_IDR8_LSB)
/* Port 9 input data */
#define GPIO_IDR_IDR9_LSB  9
#define GPIO_IDR_IDR9_MASK (1 << GPIO_IDR_IDR9_LSB)
/* Port 10 input data */
#define GPIO_IDR_IDR10_LSB  10
#define GPIO_IDR_IDR10_MASK (1 << GPIO_IDR_IDR10_LSB)
/* Port 11 input data */
#define GPIO_IDR_IDR11_LSB  11
#define GPIO_IDR_IDR11_MASK (1 << GPIO_IDR_IDR11_LSB)
/* Port 12 input data */
#define GPIO_IDR_IDR12_LSB  12
#define GPIO_IDR_IDR12_MASK (1 << GPIO_IDR_IDR12_LSB)
/* Port 13 input data */
#define GPIO_IDR_IDR13_LSB  13
#define GPIO_IDR_IDR13_MASK (1 << GPIO_IDR_IDR13_LSB)
/* Port 14 input data */
#define GPIO_IDR_IDR14_LSB  14
#define GPIO_IDR_IDR14_MASK (1 << GPIO_IDR_IDR14_LSB)
/* Port 15 input data */
#define GPIO_IDR_IDR15_LSB  15
#define GPIO_IDR_IDR15_MASK (1 << GPIO_IDR_IDR15_LSB)

/*
 * Port output data register bits
 */
/* Port 0 input data */
#define GPIO_ODR_ODR0_LSB  0
#define GPIO_ODR_ODR0_MASK (1 << GPIO_ODR_ODR0_LSB)
/* Port 1 input data */
#define GPIO_ODR_ODR1_LSB  1
#define GPIO_ODR_ODR1_MASK (1 << GPIO_ODR_ODR1_LSB)
/* Port 2 input data */
#define GPIO_ODR_ODR2_LSB  2
#define GPIO_ODR_ODR2_MASK (1 << GPIO_ODR_ODR2_LSB)
/* Port 3 input data */
#define GPIO_ODR_ODR3_LSB  3
#define GPIO_ODR_ODR3_MASK (1 << GPIO_ODR_ODR3_LSB)
/* Port 4 input data */
#define GPIO_ODR_ODR4_LSB  4
#define GPIO_ODR_ODR4_MASK (1 << GPIO_ODR_ODR4_LSB)
/* Port 5 input data */
#define GPIO_ODR_ODR5_LSB  5
#define GPIO_ODR_ODR5_MASK (1 << GPIO_ODR_ODR5_LSB)
/* Port 6 input data */
#define GPIO_ODR_ODR6_LSB  6
#define GPIO_ODR_ODR6_MASK (1 << GPIO_ODR_ODR6_LSB)
/* Port 7 input data */
#define GPIO_ODR_ODR7_LSB  7
#define GPIO_ODR_ODR7_MASK (1 << GPIO_ODR_ODR7_LSB)
/* Port 8 input data */
#define GPIO_ODR_ODR8_LSB  8
#define GPIO_ODR_ODR8_MASK (1 << GPIO_ODR_ODR8_LSB)
/* Port 9 input data */
#define GPIO_ODR_ODR9_LSB  9
#define GPIO_ODR_ODR9_MASK (1 << GPIO_ODR_ODR9_LSB)
/* Port 10 input data */
#define GPIO_ODR_ODR10_LSB  10
#define GPIO_ODR_ODR10_MASK (1 << GPIO_ODR_ODR10_LSB)
/* Port 11 input data */
#define GPIO_ODR_ODR11_LSB  11
#define GPIO_ODR_ODR11_MASK (1 << GPIO_ODR_ODR11_LSB)
/* Port 12 input data */
#define GPIO_ODR_ODR12_LSB  12
#define GPIO_ODR_ODR12_MASK (1 << GPIO_ODR_ODR12_LSB)
/* Port 13 input data */
#define GPIO_ODR_ODR13_LSB  13
#define GPIO_ODR_ODR13_MASK (1 << GPIO_ODR_ODR13_LSB)
/* Port 14 input data */
#define GPIO_ODR_ODR14_LSB  14
#define GPIO_ODR_ODR14_MASK (1 << GPIO_ODR_ODR14_LSB)
/* Port 15 input data */
#define GPIO_ODR_ODR15_LSB  15
#define GPIO_ODR_ODR15_MASK (1 << GPIO_ODR_ODR15_LSB)

/*
 * Port bit set/reset register bits
 */
/* Port 0 set bit */
#define GPIO_BSRR_BS0_LSB  0
#define GPIO_BSRR_BS0_MASK (1 << GPIO_BSRR_BS0_LSB)
/* Port 1 set bit */
#define GPIO_BSRR_BS1_LSB  1
#define GPIO_BSRR_BS1_MASK (1 << GPIO_BSRR_BS1_LSB)
/* Port 2 set bit */
#define GPIO_BSRR_BS2_LSB  2
#define GPIO_BSRR_BS2_MASK (1 << GPIO_BSRR_BS2_LSB)
/* Port 3 set bit */
#define GPIO_BSRR_BS3_LSB  3
#define GPIO_BSRR_BS3_MASK (1 << GPIO_BSRR_BS3_LSB)
/* Port 4 set bit */
#define GPIO_BSRR_BS4_LSB  4
#define GPIO_BSRR_BS4_MASK (1 << GPIO_BSRR_BS4_LSB)
/* Port 5 set bit */
#define GPIO_BSRR_BS5_LSB  5
#define GPIO_BSRR_BS5_MASK (1 << GPIO_BSRR_BS5_LSB)
/* Port 6 set bit */
#define GPIO_BSRR_BS6_LSB  6
#define GPIO_BSRR_BS6_MASK (1 << GPIO_BSRR_BS6_LSB)
/* Port 7 set bit */
#define GPIO_BSRR_BS7_LSB  7
#define GPIO_BSRR_BS7_MASK (1 << GPIO_BSRR_BS7_LSB)
/* Port 8 set bit */
#define GPIO_BSRR_BS8_LSB  8
#define GPIO_BSRR_BS8_MASK (1 << GPIO_BSRR_BS8_LSB)
/* Port 9 set bit */
#define GPIO_BSRR_BS9_LSB  9
#define GPIO_BSRR_BS9_MASK (1 << GPIO_BSRR_BS9_LSB)
/* Port 10 set bit */
#define GPIO_BSRR_BS10_LSB  10
#define GPIO_BSRR_BS10_MASK (1 << GPIO_BSRR_BS10_LSB)
/* Port 11 set bit */
#define GPIO_BSRR_BS11_LSB  11
#define GPIO_BSRR_BS11_MASK (1 << GPIO_BSRR_BS11_LSB)
/* Port 12 set bit */
#define GPIO_BSRR_BS12_LSB  12
#define GPIO_BSRR_BS12_MASK (1 << GPIO_BSRR_BS12_LSB)
/* Port 13 set bit */
#define GPIO_BSRR_BS13_LSB  13
#define GPIO_BSRR_BS13_MASK (1 << GPIO_BSRR_BS13_LSB)
/* Port 14 set bit */
#define GPIO_BSRR_BS14_LSB  14
#define GPIO_BSRR_BS14_MASK (1 << GPIO_BSRR_BS14_LSB)
/* Port 15 set bit */
#define GPIO_BSRR_BS15_LSB  15
#define GPIO_BSRR_BS15_MASK (1 << GPIO_BSRR_BS15_LSB)
/* Port 0 reset bit */
#define GPIO_BSRR_BR0_LSB  16
#define GPIO_BSRR_BR0_MASK (1 << GPIO_BSRR_BR0_LSB)
/* Port 1 reset bit */
#define GPIO_BSRR_BR1_LSB  17
#define GPIO_BSRR_BR1_MASK (1 << GPIO_BSRR_BR1_LSB)
/* Port 2 reset bit */
#define GPIO_BSRR_BR2_LSB  18
#define GPIO_BSRR_BR2_MASK (1 << GPIO_BSRR_BR2_LSB)
/* Port 3 reset bit */
#define GPIO_BSRR_BR3_LSB  19
#define GPIO_BSRR_BR3_MASK (1 << GPIO_BSRR_BR3_LSB)
/* Port 4 reset bit */
#define GPIO_BSRR_BR4_LSB  20
#define GPIO_BSRR_BR4_MASK (1 << GPIO_BSRR_BR4_LSB)
/* Port 5 reset bit */
#define GPIO_BSRR_BR5_LSB  21
#define GPIO_BSRR_BR5_MASK (1 << GPIO_BSRR_BR5_LSB)
/* Port 6 reset bit */
#define GPIO_BSRR_BR6_LSB  22
#define GPIO_BSRR_BR6_MASK (1 << GPIO_BSRR_BR6_LSB)
/* Port 7 reset bit */
#define GPIO_BSRR_BR7_LSB  23
#define GPIO_BSRR_BR7_MASK (1 << GPIO_BSRR_BR7_LSB)
/* Port 8 reset bit */
#define GPIO_BSRR_BR8_LSB  24
#define GPIO_BSRR_BR8_MASK (1 << GPIO_BSRR_BR8_LSB)
/* Port 9 reset bit */
#define GPIO_BSRR_BR9_LSB  25
#define GPIO_BSRR_BR9_MASK (1 << GPIO_BSRR_BR9_LSB)
/* Port 10 reset bit */
#define GPIO_BSRR_BR10_LSB  26
#define GPIO_BSRR_BR10_MASK (1 << GPIO_BSRR_BR10_LSB)
/* Port 11 reset bit */
#define GPIO_BSRR_BR11_LSB  27
#define GPIO_BSRR_BR11_MASK (1 << GPIO_BSRR_BR11_LSB)
/* Port 12 reset bit */
#define GPIO_BSRR_BR12_LSB  28
#define GPIO_BSRR_BR12_MASK (1 << GPIO_BSRR_BR12_LSB)
/* Port 13 reset bit */
#define GPIO_BSRR_BR13_LSB  29
#define GPIO_BSRR_BR13_MASK (1 << GPIO_BSRR_BR13_LSB)
/* Port 14 reset bit */
#define GPIO_BSRR_BR14_LSB  30
#define GPIO_BSRR_BR14_MASK (1 << GPIO_BSRR_BR14_LSB)
/* Port 15 reset bit */
#define GPIO_BSRR_BR15_LSB  31
#define GPIO_BSRR_BR15_MASK (1 << GPIO_BSRR_BR15_LSB)

/*
 * Port bit reset register bits
 */
/* Port 0 reset bit */
#define GPIO_BRR_BR0_LSB  0
#define GPIO_BRR_BR0_MASK (1 << GPIO_BRR_BR0_LSB)
/* Port 1 reset bit */
#define GPIO_BRR_BR1_LSB  1
#define GPIO_BRR_BR1_MASK (1 << GPIO_BRR_BR1_LSB)
/* Port 2 reset bit */
#define GPIO_BRR_BR2_LSB  2
#define GPIO_BRR_BR2_MASK (1 << GPIO_BRR_BR2_LSB)
/* Port 3 reset bit */
#define GPIO_BRR_BR3_LSB  3
#define GPIO_BRR_BR3_MASK (1 << GPIO_BRR_BR3_LSB)
/* Port 4 reset bit */
#define GPIO_BRR_BR4_LSB  4
#define GPIO_BRR_BR4_MASK (1 << GPIO_BRR_BR4_LSB)
/* Port 5 reset bit */
#define GPIO_BRR_BR5_LSB  5
#define GPIO_BRR_BR5_MASK (1 << GPIO_BRR_BR5_LSB)
/* Port 6 reset bit */
#define GPIO_BRR_BR6_LSB  6
#define GPIO_BRR_BR6_MASK (1 << GPIO_BRR_BR6_LSB)
/* Port 7 reset bit */
#define GPIO_BRR_BR7_LSB  7
#define GPIO_BRR_BR7_MASK (1 << GPIO_BRR_BR7_LSB)
/* Port 8 reset bit */
#define GPIO_BRR_BR8_LSB  8
#define GPIO_BRR_BR8_MASK (1 << GPIO_BRR_BR8_LSB)
/* Port 9 reset bit */
#define GPIO_BRR_BR9_LSB  9
#define GPIO_BRR_BR9_MASK (1 << GPIO_BRR_BR9_LSB)
/* Port 10 reset bit */
#define GPIO_BRR_BR10_LSB  10
#define GPIO_BRR_BR10_MASK (1 << GPIO_BRR_BR10_LSB)
/* Port 11 reset bit */
#define GPIO_BRR_BR11_LSB  11
#define GPIO_BRR_BR11_MASK (1 << GPIO_BRR_BR11_LSB)
/* Port 12 reset bit */
#define GPIO_BRR_BR12_LSB  12
#define GPIO_BRR_BR12_MASK (1 << GPIO_BRR_BR12_LSB)
/* Port 13 reset bit */
#define GPIO_BRR_BR13_LSB  13
#define GPIO_BRR_BR13_MASK (1 << GPIO_BRR_BR13_LSB)
/* Port 14 reset bit */
#define GPIO_BRR_BR14_LSB  14
#define GPIO_BRR_BR14_MASK (1 << GPIO_BRR_BR14_LSB)
/* Port 15 reset bit */
#define GPIO_BRR_BR15_LSB  15
#define GPIO_BRR_BR15_MASK (1 << GPIO_BRR_BR15_LSB)

/*
 * Port configuration lock register bits
 */
/* Port 0 reset bit */
#define GPIO_LCKR_LCK0_LSB  0
#define GPIO_LCKR_LCK0_MASK (1 << GPIO_LCKR_LCK0_LSB)
/* Port 1 reset bit */
#define GPIO_LCKR_LCK1_LSB  1
#define GPIO_LCKR_LCK1_MASK (1 << GPIO_LCKR_LCK1_LSB)
/* Port 2 reset bit */
#define GPIO_LCKR_LCK2_LSB  2
#define GPIO_LCKR_LCK2_MASK (1 << GPIO_LCKR_LCK2_LSB)
/* Port 3 reset bit */
#define GPIO_LCKR_LCK3_LSB  3
#define GPIO_LCKR_LCK3_MASK (1 << GPIO_LCKR_LCK3_LSB)
/* Port 4 reset bit */
#define GPIO_LCKR_LCK4_LSB  4
#define GPIO_LCKR_LCK4_MASK (1 << GPIO_LCKR_LCK4_LSB)
/* Port 5 reset bit */
#define GPIO_LCKR_LCK5_LSB  5
#define GPIO_LCKR_LCK5_MASK (1 << GPIO_LCKR_LCK5_LSB)
/* Port 6 reset bit */
#define GPIO_LCKR_LCK6_LSB  6
#define GPIO_LCKR_LCK6_MASK (1 << GPIO_LCKR_LCK6_LSB)
/* Port 7 reset bit */
#define GPIO_LCKR_LCK7_LSB  7
#define GPIO_LCKR_LCK7_MASK (1 << GPIO_LCKR_LCK7_LSB)
/* Port 8 reset bit */
#define GPIO_LCKR_LCK8_LSB  8
#define GPIO_LCKR_LCK8_MASK (1 << GPIO_LCKR_LCK8_LSB)
/* Port 9 reset bit */
#define GPIO_LCKR_LCK9_LSB  9
#define GPIO_LCKR_LCK9_MASK (1 << GPIO_LCKR_LCK9_LSB)
/* Port 10 reset bit */
#define GPIO_LCKR_LCK10_LSB  10
#define GPIO_LCKR_LCK10_MASK (1 << GPIO_LCKR_LCK10_LSB)
/* Port 11 reset bit */
#define GPIO_LCKR_LCK11_LSB  11
#define GPIO_LCKR_LCK11_MASK (1 << GPIO_LCKR_LCK11_LSB)
/* Port 12 reset bit */
#define GPIO_LCKR_LCK12_LSB  12
#define GPIO_LCKR_LCK12_MASK (1 << GPIO_LCKR_LCK12_LSB)
/* Port 13 reset bit */
#define GPIO_LCKR_LCK13_LSB  13
#define GPIO_LCKR_LCK13_MASK (1 << GPIO_LCKR_LCK13_LSB)
/* Port 14 reset bit */
#define GPIO_LCKR_LCK14_LSB  14
#define GPIO_LCKR_LCK14_MASK (1 << GPIO_LCKR_LCK14_LSB)
/* Port 15 reset bit */
#define GPIO_LCKR_LCK15_LSB  15
#define GPIO_LCKR_LCK15_MASK (1 << GPIO_LCKR_LCK15_LSB)

/** Minimum port pin index */
#define GPIO_PIN_IDX_MIN    0
/** First port pin index of the high half */
#define GPIO_PIN_IDX_HIGH   8
/** Maximum port pin index */
#define GPIO_PIN_IDX_MAX    15
/** Number of pins in a port */
#define GPIO_PIN_IDX_NUM    (GPIO_PIN_IDX_MAX - GPIO_PIN_IDX_MIN + 1)
/** Invalid port pin index */
#define GPIO_PIN_IDX_INV    255

/**
 * Configure a single pin on a port.
 *
 * @param gpio  The GPIO port peripheral the pin resides on.
 * @param pin   Index of the pin to configure.
 * @param mode  Pin mode to use.
 * @param conf  Pin configuration to use according to the mode. Either an
 *              enum gpio_cnf_input or an enum gpio_cnf_output value.
 */
extern void gpio_pin_conf(volatile struct gpio *gpio,
                          unsigned int pin,
                          enum gpio_mode mode,
                          unsigned int cnf);

/**
 * Set the state of a single pin on a port.
 *
 * @param gpio  The GPIO port peripheral the pin resides on.
 * @param pin   Index of the pin to set the state of.
 * @param state The pin state to set, 0 - unset, otherwise - set.
 */
static inline void
gpio_pin_set(volatile struct gpio *gpio,
             unsigned int pin,
             unsigned int state)
{
    pin |= ((unsigned int)!state) << 4;
    gpio->bsrr = (1 << pin);
}

/**
 * Get the state of a single pin on a port.
 *
 * @param gpio  The GPIO port peripheral the pin resides on.
 * @param pin   Index of the pin to get the state of.
 *
 * @return The state of the pin: 1 for set, 0 for unset.
 */
static inline unsigned int
gpio_pin_get(volatile struct gpio *gpio,
             unsigned int pin)
{
    return (gpio->idr >> pin) & 1;
}

#endif /* _STM32F103C8T6_GPIO_H */
