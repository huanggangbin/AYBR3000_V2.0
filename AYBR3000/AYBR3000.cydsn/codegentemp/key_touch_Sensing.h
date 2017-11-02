/***************************************************************************//**
* \file key_touch_Sensing.h
* \version 3.10
*
* \brief
* This file provides the headers of APIs specific to implementation of the
* sensing FW block.
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

#if !defined(CY_CAPSENSE_key_touch_SENSING_H)
#define CY_CAPSENSE_key_touch_SENSING_H

#include <CyLib.h>
#include <cyfitter.h>
#include "cytypes.h"
#include "key_touch_Configuration.h"
#include "key_touch_Structure.h"
#if (key_touch_DISABLE == key_touch_CSD2X_EN)
    #include "key_touch_ISR.h"
#endif /* (key_touch_DISABLE == key_touch_CSD2X_EN) */

#if (key_touch_ENABLE == key_touch_CSX_EN)
    #include "key_touch_SensingCSX_LL.h"
#endif /* (key_touch_ENABLE == key_touch_CSX_EN) */
#if (key_touch_ENABLE == key_touch_CSD_EN)
    #include "key_touch_SensingCSD_LL.h"
#endif /* (key_touch_ENABLE == key_touch_CSD_EN) */
#if (key_touch_ENABLE == key_touch_CSD2X_EN)
    #include "key_touch_SensingCSD2X_LL.h"
#endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
#if (key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE)
    #include "key_touch_SmartSense_LL.h"
#endif  /* (key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE) */
#if (key_touch_ENABLE == key_touch_ADC_EN)
    #include "key_touch_Adc.h"
#endif /* (key_touch_ENABLE == key_touch_ADC_EN) */

/*******************************************************************************
* Enumeration types definition
*******************************************************************************/

/* Pin states */
#define key_touch_GROUND                         (0u)
#define key_touch_HIGHZ                          (1u)
#define key_touch_SHIELD                         (2u)
#define key_touch_SENSOR                         (3u)
#define key_touch_TX_PIN                         (4u)
#define key_touch_RX_PIN                         (5u)

/*******************************************************************************
* Function Prototypes
*******************************************************************************/

/**
* \if SECTION_CAPSENSE_HIGH_LEVEL
* \addtogroup group_capsense_high_level
* \{
*/

cystatus key_touch_SetupWidget(uint32 wdgtIndex);
cystatus key_touch_Scan(void);
cystatus key_touch_ScanAllWidgets(void);
uint32 key_touch_IsBusy(void);

/** \}
* \endif */

/**
* \if SECTION_CAPSENSE_LOW_LEVEL
* \addtogroup group_capsense_low_level
* \{
*/

void key_touch_SetPinState(uint32 wdgtIndex, uint32 snsIndex, uint32 state);
#if ((key_touch_ENABLE == key_touch_CSD_IDAC_AUTOCAL_EN) || \
     (key_touch_ENABLE == key_touch_CSX_IDAC_AUTOCAL_EN))
cystatus key_touch_CalibrateWidget(uint32 wdgtIndex);
cystatus key_touch_CalibrateAllWidgets(void);
#endif /* ((key_touch_ENABLE == key_touch_CSD_IDAC_AUTOCAL_EN) || \
           (key_touch_ENABLE == key_touch_CSX_IDAC_AUTOCAL_EN))  */

/** \}
* \endif */

/**
* \if SECTION_CAPSENSE_INTERNAL
* \addtogroup group_capsense_internal
* \{
*/

cystatus key_touch_SsInitialize(void);
void key_touch_SsSetModClkClockDivider(uint32 modClk);
void key_touch_SsSetSnsClockDivider(uint32 snsClk);
void key_touch_SsSetClockDividers(uint32 snsClk, uint32 modClk);
void key_touch_SsIsrInitialize(cyisraddress address);
void key_touch_SsPostAllWidgetsScan(void);
#if ((key_touch_ENABLE == key_touch_CSD_CSX_EN) || \
     (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
     (key_touch_ENABLE == key_touch_ADC_EN))
    void key_touch_SsSwitchSensingMode(key_touch_SENSE_METHOD_ENUM mode);
#endif  /* ((key_touch_ENABLE == key_touch_CSD_CSX_EN) || \
            (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
            (key_touch_ENABLE == key_touch_ADC_EN)) */
#if (key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE)
    cystatus key_touch_SsAutoTune(void);
#endif /* (key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE) */
#if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
    void key_touch_SsChangeImoFreq(uint32 value);
#endif  /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */
#if (key_touch_ENABLE == key_touch_ADC_EN)
    cystatus key_touch_SsReleaseResources(void);
#endif  /* (key_touch_ENABLE == key_touch_ADC_EN) */
#if ((key_touch_ENABLE == key_touch_CSX_EN) || \
     (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
     (key_touch_ENABLE == key_touch_ADC_EN))
    void key_touch_SsSetIOsInDefaultState(void);
#endif  /* #if ((key_touch_ENABLE == key_touch_CSX_EN) || \
        (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
        (key_touch_ENABLE == key_touch_ADC_EN)) */
#if((key_touch_ENABLE == key_touch_CSD_EN) ||\
    (key_touch_ENABLE == key_touch_CSD2X_EN) ||\
    ((key_touch_ENABLE == key_touch_CSX_EN) && (key_touch_ENABLE == key_touch_CSDV2)))
    void key_touch_SsInitializeSourceSenseClk(void);
#endif /* ((key_touch_ENABLE == key_touch_CSD_EN) ||\
           (key_touch_ENABLE == key_touch_CSD2X_EN) ||\
           ((key_touch_ENABLE == key_touch_CSX_EN) && (key_touch_ENABLE == key_touch_CSDV2))) */
#if ((key_touch_ENABLE == key_touch_CSD_EN) ||\
    (key_touch_ENABLE == key_touch_CSD2X_EN))
    void key_touch_SsClearCSDSensors(void);
    uint32 key_touch_SsCSDGetColSnsClkDivider(uint32 wdgtIndex);
    #if (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN))
        uint32 key_touch_SsCSDGetRowSnsClkDivider(uint32 wdgtIndex);
    #endif /* (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)) */
    #if (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE)
        uint8 key_touch_SsCSDCalcPrsSize(uint32 snsClkDivider, uint32 resolution);
    #endif /* (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE) */
#endif /* ((key_touch_ENABLE == key_touch_CSD_EN) ||\
           (key_touch_ENABLE == key_touch_CSD2X_EN)) */

/** \}
* \endif */


/****************************************************************************
* m0s8csd, m0s8peri, hsiom, and IO hardware-related registers address
****************************************************************************/

#define key_touch_DR_MASK                                (0x00000001Lu)

#if (key_touch_ENABLE == key_touch_CSDV2)

    /* CSDv2 block registers   */
    #define key_touch_CONFIG_REG                         (*(reg32 *) CYREG_CSD_CONFIG)
    #define key_touch_CONFIG_PTR                         ( (reg32 *) CYREG_CSD_CONFIG)

    #define key_touch_STAT_SEQ_REG                       (*(reg32 *) CYREG_CSD_CONFIG)
    #define key_touch_STAT_SEQ_PTR                       ( (reg32 *) CYREG_CSD_CONFIG)

    #define key_touch_IDAC_MOD_REG                       (*(reg32 *) CYREG_CSD_IDACA)
    #define key_touch_IDAC_MOD_PTR                       ( (reg32 *) CYREG_CSD_IDACA)

    #define key_touch_IDAC_COMP_REG                      (*(reg32 *) CYREG_CSD_IDACB)
    #define key_touch_IDAC_COMP_PTR                      ( (reg32 *) CYREG_CSD_IDACB)

    #define key_touch_SENSE_PERIOD_REG                   (*(reg32 *) CYREG_CSD_SENSE_PERIOD)
    #define key_touch_SENSE_PERIOD_PTR                   ( (reg32 *) CYREG_CSD_SENSE_PERIOD)

    #define key_touch_RESULT_VAL1_REG                    (*(reg32 *) CYREG_CSD_RESULT_VAL1)
    #define key_touch_RESULT_VAL1_PTR                    ( (reg32 *) CYREG_CSD_RESULT_VAL1)

    #define key_touch_RESULT_VAL2_REG                    (*(reg32 *) CYREG_CSD_RESULT_VAL2)
    #define key_touch_RESULT_VAL2_PTR                    ( (reg32 *) CYREG_CSD_RESULT_VAL2)

    #define key_touch_INTR_REG                           (*(reg32 *) CYREG_CSD_INTR)
    #define key_touch_INTR_PTR                           ( (reg32 *) CYREG_CSD_INTR)

    #define key_touch_INTR_SET_REG                       (*(reg32 *) CYREG_CSD_INTR_SET)
    #define key_touch_INTR_SET_PTR                       ( (reg32 *) CYREG_CSD_INTR_SET)

    #define key_touch_INTR_MASK_REG                      (*(reg32 *) CYREG_CSD_INTR_MASK)
    #define key_touch_INTR_MASK_PTR                      ( (reg32 *) CYREG_CSD_INTR_MASK)

    #define key_touch_COUNTER_REG                        (key_touch_RESULT_VAL1_REG)
    #define key_touch_COUNTER_PTR                        (key_touch_RESULT_VAL1_PTR)

    #define key_touch_REFGEN_REG                         (*(reg32 *) CYREG_CSD_REFGEN)
    #define key_touch_REFGEN_PTR                         ( (reg32 *) CYREG_CSD_REFGEN)

    #define key_touch_SEQ_TIME_REG                       (*(reg32 *) CYREG_CSD_SEQ_TIME)
    #define key_touch_SEQ_TIME_PTR                       ( (reg32 *) CYREG_CSD_SEQ_TIME)

    #define key_touch_SEQ_INIT_CNT_REG                   (*(reg32 *) CYREG_CSD_SEQ_INIT_CNT)
    #define key_touch_SEQ_INIT_CNT_PTR                   ( (reg32 *) CYREG_CSD_SEQ_INIT_CNT)

    #define key_touch_SEQ_NORM_CNT_REG                   (*(reg32 *) CYREG_CSD_SEQ_NORM_CNT)
    #define key_touch_SEQ_NORM_CNT_PTR                   ( (reg32 *) CYREG_CSD_SEQ_NORM_CNT)

    #define key_touch_SEQ_START_REG                      (*(reg32 *) CYREG_CSD_SEQ_START)
    #define key_touch_SEQ_START_PTR                      ( (reg32 *) CYREG_CSD_SEQ_START)

    #define key_touch_CSDCMP_REG                         (*(reg32 *) CYREG_CSD_CSDCMP)
    #define key_touch_CSDCMP_PTR                         ( (reg32 *) CYREG_CSD_CSDCMP)

    #define key_touch_HSCMP_REG                          (*(reg32 *) CYREG_CSD_HSCMP)
    #define key_touch_HSCMP_PTR                          ( (reg32 *) CYREG_CSD_HSCMP)

    #define key_touch_SENSE_DUTY_REG                     (*(reg32 *) CYREG_CSD_SENSE_DUTY)
    #define key_touch_SENSE_DUTY_PTR                     ( (reg32 *) CYREG_CSD_SENSE_DUTY)

    #define key_touch_AMBUF_REG                          (*(reg32 *) CYREG_CSD_AMBUF)
    #define key_touch_AMBUF_PTR                          ( (reg32 *) CYREG_CSD_AMBUF)

    #define key_touch_SW_BYP_SEL_REG                     (*(reg32 *) CYREG_CSD_SW_BYP_SEL)
    #define key_touch_SW_BYP_SEL_PTR                     ( (reg32 *) CYREG_CSD_SW_BYP_SEL)

    #define key_touch_SW_CMP_P_SEL_REG                   (*(reg32 *) CYREG_CSD_SW_CMP_P_SEL)
    #define key_touch_SW_CMP_P_SEL_PTR                   ( (reg32 *) CYREG_CSD_SW_CMP_P_SEL)

    #define key_touch_SW_REFGEN_SEL_REG                  (*(reg32 *) CYREG_CSD_SW_REFGEN_SEL)
    #define key_touch_SW_REFGEN_SEL_PTR                  ( (reg32 *) CYREG_CSD_SW_REFGEN_SEL)

    #define key_touch_SW_CMP_N_SEL_REG                   (*(reg32 *) CYREG_CSD_SW_CMP_N_SEL)
    #define key_touch_SW_CMP_N_SEL_PTR                   ( (reg32 *) CYREG_CSD_SW_CMP_N_SEL)

    #define key_touch_SW_RES_REG                         (*(reg32 *) CYREG_CSD_SW_RES)
    #define key_touch_SW_RES_PTR                         ( (reg32 *) CYREG_CSD_SW_RES)

    #define key_touch_SW_HS_P_SEL_REG                    (*(reg32 *) CYREG_CSD_SW_HS_P_SEL)
    #define key_touch_SW_HS_P_SEL_PTR                    ( (reg32 *) CYREG_CSD_SW_HS_P_SEL)

    #define key_touch_SW_SHIELD_SEL_REG                  (*(reg32 *) CYREG_CSD_SW_SHIELD_SEL)
    #define key_touch_SW_SHIELD_SEL_PTR                  ( (reg32 *) CYREG_CSD_SW_SHIELD_SEL)

    #define key_touch_SW_AMUXBUF_SEL_REG                 (*(reg32 *) CYREG_CSD_SW_AMUXBUF_SEL)
    #define key_touch_SW_AMUXBUF_SEL_PTR                 ( (reg32 *) CYREG_CSD_SW_AMUXBUF_SEL)

    #define key_touch_SW_HS_N_SEL_REG                    (*(reg32 *) CYREG_CSD_SW_HS_N_SEL)
    #define key_touch_SW_HS_N_SEL_PTR                    ( (reg32 *) CYREG_CSD_SW_HS_N_SEL)

    #define key_touch_SW_FW_MOD_SEL_REG                  (*(reg32 *) CYREG_CSD_SW_FW_MOD_SEL)
    #define key_touch_SW_FW_MOD_SEL_PTR                  ( (reg32 *) CYREG_CSD_SW_FW_MOD_SEL)

    #define key_touch_SW_FW_TANK_SEL_REG                 (*(reg32 *) CYREG_CSD_SW_FW_TANK_SEL)
    #define key_touch_SW_FW_TANK_SEL_PTR                 ( (reg32 *) CYREG_CSD_SW_FW_TANK_SEL)

    #define key_touch_SW_DSI_SEL_REG                     (*(reg32 *) CYREG_CSD_SW_DSI_SEL)
    #define key_touch_SW_DSI_SEL_PTR                     ( (reg32 *) CYREG_CSD_SW_DSI_SEL)

    #define key_touch_ADC_CTL_REG                        (*(reg32 *) CYREG_CSD_ADC_CTL)
    #define key_touch_ADC_CTL_PTR                        ( (reg32 *) CYREG_CSD_ADC_CTL)
#else

    #if (key_touch_ENABLE == key_touch_CSD2X_EN)
        /* CSD0 block registers   */
        #define key_touch_CONFIG_REG                     (*(reg32 *) key_touch_CSD0__CSD_CONFIG)
        #define key_touch_CONFIG_PTR                     ( (reg32 *) key_touch_CSD0__CSD_CONFIG)
        #define key_touch_IDAC_CONTR_REG                 (*(reg32 *) key_touch_IDACMod0_cy_psoc4_idac__CONTROL)
        #define key_touch_IDAC_CONTR_PTR                 ( (reg32 *) key_touch_IDACMod0_cy_psoc4_idac__CONTROL)
        #define key_touch_IDAC_REG                       (*(reg32 *) key_touch_IDACMod0_cy_psoc4_idac__CSD_IDAC)
        #define key_touch_IDAC_PTR                       ( (reg32 *) key_touch_IDACMod0_cy_psoc4_idac__CSD_IDAC)
        #define key_touch_COUNTER_REG                    (*(reg32 *) key_touch_CSD0__CSD_COUNTER)
        #define key_touch_COUNTER_PTR                    ( (reg32 *) key_touch_CSD0__CSD_COUNTER)
        #define key_touch_STATUS_REG                     (*(reg32 *) key_touch_CSD0__CSD_STATUS)
        #define key_touch_STATUS_PTR                     ( (reg32 *) key_touch_CSD0__CSD_STATUS)
        #define key_touch_INTR_REG                       (*(reg32 *) key_touch_CSD0__CSD_INTR)
        #define key_touch_INTR_PTR                       ( (reg32 *) key_touch_CSD0__CSD_INTR)
        #define key_touch_INTR_SET_REG                   (*(reg32 *) key_touch_CSD0__CSD_INTR_SET)
        #define key_touch_INTR_SET_PTR                   ( (reg32 *) key_touch_CSD0__CSD_INTR_SET)
        #define key_touch_PWM_REG                        (*(reg32 *) key_touch_CSD0__CSD_PWM)
        #define key_touch_PWM_PTR                        ( (reg32 *) key_touch_CSD0__CSD_PWM)
        #define key_touch_TRIM1_REG                      (*(reg32 *) key_touch_IDACMod0_cy_psoc4_idac__CSD_TRIM1)
        #define key_touch_TRIM1_PTR                      ( (reg32 *) key_touch_IDACMod0_cy_psoc4_idac__CSD_TRIM1)
        #define key_touch_TRIM2_REG                      (*(reg32 *) key_touch_IDACMod0_cy_psoc4_idac__CSD_TRIM2)
        #define key_touch_TRIM2_PTR                      ( (reg32 *) key_touch_IDACMod0_cy_psoc4_idac__CSD_TRIM2)
    #else
        /* CSD block registers   */
        #define key_touch_CONFIG_REG                     (*(reg32 *) key_touch_CSD__CSD_CONFIG)
        #define key_touch_CONFIG_PTR                     ( (reg32 *) key_touch_CSD__CSD_CONFIG)
        #define key_touch_IDAC_CONTR_REG                 (*(reg32 *) key_touch_IDACMod_cy_psoc4_idac__CONTROL)
        #define key_touch_IDAC_CONTR_PTR                 ( (reg32 *) key_touch_IDACMod_cy_psoc4_idac__CONTROL)
        #define key_touch_IDAC_REG                       (*(reg32 *) key_touch_IDACMod_cy_psoc4_idac__CSD_IDAC)
        #define key_touch_IDAC_PTR                       ( (reg32 *) key_touch_IDACMod_cy_psoc4_idac__CSD_IDAC)
        #define key_touch_COUNTER_REG                    (*(reg32 *) key_touch_CSD__CSD_COUNTER)
        #define key_touch_COUNTER_PTR                    ( (reg32 *) key_touch_CSD__CSD_COUNTER)
        #define key_touch_STATUS_REG                     (*(reg32 *) key_touch_CSD__CSD_STATUS)
        #define key_touch_STATUS_PTR                     ( (reg32 *) key_touch_CSD__CSD_STATUS)
        #define key_touch_INTR_REG                       (*(reg32 *) key_touch_CSD__CSD_INTR)
        #define key_touch_INTR_PTR                       ( (reg32 *) key_touch_CSD__CSD_INTR)
        #define key_touch_INTR_SET_REG                   (*(reg32 *) CYREG_CSD_INTR_SET)
        #define key_touch_INTR_SET_PTR                   ( (reg32 *) CYREG_CSD_INTR_SET)
        #define key_touch_PWM_REG                        (*(reg32 *) CYREG_CSD_PWM)
        #define key_touch_PWM_PTR                        ( (reg32 *) CYREG_CSD_PWM)
        #define key_touch_TRIM1_REG                      (*(reg32 *) key_touch_IDACMod_cy_psoc4_idac__CSD_TRIM1)
        #define key_touch_TRIM1_PTR                      ( (reg32 *) key_touch_IDACMod_cy_psoc4_idac__CSD_TRIM1)
        #define key_touch_TRIM2_REG                      (*(reg32 *) key_touch_IDACMod_cy_psoc4_idac__CSD_TRIM2)
        #define key_touch_TRIM2_PTR                      ( (reg32 *) key_touch_IDACMod_cy_psoc4_idac__CSD_TRIM2)
    #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

    #if (key_touch_DISABLE == key_touch_CSD2X_EN)
        #if (CY_PSOC4_4100M || CY_PSOC4_4200M || CY_PSOC4_4200L)
            #if (1u != key_touch_CSD__CSD_NUMBER)
                #define key_touch_SFLASH_TRIM1_REG           (*(reg8 *) CYREG_SFLASH_CSD_TRIM1_CSD)
                #define key_touch_SFLASH_TRIM1_PTR           ( (reg8 *) CYREG_SFLASH_CSD_TRIM1_CSD)

                #define key_touch_SFLASH_TRIM2_REG           (*(reg8 *) CYREG_SFLASH_CSD_TRIM2_CSD)
                #define key_touch_SFLASH_TRIM2_PTR           ( (reg8 *) CYREG_SFLASH_CSD_TRIM2_CSD)
            #else
                #define key_touch_SFLASH_TRIM1_REG           (*(reg8 *) CYREG_SFLASH_CSD1_TRIM1_CSD)
                #define key_touch_SFLASH_TRIM1_PTR           ( (reg8 *) CYREG_SFLASH_CSD1_TRIM1_CSD)

                #define key_touch_SFLASH_TRIM2_REG           (*(reg8 *) CYREG_SFLASH_CSD1_TRIM2_CSD)
                #define key_touch_SFLASH_TRIM2_PTR           ( (reg8 *) CYREG_SFLASH_CSD1_TRIM2_CSD)
            #endif /* (1u != key_touch_CSD__CSD_NUMBER) */
        #else
            #define key_touch_SFLASH_TRIM1_REG               (*(reg8 *) CYREG_SFLASH_CSD_TRIM1_CSD)
            #define key_touch_SFLASH_TRIM1_PTR               ( (reg8 *) CYREG_SFLASH_CSD_TRIM1_CSD)

            #define key_touch_SFLASH_TRIM2_REG               (*(reg8 *) CYREG_SFLASH_CSD_TRIM2_CSD)
            #define key_touch_SFLASH_TRIM2_PTR               ( (reg8 *) CYREG_SFLASH_CSD_TRIM2_CSD)
        #endif /* (CY_PSOC4_4100M || CY_PSOC4_4200M || CY_PSOC4_4200L) */
    #endif /* (key_touch_DISABLE == key_touch_CSD2X_EN) */
#endif /* (key_touch_ENABLE == key_touch_CSDV2) */

/* CSDv1 and CSDv2 PERI CLOCK registers */
#if defined(CYIPBLOCK_m0s8peri_VERSION)
    #define key_touch_IS_M0S8PERI_BLOCK                  (1u)
    #define key_touch_M0S8PERI_BLOCK_VER                 ((CYIPBLOCK_m0s8peri_VERSION))
#else
    #define key_touch_IS_M0S8PERI_BLOCK                  (0u)
    #define key_touch_M0S8PERI_BLOCK_VER                 (0u)
#endif /* (CYIPBLOCK_m0s8peri_VERSION) */

#if (key_touch_ENABLE == key_touch_IS_M0S8PERI_BLOCK)
    #define key_touch_MODCLK_DIV_REG                     (*(reg32 *)key_touch_ModClk__DIV_REGISTER)
    #define key_touch_MODCLK_DIV_PTR                     ( (reg32 *)key_touch_ModClk__DIV_REGISTER)
    #define key_touch_MODCLK_CMD_REG                     (*(reg32 *)CYREG_PERI_DIV_CMD)
    #define key_touch_MODCLK_CMD_PTR                     ( (reg32 *)CYREG_PERI_DIV_CMD)
    #if (key_touch_DISABLE == key_touch_CSDV2)
        #define key_touch_SNSCLK_DIV_REG                 (*(reg32 *)key_touch_SnsClk__DIV_REGISTER)
        #define key_touch_SNSCLK_DIV_PTR                 ( (reg32 *)key_touch_SnsClk__DIV_REGISTER)
        #define key_touch_SNSCLK_CMD_REG                 (*(reg32 *)CYREG_PERI_DIV_CMD)
        #define key_touch_SNSCLK_CMD_PTR                 ( (reg32 *)CYREG_PERI_DIV_CMD)
    #endif /* (key_touch_DISABLE == key_touch_CSDV2) */
#else
    #define key_touch_MODCLK_DIV_REG                     (*(reg32 *)key_touch_ModClk__REGISTER)
    #define key_touch_MODCLK_DIV_PTR                     ( (reg32 *)key_touch_ModClk__REGISTER)
    #define key_touch_SNSCLK_DIV_REG                     (*(reg32 *)key_touch_SnsClk__REGISTER)
    #define key_touch_SNSCLK_DIV_PTR                     ( (reg32 *)key_touch_SnsClk__REGISTER)
    #define key_touch_MODCLK_CMD_REG                     (key_touch_MODCLK_DIV_REG)
    #define key_touch_MODCLK_CMD_PTR                     (key_touch_MODCLK_DIV_PTR)
    #define key_touch_SNSCLK_CMD_REG                     (key_touch_SNSCLK_DIV_REG)
    #define key_touch_SNSCLK_CMD_PTR                     (key_touch_SNSCLK_DIV_PTR)
#endif /* (key_touch_ENABLE == key_touch_IS_M0S8PERI_BLOCK) */

/****************************************************************************
* m0s8csd, m0s8peri, hsiom, and IO hardware-related registers masks
****************************************************************************/
#if (key_touch_ENABLE == key_touch_CSDV2)

    /* CSDv2 masks for Cmod, Cshield and Csh pads */
    #if (key_touch_ENABLE == key_touch_CSD_CSX_EN)
        #define key_touch_CMOD_PAD                       (1u)
        #define key_touch_CSHIELD_PAD                    (4u)
        #define key_touch_CSH_TANK_PAD                   (2u)
        #define key_touch_CMOD_CONNECTION                (key_touch_CSHIELD_PAD)
    #elif (key_touch_ENABLE == key_touch_CSD_EN)
        #define key_touch_CMOD_PAD                       (key_touch_CSD__CMOD_PAD)
        #define key_touch_CSHIELD_PAD                    (key_touch_CSD__CSHIELD_PAD)
        #define key_touch_CSH_TANK_PAD                   (key_touch_CSD__CSH_TANK_PAD)
        #define key_touch_CMOD_CONNECTION                (key_touch_CSD__DEDICATED_IO)
    #else
        /* Not supported mode */
    #endif  /* (key_touch_ENABLE == key_touch_CSD_CSX_EN) */

    #if ((key_touch_ENABLE == key_touch_CSD_SHIELD_EN) && \
         (key_touch_ENABLE == key_touch_CSD_SHIELD_TANK_EN))
        #if ((4u == key_touch_Csh__PORT) && (3u == key_touch_Csh__SHIFT))
            #define key_touch_CTANK_CONNECTION           (key_touch_CSH_TANK_PAD)
        #elif ((4u == key_touch_Csh__PORT) && (1u == key_touch_Csh__SHIFT))
            #define key_touch_CTANK_CONNECTION           (key_touch_CSHIELD_PAD)
        #elif ((4u == key_touch_Csh__PORT) && (2u == key_touch_Csh__SHIFT))
            #define key_touch_CTANK_CONNECTION           (key_touch_CMOD_PAD)
        #else
            #define key_touch_CTANK_CONNECTION           (0u)
        #endif /* ((4u == key_touch_Csh__PORT) || (2u == key_touch_Csh__SHIFT)) */
    #else
        #define key_touch_CTANK_CONNECTION               (0u)
    #endif /* ((key_touch_ENABLE == key_touch_CSD_SHIELD_EN) && \
               (key_touch_ENABLE == key_touch_CSD_SHIELD_TANK_EN)) */

    /* CSDv2 masks for the resistance or low EMI (slow ramp)  */
    #define key_touch_RES_LOW                            (0u)
    #define key_touch_RES_MED                            (1u)
    #define key_touch_RES_HIGH                           (2u)
    #define key_touch_RES_LOWEMI                         (3u)

    /* CSDv2 masks for the waveforms for corresponding switch  */
    #define key_touch_STATIC_OPEN                        (0x00000000Lu)
    #define key_touch_STATIC_CLOSE                       (0x00000001Lu)
    #define key_touch_PHI1                               (0x00000002Lu)
    #define key_touch_PHI2                               (0x00000003Lu)
    #define key_touch_PHI1_HSCMP                         (0x00000004Lu)
    #define key_touch_PHI2_HSCMP                         (0x00000005Lu)
    #define key_touch_HSCMP                              (0x00000006Lu)

    #define key_touch_SW_DSI_CMOD                        (1uL << 4u)
    #define key_touch_SW_DSI_CTANK                       (1uL << 0u)

    /* CSDv2 CSD_CONFIG register masks    */
    #define key_touch_CONFIG_FILTER_DELAY_MASK           (((0x00000001Lu << CYFLD_CSD_FILTER_DELAY__SIZE) - 1u) << CYFLD_CSD_FILTER_DELAY__OFFSET)
    #define key_touch_CONFIG_FILTER_DELAY_2_CYCLES       (0x00000002Lu)
    #define key_touch_CONFIG_FILTER_DELAY_3_CYCLES       (0x00000003Lu)
    #define key_touch_CONFIG_FILTER_DELAY_4_CYCLES       (0x00000004Lu)
    #define key_touch_CONFIG_FILTER_DELAY_12MHZ          (key_touch_CONFIG_FILTER_DELAY_2_CYCLES << CYFLD_CSD_FILTER_DELAY__OFFSET)
    #define key_touch_CONFIG_FILTER_DELAY_24MHZ          (key_touch_CONFIG_FILTER_DELAY_3_CYCLES << CYFLD_CSD_FILTER_DELAY__OFFSET)
    #define key_touch_CONFIG_FILTER_DELAY_48MHZ          (key_touch_CONFIG_FILTER_DELAY_4_CYCLES << CYFLD_CSD_FILTER_DELAY__OFFSET)
    #define key_touch_CONFIG_SHIELD_DELAY_MASK           (((0x00000001Lu << CYFLD_CSD_SHIELD_DELAY__SIZE) - 1u) << CYFLD_CSD_SHIELD_DELAY__OFFSET)
    #define key_touch_CONFIG_SENSE_EN_MASK               (((0x00000001Lu << CYFLD_CSD_SENSE_EN__SIZE) - 1u) << CYFLD_CSD_SENSE_EN__OFFSET)
    #define key_touch_CONFIG_CHARGE_MODE_MASK            (((0x00000001Lu << CYFLD_CSD_CHARGE_MODE__SIZE) - 1u) << CYFLD_CSD_CHARGE_MODE__OFFSET)
    #define key_touch_CONFIG_MUTUAL_CAP_MASK             (((0x00000001Lu << CYFLD_CSD_MUTUAL_CAP__SIZE) - 1u) << CYFLD_CSD_MUTUAL_CAP__OFFSET)
    #define key_touch_CONFIG_CSX_DUAL_CNT_MASK           (((0x00000001Lu << CYFLD_CSD_CSX_DUAL_CNT__SIZE) - 1u) << CYFLD_CSD_CSX_DUAL_CNT__OFFSET)
    #define key_touch_CONFIG_DSI_COUNT_SEL_MASK          (((0x00000001Lu << CYFLD_CSD_DSI_COUNT_SEL__SIZE) - 1u) << CYFLD_CSD_DSI_COUNT_SEL__OFFSET)
    #define key_touch_CONFIG_DSI_SAMPLE_EN_MASK          (((0x00000001Lu << CYFLD_CSD_DSI_SAMPLE_EN__SIZE) - 1u) << CYFLD_CSD_DSI_SAMPLE_EN__OFFSET)
    #define key_touch_CONFIG_SAMPLE_SYNC_MASK            (((0x00000001Lu << CYFLD_CSD_SAMPLE_SYNC__SIZE) - 1u) << CYFLD_CSD_SAMPLE_SYNC__OFFSET)
    #define key_touch_CONFIG_DSI_SENSE_EN_MASK           (((0x00000001Lu << CYFLD_CSD_DSI_SENSE_EN__SIZE) - 1u) << CYFLD_CSD_DSI_SENSE_EN__OFFSET)
    #define key_touch_CONFIG_LP_MODE_MASK                (((0x00000001Lu << CYFLD_CSD_LP_MODE__SIZE) - 1u) << CYFLD_CSD_LP_MODE__OFFSET)
    #define key_touch_CONFIG_ENABLE_MASK                 (((0x00000001Lu << CYFLD_CSD_ENABLE__SIZE) - 1u) << CYFLD_CSD_ENABLE__OFFSET)

    /* CSDv2 CSD_STATUS register masks    */
    #define key_touch_STATUS_CSD_CHARGE_MASK             (((0x00000001Lu << CYFLD_CSD_CSD_CHARGE__SIZE) - 1u) << CYFLD_CSD_CSD_CHARGE__OFFSET)
    #define key_touch_STATUS_CSD_SENSE_MASK              (((0x00000001Lu << CYFLD_CSD_CSD_SENSE__SIZE) - 1u) << CYFLD_CSD_CSD_SENSE__OFFSET)
    #define key_touch_STATUS_HSCMP_OUT_MASK              (((0x00000001Lu << CYFLD_CSD_HSCMP_OUT__SIZE) - 1u) << CYFLD_CSD_HSCMP_OUT__OFFSET)
    #define key_touch_STATUS_CSDCMP_OUT_MASK             (((0x00000001Lu << CYFLD_CSD_CSDCMP_OUT__SIZE) - 1u) << CYFLD_CSD_CSDCMP_OUT__OFFSET)

    /* CSDv2 STAT_SEQ register masks    */
    #define key_touch_STAT_SEQ_SEQ_STATE_MASK            (((0x00000001Lu << CYFLD_CSD_SEQ_STATE__SIZE) - 1u) << CYFLD_CSD_SEQ_STATE__OFFSET)
    #define key_touch_STAT_SEQ_ADC_STATE_MASK            (((0x00000001Lu << CYFLD_CSD_ADC_STATE__SIZE) - 1u) << CYFLD_CSD_ADC_STATE__OFFSET)

    /* CSDv2 sequencer state codes */
    #define key_touch_STAT_SEQ_IDLE                      (0x00000000Lu << CYFLD_CSD_SEQ_STATE__OFFSET)
    #define key_touch_STAT_SEQ_INIT_COARSE               (0x00000001Lu << CYFLD_CSD_SEQ_STATE__OFFSET)
    #define key_touch_STAT_SEQ_AUTO_ZERO_0               (0x00000002Lu << CYFLD_CSD_SEQ_STATE__OFFSET)
    #define key_touch_STAT_SEQ_SAMPLE_INIT               (0x00000003Lu << CYFLD_CSD_SEQ_STATE__OFFSET)
    #define key_touch_STAT_SEQ_AUTO_ZERO_1               (0x00000004Lu << CYFLD_CSD_SEQ_STATE__OFFSET)
    #define key_touch_STAT_SEQ_SAMPLE_NORM               (0x00000005Lu << CYFLD_CSD_SEQ_STATE__OFFSET)


    /* CSDv2 STAT_CNTS register masks    */
    #define key_touch_STAT_CNTS_NUM_CONV_MASK            (((0x00000001Lu << CYFLD_CSD_NUM_CONV__SIZE) - 1u) << CYFLD_CSD_NUM_CONV__OFFSET)

    /* CSDv2 RESULT_VAL1 register masks    */
    #define key_touch_RESULT_VAL1_VALUE_MASK             (((0x00000001Lu << CYFLD_CSD_VALUE__SIZE) - 1u) << CYFLD_CSD_VALUE__OFFSET)
    #define key_touch_RESULT_VAL1_BAD_CONVS_MASK         (((0x00000001Lu << CYFLD_CSD_BAD_CONVS__SIZE) - 1u) << CYFLD_CSD_BAD_CONVS__OFFSET)

    /* CSDv2 RESULT_VAL2 register masks    */
    #define key_touch_RESULT_VAL2_VALUE_MASK             (0x0000FFFFLu)

    /* CSDv2 INTR register masks    */
    #define key_touch_INTR_SAMPLE_MASK                   (((0x00000001Lu << CYFLD_CSD_SAMPLE__SIZE) - 1u) << CYFLD_CSD_SAMPLE__OFFSET)
    #define key_touch_INTR_INIT_MASK                     (((0x00000001Lu << CYFLD_CSD_INIT__SIZE) - 1u) << CYFLD_CSD_INIT__OFFSET)
    #define key_touch_INTR_ADC_RES_MASK                  (((0x00000001Lu << CYFLD_CSD_ADC_RES__SIZE) - 1u) << CYFLD_CSD_ADC_RES__OFFSET)

    /* CSDv2 INTR_SET register masks    */
    #define key_touch_INTR_SET_SAMPLE_MASK               (key_touch_INTR_SAMPLE_MASK)
    #define key_touch_INTR_SET_INIT_MASK                 (key_touch_INTR_INIT_MASK)
    #define key_touch_INTR_SET_ADC_RES_MASK              (key_touch_INTR_ADC_RES_MASK)
    #define key_touch_INTR_SET_MASK                      (key_touch_INTR_SET_SAMPLE_MASK | \
                                                                 key_touch_INTR_SET_INIT_MASK | \
                                                                 key_touch_INTR_SET_ADC_RES_MASK)

    /* CSDv2 INTR_MASK register masks    */
    #define key_touch_INTR_MASK_SAMPLE_MASK              (key_touch_INTR_SAMPLE_MASK)
    #define key_touch_INTR_MASK_INIT_MASK                (key_touch_INTR_INIT_MASK)
    #define key_touch_INTR_MASK_ADC_RES_MASK             (key_touch_INTR_ADC_RES_MASK)


    /* CSDv2 HSCMP v2 register masks    */
    #define key_touch_HSCMP_EN_MASK                      (((0x00000001Lu << CYFLD_CSD_HSCMP_EN__SIZE) - 1u) << CYFLD_CSD_HSCMP_EN__OFFSET)
    #define key_touch_HSCMP_INVERT_MASK                  (((0x00000001Lu << CYFLD_CSD_HSCMP_INVERT__SIZE) - 1u) << CYFLD_CSD_HSCMP_INVERT__OFFSET)
    #define key_touch_CSD_AZ_EN_MASK                     (((0x00000001Lu << CYFLD_CSD_AZ_EN__SIZE) - 1u) << CYFLD_CSD_AZ_EN__OFFSET)

    /* CSDv2 AMBUF v2 register masks    */
    #define key_touch_AMBUF_AMBUF_EN_MASK                ((0x00000001Lu << CYFLD_CSD_PWR_MODE__SIZE) - 1u)
    #define key_touch_AMBUF_PWR_MODE_OFF                 (CYVAL_CSD_PWR_MODE_OFF)
    #define key_touch_AMBUF_PWR_MODE_NORM                (CYVAL_CSD_PWR_MODE_NORM)
    #define key_touch_AMBUF_PWR_MODE_HI                  (CYVAL_CSD_PWR_MODE_HI)

    /* CSDv2 REFGEN v2 register masks    */
    #define key_touch_REFGEN_REFGEN_EN_MASK              ((0x00000001Lu << CYFLD_CSD_REFGEN_EN__SIZE) - 1u)
    #define key_touch_REFGEN_BYPASS_MASK                 (((0x00000001Lu << CYFLD_CSD_BYPASS__SIZE) - 1u) << CYFLD_CSD_BYPASS__OFFSET)
    #define key_touch_REFGEN_VDDA_EN_MASK                (((0x00000001Lu << CYFLD_CSD_VDDA_EN__SIZE) - 1u) << CYFLD_CSD_VDDA_EN__OFFSET)
    #define key_touch_REFGEN_RES_EN_MASK                 (((0x00000001Lu << CYFLD_CSD_RES_EN__SIZE) - 1u) << CYFLD_CSD_RES_EN__OFFSET)
    #define key_touch_REFGEN_GAIN_MASK                   (((0x00000001Lu << CYFLD_CSD_GAIN__SIZE) - 1u) << CYFLD_CSD_GAIN__OFFSET)
    #define key_touch_REFGEN_VREFLO_SEL_MASK             (((0x00000001Lu << CYFLD_CSD_VREFLO_SEL__SIZE) - 1u) << CYFLD_CSD_VREFLO_SEL__OFFSET)
    #define key_touch_REFGEN_VREFLO_INT_MASK             (((0x00000001Lu << CYFLD_CSD_VREFLO_INT__SIZE) - 1u) << CYFLD_CSD_VREFLO_INT__OFFSET)

    /* CSDv2 IDACA v2 register masks  */
    #define key_touch_IDAC_MOD_VAL_MASK                  (((0x00000001Lu << CYFLD_CSD_VAL__SIZE) - 1u) << CYFLD_CSD_VAL__OFFSET)
    #define key_touch_IDAC_MOD_POLARITY_MASK             (((0x00000001Lu << CYFLD_CSD_POLARITY__SIZE) - 1u) << CYFLD_CSD_POLARITY__OFFSET)
    #define key_touch_IDAC_MOD_POLARITY_VSSA_SRC         ((uint32)CYVAL_CSD_POLARITY_VSSA_SRC << CYFLD_CSD_POLARITY__OFFSET)
    #define key_touch_IDAC_MOD_POLARITY_VDDA_SNK         ((uint32)CYVAL_CSD_POLARITY_VDDA_SNK << CYFLD_CSD_POLARITY__OFFSET)
    #define key_touch_IDAC_MOD_POLARITY_SENSE            ((uint32)CYVAL_CSD_POLARITY_SENSE << CYFLD_CSD_POLARITY__OFFSET)
    #define key_touch_IDAC_MOD_POLARITY_SENSE_INV        ((uint32)CYVAL_CSD_POLARITY_SENSE_INV << CYFLD_CSD_POLARITY__OFFSET)
    #define key_touch_IDAC_MOD_POL_DYN_MASK              (((0x00000001Lu << CYFLD_CSD_POL_DYN__SIZE) - 1u) << CYFLD_CSD_POL_DYN__OFFSET)
    #define key_touch_IDAC_MOD_LEG1_MODE_MASK            (((0x00000001Lu << CYFLD_CSD_LEG1_MODE__SIZE) - 1u) << CYFLD_CSD_LEG1_MODE__OFFSET)
    #define key_touch_IDAC_MOD_LEG1_MODE_GP_STATIC_MASK  (CYVAL_CSD_LEG1_MODE_GP_STATIC)
    #define key_touch_IDAC_MOD_LEG1_MODE_GP_MASK         ((uint32)CYVAL_CSD_LEG1_MODE_GP << CYFLD_CSD_LEG1_MODE__OFFSET)
    #define key_touch_IDAC_MOD_LEG1_MODE_CSD_STATIC_MASK ((uint32)CYVAL_CSD_LEG1_MODE_CSD_STATIC << CYFLD_CSD_LEG1_MODE__OFFSET)
    #define key_touch_IDAC_MOD_LEG1_MODE_CSD_MASK        (0x00000003Lu << CYFLD_CSD_LEG1_MODE__OFFSET)
    #define key_touch_IDAC_MOD_LEG2_MODE_MASK            (((0x00000001Lu << CYFLD_CSD_LEG2_MODE__SIZE) - 1u) << CYFLD_CSD_LEG2_MODE__OFFSET)
    #define key_touch_IDAC_MOD_LEG2_MODE_GP_STATIC_MASK  (CYVAL_CSD_LEG2_MODE_GP_STATIC)
    #define key_touch_IDAC_MOD_LEG2_MODE_GP_MASK         ((uint32)CYVAL_CSD_LEG2_MODE_GP << CYFLD_CSD_LEG2_MODE__OFFSET)
    #define key_touch_IDAC_MOD_LEG2_MODE_CSD_STATIC_MASK (0x00000002Lu << CYFLD_CSD_LEG2_MODE__OFFSET)
    #define key_touch_IDAC_MOD_LEG2_MODE_CSD_MASK        ((uint32)CYVAL_CSD_LEG2_MODE_CSD << CYFLD_CSD_LEG2_MODE__OFFSET)
    #define key_touch_IDAC_MOD_BAL_MODE_PHI1             ((uint32)CYVAL_CSD_BAL_MODE_PHI1 << CYFLD_CSD_BAL_MODE__OFFSET)

    #define key_touch_IDAC_MOD_DSI_CTRL_EN_MASK          (0x00200000Lu)
    #define key_touch_IDAC_MOD_RANGE_MASK                (0x00C00000Lu)
    #define key_touch_IDAC_MOD_RANGE_IDAC_LO_MASK        (0x00000000Lu)
    #define key_touch_IDAC_MOD_RANGE_IDAC_MED_MASK       (0x00400000Lu)
    #define key_touch_IDAC_MOD_RANGE_IDAC_HI_MASK        (0x00800000Lu)
    #define key_touch_IDAC_MOD_LEG1_EN_MASK              (0x01000000Lu)
    #define key_touch_IDAC_MOD_LEG2_EN_MASK              (0x02000000Lu)

    /* CSDv2 IDACB v2 register masks  */
    #define key_touch_IDAC_COMP_VAL_MASK                  (((0x00000001Lu << CYFLD_CSD_VAL__SIZE) - 1u) << CYFLD_CSD_VAL__OFFSET)
    #define key_touch_IDAC_COMP_POLARITY_MASK             (((0x00000001Lu << CYFLD_CSD_POLARITY__SIZE) - 1u) << CYFLD_CSD_POLARITY__OFFSET)
    #define key_touch_IDAC_COMP_POLARITY_VSSA_SRC         ((uint32)CYVAL_CSD_POLARITY_VSSA_SRC << CYFLD_CSD_POLARITY__OFFSET)
    #define key_touch_IDAC_COMP_POLARITY_VDDA_SNK         ((uint32)CYVAL_CSD_POLARITY_VDDA_SNK << CYFLD_CSD_POLARITY__OFFSET)
    #define key_touch_IDAC_COMP_POLARITY_SENSE            ((uint32)CYVAL_CSD_POLARITY_SENSE << CYFLD_CSD_POLARITY__OFFSET)
    #define key_touch_IDAC_COMP_POLARITY_SENSE_INV        ((uint32)CYVAL_CSD_POLARITY_SENSE_INV << CYFLD_CSD_POLARITY__OFFSET)
    #define key_touch_IDAC_COMP_POL_DYN_MASK              (((0x00000001Lu << CYFLD_CSD_POL_DYN__SIZE) - 1u) << CYFLD_CSD_POL_DYN__OFFSET)
    #define key_touch_IDAC_COMP_LEG1_MODE_MASK            (((0x00000001Lu << CYFLD_CSD_LEG1_MODE__SIZE) - 1u) << CYFLD_CSD_LEG1_MODE__OFFSET)
    #define key_touch_IDAC_COMP_LEG1_MODE_GP_STATIC_MASK  (CYVAL_CSD_LEG1_MODE_GP_STATIC)
    #define key_touch_IDAC_COMP_LEG1_MODE_GP_MASK         ((uint32)CYVAL_CSD_LEG1_MODE_GP << CYFLD_CSD_LEG1_MODE__OFFSET)
    #define key_touch_IDAC_COMP_LEG1_MODE_CSD_STATIC_MASK ((uint32)CYVAL_CSD_LEG1_MODE_CSD_STATIC << CYFLD_CSD_LEG1_MODE__OFFSET)
    #define key_touch_IDAC_COMP_LEG1_MODE_CSD_MASK        (0x00000003Lu << CYFLD_CSD_LEG1_MODE__OFFSET)
    #define key_touch_IDAC_COMP_LEG2_MODE_MASK            (((0x00000001Lu << CYFLD_CSD_LEG2_MODE__SIZE) - 1u) << CYFLD_CSD_LEG2_MODE__OFFSET)
    #define key_touch_IDAC_COMP_LEG2_MODE_GP_STATIC_MASK  (CYVAL_CSD_LEG2_MODE_GP_STATIC)
    #define key_touch_IDAC_COMP_LEG2_MODE_GP_MASK         ((uint32)CYVAL_CSD_LEG2_MODE_GP << CYFLD_CSD_LEG2_MODE__OFFSET)
    #define key_touch_IDAC_COMP_LEG2_MODE_CSD_STATIC_MASK (0x00000002Lu << CYFLD_CSD_LEG2_MODE__OFFSET)
    #define key_touch_IDAC_COMP_LEG2_MODE_CSD_MASK        ((uint32)CYVAL_CSD_LEG2_MODE_CSD << CYFLD_CSD_LEG2_MODE__OFFSET)
    #define key_touch_IDAC_COMP_DSI_CTRL_EN_MASK          (0x00200000Lu)
    #define key_touch_IDAC_COMP_RANGE_MASK                (0x00C00000Lu)
    #define key_touch_IDAC_COMP_RANGE_IDAC_LO_MASK        (0x00000000Lu)
    #define key_touch_IDAC_COMP_RANGE_IDAC_MED_MASK       (0x00400000Lu)
    #define key_touch_IDAC_COMP_RANGE_IDAC_HI_MASK        (0x00800000Lu)
    #define key_touch_IDAC_COMP_LEG1_EN_MASK              (0x01000000Lu)
    #define key_touch_IDAC_COMP_LEG2_EN_MASK              (0x02000000Lu)

    /* CSDv2 SENSE_PERIOD register masks  */
    #define key_touch_SENSE_PERIOD_SENSE_DIV_MASK        (((0x00000001Lu << CYFLD_CSD_SENSE_DIV__SIZE) - 1u) << CYFLD_CSD_SENSE_DIV__OFFSET)
    #define key_touch_SENSE_PERIOD_LFSR_SIZE_MASK        (((0x00000001Lu << CYFLD_CSD_LFSR_SIZE__SIZE) - 1u) << CYFLD_CSD_LFSR_SIZE__OFFSET)
    #define key_touch_SENSE_PERIOD_LFSR_SCALE_MASK       (((0x00000001Lu << CYFLD_CSD_LFSR_SCALE__SIZE) - 1u) << CYFLD_CSD_LFSR_SCALE__OFFSET)
    #define key_touch_SENSE_PERIOD_LFSR_CLEAR_MASK       (((0x00000001Lu << CYFLD_CSD_LFSR_CLEAR__SIZE) - 1u) << CYFLD_CSD_LFSR_CLEAR__OFFSET)
    #define key_touch_SENSE_PERIOD_SEL_LFSR_MSB_MASK     (((0x00000001Lu << CYFLD_CSD_SEL_LFSR_MSB__SIZE) - 1u) << CYFLD_CSD_SEL_LFSR_MSB__OFFSET)
    #define key_touch_SENSE_6MHZ                         (6u)
    #define key_touch_SENSE_PERIOD_SENSE_DIV_6MHZ        (CYDEV_BCLK__HFCLK__KHZ/key_touch_CSD_SCANSPEED_DIVIDER/key_touch_SENSE_6MHZ)

    /* CSDv2 SW_BYP_SEL register masks  */
    #define key_touch_SW_BYP_SEL_SW_BYA_MASK             (((0x00000001Lu << CYFLD_CSD_SW_BYA__SIZE) - 1u) << CYFLD_CSD_SW_BYA__OFFSET)
    #define key_touch_SW_BYP_SEL_SW_BYB_MASK             (((0x00000001Lu << CYFLD_CSD_SW_BYB__SIZE) - 1u) << CYFLD_CSD_SW_BYB__OFFSET)
    #define key_touch_SW_BYP_SEL_SW_CBCC_MASK            (((0x00000001Lu << CYFLD_CSD_SW_CBCC__SIZE) - 1u) << CYFLD_CSD_SW_CBCC__OFFSET)

    /* CSDv2 SW_REFGEN_SEL register masks  */
    #define key_touch_SW_REFGEN_SEL_SW_IAIB_MASK         (((0x00000001Lu << CYFLD_CSD_SW_IAIB__SIZE) - 1u) << CYFLD_CSD_SW_IAIB__OFFSET)
    #define key_touch_SW_REFGEN_SEL_SW_IBCB_MASK         (((0x00000001Lu << CYFLD_CSD_SW_IBCB__SIZE) - 1u) << CYFLD_CSD_SW_IBCB__OFFSET)
    #define key_touch_SW_REFGEN_SEL_SW_SGMB_MASK         (((0x00000001Lu << CYFLD_CSD_SW_SGMB__SIZE) - 1u) << CYFLD_CSD_SW_SGMB__OFFSET)
    #define key_touch_SW_REFGEN_SEL_SW_SGRE_MASK         (((0x00000001Lu << CYFLD_CSD_SW_SGRE__SIZE) - 1u) << CYFLD_CSD_SW_SGRE__OFFSET)
    #define key_touch_SW_REFGEN_SEL_SW_SGR_MASK          (((0x00000001Lu << CYFLD_CSD_SW_SGR__SIZE) - 1u) << CYFLD_CSD_SW_SGR__OFFSET)

    /* CSDv2 SW_CMP_N_SEL register masks  */
    #define key_touch_SW_CMP_N_SEL_SW_SCRH_MASK          (((0x00000001Lu << CYFLD_CSD_SW_SCRH__SIZE) - 1u) << CYFLD_CSD_SW_SCRH__OFFSET)
    #define key_touch_SW_CMP_N_SEL_SW_SCRH_STATIC_OPEN   (key_touch_STATIC_OPEN << CYFLD_CSD_SW_SCRH__OFFSET)
    #define key_touch_SW_CMP_N_SEL_SW_SCRH_STATIC_CLOSE  (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_SCRH__OFFSET)
    #define key_touch_SW_CMP_N_SEL_SW_SCRL_MASK          (((0x00000001Lu << CYFLD_CSD_SW_SCRL__SIZE) - 1u) << CYFLD_CSD_SW_SCRL__OFFSET)
    #define key_touch_SW_CMP_N_SEL_SW_SCRL_STATIC_OPEN   (key_touch_STATIC_OPEN << CYFLD_CSD_SW_SCRL__OFFSET)
    #define key_touch_SW_CMP_N_SEL_SW_SCRL_STATIC_CLOSE  (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_SCRL__OFFSET)

    /* CSDv2 SEQ_TIME register masks  */
    #define key_touch_SEQ_TIME_AZ_TIME_MASK              (((0x00000001Lu << CYFLD_CSD_AZ_TIME__SIZE) - 1u) << CYFLD_CSD_AZ_TIME__OFFSET)

    /* CSDv2 SEQ_INIT_CNT register masks  */
    #define key_touch_SEQ_INIT_CNT_CONV_CNT_MASK         (((0x00000001Lu << CYFLD_CSD_CONV_CNT__SIZE) - 1u) << CYFLD_CSD_CONV_CNT__OFFSET)
    #define key_touch_SEQ_INIT_CNT_CONV_CNT_FINE_INIT    (0x0000000ALu)

    /* CSDv2 SEQ_NORM_CNT register masks  */
    #define key_touch_SEQ_NORM_CNT_CONV_CNT_MASK         (((0x00000001Lu << CYFLD_CSD_CONV_CNT__SIZE) - 1u) << CYFLD_CSD_CONV_CNT__OFFSET)

    /* CSDv2 SW_RES register masks  */
    #define key_touch_SW_RES_RES_HCAV_MASK               (((0x00000001Lu << CYFLD_CSD_RES_HCAV__SIZE) - 1u) << CYFLD_CSD_RES_HCAV__OFFSET)
    #define key_touch_SW_RES_RES_HCAG_MASK               (((0x00000001Lu << CYFLD_CSD_RES_HCAG__SIZE) - 1u) << CYFLD_CSD_RES_HCAG__OFFSET)
    #define key_touch_SW_RES_RES_HCBV_MASK               (((0x00000001Lu << CYFLD_CSD_RES_HCBV__SIZE) - 1u) << CYFLD_CSD_RES_HCBV__OFFSET)
    #define key_touch_SW_RES_RES_HCBG_MASK               (((0x00000001Lu << CYFLD_CSD_RES_HCBG__SIZE) - 1u) << CYFLD_CSD_RES_HCBG__OFFSET)
    #define key_touch_SW_RES_RES_F1PM_MASK               (((0x00000001Lu << CYFLD_CSD_RES_F1PM__SIZE) - 1u) << CYFLD_CSD_RES_F1PM__OFFSET)
    #define key_touch_SW_RES_RES_F2PT_MASK               (((0x00000001Lu << CYFLD_CSD_RES_F2PT__SIZE) - 1u) << CYFLD_CSD_RES_F2PT__OFFSET)

    #define key_touch_SW_RES_RES_DEFAULT                 ((key_touch_CSD_INIT_SWITCH_RES << CYFLD_CSD_RES_HCAV__OFFSET) | \
                                                                 (key_touch_CSD_SHIELD_SWITCH_RES << CYFLD_CSD_RES_HCBV__OFFSET))

    /* CSDv2 SW_HS_P_SEL register masks  */
    #define key_touch_SW_HS_P_SEL_SW_HMPM_MASK           (((0x00000001Lu << CYFLD_CSD_SW_HMPM__SIZE) - 1u) << CYFLD_CSD_SW_HMPM__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMPM_STATIC_OPEN    (key_touch_STATIC_OPEN << CYFLD_CSD_SW_HMPM__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE   (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_HMPM__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMPT_MASK           (((0x00000001Lu << CYFLD_CSD_SW_HMPT__SIZE) - 1u) << CYFLD_CSD_SW_HMPT__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMPT_STATIC_OPEN    (key_touch_STATIC_OPEN << CYFLD_CSD_SW_HMPT__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE   (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_HMPT__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMPS_MASK           (((0x00000001Lu << CYFLD_CSD_SW_HMPS__SIZE) - 1u) << CYFLD_CSD_SW_HMPS__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMPS_STATIC_OPEN    (key_touch_STATIC_OPEN << CYFLD_CSD_SW_HMPS__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE   (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_HMPS__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMMA_MASK           (((0x00000001Lu << CYFLD_CSD_SW_HMMA__SIZE) - 1u) << CYFLD_CSD_SW_HMMA__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMMA_STATIC_OPEN    (key_touch_STATIC_OPEN << CYFLD_CSD_SW_HMMA__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMMA_STATIC_CLOSE   (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_HMMA__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMMB_MASK           (((0x00000001Lu << CYFLD_CSD_SW_HMMB__SIZE) - 1u) << CYFLD_CSD_SW_HMMB__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMMB_STATIC_OPEN    (key_touch_STATIC_OPEN << CYFLD_CSD_SW_HMMB__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMMB_STATIC_CLOSE   (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_HMMB__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMCA_MASK           (((0x00000001Lu << CYFLD_CSD_SW_HMCA__SIZE) - 1u) << CYFLD_CSD_SW_HMCA__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMCB_MASK           (((0x00000001Lu << CYFLD_CSD_SW_HMCB__SIZE) - 1u) << CYFLD_CSD_SW_HMCB__OFFSET)
    #define key_touch_SW_HS_P_SEL_SW_HMRH_MASK           (((0x00000001Lu << CYFLD_CSD_SW_HMRH__SIZE) - 1u) << CYFLD_CSD_SW_HMRH__OFFSET)

    /* CSDv2 SW_SHIELD_SEL register masks  */
    #define key_touch_SW_SHIELD_SEL_SW_HCAV_MASK         (((0x00000001Lu << CYFLD_CSD_SW_HCAV__SIZE) - 1u) << CYFLD_CSD_SW_HCAV__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCAV_STATIC_OPEN  (key_touch_STATIC_OPEN)
    #define key_touch_SW_SHIELD_SEL_SW_HCAV_HSCMP        (key_touch_HSCMP)
    #define key_touch_SW_SHIELD_SEL_SW_HCAG_MASK         (((0x00000001Lu << CYFLD_CSD_SW_HCAG__SIZE) - 1u) << CYFLD_CSD_SW_HCAG__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBV_MASK         (((0x00000001Lu << CYFLD_CSD_SW_HCBV__SIZE) - 1u) << CYFLD_CSD_SW_HCBV__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBV_HSCMP        (key_touch_HSCMP << CYFLD_CSD_SW_HCBV__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBV_PHI1         (key_touch_PHI1 << CYFLD_CSD_SW_HCBV__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBV_PHI2         (key_touch_PHI2 << CYFLD_CSD_SW_HCBV__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBV_PHI1_HSCMP   (key_touch_PHI1_HSCMP << CYFLD_CSD_SW_HCBV__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBV_PHI2_HSCMP   (key_touch_PHI2_HSCMP << CYFLD_CSD_SW_HCBV__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBV_STATIC_OPEN  (key_touch_STATIC_OPEN << CYFLD_CSD_SW_HCBV__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBG_MASK         (((0x00000001Lu << CYFLD_CSD_SW_HCBG__SIZE) - 1u) << CYFLD_CSD_SW_HCBG__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBG_HSCMP        (key_touch_HSCMP << CYFLD_CSD_SW_HCBG__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBG_PHI1         (key_touch_PHI1 << CYFLD_CSD_SW_HCBG__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBG_PHI2         (key_touch_PHI2 << CYFLD_CSD_SW_HCBG__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBG_PHI1_HSCMP   (key_touch_PHI1_HSCMP << CYFLD_CSD_SW_HCBG__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBG_PHI2_HSCMP   (key_touch_PHI2_HSCMP << CYFLD_CSD_SW_HCBG__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBG_STATIC_OPEN  (key_touch_STATIC_OPEN << CYFLD_CSD_SW_HCBG__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCCV_MASK         (((0x00000001Lu << CYFLD_CSD_SW_HCCV__SIZE) - 1u) << CYFLD_CSD_SW_HCCV__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCCG_MASK         (((0x00000001Lu << CYFLD_CSD_SW_HCCG__SIZE) - 1u) << CYFLD_CSD_SW_HCCG__OFFSET)

    /* CSDv2 SEQ_START register masks  */
    #define key_touch_SEQ_START_START_MASK               (((0x00000001Lu << CYFLD_CSD_START__SIZE) - 1u) << CYFLD_CSD_START__OFFSET)
    #define key_touch_SEQ_START_SEQ_MODE_MASK            (((0x00000001Lu << CYFLD_CSD_SEQ_MODE__SIZE) - 1u) << CYFLD_CSD_SEQ_MODE__OFFSET)
    #define key_touch_SEQ_START_ABORT_MASK               (((0x00000001Lu << CYFLD_CSD_ABORT__SIZE) - 1u) << CYFLD_CSD_ABORT__OFFSET)
    #define key_touch_SEQ_START_DSI_START_EN_MASK        (((0x00000001Lu << CYFLD_CSD_DSI_START_EN__SIZE) - 1u) << CYFLD_CSD_DSI_START_EN__OFFSET)
    #define key_touch_SEQ_START_AZ0_SKIP_MASK            (((0x00000001Lu << CYFLD_CSD_AZ0_SKIP__SIZE) - 1u) << CYFLD_CSD_AZ0_SKIP__OFFSET)
    #define key_touch_SEQ_START_AZ1_SKIP_MASK            (((0x00000001Lu << CYFLD_CSD_AZ1_SKIP__SIZE) - 1u) << CYFLD_CSD_AZ1_SKIP__OFFSET)

    /* CSDv2 SW_CMP_P_SEL register masks  */
    #define key_touch_SW_CMP_P_SEL_SW_SFPM_MASK          (((0x00000001Lu << CYFLD_CSD_SW_SFPM__SIZE) - 1u) << CYFLD_CSD_SW_SFPM__OFFSET)
    #define key_touch_SW_CMP_P_SEL_SW_SFPM_STATIC_OPEN   (key_touch_STATIC_OPEN << CYFLD_CSD_SW_SFPM__OFFSET)
    #define key_touch_SW_CMP_P_SEL_SW_SFPM_STATIC_CLOSE  (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_SFPM__OFFSET)
    #define key_touch_SW_CMP_P_SEL_SW_SFPT_MASK          (((0x00000001Lu << CYFLD_CSD_SW_SFPT__SIZE) - 1u) << CYFLD_CSD_SW_SFPT__OFFSET)
    #define key_touch_SW_CMP_P_SEL_SW_SFPT_STATIC_OPEN   (key_touch_STATIC_OPEN << CYFLD_CSD_SW_SFPT__OFFSET)
    #define key_touch_SW_CMP_P_SEL_SW_SFPT_STATIC_CLOSE  (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_SFPT__OFFSET)
    #define key_touch_SW_CMP_P_SEL_SW_SFPS_MASK          (((0x00000001Lu << CYFLD_CSD_SW_SFPS__SIZE) - 1u) << CYFLD_CSD_SW_SFPS__OFFSET)
    #define key_touch_SW_CMP_P_SEL_SW_SFPS_STATIC_OPEN   (key_touch_STATIC_OPEN << CYFLD_CSD_SW_SFPS__OFFSET)
    #define key_touch_SW_CMP_P_SEL_SW_SFPS_STATIC_CLOSE  (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_SFPS__OFFSET)
    #define key_touch_SW_CMP_P_SEL_SW_SFMA_MASK          (((0x00000001Lu << CYFLD_CSD_SW_SFMA__SIZE) - 1u) << CYFLD_CSD_SW_SFMA__OFFSET)
    #define key_touch_SW_CMP_P_SEL_SW_SFMB_MASK          (((0x00000001Lu << CYFLD_CSD_SW_SFMB__SIZE) - 1u) << CYFLD_CSD_SW_SFMB__OFFSET)
    #define key_touch_SW_CMP_P_SEL_SW_SFCA_MASK          (((0x00000001Lu << CYFLD_CSD_SW_SFCA__SIZE) - 1u) << CYFLD_CSD_SW_SFCA__OFFSET)
    #define key_touch_SW_CMP_P_SEL_SW_SFCB_MASK          (((0x00000001Lu << CYFLD_CSD_SW_SFCB__SIZE) - 1u) << CYFLD_CSD_SW_SFCB__OFFSET)

    /* CSDv2 CSDCMP register masks    */
    #define key_touch_CSDCMP_CSDCMP_EN_MASK              (((0x00000001Lu << CYFLD_CSD_CSDCMP_EN__SIZE) - 1u) << CYFLD_CSD_CSDCMP_EN__OFFSET)
    #define key_touch_CSDCMP_POLARITY_SEL_MASK           (((0x00000001Lu << CYFLD_CSD_POLARITY_SEL__SIZE) - 1u) << CYFLD_CSD_POLARITY_SEL__OFFSET)
    #define key_touch_CSDCMP_FEEDBACK_MODE_MASK          (((0x00000001Lu << CYFLD_CSD_FEEDBACK_MODE__SIZE) - 1u) << CYFLD_CSD_FEEDBACK_MODE__OFFSET)
    #define key_touch_CSDCMP_AZ_EN_MASK                  (((0x00000001Lu << CYFLD_CSD_AZ_EN__SIZE) - 1u) << CYFLD_CSD_AZ_EN__OFFSET)

    /* CSDv2 SENSE_DUTY register masks  */
    #define key_touch_SENSE_DUTY_SENSE_WIDTH_MASK        (((0x00000001Lu << CYFLD_CSD_SENSE_WIDTH__SIZE) - 1u) << CYFLD_CSD_SENSE_WIDTH__OFFSET)
    #define key_touch_SENSE_DUTY_SENSE_POL_MASK          (((0x00000001Lu << CYFLD_CSD_SENSE_POL__SIZE) - 1u) << CYFLD_CSD_SENSE_POL__OFFSET)
    #define key_touch_SENSE_DUTY_OVERLAP_PHI1_MASK       (((0x00000001Lu << CYFLD_CSD_OVERLAP_PHI1__SIZE) - 1u) << CYFLD_CSD_OVERLAP_PHI1__OFFSET)
    #define key_touch_SENSE_DUTY_OVERLAP_PHI2_MASK       (((0x00000001Lu << CYFLD_CSD_OVERLAP_PHI2__SIZE) - 1u) << CYFLD_CSD_OVERLAP_PHI2__OFFSET)

    /* CSDv2 SW_AMUXBUF_SEL register masks  */
    #define key_touch_SW_AMUXBUF_SEL_SW_IRBY_MASK        (((0x00000001Lu << CYFLD_CSD_SW_IRBY__SIZE) - 1u) << CYFLD_CSD_SW_IRBY__OFFSET)
    #define key_touch_SW_AMUXBUF_SEL_SW_IRLB_MASK        (((0x00000001Lu << CYFLD_CSD_SW_IRLB__SIZE) - 1u) << CYFLD_CSD_SW_IRLB__OFFSET)
    #define key_touch_SW_AMUXBUF_SEL_SW_IRLB_STATIC_CLOSE (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_IRLB__OFFSET)
    #define key_touch_SW_AMUXBUF_SEL_SW_ICA_MASK         (((0x00000001Lu << CYFLD_CSD_SW_ICA__SIZE) - 1u) << CYFLD_CSD_SW_ICA__OFFSET)
    #define key_touch_SW_AMUXBUF_SEL_SW_ICB_MASK         (((0x00000001Lu << CYFLD_CSD_SW_ICB__SIZE) - 1u) << CYFLD_CSD_SW_ICB__OFFSET)
    #define key_touch_SW_AMUXBUF_SEL_SW_ICB_PHI2_HSCMP   (key_touch_PHI2_HSCMP << CYFLD_CSD_SW_ICB__OFFSET)
    #define key_touch_SW_AMUXBUF_SEL_SW_IRLI_MASK        (((0x00000001Lu << CYFLD_CSD_SW_IRLI__SIZE) - 1u) << CYFLD_CSD_SW_IRLI__OFFSET)
    #define key_touch_SW_AMUXBUF_SEL_SW_IRH_MASK         (((0x00000001Lu << CYFLD_CSD_SW_IRH__SIZE) - 1u) << CYFLD_CSD_SW_IRH__OFFSET)
    #define key_touch_SW_AMUXBUF_SEL_SW_IRH_STATIC_CLOSE (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_IRH__OFFSET)
    #define key_touch_SW_AMUXBUF_SEL_SW_IRL_MASK         (((0x00000001Lu << CYFLD_CSD_SW_IRL__SIZE) - 1u) << CYFLD_CSD_SW_IRL__OFFSET)
    #define key_touch_SW_AMUXBUF_SEL_SW_IRL_MASK         (((0x00000001Lu << CYFLD_CSD_SW_IRL__SIZE) - 1u) << CYFLD_CSD_SW_IRL__OFFSET)
    #define key_touch_SW_AMUXBUF_SEL_SW_DEFAULT          (0x01030000Lu)
    #define key_touch_SW_AMUXBUF_SEL_SW_ICB_PHI2         (0x00030000uL)
    #define key_touch_SW_AMUXBUF_SEL_SW_ICB_PHI1         (key_touch_PHI1 << CYFLD_CSD_SW_ICB__OFFSET)

    /* CSDv2 SW_FW_TANK_SEL register masks  */
    #define key_touch_SW_HS_N_SEL_SW_HCCC_MASK           (((0x00000001Lu << CYFLD_CSD_SW_HCCC__SIZE) - 1u) << CYFLD_CSD_SW_HCCC__OFFSET)
    #define key_touch_SW_HS_N_SEL_SW_HCCD_MASK           (((0x00000001Lu << CYFLD_CSD_SW_HCCD__SIZE) - 1u) << CYFLD_CSD_SW_HCCD__OFFSET)
    #define key_touch_SW_HS_N_SEL_SW_HCRH_MASK           (((0x00000001Lu << CYFLD_CSD_SW_HCRH__SIZE) - 1u) << CYFLD_CSD_SW_HCRH__OFFSET)
    #define key_touch_SW_HS_N_SEL_SW_HCRH_STATIC_OPEN    (key_touch_STATIC_OPEN << CYFLD_CSD_SW_HCRH__OFFSET)
    #define key_touch_SW_HS_N_SEL_SW_HCRH_STATIC_CLOSE   (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_HCRH__OFFSET)
    #define key_touch_SW_HS_N_SEL_SW_HCRL_MASK           (((0x00000001Lu << CYFLD_CSD_SW_HCRL__SIZE) - 1u) << CYFLD_CSD_SW_HCRL__OFFSET)
    #define key_touch_SW_HS_N_SEL_SW_HCRL_STATIC_OPEN    (key_touch_STATIC_OPEN << CYFLD_CSD_SW_HCRL__OFFSET)
    #define key_touch_SW_HS_N_SEL_SW_HCRL_STATIC_CLOSE   (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_HCRL__OFFSET)

    /* CSDv2 SW_FW_MOD_SEL register masks  */
    #define key_touch_SW_FW_MOD_SEL_SW_F1PM_MASK         (((0x00000001Lu << CYFLD_CSD_SW_F1PM__SIZE) - 1u) << CYFLD_CSD_SW_F1PM__OFFSET)
    #define key_touch_SW_FW_MOD_SEL_SW_F1PM_STATIC_CLOSE (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_F1PM__OFFSET)
    #define key_touch_SW_FW_MOD_SEL_SW_F1MA_MASK         (((0x00000001Lu << CYFLD_CSD_SW_F1MA__SIZE) - 1u) << CYFLD_CSD_SW_F1MA__OFFSET)
    #define key_touch_SW_FW_MOD_SEL_SW_F1MA_STATIC_CLOSE (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_F1MA__OFFSET)
    #define key_touch_SW_FW_MOD_SEL_SW_F1CA_MASK         (((0x00000001Lu << CYFLD_CSD_SW_F1CA__SIZE) - 1u) << CYFLD_CSD_SW_F1CA__OFFSET)
    #define key_touch_SW_FW_MOD_SEL_SW_F1CA_STATIC_CLOSE (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_F1CA__OFFSET)

    /* CSDv2 SW_FW_TANK_SEL register masks  */
    #define key_touch_SW_FW_TANK_SEL_SW_F2PT_MASK        (((0x00000001Lu << CYFLD_CSD_SW_F2PT__SIZE) - 1u) << CYFLD_CSD_SW_F2PT__OFFSET)
    #define key_touch_SW_FW_TANK_SEL_SW_F2PT_STATIC_CLOSE (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_F2PT__OFFSET)
    #define key_touch_SW_FW_TANK_SEL_SW_F2CB_MASK        (((0x00000001Lu << CYFLD_CSD_SW_F2CB__SIZE) - 1u) << CYFLD_CSD_SW_F2CB__OFFSET)
    #define key_touch_SW_FW_TANK_SEL_SW_F2CB_PHI2        (key_touch_PHI2 << CYFLD_CSD_SW_F2CB__OFFSET)
    #define key_touch_SW_FW_TANK_SEL_SW_F2MA_MASK        (((0x00000001Lu << CYFLD_CSD_SW_F2MA__SIZE) - 1u) << CYFLD_CSD_SW_F2MA__OFFSET)
    #define key_touch_SW_FW_TANK_SEL_SW_F2MA_STATIC_CLOSE (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_F2MA__OFFSET)
    #define key_touch_SW_FW_TANK_SEL_SW_F2CA_MASK        (((0x00000001Lu << CYFLD_CSD_SW_F2CA__SIZE) - 1u) << CYFLD_CSD_SW_F2CA__OFFSET)
    #define key_touch_SW_FW_TANK_SEL_SW_F2CA_STATIC_CLOSE (key_touch_STATIC_CLOSE << CYFLD_CSD_SW_F2CA__OFFSET)

    /* Defining default CSDv2 configuration according to settings in customizer. */
    #define key_touch_DEFAULT_CSD_CONFIG                 (key_touch_CONFIG_FILTER_DELAY_2_CYCLES | key_touch_CONFIG_SAMPLE_SYNC_MASK)

    /* CSDv2 CTANK masks    */
    #define key_touch_CTANK_DR_VDDIO                     (0x0u)
    #define key_touch_CTANK_DR_VSSIO                     (key_touch_DR_MASK << key_touch_CSH_SHIFT)

    /* CSDv2 IDACs' masks */
    #if (key_touch_IDAC_SINKING == key_touch_CSD_IDAC_CONFIG)
        #define key_touch_DEFAULT_IDAC_MOD_POLARITY      (key_touch_IDAC_MOD_POLARITY_VDDA_SNK)
        #define key_touch_DEFAULT_IDAC_COMP_POLARITY     (key_touch_IDAC_COMP_POLARITY_VDDA_SNK)
        #define key_touch_CSH_DR_CONFIG                  (key_touch_CTANK_DR_VSSIO)
    #else
        #define key_touch_DEFAULT_IDAC_MOD_POLARITY      (0x00000000Lu)
        #define key_touch_DEFAULT_IDAC_COMP_POLARITY     (0x00000000Lu)
        #define key_touch_CSH_DR_CONFIG                  (key_touch_CTANK_DR_VDDIO)
    #endif /*  (key_touch_IDAC_SINKING == key_touch_CSD_IDAC_CONFIG) */

    #if (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN)
        #if (key_touch_ENABLE == key_touch_CSD_DEDICATED_IDAC_COMP_EN)
            #if (0u != key_touch_TOTAL_CSD_WIDGETS)
                #define key_touch_IDACB_USED             (1u)
            #else
                #define key_touch_IDACB_USED             (0u)
            #endif /* (0u != key_touch_TOTAL_CSD_WIDGETS) */
            #define key_touch_DEFAULT_IDAC_MOD_LEG2_MODE (key_touch_IDAC_MOD_LEG2_MODE_GP_STATIC_MASK)
            #define key_touch_DEFAULT_IDAC_COMP_LEG1_MODE (key_touch_IDAC_COMP_LEG1_EN_MASK |\
                                                                key_touch_IDAC_COMP_LEG1_MODE_CSD_STATIC_MASK)
            #define key_touch_DEFAULT_SW_REFGEN_SEL      (key_touch_SW_REFGEN_SEL_SW_SGR_MASK |\
                                                                key_touch_SW_REFGEN_SEL_SW_IAIB_MASK)
        #else
            #define key_touch_IDACB_USED                 (0u)
            #define key_touch_DEFAULT_IDAC_MOD_LEG2_MODE (key_touch_IDAC_MOD_LEG2_EN_MASK |\
                                                                key_touch_IDAC_MOD_LEG2_MODE_CSD_STATIC_MASK)
            #define key_touch_DEFAULT_IDAC_COMP_LEG1_MODE (key_touch_IDAC_COMP_LEG1_MODE_GP_STATIC_MASK)
            #define key_touch_DEFAULT_SW_REFGEN_SEL      (key_touch_SW_REFGEN_SEL_SW_SGR_MASK)
        #endif /* (key_touch_ENABLE == key_touch_CSD_DEDICATED_IDAC_COMP_EN)) */
    #else
        #define key_touch_IDACB_USED                     (0u)
        #define key_touch_DEFAULT_IDAC_MOD_LEG2_MODE     (key_touch_IDAC_MOD_LEG2_MODE_GP_STATIC_MASK)
        #define key_touch_DEFAULT_IDAC_COMP_LEG1_MODE    (key_touch_IDAC_COMP_LEG1_MODE_GP_STATIC_MASK)
        #define key_touch_DEFAULT_SW_REFGEN_SEL          (key_touch_SW_REFGEN_SEL_SW_SGR_MASK)
    #endif /* (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) */

    #define key_touch_DEFAULT_IDAC_MOD_LEG1_MODE         (key_touch_IDAC_MOD_LEG1_EN_MASK |\
                                                                key_touch_IDAC_MOD_LEG1_MODE_CSD_MASK)
    #define key_touch_DEFAULT_IDAC_COMP_LEG2_MODE        (key_touch_IDAC_COMP_LEG2_MODE_GP_STATIC_MASK)

    /* IDACs ranges */
    #if (key_touch_IDAC_GAIN_LOW == key_touch_CSD_IDAC_GAIN)
        #define key_touch_DEFAULT_IDAC_MOD_RANGE         (key_touch_IDAC_MOD_RANGE_IDAC_LO_MASK)
        #define key_touch_DEFAULT_IDAC_COMP_RANGE        (key_touch_IDAC_MOD_RANGE_IDAC_LO_MASK)
    #elif (key_touch_IDAC_GAIN_MEDIUM == key_touch_CSD_IDAC_GAIN)
        #define key_touch_DEFAULT_IDAC_MOD_RANGE         (key_touch_IDAC_MOD_RANGE_IDAC_MED_MASK)
        #define key_touch_DEFAULT_IDAC_COMP_RANGE        (key_touch_IDAC_MOD_RANGE_IDAC_MED_MASK)
    #else
        #define key_touch_DEFAULT_IDAC_MOD_RANGE         (key_touch_IDAC_MOD_RANGE_IDAC_HI_MASK)
        #define key_touch_DEFAULT_IDAC_COMP_RANGE        (key_touch_IDAC_MOD_RANGE_IDAC_HI_MASK)
    #endif /* (key_touch_CSD_IDAC_GAIN == key_touch_IDAC_RANGE_8X) */

    #define key_touch_DEFAULT_IDAC_MOD                   (key_touch_DEFAULT_IDAC_MOD_RANGE |\
                                                                key_touch_DEFAULT_IDAC_MOD_POLARITY |\
                                                                key_touch_DEFAULT_IDAC_MOD_LEG1_MODE |\
                                                                key_touch_DEFAULT_IDAC_MOD_LEG2_MODE)

    #define key_touch_DEFAULT_IDAC_COMP                  (key_touch_DEFAULT_IDAC_COMP_RANGE |\
                                                                key_touch_DEFAULT_IDAC_COMP_POLARITY |\
                                                                key_touch_DEFAULT_IDAC_COMP_LEG1_MODE |\
                                                                key_touch_DEFAULT_IDAC_COMP_LEG2_MODE)

    #define key_touch_CALIBRATE_IDAC_MOD                 (key_touch_DEFAULT_IDAC_MOD_RANGE |\
                                                                key_touch_DEFAULT_IDAC_MOD_POLARITY |\
                                                                key_touch_DEFAULT_IDAC_MOD_LEG1_MODE |\
                                                                key_touch_IDAC_MOD_LEG2_MODE_GP_STATIC_MASK)

    #define key_touch_CALIBRATE_IDAC_COMP                (key_touch_DEFAULT_IDAC_COMP_RANGE |\
                                                                key_touch_DEFAULT_IDAC_COMP_POLARITY |\
                                                                key_touch_IDAC_COMP_LEG1_MODE_GP_STATIC_MASK |\
                                                                key_touch_IDAC_COMP_LEG2_MODE_GP_STATIC_MASK)

    #define key_touch_CALIBRATE_SW_REFGEN_SEL            (key_touch_SW_REFGEN_SEL_SW_SGR_MASK)

    #define key_touch_DEFAULT_REFGEN_GAIN                (key_touch_CSD_GAIN << CYFLD_CSD_GAIN__OFFSET)
    #define key_touch_VREF_HI_OVERSHOOT_CORRECTION       (0x00000001Lu)
    #define key_touch_VREF_LOW_MAX_VALUE                 (31Lu)
    #define key_touch_DEFAULT_REFGEN_VREFLO_SEL          ((key_touch_VREF_LOW_MAX_VALUE - key_touch_VREF_HI_OVERSHOOT_CORRECTION) \
                                                                  <<  CYFLD_CSD_VREFLO_SEL__OFFSET)

    #define key_touch_REFGEN_WITH_SHIELD                 (key_touch_REFGEN_REFGEN_EN_MASK |\
                                                                key_touch_REFGEN_RES_EN_MASK |\
                                                                key_touch_DEFAULT_REFGEN_GAIN |\
                                                                key_touch_DEFAULT_REFGEN_VREFLO_SEL)

    #define key_touch_REFGEN_NO_SHIELD                  (key_touch_REFGEN_REFGEN_EN_MASK |\
                                                                key_touch_REFGEN_RES_EN_MASK |\
                                                                key_touch_DEFAULT_REFGEN_GAIN)

    #define key_touch_SENSE_PERIOD_LFSR_SIZE_SHIFT       (CYFLD_CSD_LFSR_SIZE__OFFSET)

    /* Initial PRS mode */
    #define key_touch_PRS_8_CONFIG                       (key_touch_CLK_SOURCE_PRS8)
    #define key_touch_PRS_12_CONFIG                      (key_touch_CLK_SOURCE_PRS12)

    #if (key_touch_CLK_SOURCE_DIRECT == key_touch_CSD_SNS_CLK_SOURCE)
        #define key_touch_DEFAULT_SENSE_PERIOD           (key_touch_CLK_SOURCE_DIRECT)
    #elif (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE)
        #define key_touch_DEFAULT_SENSE_PERIOD           (key_touch_CLK_SOURCE_SSC2)
    #elif ((key_touch_CLK_SOURCE_PRS8) == key_touch_CSD_SNS_CLK_SOURCE)
        #define key_touch_DEFAULT_SENSE_PERIOD           (key_touch_CSD_SNS_CLK_SOURCE)
    #elif ((key_touch_CLK_SOURCE_PRS12) == key_touch_CSD_SNS_CLK_SOURCE)
        #define key_touch_DEFAULT_SENSE_PERIOD           (key_touch_CSD_SNS_CLK_SOURCE)
    #else
        #define key_touch_DEFAULT_SENSE_PERIOD           (key_touch_CSD_SNS_CLK_SOURCE)
    #endif /* (key_touch_CLK_SOURCE_DIRECT != key_touch_CSD_SNS_CLK_SOURCE) */

    #define key_touch_DEFAULT_MODULATION_MODE            (key_touch_DEFAULT_SENSE_PERIOD)

    /* SW_HS_P_SEL switches state for Coarse initialization of CMOD (sense path) */
    #if ((key_touch_ENABLE == key_touch_CSD_CSX_EN) || (key_touch_ENABLE == key_touch_CSD_EN))
        #if (key_touch_CMOD_PAD == key_touch_CMOD_CONNECTION)
            #define key_touch_HS_P_SEL_COARSE_CMOD             (key_touch_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE)
        #elif (key_touch_CSHIELD_PAD == key_touch_CMOD_CONNECTION)
            #define key_touch_HS_P_SEL_COARSE_CMOD             (key_touch_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE)
        #else
            #define key_touch_HS_P_SEL_COARSE_CMOD             (key_touch_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE)
        #endif /* (key_touch_CMOD_PAD == key_touch_CMOD_CONNECTION) */
    #else
        #define key_touch_HS_P_SEL_COARSE_CMOD                 (0x00000000uL)
    #endif /* ((key_touch_ENABLE == key_touch_CSD_CSX_EN) && (key_touch_ENABLE == key_touch_CSD_EN)) */

    #if ((0u != key_touch_CSD_SHIELD_TANK_EN) && (key_touch_ENABLE == key_touch_CSD_SHIELD_EN))
        /* SW_HS_P_SEL switches state for Coarse initialization of CTANK (sense path) */
        #if (key_touch_CSH_TANK_PAD == key_touch_CTANK_CONNECTION)
            #define key_touch_HS_P_SEL_COARSE_TANK             (key_touch_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE)
            #define key_touch_HS_P_SEL_SCAN_TANK               (key_touch_SW_HS_P_SEL_SW_HMPT_STATIC_CLOSE)
        #elif (key_touch_CSHIELD_PAD == key_touch_CTANK_CONNECTION)
            #define key_touch_HS_P_SEL_COARSE_TANK             (key_touch_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE)
            #define key_touch_HS_P_SEL_SCAN_TANK               (key_touch_SW_HS_P_SEL_SW_HMPS_STATIC_CLOSE)
        #elif (key_touch_CMOD_PAD == key_touch_CTANK_CONNECTION)
            #define key_touch_HS_P_SEL_COARSE_TANK             (key_touch_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE)
            #define key_touch_HS_P_SEL_SCAN_TANK               (key_touch_SW_HS_P_SEL_SW_HMPM_STATIC_CLOSE)
        #else
            #define key_touch_HS_P_SEL_COARSE_TANK             (key_touch_SW_HS_P_SEL_SW_HMMA_STATIC_CLOSE)
            #define key_touch_HS_P_SEL_SCAN_TANK               (key_touch_SW_HS_P_SEL_SW_HMMB_STATIC_CLOSE)
        #endif /* (key_touch_CSH_TANK_PAD == key_touch_CTANK_CONNECTION) */
        #define key_touch_SW_HS_P_SEL_SCAN                     (key_touch_HS_P_SEL_SCAN_TANK)
    #else
        #define key_touch_HS_P_SEL_COARSE_TANK                 (0x00000000uL)
        #define key_touch_SW_HS_P_SEL_SCAN                     (key_touch_SW_HS_P_SEL_SW_HMMB_STATIC_CLOSE)
    #endif /* ((0u != key_touch_CSD_CSH_TANK_ENABLE) && (key_touch_ENABLE == key_touch_CSD_SHIELD_EN)) */

    #define key_touch_SW_HS_P_SEL_COARSE                 (key_touch_HS_P_SEL_COARSE_CMOD | key_touch_HS_P_SEL_COARSE_TANK)

    /***************************************
    * CSDv2 Registers shifts
    ***************************************/
    #define key_touch_SHIELD_DELAY_SHIFT                 (CYFLD_CSD_SHIELD_DELAY__OFFSET)
    #define key_touch_LFSR_SIZE_SHIFT                    (CYFLD_CSD_LFSR_SIZE__OFFSET)
    #define key_touch_RESULT_VAL1_BAD_CONVS_SHIFT        (CYFLD_CSD_BAD_CONVS__OFFSET)
    #define key_touch_SW_SHIELD_SEL_SW_HCBV_SHIFT        (CYFLD_CSD_SW_HCBV__OFFSET)

    /***************************************
    * LFSR Register masks
    ***************************************/
    #define key_touch_RESOLUTION_OFFSET                  (0u)
    #define key_touch_LFSR_TABLE_SIZE                    (4u)

    #define key_touch_PRS_LENGTH_2_BITS                  (0x00000003Lu)
    #define key_touch_PRS_LENGTH_3_BITS                  (0x00000007Lu)
    #define key_touch_PRS_LENGTH_4_BITS                  (0x0000000FLu)
    #define key_touch_PRS_LENGTH_5_BITS                  (0x0000001FLu)
    #define key_touch_PRS_LENGTH_8_BITS                  (0x000000FFLu)
    #define key_touch_PRS_LENGTH_12_BITS                 (0x00000FFFLu)

    #if(key_touch_ENABLE != key_touch_CSDV2_REF9P6UA_EN)
        #define key_touch_SNSCLK_SSC1_PERIOD                (3u)
        #define key_touch_SNSCLK_SSC2_PERIOD                (7u)
        #define key_touch_SNSCLK_SSC3_PERIOD                (15u)
        #define key_touch_SNSCLK_SSC4_PERIOD                (31u)

        #define key_touch_SNSCLK_SSC1_RANGE                 (1u)
        #define key_touch_SNSCLK_SSC2_RANGE                 (3u)
        #define key_touch_SNSCLK_SSC3_RANGE                 (7u)
        #define key_touch_SNSCLK_SSC4_RANGE                 (15u)
    #else

        #define key_touch_SNSCLK_SSC1_PERIOD                (63u)
        #define key_touch_SNSCLK_SSC2_PERIOD                (127u)
        #define key_touch_SNSCLK_SSC3_PERIOD                (255u)
        #define key_touch_SNSCLK_SSC4_PERIOD                (511u)

        #define key_touch_SNSCLK_SSC1_RANGE                 (16u)
        #define key_touch_SNSCLK_SSC2_RANGE                 (16u)
        #define key_touch_SNSCLK_SSC3_RANGE                 (16u)
        #define key_touch_SNSCLK_SSC4_RANGE                 (16u)
    #endif /* (key_touch_ENABLE != key_touch_CSDV2_REF9P6UA_EN) */

    #define key_touch_LFSR_DITHER_PERCENTAGE             (10uL)
    #define key_touch_SNSCLK_SSC1_THRESHOLD              (key_touch_LFSR_DITHER_PERCENTAGE * key_touch_SNSCLK_SSC1_RANGE)
    #define key_touch_SNSCLK_SSC2_THRESHOLD              (key_touch_LFSR_DITHER_PERCENTAGE * key_touch_SNSCLK_SSC2_RANGE)
    #define key_touch_SNSCLK_SSC3_THRESHOLD              (key_touch_LFSR_DITHER_PERCENTAGE * key_touch_SNSCLK_SSC3_RANGE)
    #define key_touch_SNSCLK_SSC4_THRESHOLD              (key_touch_LFSR_DITHER_PERCENTAGE * key_touch_SNSCLK_SSC4_RANGE)

    #define key_touch_HFCLK_SNSCLK_FACTOR                (160u)
    #define key_touch_SKIP_INIT_CYCLES                   (4u)

#else

    /* CSDv1 CSD_CONFIG register masks    */
    #define key_touch_CONFIG_BYPASS_SEL_MASK         (0x00000004Lu)
    #define key_touch_CONFIG_FILTER_EN_MASK          (0x00000008Lu)
    #define key_touch_CONFIG_DUAL_CAP_EN_MASK        (0x00000010Lu)
    #define key_touch_CONFIG_PRS_CLEAR_MASK          (0x00000020Lu)
    #define key_touch_CONFIG_PRS_SELECT_MASK         (0x00000040Lu)
    #define key_touch_CONFIG_PRS_12_8_MASK           (0x00000080Lu)
    #define key_touch_CONFIG_SHIELD_DELAY_MASK       (0x00000600Lu)
    #define key_touch_CONFIG_SENSE_COMP_BW_MASK      (0x00000800Lu)
    #define key_touch_CONFIG_SENSE_EN_MASK           (0x00001000Lu)
    #define key_touch_CONFIG_REFBUF_EN_MASK          (0x00002000Lu)
    #define key_touch_CONFIG_COMP_MODE_MASK          (0x00004000Lu)
    #define key_touch_CONFIG_COMP_PIN_MASK           (0x00008000Lu)
    #define key_touch_CONFIG_POLARITY_MASK           (0x00010000Lu)
    #define key_touch_CONFIG_POLARITY2_MASK          (0x00020000Lu)
    #define key_touch_CONFIG_MUTUALCAP_EN_MASK       (0x00040000Lu)
    #define key_touch_CONFIG_SENSE_COMP_EN_MASK      (0x00080000Lu)
    #define key_touch_CONFIG_REFBUF_OUTSEL_MASK      (0x00200000Lu)
    #define key_touch_CONFIG_SENSE_INSEL_MASK        (0x00400000Lu)
    #define key_touch_CONFIG_REFBUF_DRV_MASK         (0x01800000Lu)
    #define key_touch_CONFIG_DDFTSEL_MASK            (0x1C000000Lu)
    #define key_touch_CONFIG_ADFTEN_MASK             (0x20000000Lu)
    #define key_touch_CONFIG_DDFT_COMP_MASK          (0x40000000Lu)
    #define key_touch_CONFIG_ENABLE_MASK             (0x80000000Lu)

    /* CSDv1 CSD_IDAC register masks  */
    #define key_touch_IDAC_MOD_MASK                  (0x000000FFLu)
    #define key_touch_IDAC_MOD_MODE_MASK             (0x00000300Lu)
    #define key_touch_IDAC_MOD_RANGE_MASK            (0x00000400Lu)
    #define key_touch_IDAC_POLARITY1_MIR_MASK        (0x00001000Lu)
    #define key_touch_IDAC_COMP_MASK                 (0x007F0000Lu)
    #define key_touch_IDAC_COMP_MODE_MASK            (0x03000000Lu)
    #define key_touch_IDAC_COMP_RANGE_MASK           (0x04000000Lu)
    #define key_touch_IDAC_POLARITY2_MIR_MASK        (0x10000000Lu)
    #define key_touch_IDAC_FEEDBACK_MODE_MASK        (0x40000000Lu)
    #define key_touch_IDAC_MOD_MODE_OFF              (0x00000000Lu)
    #define key_touch_IDAC_MOD_MODE_FIXED            (0x00000100Lu)
    #define key_touch_IDAC_MOD_MODE_VARIABLE         (0x00000200Lu)
    #define key_touch_IDAC_MOD_MODE_DSI              (0x00000300Lu)
    #define key_touch_IDAC_COMP_MODE_OFF             (0x00000000Lu)
    #define key_touch_IDAC_COMP_MODE_FIXED           (0x01000000Lu)
    #define key_touch_IDAC_COMP_MODE_VARIABLE        (0x02000000Lu)
    #define key_touch_IDAC_COMP_MODE_DSI             (0x03000000Lu)
    #define key_touch_IDAC_MOD_VALUE_SHIFT           (0u)

    /* CSDv1 CSD_COUNTER register masks   */
    #define key_touch_COUNTER_COUNTER_MASK           (0x0000FFFFLu)
    #define key_touch_COUNTER_PERIOD_MASK            (0xFFFF0000Lu)

    /* CSDv1 CSD_STATUS register masks    */
    #define key_touch_STATUS_CSD_CHARGE_MASK         (0x00000001Lu)
    #define key_touch_STATUS_CSD_SENSE_MASK          (0x00000002Lu)
    #define key_touch_STATUS_COMP_OUT_MASK           (0x00000004Lu)
    #define key_touch_STATUS_SAMPLE                  (0x00000008Lu)

    /* CSDv1 CSD_INTR, CSD_INTR_SET register masks  */
    #define key_touch_INTR_CSD_MASK                  (0x00000001Lu)
    #define key_touch_INTR_SET_CSD_MASK              (0x00000001Lu)
    #define key_touch_INTR_SET_MASK                  (key_touch_INTR_SET_CSD_MASK)

    /* CSDv1 CSD_PWM register masks   */
    #define key_touch_PWM_COUNT_MASK                 (0x0000000FLu)
    #define key_touch_PWM_SEL_MASK                   (0x00000030Lu)

    /* CSDv1 CSD_TRIM1/2 (for IDAC) register masks    */
    #define key_touch_IDAC_TRIM2_MOD_SNK_MASK        (0x0000000FLu)
    #define key_touch_IDAC_TRIM2_COMP_SNK_MASK       (0x000000F0Lu)
    #define key_touch_IDAC_TRIM1_MOD_SRC_MASK        (0x0000000FLu)
    #define key_touch_IDAC_TRIM1_COMP_SRC_MASK       (0x000000F0Lu)

    /* CSDv1 CSD_TRIM FLASH register masks    */
    #define key_touch_SFLASH_TRIM_IDAC_MOD_MASK      (0x0FLu)
    #define key_touch_SFLASH_TRIM_IDAC_COMP_MASK     (0xF0Lu)

    /* CSDv1 Clock register masks    */
    #define key_touch_SNSCLK_CMD_DIV_SHIFT           (0u)
    #define key_touch_SNSCLK_CMD_PA_DIV_SHIFT        (8u)
    #define key_touch_SNSCLK_CMD_DISABLE_SHIFT       (30u)
    #define key_touch_SNSCLK_CMD_ENABLE_SHIFT        (31u)
    #define key_touch_SNSCLK_CMD_DISABLE_MASK        ((uint32)((uint32)1u << key_touch_SNSCLK_CMD_DISABLE_SHIFT))
    #define key_touch_SNSCLK_CMD_ENABLE_MASK         ((uint32)((uint32)1u << key_touch_SNSCLK_CMD_ENABLE_SHIFT))

    /* CSDv1 CTANK masks    */
    #define key_touch_CTANK_DR_VDDIO                 (0x0u)
    #define key_touch_CTANK_DR_VSSIO                 (key_touch_DR_MASK << key_touch_CSH_SHIFT)

    #define key_touch_PRS_8_CONFIG                   key_touch_CONFIG_PRS_SELECT_MASK
    #define key_touch_PRS_12_CONFIG                  (key_touch_CONFIG_PRS_12_8_MASK |\
                                                            key_touch_CONFIG_PRS_SELECT_MASK)

    /* CSDv1 Initial PRS mode */
    #if (key_touch_CLK_SOURCE_PRS8 == key_touch_CSD_SNS_CLK_SOURCE)
        #define key_touch_DEFAULT_MODULATION_MODE    key_touch_CONFIG_PRS_SELECT_MASK

    #elif (key_touch_CLK_SOURCE_PRS12 == key_touch_CSD_SNS_CLK_SOURCE)
        #define key_touch_DEFAULT_MODULATION_MODE    (key_touch_CONFIG_PRS_12_8_MASK |\
                                                            key_touch_CONFIG_PRS_SELECT_MASK)
    #else
        #define key_touch_DEFAULT_MODULATION_MODE    (0u)
    #endif /* (key_touch_CSD_SNS_CLK_SOURCE == key_touch_PRS_8BITS) */

    #if (key_touch_DISABLE == key_touch_CSD2X_EN)

    /* CSDv1 Set IDAC polarity */
    #if (key_touch_CSD_IDAC_CONFIG == key_touch_IDAC_SINKING)
        #define key_touch_DEFAULT_IDAC_POLARITY      key_touch_CONFIG_POLARITY_MASK
        #define key_touch_CSH_DR_CONFIG              key_touch_CTANK_DR_VDDIO
    #else
        #define key_touch_DEFAULT_IDAC_POLARITY      (0u)
        #define key_touch_CSH_DR_CONFIG              key_touch_CTANK_DR_VSSIO
    #endif /* (key_touch_CSD_IDAC_CONFIG == key_touch_IDAC_SINKING) */

    /* Defining default CSD configuration according to settings in customizer. */
    #define key_touch_DEFAULT_CSD_CONFIG             (key_touch_CONFIG_SENSE_COMP_BW_MASK |\
                                                             key_touch_DEFAULT_IDAC_POLARITY |\
                                                             key_touch_CONFIG_SENSE_INSEL_MASK |\
                                                             key_touch_CONFIG_REFBUF_DRV_MASK)

    #define key_touch_CSD_ENABLE_MASK                (key_touch_CONFIG_ENABLE_MASK |\
                                                             key_touch_CONFIG_SENSE_EN_MASK |\
                                                             key_touch_CONFIG_SENSE_COMP_EN_MASK)

    /* CSDv1 Defining mask intended for clearing bits related to pre-charging options. */
    #define key_touch_PRECHARGE_CONFIG_MASK          (key_touch_CONFIG_REFBUF_EN_MASK |\
                                                             key_touch_CONFIG_COMP_MODE_MASK |\
                                                             key_touch_CONFIG_COMP_PIN_MASK  |\
                                                             key_touch_CONFIG_REFBUF_OUTSEL_MASK)

    #define key_touch_CMOD_PRECHARGE_CONFIG          (key_touch_DEFAULT_CSD_CONFIG |\
                                                             key_touch_CONFIG_REFBUF_EN_MASK |\
                                                             key_touch_CONFIG_COMP_PIN_MASK)

    #define key_touch_CMOD_PRECHARGE_CONFIG_CSD_EN   (key_touch_DEFAULT_CSD_CONFIG |\
                                                             key_touch_CSD_ENABLE_MASK |\
                                                             key_touch_CONFIG_REFBUF_EN_MASK |\
                                                             key_touch_CONFIG_COMP_PIN_MASK)


    /* CSDv1 Ctank pre-charge mode configuration */
    #if(key_touch_CSD_CSH_PRECHARGE_SRC == key_touch_CSH_PRECHARGE_VREF)
        #if (key_touch_ENABLE == key_touch_CSD_SHIELD_EN)
            #define  key_touch_CTANK_PRECHARGE_CONFIG    (key_touch_DEFAULT_CSD_CONFIG |\
                                                                 key_touch_CONFIG_REFBUF_EN_MASK |\
                                                                 key_touch_CONFIG_PRS_CLEAR_MASK |\
                                                                 key_touch_CONFIG_REFBUF_OUTSEL_MASK)
        #else
            #define  key_touch_CTANK_PRECHARGE_CONFIG    (key_touch_DEFAULT_CSD_CONFIG |\
                                                                 key_touch_CONFIG_REFBUF_OUTSEL_MASK |\
                                                                 key_touch_CONFIG_PRS_CLEAR_MASK)
        #endif /* (key_touch_ENABLE == key_touch_CSD_SHIELD_EN) */
    #else
        #define  key_touch_CTANK_PRECHARGE_CONFIG        (key_touch_DEFAULT_CSD_CONFIG |\
                                                                key_touch_CONFIG_REFBUF_OUTSEL_MASK |\
                                                                key_touch_CONFIG_REFBUF_EN_MASK |\
                                                                key_touch_CONFIG_COMP_MODE_MASK |\
                                                                key_touch_CONFIG_PRS_CLEAR_MASK |\
                                                                key_touch_CONFIG_COMP_PIN_MASK)
    #endif /* (key_touch_CSD_CSH_PRECHARGE_SRC == key_touch__CSH_PRECHARGE_IO_BUF) */

    #define  key_touch_CTANK_PRECHARGE_CONFIG_CSD_EN     (key_touch_CTANK_PRECHARGE_CONFIG |\
                                                                 key_touch_CONFIG_ENABLE_MASK |\
                                                                 key_touch_CONFIG_SENSE_COMP_EN_MASK)

    #endif /* (key_touch_DISABLE == key_touch_CSD2X_EN) */

    #define key_touch_RESOLUTION_OFFSET                  (16u)
    #define key_touch_PRS_LENGTH_12_BITS                 (0x00000FFFLu)
    #define key_touch_PRS_LENGTH_8_BITS                  (0x000000FFLu)
    #define key_touch_CSD_PRS_12_BIT                     (key_touch_CONFIG_PRS_12_8_MASK)
    #define key_touch_PRS_MODE_MASK                      (key_touch_CONFIG_PRS_12_8_MASK)

    /***************************************
    * CSDv1 Registers shifts
    ***************************************/
    #define key_touch_SHIELD_DELAY_SHIFT                 (0x09u)
    #define key_touch_IDAC_COMP_DATA_OFFSET              (16u)

#endif /* (key_touch_ENABLE == key_touch_CSDV2) */

    /* CSDv1 and CSDv2 Clock register masks    */
    #define key_touch_MODCLK_CMD_DIV_SHIFT               (0u)
    #define key_touch_MODCLK_CMD_PA_DIV_SHIFT            (8u)
    #define key_touch_MODCLK_CMD_DISABLE_SHIFT           (30u)
    #define key_touch_MODCLK_CMD_ENABLE_SHIFT            (31u)
    #define key_touch_MODCLK_CMD_DISABLE_MASK            ((uint32)((uint32)1u << key_touch_MODCLK_CMD_DISABLE_SHIFT))
    #define key_touch_MODCLK_CMD_ENABLE_MASK             ((uint32)((uint32)1u << key_touch_MODCLK_CMD_ENABLE_SHIFT))

/* CintB and CintA pin registers  */
#if ((key_touch_ENABLE == key_touch_CSX_EN) || (key_touch_ENABLE == key_touch_CSD_CSX_EN))

    #define key_touch_CintA_PC_REG                       (* (reg32 *) key_touch_CintA__0__PC)
    #define key_touch_CintA_DR_REG                       (* (reg32 *) key_touch_CintA__0__DR)
    #define key_touch_CintA_HSIOM_REG                    (* (reg32 *) key_touch_CintA__0__HSIOM)
    #define key_touch_CintB_PC_REG                       (* (reg32 *) key_touch_CintB__0__PC)
    #define key_touch_CintB_DR_REG                       (* (reg32 *) key_touch_CintB__0__DR)
    #define key_touch_CintB_HSIOM_REG                    (* (reg32 *) key_touch_CintB__0__HSIOM)

    #define key_touch_CintA_PC_PTR                       ((reg32 *) key_touch_CintA__0__PC)
    #define key_touch_CintA_DR_PTR                       ((reg32 *) key_touch_CintA__0__DR)
    #define key_touch_CintA_HSIOM_PTR                    ((reg32 *) key_touch_CintA__0__HSIOM)
    #define key_touch_CintB_PC_PTR                       ((reg32 *) key_touch_CintB__0__PC)
    #define key_touch_CintB_DR_PTR                       ((reg32 *) key_touch_CintB__0__DR)
    #define key_touch_CintB_HSIOM_PTR                    ((reg32 *) key_touch_CintB__0__HSIOM)

    /* CintB and CintA pin masks                                                */
    #define key_touch_CintA_HSIOM_MASK                   ((uint32)key_touch_CintA__0__HSIOM_MASK)
    #define key_touch_CintA_HSIOM_SHIFT                  ((uint32)key_touch_CintA__0__HSIOM_SHIFT)
    #define key_touch_CintA_SHIFT                        ((uint32)key_touch_CintA__0__SHIFT)

    #define key_touch_CintB_HSIOM_MASK                   ((uint32)key_touch_CintB__0__HSIOM_MASK)
    #define key_touch_CintB_HSIOM_SHIFT                  ((uint32)key_touch_CintB__0__HSIOM_SHIFT)
    #define key_touch_CintB_SHIFT                        ((uint32)key_touch_CintB__0__SHIFT)

#endif  /* ((key_touch_ENABLE == key_touch_CSX_EN) || (key_touch_ENABLE == key_touch_CSD_CSX_EN)) */

/* CMOD and CSH capacitor port-pins registers */
#if ((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD_CSX_EN))

    #define key_touch_CSH_PC_REG                         (* (reg32 *) key_touch_Csh__PC)
    #define key_touch_CSH_PC_PTR                         (  (reg32 *) key_touch_Csh__PC)
    #define key_touch_CSH_DR_REG                         (* (reg32 *) key_touch_Csh__DR)
    #define key_touch_CSH_DR_PTR                         (  (reg32 *) key_touch_Csh__DR)
    #define key_touch_CSH_HSIOM_REG                      (* (reg32 *) key_touch_Csh__0__HSIOM)
    #define key_touch_CSH_HSIOM_PTR                      (  (reg32 *) key_touch_Csh__0__HSIOM)

    #define key_touch_CMOD_PC_REG                        (* (reg32 *) key_touch_Cmod__PC)
    #define key_touch_CMOD_PC_PTR                        (  (reg32 *) key_touch_Cmod__PC)
    #define key_touch_CMOD_PC_SHIFT                      (key_touch_Cmod__0__SHIFT * 3u)    
    #define key_touch_CMOD_DR_REG                        (* (reg32 *) key_touch_Cmod__DR)
    #define key_touch_CMOD_DR_PTR                        (  (reg32 *) key_touch_Cmod__DR)
    #define key_touch_CMOD_DR_SHIFT                      key_touch_Cmod__0__SHIFT    
    #define key_touch_CMOD_HSIOM_REG                     (* (reg32 *) key_touch_Cmod__0__HSIOM)
    #define key_touch_CMOD_HSIOM_PTR                     (  (reg32 *) key_touch_Cmod__0__HSIOM)

    /* Cmod and Csh pin masks */
    #define key_touch_CMOD_HSIOM_MASK                    key_touch_Cmod__0__HSIOM_MASK
    #define key_touch_CMOD_HSIOM_SHIFT                   key_touch_Cmod__0__HSIOM_SHIFT
    #define key_touch_CSH_HSIOM_MASK                     key_touch_Csh__0__HSIOM_MASK
    #define key_touch_CSH_HSIOM_SHIFT                    key_touch_Csh__0__HSIOM_SHIFT
    #define key_touch_CSH_SHIFT                          key_touch_Csh__0__SHIFT
    #define key_touch_CSH_PC_SHIFT                       (key_touch_Csh__0__SHIFT * 3u)

#endif  /* ((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD_CSX_EN)) */

/* GPIO register masks */
#define key_touch_CSH_TO_AMUXBUS_B_MASK                  (0x00000007Lu)
#define key_touch_CSH_PC_MASK                            (0x00000007Lu)
#define key_touch_CSH_PC_STRONG_MODE                     (0x00000006Lu)

#define key_touch_HSIOM_SEL_MASK                         (0x0000000FLu)
#define key_touch_HSIOM_SEL_GPIO                         (0x00000000Lu)
#define key_touch_HSIOM_SEL_CSD_SENSE                    (0x00000004Lu)
#define key_touch_HSIOM_SEL_CSD_SHIELD                   (0x00000005Lu)
#define key_touch_HSIOM_SEL_AMUXA                        (0x00000006Lu)
#define key_touch_HSIOM_SEL_AMUXB                        (0x00000007Lu)

#define key_touch_GPIO_PC_MASK                           (0x00000007Lu)
#define key_touch_GPIO_HIGHZ_MASK                        (0x00000007Lu)
#define key_touch_GPIO_STRGDRV                           (0x00000006Lu)

#define key_touch_SNS_GROUND_CONNECT                     (0x00000006Lu)

#define key_touch_GPIO_PC_BIT_SIZE                       (3u)

/***************************************
* API Constants
***************************************/

#define key_touch_MOD_CSD_CLK_12MHZ                      (12000000uL)
#define key_touch_MOD_CSD_CLK_24MHZ                      (24000000uL)
#define key_touch_MOD_CSD_CLK_48MHZ                      (48000000uL)

/* ISR Number to work with CyLib functions */
#if (key_touch_ENABLE == key_touch_CSD2X_EN)
    #define key_touch_ISR0_NUMBER                         (key_touch_ISR0__INTC_NUMBER)
    #define key_touch_ISR1_NUMBER                         (key_touch_ISR1__INTC_NUMBER)
#else
    #define key_touch_ISR_NUMBER                         (key_touch_ISR__INTC_NUMBER)
#endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

/* Multi-frequency scanning constants */
#define key_touch_FREQ_CHANNEL_0                         (0u)
#define key_touch_FREQ_CHANNEL_1                         (1u)
#define key_touch_FREQ_CHANNEL_2                         (2u)

/* Bit-mask which says that scanning is not complete */
#if (key_touch_ENABLE == key_touch_CSD2X_EN)
    /* Bit 18: WIDGET BUSY flag status for CSD2X (scan is ccomplete for both channels */
    #define key_touch_STATUS_CSD01_BUSY_SIZE             (0x00000001Lu)
    #define key_touch_STATUS_CSD01_BUSY_SHIFT            (18u)
    #define key_touch_STATUS_CSD01_BUSY_MASK             (key_touch_STATUS_CSD01_BUSY_SIZE << key_touch_STATUS_CSD01_BUSY_SHIFT)

    #define key_touch_SW_STS_BUSY                        (key_touch_STATUS_CSD01_BUSY_MASK)
#else
    #define key_touch_SW_STS_BUSY                        (key_touch_STATUS_CSD0_MASK)
#endif  /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
#define key_touch_NOT_BUSY                               (0u)

#define key_touch_WDGT_SW_STS_BUSY                       (key_touch_STATUS_WDGT0_BUSY_MASK)

/* Definition of time interval that is enough for charging 100nF capacitor */
#define key_touch_AVG_CYCLES_PER_LOOP                    (5u)
#define key_touch_MAX_CHARGE_TIME_US                     (100u)
#define key_touch_SOFTWARE_WDT_CYCLES_NUM                (((CYDEV_BCLK__SYSCLK__MHZ) * (key_touch_MAX_CHARGE_TIME_US)) /\
                                                                 (key_touch_AVG_CYCLES_PER_LOOP))

#define key_touch_DELAY_EXTRACYCLES_NUM                  (9u)
#define key_touch_GLITCH_ELIMINATION_CYCLES_CALC         (key_touch_CSD_PRESCAN_SETTLING_TIME * CYDEV_BCLK__SYSCLK__MHZ)
#define key_touch_CMOD_DISCHARGE_TIME                    (2u)
#define key_touch_CMOD_DISCHARGE_CYCLES_CALC             (key_touch_CMOD_DISCHARGE_TIME * CYDEV_BCLK__SYSCLK__MHZ)

#if(key_touch_GLITCH_ELIMINATION_CYCLES_CALC >= key_touch_DELAY_EXTRACYCLES_NUM)
    #define key_touch_GLITCH_ELIMINATION_CYCLES          (key_touch_GLITCH_ELIMINATION_CYCLES_CALC -\
                                                                key_touch_DELAY_EXTRACYCLES_NUM)
#else
    #define key_touch_GLITCH_ELIMINATION_CYCLES          (key_touch_GLITCH_ELIMINATION_CYCLES_CALC)
#endif /* (key_touch_GLITCH_ELIMINATION_CYCLES_CALC >= key_touch_DELAY_EXTRACYCLES_NUM) */

#if(key_touch_CMOD_DISCHARGE_CYCLES_CALC >= key_touch_DELAY_EXTRACYCLES_NUM)
    #define key_touch_CMOD_DISCHARGE_CYCLES              (key_touch_CMOD_DISCHARGE_CYCLES_CALC -\
                                                                key_touch_DELAY_EXTRACYCLES_NUM)
#else
    #define key_touch_CMOD_DISCHARGE_CYCLES              (key_touch_CMOD_DISCHARGE_CYCLES_CALC)
#endif /* (key_touch_CMOD_DISCHARGE_CYCLES_CALC >= key_touch_DELAY_EXTRACYCLES_NUM) */

#define key_touch_PRECHARGE_IDAC_MOD_VAL                 (0xF0u)
#define key_touch_CSD_IDAC_PRECHARGE_CONFIG              (key_touch_IDAC_MOD_MODE_VARIABLE |\
                                                                 key_touch_IDAC_MOD_RANGE_MASK |\
                                                                 key_touch_IDAC_FEEDBACK_MODE_MASK |\
                                                                 key_touch_PRECHARGE_IDAC_MOD_VAL)

#define key_touch_CNT_RESOLUTION_12_BITS                 (0x0FFF0000Lu)
#define key_touch_ONE_CYCLE                              (0x00010000Lu)
#define key_touch_RESOLUTION_16_BITS                     (0xFFFF0000Lu)
#define key_touch_DISCONNECT_IO_FLAG                     (1u)
#define key_touch_PRESCALERS_TBL_SIZE                    (16u)

/* Calibration constants */
#define key_touch_CALIBRATION_LEVEL_85                   (85u)
#define key_touch_PERCENTAGE_100                         (0x00000064Lu)
#define key_touch_IDAC_MOD_MAX_CALIB_ERROR_NEG           (10u)
#define key_touch_IDAC_MOD_MAX_CALIB_ERROR_POS           (10u)
#define key_touch_IDAC_MOD_MAX_INT_MATH_SHIFT            (16u)
#define key_touch_IDAC_MOD_MAX_CALIB_ERROR_MULT          ((((key_touch_PERCENTAGE_100 + key_touch_IDAC_MOD_MAX_CALIB_ERROR_POS + 1u) \
                                                                 << key_touch_IDAC_MOD_MAX_INT_MATH_SHIFT) / key_touch_PERCENTAGE_100))
#define key_touch_IDAC_MOD_MIN_CALIB_ERROR_MULT          ((((key_touch_PERCENTAGE_100 - key_touch_IDAC_MOD_MAX_CALIB_ERROR_NEG - 1u) \
                                                                 << key_touch_IDAC_MOD_MAX_INT_MATH_SHIFT) / key_touch_PERCENTAGE_100))

#if (key_touch_ENABLE == key_touch_CSDV2)
    #define key_touch_CSD_IDAC_BITS_USED                 (7u)
#else
    #define key_touch_CSD_IDAC_BITS_USED                 (8u)
#endif /* (key_touch_ENABLE == key_touch_CSDV2) */
#define key_touch_CAL_MIDDLE_BIT                         (1uL << (key_touch_CSD_IDAC_BITS_USED - 1u))
#define key_touch_MAX_16_BITS_VALUE                      (0x0000FFFFLu)
#define key_touch_MAX_SCAN_TIME                          (key_touch_MAX_16_BITS_VALUE * key_touch_CSD_SCANSPEED_DIVIDER)
#define key_touch_CALIBR_WATCHDOG_CYCLES_NUM             (key_touch_MAX_SCAN_TIME / key_touch_AVG_CYCLES_PER_LOOP)

#if (key_touch_DISABLE == key_touch_CSD2X_EN)
    #if (key_touch_IDAC_GAIN_8X == key_touch_CSD_IDAC_GAIN)
        #define key_touch_CSD_IDAC_GAIN_VALUE_NA             (2400u)
    #elif (key_touch_IDAC_GAIN_HIGH == key_touch_CSD_IDAC_GAIN)
        #define key_touch_CSD_IDAC_GAIN_VALUE_NA             (2400u)
    #elif (key_touch_IDAC_GAIN_4X == key_touch_CSD_IDAC_GAIN)
        #define key_touch_CSD_IDAC_GAIN_VALUE_NA             (1200u)
    #elif (key_touch_IDAC_GAIN_MEDIUM == key_touch_CSD_IDAC_GAIN)
        #define key_touch_CSD_IDAC_GAIN_VALUE_NA             (300u)
    #else
        #define key_touch_CSD_IDAC_GAIN_VALUE_NA             (37u)
    #endif /* (key_touch_IDAC_GAIN_8X == key_touch_CSD_IDAC_GAIN) */
#endif /* (key_touch_DISABLE == key_touch_CSD2X_EN) */

#if (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN)
    #define key_touch_CSD_DUAL_IDAC_FACTOR               (2u)
#else
    #define key_touch_CSD_DUAL_IDAC_FACTOR               (1u)
#endif /* (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) */

#define key_touch_EMPTY_SLOT                          (255u)

/***************************************
* Global software/external variables
***************************************/
#if ((key_touch_ENABLE == key_touch_CSD_CSX_EN) || \
     (key_touch_ENABLE == key_touch_ADC_EN))
    extern key_touch_SENSE_METHOD_ENUM key_touch_currentSenseMethod;
#endif /* ((key_touch_ENABLE == key_touch_CSD_CSX_EN) || \
     (key_touch_ENABLE == key_touch_ADC_EN)) */

#if(key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
    extern uint8 key_touch_scanFreqIndex;
    extern uint8 key_touch_immunity[key_touch_NUM_SCAN_FREQS];
#else
    extern const uint8 key_touch_scanFreqIndex;
#endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */
#if (key_touch_ENABLE == key_touch_CSD2X_EN)
    extern volatile uint8 key_touch_widgetIndex0;
    extern volatile uint8 key_touch_sensorIndex0;
    extern volatile uint8 key_touch_widgetIndex1;
    extern volatile uint8 key_touch_sensorIndex1;
#else
    extern volatile uint8 key_touch_widgetIndex;
    extern volatile uint8 key_touch_sensorIndex;
#endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
extern uint8 key_touch_requestScanAllWidget;
#if (key_touch_ENABLE == key_touch_CSD2X_EN)
    extern key_touch_RAM_SNS_STRUCT *key_touch_curRamSnsPtr0;
    extern key_touch_RAM_SNS_STRUCT *key_touch_curRamSnsPtr1;
#else
    extern key_touch_RAM_SNS_STRUCT *key_touch_curRamSnsPtr;
#endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
#if ((key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) || \
     (key_touch_ENABLE == key_touch_CSX_EN))
    #if (key_touch_ENABLE == key_touch_CSD2X_EN)
         extern key_touch_FLASH_WD_STRUCT const *key_touch_curFlashWdgtPtr0;
         extern key_touch_FLASH_WD_STRUCT const *key_touch_curFlashWdgtPtr1;
    #else
         extern key_touch_FLASH_WD_STRUCT const *key_touch_curFlashWdgtPtr;
    #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
#endif /* ((key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) || \
           (key_touch_ENABLE == key_touch_CSX_EN))  */
#if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
    /*  Pointer to Flash structure holding info of sensor to be scanned  */
    #if (key_touch_ENABLE == key_touch_CSD2X_EN)
        extern key_touch_FLASH_SNS_STRUCT const *key_touch_curFlashSnsPtr0;
        extern key_touch_FLASH_SNS_STRUCT const *key_touch_curFlashSnsPtr1;
    #else
        extern key_touch_FLASH_SNS_STRUCT const *key_touch_curFlashSnsPtr;
    #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
#endif /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)  */
#if (key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE)
    extern uint8 key_touch_prescalersTuningDone;
    extern const uint8 key_touch_prescalerTable[key_touch_PRESCALERS_TBL_SIZE];
#endif /* (key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE) */
#if (key_touch_ENABLE == key_touch_CSD2X_EN)
    extern key_touch_FLASH_IO_STRUCT const *key_touch_curSnsIOPtr0;
    extern key_touch_FLASH_IO_STRUCT const *key_touch_curSnsIOPtr1;
#else
    extern key_touch_FLASH_IO_STRUCT const *key_touch_curSnsIOPtr;
#endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

#endif /* End CY_CAPSENSE_key_touch_SENSING_H */


/* [] END OF FILE */
