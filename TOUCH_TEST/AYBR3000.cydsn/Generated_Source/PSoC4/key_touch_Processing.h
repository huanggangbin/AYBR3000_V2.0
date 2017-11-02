/***************************************************************************//**
* \file key_touch_Processing.h
* \version 3.10
*
* \brief
* This file provides the function prototypes for the Data Processing module.
* The Data Processing module is responsible for the low level raw counts
* processing provided by the sensing module, maintaining baseline and 
* difference values and performing high-level widget processing like updating
* button status or calculating slider position.
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

#if !defined(CY_CAPSENSE_key_touch_DATA_PROCESS_H)
#define CY_CAPSENSE_key_touch_DATA_PROCESS_H

#include "key_touch_Configuration.h"
#include "key_touch_Structure.h"

#if (0 != (key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN))
    #include "key_touch_SmartSense_LL.h"
#endif /* (0 != (key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN)) */
    
/*******************************************************************************
* Definitions
*******************************************************************************/
    
/* Define the data processing tasks */
   
/* Applies all enabled filters in the default order to the raw counts */
#define key_touch_PROCESS_FILTER             (0x01Lu)
    
/* Updates baselines using current raw count values for the widget/sensor */
#define key_touch_PROCESS_BASELINE           (0x02Lu)
    
/* Calculates differences for the widget/sensor */
#define key_touch_PROCESS_DIFFCOUNTS         (0x04Lu)
    
/* Runs the noise envelope filter to measure noise magnitude for the widget/sensor */
#define key_touch_PROCESS_CALC_NOISE         (0x08Lu)
    
/* Updates widget thresholds based on raw counts noise magnitude */
#define key_touch_PROCESS_THRESHOLDS         (0x10Lu)
    
/* Runs the widget-specific processing algorithms and updates it status */
#define key_touch_PROCESS_STATUS             (0x20Lu)
    
/* Runs the deconvolution algorithm for the widgets with the multiphase TX scanning */
#define key_touch_PROCESS_DECONVOLUTION      (0x40Lu)
    
/* Definition that combines all possible processing tasks */
#define key_touch_PROCESS_ALL    (key_touch_PROCESS_FILTER        | \
                                         key_touch_PROCESS_BASELINE      | \
                                         key_touch_PROCESS_DIFFCOUNTS    | \
                                         key_touch_PROCESS_CALC_NOISE    | \
                                         key_touch_PROCESS_THRESHOLDS    | \
                                         key_touch_PROCESS_DECONVOLUTION | \
                                         key_touch_PROCESS_STATUS )
        
/*******************************************************************************
* Function Prototypes 
*******************************************************************************/

/*******************************************************************************
* Function Prototypes - internal functions.
*******************************************************************************/
/**
* \if SECTION_CAPSENSE_INTERNAL
* \addtogroup group_capsense_internal
* \{
*/

void key_touch_DpInitialize(void);

#if ((0u != key_touch_BUTTON_WIDGET_EN) || (0u != key_touch_CSX_MATRIX_WIDGET_EN))
    uint32 key_touch_DpProcessButton(uint32 currStatus, key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if ((0u != key_touch_BUTTON_WIDGET_EN) || (0u != key_touch_CSX_MATRIX_WIDGET_EN)) */

#if (0u != key_touch_CSX_TOUCHPAD_WIDGET_EN)
    uint32 key_touch_DpProcessCsxTouchpad(
                uint32 currStatus, key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != key_touch_CSX_TOUCHPAD_WIDGET_EN) */

#if (0u != key_touch_PROXIMITY_WIDGET_EN)
    uint32 key_touch_DpProcessProximity(uint32 currStatus, key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != key_touch_PROXIMITY_WIDGET_EN) */

#if (0u != key_touch_SLIDER_WIDGET_EN)
    uint32 key_touch_DpProcessSlider(uint32 currStatus, key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != key_touch_SLIDER_WIDGET_EN) */

#if (0u != key_touch_CSD_MATRIX_WIDGET_EN)
    uint32 key_touch_DpProcessCsdMatrix(uint32 currStatus, key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != key_touch_CSD_MATRIX_WIDGET_EN) */

#if (0u != key_touch_CSD_TOUCHPAD_WIDGET_EN)
    uint32 key_touch_DpProcessCsdTouchpad(
                uint32 currStatus, key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != key_touch_CSD_TOUCHPAD_WIDGET_EN) */

#if (0u != key_touch_TOTAL_CSD_WIDGETS)
    uint32 key_touch_DpProcessCsdWidgetRawCounts(
                    key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt);
    
    uint32 key_touch_DpProcessCsdSensorRawCountsExt(
                    key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt, 
                    key_touch_RAM_SNS_STRUCT *ptrSns,
                    key_touch_PTR_FILTER_VARIANT fltrHistV, 
                     uint32 mode);
    
    void key_touch_DpProcessCsdWidgetStatus(uint32 wdgtId, key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != key_touch_TOTAL_CSD_WIDGETS) */

#if (0u != key_touch_TOTAL_CSX_WIDGETS)
    uint32 key_touch_DpProcessCsxWidgetRawCounts(
            key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt);

    uint32 key_touch_DpProcessCsxSensorRawCountsExt(
                    key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt, 
                    key_touch_RAM_SNS_STRUCT *ptrSns,
                    key_touch_PTR_FILTER_VARIANT fltrHistV, 
                     uint32 mode);
    
    void key_touch_DpProcessCsxWidgetStatus(
                uint32 wdgtId, key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != key_touch_TOTAL_CSX_WIDGETS) */

void key_touch_DpUpdateDifferences(
        key_touch_RAM_WD_BASE_STRUCT  *ptrRamWdgt, key_touch_RAM_SNS_STRUCT *ptrSns);

#if (0u != (key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN))
    void key_touch_DpUpdateThresholds(
                    key_touch_RAM_WD_BASE_STRUCT *ptrRamWdgt,
                    SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope,
                    uint32 startFlag);
#endif /* #if (0u != (key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN)) */

#if (0u != key_touch_CSX_MULTIPHASE_TX_EN)
    void key_touch_DpDeconvolution(key_touch_FLASH_WD_STRUCT const *ptrFlashWdgt);
#endif /* #if (0u != key_touch_CSX_MULTIPHASE_TX_EN) */


/** \}
* \endif */

#endif /* End CY_CAPSENSE_key_touch_DATA_PROCESS_H */


/* [] END OF FILE */
