/*
 * STK (SysTick timer)
 */

#ifndef _ARM_STK_H
#define _ARM_STK_H

/** STK (SysTick) structure */
struct stk {
    unsigned int ctrl;  /**< Control and status register */
    unsigned int load;  /**< Reload value register */
    unsigned int val;   /**< Current value register */
    unsigned int calib; /**< Calibration value register */
};

/** The STK (SysTick) instance */
#define STK ((volatile struct stk *)0xe000e010)

/*
 * Control and status register bits
 */
/* Counter enable */
#define STK_CTRL_ENABLE_LSB     0
#define STK_CTRL_ENABLE_MASK    (1 << STK_CTRL_ENABLE_LSB)
/* SysTick exception request enable */
#define STK_CTRL_TICKINT_LSB    1
#define STK_CTRL_TICKINT_MASK   (1 << STK_CTRL_TICKINT_LSB)
/* Clock source selection */
#define STK_CTRL_CLKSOURCE_LSB  2
#define STK_CTRL_CLKSOURCE_MASK (1 << STK_CTRL_CLKSOURCE_LSB)
#define STK_CTRL_CLKSOURCE_VAL_AHB_DIV_8    0
#define STK_CTRL_CLKSOURCE_VAL_AHB          1
/* Returns 1 if timer counted to 0 since last time this was read */
#define STK_CTRL_COUNTFLAG_LSB  16
#define STK_CTRL_COUNTFLAG_MASK (1 << STK_CTRL_COUNTFLAG_LSB)

/*
 * Reload value register bits
 */
/* Reload value */
#define STK_LOAD_RELOAD_LSB     0
#define STK_LOAD_RELOAD_MSB     23
#define STK_LOAD_RELOAD_MASK    (0xffffff << STK_LOAD_RELOAD_LSB)

/*
 * Current value register bits
 */
/* Current counter value */
#define STK_VAL_CURRENT_LSB     0
#define STK_VAL_CURRENT_MSB     23
#define STK_VAL_CURRENT_MASK    (0xffffff << STK_VAL_CURRENT_LSB)

/*
 * Calibration value register bits
 */
/* Calibration value */
#define STK_CALIB_TENMS_LSB     0
#define STK_CALIB_TENMS_MSB     23
#define STK_CALIB_TENMS_MASK    (0xffffff << STK_CALIB_TENMS_LSB)
/* SKEW flag */
#define STK_CALIB_SKEW_LSB      30
#define STK_CALIB_SKEW_MASK     (1 << STK_CALIB_SKEW_LSB)
/* NOREF flag */
#define STK_CALIB_NOREF_LSB     31
#define STK_CALIB_NOREF_MASK    (1 << STK_CALIB_NOREF_LSB)

#endif /* _ARM_STK_H */
