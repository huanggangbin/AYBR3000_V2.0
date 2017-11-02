/***************************************************************************//**
* \file key_touch_Structure.c
* \version 3.10
*
* \brief
*   This file defines the data structure global variables and provides implementation
*   for the high-level and low-level APIs of the Data Structure module.
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

#include <cytypes.h>
#include "CyLib.h"
#include "key_touch_Structure.h"
#include "key_touch_Configuration.h"

#if (0u != key_touch_ADC_EN)
    #include "key_touch_Adc.h"
#endif /* (0u != key_touch_ADC_EN) */

#if (key_touch_ENABLE == key_touch_SELF_TEST_EN)
    #include "key_touch_SelfTest.h"
#endif

/*******************************************************************************
* Define the RAM Data Structure variables and their init data in flash
*******************************************************************************/
/**
* \if SECTION_GLOBAL_VARIABLES
* \addtogroup group_global_variables
* \{
*/

/**
* Variable that contains key_touch configuration, settings and scanning results.
* key_touch_dsRam represents RAM Data Structure.
*/
key_touch_RAM_STRUCT key_touch_dsRam;
/** \}
* \endif */

/*******************************************************************************
* Declare Widget's De-bounce Counters
*******************************************************************************/
static uint8 key_touch_debounceButton0[key_touch_BUTTON0_NUM_SENSORS];
static uint8 key_touch_debounceButton1[key_touch_BUTTON1_NUM_SENSORS];
static uint8 key_touch_debounceButton2[key_touch_BUTTON2_NUM_SENSORS];
static uint8 key_touch_debounceButton3[key_touch_BUTTON3_NUM_SENSORS];
static uint8 key_touch_debounceButton4[key_touch_BUTTON4_NUM_SENSORS];
static uint8 key_touch_debounceButton5[key_touch_BUTTON5_NUM_SENSORS];
static uint8 key_touch_debounceButton6[key_touch_BUTTON6_NUM_SENSORS];
static uint8 key_touch_debounceButton7[key_touch_BUTTON7_NUM_SENSORS];
static uint8 key_touch_debounceButton8[key_touch_BUTTON8_NUM_SENSORS];
static uint8 key_touch_debounceButton9[key_touch_BUTTON9_NUM_SENSORS];
static uint8 key_touch_debounceButton10[key_touch_BUTTON10_NUM_SENSORS];
static uint8 key_touch_debounceButton11[key_touch_BUTTON11_NUM_SENSORS];


/***************************************************************************//**
* Declare Noise Envelope data structures
*******************************************************************************/
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT key_touch_noiseEnvlpButton0[key_touch_BUTTON0_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT key_touch_noiseEnvlpButton1[key_touch_BUTTON1_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT key_touch_noiseEnvlpButton2[key_touch_BUTTON2_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT key_touch_noiseEnvlpButton3[key_touch_BUTTON3_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT key_touch_noiseEnvlpButton4[key_touch_BUTTON4_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT key_touch_noiseEnvlpButton5[key_touch_BUTTON5_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT key_touch_noiseEnvlpButton6[key_touch_BUTTON6_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT key_touch_noiseEnvlpButton7[key_touch_BUTTON7_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT key_touch_noiseEnvlpButton8[key_touch_BUTTON8_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT key_touch_noiseEnvlpButton9[key_touch_BUTTON9_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT key_touch_noiseEnvlpButton10[key_touch_BUTTON10_NUM_SENSORS];
static SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT key_touch_noiseEnvlpButton11[key_touch_BUTTON11_NUM_SENSORS];

/*******************************************************************************
* Define and initialize the Flash Data Structure
*******************************************************************************/

/**
* \if SECTION_API_CONSTANTS
* \addtogroup group_api_constants
* \{
*/

/**
* Constant for the FLASH Data Structure
*/
const key_touch_FLASH_STRUCT key_touch_dsFlash =
{
    /* Flash Widget Initialization Data */
    {
        { /* Button0 */
            &key_touch_ioList[0u],
            (void *)&key_touch_dsRam.wdgtList.button0,
            key_touch_dsRam.snsList.button0,
            (void *)0u,
            key_touch_debounceButton0,
            key_touch_BUTTON0_STATIC_CONFIG,
            key_touch_BUTTON0_NUM_SENSORS,
            (uint8)key_touch_WD_BUTTON_E,
            key_touch_BUTTON0_NUM_SENSORS,
            key_touch_noiseEnvlpButton0,
        },
        { /* Button1 */
            &key_touch_ioList[1u],
            (void *)&key_touch_dsRam.wdgtList.button1,
            key_touch_dsRam.snsList.button1,
            (void *)0u,
            key_touch_debounceButton1,
            key_touch_BUTTON1_STATIC_CONFIG,
            key_touch_BUTTON1_NUM_SENSORS,
            (uint8)key_touch_WD_BUTTON_E,
            key_touch_BUTTON1_NUM_SENSORS,
            key_touch_noiseEnvlpButton1,
        },
        { /* Button2 */
            &key_touch_ioList[2u],
            (void *)&key_touch_dsRam.wdgtList.button2,
            key_touch_dsRam.snsList.button2,
            (void *)0u,
            key_touch_debounceButton2,
            key_touch_BUTTON2_STATIC_CONFIG,
            key_touch_BUTTON2_NUM_SENSORS,
            (uint8)key_touch_WD_BUTTON_E,
            key_touch_BUTTON2_NUM_SENSORS,
            key_touch_noiseEnvlpButton2,
        },
        { /* Button3 */
            &key_touch_ioList[3u],
            (void *)&key_touch_dsRam.wdgtList.button3,
            key_touch_dsRam.snsList.button3,
            (void *)0u,
            key_touch_debounceButton3,
            key_touch_BUTTON3_STATIC_CONFIG,
            key_touch_BUTTON3_NUM_SENSORS,
            (uint8)key_touch_WD_BUTTON_E,
            key_touch_BUTTON3_NUM_SENSORS,
            key_touch_noiseEnvlpButton3,
        },
        { /* Button4 */
            &key_touch_ioList[4u],
            (void *)&key_touch_dsRam.wdgtList.button4,
            key_touch_dsRam.snsList.button4,
            (void *)0u,
            key_touch_debounceButton4,
            key_touch_BUTTON4_STATIC_CONFIG,
            key_touch_BUTTON4_NUM_SENSORS,
            (uint8)key_touch_WD_BUTTON_E,
            key_touch_BUTTON4_NUM_SENSORS,
            key_touch_noiseEnvlpButton4,
        },
        { /* Button5 */
            &key_touch_ioList[5u],
            (void *)&key_touch_dsRam.wdgtList.button5,
            key_touch_dsRam.snsList.button5,
            (void *)0u,
            key_touch_debounceButton5,
            key_touch_BUTTON5_STATIC_CONFIG,
            key_touch_BUTTON5_NUM_SENSORS,
            (uint8)key_touch_WD_BUTTON_E,
            key_touch_BUTTON5_NUM_SENSORS,
            key_touch_noiseEnvlpButton5,
        },
        { /* Button6 */
            &key_touch_ioList[6u],
            (void *)&key_touch_dsRam.wdgtList.button6,
            key_touch_dsRam.snsList.button6,
            (void *)0u,
            key_touch_debounceButton6,
            key_touch_BUTTON6_STATIC_CONFIG,
            key_touch_BUTTON6_NUM_SENSORS,
            (uint8)key_touch_WD_BUTTON_E,
            key_touch_BUTTON6_NUM_SENSORS,
            key_touch_noiseEnvlpButton6,
        },
        { /* Button7 */
            &key_touch_ioList[7u],
            (void *)&key_touch_dsRam.wdgtList.button7,
            key_touch_dsRam.snsList.button7,
            (void *)0u,
            key_touch_debounceButton7,
            key_touch_BUTTON7_STATIC_CONFIG,
            key_touch_BUTTON7_NUM_SENSORS,
            (uint8)key_touch_WD_BUTTON_E,
            key_touch_BUTTON7_NUM_SENSORS,
            key_touch_noiseEnvlpButton7,
        },
        { /* Button8 */
            &key_touch_ioList[8u],
            (void *)&key_touch_dsRam.wdgtList.button8,
            key_touch_dsRam.snsList.button8,
            (void *)0u,
            key_touch_debounceButton8,
            key_touch_BUTTON8_STATIC_CONFIG,
            key_touch_BUTTON8_NUM_SENSORS,
            (uint8)key_touch_WD_BUTTON_E,
            key_touch_BUTTON8_NUM_SENSORS,
            key_touch_noiseEnvlpButton8,
        },
        { /* Button9 */
            &key_touch_ioList[9u],
            (void *)&key_touch_dsRam.wdgtList.button9,
            key_touch_dsRam.snsList.button9,
            (void *)0u,
            key_touch_debounceButton9,
            key_touch_BUTTON9_STATIC_CONFIG,
            key_touch_BUTTON9_NUM_SENSORS,
            (uint8)key_touch_WD_BUTTON_E,
            key_touch_BUTTON9_NUM_SENSORS,
            key_touch_noiseEnvlpButton9,
        },
        { /* Button10 */
            &key_touch_ioList[10u],
            (void *)&key_touch_dsRam.wdgtList.button10,
            key_touch_dsRam.snsList.button10,
            (void *)0u,
            key_touch_debounceButton10,
            key_touch_BUTTON10_STATIC_CONFIG,
            key_touch_BUTTON10_NUM_SENSORS,
            (uint8)key_touch_WD_BUTTON_E,
            key_touch_BUTTON10_NUM_SENSORS,
            key_touch_noiseEnvlpButton10,
        },
        { /* Button11 */
            &key_touch_ioList[11u],
            (void *)&key_touch_dsRam.wdgtList.button11,
            key_touch_dsRam.snsList.button11,
            (void *)0u,
            key_touch_debounceButton11,
            key_touch_BUTTON11_STATIC_CONFIG,
            key_touch_BUTTON11_NUM_SENSORS,
            (uint8)key_touch_WD_BUTTON_E,
            key_touch_BUTTON11_NUM_SENSORS,
            key_touch_noiseEnvlpButton11,
        },
    },
};


/**
* Array of pointers to the electrode specific register
*/
const key_touch_FLASH_IO_STRUCT key_touch_ioList[key_touch_TOTAL_ELECTRODES] =
{
    { /* 0: Button0_Sns0 */
        (reg32 *)key_touch_Sns__0__HSIOM,
        (reg32 *)key_touch_Sns__0__PC,
        (reg32 *)key_touch_Sns__0__DR,
        (reg32 *)key_touch_Sns__0__PS,
        key_touch_Sns__0__HSIOM_MASK,
        key_touch_Sns__0__MASK,
        key_touch_Sns__0__HSIOM_SHIFT,
        (uint8)key_touch_Sns__0__SHIFT,
        (uint8)key_touch_Sns__0__SHIFT * 3u,
    },
    { /* 1: Button1_Sns0 */
        (reg32 *)key_touch_Sns__1__HSIOM,
        (reg32 *)key_touch_Sns__1__PC,
        (reg32 *)key_touch_Sns__1__DR,
        (reg32 *)key_touch_Sns__1__PS,
        key_touch_Sns__1__HSIOM_MASK,
        key_touch_Sns__1__MASK,
        key_touch_Sns__1__HSIOM_SHIFT,
        (uint8)key_touch_Sns__1__SHIFT,
        (uint8)key_touch_Sns__1__SHIFT * 3u,
    },
    { /* 2: Button2_Sns0 */
        (reg32 *)key_touch_Sns__2__HSIOM,
        (reg32 *)key_touch_Sns__2__PC,
        (reg32 *)key_touch_Sns__2__DR,
        (reg32 *)key_touch_Sns__2__PS,
        key_touch_Sns__2__HSIOM_MASK,
        key_touch_Sns__2__MASK,
        key_touch_Sns__2__HSIOM_SHIFT,
        (uint8)key_touch_Sns__2__SHIFT,
        (uint8)key_touch_Sns__2__SHIFT * 3u,
    },
    { /* 3: Button3_Sns0 */
        (reg32 *)key_touch_Sns__3__HSIOM,
        (reg32 *)key_touch_Sns__3__PC,
        (reg32 *)key_touch_Sns__3__DR,
        (reg32 *)key_touch_Sns__3__PS,
        key_touch_Sns__3__HSIOM_MASK,
        key_touch_Sns__3__MASK,
        key_touch_Sns__3__HSIOM_SHIFT,
        (uint8)key_touch_Sns__3__SHIFT,
        (uint8)key_touch_Sns__3__SHIFT * 3u,
    },
    { /* 4: Button4_Sns0 */
        (reg32 *)key_touch_Sns__4__HSIOM,
        (reg32 *)key_touch_Sns__4__PC,
        (reg32 *)key_touch_Sns__4__DR,
        (reg32 *)key_touch_Sns__4__PS,
        key_touch_Sns__4__HSIOM_MASK,
        key_touch_Sns__4__MASK,
        key_touch_Sns__4__HSIOM_SHIFT,
        (uint8)key_touch_Sns__4__SHIFT,
        (uint8)key_touch_Sns__4__SHIFT * 3u,
    },
    { /* 5: Button5_Sns0 */
        (reg32 *)key_touch_Sns__5__HSIOM,
        (reg32 *)key_touch_Sns__5__PC,
        (reg32 *)key_touch_Sns__5__DR,
        (reg32 *)key_touch_Sns__5__PS,
        key_touch_Sns__5__HSIOM_MASK,
        key_touch_Sns__5__MASK,
        key_touch_Sns__5__HSIOM_SHIFT,
        (uint8)key_touch_Sns__5__SHIFT,
        (uint8)key_touch_Sns__5__SHIFT * 3u,
    },
    { /* 6: Button6_Sns0 */
        (reg32 *)key_touch_Sns__6__HSIOM,
        (reg32 *)key_touch_Sns__6__PC,
        (reg32 *)key_touch_Sns__6__DR,
        (reg32 *)key_touch_Sns__6__PS,
        key_touch_Sns__6__HSIOM_MASK,
        key_touch_Sns__6__MASK,
        key_touch_Sns__6__HSIOM_SHIFT,
        (uint8)key_touch_Sns__6__SHIFT,
        (uint8)key_touch_Sns__6__SHIFT * 3u,
    },
    { /* 7: Button7_Sns0 */
        (reg32 *)key_touch_Sns__7__HSIOM,
        (reg32 *)key_touch_Sns__7__PC,
        (reg32 *)key_touch_Sns__7__DR,
        (reg32 *)key_touch_Sns__7__PS,
        key_touch_Sns__7__HSIOM_MASK,
        key_touch_Sns__7__MASK,
        key_touch_Sns__7__HSIOM_SHIFT,
        (uint8)key_touch_Sns__7__SHIFT,
        (uint8)key_touch_Sns__7__SHIFT * 3u,
    },
    { /* 8: Button8_Sns0 */
        (reg32 *)key_touch_Sns__8__HSIOM,
        (reg32 *)key_touch_Sns__8__PC,
        (reg32 *)key_touch_Sns__8__DR,
        (reg32 *)key_touch_Sns__8__PS,
        key_touch_Sns__8__HSIOM_MASK,
        key_touch_Sns__8__MASK,
        key_touch_Sns__8__HSIOM_SHIFT,
        (uint8)key_touch_Sns__8__SHIFT,
        (uint8)key_touch_Sns__8__SHIFT * 3u,
    },
    { /* 9: Button9_Sns0 */
        (reg32 *)key_touch_Sns__9__HSIOM,
        (reg32 *)key_touch_Sns__9__PC,
        (reg32 *)key_touch_Sns__9__DR,
        (reg32 *)key_touch_Sns__9__PS,
        key_touch_Sns__9__HSIOM_MASK,
        key_touch_Sns__9__MASK,
        key_touch_Sns__9__HSIOM_SHIFT,
        (uint8)key_touch_Sns__9__SHIFT,
        (uint8)key_touch_Sns__9__SHIFT * 3u,
    },
    { /* 10: Button10_Sns0 */
        (reg32 *)key_touch_Sns__10__HSIOM,
        (reg32 *)key_touch_Sns__10__PC,
        (reg32 *)key_touch_Sns__10__DR,
        (reg32 *)key_touch_Sns__10__PS,
        key_touch_Sns__10__HSIOM_MASK,
        key_touch_Sns__10__MASK,
        key_touch_Sns__10__HSIOM_SHIFT,
        (uint8)key_touch_Sns__10__SHIFT,
        (uint8)key_touch_Sns__10__SHIFT * 3u,
    },
    { /* 11: Button11_Sns0 */
        (reg32 *)key_touch_Sns__11__HSIOM,
        (reg32 *)key_touch_Sns__11__PC,
        (reg32 *)key_touch_Sns__11__DR,
        (reg32 *)key_touch_Sns__11__PS,
        key_touch_Sns__11__HSIOM_MASK,
        key_touch_Sns__11__MASK,
        key_touch_Sns__11__HSIOM_SHIFT,
        (uint8)key_touch_Sns__11__SHIFT,
        (uint8)key_touch_Sns__11__SHIFT * 3u,
    },
};



/** \}
* \endif */

/* Initialization data for RAM widget list */
static const key_touch_RAM_WD_LIST_STRUCT key_touch_ramWidgetInit =
{
    { /* Button0 */
        key_touch_BUTTON0_RESOLUTION,
        key_touch_BUTTON0_FINGER_TH,
        key_touch_BUTTON0_NOISE_TH,
        key_touch_BUTTON0_NNOISE_TH,
        key_touch_BUTTON0_HYSTERESIS,
        key_touch_BUTTON0_ON_DEBOUNCE,
        key_touch_BUTTON0_LOW_BSLN_RST,
        key_touch_BUTTON0_BSLN_COEFF,
        {
            key_touch_BUTTON0_IDAC_MOD0,
        },
        key_touch_BUTTON0_SNS_CLK,
        key_touch_BUTTON0_SNS_CLK_SOURCE,
        key_touch_BUTTON0_FINGER_CAP,
        key_touch_BUTTON0_SIGPFC,
    },
    { /* Button1 */
        key_touch_BUTTON1_RESOLUTION,
        key_touch_BUTTON1_FINGER_TH,
        key_touch_BUTTON1_NOISE_TH,
        key_touch_BUTTON1_NNOISE_TH,
        key_touch_BUTTON1_HYSTERESIS,
        key_touch_BUTTON1_ON_DEBOUNCE,
        key_touch_BUTTON1_LOW_BSLN_RST,
        key_touch_BUTTON1_BSLN_COEFF,
        {
            key_touch_BUTTON1_IDAC_MOD0,
        },
        key_touch_BUTTON1_SNS_CLK,
        key_touch_BUTTON1_SNS_CLK_SOURCE,
        key_touch_BUTTON1_FINGER_CAP,
        key_touch_BUTTON1_SIGPFC,
    },
    { /* Button2 */
        key_touch_BUTTON2_RESOLUTION,
        key_touch_BUTTON2_FINGER_TH,
        key_touch_BUTTON2_NOISE_TH,
        key_touch_BUTTON2_NNOISE_TH,
        key_touch_BUTTON2_HYSTERESIS,
        key_touch_BUTTON2_ON_DEBOUNCE,
        key_touch_BUTTON2_LOW_BSLN_RST,
        key_touch_BUTTON2_BSLN_COEFF,
        {
            key_touch_BUTTON2_IDAC_MOD0,
        },
        key_touch_BUTTON2_SNS_CLK,
        key_touch_BUTTON2_SNS_CLK_SOURCE,
        key_touch_BUTTON2_FINGER_CAP,
        key_touch_BUTTON2_SIGPFC,
    },
    { /* Button3 */
        key_touch_BUTTON3_RESOLUTION,
        key_touch_BUTTON3_FINGER_TH,
        key_touch_BUTTON3_NOISE_TH,
        key_touch_BUTTON3_NNOISE_TH,
        key_touch_BUTTON3_HYSTERESIS,
        key_touch_BUTTON3_ON_DEBOUNCE,
        key_touch_BUTTON3_LOW_BSLN_RST,
        key_touch_BUTTON3_BSLN_COEFF,
        {
            key_touch_BUTTON3_IDAC_MOD0,
        },
        key_touch_BUTTON3_SNS_CLK,
        key_touch_BUTTON3_SNS_CLK_SOURCE,
        key_touch_BUTTON3_FINGER_CAP,
        key_touch_BUTTON3_SIGPFC,
    },
    { /* Button4 */
        key_touch_BUTTON4_RESOLUTION,
        key_touch_BUTTON4_FINGER_TH,
        key_touch_BUTTON4_NOISE_TH,
        key_touch_BUTTON4_NNOISE_TH,
        key_touch_BUTTON4_HYSTERESIS,
        key_touch_BUTTON4_ON_DEBOUNCE,
        key_touch_BUTTON4_LOW_BSLN_RST,
        key_touch_BUTTON4_BSLN_COEFF,
        {
            key_touch_BUTTON4_IDAC_MOD0,
        },
        key_touch_BUTTON4_SNS_CLK,
        key_touch_BUTTON4_SNS_CLK_SOURCE,
        key_touch_BUTTON4_FINGER_CAP,
        key_touch_BUTTON4_SIGPFC,
    },
    { /* Button5 */
        key_touch_BUTTON5_RESOLUTION,
        key_touch_BUTTON5_FINGER_TH,
        key_touch_BUTTON5_NOISE_TH,
        key_touch_BUTTON5_NNOISE_TH,
        key_touch_BUTTON5_HYSTERESIS,
        key_touch_BUTTON5_ON_DEBOUNCE,
        key_touch_BUTTON5_LOW_BSLN_RST,
        key_touch_BUTTON5_BSLN_COEFF,
        {
            key_touch_BUTTON5_IDAC_MOD0,
        },
        key_touch_BUTTON5_SNS_CLK,
        key_touch_BUTTON5_SNS_CLK_SOURCE,
        key_touch_BUTTON5_FINGER_CAP,
        key_touch_BUTTON5_SIGPFC,
    },
    { /* Button6 */
        key_touch_BUTTON6_RESOLUTION,
        key_touch_BUTTON6_FINGER_TH,
        key_touch_BUTTON6_NOISE_TH,
        key_touch_BUTTON6_NNOISE_TH,
        key_touch_BUTTON6_HYSTERESIS,
        key_touch_BUTTON6_ON_DEBOUNCE,
        key_touch_BUTTON6_LOW_BSLN_RST,
        key_touch_BUTTON6_BSLN_COEFF,
        {
            key_touch_BUTTON6_IDAC_MOD0,
        },
        key_touch_BUTTON6_SNS_CLK,
        key_touch_BUTTON6_SNS_CLK_SOURCE,
        key_touch_BUTTON6_FINGER_CAP,
        key_touch_BUTTON6_SIGPFC,
    },
    { /* Button7 */
        key_touch_BUTTON7_RESOLUTION,
        key_touch_BUTTON7_FINGER_TH,
        key_touch_BUTTON7_NOISE_TH,
        key_touch_BUTTON7_NNOISE_TH,
        key_touch_BUTTON7_HYSTERESIS,
        key_touch_BUTTON7_ON_DEBOUNCE,
        key_touch_BUTTON7_LOW_BSLN_RST,
        key_touch_BUTTON7_BSLN_COEFF,
        {
            key_touch_BUTTON7_IDAC_MOD0,
        },
        key_touch_BUTTON7_SNS_CLK,
        key_touch_BUTTON7_SNS_CLK_SOURCE,
        key_touch_BUTTON7_FINGER_CAP,
        key_touch_BUTTON7_SIGPFC,
    },
    { /* Button8 */
        key_touch_BUTTON8_RESOLUTION,
        key_touch_BUTTON8_FINGER_TH,
        key_touch_BUTTON8_NOISE_TH,
        key_touch_BUTTON8_NNOISE_TH,
        key_touch_BUTTON8_HYSTERESIS,
        key_touch_BUTTON8_ON_DEBOUNCE,
        key_touch_BUTTON8_LOW_BSLN_RST,
        key_touch_BUTTON8_BSLN_COEFF,
        {
            key_touch_BUTTON8_IDAC_MOD0,
        },
        key_touch_BUTTON8_SNS_CLK,
        key_touch_BUTTON8_SNS_CLK_SOURCE,
        key_touch_BUTTON8_FINGER_CAP,
        key_touch_BUTTON8_SIGPFC,
    },
    { /* Button9 */
        key_touch_BUTTON9_RESOLUTION,
        key_touch_BUTTON9_FINGER_TH,
        key_touch_BUTTON9_NOISE_TH,
        key_touch_BUTTON9_NNOISE_TH,
        key_touch_BUTTON9_HYSTERESIS,
        key_touch_BUTTON9_ON_DEBOUNCE,
        key_touch_BUTTON9_LOW_BSLN_RST,
        key_touch_BUTTON9_BSLN_COEFF,
        {
            key_touch_BUTTON9_IDAC_MOD0,
        },
        key_touch_BUTTON9_SNS_CLK,
        key_touch_BUTTON9_SNS_CLK_SOURCE,
        key_touch_BUTTON9_FINGER_CAP,
        key_touch_BUTTON9_SIGPFC,
    },
    { /* Button10 */
        key_touch_BUTTON10_RESOLUTION,
        key_touch_BUTTON10_FINGER_TH,
        key_touch_BUTTON10_NOISE_TH,
        key_touch_BUTTON10_NNOISE_TH,
        key_touch_BUTTON10_HYSTERESIS,
        key_touch_BUTTON10_ON_DEBOUNCE,
        key_touch_BUTTON10_LOW_BSLN_RST,
        key_touch_BUTTON10_BSLN_COEFF,
        {
            key_touch_BUTTON10_IDAC_MOD0,
        },
        key_touch_BUTTON10_SNS_CLK,
        key_touch_BUTTON10_SNS_CLK_SOURCE,
        key_touch_BUTTON10_FINGER_CAP,
        key_touch_BUTTON10_SIGPFC,
    },
    { /* Button11 */
        key_touch_BUTTON11_RESOLUTION,
        key_touch_BUTTON11_FINGER_TH,
        key_touch_BUTTON11_NOISE_TH,
        key_touch_BUTTON11_NNOISE_TH,
        key_touch_BUTTON11_HYSTERESIS,
        key_touch_BUTTON11_ON_DEBOUNCE,
        key_touch_BUTTON11_LOW_BSLN_RST,
        key_touch_BUTTON11_BSLN_COEFF,
        {
            key_touch_BUTTON11_IDAC_MOD0,
        },
        key_touch_BUTTON11_SNS_CLK,
        key_touch_BUTTON11_SNS_CLK_SOURCE,
        key_touch_BUTTON11_FINGER_CAP,
        key_touch_BUTTON11_SIGPFC,
    },
};


/* IDAC Initialization Data */
static const uint8 key_touch_ramIdacInit[key_touch_TOTAL_SENSORS] =
{
    /* Button0 */
    key_touch_BUTTON0_SNS0_IDAC_COMP0,

    /* Button1 */
    key_touch_BUTTON1_SNS0_IDAC_COMP0,

    /* Button2 */
    key_touch_BUTTON2_SNS0_IDAC_COMP0,

    /* Button3 */
    key_touch_BUTTON3_SNS0_IDAC_COMP0,

    /* Button4 */
    key_touch_BUTTON4_SNS0_IDAC_COMP0,

    /* Button5 */
    key_touch_BUTTON5_SNS0_IDAC_COMP0,

    /* Button6 */
    key_touch_BUTTON6_SNS0_IDAC_COMP0,

    /* Button7 */
    key_touch_BUTTON7_SNS0_IDAC_COMP0,

    /* Button8 */
    key_touch_BUTTON8_SNS0_IDAC_COMP0,

    /* Button9 */
    key_touch_BUTTON9_SNS0_IDAC_COMP0,

    /* Button10 */
    key_touch_BUTTON10_SNS0_IDAC_COMP0,

    /* Button11 */
    key_touch_BUTTON11_SNS0_IDAC_COMP0,
};


/*******************************************************************************
* Define internal data types and statements
*******************************************************************************/
#define PARAM_TYPE_OFFSET       (30u)
#define PARAM_TYPE_MASK         (3Lu << PARAM_TYPE_OFFSET)
#define PARAM_RWBIT_OFFSET      (29u)
#define PARAM_RWBIT_MASK        (1Lu << PARAM_RWBIT_OFFSET)
#define PARAM_FBIT_OFFSET       (28u)
#define PARAM_FBIT_MASK         (1Lu << PARAM_FBIT_OFFSET)
#define PARAM_UBIT_OFFSET       (23u)
#define PARAM_UBIT_MASK         (1Lu << PARAM_UBIT_OFFSET)
#define PARAM_WDID_OFFSET       (16u)
#define PARAM_WDID_MASK         (0x7FLu << PARAM_WDID_OFFSET)
#define PARAM_CRC_OFFSET        (24u)
#define PARAM_CRC_MASK          (0x0FLu << PARAM_CRC_OFFSET)

/* Define align masks for uint16 and uint32 */
#define UINT16_ALIGN_MASK       (1Lu)
#define UINT32_ALIGN_MASK       (3Lu)

/* Define supported parameter types */
#define DS_PARAM_TYPE_UINT8     (0x01u)
#define DS_PARAM_TYPE_UINT16    (0x02u)
#define DS_PARAM_TYPE_UINT32    (0x03u)


/* Define PARAM_ID structure */
typedef struct
{
    uint16 offset;      /* parameter offset                     */
    uint8  widgetId;    /* widget Id parameter belongs to       */
    uint8  affectsCrc;  /* parameter affects widget CRC         */
    uint8  crc;         /* parameter CRC                        */
    uint8  flash;       /* parameter located in FLASH flag      */
    uint8  rw;          /* parameter is read/write flag         */
    uint8  type;        /* parameter type: uint8/uint16/uint32  */
} PARAM_ID_STRUCT;


/*******************************************************************************
* Static Function Prototypes
*******************************************************************************/
/**
* \if SECTION_CAPSENSE_INTERNAL
* \addtogroup group_capsense_internal
* \{
*/

static cystatus DsParseParamId(uint32 paramId, PARAM_ID_STRUCT *pData);

/** \}
* \endif */


/*******************************************************************************
* Function Name: key_touch_DsInitialize
****************************************************************************//**
*
* \brief
*   This function initializes the Data Structure storage.
*
* \details
*   This function copies the default widget configuration parameters 
*   from the Flash storage into the RAM Data Structure.
*
*******************************************************************************/
void key_touch_DsInitialize(void)
{
    #if (0u != key_touch_CSX_EN) || (0 != key_touch_CSD_IDAC_COMP_EN)
        uint32 snsId;
        uint32 wdgtId;
    
        key_touch_RAM_SNS_STRUCT * ptrSns;
        key_touch_FLASH_WD_STRUCT const * ptrFlashWdgt;
        uint8 const * ptrIdacInit = key_touch_ramIdacInit;
    #endif        
    
    /* Reset RAM data structure content */
    (void)memset(&key_touch_dsRam, 0, sizeof(key_touch_dsRam));
    
    /* Initialize configId and deviceId registers */
    key_touch_dsRam.configId = key_touch_CONFIG_ID;
    key_touch_dsRam.deviceId = key_touch_DEVICE_ID;
    
    /* Initialize global RAM data */
    key_touch_dsRam.csd0Config = key_touch_CSD0_CONFIG;

    #if ((0u != key_touch_CSD2X_EN) || (0u != key_touch_CSX2X_EN))
        key_touch_dsRam.csd1Config = key_touch_CSD1_CONFIG;
    #endif /* #if ((0u != key_touch_CSD2X_EN) || (0u != key_touch_CSX2X_EN)) */
    
    #if (0u != key_touch_TOTAL_CSD_WIDGETS)
        key_touch_dsRam.modCsdClk = key_touch_CSD_SCANSPEED_DIVIDER;
        
        #if (0u != key_touch_CSD_COMMON_SNS_CLK_EN)
            key_touch_dsRam.snsCsdClk = key_touch_CSD_SNS_CLK_DIVIDER;
        #endif /* #if (0u != key_touch_CSD_COMMON_SNS_CLK_EN) */
    #endif /* #if (0u != key_touch_TOTAL_CSD_WIDGETS) */
    
    #if (0u != key_touch_CSX_EN)
        key_touch_dsRam.modCsxClk = key_touch_CSX_SCANSPEED_DIVIDER;
        
        #if (0u != key_touch_CSX_COMMON_TX_CLK_EN)
            key_touch_dsRam.snsCsxClk = key_touch_CSX_TX_CLK_DIVIDER;
        #endif /* #if (0u != key_touch_CSX_COMMON_TX_CLK_EN) */
    #endif /* #if (0u != key_touch_CSX_EN) */
    
    #if (0u != key_touch_SELF_TEST_EN)
        key_touch_dsRam.glbCrc = key_touch_GLB_CRC;
    #endif /* #if (0u != key_touch_SELF_TEST_EN) */
   
    /* Initialize RAM widget data */
    key_touch_dsRam.wdgtList = key_touch_ramWidgetInit;
    
    #if (0u != key_touch_CSX_EN) || (0 != key_touch_CSD_IDAC_COMP_EN)
        /* Initialize IDAC data */
        ptrFlashWdgt = key_touch_dsFlash.wdgtArray;
        
        for (wdgtId = key_touch_TOTAL_WIDGETS; wdgtId-- > 0u; )
        {
            ptrSns = ptrFlashWdgt->ptr2SnsRam;
                
            for (snsId = key_touch_GET_SNS_CNT_BY_PTR(ptrFlashWdgt); snsId-- > 0u;)
            {
                ptrSns->idacComp[0u] = *ptrIdacInit;
                ptrIdacInit++;
                
                #if (0u != key_touch_MULTI_FREQ_SCAN_EN)
                    ptrSns->idacComp[1u] = *ptrIdacInit;
                    ptrIdacInit++;
                    
                    ptrSns->idacComp[2u] = *ptrIdacInit;
                    ptrIdacInit++;
                #endif /* #if (0u != key_touch_MULTI_FREQ_SCAN_EN) */
                
                ptrSns++;
            }
            
            ptrFlashWdgt++; /* Move to next widget */
        }
    #endif /*(0u != key_touch_CSX_EN) || (0 != key_touch_CSD_IDAC_COMP_EN)*/
    
    #if (0u != key_touch_ADC_EN)
        key_touch_AdcDsInitialize();
    #endif /* (0u != key_touch_ADC_EN) */
}


#if (0u != key_touch_ADC_EN)
    /*******************************************************************************
    * Function Name: key_touch_AdcDsInitialize
    ****************************************************************************//**
    *
    * \brief
    *   Configures the initial Adc datastructure members.
    *
    *******************************************************************************/
    void key_touch_AdcDsInitialize(void)
    {
        key_touch_dsRam.adcResolution = key_touch_ADC_RESOLUTION;
        key_touch_dsRam.adcIdac = (uint8)(key_touch_ADC_IDACVAL);
    }
#endif /* (0u != key_touch_ADC_EN) */


/*******************************************************************************
* Function Name: DsParseParamId
****************************************************************************//**
*
* \brief
*   This function parses the parameter ID and checks its correctness.
*
* \details
*   This function checks the parameter CRC if the self-test is enabled, 
*   validates the offset value and parameter type.
*
* \param paramId The parameter to parse.
* \param pData   The pointer to the structure that will hold parsed data.
*
* \return CYRET_SUCCESS     If the parameter is valid
*         CYRET_BAD_PARAM   If  the parameter is invalid
*
*******************************************************************************/
static cystatus DsParseParamId(uint32 paramId, PARAM_ID_STRUCT *pData)
{
    cystatus result = CYRET_SUCCESS;
    
    #if (0u != key_touch_SELF_TEST_EN)
        const uint8 crcTable[] =
        {
            0x00u, 0x09u, 0x0Bu, 0x02u, 0x0Fu, 0x06u, 0x04u, 0x0Du,
            0x07u, 0x0Eu, 0x0Cu, 0x05u, 0x08u, 0x01u, 0x03u, 0x0Au
        };
        
        uint32 i;
        uint32 actualCrc = 0u;
        uint32 crcIndex;
    #endif /* #if (0u != key_touch_SELF_TEST_EN) */
            
    /* Extract parameter data */
    pData->offset     = LO16(paramId);
    pData->affectsCrc = LO8((paramId & PARAM_UBIT_MASK)  >> PARAM_UBIT_OFFSET);
    pData->widgetId   = LO8((paramId & PARAM_WDID_MASK)  >> PARAM_WDID_OFFSET);
    pData->type       = LO8((paramId & PARAM_TYPE_MASK)  >> PARAM_TYPE_OFFSET);
    pData->flash      = LO8((paramId & PARAM_FBIT_MASK)  >> PARAM_FBIT_OFFSET);
    pData->rw         = LO8((paramId & PARAM_RWBIT_MASK) >> PARAM_RWBIT_OFFSET);
    pData->crc        = LO8((paramId & PARAM_CRC_MASK)   >> PARAM_CRC_OFFSET);
    
    /* Check parameter CRC if self-test is enabled */
    #if (0u != key_touch_SELF_TEST_EN)
 
        /* Calculate CRC for bits 0..24.
         * The CRC is calculated using nibbles (4-bits). 
         * So for 0..24 bits there are in total 6 nibbles. */
        for (i = 6u; i > 0u; i--)
        {
            crcIndex = actualCrc ^ (paramId & 0x0Fu);
            actualCrc = crcTable[crcIndex];
            paramId >>= 4u;
        }

        /* Add bits 28..32 */
        crcIndex = actualCrc ^ ((paramId >> 4u) & 0x0Fu);
        actualCrc = crcTable[crcIndex];

        /* Add bits 24..28 (CRC) */
        crcIndex = actualCrc ^ (paramId & 0x0Fu);
        actualCrc = crcTable[crcIndex];
        
        if (0u != actualCrc)
        {
            /* CRC mismatch */
            result = CYRET_BAD_PARAM;
        }
        
        if ((CYRET_SUCCESS == result) && 
            (0u != pData->affectsCrc) && (pData->widgetId >= key_touch_TOTAL_WIDGETS ))
        {
            /* Wrong widgetId for protected parameter */
            result = CYRET_BAD_PARAM;
        }
        
        /* Check offset value range */
        if (CYRET_SUCCESS == result)
        {
            if (0u == pData->flash)
            {
                /* Check offset for RAM Data Structure range */
                if (pData->offset >= sizeof(key_touch_dsRam))
                {
                    result = CYRET_BAD_PARAM;
                }
            }
            else
            {
                /* Check offset for Flash Data Structure range */
                if (pData->offset >= sizeof(key_touch_dsFlash))
                {
                    result = CYRET_BAD_PARAM;
                }
                
                /* Check if it is marked as Read Only */
                if (0u != pData->rw)
                {
                    result = CYRET_BAD_PARAM;
                }
            }
        }
    #else /* #if (0u != key_touch_SELF_TEST_EN) */
        /* Check offset value range */
        if (0u == pData->flash)
        {
            /* Check offset for RAM Data Structure range */
            if (pData->offset >= sizeof(key_touch_dsRam))
            {
                result = CYRET_BAD_PARAM;
            }
        }
        else
        {
            /* Check offset for Flash Data Structure range */
            if (pData->offset >= sizeof(key_touch_dsFlash))
            {
                result = CYRET_BAD_PARAM;
            }
            
            /* Check if it is marked as Read Only */
            if (0u != pData->rw)
            {
                result = CYRET_BAD_PARAM;
            }
        }
    #endif /* #if (0u != key_touch_SELF_TEST_EN) */

    if (CYRET_SUCCESS == result)
    {
        /* Check parameter type, offset alignment */
        switch (pData->type)
        {
        case DS_PARAM_TYPE_UINT16:
            if (0u != (pData->offset & UINT16_ALIGN_MASK))
            {
                result = CYRET_BAD_PARAM;
            }
            break;
            
        case DS_PARAM_TYPE_UINT32:
            if (0u != (pData->offset & UINT32_ALIGN_MASK))
            {
                result = CYRET_BAD_PARAM;
            }
            break;
            
        case DS_PARAM_TYPE_UINT8:
            break;
            
        default:
            result = CYRET_BAD_PARAM;
            break;
        }
    }

    return result;
}

/*******************************************************************************
* Function Name: key_touch_GetParam
****************************************************************************//**
*
* \brief
*  Gets the specified parameter value from the \ref group_structures.
*
* \details
*  This function gets the value of the specified parameter by the paramId 
*  argument. The paramId for each register is available in the 
*  key_touch RegisterMap header file as 
*  key_touch_<ParameterName>_PARAM_ID. The paramId is a special 
*  enumerated value generated by the customizer. The format of paramId is as 
*  follows:
*    1. [ byte 3 byte 2 byte 1 byte 0 ] 
*    2. [ TTWFCCCC UIIIIIII MMMMMMMM LLLLLLLL ]
*    3. T - encodes the parameter type:
*      - 01b: uint8
*      - 10b: uint16
*      - 11b: uint32
*    4. W - indicates whether the parameter is writable:
*      - 0: ReadOnly
*      - 1: Read/Write
*    5. C - 4 bit CRC (X^3 + 1) of the whole paramId word, the C bits are 
*       filled with 0s when the CRC is calculated.
*    6. U - indicates if the parameter affects the RAM Widget Object CRC.
*    7. I - specifies that the widgetID parameter belongs to
*    8. M,L - the parameter offset MSB and LSB accordingly in:
*      - Flash Data Structure if W bit is 0.
*      - RAM Data Structure if W bit is 1.
*
*  Refer to the \ref group_structures section for details of the data structure 
*  organization and examples of its register access.
*
* \param  paramId 
*  Specify the ID of parameter to get its value.
*  A macro for the parameter ID can be found in the key_touch RegisterMap header 
*  file defined as key_touch_<ParameterName>_PARAM_ID.
*
* \param  value   
*  The pointer to a variable that should be updated with the got value.
*
* \return
*  Returns the status of operation:
*    - CYRET_SUCCESS if the operation is successfully completed.
*    - CYRET_BAD_PARAM if the input parameter is invalid. 
*
*******************************************************************************/
cystatus key_touch_GetParam(uint32 paramId, uint32 *value)
{
    PARAM_ID_STRUCT pData;
    cystatus result;
    
    union
    {
        volatile void   const * ptr;
        volatile uint8  const * ptrUint8;
        volatile uint16 const * ptrUint16;
        volatile uint32 const * ptrUint32;
    } ptrData;
    
    result = DsParseParamId(paramId, &pData);
    
    /* Parse and validate paramId */
    if (CYRET_SUCCESS == result)
    {
        /* Get base address of parameter */
        if (0u == pData.flash)
        {
            ptrData.ptr = &key_touch_dsRam;
        }
        else
        {
            ptrData.ptr = &key_touch_dsFlash;
        }
        
        /* Add offset to base address */
        ptrData.ptrUint8 += pData.offset;
        
        /* Read data */
        if (DS_PARAM_TYPE_UINT8 == pData.type)
        {
            *value = (uint32) (*ptrData.ptrUint8);
        }
        else if (DS_PARAM_TYPE_UINT16 == pData.type)
        {
            *value = (uint32) (*ptrData.ptrUint16);
        }
        else if (DS_PARAM_TYPE_UINT32 == pData.type)
        {
            *value = *ptrData.ptrUint32;
        }
        else
        {
            /* Parameter comes here already validated. */
            CYASSERT(0u);
        }
    }
    
    return result;
}


/*******************************************************************************
* Function Name: key_touch_SetParam
****************************************************************************//**
*
* \brief
*  Sets a new value for the specified parameter in the \ref group_structures.
*
* \details
*  This function sets the value of the specified parameter by the paramId 
*  argument. The paramId for each register is available in the 
*  key_touch RegisterMap header file as 
*  key_touch_<ParameterName>_PARAM_ID. The paramId is a special 
*  enumerated value generated by the customizer. The format of paramId is as 
*  follows:
*    1. [ byte 3 byte 2 byte 1 byte 0 ] 
*    2. [ TTWFCCCC UIIIIIII MMMMMMMM LLLLLLLL ]
*    3. T - encodes the parameter type:
*      - 01b: uint8
*      - 10b: uint16
*      - 11b: uint32
*    4. W - indicates whether the parameter is writable:
*      - 0: ReadOnly
*      - 1: Read/Write
*    5. C - 4 bit CRC (X^3 + 1) of the whole paramId word, the C bits are 
*       filled with 0s when the CRC is calculated.
*    6. U - indicates if the parameter affects the RAM Widget Object CRC.
*    7. I - specifies that the widgetID parameter belongs to
*    8. M,L - the parameter offset MSB and LSB accordingly in:
*      - Flash Data Structure if W bit is 0.
*      - RAM Data Structure if W bit is 1.
*
*  Refer to the \ref group_structures section for details of the data structure 
*  organization and examples of its register access.
*
* \param paramId  
*  Specify the ID of parameter to set its value.
*  A macro for the parameter ID can be found in the key_touch RegisterMap header
*  file defined as key_touch_<ParameterName>_PARAM_ID.

* \param value    
*  Specify the new parameter's value.
*
* \return
*  Returns the status of operation:
*    - CYRET_SUCCESS if the operation is successfully completed.
*    - CYRET_BAD_PARAM if the input parameter is invalid. 
*
*******************************************************************************/
cystatus key_touch_SetParam(uint32 paramId, uint32 value)
{
    cystatus result;
    PARAM_ID_STRUCT pData;
    
    union
    {
        volatile void   * ptr;
        volatile uint8  * ptrUint8;
        volatile uint16 * ptrUint16;
        volatile uint32 * ptrUint32;
    } ptrData;
    
    result = DsParseParamId(paramId, &pData);
    
    /* verify if parameter is writable */
    if (CYRET_SUCCESS == result)
    {
        if (0u == pData.rw)
        {
            result = CYRET_BAD_PARAM;
        }
    }
    
    /* Parse and validate paramId */
    if (CYRET_SUCCESS == result)
    {
        /* Get base address of parameter */
        ptrData.ptr = &key_touch_dsRam;
        
        /* Add offset to base address */
        ptrData.ptrUint8 += pData.offset;
        
        /* Write data */
        if (DS_PARAM_TYPE_UINT8 == pData.type)
        {
            *ptrData.ptrUint8 = LO8(value);
        }
        else if (DS_PARAM_TYPE_UINT16 == pData.type)
        {
            *ptrData.ptrUint16 = LO16(value);
        }
        else if (DS_PARAM_TYPE_UINT32 == pData.type)
        {
            *ptrData.ptrUint32 = value;
        }
        else
        {
            /* Parameter comes here already validated. */
            CYASSERT(0u);
        }
        
        #if (key_touch_ENABLE == (key_touch_TST_WDGT_CRC_EN || key_touch_TST_GLOBAL_CRC_EN))
            /* Update widget or global CRC if self-test is enabled and parameter affects it */
            if (0u != pData.affectsCrc)
            {
                if ((ptrData.ptrUint16 >= &key_touch_dsRam.csd0Config) &&
                    (ptrData.ptrUint16 <  &key_touch_dsRam.glbCrc))
                {
                    
                    #if (key_touch_ENABLE == key_touch_TST_GLOBAL_CRC_EN)
                        key_touch_DsUpdateGlobalCrc();
                    #endif /* (key_touch_ENABLE == key_touch_TST_GLOBAL_CRC_EN) */

                }
                else
                {
                    #if (key_touch_ENABLE == key_touch_TST_WDGT_CRC_EN)
                        key_touch_DsUpdateWidgetCrc((uint32)pData.widgetId);
                    #endif /* (key_touch_ENABLE == key_touch_TST_WDGT_CRC_EN) */
                }
            }
        #endif /* (key_touch_ENABLE == (key_touch_TST_WDGT_CRC_EN || key_touch_TST_GLOBAL_CRC_EN)) */
    }
    
    return result;
}

/*******************************************************************************
* Function Name: key_touch_IsAnyWidgetActive
****************************************************************************//**
*
* \brief
*  Reports if any widget has detected a touch.
*
* \details
*  This function reports if any widget has detected a touch or not by extracting 
*  the information from the wdgtStatus registers 
*  (key_touch_WDGT_STATUS<X>_VALUE). This function does not process any 
*  widget but extracts the processed results from the \ref group_structures.
*
* \return 
*   Returns the touch detection status of all widgets:
*     - Zero if no touch is detected in all widgets or sensors.
*     - Non-zero if at least one widget or sensor detected a touch.
*
*******************************************************************************/
uint32 key_touch_IsAnyWidgetActive(void)
{
    uint32 result = 0Lu;
    uint32 wdWord;
    
    for (wdWord = key_touch_WDGT_STATUS_WORDS; wdWord-- > 0u;)
    {
        result |= key_touch_dsRam.wdgtStatus[wdWord];
    }
    
    return result;
}


/*******************************************************************************
* Function Name: key_touch_IsWidgetActive
****************************************************************************//**
*
* \brief
*  Reports if the specified widget detects a touch on any of its sensors.
*
* \details
*  This function reports if the specified widget has detected a touch or not by 
*  extracting the information from the wdgtStatus registers 
*  (key_touch_WDGT_STATUS<X>_VALUE). This function does not process the 
*  widget, but extracts the processed results from the \ref group_structures.
*
* \param widgetId  
*  Specify the ID number of the widget to get its status.
*  A macro for the widget ID can be found in the key_touch Configuration header 
*  file defined as key_touch_<WidgetName>_WDGT_ID.
*
* \return 
*  Returns the touch detection status of the specified widgets:
*    - Zero if no touch is detected in the specified widget or a wrong widgetId
*      is specified
*    - Non-zero if at least one sensor of the specified widget is active i.e. 
*      touch is detected
*
*******************************************************************************/
uint32 key_touch_IsWidgetActive(uint32 widgetId)
{
    uint32 result = 0Lu;
   
    if (widgetId < key_touch_TOTAL_WIDGETS)
    {
        result = key_touch_GET_WIDGET_ACTIVE_STATUS(widgetId);
    }
    return result;
}


/*******************************************************************************
* Function Name: key_touch_IsSensorActive
****************************************************************************//**
*
* \brief
*  Reports if the specified sensor in the widget detects a touch.
*
* \details 
*  This function reports if the specified sensor in the widget has detected a 
*  touch or not by extracting the information from wdgtStatus registers 
*  (key_touch_WDGT_STATUS<X>_VALUE). This function does not process the
*  widget or sensor, but extracts the processed results from the \ref group_structures.
*   
*  For Proximity sensors this function returns proximity detection status. To 
*  get finger touch status of proximity sensors, use the 
*  key_touch_IsProximitySensorActive() function. 
*
* \param widgetId  
*  Specify the ID number of the widget.
*  A macro for the widget ID can be found in the key_touch Configuration header 
*  file defined as key_touch_<WidgetName>_WDGT_ID 

* \param sensorId  
*  Specify the ID number of the sensor within the widget to get its touch 
*  detection status.
*  A macro for the sensor ID within specified widget can be found in the 
*  key_touch Configuration header file defined as 
*  key_touch_<WidgetName>_SNS<SensorNumber>_ID 
*
* \return 
*  Returns the touch detection status of the specified sensor / widget:
*    - Zero if no touch is detected in the specified sensor / widget or a wrong
*      widget ID / sensor ID is specified
*    - Non-zero if the specified sensor is active i.e. touch is detected. If the
*      specific sensor belongs to a proximity widget, the proximity detection 
*      status is returned.
*
*******************************************************************************/
uint32 key_touch_IsSensorActive(uint32 widgetId, uint32 sensorId)
{
    uint32 result = 0Lu;
    
    if ((widgetId < key_touch_TOTAL_WIDGETS) &&
        (sensorId < key_touch_GET_SENSOR_COUNT(widgetId)))
    {
        #if (key_touch_ENABLE == key_touch_PROXIMITY_WIDGET_EN)
            if (key_touch_WD_PROXIMITY_E == 
				(key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[widgetId].wdgtType)
            {
                sensorId = key_touch_PROX_STS_OFFSET(sensorId);
            }
        #endif /* (key_touch_ENABLE != key_touch_PROXIMITY_WIDGET_EN) */
        result = key_touch_dsRam.snsStatus[widgetId] & (1Lu << sensorId);
    }
    
    return result;
}

#if (0u != key_touch_MATRIX_WIDGET_EN)
/*******************************************************************************
* Function Name: key_touch_IsMatrixButtonsActive
****************************************************************************//**
*
* \brief
*  Reports the status of the specified matrix button widget.
*
* \details 
*  This function reports if the specified matrix widget has detected a touch or
*  not by extracting the information from the wdgtStatus registers 
*  (key_touch_WDGT_STATUS<X>_VALUE for the CSD widgets and 
*  key_touch_SNS_STATUS<WidgetId>_VALUE for CSX widget). In addition, the
*  function provides details of the active sensor including active rows/columns 
*  for the CSD widgets. This function should be used only with the matrix button
*  widgets. This function does not process the widget, but extracts the 
*  processed results from the \ref group_structures.
*
* \param widgetId 
*  Specify the ID number of the matrix button widget to check status of its 
*  sensors. 
*  A macro for widget ID can be found in the key_touch Configuration header file 
*  defined as key_touch_<WidgetName>_WDGT_ID
*
* \return 
*  Returns the touch detection status of sensors in the specified matrix 
*  buttons widget. Zero indicates that no touch is detected in the specified 
*  widget or a wrong widgetId is specified.
*    1. For the matrix buttons widgets with the CSD sensing mode:
*      - Bit [31] if set, indicates that one or more sensors in the widget 
*        detected a touch.
*      - Bits [30..24] is reserved
*      - Bits [23..16] indicates the logical sensor number of the sensor that 
*        detected a touch. If more than one sensor detected a touch for the CSD
*        widget, no status is reported as more than one touch is invalid for the
*        CSD matrix buttons widgets.
*      - Bits [15..8] indicates the active row number.
*      - Bits [7..0] indicates the active column number.
*    2. For the matrix buttons widgets with the CSX widgets, each bit (31..0)
*      corresponds to the TX/RX intersection.
*
*******************************************************************************/
uint32 key_touch_IsMatrixButtonsActive(uint32 widgetId)
{
    uint32 result = 0Lu;
    cystatus state = CYRET_SUCCESS;
    key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt = 0u;
    
    #if (0u != key_touch_CSD_MATRIX_WIDGET_EN)
        key_touch_RAM_WD_CSD_MATRIX_STRUCT *wdCsdMatrix;
    #endif
  
    if (widgetId >= key_touch_TOTAL_WIDGETS)
    {
        state = CYRET_BAD_PARAM;
    }
    else
    {
        ptrFlashWdgt = &key_touch_dsFlash.wdgtArray[widgetId];
        
        if ((key_touch_WD_TYPE_ENUM)ptrFlashWdgt->wdgtType != key_touch_WD_MATRIX_BUTTON_E)
        {
            state = CYRET_BAD_PARAM;
        }
        else if (0u == key_touch_GET_WIDGET_ACTIVE_STATUS(widgetId))
        {
            state = CYRET_BAD_PARAM;
        }
        else
        {
            /* input parameters are OK */
        }
    }
       
    if (CYRET_SUCCESS == state)
    {
        switch(key_touch_GET_SENSE_METHOD(ptrFlashWdgt))
        {
        #if (0u != key_touch_CSD_MATRIX_WIDGET_EN)
            case key_touch_SENSE_METHOD_CSD_E:
                wdCsdMatrix = ptrFlashWdgt->ptr2WdgtRam;
                
                result = key_touch_MATRIX_BUTTONS_TOUCHED | 
                         ((uint32)wdCsdMatrix->posSnsId << 16u)  |
                         ((uint32)wdCsdMatrix->posRow   << 8u)   |
                         (uint32)wdCsdMatrix->posCol;
                break;
        #endif /* #if (0u != key_touch_CSD_MATRIX_WIDGET_EN) */
        
        #if (0u != key_touch_CSX_MATRIX_WIDGET_EN)
            case key_touch_SENSE_METHOD_CSX_E:
                result = key_touch_dsRam.snsStatus[widgetId];
                break;
        #endif /* #if (0u != key_touch_CSX_MATRIX_WIDGET_EN) */
        
        default:
            CYASSERT(0u);
            break;
        }
    }
    
    return result;
}
#endif /* #if (0u != key_touch_MATRIX_WIDGET_EN) */

#if (0u != key_touch_PROXIMITY_WIDGET_EN)
/*******************************************************************************
* Function Name: key_touch_IsProximitySensorActive
****************************************************************************//**
*
* \brief
*  Reports the finger detection status of the specified proximity widget/sensor.
*
* \details 
*  This function reports if the specified proximity sensor has detected a touch
*  or not by extracting the information from the wdgtStatus registers 
*  (key_touch_SNS_STATUS<WidgetId>_VALUE). This function should be used 
*  only with the proximity sensor widgets. This function does not process the 
*  widget but extracts the processed results from the \ref group_structures.
*
* \param widgetId  
*  Specify the ID number of the proximity widget.
*  A macro for the widget ID can be found in the key_touch Configuration header 
*  file defined as key_touch_<WidgetName>_WDGT_ID
*  
* \param proxId    
*  Specify the ID number of the proximity sensor within the proximity widget to 
*  get its touch detection status.
*  A macro for the proximity ID within a specified widget can be found in the
*  key_touch Configuration header file defined as 
*  key_touch_<WidgetName>_SNS<SensorNumber>_ID
*
* \return 
*  Returns the status of the specified sensor of proximity widget. Zero 
*  indicates that no touch is detected in the specified sensor / widget or a 
*  wrong widgetId / proxId is specified.
*    - Bits [31..2] is reserved.
*    - Bit [1] indicates that a touch is detected.
*    - Bit [0] indicates that a proximity is detected.
*
*******************************************************************************/
uint32 key_touch_IsProximitySensorActive(uint32 widgetId, uint32 proxId)
{
    uint32 result = 0Lu;
    
    if ((widgetId < key_touch_TOTAL_WIDGETS) && (proxId < key_touch_GET_SENSOR_COUNT(widgetId)) &&
        (key_touch_WD_PROXIMITY_E == 
            (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[widgetId].wdgtType))
    {
        result = key_touch_dsRam.snsStatus[widgetId];
        result >>= key_touch_PROX_STS_OFFSET(proxId);
        result &=  key_touch_PROX_STS_MASK;
    }
    
    return result;
}
#endif /* #if (0u != key_touch_PROXIMITY_WIDGET_EN) */


#if (0u != key_touch_SLIDER_WIDGET_EN)
/*******************************************************************************
* Function Name: key_touch_GetCentroidPos
****************************************************************************//**
*
* \brief
*  Reports the centroid position for the specified slider widget.
*
* \details 
*  This function reports the centrode value of a specified radial or linear 
*  slider widget by extracting the information from the wdgtStatus registers 
*  (key_touch_<WidgetName>_POSITION<X>_VALUE). This function should be 
*  used only with the radial or linear slider widgets. This function does not 
*  process the widget but extracts the processed results from the \ref group_structures.
*
* \param widgetId 
*  Specify the ID number of the slider widget to get the centroid of the 
*  detected touch.
*  A macro for the widget ID can be found in the 
*  key_touch Configuration header file defined as 
*  key_touch_<WidgetName>_WDGT_ID
*
* \return 
*  Returns the centroid position of a specified slider widget:
*    - The centroid position if a touch is detected.
*    - key_touch_SLIDER_NO_TOUCH if no touch is detected or a wrong 
*      widgetId is specified.
*
*******************************************************************************/
uint32 key_touch_GetCentroidPos(uint32 widgetId)
{
    uint32 result = key_touch_SLIDER_NO_TOUCH;
    key_touch_RAM_WD_SLIDER_STRUCT *wdSlider;
    
    if ((widgetId < key_touch_TOTAL_WIDGETS) && 
        ((key_touch_WD_LINEAR_SLIDER_E == 
            (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[widgetId].wdgtType) ||
         (key_touch_WD_RADIAL_SLIDER_E == 
            (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[widgetId].wdgtType)))
    {
        wdSlider = key_touch_dsFlash.wdgtArray[widgetId].ptr2WdgtRam;
        result = (uint32)wdSlider->position[0u];
    }
    
    return result;
}
#endif /* #if (0u != key_touch_SLIDER_WIDGET_EN) */


#if (0u != key_touch_TOUCHPAD_WIDGET_EN)
/*******************************************************************************
* Function Name: key_touch_GetXYCoordinates
****************************************************************************//**
*
* \brief
*  Reports the X/Y position detected for the specified touchpad widget.
*
* \details 
*  This function reports a touch position (X and Y coordinates) value of a 
*  specified touchpad widget by extracting the information from the wdgtStatus 
*  registers (key_touch_<WidgetName>_POS_Y_VALUE). This function should 
*  be used only with the touchpad widgets. This function does not process the 
*  widget, but extracts the processed results from the \ref group_structures.
*
* \param widgetId 
*  Specify the ID number of the touchpad widget to get the X/Y position of a 
*  detected touch.
*  A macro for the widget ID can be found in the 
*  key_touch Configuration header file defined as 
*  key_touch_<WidgetName>_WDGT_ID.
*
* \return 
*  Returns the touch position of a specified touchpad widget:
*    1. If a touch is detected:
*      - Bits [31..16] indicates the Y coordinate.
*      - Bits [15..0] indicates the X coordinate.
*    2. If no touch is detected or a wrong widgetId is specified:
*      - key_touch_TOUCHPAD_NO_TOUCH.
*
*******************************************************************************/
uint32 key_touch_GetXYCoordinates(uint32 widgetId)
{
    key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt = NULL;
    
    #if (0u != key_touch_CSD_TOUCHPAD_WIDGET_EN)
        key_touch_RAM_WD_CSD_TOUCHPAD_STRUCT *wdCsdTouchpad;
    #endif /* #if (0u != key_touch_CSD_TOUCHPAD_WIDGET_EN) */
    
    #if (0u != key_touch_CSX_TOUCHPAD_WIDGET_EN)
        key_touch_RAM_WD_CSX_TOUCHPAD_STRUCT *wdCsxTouchpad;
    #endif /* #if (0u != key_touch_CSX_TOUCHPAD_WIDGET_EN) */
    
    cystatus state = CYRET_SUCCESS;
    uint32 result = key_touch_TOUCHPAD_NO_TOUCH;

    if (widgetId >= key_touch_TOTAL_WIDGETS)
    {
        state = CYRET_BAD_PARAM;
    }
    else
    {
        ptrFlashWdgt = &key_touch_dsFlash.wdgtArray[widgetId];
         
        if ((key_touch_WD_TYPE_ENUM)ptrFlashWdgt->wdgtType != key_touch_WD_TOUCHPAD_E)
        {
            state = CYRET_BAD_PARAM;
        }
    }
      
    if (CYRET_SUCCESS == state)
    {
        switch(key_touch_GET_SENSE_METHOD(ptrFlashWdgt))
        {
        #if (0u != key_touch_CSD_TOUCHPAD_WIDGET_EN)
            case key_touch_SENSE_METHOD_CSD_E:
                wdCsdTouchpad = ptrFlashWdgt->ptr2WdgtRam;
                
                result = ((uint32)wdCsdTouchpad->posX) |
                         ((uint32)wdCsdTouchpad->posY << 16u);
                break;
        #endif /* #if (0u != key_touch_CSD_TOUCHPAD_WIDGET_EN) */
        
        #if (0u != key_touch_CSX_TOUCHPAD_WIDGET_EN)
            case key_touch_SENSE_METHOD_CSX_E:
                wdCsxTouchpad = ptrFlashWdgt->ptr2WdgtRam;
                
                result = ((uint32)wdCsxTouchpad->touch[0u].x) |
                         ((uint32)wdCsxTouchpad->touch[0u].y << 16u);
                break;
        #endif /* #if (0u != key_touch_CSX_TOUCHPAD_WIDGET_EN) */
        
        default:
            CYASSERT(0u);
            break;
        }
    }
    
    return result;
}
#endif /* #if (0u != key_touch_TOUCHPAD_WIDGET_EN) */


/* [] END OF FILE */
