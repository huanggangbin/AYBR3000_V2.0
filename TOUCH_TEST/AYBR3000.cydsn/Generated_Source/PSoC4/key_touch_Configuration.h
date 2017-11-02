/*******************************************************************************
* \file       key_touch_Configuration.h
* \version    3.10
*
* \brief
*   This file provides the customizer parameters definitions.
*
* \see CapSense P4 v3.10 Datasheet
*
*//*****************************************************************************
* Copyright (2016), Cypress Semiconductor Corporation.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#if !defined(CY_CAPSENSE_key_touch_CONFIGURATION_H)
#define CY_CAPSENSE_key_touch_CONFIGURATION_H

#include <cytypes.h>

/*******************************************************************************
* Customizer-generated defines
*******************************************************************************/
#define key_touch_ENABLE                   (1u)
#define key_touch_DISABLE                  (0u)

/*******************************************************************************
* Creator-global defines
*******************************************************************************/
#ifdef CYIPBLOCK_m0s8csdv2_VERSION
    #define key_touch_CSDV2                              (1u)
#else
    #define key_touch_CSDV2                              (0u)
#endif  /* CYIPBLOCK_m0s8csdv2_VERSION */

#define key_touch_2000_MV                            (2000u)

#ifdef CYDEV_VDDA_MV
    #define key_touch_CYDEV_VDDA_MV                  (CYDEV_VDDA_MV)
#else
    #define key_touch_CYDEV_VDDA_MV                  (CYDEV_VDD_MV)
#endif  /* #ifdef CYDEV_VDDA_MV */

#define key_touch_BAD_CONVERSIONS_NUM                (1u)
#define key_touch_RESAMPLING_CYCLES_MAX_NUMBER       (1u)

/*******************************************************************************
* Enabled Scan Methods
*******************************************************************************/
#define key_touch_CSD_EN                   (1u)
#define key_touch_CSX_EN                   (0u)
#define key_touch_CSD_CSX_EN               (key_touch_CSD_EN & key_touch_CSX_EN)
#define key_touch_CSD2X_EN                 (0u)
#define key_touch_CSX2X_EN                 (0u)

/*******************************************************************************
* Definitions for number of widgets and sensors
*******************************************************************************/
#define key_touch_TOTAL_WIDGETS            (12u)
#define key_touch_TOTAL_CSD_WIDGETS        (12u)
#define key_touch_TOTAL_CSD_SENSORS        (12u)
#define key_touch_TOTAL_CSX_WIDGETS        (0u)
#define key_touch_TOTAL_CSX_NODES          (0u)

/*******************************************************************************
* Total number of CSD sensors + CSX nodes
*******************************************************************************/
#define key_touch_TOTAL_SENSORS            (key_touch_TOTAL_CSD_SENSORS + \
                                                   key_touch_TOTAL_CSX_NODES)

/*******************************************************************************
* Total number of scan slots (used only when dual-channel scan is enabled)
*******************************************************************************/
#define key_touch_TOTAL_SCAN_SLOTS         (12u)

/*******************************************************************************
* Define widget IDs
*******************************************************************************/
#define key_touch_BUTTON0_WDGT_ID               (0u)
#define key_touch_BUTTON1_WDGT_ID               (1u)
#define key_touch_BUTTON2_WDGT_ID               (2u)
#define key_touch_BUTTON3_WDGT_ID               (3u)
#define key_touch_BUTTON4_WDGT_ID               (4u)
#define key_touch_BUTTON5_WDGT_ID               (5u)
#define key_touch_BUTTON6_WDGT_ID               (6u)
#define key_touch_BUTTON7_WDGT_ID               (7u)
#define key_touch_BUTTON8_WDGT_ID               (8u)
#define key_touch_BUTTON9_WDGT_ID               (9u)
#define key_touch_BUTTON10_WDGT_ID              (10u)
#define key_touch_BUTTON11_WDGT_ID              (11u)

/*******************************************************************************
* Define sensor IDs
*******************************************************************************/

/* Button0 */
#define key_touch_BUTTON0_SNS0_ID               (0u)

/* Button1 */
#define key_touch_BUTTON1_SNS0_ID               (0u)

/* Button2 */
#define key_touch_BUTTON2_SNS0_ID               (0u)

/* Button3 */
#define key_touch_BUTTON3_SNS0_ID               (0u)

/* Button4 */
#define key_touch_BUTTON4_SNS0_ID               (0u)

/* Button5 */
#define key_touch_BUTTON5_SNS0_ID               (0u)

/* Button6 */
#define key_touch_BUTTON6_SNS0_ID               (0u)

/* Button7 */
#define key_touch_BUTTON7_SNS0_ID               (0u)

/* Button8 */
#define key_touch_BUTTON8_SNS0_ID               (0u)

/* Button9 */
#define key_touch_BUTTON9_SNS0_ID               (0u)

/* Button10 */
#define key_touch_BUTTON10_SNS0_ID              (0u)

/* Button11 */
#define key_touch_BUTTON11_SNS0_ID              (0u)



/*******************************************************************************
* Enabled widget types
*******************************************************************************/
#define key_touch_BUTTON_WIDGET_EN         (1u)
#define key_touch_SLIDER_WIDGET_EN         (0u)
#define key_touch_MATRIX_WIDGET_EN         (0u)
#define key_touch_PROXIMITY_WIDGET_EN      (0u)
#define key_touch_TOUCHPAD_WIDGET_EN       (0u)

#define key_touch_CSD_MATRIX_WIDGET_EN     (0u)
#define key_touch_CSD_TOUCHPAD_WIDGET_EN   (0u)

#define key_touch_CSX_MATRIX_WIDGET_EN     (0u)
#define key_touch_CSX_TOUCHPAD_WIDGET_EN   (0u)

/*******************************************************************************
* Centroid APIs
*******************************************************************************/
#define key_touch_CENTROID_EN              (0u)
#define key_touch_TOTAL_DIPLEXED_SLIDERS   (0u)
#define key_touch_TOTAL_LINEAR_SLIDERS     (0u)
#define key_touch_TOTAL_RADIAL_SLIDERS     (0u)
#define key_touch_TOTAL_TOUCHPADS          (0u)
#define key_touch_MAX_CENTROID_LENGTH      (0u)

/*******************************************************************************
* Enabled sensor types
*******************************************************************************/
#define key_touch_REGULAR_SENSOR_EN        (1u)
#define key_touch_PROXIMITY_SENSOR_EN      (0u)

/*******************************************************************************
* Sensor ganging
*******************************************************************************/
#define key_touch_GANGED_SNS_EN            (0u)
#define key_touch_CSD_GANGED_SNS_EN        (0u)
#define key_touch_CSX_GANGED_SNS_EN        (0u)

/*******************************************************************************
* Max number of sensors used among all widgets
*******************************************************************************/
#define key_touch_MAX_SENSORS_PER_WIDGET   (1u)

/*******************************************************************************
* Total number of all used electrodes (NOT unique)
*******************************************************************************/
#define key_touch_TOTAL_ELECTRODES         (12u)
/* Obsolete */
#define key_touch_TOTAL_SENSOR_IOS         key_touch_TOTAL_ELECTRODES

/*******************************************************************************
* Total number of used physical IOs (unique)
*******************************************************************************/
#define key_touch_TOTAL_IO_CNT             (12u)

/*******************************************************************************
* Array length for widget status registers
*******************************************************************************/
#define key_touch_WDGT_STATUS_WORDS        \
                        (((uint8)((key_touch_TOTAL_WIDGETS - 1u) / 32u)) + 1u)


/*******************************************************************************
* Auto-tuning mode selection
*******************************************************************************/
#define key_touch_CSD_SS_DIS         (0x00ul)
#define key_touch_CSD_SS_HW_EN       (0x01ul)
#define key_touch_CSD_SS_TH_EN       (0x02ul)
#define key_touch_CSD_SS_HWTH_EN     (key_touch_CSD_SS_HW_EN | \
                                             key_touch_CSD_SS_TH_EN)

#define key_touch_CSD_AUTOTUNE       key_touch_CSD_SS_HWTH_EN


/*******************************************************************************
* General settings
*******************************************************************************/

#define key_touch_AUTO_RESET_METHOD_LEGACY (0u)
#define key_touch_AUTO_RESET_METHOD_SAMPLE (1u)

#define key_touch_MULTI_FREQ_SCAN_EN       (0u)
#define key_touch_SENSOR_AUTO_RESET_EN     (0u)
#define key_touch_SENSOR_AUTO_RESET_METHOD (0u)
#define key_touch_NUM_CENTROIDS            (1u)
#define key_touch_OFF_DEBOUNCE_EN          (0u)

/* Define power status of HW IP block after scanning */
#define key_touch_BLOCK_OFF_AFTER_SCAN_EN  (0u)

/* Define number of scan frequencies */
#if (key_touch_DISABLE != key_touch_MULTI_FREQ_SCAN_EN)
    #define key_touch_NUM_SCAN_FREQS       (3u)
#else
    #define key_touch_NUM_SCAN_FREQS       (1u)
#endif /* #if (key_touch_DISABLE != key_touch_MULTI_FREQ_SCAN_EN) */

/* Data size for thresholds / low baseline reset */
#define key_touch_SIZE_8BITS               (8u)
#define key_touch_SIZE_16BITS              (16u)

#define key_touch_THRESHOLD_SIZE           key_touch_SIZE_16BITS
typedef uint16 key_touch_THRESHOLD_TYPE;

#if (key_touch_AUTO_RESET_METHOD_LEGACY == key_touch_SENSOR_AUTO_RESET_METHOD)
    #define key_touch_LOW_BSLN_RST_SIZE        key_touch_SIZE_8BITS
    typedef uint8 key_touch_LOW_BSLN_RST_TYPE;
#else
    #define key_touch_LOW_BSLN_RST_SIZE    (16u)
    typedef uint16 key_touch_LOW_BSLN_RST_TYPE;
#endif /* #if (key_touch_AUTO_RESET_METHOD_LEGACY == key_touch_SENSOR_AUTO_RESET_METHOD) */

/* Coefficient to define touch threshold for proximity sensors */
#define key_touch_PROX_TOUCH_COEFF         (300u)

/*******************************************************************************
* General Filter Constants
*******************************************************************************/

/* Baseline algorithm options */
#define key_touch_IIR_BASELINE                 (0u)
#define key_touch_BUCKET_BASELINE              (1u)

#define key_touch_BASELINE_TYPE                key_touch_IIR_BASELINE

/* IIR baseline filter algorithm for regular sensors*/
#define key_touch_REGULAR_IIR_BL_TYPE          key_touch_IIR_FILTER_PERFORMANCE

/* IIR baseline coefficients for regular sensors */
#define key_touch_REGULAR_IIR_BL_N             (1u)
#define key_touch_REGULAR_IIR_BL_SHIFT         (8u)

/* IIR baseline filter algorithm for proximity sensors*/
#define key_touch_PROX_IIR_BL_TYPE             key_touch_IIR_FILTER_PERFORMANCE

/* IIR baseline coefficients for proximity sensors */
#define key_touch_PROX_IIR_BL_N                (1u)
#define key_touch_PROX_IIR_BL_SHIFT            (8u)


/* IIR filter constants */
#define key_touch_IIR_COEFFICIENT_K            (256u)

/* IIR filter type */
#define key_touch_IIR_FILTER_STANDARD          (1u)
#define key_touch_IIR_FILTER_PERFORMANCE       (2u)
#define key_touch_IIR_FILTER_MEMORY            (3u)

/* Regular sensor raw-count filters */
#define key_touch_REGULAR_RC_FILTER_EN         (0u)
#define key_touch_REGULAR_RC_IIR_FILTER_EN     (0u)
#define key_touch_REGULAR_RC_MEDIAN_FILTER_EN  (0u)
#define key_touch_REGULAR_RC_AVERAGE_FILTER_EN (0u)
#define key_touch_REGULAR_RC_CUSTOM_FILTER_EN  (0u)

/* Proximity sensor raw-count filters */
#define key_touch_PROX_RC_FILTER_EN            (0u)
#define key_touch_PROX_RC_IIR_FILTER_EN        (0u)
#define key_touch_PROX_RC_MEDIAN_FILTER_EN     (0u)
#define key_touch_PROX_RC_AVERAGE_FILTER_EN    (0u)
#define key_touch_PROX_RC_CUSTOM_FILTER_EN     (0u)

/* IIR raw-count filter algorithm for regular sensors */
#define key_touch_REGULAR_IIR_RC_TYPE          (key_touch_IIR_FILTER_STANDARD)

/* IIR raw-count filter coefficients for regular sensors */
#define key_touch_REGULAR_IIR_RC_N             (128u)
#define key_touch_REGULAR_IIR_RC_SHIFT         (0u)

/* IIR raw-count filter algorithm for proximity sensors*/
#define key_touch_PROX_IIR_RC_TYPE             (key_touch_IIR_FILTER_STANDARD)

/* IIR raw-count filter coefficients for proximity sensors */
#define key_touch_PROX_IIR_RC_N                (128u)
#define key_touch_PROX_IIR_RC_SHIFT            (0u)

/* Median filter constants */

/* Order of regular sensor median filter */
#define key_touch_REGULAR_MEDIAN_LEN           (2u)

/* Order of proximity sensor median filter */
#define key_touch_PROX_MEDIAN_LEN              (2u)

/* Average filter constants*/
#define key_touch_AVERAGE_FILTER_LEN_2         (2u)
#define key_touch_AVERAGE_FILTER_LEN_4         (4u)

/* Order of regular sensor average filter */
#define key_touch_REGULAR_AVERAGE_LEN          (key_touch_AVERAGE_FILTER_LEN_4)

/* Order of proximity sensor average filter */
#define key_touch_PROX_AVERAGE_LEN             (key_touch_AVERAGE_FILTER_LEN_4)


/* Centroid position filters */
#define key_touch_POS_IIR_FILTER_EN            (0x00u)
#define key_touch_POS_MEDIAN_FILTER_EN         (0x00u)
#define key_touch_POS_AVERAGE_FILTER_EN        (0x00u)
#define key_touch_POS_JITTER_FILTER_EN         (0x00u)
#define key_touch_CSX_TOUCHPAD_POS_MEDIAN_FILTER_EN (0x00u)

#define key_touch_POS_IIR_COEFF                (128u)
#define key_touch_CSX_TOUCHPAD_UNDEFINED       (40u)


/* IDAC options */

/* CSDv1 IDAC gain */
#define key_touch_IDAC_GAIN_4X                 (4u)
#define key_touch_IDAC_GAIN_8X                 (8u)

/* CSDv2 IDAC gain */
#define key_touch_IDAC_GAIN_LOW                (0uL)
#define key_touch_IDAC_GAIN_MEDIUM             (1uL)
#define key_touch_IDAC_GAIN_HIGH               (2uL)

#define key_touch_IDAC_SOURCING                (0u)
#define key_touch_IDAC_SINKING                 (1u)

/* Shield tank capacitor precharge source */
#define key_touch_CSH_PRECHARGE_VREF           (0u)
#define key_touch_CSH_PRECHARGE_IO_BUF         (1u)

/* Shield electrode delay */
#define key_touch_NO_DELAY                     (0u)
/* CSDv1 */
#define key_touch_SH_DELAY_50NS                (1u)
#define key_touch_SH_DELAY_100NS               (2u)
/* CSDv2 */
#define key_touch_SH_DELAY_5NS                 (1u)
#define key_touch_SH_DELAY_10NS                (2u)
#define key_touch_SH_DELAY_20NS                (3u)

/* Inactive sensor connection options */
#define key_touch_SNS_CONNECTION_GROUND        (0x00000006Lu)
#define key_touch_SNS_CONNECTION_HIGHZ         (0x00000000Lu)
#define key_touch_SNS_CONNECTION_SHIELD        (0x00000002Lu)

/* Sense clock selection options */
#if defined(key_touch_TAPEOUT_STAR_USED)
    #define key_touch_CSDV2_REF9P6UA_EN            (0u)
#else
    #define key_touch_CSDV2_REF9P6UA_EN            (1u)
#endif /* defined(key_touch_TAPEOUT_A_USED) */

#define key_touch_CLK_SOURCE_DIRECT            (0x00000000Lu)

#define key_touch_CLK_SOURCE_SSC1              (0x01u)
#define key_touch_CLK_SOURCE_SSC2              (0x02u)
#define key_touch_CLK_SOURCE_SSC3              (0x03u)
#define key_touch_CLK_SOURCE_SSC4              (0x04u)

/* CSDv1 and CSDv2 */
#define key_touch_CLK_SOURCE_PRS8              (0x05u)
#define key_touch_CLK_SOURCE_PRS12             (0x06u)
#define key_touch_CLK_SOURCE_PRSAUTO           (0xFFu)

/* Defines scan resolutions */
#define key_touch_RES6BIT                      (6u)
#define key_touch_RES7BIT                      (7u)
#define key_touch_RES8BIT                      (8u)
#define key_touch_RES9BIT                      (9u)
#define key_touch_RES10BIT                     (10u)
#define key_touch_RES11BIT                     (11u)
#define key_touch_RES12BIT                     (12u)
#define key_touch_RES13BIT                     (13u)
#define key_touch_RES14BIT                     (14u)
#define key_touch_RES15BIT                     (15u)
#define key_touch_RES16BIT                     (16u)

/* CSDv2: Initialization switch resistance */
#define key_touch_INIT_SW_RES_LOW              (0x00000000Lu)
#define key_touch_INIT_SW_RES_MEDIUM           (0x00000001Lu)
#define key_touch_INIT_SW_RES_HIGH             (0x00000002Lu)

/* CSDv2: Initialization switch resistance */
#define key_touch_SCAN_SW_RES_LOW              (0x00000000Lu)
#define key_touch_SCAN_SW_RES_MEDIUM           (0x00000001Lu)
#define key_touch_SCAN_SW_RES_HIGH             (0x00000002Lu)

/* CSDv2: CSD shield switch resistance */
#define key_touch_SHIELD_SW_RES_LOW            (0x00000000Lu)
#define key_touch_SHIELD_SW_RES_MEDIUM         (0x00000001Lu)
#define key_touch_SHIELD_SW_RES_HIGH           (0x00000002Lu)
#define key_touch_SHIELD_SW_RES_LOW_EMI        (0x00000003Lu)

/* CSDv2: CSD shield switch resistance */
#define key_touch_INIT_SHIELD_SW_RES_LOW       (0x00000000Lu)
#define key_touch_INIT_SHIELD_SW_RES_MEDIUM    (0x00000001Lu)
#define key_touch_INIT_SHIELD_SW_RES_HIGH      (0x00000002Lu)
#define key_touch_INIT_SHIELD_SW_RES_LOW_EMI   (0x00000003Lu)

/* CSDv2: CSD shield switch resistance */
#define key_touch_SCAN_SHIELD_SW_RES_LOW            (0x00000000Lu)
#define key_touch_SCAN_SHIELD_SW_RES_MEDIUM         (0x00000001Lu)
#define key_touch_SCAN_SHIELD_SW_RES_HIGH           (0x00000002Lu)
#define key_touch_SCAN_SHIELD_SW_RES_LOW_EMI        (0x00000003Lu)

/*******************************************************************************
* CSD Specific settings
*******************************************************************************/

/* CSD scan method settings */
#define key_touch_CSD_IDAC_AUTOCAL_EN          (1u)
#define key_touch_CSD_IDAC_GAIN                (key_touch_IDAC_GAIN_HIGH)
#define key_touch_CSD_SHIELD_EN                (0u)
#define key_touch_CSD_SHIELD_TANK_EN           (0u)
#define key_touch_CSD_CSH_PRECHARGE_SRC        (key_touch_CSH_PRECHARGE_VREF)
#define key_touch_CSD_SHIELD_DELAY             (key_touch_NO_DELAY)
#define key_touch_CSD_TOTAL_SHIELD_COUNT       (0u)
#define key_touch_CSD_SCANSPEED_DIVIDER        (1u)
#define key_touch_CSD_COMMON_SNS_CLK_EN        (0u)
#define key_touch_CSD_SNS_CLK_SOURCE           (key_touch_CLK_SOURCE_PRSAUTO)
#define key_touch_CSD_SNS_CLK_DIVIDER          (4u)
#define key_touch_CSD_INACTIVE_SNS_CONNECTION  (key_touch_SNS_CONNECTION_GROUND)
#define key_touch_CSD_IDAC_COMP_EN             (1u)
#define key_touch_CSD_IDAC_CONFIG              (key_touch_IDAC_SOURCING)
#define key_touch_CSD_RAWCOUNT_CAL_LEVEL       (60u)
#define key_touch_CSD_DUALIDAC_LEVEL           (50u)
#define key_touch_CSD_PRESCAN_SETTLING_TIME    (5u)
#define key_touch_CSD_SNSCLK_R_CONST           (1000u)
#define key_touch_CSD_VREF_MV                  (2021u)

/* CSD settings - CSDv2 */
#define key_touch_CSD_DEDICATED_IDAC_COMP_EN   (1u)
#define key_touch_CSD_AUTO_ZERO_EN             (0u)
#define key_touch_CSD_AUTO_ZERO_TIME           (15Lu)
#define key_touch_CSD_NOISE_METRIC_EN          (0u)
#define key_touch_CSD_NOISE_METRIC_TH          (1Lu)
#define key_touch_CSD_INIT_SWITCH_RES          (key_touch_INIT_SW_RES_MEDIUM)
#define key_touch_CSD_SHIELD_SWITCH_RES        (key_touch_SHIELD_SW_RES_MEDIUM)
#define key_touch_CSD_GAIN                     (18Lu)


/*******************************************************************************
* CSX Specific settings
*******************************************************************************/

/* CSX scan method settings */
#define key_touch_CSX_SCANSPEED_DIVIDER        (1u)
#define key_touch_CSX_COMMON_TX_CLK_EN         (0u)
#define key_touch_CSX_TX_CLK_SOURCE            (key_touch_CLK_SOURCE_PRSAUTO)
#define key_touch_CSX_TX_CLK_DIVIDER           (40u)
#define key_touch_CSX_MAX_FINGERS              (1u)
#define key_touch_CSX_MAX_LOCAL_PEAKS          (5u)
#define key_touch_CSX_IDAC_AUTOCAL_EN          (0u)
#define key_touch_CSX_IDAC_BITS_USED           (7u)
#define key_touch_CSX_RAWCOUNT_CAL_LEVEL       (40u)
#define key_touch_CSX_IDAC_GAIN                (key_touch_IDAC_GAIN_MEDIUM)
#define key_touch_CSX_SKIP_OVSMPL_SPECIFIC_NODES (0u)
#define key_touch_CSX_MULTIPHASE_TX_EN         (0u)
#define key_touch_CSX_MAX_TX_PHASE_LENGTH      (0u)

/* CSX settings - CSDv2 */
#define key_touch_CSX_AUTO_ZERO_EN             (0u)
#define key_touch_CSX_AUTO_ZERO_TIME           (15u)
#define key_touch_CSX_FINE_INIT_TIME           (4u)
#define key_touch_CSX_NOISE_METRIC_EN          (0u)
#define key_touch_CSX_NOISE_METRIC_TH          (1u)
#define key_touch_CSX_INIT_SWITCH_RES          (key_touch_INIT_SW_RES_MEDIUM)
#define key_touch_CSX_SCAN_SWITCH_RES          (key_touch_SCAN_SW_RES_LOW)
#define key_touch_CSX_INIT_SHIELD_SWITCH_RES   (key_touch_INIT_SHIELD_SW_RES_HIGH)
#define key_touch_CSX_SCAN_SHIELD_SWITCH_RES   (key_touch_SCAN_SHIELD_SW_RES_LOW)


/*******************************************************************************
* Global Parameter Definitions
*******************************************************************************/

/* RAM Global Parameters Definitions */
#define key_touch_CONFIG_ID                     (0xA122u)
#define key_touch_DEVICE_ID                     (0x0130u)
#define key_touch_CSD0_CONFIG                   (0x0008u)

/***************************************************************************//**
* Button0 initialization values for FLASH data structure
*******************************************************************************/
#define key_touch_BUTTON0_STATIC_CONFIG         (1u)
#define key_touch_BUTTON0_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button0 initialization values for RAM data structure
*******************************************************************************/
#define key_touch_BUTTON0_RESOLUTION            (key_touch_RES12BIT)
#define key_touch_BUTTON0_FINGER_TH             (100u)
#define key_touch_BUTTON0_NOISE_TH              (40u)
#define key_touch_BUTTON0_NNOISE_TH             (40u)
#define key_touch_BUTTON0_HYSTERESIS            (10u)
#define key_touch_BUTTON0_ON_DEBOUNCE           (3u)
#define key_touch_BUTTON0_LOW_BSLN_RST          (30u)
#define key_touch_BUTTON0_BSLN_COEFF            (100u)
#define key_touch_BUTTON0_IDAC_MOD0             (32u)
#define key_touch_BUTTON0_SNS_CLK               (4u)
#define key_touch_BUTTON0_SNS_CLK_SOURCE        (0u)
#define key_touch_BUTTON0_FINGER_CAP            (160u)
#define key_touch_BUTTON0_SIGPFC                (0u)

/***************************************************************************//**
* Button1 initialization values for FLASH data structure
*******************************************************************************/
#define key_touch_BUTTON1_STATIC_CONFIG         (1u)
#define key_touch_BUTTON1_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button1 initialization values for RAM data structure
*******************************************************************************/
#define key_touch_BUTTON1_RESOLUTION            (key_touch_RES12BIT)
#define key_touch_BUTTON1_FINGER_TH             (100u)
#define key_touch_BUTTON1_NOISE_TH              (40u)
#define key_touch_BUTTON1_NNOISE_TH             (40u)
#define key_touch_BUTTON1_HYSTERESIS            (10u)
#define key_touch_BUTTON1_ON_DEBOUNCE           (3u)
#define key_touch_BUTTON1_LOW_BSLN_RST          (30u)
#define key_touch_BUTTON1_BSLN_COEFF            (100u)
#define key_touch_BUTTON1_IDAC_MOD0             (32u)
#define key_touch_BUTTON1_SNS_CLK               (4u)
#define key_touch_BUTTON1_SNS_CLK_SOURCE        (0u)
#define key_touch_BUTTON1_FINGER_CAP            (160u)
#define key_touch_BUTTON1_SIGPFC                (0u)

/***************************************************************************//**
* Button2 initialization values for FLASH data structure
*******************************************************************************/
#define key_touch_BUTTON2_STATIC_CONFIG         (1u)
#define key_touch_BUTTON2_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button2 initialization values for RAM data structure
*******************************************************************************/
#define key_touch_BUTTON2_RESOLUTION            (key_touch_RES12BIT)
#define key_touch_BUTTON2_FINGER_TH             (100u)
#define key_touch_BUTTON2_NOISE_TH              (40u)
#define key_touch_BUTTON2_NNOISE_TH             (40u)
#define key_touch_BUTTON2_HYSTERESIS            (10u)
#define key_touch_BUTTON2_ON_DEBOUNCE           (3u)
#define key_touch_BUTTON2_LOW_BSLN_RST          (30u)
#define key_touch_BUTTON2_BSLN_COEFF            (100u)
#define key_touch_BUTTON2_IDAC_MOD0             (32u)
#define key_touch_BUTTON2_SNS_CLK               (4u)
#define key_touch_BUTTON2_SNS_CLK_SOURCE        (0u)
#define key_touch_BUTTON2_FINGER_CAP            (160u)
#define key_touch_BUTTON2_SIGPFC                (0u)

/***************************************************************************//**
* Button3 initialization values for FLASH data structure
*******************************************************************************/
#define key_touch_BUTTON3_STATIC_CONFIG         (1u)
#define key_touch_BUTTON3_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button3 initialization values for RAM data structure
*******************************************************************************/
#define key_touch_BUTTON3_RESOLUTION            (key_touch_RES12BIT)
#define key_touch_BUTTON3_FINGER_TH             (100u)
#define key_touch_BUTTON3_NOISE_TH              (40u)
#define key_touch_BUTTON3_NNOISE_TH             (40u)
#define key_touch_BUTTON3_HYSTERESIS            (10u)
#define key_touch_BUTTON3_ON_DEBOUNCE           (3u)
#define key_touch_BUTTON3_LOW_BSLN_RST          (30u)
#define key_touch_BUTTON3_BSLN_COEFF            (100u)
#define key_touch_BUTTON3_IDAC_MOD0             (32u)
#define key_touch_BUTTON3_SNS_CLK               (4u)
#define key_touch_BUTTON3_SNS_CLK_SOURCE        (0u)
#define key_touch_BUTTON3_FINGER_CAP            (160u)
#define key_touch_BUTTON3_SIGPFC                (0u)

/***************************************************************************//**
* Button4 initialization values for FLASH data structure
*******************************************************************************/
#define key_touch_BUTTON4_STATIC_CONFIG         (1u)
#define key_touch_BUTTON4_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button4 initialization values for RAM data structure
*******************************************************************************/
#define key_touch_BUTTON4_RESOLUTION            (key_touch_RES12BIT)
#define key_touch_BUTTON4_FINGER_TH             (100u)
#define key_touch_BUTTON4_NOISE_TH              (40u)
#define key_touch_BUTTON4_NNOISE_TH             (40u)
#define key_touch_BUTTON4_HYSTERESIS            (10u)
#define key_touch_BUTTON4_ON_DEBOUNCE           (3u)
#define key_touch_BUTTON4_LOW_BSLN_RST          (30u)
#define key_touch_BUTTON4_BSLN_COEFF            (100u)
#define key_touch_BUTTON4_IDAC_MOD0             (32u)
#define key_touch_BUTTON4_SNS_CLK               (4u)
#define key_touch_BUTTON4_SNS_CLK_SOURCE        (0u)
#define key_touch_BUTTON4_FINGER_CAP            (160u)
#define key_touch_BUTTON4_SIGPFC                (0u)

/***************************************************************************//**
* Button5 initialization values for FLASH data structure
*******************************************************************************/
#define key_touch_BUTTON5_STATIC_CONFIG         (1u)
#define key_touch_BUTTON5_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button5 initialization values for RAM data structure
*******************************************************************************/
#define key_touch_BUTTON5_RESOLUTION            (key_touch_RES12BIT)
#define key_touch_BUTTON5_FINGER_TH             (100u)
#define key_touch_BUTTON5_NOISE_TH              (40u)
#define key_touch_BUTTON5_NNOISE_TH             (40u)
#define key_touch_BUTTON5_HYSTERESIS            (10u)
#define key_touch_BUTTON5_ON_DEBOUNCE           (3u)
#define key_touch_BUTTON5_LOW_BSLN_RST          (30u)
#define key_touch_BUTTON5_BSLN_COEFF            (100u)
#define key_touch_BUTTON5_IDAC_MOD0             (32u)
#define key_touch_BUTTON5_SNS_CLK               (4u)
#define key_touch_BUTTON5_SNS_CLK_SOURCE        (0u)
#define key_touch_BUTTON5_FINGER_CAP            (160u)
#define key_touch_BUTTON5_SIGPFC                (0u)

/***************************************************************************//**
* Button6 initialization values for FLASH data structure
*******************************************************************************/
#define key_touch_BUTTON6_STATIC_CONFIG         (1u)
#define key_touch_BUTTON6_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button6 initialization values for RAM data structure
*******************************************************************************/
#define key_touch_BUTTON6_RESOLUTION            (key_touch_RES12BIT)
#define key_touch_BUTTON6_FINGER_TH             (100u)
#define key_touch_BUTTON6_NOISE_TH              (40u)
#define key_touch_BUTTON6_NNOISE_TH             (40u)
#define key_touch_BUTTON6_HYSTERESIS            (10u)
#define key_touch_BUTTON6_ON_DEBOUNCE           (3u)
#define key_touch_BUTTON6_LOW_BSLN_RST          (30u)
#define key_touch_BUTTON6_BSLN_COEFF            (100u)
#define key_touch_BUTTON6_IDAC_MOD0             (32u)
#define key_touch_BUTTON6_SNS_CLK               (4u)
#define key_touch_BUTTON6_SNS_CLK_SOURCE        (0u)
#define key_touch_BUTTON6_FINGER_CAP            (160u)
#define key_touch_BUTTON6_SIGPFC                (0u)

/***************************************************************************//**
* Button7 initialization values for FLASH data structure
*******************************************************************************/
#define key_touch_BUTTON7_STATIC_CONFIG         (1u)
#define key_touch_BUTTON7_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button7 initialization values for RAM data structure
*******************************************************************************/
#define key_touch_BUTTON7_RESOLUTION            (key_touch_RES12BIT)
#define key_touch_BUTTON7_FINGER_TH             (100u)
#define key_touch_BUTTON7_NOISE_TH              (40u)
#define key_touch_BUTTON7_NNOISE_TH             (40u)
#define key_touch_BUTTON7_HYSTERESIS            (10u)
#define key_touch_BUTTON7_ON_DEBOUNCE           (3u)
#define key_touch_BUTTON7_LOW_BSLN_RST          (30u)
#define key_touch_BUTTON7_BSLN_COEFF            (100u)
#define key_touch_BUTTON7_IDAC_MOD0             (32u)
#define key_touch_BUTTON7_SNS_CLK               (4u)
#define key_touch_BUTTON7_SNS_CLK_SOURCE        (0u)
#define key_touch_BUTTON7_FINGER_CAP            (160u)
#define key_touch_BUTTON7_SIGPFC                (0u)

/***************************************************************************//**
* Button8 initialization values for FLASH data structure
*******************************************************************************/
#define key_touch_BUTTON8_STATIC_CONFIG         (1u)
#define key_touch_BUTTON8_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button8 initialization values for RAM data structure
*******************************************************************************/
#define key_touch_BUTTON8_RESOLUTION            (key_touch_RES12BIT)
#define key_touch_BUTTON8_FINGER_TH             (100u)
#define key_touch_BUTTON8_NOISE_TH              (40u)
#define key_touch_BUTTON8_NNOISE_TH             (40u)
#define key_touch_BUTTON8_HYSTERESIS            (10u)
#define key_touch_BUTTON8_ON_DEBOUNCE           (3u)
#define key_touch_BUTTON8_LOW_BSLN_RST          (30u)
#define key_touch_BUTTON8_BSLN_COEFF            (100u)
#define key_touch_BUTTON8_IDAC_MOD0             (32u)
#define key_touch_BUTTON8_SNS_CLK               (4u)
#define key_touch_BUTTON8_SNS_CLK_SOURCE        (0u)
#define key_touch_BUTTON8_FINGER_CAP            (160u)
#define key_touch_BUTTON8_SIGPFC                (0u)

/***************************************************************************//**
* Button9 initialization values for FLASH data structure
*******************************************************************************/
#define key_touch_BUTTON9_STATIC_CONFIG         (1u)
#define key_touch_BUTTON9_NUM_SENSORS           (1u)

/***************************************************************************//**
* Button9 initialization values for RAM data structure
*******************************************************************************/
#define key_touch_BUTTON9_RESOLUTION            (key_touch_RES12BIT)
#define key_touch_BUTTON9_FINGER_TH             (100u)
#define key_touch_BUTTON9_NOISE_TH              (40u)
#define key_touch_BUTTON9_NNOISE_TH             (40u)
#define key_touch_BUTTON9_HYSTERESIS            (10u)
#define key_touch_BUTTON9_ON_DEBOUNCE           (3u)
#define key_touch_BUTTON9_LOW_BSLN_RST          (30u)
#define key_touch_BUTTON9_BSLN_COEFF            (100u)
#define key_touch_BUTTON9_IDAC_MOD0             (32u)
#define key_touch_BUTTON9_SNS_CLK               (4u)
#define key_touch_BUTTON9_SNS_CLK_SOURCE        (0u)
#define key_touch_BUTTON9_FINGER_CAP            (160u)
#define key_touch_BUTTON9_SIGPFC                (0u)

/***************************************************************************//**
* Button10 initialization values for FLASH data structure
*******************************************************************************/
#define key_touch_BUTTON10_STATIC_CONFIG        (1u)
#define key_touch_BUTTON10_NUM_SENSORS          (1u)

/***************************************************************************//**
* Button10 initialization values for RAM data structure
*******************************************************************************/
#define key_touch_BUTTON10_RESOLUTION           (key_touch_RES12BIT)
#define key_touch_BUTTON10_FINGER_TH            (100u)
#define key_touch_BUTTON10_NOISE_TH             (40u)
#define key_touch_BUTTON10_NNOISE_TH            (40u)
#define key_touch_BUTTON10_HYSTERESIS           (10u)
#define key_touch_BUTTON10_ON_DEBOUNCE          (3u)
#define key_touch_BUTTON10_LOW_BSLN_RST         (30u)
#define key_touch_BUTTON10_BSLN_COEFF           (100u)
#define key_touch_BUTTON10_IDAC_MOD0            (32u)
#define key_touch_BUTTON10_SNS_CLK              (4u)
#define key_touch_BUTTON10_SNS_CLK_SOURCE       (0u)
#define key_touch_BUTTON10_FINGER_CAP           (160u)
#define key_touch_BUTTON10_SIGPFC               (0u)

/***************************************************************************//**
* Button11 initialization values for FLASH data structure
*******************************************************************************/
#define key_touch_BUTTON11_STATIC_CONFIG        (1u)
#define key_touch_BUTTON11_NUM_SENSORS          (1u)

/***************************************************************************//**
* Button11 initialization values for RAM data structure
*******************************************************************************/
#define key_touch_BUTTON11_RESOLUTION           (key_touch_RES12BIT)
#define key_touch_BUTTON11_FINGER_TH            (100u)
#define key_touch_BUTTON11_NOISE_TH             (40u)
#define key_touch_BUTTON11_NNOISE_TH            (40u)
#define key_touch_BUTTON11_HYSTERESIS           (10u)
#define key_touch_BUTTON11_ON_DEBOUNCE          (3u)
#define key_touch_BUTTON11_LOW_BSLN_RST         (30u)
#define key_touch_BUTTON11_BSLN_COEFF           (100u)
#define key_touch_BUTTON11_IDAC_MOD0            (32u)
#define key_touch_BUTTON11_SNS_CLK              (4u)
#define key_touch_BUTTON11_SNS_CLK_SOURCE       (0u)
#define key_touch_BUTTON11_FINGER_CAP           (160u)
#define key_touch_BUTTON11_SIGPFC               (0u)

/* RAM Sensor Parameters Definitions */
#define key_touch_BUTTON0_SNS0_IDAC_COMP0       (32u)
#define key_touch_BUTTON1_SNS0_IDAC_COMP0       (32u)
#define key_touch_BUTTON2_SNS0_IDAC_COMP0       (32u)
#define key_touch_BUTTON3_SNS0_IDAC_COMP0       (32u)
#define key_touch_BUTTON4_SNS0_IDAC_COMP0       (32u)
#define key_touch_BUTTON5_SNS0_IDAC_COMP0       (32u)
#define key_touch_BUTTON6_SNS0_IDAC_COMP0       (32u)
#define key_touch_BUTTON7_SNS0_IDAC_COMP0       (32u)
#define key_touch_BUTTON8_SNS0_IDAC_COMP0       (32u)
#define key_touch_BUTTON9_SNS0_IDAC_COMP0       (32u)
#define key_touch_BUTTON10_SNS0_IDAC_COMP0      (32u)
#define key_touch_BUTTON11_SNS0_IDAC_COMP0      (32u)


/*******************************************************************************
* ADC Specific Macros
*******************************************************************************/
#define key_touch_ADC_RES8BIT                  (8u)
#define key_touch_ADC_RES10BIT                 (10u)

#define key_touch_ADC_EN                       (0u)
#define key_touch_ADC_STANDALONE_EN            (0u)
#define key_touch_ADC_TOTAL_CHANNELS           (1u)
#define key_touch_ADC_RESOLUTION               (key_touch_ADC_RES10BIT)
#define key_touch_ADC_AMUXB_INPUT_EN           (0u)
#define key_touch_ADC_SELECT_AMUXB_CH          (0u)
#define key_touch_ADC_AZ_EN                    (1Lu)
#define key_touch_ADC_AZ_TIME                  (5u)
#define key_touch_ADC_VREF_MV                  (2133u)
#define key_touch_ADC_GAIN                     (17Lu)
#define key_touch_ADC_IDACVAL                  (22u)
#define key_touch_ADC_MEASURE_MODE             (0u)

/*******************************************************************************
* Built-In Self-Test Configuration
*******************************************************************************/
#define key_touch_SELF_TEST_EN                   (0Lu)
#define key_touch_TST_GLOBAL_CRC_EN              (0Lu)
#define key_touch_TST_WDGT_CRC_EN                (0Lu)
#define key_touch_TST_BSLN_DUPLICATION_EN        (0Lu)
#define key_touch_TST_BSLN_RAW_OUT_RANGE_EN      (0Lu)
#define key_touch_TST_SNS_SHORT_EN               (0Lu)
#define key_touch_TST_SNS2SNS_SHORT_EN           (0Lu)
#define key_touch_TST_SNS_CAP_EN                 (0Lu)
#define key_touch_TST_SH_CAP_EN                  (0Lu)
#define key_touch_TST_EXTERNAL_CAP_EN            (0Lu)
#define key_touch_TST_INTERNAL_CAP_EN            (0Lu)
#define key_touch_TST_VDDA_EN                    (0Lu)


#endif /* CY_CAPSENSE_key_touch_CONFIGURATION_H */


/* [] END OF FILE */
