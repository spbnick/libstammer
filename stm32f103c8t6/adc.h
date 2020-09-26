/*
 * ADC
 */

#ifndef _ADC_H
#define _ADC_H

#include <../stm32/misc.h>

/** ADC */
struct adc {
    unsigned int sr;    /**< Status register */
    unsigned int cr1;   /**< Control register 1 */
    unsigned int cr2;   /**< Control register 2 */
    union {
        struct {
            unsigned int smpr1; /**< Sample time register 1 */
            unsigned int smpr2; /**< Sample time register 2 */
        };
        unsigned int smpr[2];   /**< Sample time registers */
    };
    union {
        struct {
            unsigned int jofr1; /**< Injected channel data offset register 1 */
            unsigned int jofr2; /**< Injected channel data offset register 2 */
            unsigned int jofr3; /**< Injected channel data offset register 3 */
            unsigned int jofr4; /**< Injected channel data offset register 4 */
        };
        unsigned int jofr[4];   /**< Injected channel data offset registers */
    };
    unsigned int htr;   /**< High threshold register */
    unsigned int ltr;   /**< Low threshold register */
    unsigned int sqr1;  /**< Regular sequence register 1 */
    unsigned int sqr2;  /**< Regular sequence register 2 */
    unsigned int sqr3;  /**< Regular sequence register 3 */
    unsigned int jsqr;  /**< Injected sequence register */
    union {
        struct {
            unsigned int jdr1;  /**< Injected data register 1 */
            unsigned int jdr2;  /**< Injected data register 2 */
            unsigned int jdr3;  /**< Injected data register 3 */
            unsigned int jdr4;  /**< Injected data register 4 */
        };
        unsigned int jdr[4];    /**< Injected data registers */
    };
    unsigned int dr;    /**< Regular data register */
};

/** ADC 1 */
#define ADC1    ((volatile struct adc *)0x40012400)
/** ADC 2 */
#define ADC2    ((volatile struct adc *)0x40012800)

/*
 * Status register bits
 */
/* Analog watchdog flag */
#define ADC_SR_AWD_LSB      0
#define ADC_SR_AWD_MASK     (1 << ADC_SR_AWD_LSB)
/* End of conversion */
#define ADC_SR_EOC_LSB      1
#define ADC_SR_EOC_MASK     (1 << ADC_SR_EOC_LSB)
/* Injected channel end of conversion */
#define ADC_SR_JEOC_LSB     2
#define ADC_SR_JEOC_MASK    (1 << ADC_SR_JEOC_LSB)
/* Injected channel start flag */
#define ADC_SR_JSTRT_LSB    3
#define ADC_SR_JSTRT_MASK   (1 << ADC_SR_JSTRT_LSB)
/* Regular channel start flag */
#define ADC_SR_STRT_LSB     4
#define ADC_SR_STRT_MASK    (1 << ADC_SR_STRT_LSB)

/*
 * Control register 1 bits
 */
/* Analog watchdog channel select bits */
#define ADC_CR1_AWDCH_LSB   0
#define ADC_CR1_AWDCH_MSB   4
#define ADC_CR1_AWDCH_MASK  (0x1f << ADC_CR1_AWDCH_LSB)
/* Interrupt enable for EOC (End Of Conversion) */
#define ADC_CR1_EOCIE_LSB   5
#define ADC_CR1_EOCIE_MASK  (1 << ADC_CR1_EOCIE_LSB)
/* Analog watchdog interrupt enable */
#define ADC_CR1_AWDIE_LSB   6
#define ADC_CR1_AWDIE_MASK  (1 << ADC_CR1_AWDIE_LSB)
/* Interrupt enable for injected channels */
#define ADC_CR1_JEOCIE_LSB  7
#define ADC_CR1_JEOCIE_MASK (1 << ADC_CR1_JEOCIE_LSB)
/* Scan mode */
#define ADC_CR1_SCAN_LSB    8
#define ADC_CR1_SCAN_MASK   (1 << ADC_CR1_SCAN_LSB)
/* Enable the watchdog on a single channel in scan mode */
#define ADC_CR1_AWDSGL_LSB      9
#define ADC_CR1_AWDSGL_MASK     (1 << ADC_CR1_AWDSGL_LSB)
/* Automatic injected group conversion */
#define ADC_CR1_JAUTO_LSB       10
#define ADC_CR1_JAUTO_MASK      (1 << ADC_CR1_JAUTO_LSB)
/* Discontinuous mode on regular channels */
#define ADC_CR1_DISCEN_LSB      11
#define ADC_CR1_DISCEN_MASK     (1 << ADC_CR1_DISCEN_LSB)
/* Discontinuous mode on injected channels */
#define ADC_CR1_JDISCEN_LSB     12
#define ADC_CR1_JDISCEN_MASK    (1 << ADC_CR1_JDISCEN_LSB)
/* Discontinuous mode channel count (minus one) */
#define ADC_CR1_DISCNUM_LSB     13
#define ADC_CR1_DISCNUM_MSB     15
#define ADC_CR1_DISCNUM_MASK    (0x7 << ADC_CR1_DISCNUM_LSB)
/* Dual mode selection */
#define ADC_CR1_DUALMOD_LSB     16
#define ADC_CR1_DUALMOD_MSB     19
#define ADC_CR1_DUALMOD_MASK    (0xf << ADC_CR1_DUALMOD_LSB)
/** Dual mode selection value */
enum adc_cr1_dualmod_val {
    ADC_CR1_DUALMOD_VAL_INDEP = 0,
    ADC_CR1_DUALMOD_VAL_COMB_REG_SIMUL_PLUS_INJ_SIMUL,
    ADC_CR1_DUALMOD_VAL_COMB_REG_SIMUL_PLUS_ALT_TRIG,
    ADC_CR1_DUALMOD_VAL_COMB_INJ_SIMUL_PLUS_FAST_INTRLVD,
    ADC_CR1_DUALMOD_VAL_COMB_INJ_SIMUL_PLUS_SLOW_INTRLVD,
    ADC_CR1_DUALMOD_VAL_INJ_SIMUL,
    ADC_CR1_DUALMOD_VAL_REG_SIMUL,
    ADC_CR1_DUALMOD_VAL_FAST_INTRLVD,
    ADC_CR1_DUALMOD_VAL_SLOW_INTRLVD,
    ADC_CR1_DUALMOD_VAL_ALT_TRIG,
};
/* Analog watchdog enable on injected channels */
#define ADC_CR1_JAWDEN_LSB     22
#define ADC_CR1_JAWDEN_MASK    (1 << ADC_CR1_JAWDEN_LSB)
/* Analog watchdog enable on regular channels */
#define ADC_CR1_AWDEN_LSB     23
#define ADC_CR1_AWDEN_MASK    (1 << ADC_CR1_AWDEN_LSB)

/*
 * Control register 2 bits
 */
/* A/D converter ON / OFF */
#define ADC_CR2_ADON_LSB        0
#define ADC_CR2_ADON_MASK       (1 << ADC_CR2_ADON_LSB)
/* Continuous conversion */
#define ADC_CR2_CONT_LSB        1
#define ADC_CR2_CONT_MASK       (1 << ADC_CR2_CONT_LSB)
/* A/D calibration */
#define ADC_CR2_CAL_LSB         2
#define ADC_CR2_CAL_MASK        (1 << ADC_CR2_CAL_LSB)
/* Reset calibration */
#define ADC_CR2_RSTCAL_LSB      3
#define ADC_CR2_RSTCAL_MASK     (1 << ADC_CR2_RSTCAL_LSB)
/* Direct memory access mode */
#define ADC_CR2_DMA_LSB         8
#define ADC_CR2_DMA_MASK        (1 << ADC_CR2_DMA_LSB)
/* Data alignment */
#define ADC_CR2_ALIGN_LSB       11
#define ADC_CR2_ALIGN_MASK      (1 << ADC_CR2_ALIGN_LSB)
#define ADC_CR2_ALIGN_VAL_RIGHT 0
#define ADC_CR2_ALIGN_VAL_LEFT  1
/* External event select for injected group */
#define ADC_CR2_JEXTSEL_LSB     12
#define ADC_CR2_JEXTSEL_MSB     14
#define ADC_CR2_JEXTSEL_MASK    (0x7 << ADC_CR2_JEXTSEL_LSB)
/** Value of external event select for injected group for ADC1 and ADC2 */
enum adc_cr2_jextsel_val_adc1_2 {
    ADC_CR2_JEXTSEL_VAL_ADC1_2_TIM1_TRGO = 0,
    ADC_CR2_JEXTSEL_VAL_ADC1_2_TIM1_CC4,
    ADC_CR2_JEXTSEL_VAL_ADC1_2_TIM2_TRGO,
    ADC_CR2_JEXTSEL_VAL_ADC1_2_TIM2_CC1,
    ADC_CR2_JEXTSEL_VAL_ADC1_2_TIM3_CC4,
    ADC_CR2_JEXTSEL_VAL_ADC1_2_TIM4_TRGO,
    ADC_CR2_JEXTSEL_VAL_ADC1_2_EXTI_LINE15_OR_TIM8_CC4,
    ADC_CR2_JEXTSEL_VAL_ADC1_2_JSWSTART,
};
/** Value of external event select for injected group for ADC3 */
enum adc_cr2_jextsel_val_adc3 {
    ADC_CR2_JEXTSEL_VAL_ADC3_TIM1_TRGO = 0,
    ADC_CR2_JEXTSEL_VAL_ADC3_TIM1_CC4,
    ADC_CR2_JEXTSEL_VAL_ADC3_TIM4_CC3,
    ADC_CR2_JEXTSEL_VAL_ADC3_TIM8_CC2,
    ADC_CR2_JEXTSEL_VAL_ADC3_TIM8_CC4,
    ADC_CR2_JEXTSEL_VAL_ADC3_TIM5_TRGO,
    ADC_CR2_JEXTSEL_VAL_ADC3_TIM5_CC4,
    ADC_CR2_JEXTSEL_VAL_ADC3_JSWSTART,
};
/* External trigger conversion mode for injected channels */
#define ADC_CR2_JEXTTRIG_LSB    15
#define ADC_CR2_JEXTTRIG_MASK   (1 << ADC_CR2_JEXTTRIG_LSB)
/* External event select for regular group */
#define ADC_CR2_EXTSEL_LSB     17
#define ADC_CR2_EXTSEL_MSB     19
#define ADC_CR2_EXTSEL_MASK    (0x7 << ADC_CR2_EXTSEL_LSB)
/** Value of external event select for regular group for ADC1 and ADC2 */
enum adc_cr2_extsel_val_adc1_2 {
    ADC_CR2_EXTSEL_VAL_ADC1_2_TIM1_CC1 = 0,
    ADC_CR2_EXTSEL_VAL_ADC1_2_TIM1_CC2,
    ADC_CR2_EXTSEL_VAL_ADC1_2_TIM1_CC3,
    ADC_CR2_EXTSEL_VAL_ADC1_2_TIM2_CC2,
    ADC_CR2_EXTSEL_VAL_ADC1_2_TIM3_TRGO,
    ADC_CR2_EXTSEL_VAL_ADC1_2_TIM4_CC4,
    ADC_CR2_EXTSEL_VAL_ADC1_2_EXTI_LINE11_OR_TIM8_TRGO,
    ADC_CR2_EXTSEL_VAL_ADC1_2_SWSTART,
};
/** Value of external event select for regular group for ADC3 */
enum adc_cr2_extsel_val_adc3 {
    ADC_CR2_EXTSEL_VAL_ADC3_TIM3_CC1 = 0,
    ADC_CR2_EXTSEL_VAL_ADC3_TIM2_CC3,
    ADC_CR2_EXTSEL_VAL_ADC3_TIM1_CC3,
    ADC_CR2_EXTSEL_VAL_ADC3_TIM8_CC1,
    ADC_CR2_EXTSEL_VAL_ADC3_TIM8_TRGO,
    ADC_CR2_EXTSEL_VAL_ADC3_TIM5_CC1,
    ADC_CR2_EXTSEL_VAL_ADC3_TIM5_CC3,
    ADC_CR2_EXTSEL_VAL_ADC3_SWSTART,
};
/* External trigger conversion mode for regular channels */
#define ADC_CR2_EXTTRIG_LSB     20
#define ADC_CR2_EXTTRIG_MASK    (1 << ADC_CR2_EXTTRIG_LSB)
/* Start conversion of injected channels */
#define ADC_CR2_JSWSTART_LSB    21
#define ADC_CR2_JSWSTART_MASK   (1 << ADC_CR2_JSWSTART_LSB)
/* Start conversion of regular channels */
#define ADC_CR2_SWSTART_LSB     22
#define ADC_CR2_SWSTART_MASK    (1 << ADC_CR2_SWSTART_LSB)
/* Temperature sensor and Vrefint enable */
#define ADC_CR2_TSVREFE_LSB     23
#define ADC_CR2_TSVREFE_MASK    (1 << ADC_CR2_TSVREFE_LSB)

/*
 * Sample time register 1 bits
 */
/* Channel 10 sample time selection */
#define ADC_SMPR1_SMP10_LSB     0
#define ADC_SMPR1_SMP10_MSB     2
#define ADC_SMPR1_SMP10_MASK    (0x7 << ADC_SMPR1_SMP10_LSB)
/* Channel 11 sample time selection */
#define ADC_SMPR1_SMP11_LSB     3
#define ADC_SMPR1_SMP11_MSB     5
#define ADC_SMPR1_SMP11_MASK    (0x7 << ADC_SMPR1_SMP11_LSB)
/* Channel 12 sample time selection */
#define ADC_SMPR1_SMP12_LSB     6
#define ADC_SMPR1_SMP12_MSB     8
#define ADC_SMPR1_SMP12_MASK    (0x7 << ADC_SMPR1_SMP12_LSB)
/* Channel 13 sample time selection */
#define ADC_SMPR1_SMP13_LSB     9
#define ADC_SMPR1_SMP13_MSB     11
#define ADC_SMPR1_SMP13_MASK    (0x7 << ADC_SMPR1_SMP13_LSB)
/* Channel 14 sample time selection */
#define ADC_SMPR1_SMP14_LSB     12
#define ADC_SMPR1_SMP14_MSB     14
#define ADC_SMPR1_SMP14_MASK    (0x7 << ADC_SMPR1_SMP14_LSB)
/* Channel 15 sample time selection */
#define ADC_SMPR1_SMP15_LSB     15
#define ADC_SMPR1_SMP15_MSB     17
#define ADC_SMPR1_SMP15_MASK    (0x7 << ADC_SMPR1_SMP15_LSB)
/* Channel 16 sample time selection */
#define ADC_SMPR1_SMP16_LSB     18
#define ADC_SMPR1_SMP16_MSB     20
#define ADC_SMPR1_SMP16_MASK    (0x7 << ADC_SMPR1_SMP16_LSB)
/* Channel 17 sample time selection */
#define ADC_SMPR1_SMP17_LSB     21
#define ADC_SMPR1_SMP17_MSB     23
#define ADC_SMPR1_SMP17_MASK    (0x7 << ADC_SMPR1_SMP17_LSB)
/*
 * Sample time register 2 bits
 */
/* Channel 0 sample time selection */
#define ADC_SMPR2_SMP0_LSB     0
#define ADC_SMPR2_SMP0_MSB     2
#define ADC_SMPR2_SMP0_MASK    (0x7 << ADC_SMPR2_SMP0_LSB)
/* Channel 1 sample time selection */
#define ADC_SMPR2_SMP1_LSB     3
#define ADC_SMPR2_SMP1_MSB     5
#define ADC_SMPR2_SMP1_MASK    (0x7 << ADC_SMPR2_SMP1_LSB)
/* Channel 2 sample time selection */
#define ADC_SMPR2_SMP2_LSB     6
#define ADC_SMPR2_SMP2_MSB     8
#define ADC_SMPR2_SMP2_MASK    (0x7 << ADC_SMPR2_SMP2_LSB)
/* Channel 3 sample time selection */
#define ADC_SMPR2_SMP3_LSB     9
#define ADC_SMPR2_SMP3_MSB     11
#define ADC_SMPR2_SMP3_MASK    (0x7 << ADC_SMPR2_SMP3_LSB)
/* Channel 4 sample time selection */
#define ADC_SMPR2_SMP4_LSB     12
#define ADC_SMPR2_SMP4_MSB     14
#define ADC_SMPR2_SMP4_MASK    (0x7 << ADC_SMPR2_SMP4_LSB)
/* Channel 5 sample time selection */
#define ADC_SMPR2_SMP5_LSB     15
#define ADC_SMPR2_SMP5_MSB     17
#define ADC_SMPR2_SMP5_MASK    (0x7 << ADC_SMPR2_SMP5_LSB)
/* Channel 6 sample time selection */
#define ADC_SMPR2_SMP6_LSB     18
#define ADC_SMPR2_SMP6_MSB     20
#define ADC_SMPR2_SMP6_MASK    (0x7 << ADC_SMPR2_SMP6_LSB)
/* Channel 7 sample time selection */
#define ADC_SMPR2_SMP7_LSB     21
#define ADC_SMPR2_SMP7_MSB     23
#define ADC_SMPR2_SMP7_MASK    (0x7 << ADC_SMPR2_SMP7_LSB)
/* Channel 8 sample time selection */
#define ADC_SMPR2_SMP8_LSB     24
#define ADC_SMPR2_SMP8_MSB     26
#define ADC_SMPR2_SMP8_MASK    (0x7 << ADC_SMPR2_SMP8_LSB)
/* Channel 9 sample time selection */
#define ADC_SMPR2_SMP9_LSB     27
#define ADC_SMPR2_SMP9_MSB     29
#define ADC_SMPR2_SMP9_MASK    (0x7 << ADC_SMPR2_SMP9_LSB)

/** Channel sample time value, ADC cycles */
enum adc_smprx_smpx_val {
    ADC_SMPRX_SMPX_VAL_1_5C,
    ADC_SMPRX_SMPX_VAL_7_5C,
    ADC_SMPRX_SMPX_VAL_13_5C,
    ADC_SMPRX_SMPX_VAL_28_5C,
    ADC_SMPRX_SMPX_VAL_41_5C,
    ADC_SMPRX_SMPX_VAL_55_5C,
    ADC_SMPRX_SMPX_VAL_71_5C,
    ADC_SMPRX_SMPX_VAL_239_5C,
    ADC_SMPRX_SMPX_VAL_NUM
};

/*
 * Injected channel data offset register X (1-4) bits
 */
#define ADC_JOFRX_JOFFSETX_LSB  0
#define ADC_JOFRX_JOFFSETX_MSB  11
#define ADC_JOFRX_JOFFSETX_MASK (0xfff << ADC_JOFRX_JOFFSETX_LSB)

/*
 * Watchdog high threshold register bits
 */
#define ADC_HTR_HT_LSB  0
#define ADC_HTR_HT_MSB  11
#define ADC_HTR_HT_MASK (0xfff << ADC_HTR_HT_LSB)

/*
 * Watchdog low threshold register bits
 */
#define ADC_LTR_LT_LSB  0
#define ADC_LTR_LT_MSB  11
#define ADC_LTR_LT_MASK (0xfff << ADC_LTR_LT_LSB)

/*
 * Regular sequence register 1 bits
 */
/* 13th conversion in regular sequence */
#define ADC_SQR1_SQ13_LSB   0
#define ADC_SQR1_SQ13_MSB   4
#define ADC_SQR1_SQ13_MASK  (0x1f << ADC_SQR1_SQ13_LSB)
/* 14th conversion in regular sequence */
#define ADC_SQR1_SQ14_LSB   5
#define ADC_SQR1_SQ14_MSB   9
#define ADC_SQR1_SQ14_MASK  (0x1f << ADC_SQR1_SQ14_LSB)
/* 15th conversion in regular sequence */
#define ADC_SQR1_SQ15_LSB   10
#define ADC_SQR1_SQ15_MSB   14
#define ADC_SQR1_SQ15_MASK  (0x1f << ADC_SQR1_SQ15_LSB)
/* 16th conversion in regular sequence */
#define ADC_SQR1_SQ16_LSB   15
#define ADC_SQR1_SQ16_MSB   19
#define ADC_SQR1_SQ16_MASK  (0x1f << ADC_SQR1_SQ16_LSB)
/* Regular channel sequence length (minus one) */
#define ADC_SQR1_L_LSB      20
#define ADC_SQR1_L_MSB      23
#define ADC_SQR1_L_MASK     (0xf << ADC_SQR1_L_LSB)

/*
 * Regular sequence register 2 bits
 */
/* 7th conversion in regular sequence */
#define ADC_SQR2_SQ7_LSB    0
#define ADC_SQR2_SQ7_MSB    4
#define ADC_SQR2_SQ7_MASK   (0x1f << ADC_SQR2_SQ7_LSB)
/* 8th conversion in regular sequence */
#define ADC_SQR2_SQ8_LSB    5
#define ADC_SQR2_SQ8_MSB    9
#define ADC_SQR2_SQ8_MASK   (0x1f << ADC_SQR2_SQ8_LSB)
/* 9th conversion in regular sequence */
#define ADC_SQR2_SQ9_LSB    10
#define ADC_SQR2_SQ9_MSB    14
#define ADC_SQR2_SQ9_MASK   (0x1f << ADC_SQR2_SQ9_LSB)
/* 10th conversion in regular sequence */
#define ADC_SQR2_SQ10_LSB   15
#define ADC_SQR2_SQ10_MSB   19
#define ADC_SQR2_SQ10_MASK  (0x1f << ADC_SQR2_SQ10_LSB)
/* 11th conversion in regular sequence */
#define ADC_SQR2_SQ11_LSB   20
#define ADC_SQR2_SQ11_MSB   24
#define ADC_SQR2_SQ11_MASK  (0x1f << ADC_SQR2_SQ11_LSB)
/* 12th conversion in regular sequence */
#define ADC_SQR2_SQ12_LSB   25
#define ADC_SQR2_SQ12_MSB   29
#define ADC_SQR2_SQ12_MASK  (0x1f << ADC_SQR2_SQ12_LSB)

/*
 * Regular sequence register 3 bits
 */
/* 1st conversion in regular sequence */
#define ADC_SQR3_SQ1_LSB    0
#define ADC_SQR3_SQ1_MSB    4
#define ADC_SQR3_SQ1_MASK   (0x1f << ADC_SQR3_SQ1_LSB)
/* 2nd conversion in regular sequence */
#define ADC_SQR3_SQ2_LSB    5
#define ADC_SQR3_SQ2_MSB    9
#define ADC_SQR3_SQ2_MASK   (0x1f << ADC_SQR3_SQ2_LSB)
/* 3rd conversion in regular sequence */
#define ADC_SQR3_SQ3_LSB    10
#define ADC_SQR3_SQ3_MSB    14
#define ADC_SQR3_SQ3_MASK   (0x1f << ADC_SQR3_SQ3_LSB)
/* 4th conversion in regular sequence */
#define ADC_SQR3_SQ4_LSB    15
#define ADC_SQR3_SQ4_MSB    19
#define ADC_SQR3_SQ4_MASK   (0x1f << ADC_SQR3_SQ4_LSB)
/* 5th conversion in regular sequence */
#define ADC_SQR3_SQ5_LSB    20
#define ADC_SQR3_SQ5_MSB    24
#define ADC_SQR3_SQ5_MASK   (0x1f << ADC_SQR3_SQ5_LSB)
/* 6th conversion in regular sequence */
#define ADC_SQR3_SQ6_LSB    25
#define ADC_SQR3_SQ6_MSB    29
#define ADC_SQR3_SQ6_MASK   (0x1f << ADC_SQR3_SQ6_LSB)

/*
 * Injected sequence register bits
 */
/* 1st conversion in injected sequence */
#define ADC_JSQR_JSQ1_LSB   0
#define ADC_JSQR_JSQ1_MSB   4
#define ADC_JSQR_JSQ1_MASK  (0x1f << ADC_JSQR_JSQ1_LSB)
/* 2nd conversion in injected sequence */
#define ADC_JSQR_JSQ2_LSB   5
#define ADC_JSQR_JSQ2_MSB   9
#define ADC_JSQR_JSQ2_MASK  (0x1f << ADC_JSQR_JSQ2_LSB)
/* 3rd conversion in injected sequence */
#define ADC_JSQR_JSQ3_LSB   10
#define ADC_JSQR_JSQ3_MSB   14
#define ADC_JSQR_JSQ3_MASK  (0x1f << ADC_JSQR_JSQ3_LSB)
/* 4th conversion in injected sequence */
#define ADC_JSQR_JSQ4_LSB   15
#define ADC_JSQR_JSQ4_MSB   19
#define ADC_JSQR_JSQ4_MASK  (0x1f << ADC_JSQR_JSQ4_LSB)
/* Injected sequence length (minus one, cutting from the start) */
#define ADC_JSQR_JL_LSB     20
#define ADC_JSQR_JL_MSB     21
#define ADC_JSQR_JL_MASK    (0x3 << ADC_JSQR_JL_LSB)

/*
 * Injected data register X (1-4) bits
 */
/* Injected data */
#define ADC_JDRX_JDATA_LSB  0
#define ADC_JDRX_JDATA_MSB  15
#define ADC_JDRX_JDATA_MASK (0xffff << ADC_JDRX_JDATA_LSB)

/*
 * Regular data register bits
 */
/* Regular data */
#define ADC_DR_DATA_LSB     0
#define ADC_DR_DATA_MSB     15
#define ADC_DR_DATA_MASK    (0xffff << ADC_DR_DATA_LSB)
/* ADC2 data (ADC1-only) */
#define ADC_DR_ADC2DATA_LSB     16
#define ADC_DR_ADC2DATA_MSB     31
#define ADC_DR_ADC2DATA_MASK    (0xffff << ADC_DR_ADC2DATA_LSB)

/**
 * Number of available ADC channels, including temperature sensor and Vrefint
 */
#define ADC_CHANNEL_NUM 17

/**
 * Set sample time for an ADC channel.
 *
 * @param adc           The ADC with the channel having sample time set.
 * @param channel       The number of the channel to set sample time for.
 * @param sample_time   The sample time to set.
 */
static inline void
adc_channel_set_sample_time(volatile struct adc *adc,
                            unsigned int channel,
                            enum adc_smprx_smpx_val sample_time)
{
    static const unsigned int field_width = 3;
    static const unsigned int mask = (1 << field_width) - 1;
    static const unsigned int channels_per_reg =
                                sizeof(*adc->smpr) / field_width;

    assert(adc != NULL);
    assert(channel < ADC_CHANNEL_NUM);
    assert(sample_time < ADC_SMPRX_SMPX_VAL_NUM);

    size_t reg = channel / channels_per_reg;
    size_t lsb = (channel - reg * channels_per_reg) * field_width;

    adc->smpr[1 - reg] = (adc->smpr[1 - reg] & ~(mask << lsb)) |
                         sample_time << lsb;
}

#endif /* _ADC_H */
