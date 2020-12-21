/*
 * GPIO
 */

#ifndef _STM32L052C8T6_GPIO_H
#define _STM32L052C8T6_GPIO_H

/** GPIO */
struct gpio {
    unsigned int moder;     /**< GPIO port mode register */
    unsigned int otyper;    /**< GPIO port output type register */
    unsigned int ospeedr;   /**< GPIO port output speed register */
    unsigned int pupdr;     /**< GPIO port pull-up/pull-down register */
    unsigned int idr;       /**< GPIO port input data register */
    unsigned int odr;       /**< GPIO port output data register */
    unsigned int bsrr;      /**< GPIO port bit set/reset register */
    unsigned int lckr;      /**< GPIO port configuration lock register */
    union {
        unsigned int afr[2];    /**< GPIO alternate function registers */
        struct {
            unsigned int afrl;  /**< GPIO alternate function low register */
            unsigned int afrh;  /**< GPIO alternate function high register */
        };
    };
    unsigned int brr;       /**< GPIO port bit reset register */
};

/** GPIO port A */
#define GPIO_A  ((volatile struct gpio *)0x50000000)
/** GPIO port B */
#define GPIO_B  ((volatile struct gpio *)0x50000400)
/** GPIO port C */
#define GPIO_C  ((volatile struct gpio *)0x50000800)
/** GPIO port D */
#define GPIO_D  ((volatile struct gpio *)0x50000C00)
/** GPIO port E */
#define GPIO_E  ((volatile struct gpio *)0x50001000)
/** GPIO port H */
#define GPIO_H  ((volatile struct gpio *)0x50001C00)

/*
 * Port mode register bits
 */
/* Port mode bits 0 */
#define GPIO_MODER_MODE0_LSB  0
#define GPIO_MODER_MODE0_MSB  1
#define GPIO_MODER_MODE0_MASK (3 << GPIO_MODER_MODE0_LSB)
/* Port mode bits 1 */
#define GPIO_MODER_MODE1_LSB  2
#define GPIO_MODER_MODE1_MSB  3
#define GPIO_MODER_MODE1_MASK (3 << GPIO_MODER_MODE1_LSB)
/* Port mode bits 2 */
#define GPIO_MODER_MODE2_LSB  4
#define GPIO_MODER_MODE2_MSB  5
#define GPIO_MODER_MODE2_MASK (3 << GPIO_MODER_MODE2_LSB)
/* Port mode bits 3 */
#define GPIO_MODER_MODE3_LSB  6
#define GPIO_MODER_MODE3_MSB  7
#define GPIO_MODER_MODE3_MASK (3 << GPIO_MODER_MODE3_LSB)
/* Port mode bits 4 */
#define GPIO_MODER_MODE4_LSB  8
#define GPIO_MODER_MODE4_MSB  9
#define GPIO_MODER_MODE4_MASK (3 << GPIO_MODER_MODE4_LSB)
/* Port mode bits 5 */
#define GPIO_MODER_MODE5_LSB  10
#define GPIO_MODER_MODE5_MSB  11
#define GPIO_MODER_MODE5_MASK (3 << GPIO_MODER_MODE5_LSB)
/* Port mode bits 6 */
#define GPIO_MODER_MODE6_LSB  12
#define GPIO_MODER_MODE6_MSB  13
#define GPIO_MODER_MODE6_MASK (3 << GPIO_MODER_MODE6_LSB)
/* Port mode bits 7 */
#define GPIO_MODER_MODE7_LSB  14
#define GPIO_MODER_MODE7_MSB  15
#define GPIO_MODER_MODE7_MASK (3 << GPIO_MODER_MODE7_LSB)
/* Port mode bits 8 */
#define GPIO_MODER_MODE8_LSB  16
#define GPIO_MODER_MODE8_MSB  17
#define GPIO_MODER_MODE8_MASK (3 << GPIO_MODER_MODE8_LSB)
/* Port mode bits 9 */
#define GPIO_MODER_MODE9_LSB  18
#define GPIO_MODER_MODE9_MSB  19
#define GPIO_MODER_MODE9_MASK (3 << GPIO_MODER_MODE9_LSB)
/* Port mode bits 10 */
#define GPIO_MODER_MODE10_LSB  20
#define GPIO_MODER_MODE10_MSB  21
#define GPIO_MODER_MODE10_MASK (3 << GPIO_MODER_MODE10_LSB)
/* Port mode bits 11 */
#define GPIO_MODER_MODE11_LSB  22
#define GPIO_MODER_MODE11_MSB  23
#define GPIO_MODER_MODE11_MASK (3 << GPIO_MODER_MODE11_LSB)
/* Port mode bits 12 */
#define GPIO_MODER_MODE12_LSB  24
#define GPIO_MODER_MODE12_MSB  25
#define GPIO_MODER_MODE12_MASK (3 << GPIO_MODER_MODE12_LSB)
/* Port mode bits 13 */
#define GPIO_MODER_MODE13_LSB  26
#define GPIO_MODER_MODE13_MSB  27
#define GPIO_MODER_MODE13_MASK (3 << GPIO_MODER_MODE13_LSB)
/* Port mode bits 14 */
#define GPIO_MODER_MODE14_LSB  28
#define GPIO_MODER_MODE14_MSB  29
#define GPIO_MODER_MODE14_MASK (3 << GPIO_MODER_MODE14_LSB)
/* Port mode bits 15 */
#define GPIO_MODER_MODE15_LSB  30
#define GPIO_MODER_MODE15_MSB  31
#define GPIO_MODER_MODE15_MASK (3 << GPIO_MODER_MODE15_LSB)

/** Port mode */
enum gpio_mode {
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_AF,
    GPIO_MODE_ANALOG,
};

/*
 * Port output type register bits
 */
/* Port configuration bits 0 */
#define GPIO_OTYPER_OT0_LSB  0
#define GPIO_OTYPER_OT0_MASK (1 << GPIO_OTYPER_OT0_LSB)
/* Port configuration bits 1 */
#define GPIO_OTYPER_OT1_LSB  1
#define GPIO_OTYPER_OT1_MASK (1 << GPIO_OTYPER_OT1_LSB)
/* Port configuration bits 2 */
#define GPIO_OTYPER_OT2_LSB  2
#define GPIO_OTYPER_OT2_MASK (1 << GPIO_OTYPER_OT2_LSB)
/* Port configuration bits 3 */
#define GPIO_OTYPER_OT3_LSB  3
#define GPIO_OTYPER_OT3_MASK (1 << GPIO_OTYPER_OT3_LSB)
/* Port configuration bits 4 */
#define GPIO_OTYPER_OT4_LSB  4
#define GPIO_OTYPER_OT4_MASK (1 << GPIO_OTYPER_OT4_LSB)
/* Port configuration bits 5 */
#define GPIO_OTYPER_OT5_LSB  5
#define GPIO_OTYPER_OT5_MASK (1 << GPIO_OTYPER_OT5_LSB)
/* Port configuration bits 6 */
#define GPIO_OTYPER_OT6_LSB  6
#define GPIO_OTYPER_OT6_MASK (1 << GPIO_OTYPER_OT6_LSB)
/* Port configuration bits 7 */
#define GPIO_OTYPER_OT7_LSB  7
#define GPIO_OTYPER_OT7_MASK (1 << GPIO_OTYPER_OT7_LSB)
/* Port configuration bits 8 */
#define GPIO_OTYPER_OT8_LSB  8
#define GPIO_OTYPER_OT8_MASK (1 << GPIO_OTYPER_OT8_LSB)
/* Port configuration bits 9 */
#define GPIO_OTYPER_OT9_LSB  9
#define GPIO_OTYPER_OT9_MASK (1 << GPIO_OTYPER_OT9_LSB)
/* Port configuration bits 10 */
#define GPIO_OTYPER_OT10_LSB  10
#define GPIO_OTYPER_OT10_MASK (1 << GPIO_OTYPER_OT10_LSB)
/* Port configuration bits 11 */
#define GPIO_OTYPER_OT11_LSB  11
#define GPIO_OTYPER_OT11_MASK (1 << GPIO_OTYPER_OT11_LSB)
/* Port configuration bits 12 */
#define GPIO_OTYPER_OT12_LSB  12
#define GPIO_OTYPER_OT12_MASK (1 << GPIO_OTYPER_OT12_LSB)
/* Port configuration bits 13 */
#define GPIO_OTYPER_OT13_LSB  13
#define GPIO_OTYPER_OT13_MASK (1 << GPIO_OTYPER_OT13_LSB)
/* Port configuration bits 14 */
#define GPIO_OTYPER_OT14_LSB  14
#define GPIO_OTYPER_OT14_MASK (1 << GPIO_OTYPER_OT14_LSB)
/* Port configuration bits 15 */
#define GPIO_OTYPER_OT15_LSB  15
#define GPIO_OTYPER_OT15_MASK (1 << GPIO_OTYPER_OT15_LSB)

/** Port output type */
enum gpio_otype {
    GPIO_OTYPE_PUSH_PULL,
    GPIO_OTYPE_OPEN_DRAIN,
};

/*
 * Port output speed register bits
 */
/* Port configuration bits 0 */
#define GPIO_OSPEEDR_OSPEED0_LSB  0
#define GPIO_OSPEEDR_OSPEED0_MSB  1
#define GPIO_OSPEEDR_OSPEED0_MASK (3 << GPIO_OSPEEDR_OSPEED0_LSB)
/* Port configuration bits 1 */
#define GPIO_OSPEEDR_OSPEED1_LSB  2
#define GPIO_OSPEEDR_OSPEED1_MSB  3
#define GPIO_OSPEEDR_OSPEED1_MASK (3 << GPIO_OSPEEDR_OSPEED1_LSB)
/* Port configuration bits 2 */
#define GPIO_OSPEEDR_OSPEED2_LSB  4
#define GPIO_OSPEEDR_OSPEED2_MSB  5
#define GPIO_OSPEEDR_OSPEED2_MASK (3 << GPIO_OSPEEDR_OSPEED2_LSB)
/* Port configuration bits 3 */
#define GPIO_OSPEEDR_OSPEED3_LSB  6
#define GPIO_OSPEEDR_OSPEED3_MSB  7
#define GPIO_OSPEEDR_OSPEED3_MASK (3 << GPIO_OSPEEDR_OSPEED3_LSB)
/* Port configuration bits 4 */
#define GPIO_OSPEEDR_OSPEED4_LSB  8
#define GPIO_OSPEEDR_OSPEED4_MSB  9
#define GPIO_OSPEEDR_OSPEED4_MASK (3 << GPIO_OSPEEDR_OSPEED4_LSB)
/* Port configuration bits 5 */
#define GPIO_OSPEEDR_OSPEED5_LSB  10
#define GPIO_OSPEEDR_OSPEED5_MSB  11
#define GPIO_OSPEEDR_OSPEED5_MASK (3 << GPIO_OSPEEDR_OSPEED5_LSB)
/* Port configuration bits 6 */
#define GPIO_OSPEEDR_OSPEED6_LSB  12
#define GPIO_OSPEEDR_OSPEED6_MSB  13
#define GPIO_OSPEEDR_OSPEED6_MASK (3 << GPIO_OSPEEDR_OSPEED6_LSB)
/* Port configuration bits 7 */
#define GPIO_OSPEEDR_OSPEED7_LSB  14
#define GPIO_OSPEEDR_OSPEED7_MSB  15
#define GPIO_OSPEEDR_OSPEED7_MASK (3 << GPIO_OSPEEDR_OSPEED7_LSB)
/* Port configuration bits 8 */
#define GPIO_OSPEEDR_OSPEED8_LSB  16
#define GPIO_OSPEEDR_OSPEED8_MSB  17
#define GPIO_OSPEEDR_OSPEED8_MASK (3 << GPIO_OSPEEDR_OSPEED8_LSB)
/* Port configuration bits 9 */
#define GPIO_OSPEEDR_OSPEED9_LSB  18
#define GPIO_OSPEEDR_OSPEED9_MSB  19
#define GPIO_OSPEEDR_OSPEED9_MASK (3 << GPIO_OSPEEDR_OSPEED9_LSB)
/* Port configuration bits 10 */
#define GPIO_OSPEEDR_OSPEED10_LSB  20
#define GPIO_OSPEEDR_OSPEED10_MSB  21
#define GPIO_OSPEEDR_OSPEED10_MASK (3 << GPIO_OSPEEDR_OSPEED10_LSB)
/* Port configuration bits 11 */
#define GPIO_OSPEEDR_OSPEED11_LSB  22
#define GPIO_OSPEEDR_OSPEED11_MSB  23
#define GPIO_OSPEEDR_OSPEED11_MASK (3 << GPIO_OSPEEDR_OSPEED11_LSB)
/* Port configuration bits 12 */
#define GPIO_OSPEEDR_OSPEED12_LSB  24
#define GPIO_OSPEEDR_OSPEED12_MSB  25
#define GPIO_OSPEEDR_OSPEED12_MASK (3 << GPIO_OSPEEDR_OSPEED12_LSB)
/* Port configuration bits 13 */
#define GPIO_OSPEEDR_OSPEED13_LSB  26
#define GPIO_OSPEEDR_OSPEED13_MSB  27
#define GPIO_OSPEEDR_OSPEED13_MASK (3 << GPIO_OSPEEDR_OSPEED13_LSB)
/* Port configuration bits 14 */
#define GPIO_OSPEEDR_OSPEED14_LSB  28
#define GPIO_OSPEEDR_OSPEED14_MSB  29
#define GPIO_OSPEEDR_OSPEED14_MASK (3 << GPIO_OSPEEDR_OSPEED14_LSB)
/* Port configuration bits 15 */
#define GPIO_OSPEEDR_OSPEED15_LSB  30
#define GPIO_OSPEEDR_OSPEED15_MSB  31
#define GPIO_OSPEEDR_OSPEED15_MASK (3 << GPIO_OSPEEDR_OSPEED15_LSB)

/** Port output speed */
enum gpio_ospeed {
    GPIO_OSPEED_LOW,
    GPIO_OSPEED_MEDIUM,
    GPIO_OSPEED_HIGH,
    GPIO_OSPEED_VERY_HIGH,
};

/*
 * Port pull-up/pull-down register bits
 */
/* Port configuration bits 0 */
#define GPIO_PUPDR_PUPD0_LSB  0
#define GPIO_PUPDR_PUPD0_MSB  1
#define GPIO_PUPDR_PUPD0_MASK (3 << GPIO_PUPDR_PUPD0_LSB)
/* Port configuration bits 1 */
#define GPIO_PUPDR_PUPD1_LSB  2
#define GPIO_PUPDR_PUPD1_MSB  3
#define GPIO_PUPDR_PUPD1_MASK (3 << GPIO_PUPDR_PUPD1_LSB)
/* Port configuration bits 2 */
#define GPIO_PUPDR_PUPD2_LSB  4
#define GPIO_PUPDR_PUPD2_MSB  5
#define GPIO_PUPDR_PUPD2_MASK (3 << GPIO_PUPDR_PUPD2_LSB)
/* Port configuration bits 3 */
#define GPIO_PUPDR_PUPD3_LSB  6
#define GPIO_PUPDR_PUPD3_MSB  7
#define GPIO_PUPDR_PUPD3_MASK (3 << GPIO_PUPDR_PUPD3_LSB)
/* Port configuration bits 4 */
#define GPIO_PUPDR_PUPD4_LSB  8
#define GPIO_PUPDR_PUPD4_MSB  9
#define GPIO_PUPDR_PUPD4_MASK (3 << GPIO_PUPDR_PUPD4_LSB)
/* Port configuration bits 5 */
#define GPIO_PUPDR_PUPD5_LSB  10
#define GPIO_PUPDR_PUPD5_MSB  11
#define GPIO_PUPDR_PUPD5_MASK (3 << GPIO_PUPDR_PUPD5_LSB)
/* Port configuration bits 6 */
#define GPIO_PUPDR_PUPD6_LSB  12
#define GPIO_PUPDR_PUPD6_MSB  13
#define GPIO_PUPDR_PUPD6_MASK (3 << GPIO_PUPDR_PUPD6_LSB)
/* Port configuration bits 7 */
#define GPIO_PUPDR_PUPD7_LSB  14
#define GPIO_PUPDR_PUPD7_MSB  15
#define GPIO_PUPDR_PUPD7_MASK (3 << GPIO_PUPDR_PUPD7_LSB)
/* Port configuration bits 8 */
#define GPIO_PUPDR_PUPD8_LSB  16
#define GPIO_PUPDR_PUPD8_MSB  17
#define GPIO_PUPDR_PUPD8_MASK (3 << GPIO_PUPDR_PUPD8_LSB)
/* Port configuration bits 9 */
#define GPIO_PUPDR_PUPD9_LSB  18
#define GPIO_PUPDR_PUPD9_MSB  19
#define GPIO_PUPDR_PUPD9_MASK (3 << GPIO_PUPDR_PUPD9_LSB)
/* Port configuration bits 10 */
#define GPIO_PUPDR_PUPD10_LSB  20
#define GPIO_PUPDR_PUPD10_MSB  21
#define GPIO_PUPDR_PUPD10_MASK (3 << GPIO_PUPDR_PUPD10_LSB)
/* Port configuration bits 11 */
#define GPIO_PUPDR_PUPD11_LSB  22
#define GPIO_PUPDR_PUPD11_MSB  23
#define GPIO_PUPDR_PUPD11_MASK (3 << GPIO_PUPDR_PUPD11_LSB)
/* Port configuration bits 12 */
#define GPIO_PUPDR_PUPD12_LSB  24
#define GPIO_PUPDR_PUPD12_MSB  25
#define GPIO_PUPDR_PUPD12_MASK (3 << GPIO_PUPDR_PUPD12_LSB)
/* Port configuration bits 13 */
#define GPIO_PUPDR_PUPD13_LSB  26
#define GPIO_PUPDR_PUPD13_MSB  27
#define GPIO_PUPDR_PUPD13_MASK (3 << GPIO_PUPDR_PUPD13_LSB)
/* Port configuration bits 14 */
#define GPIO_PUPDR_PUPD14_LSB  28
#define GPIO_PUPDR_PUPD14_MSB  29
#define GPIO_PUPDR_PUPD14_MASK (3 << GPIO_PUPDR_PUPD14_LSB)
/* Port configuration bits 15 */
#define GPIO_PUPDR_PUPD15_LSB  30
#define GPIO_PUPDR_PUPD15_MSB  31
#define GPIO_PUPDR_PUPD15_MASK (3 << GPIO_PUPDR_PUPD15_LSB)

/** Port pull-up/pull-down */
enum gpio_pupd {
    GPIO_PUPD_NONE,
    GPIO_PUPD_UP,
    GPIO_PUPD_DOWN,
    GPIO_PUPD_RESERVED,
};

/*
 * Port input data register bits
 */
/* Port input data bit 0 */
#define GPIO_IDR_ID0_LSB  0
#define GPIO_IDR_ID0_MASK (1 << GPIO_IDR_ID0_LSB)
/* Port input data bit 1 */
#define GPIO_IDR_ID1_LSB  1
#define GPIO_IDR_ID1_MASK (1 << GPIO_IDR_ID1_LSB)
/* Port input data bit 2 */
#define GPIO_IDR_ID2_LSB  2
#define GPIO_IDR_ID2_MASK (1 << GPIO_IDR_ID2_LSB)
/* Port input data bit 3 */
#define GPIO_IDR_ID3_LSB  3
#define GPIO_IDR_ID3_MASK (1 << GPIO_IDR_ID3_LSB)
/* Port input data bit 4 */
#define GPIO_IDR_ID4_LSB  4
#define GPIO_IDR_ID4_MASK (1 << GPIO_IDR_ID4_LSB)
/* Port input data bit 5 */
#define GPIO_IDR_ID5_LSB  5
#define GPIO_IDR_ID5_MASK (1 << GPIO_IDR_ID5_LSB)
/* Port input data bit 6 */
#define GPIO_IDR_ID6_LSB  6
#define GPIO_IDR_ID6_MASK (1 << GPIO_IDR_ID6_LSB)
/* Port input data bit 7 */
#define GPIO_IDR_ID7_LSB  7
#define GPIO_IDR_ID7_MASK (1 << GPIO_IDR_ID7_LSB)
/* Port input data bit 8 */
#define GPIO_IDR_ID8_LSB  8
#define GPIO_IDR_ID8_MASK (1 << GPIO_IDR_ID8_LSB)
/* Port input data bit 9 */
#define GPIO_IDR_ID9_LSB  9
#define GPIO_IDR_ID9_MASK (1 << GPIO_IDR_ID9_LSB)
/* Port input data bit 10 */
#define GPIO_IDR_ID10_LSB  10
#define GPIO_IDR_ID10_MASK (1 << GPIO_IDR_ID10_LSB)
/* Port input data bit 11 */
#define GPIO_IDR_ID11_LSB  11
#define GPIO_IDR_ID11_MASK (1 << GPIO_IDR_ID11_LSB)
/* Port input data bit 12 */
#define GPIO_IDR_ID12_LSB  12
#define GPIO_IDR_ID12_MASK (1 << GPIO_IDR_ID12_LSB)
/* Port input data bit 13 */
#define GPIO_IDR_ID13_LSB  13
#define GPIO_IDR_ID13_MASK (1 << GPIO_IDR_ID13_LSB)
/* Port input data bit 14 */
#define GPIO_IDR_ID14_LSB  14
#define GPIO_IDR_ID14_MASK (1 << GPIO_IDR_ID14_LSB)
/* Port input data bit 15 */
#define GPIO_IDR_ID15_LSB  15
#define GPIO_IDR_ID15_MASK (1 << GPIO_IDR_ID15_LSB)

/*
 * Port output data register bits
 */
/* Port output data bit 0 */
#define GPIO_ODR_OD0_LSB  0
#define GPIO_ODR_OD0_MASK (1 << GPIO_ODR_OD0_LSB)
/* Port output data bit 1 */
#define GPIO_ODR_OD1_LSB  1
#define GPIO_ODR_OD1_MASK (1 << GPIO_ODR_OD1_LSB)
/* Port output data bit 2 */
#define GPIO_ODR_OD2_LSB  2
#define GPIO_ODR_OD2_MASK (1 << GPIO_ODR_OD2_LSB)
/* Port output data bit 3 */
#define GPIO_ODR_OD3_LSB  3
#define GPIO_ODR_OD3_MASK (1 << GPIO_ODR_OD3_LSB)
/* Port output data bit 4 */
#define GPIO_ODR_OD4_LSB  4
#define GPIO_ODR_OD4_MASK (1 << GPIO_ODR_OD4_LSB)
/* Port output data bit 5 */
#define GPIO_ODR_OD5_LSB  5
#define GPIO_ODR_OD5_MASK (1 << GPIO_ODR_OD5_LSB)
/* Port output data bit 6 */
#define GPIO_ODR_OD6_LSB  6
#define GPIO_ODR_OD6_MASK (1 << GPIO_ODR_OD6_LSB)
/* Port output data bit 7 */
#define GPIO_ODR_OD7_LSB  7
#define GPIO_ODR_OD7_MASK (1 << GPIO_ODR_OD7_LSB)
/* Port output data bit 8 */
#define GPIO_ODR_OD8_LSB  8
#define GPIO_ODR_OD8_MASK (1 << GPIO_ODR_OD8_LSB)
/* Port output data bit 9 */
#define GPIO_ODR_OD9_LSB  9
#define GPIO_ODR_OD9_MASK (1 << GPIO_ODR_OD9_LSB)
/* Port output data bit 10 */
#define GPIO_ODR_OD10_LSB  10
#define GPIO_ODR_OD10_MASK (1 << GPIO_ODR_OD10_LSB)
/* Port output data bit 11 */
#define GPIO_ODR_OD11_LSB  11
#define GPIO_ODR_OD11_MASK (1 << GPIO_ODR_OD11_LSB)
/* Port output data bit 12 */
#define GPIO_ODR_OD12_LSB  12
#define GPIO_ODR_OD12_MASK (1 << GPIO_ODR_OD12_LSB)
/* Port output data bit 13 */
#define GPIO_ODR_OD13_LSB  13
#define GPIO_ODR_OD13_MASK (1 << GPIO_ODR_OD13_LSB)
/* Port output data bit 14 */
#define GPIO_ODR_OD14_LSB  14
#define GPIO_ODR_OD14_MASK (1 << GPIO_ODR_OD14_LSB)
/* Port output data bit 15 */
#define GPIO_ODR_OD15_LSB  15
#define GPIO_ODR_OD15_MASK (1 << GPIO_ODR_OD15_LSB)

/*
 * Port bit set/reset register bits
 */
/* Port set bit 0 */
#define GPIO_BSRR_BS0_LSB  0
#define GPIO_BSRR_BS0_MASK (1 << GPIO_BSRR_BS0_LSB)
/* Port set bit 1 */
#define GPIO_BSRR_BS1_LSB  1
#define GPIO_BSRR_BS1_MASK (1 << GPIO_BSRR_BS1_LSB)
/* Port set bit 2 */
#define GPIO_BSRR_BS2_LSB  2
#define GPIO_BSRR_BS2_MASK (1 << GPIO_BSRR_BS2_LSB)
/* Port set bit 3 */
#define GPIO_BSRR_BS3_LSB  3
#define GPIO_BSRR_BS3_MASK (1 << GPIO_BSRR_BS3_LSB)
/* Port set bit 4 */
#define GPIO_BSRR_BS4_LSB  4
#define GPIO_BSRR_BS4_MASK (1 << GPIO_BSRR_BS4_LSB)
/* Port set bit 5 */
#define GPIO_BSRR_BS5_LSB  5
#define GPIO_BSRR_BS5_MASK (1 << GPIO_BSRR_BS5_LSB)
/* Port set bit 6 */
#define GPIO_BSRR_BS6_LSB  6
#define GPIO_BSRR_BS6_MASK (1 << GPIO_BSRR_BS6_LSB)
/* Port set bit 7 */
#define GPIO_BSRR_BS7_LSB  7
#define GPIO_BSRR_BS7_MASK (1 << GPIO_BSRR_BS7_LSB)
/* Port set bit 8 */
#define GPIO_BSRR_BS8_LSB  8
#define GPIO_BSRR_BS8_MASK (1 << GPIO_BSRR_BS8_LSB)
/* Port set bit 9 */
#define GPIO_BSRR_BS9_LSB  9
#define GPIO_BSRR_BS9_MASK (1 << GPIO_BSRR_BS9_LSB)
/* Port set bit 10 */
#define GPIO_BSRR_BS10_LSB  10
#define GPIO_BSRR_BS10_MASK (1 << GPIO_BSRR_BS10_LSB)
/* Port set bit 11 */
#define GPIO_BSRR_BS11_LSB  11
#define GPIO_BSRR_BS11_MASK (1 << GPIO_BSRR_BS11_LSB)
/* Port set bit 12 */
#define GPIO_BSRR_BS12_LSB  12
#define GPIO_BSRR_BS12_MASK (1 << GPIO_BSRR_BS12_LSB)
/* Port set bit 13 */
#define GPIO_BSRR_BS13_LSB  13
#define GPIO_BSRR_BS13_MASK (1 << GPIO_BSRR_BS13_LSB)
/* Port set bit 14 */
#define GPIO_BSRR_BS14_LSB  14
#define GPIO_BSRR_BS14_MASK (1 << GPIO_BSRR_BS14_LSB)
/* Port set bit 15 */
#define GPIO_BSRR_BS15_LSB  15
#define GPIO_BSRR_BS15_MASK (1 << GPIO_BSRR_BS15_LSB)
/* Port reset bit 0 */
#define GPIO_BSRR_BR0_LSB  16
#define GPIO_BSRR_BR0_MASK (1 << GPIO_BSRR_BR0_LSB)
/* Port reset bit 1 */
#define GPIO_BSRR_BR1_LSB  17
#define GPIO_BSRR_BR1_MASK (1 << GPIO_BSRR_BR1_LSB)
/* Port reset bit 2 */
#define GPIO_BSRR_BR2_LSB  18
#define GPIO_BSRR_BR2_MASK (1 << GPIO_BSRR_BR2_LSB)
/* Port reset bit 3 */
#define GPIO_BSRR_BR3_LSB  19
#define GPIO_BSRR_BR3_MASK (1 << GPIO_BSRR_BR3_LSB)
/* Port reset bit 4 */
#define GPIO_BSRR_BR4_LSB  20
#define GPIO_BSRR_BR4_MASK (1 << GPIO_BSRR_BR4_LSB)
/* Port reset bit 5 */
#define GPIO_BSRR_BR5_LSB  21
#define GPIO_BSRR_BR5_MASK (1 << GPIO_BSRR_BR5_LSB)
/* Port reset bit 6 */
#define GPIO_BSRR_BR6_LSB  22
#define GPIO_BSRR_BR6_MASK (1 << GPIO_BSRR_BR6_LSB)
/* Port reset bit 7 */
#define GPIO_BSRR_BR7_LSB  23
#define GPIO_BSRR_BR7_MASK (1 << GPIO_BSRR_BR7_LSB)
/* Port reset bit 8 */
#define GPIO_BSRR_BR8_LSB  24
#define GPIO_BSRR_BR8_MASK (1 << GPIO_BSRR_BR8_LSB)
/* Port reset bit 9 */
#define GPIO_BSRR_BR9_LSB  25
#define GPIO_BSRR_BR9_MASK (1 << GPIO_BSRR_BR9_LSB)
/* Port reset bit 10 */
#define GPIO_BSRR_BR10_LSB  26
#define GPIO_BSRR_BR10_MASK (1 << GPIO_BSRR_BR10_LSB)
/* Port reset bit 11 */
#define GPIO_BSRR_BR11_LSB  27
#define GPIO_BSRR_BR11_MASK (1 << GPIO_BSRR_BR11_LSB)
/* Port reset bit 12 */
#define GPIO_BSRR_BR12_LSB  28
#define GPIO_BSRR_BR12_MASK (1 << GPIO_BSRR_BR12_LSB)
/* Port reset bit 13 */
#define GPIO_BSRR_BR13_LSB  29
#define GPIO_BSRR_BR13_MASK (1 << GPIO_BSRR_BR13_LSB)
/* Port reset bit 14 */
#define GPIO_BSRR_BR14_LSB  30
#define GPIO_BSRR_BR14_MASK (1 << GPIO_BSRR_BR14_LSB)
/* Port reset bit 15 */
#define GPIO_BSRR_BR15_LSB  31
#define GPIO_BSRR_BR15_MASK (1 << GPIO_BSRR_BR15_LSB)

/*
 * Port configuration lock register bits
 */
/* Port lock bit 0 */
#define GPIO_LCKR_LCK0_LSB  0
#define GPIO_LCKR_LCK0_MASK (1 << GPIO_LCKR_LCK0_LSB)
/* Port lock bit 1 */
#define GPIO_LCKR_LCK1_LSB  1
#define GPIO_LCKR_LCK1_MASK (1 << GPIO_LCKR_LCK1_LSB)
/* Port lock bit 2 */
#define GPIO_LCKR_LCK2_LSB  2
#define GPIO_LCKR_LCK2_MASK (1 << GPIO_LCKR_LCK2_LSB)
/* Port lock bit 3 */
#define GPIO_LCKR_LCK3_LSB  3
#define GPIO_LCKR_LCK3_MASK (1 << GPIO_LCKR_LCK3_LSB)
/* Port lock bit 4 */
#define GPIO_LCKR_LCK4_LSB  4
#define GPIO_LCKR_LCK4_MASK (1 << GPIO_LCKR_LCK4_LSB)
/* Port lock bit 5 */
#define GPIO_LCKR_LCK5_LSB  5
#define GPIO_LCKR_LCK5_MASK (1 << GPIO_LCKR_LCK5_LSB)
/* Port lock bit 6 */
#define GPIO_LCKR_LCK6_LSB  6
#define GPIO_LCKR_LCK6_MASK (1 << GPIO_LCKR_LCK6_LSB)
/* Port lock bit 7 */
#define GPIO_LCKR_LCK7_LSB  7
#define GPIO_LCKR_LCK7_MASK (1 << GPIO_LCKR_LCK7_LSB)
/* Port lock bit 8 */
#define GPIO_LCKR_LCK8_LSB  8
#define GPIO_LCKR_LCK8_MASK (1 << GPIO_LCKR_LCK8_LSB)
/* Port lock bit 9 */
#define GPIO_LCKR_LCK9_LSB  9
#define GPIO_LCKR_LCK9_MASK (1 << GPIO_LCKR_LCK9_LSB)
/* Port lock bit 10 */
#define GPIO_LCKR_LCK10_LSB  10
#define GPIO_LCKR_LCK10_MASK (1 << GPIO_LCKR_LCK10_LSB)
/* Port lock bit 11 */
#define GPIO_LCKR_LCK11_LSB  11
#define GPIO_LCKR_LCK11_MASK (1 << GPIO_LCKR_LCK11_LSB)
/* Port lock bit 12 */
#define GPIO_LCKR_LCK12_LSB  12
#define GPIO_LCKR_LCK12_MASK (1 << GPIO_LCKR_LCK12_LSB)
/* Port lock bit 13 */
#define GPIO_LCKR_LCK13_LSB  13
#define GPIO_LCKR_LCK13_MASK (1 << GPIO_LCKR_LCK13_LSB)
/* Port lock bit 14 */
#define GPIO_LCKR_LCK14_LSB  14
#define GPIO_LCKR_LCK14_MASK (1 << GPIO_LCKR_LCK14_LSB)
/* Port lock bit 15 */
#define GPIO_LCKR_LCK15_LSB  15
#define GPIO_LCKR_LCK15_MASK (1 << GPIO_LCKR_LCK15_LSB)
/* Port lock key */
#define GPIO_LCKR_LCKK_LSB  16
#define GPIO_LCKR_LCKK_MASK (1 << GPIO_LCKR_LCKK_LSB)

/*
 * Alternate function low register bits
 */
/* Alternate function selection for pin 0 */
#define GPIO_AFRL_AFSEL0_LSB  0
#define GPIO_AFRL_AFSEL0_MSB  3
#define GPIO_AFRL_AFSEL0_MASK (0xf << GPIO_AFRL_AFSEL0_LSB)
/* Alternate function selection for pin 1 */
#define GPIO_AFRL_AFSEL1_LSB  4
#define GPIO_AFRL_AFSEL1_MSB  7
#define GPIO_AFRL_AFSEL1_MASK (0xf << GPIO_AFRL_AFSEL1_LSB)
/* Alternate function selection for pin 2 */
#define GPIO_AFRL_AFSEL2_LSB  8
#define GPIO_AFRL_AFSEL2_MSB  11
#define GPIO_AFRL_AFSEL2_MASK (0xf << GPIO_AFRL_AFSEL2_LSB)
/* Alternate function selection for pin 3 */
#define GPIO_AFRL_AFSEL3_LSB  12
#define GPIO_AFRL_AFSEL3_MSB  15
#define GPIO_AFRL_AFSEL3_MASK (0xf << GPIO_AFRL_AFSEL3_LSB)
/* Alternate function selection for pin 4 */
#define GPIO_AFRL_AFSEL4_LSB  16
#define GPIO_AFRL_AFSEL4_MSB  19
#define GPIO_AFRL_AFSEL4_MASK (0xf << GPIO_AFRL_AFSEL4_LSB)
/* Alternate function selection for pin 5 */
#define GPIO_AFRL_AFSEL5_LSB  20
#define GPIO_AFRL_AFSEL5_MSB  23
#define GPIO_AFRL_AFSEL5_MASK (0xf << GPIO_AFRL_AFSEL5_LSB)
/* Alternate function selection for pin 6 */
#define GPIO_AFRL_AFSEL6_LSB  24
#define GPIO_AFRL_AFSEL6_MSB  27
#define GPIO_AFRL_AFSEL6_MASK (0xf << GPIO_AFRL_AFSEL6_LSB)
/* Alternate function selection for pin 7 */
#define GPIO_AFRL_AFSEL7_LSB  28
#define GPIO_AFRL_AFSEL7_MSB  31
#define GPIO_AFRL_AFSEL7_MASK (0xf << GPIO_AFRL_AFSEL7_LSB)

/*
 * Alternate function high register bits
 */
/* Alternate function selection for pin 8 */
#define GPIO_AFRH_AFSEL8_LSB  0
#define GPIO_AFRH_AFSEL8_MSB  3
#define GPIO_AFRH_AFSEL8_MASK (0xf << GPIO_AFRH_AFSEL8_LSB)
/* Alternate function selection for pin 9 */
#define GPIO_AFRH_AFSEL9_LSB  4
#define GPIO_AFRH_AFSEL9_MSB  7
#define GPIO_AFRH_AFSEL9_MASK (0xf << GPIO_AFRH_AFSEL9_LSB)
/* Alternate function selection for pin 10 */
#define GPIO_AFRH_AFSEL10_LSB  8
#define GPIO_AFRH_AFSEL10_MSB  11
#define GPIO_AFRH_AFSEL10_MASK (0xf << GPIO_AFRH_AFSEL10_LSB)
/* Alternate function selection for pin 11 */
#define GPIO_AFRH_AFSEL11_LSB  12
#define GPIO_AFRH_AFSEL11_MSB  15
#define GPIO_AFRH_AFSEL11_MASK (0xf << GPIO_AFRH_AFSEL11_LSB)
/* Alternate function selection for pin 12 */
#define GPIO_AFRH_AFSEL12_LSB  16
#define GPIO_AFRH_AFSEL12_MSB  19
#define GPIO_AFRH_AFSEL12_MASK (0xf << GPIO_AFRH_AFSEL12_LSB)
/* Alternate function selection for pin 13 */
#define GPIO_AFRH_AFSEL13_LSB  20
#define GPIO_AFRH_AFSEL13_MSB  23
#define GPIO_AFRH_AFSEL13_MASK (0xf << GPIO_AFRH_AFSEL13_LSB)
/* Alternate function selection for pin 14 */
#define GPIO_AFRH_AFSEL14_LSB  24
#define GPIO_AFRH_AFSEL14_MSB  27
#define GPIO_AFRH_AFSEL14_MASK (0xf << GPIO_AFRH_AFSEL14_LSB)
/* Alternate function selection for pin 15 */
#define GPIO_AFRH_AFSEL15_LSB  28
#define GPIO_AFRH_AFSEL15_MSB  31
#define GPIO_AFRH_AFSEL15_MASK (0xf << GPIO_AFRH_AFSEL15_LSB)

/* Alternate function selection */
enum gpio_afsel {
    GPIO_AFSEL_AF0,
    GPIO_AFSEL_AF1,
    GPIO_AFSEL_AF2,
    GPIO_AFSEL_AF3,
    GPIO_AFSEL_AF4,
    GPIO_AFSEL_AF5,
    GPIO_AFSEL_AF6,
    GPIO_AFSEL_AF7,
};

/*
 * Port bit reset register bits
 */
/* Port reset bit 0 */
#define GPIO_BRR_BR0_LSB  0
#define GPIO_BRR_BR0_MASK (1 << GPIO_BRR_BR0_LSB)
/* Port reset bit 1 */
#define GPIO_BRR_BR1_LSB  1
#define GPIO_BRR_BR1_MASK (1 << GPIO_BRR_BR1_LSB)
/* Port reset bit 2 */
#define GPIO_BRR_BR2_LSB  2
#define GPIO_BRR_BR2_MASK (1 << GPIO_BRR_BR2_LSB)
/* Port reset bit 3 */
#define GPIO_BRR_BR3_LSB  3
#define GPIO_BRR_BR3_MASK (1 << GPIO_BRR_BR3_LSB)
/* Port reset bit 4 */
#define GPIO_BRR_BR4_LSB  4
#define GPIO_BRR_BR4_MASK (1 << GPIO_BRR_BR4_LSB)
/* Port reset bit 5 */
#define GPIO_BRR_BR5_LSB  5
#define GPIO_BRR_BR5_MASK (1 << GPIO_BRR_BR5_LSB)
/* Port reset bit 6 */
#define GPIO_BRR_BR6_LSB  6
#define GPIO_BRR_BR6_MASK (1 << GPIO_BRR_BR6_LSB)
/* Port reset bit 7 */
#define GPIO_BRR_BR7_LSB  7
#define GPIO_BRR_BR7_MASK (1 << GPIO_BRR_BR7_LSB)
/* Port reset bit 8 */
#define GPIO_BRR_BR8_LSB  8
#define GPIO_BRR_BR8_MASK (1 << GPIO_BRR_BR8_LSB)
/* Port reset bit 9 */
#define GPIO_BRR_BR9_LSB  9
#define GPIO_BRR_BR9_MASK (1 << GPIO_BRR_BR9_LSB)
/* Port reset bit 10 */
#define GPIO_BRR_BR10_LSB  10
#define GPIO_BRR_BR10_MASK (1 << GPIO_BRR_BR10_LSB)
/* Port reset bit 11 */
#define GPIO_BRR_BR11_LSB  11
#define GPIO_BRR_BR11_MASK (1 << GPIO_BRR_BR11_LSB)
/* Port reset bit 12 */
#define GPIO_BRR_BR12_LSB  12
#define GPIO_BRR_BR12_MASK (1 << GPIO_BRR_BR12_LSB)
/* Port reset bit 13 */
#define GPIO_BRR_BR13_LSB  13
#define GPIO_BRR_BR13_MASK (1 << GPIO_BRR_BR13_LSB)
/* Port reset bit 14 */
#define GPIO_BRR_BR14_LSB  14
#define GPIO_BRR_BR14_MASK (1 << GPIO_BRR_BR14_LSB)
/* Port reset bit 15 */
#define GPIO_BRR_BR15_LSB  15
#define GPIO_BRR_BR15_MASK (1 << GPIO_BRR_BR15_LSB)

/**
 * Configure a GPIO pin as an output.
 *
 * @param gpio      The GPIO port peripheral the pin resides on.
 * @param pin       Index of the pin to configure.
 * @param otype     Output type.
 * @param pupd      Pull-up/pull-down configuration.
 * @param ospeed    Output speed.
 */
static inline void gpio_pin_conf_output(volatile struct gpio *gpio,
                                        unsigned int pin,
                                        enum gpio_otype otype,
                                        enum gpio_pupd pupd,
                                        enum gpio_ospeed ospeed)
{
    assert(pin < 16);
    const size_t lsb2 = pin << 1;
    gpio->moder = (gpio->moder & ~(3 << lsb2)) | (GPIO_MODE_OUTPUT << lsb2);
    gpio->otyper = (gpio->otyper & ~(1 << pin)) | ((otype & 1) << pin);
    gpio->pupdr = (gpio->pupdr & ~(3 << lsb2)) | ((pupd & 3) << lsb2);
    gpio->ospeedr = (gpio->ospeedr & ~(3 << lsb2)) | ((ospeed & 3) << lsb2);
}

/**
 * Configure a GPIO pin for an alternate function.
 *
 * @param gpio      The GPIO port peripheral the pin resides on.
 * @param pin       Index of the pin to configure.
 * @param afsel     Alternate function selection.
 * @param otype     Output type.
 * @param pupd      Pull-up/pull-down configuration.
 * @param ospeed    Output speed.
 */
static inline void gpio_pin_conf_af(volatile struct gpio *gpio,
                                    unsigned int pin,
                                    enum gpio_afsel afsel,
                                    enum gpio_otype otype,
                                    enum gpio_pupd pupd,
                                    enum gpio_ospeed ospeed)
{
    assert(pin < 16);
    const size_t lsb2 = pin << 1;
    const size_t reg4 = pin >> 3;
    const size_t lsb4 = (pin << 2) & 31;
    gpio->moder = (gpio->moder & ~(3 << lsb2)) | (GPIO_MODE_AF << lsb2);
    gpio->otyper = (gpio->otyper & ~(1 << pin)) | ((otype & 1) << pin);
    gpio->afr[reg4] = (gpio->afr[reg4] & ~(7 << lsb4)) |
                      ((afsel & 7) << lsb4);
    gpio->pupdr = (gpio->pupdr & ~(3 << lsb2)) | ((pupd & 3) << lsb2);
    gpio->ospeedr = (gpio->ospeedr & ~(3 << lsb2)) | ((ospeed & 3) << lsb2);
}

/**
 * Configure a GPIO pin as an input.
 *
 * @param gpio      The GPIO port peripheral the pin resides on.
 * @param pin       Index of the pin to configure.
 * @param pupd      Pull-up/pull-down configuration.
 */
static inline void gpio_pin_conf_input(volatile struct gpio *gpio,
                                       unsigned int pin,
                                       enum gpio_pupd pupd)
{
    assert(pin < 16);
    const size_t lsb2 = pin << 1;
    gpio->moder = (gpio->moder & ~(3 << lsb2)) | (GPIO_MODE_INPUT << lsb2);
    gpio->pupdr = (gpio->pupdr & ~(3 << lsb2)) | ((pupd & 3) << lsb2);
}

/**
 * Configure a GPIO pin as an analog pin.
 *
 * @param gpio      The GPIO port peripheral the pin resides on.
 * @param pin       Index of the pin to configure.
 */
static inline void gpio_pin_conf_analog(volatile struct gpio *gpio,
                                        unsigned int pin)
{
    assert(pin < 16);
    const size_t lsb2 = pin << 1;
    gpio->moder = (gpio->moder & ~(3 << lsb2)) | (GPIO_MODE_ANALOG << lsb2);
}

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

#endif /* _STM32L052C8T6_GPIO_H */
