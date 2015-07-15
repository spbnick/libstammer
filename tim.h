/*
 * TIM (timer)
 */

#ifndef _TIM_H
#define _TIM_H

/* TIM (timer) */
struct tim {
    unsigned int cr1;   /* Control register 1 */
    unsigned int cr2;   /* Control register 2 */
    unsigned int smcr;  /* Slave mode control register */
    unsigned int dier;  /* DMA/interrupt enable register */
    unsigned int sr;    /* Status register */
    unsigned int egr;   /* Event generation register */
    unsigned int ccmr1; /* Capture/compare mode register 1 */
    unsigned int ccmr2; /* Capture/compare mode register 2 */
    unsigned int ccer;  /* Capture/compare enable register */
    unsigned int cnt;   /* Counter */
    unsigned int psc;   /* Prescaler */
    unsigned int arr;   /* Auto-reload register */
    unsigned int rcr;   /* Repition counter register */
    unsigned int ccr1;  /* Capture/compare register 1 */
    unsigned int ccr2;  /* Capture/compare register 2 */
    unsigned int ccr3;  /* Capture/compare register 3 */
    unsigned int ccr4;  /* Capture/compare register 4 */
    unsigned int bdtr;  /* Break and dead-time register */
    unsigned int dcr;   /* DMA control register */
    unsigned int dmar;  /* DMA address register (address for full transfer) */
};

/* The TIM1 (advanced control timer) instance */
#define TIM1 ((volatile struct tim *)0x40012c00)
/* The TIM2 (general purpose timer) instance */
#define TIM2 ((volatile struct tim *)0x40000000)
/* The TIM3 (general purpose timer) instance */
#define TIM3 ((volatile struct tim *)0x40000400)
/* The TIM4 (general purpose timer) instance */
#define TIM4 ((volatile struct tim *)0x40000800)

/*
 * Control register 1 bits
 */
/* Counter enable */
#define TIM_CR1_CEN_LSB     0
#define TIM_CR1_CEN_MASK    (1 << TIM_CR1_CEN_LSB)
#define TIM_CR1_CEN_VAL_DISABLED    0
#define TIM_CR1_CEN_VAL_ENABLED     1
/* Update disable */
#define TIM_CR1_UDIS_LSB     1
#define TIM_CR1_UDIS_MASK    (1 << TIM_CR1_UDIS_LSB)
#define TIM_CR1_UDIS_VAL_UEV_ENABLED    0
#define TIM_CR1_UDIS_VAL_UEV_DISABLED   1
/* Update request source */
#define TIM_CR1_URS_LSB     2
#define TIM_CR1_URS_MASK    (1 << TIM_CR1_URS_LSB)
#define TIM_CR1_URS_VAL_ANY     0
#define TIM_CR1_URS_VAL_COUNTER 1
/* One pulse mode */
#define TIM_CR1_OPM_LSB     3
#define TIM_CR1_OPM_MASK    (1 << TIM_CR1_OPM_LSB)
#define TIM_CR1_OPM_VAL_DISABLED    0
#define TIM_CR1_OPM_VAL_ENABLED     1
/* Direction */
#define TIM_CR1_DIR_LSB     4
#define TIM_CR1_DIR_MASK    (1 << TIM_CR1_DIR_LSB)
#define TIM_CR1_DIR_VAL_UP      0
#define TIM_CR1_DIR_VAL_DOWN    1
/* Center-aligned mode selection */
#define TIM_CR1_CMS_LSB     5
#define TIM_CR1_CMS_MSB     6
#define TIM_CR1_CMS_MASK    (3 << TIM_CR1_CMS_LSB)
#define TIM_CR1_CMS_VAL_EDGE            0   /* Edge-aligned */
#define TIM_CR1_CMS_VAL_CENTER_OC_DOWN  1   /* Center-aligned, OC when down */
#define TIM_CR1_CMS_VAL_CENTER_OC_UP    2   /* Center-aligned, OC when up */
#define TIM_CR1_CMS_VAL_CENTER_OC_BOTH  3   /* Center-aligned, OC when both */
/* Auto-reload preload enable */
#define TIM_CR1_ARPE_LSB    7
#define TIM_CR1_ARPE_MASK   (1 << TIM_CR1_ARPE_LSB)
/* Clock division */
#define TIM_CR1_CKD_LSB     8
#define TIM_CR1_CKD_MSB     9
#define TIM_CR1_CKD_MASK    (3 << TIM_CR1_CKD_LSB)
#define TIM_CR1_CKD_VAL_1X  0   /* 1 x t(CK_INT) */
#define TIM_CR1_CKD_VAL_2X  1   /* 2 x t(CK_INT) */
#define TIM_CR1_CKD_VAL_4X  2   /* 4 x t(CK_INT) */

/*
 * Control register 2 bits
 */
/* Capture/compare DMA selection */
#define TIM_CR2_CCDS_LSB    3
#define TIM_CR2_CCDS_MASK   (1 << TIM_CR1_CCDS_LSB)
#define TIM_CR2_CCDS_VAL_CC     0
#define TIM_CR2_CCDS_VAL_UPDATE 1
/* Master mode selection */
#define TIM_CR2_MMS_LSB     4
#define TIM_CR2_MMS_MSB     6
#define TIM_CR2_MMS_MASK    (3 << TIM_CR1_MMS_LSB)
#define TIM_CR2_MMS_VAL_RESET           0
#define TIM_CR2_MMS_VAL_ENABLE          1
#define TIM_CR2_MMS_VAL_UPDATE          2
#define TIM_CR2_MMS_VAL_COMPARE_PULSE   3
#define TIM_CR2_MMS_VAL_COMPARE_OC1     4
#define TIM_CR2_MMS_VAL_COMPARE_OC2     5
#define TIM_CR2_MMS_VAL_COMPARE_OC3     6
#define TIM_CR2_MMS_VAL_COMPARE_OC4     7
/* TI1 selection */
#define TIM_CR2_TI1S_LSB    7
#define TIM_CR2_TI1S_MASK   (1 << TIM_CR1_TI1S_LSB)
#define TIM_CR2_TI1S_VAL_CH1        0   /* CH1 */
#define TIM_CR2_TI1S_VAL_CH123_XOR  1   /* CH1 ^ CH2 ^ CH3 */

/*
 * DMA/interrupt enable register bits
 */
/* Update interrupt enable */
#define TIM_DIER_UIE_LSB    0
#define TIM_DIER_UIE_MASK   (1 << TIM_DIER_UIE_LSB)
/* Capture/compare 1 interrupt enable */
#define TIM_DIER_CC1IE_LSB  1
#define TIM_DIER_CC1IE_MASK (1 << TIM_DIER_CC1IE_LSB)
/* Capture/compare 2 interrupt enable */
#define TIM_DIER_CC2IE_LSB  2
#define TIM_DIER_CC2IE_MASK (1 << TIM_DIER_CC2IE_LSB)
/* Capture/compare 3 interrupt enable */
#define TIM_DIER_CC3IE_LSB  3
#define TIM_DIER_CC3IE_MASK (1 << TIM_DIER_CC3IE_LSB)
/* Capture/compare 4 interrupt enable */
#define TIM_DIER_CC4IE_LSB  4
#define TIM_DIER_CC4IE_MASK (1 << TIM_DIER_CC4IE_LSB)
/* Trigger interrupt enable */
#define TIM_DIER_TIE_LSB    6
#define TIM_DIER_TIE_MASK   (1 << TIM_DIER_TIE_LSB)
/* Update DMA request enable */
#define TIM_DIER_UDE_LSB    8
#define TIM_DIER_UDE_MASK   (1 << TIM_DIER_UDE_LSB)
/* Capture/compare 1 DMA request enable */
#define TIM_DIER_CC1DE_LSB  9
#define TIM_DIER_CC1DE_MASK (1 << TIM_DIER_CC1DE_LSB)
/* Capture/compare 2 DMA request enable */
#define TIM_DIER_CC2DE_LSB  10
#define TIM_DIER_CC2DE_MASK (1 << TIM_DIER_CC2DE_LSB)
/* Capture/compare 3 DMA request enable */
#define TIM_DIER_CC3DE_LSB  11
#define TIM_DIER_CC3DE_MASK (1 << TIM_DIER_CC3DE_LSB)
/* Capture/compare 4 DMA request enable */
#define TIM_DIER_CC4DE_LSB  12
#define TIM_DIER_CC4DE_MASK (1 << TIM_DIER_CC4DE_LSB)
/* Trigger DMA request enable */
#define TIM_DIER_TDE_LSB    14
#define TIM_DIER_TDE_MASK   (1 << TIM_DIER_TDE_LSB)

/*
 * Status register bits
 */
/* Update interrupt flag */
#define TIM_SR_UIF_LSB      0
#define TIM_SR_UIF_MASK     (1 << TIM_SR_UIF_LSB)
/* Capture/compare 1 interrupt flag */
#define TIM_SR_CC1IF_LSB    1
#define TIM_SR_CC1IF_MASK   (1 << TIM_SR_CC1IF_LSB)
/* Capture/compare 2 interrupt flag */
#define TIM_SR_CC2IF_LSB    2
#define TIM_SR_CC2IF_MASK   (1 << TIM_SR_CC2IF_LSB)
/* Capture/compare 3 interrupt flag */
#define TIM_SR_CC3IF_LSB    3
#define TIM_SR_CC3IF_MASK   (1 << TIM_SR_CC3IF_LSB)
/* Capture/compare 4 interrupt flag */
#define TIM_SR_CC4IF_LSB    4
#define TIM_SR_CC4IF_MASK   (1 << TIM_SR_CC4IF_LSB)
/* Trigger interrupt flag */
#define TIM_SR_TIF_LSB      6
#define TIM_SR_TIF_MASK     (1 << TIM_SR_TIF_LSB)
/* Capture/compare 1 overcapture flag */
#define TIM_SR_CC1OF_LSB    9
#define TIM_SR_CC1OF_MASK   (1 << TIM_SR_CC1OF_LSB)
/* Capture/compare 2 overcapture flag */
#define TIM_SR_CC2OF_LSB    10
#define TIM_SR_CC2OF_MASK   (1 << TIM_SR_CC2OF_LSB)
/* Capture/compare 3 overcapture flag */
#define TIM_SR_CC3OF_LSB    11
#define TIM_SR_CC3OF_MASK   (1 << TIM_SR_CC3OF_LSB)
/* Capture/compare 4 overcapture flag */
#define TIM_SR_CC4OF_LSB    12
#define TIM_SR_CC4OF_MASK   (1 << TIM_SR_CC4OF_LSB)

/*
 * Event generation register bits
 */
/* Update generation */
#define TIM_EGR_UG_LSB      0
#define TIM_EGR_UG_MASK     (1 << TIM_EGR_UG_LSB)
/* Capture/compare 1 generation */
#define TIM_EGR_CC1G_LSB    1
#define TIM_EGR_CC1G_MASK   (1 << TIM_EGR_CC1G_LSB)
/* Capture/compare 2 generation */
#define TIM_EGR_CC2G_LSB    2
#define TIM_EGR_CC2G_MASK   (1 << TIM_EGR_CC2G_LSB)
/* Capture/compare 3 generation */
#define TIM_EGR_CC3G_LSB    3
#define TIM_EGR_CC3G_MASK   (1 << TIM_EGR_CC3G_LSB)
/* Capture/compare 4 generation */
#define TIM_EGR_CC4G_LSB    4
#define TIM_EGR_CC4G_MASK   (1 << TIM_EGR_CC4G_LSB)
/* Trigger generation */
#define TIM_EGR_TG_LSB      6
#define TIM_EGR_TG_MASK     (1 << TIM_EGR_TG_LSB)
/* Break generation */
#define TIM_EGR_BG_LSB      7
#define TIM_EGR_BG_MASK     (1 << TIM_EGR_BG_LSB)

/*
 * Capture/compare mode register 1 bits
 */
/* Capture/compare 1 selection */
#define TIM_CCMR1_CC1S_LSB      0
#define TIM_CCMR1_CC1S_MSB      1
#define TIM_CCMR1_CC1S_MASK     (3 << TIM_CCMR1_CC1S_LSB)
/* Input capture 1 prescaler */
#define TIM_CCMR1_IC1PSC_LSB    2
#define TIM_CCMR1_IC1PSC_MSB    3
#define TIM_CCMR1_IC1PSC_MASK   (3 << TIM_CCMR1_IC1PSC_LSB)
/* Input capture 1 filter */
#define TIM_CCMR1_IC1F_LSB      4
#define TIM_CCMR1_IC1F_MSB      7
#define TIM_CCMR1_IC1F_MASK     (0xf << TIM_CCMR1_IC1F_LSB)

/* Output compare 1 fast enable */
#define TIM_CCMR1_OC1FE_LSB     2
#define TIM_CCMR1_OC1FE_MASK    (1 << TIM_CCMR1_OC1FE_LSB)
/* Output compare 1 preload enable */
#define TIM_CCMR1_OC1PE_LSB     3
#define TIM_CCMR1_OC1PE_MASK    (1 << TIM_CCMR1_OC1PE_LSB)
/* Output compare 1 mode */
#define TIM_CCMR1_OC1M_LSB      4
#define TIM_CCMR1_OC1M_MSB      6
#define TIM_CCMR1_OC1M_MASK     (0x7 << TIM_CCMR1_OC1M_LSB)
/* Output compare 1 clear enable */
#define TIM_CCMR1_OC1CE_LSB     7
#define TIM_CCMR1_OC1CE_MASK    (1 << TIM_CCMR1_OC1CE_LSB)

/* Capture/compare 2 selection */
#define TIM_CCMR1_CC2S_LSB      8
#define TIM_CCMR1_CC2S_MSB      9
#define TIM_CCMR1_CC2S_MASK     (3 << TIM_CCMR1_CC2S_LSB)
/* Input capture 2 prescaler */
#define TIM_CCMR1_IC2PSC_LSB    10
#define TIM_CCMR1_IC2PSC_MSB    11
#define TIM_CCMR1_IC2PSC_MASK   (3 << TIM_CCMR1_IC2PSC_LSB)
/* Input capture 2 filter */
#define TIM_CCMR1_IC2F_LSB      12
#define TIM_CCMR1_IC2F_MSB      15
#define TIM_CCMR1_IC2F_MASK     (0xf << TIM_CCMR1_IC2F_LSB)

/* Output compare 2 fast enable */
#define TIM_CCMR1_OC2FE_LSB     10
#define TIM_CCMR1_OC2FE_MASK    (1 << TIM_CCMR1_OC2FE_LSB)
/* Output compare 2 preload enable */
#define TIM_CCMR1_OC2PE_LSB     11
#define TIM_CCMR1_OC2PE_MASK    (1 << TIM_CCMR1_OC2PE_LSB)
/* Output compare 2 mode */
#define TIM_CCMR1_OC2M_LSB      12
#define TIM_CCMR1_OC2M_MSB      14
#define TIM_CCMR1_OC2M_MASK     (0x7 << TIM_CCMR1_OC2M_LSB)
/* Output compare 2 clear enable */
#define TIM_CCMR1_OC2CE_LSB     15
#define TIM_CCMR1_OC2CE_MASK    (1 << TIM_CCMR1_OC2CE_LSB)

/* Capture/compare Y selection value */
#define TIM_CCMR1_CCYS_VAL_OUT      0x0
#define TIM_CCMR1_CCYS_VAL_IN_TI1   0x1
#define TIM_CCMR1_CCYS_VAL_IN_TI2   0x2
#define TIM_CCMR1_CCYS_VAL_IN_TRC   0x3

/*
 * Capture/compare mode register 2 bits
 */
/* Capture/compare 3 selection */
#define TIM_CCMR2_CC3S_LSB      0
#define TIM_CCMR2_CC3S_MSB      1
#define TIM_CCMR2_CC3S_MASK     (3 << TIM_CCMR2_CC3S_LSB)
/* Input capture 3 prescaler */
#define TIM_CCMR2_IC3PSC_LSB    2
#define TIM_CCMR2_IC3PSC_MSB    3
#define TIM_CCMR2_IC3PSC_MASK   (3 << TIM_CCMR2_IC3PSC_LSB)
/* Input capture 3 filter */
#define TIM_CCMR2_IC3F_LSB      4
#define TIM_CCMR2_IC3F_MSB      7
#define TIM_CCMR2_IC3F_MASK     (0xf << TIM_CCMR2_IC3F_LSB)

/* Output compare 3 fast enable */
#define TIM_CCMR2_OC3FE_LSB     2
#define TIM_CCMR2_OC3FE_MASK    (1 << TIM_CCMR2_OC3FE_LSB)
/* Output compare 3 preload enable */
#define TIM_CCMR2_OC3PE_LSB     3
#define TIM_CCMR2_OC3PE_MASK    (1 << TIM_CCMR2_OC3PE_LSB)
/* Output compare 3 mode */
#define TIM_CCMR2_OC3M_LSB      4
#define TIM_CCMR2_OC3M_MSB      6
#define TIM_CCMR2_OC3M_MASK     (0x7 << TIM_CCMR2_OC3M_LSB)
/* Output compare 3 clear enable */
#define TIM_CCMR2_OC3CE_LSB     7
#define TIM_CCMR2_OC3CE_MASK    (1 << TIM_CCMR2_OC3CE_LSB)

/* Capture/compare 4 selection */
#define TIM_CCMR2_CC4S_LSB      8
#define TIM_CCMR2_CC4S_MSB      9
#define TIM_CCMR2_CC4S_MASK     (3 << TIM_CCMR2_CC4S_LSB)
/* Input capture 4 prescaler */
#define TIM_CCMR2_IC4PSC_LSB    10
#define TIM_CCMR2_IC4PSC_MSB    11
#define TIM_CCMR2_IC4PSC_MASK   (3 << TIM_CCMR2_IC4PSC_LSB)
/* Input capture 4 filter */
#define TIM_CCMR2_IC4F_LSB      12
#define TIM_CCMR2_IC4F_MSB      15
#define TIM_CCMR2_IC4F_MASK     (0xf << TIM_CCMR2_IC4F_LSB)

/* Output compare 4 fast enable */
#define TIM_CCMR2_OC4FE_LSB     10
#define TIM_CCMR2_OC4FE_MASK    (1 << TIM_CCMR2_OC4FE_LSB)
/* Output compare 4 preload enable */
#define TIM_CCMR2_OC4PE_LSB     11
#define TIM_CCMR2_OC4PE_MASK    (1 << TIM_CCMR2_OC4PE_LSB)
/* Output compare 4 mode */
#define TIM_CCMR2_OC4M_LSB      12
#define TIM_CCMR2_OC4M_MSB      14
#define TIM_CCMR2_OC4M_MASK     (0x7 << TIM_CCMR2_OC4M_LSB)
/* Output compare 4 clear enable */
#define TIM_CCMR2_OC4CE_LSB     15
#define TIM_CCMR2_OC4CE_MASK    (1 << TIM_CCMR2_OC4CE_LSB)

/* Capture/compare Y selection value */
#define TIM_CCMR2_CCYS_VAL_OUT      0x0
#define TIM_CCMR2_CCYS_VAL_IN_TI3   0x1
#define TIM_CCMR2_CCYS_VAL_IN_TI4   0x2
#define TIM_CCMR2_CCYS_VAL_IN_TRC   0x3

/*
 * Capture/compare mode register X values
 */
/* Input capture Y prescaler value */
#define TIM_CCMRX_ICYPSC_VAL_1X     0x0
#define TIM_CCMRX_ICYPSC_VAL_2X     0x1
#define TIM_CCMRX_ICYPSC_VAL_4X     0x2
#define TIM_CCMRX_ICYPSC_VAL_8X     0x3

/* Input capture Y filter value */
#define TIM_CCMRX_ICYF_VAL_FDTS         0x0
#define TIM_CCMRX_ICYF_VAL_FCK_INT_N2   0x1
#define TIM_CCMRX_ICYF_VAL_FCK_INT_N4   0x2
#define TIM_CCMRX_ICYF_VAL_FCK_INT_N8   0x3
#define TIM_CCMRX_ICYF_VAL_FDTS2_N6     0x4
#define TIM_CCMRX_ICYF_VAL_FDTS2_N8     0x5
#define TIM_CCMRX_ICYF_VAL_FDTS4_N6     0x6
#define TIM_CCMRX_ICYF_VAL_FDTS4_N8     0x7
#define TIM_CCMRX_ICYF_VAL_FDTS8_N6     0x8
#define TIM_CCMRX_ICYF_VAL_FDTS8_N8     0x9
#define TIM_CCMRX_ICYF_VAL_FDTS16_N5    0xa
#define TIM_CCMRX_ICYF_VAL_FDTS16_N6    0xb
#define TIM_CCMRX_ICYF_VAL_FDTS16_N8    0xc
#define TIM_CCMRX_ICYF_VAL_FDTS32_N5    0xd
#define TIM_CCMRX_ICYF_VAL_FDTS32_N6    0xe
#define TIM_CCMRX_ICYF_VAL_FDTS32_N8    0xf

/* Output compare Y mode value */
#define TIM_CCMRX_OCYM_VAL_FROZEN           0x0
#define TIM_CCMRX_OCYM_VAL_ACTIVE_MATCH     0x1
#define TIM_CCMRX_OCYM_VAL_INACTIVE_MATCH   0x2
#define TIM_CCMRX_OCYM_VAL_TOGGLE           0x3
#define TIM_CCMRX_OCYM_VAL_FORCE_INACTIVE   0x4
#define TIM_CCMRX_OCYM_VAL_FORCE_ACTIVE     0x5
#define TIM_CCMRX_OCYM_VAL_PWM_MODE1        0x6
#define TIM_CCMRX_OCYM_VAL_PWM_MODE2        0x7

/*
 * Capture/compare enable register bits
 */
/* Capture/compare 1 output enable */
#define TIM_CCER_CC1E_LSB       0
#define TIM_CCER_CC1E_MASK      (1 << TIM_CCER_CC1E_LSB)
/* Capture/compare 1 output polarity */
#define TIM_CCER_CC1P_LSB       1
#define TIM_CCER_CC1P_MASK      (1 << TIM_CCER_CC1P_LSB)
/* Capture/compare 1 complementary output enable */
#define TIM_CCER_CC1NE_LSB      2
#define TIM_CCER_CC1NE_MASK     (1 << TIM_CCER_CC1NE_LSB)
/* Capture/compare 1 output polarity */
#define TIM_CCER_CC1NP_LSB      3
#define TIM_CCER_CC1NP_MASK     (1 << TIM_CCER_CC1NP_LSB)
/* Capture/compare 2 output enable */
#define TIM_CCER_CC2E_LSB       4
#define TIM_CCER_CC2E_MASK      (1 << TIM_CCER_CC2E_LSB)
/* Capture/compare 2 output polarity */
#define TIM_CCER_CC2P_LSB       5
#define TIM_CCER_CC2P_MASK      (1 << TIM_CCER_CC2P_LSB)
/* Capture/compare 2 complementary output enable */
#define TIM_CCER_CC2NE_LSB      6
#define TIM_CCER_CC2NE_MASK     (1 << TIM_CCER_CC2NE_LSB)
/* Capture/compare 2 output polarity */
#define TIM_CCER_CC2NP_LSB      7
#define TIM_CCER_CC2NP_MASK     (1 << TIM_CCER_CC2NP_LSB)
/* Capture/compare 3 output enable */
#define TIM_CCER_CC3E_LSB       8
#define TIM_CCER_CC3E_MASK      (1 << TIM_CCER_CC3E_LSB)
/* Capture/compare 3 output polarity */
#define TIM_CCER_CC3P_LSB       9
#define TIM_CCER_CC3P_MASK      (1 << TIM_CCER_CC3P_LSB)
/* Capture/compare 3 complementary output enable */
#define TIM_CCER_CC3NE_LSB      10
#define TIM_CCER_CC3NE_MASK     (1 << TIM_CCER_CC3NE_LSB)
/* Capture/compare 3 output polarity */
#define TIM_CCER_CC3NP_LSB      11
#define TIM_CCER_CC3NP_MASK     (1 << TIM_CCER_CC3NP_LSB)
/* Capture/compare 4 output enable */
#define TIM_CCER_CC4E_LSB       12
#define TIM_CCER_CC4E_MASK      (1 << TIM_CCER_CC4E_LSB)
/* Capture/compare 4 output polarity */
#define TIM_CCER_CC4P_LSB       13
#define TIM_CCER_CC4P_MASK      (1 << TIM_CCER_CC4P_LSB)

/*
 * Break and dead-time register bits
 */
/* Dead-time generator setup */
#define TIM_BDTR_DTG_LSB        0
#define TIM_BDTR_DTG_MSB        7
#define TIM_BDTR_DTG_MASK       (0xff << TIM_BDTR_DTG_LSB)
/* Lock configuration */
#define TIM_BDTR_LOCK_LSB       8
#define TIM_BDTR_LOCK_MSB       9
#define TIM_BDTR_LOCK_MASK      (0x3 << TIM_BDTR_LOCK_LSB)
#define TIM_BDTR_LOCK_VAL_OFF   0x0
#define TIM_BDTR_LOCK_VAL_LVL1  0x1
#define TIM_BDTR_LOCK_VAL_LVL2  0x2
#define TIM_BDTR_LOCK_VAL_LVL3  0x3
/* Off-state selection for idle mode */
#define TIM_BDTR_OSSI_MSB       10
#define TIM_BDTR_OSSI_MASK      (1 << TIM_BDTR_OSSI_LSB)
/* Off-state selection for run mode */
#define TIM_BDTR_OSSR_MSB       11
#define TIM_BDTR_OSSR_MASK      (1 << TIM_BDTR_OSSR_LSB)
/* Break enable */
#define TIM_BDTR_BKE_MSB        12
#define TIM_BDTR_BKE_MASK       (1 << TIM_BDTR_BKE_LSB)
/* Break polarity */
#define TIM_BDTR_BKP_MSB        13
#define TIM_BDTR_BKP_MASK       (1 << TIM_BDTR_BKP_LSB)
/* Automatic output enable */
#define TIM_BDTR_AOE_MSB        14
#define TIM_BDTR_AOE_MASK       (1 << TIM_BDTR_AOE_LSB)
/* Main output enable */
#define TIM_BDTR_MOE_MSB        15
#define TIM_BDTR_MOE_MASK       (1 << TIM_BDTR_MOE_LSB)

/*
 * DMA control register bits
 */
/* DMA base address */
#define TIM_DCR_DBA_LSB         0
#define TIM_DCR_DBA_MSB         4
#define TIM_DCR_DBA_MASK        (0x1f << TIM_DCR_DBA_LSB)
/* DMA burst length */
#define TIM_DCR_DBL_LSB         8
#define TIM_DCR_DBL_MSB         12
#define TIM_DCR_DBL_MASK        (0x1f << TIM_DCR_DBL_LSB)

#endif /* _TIM_H */
