/***************************************************************************//**
* \file key_touch_SensingCSD_LL.h
* \version 3.10
*
* \brief
*   This file provides the headers of APIs specific to CSD sensing implementation.
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

#if !defined(CY_CAPSENSE_key_touch_SENSINGCSD_LL_H)
#define CY_CAPSENSE_key_touch_SENSINGCSD_LL_H

#include <CyLib.h>
#include <cyfitter.h>
#include "cytypes.h"
#include "key_touch_Structure.h"
#include "key_touch_Configuration.h"

/***************************************
* Function Prototypes
**************************************/

/**
* \if SECTION_CAPSENSE_LOW_LEVEL
* \addtogroup group_capsense_low_level
* \{
*/

void key_touch_CSDSetupWidget(uint32 wdgtIndex);
void key_touch_CSDSetupWidgetExt(uint32 wdgtIndex, uint32 snsIndex);
void key_touch_CSDScan(void);
void key_touch_CSDScanExt(void);
#if ((key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE) || \
     (key_touch_ENABLE == key_touch_CSD_IDAC_AUTOCAL_EN))
    cystatus key_touch_CSDCalibrateWidget(uint32 wdgtIndex, uint32 target);
#endif /* ((key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE) || \
           (key_touch_ENABLE == key_touch_CSD_IDAC_AUTOCAL_EN))  */
void key_touch_CSDConnectSns(key_touch_FLASH_IO_STRUCT const *snsAddrPtr);
void key_touch_CSDDisconnectSns(key_touch_FLASH_IO_STRUCT const *snsAddrPtr);

/** \}
* \endif */

/*****************************************************
* Function Prototypes - internal Low Level functions
*****************************************************/
/**
* \if SECTION_CAPSENSE_INTERNAL
* \addtogroup group_capsense_internal
* \{
*/

void key_touch_SsCSDInitialize(void);
void key_touch_SsCSDStartSample(void);
void key_touch_SsCSDSetUpIdacs(key_touch_RAM_WD_BASE_STRUCT const *ptrWdgt);
void key_touch_SsCSDConfigClock(void);
void key_touch_SsCSDElectrodeCheck(void);
#if ((key_touch_ENABLE == key_touch_CSD_SHIELD_EN) && \
     (0u != key_touch_CSD_TOTAL_SHIELD_COUNT))
    void key_touch_SsCSDDisableShieldElectrodes(void);
#endif /* ((key_touch_ENABLE == key_touch_CSD_SHIELD_EN) && \
           (0u != key_touch_CSD_TOTAL_SHIELD_COUNT)) */
#if (key_touch_ENABLE == key_touch_CSDV2)
    uint32 key_touch_SsCSDGetNumberOfConversions(uint32 snsClkDivider, uint32 resolution, uint32 snsClkSrc);
#endif /* (key_touch_ENABLE == key_touch_CSDV2) */
void key_touch_SsCSDCalculateScanDuration(key_touch_RAM_WD_BASE_STRUCT const *ptrWdgt);
void key_touch_SsCSDConnectSensorExt(uint32 wdgtIndex, uint32 sensorIndex);
void key_touch_SsCSDDisconnectSnsExt(uint32 wdgtIndex, uint32 sensorIndex);
void key_touch_SsCSDSetModeSnsClockDivider(uint32 snsClkSource, uint32 snsClkDivider);

#if ((key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE) || \
     (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
     (key_touch_ENABLE == key_touch_CSD_IDAC_AUTOCAL_EN))
    #if (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN)
        void key_touch_SsCSDSetSingleIdacMode(void);
    #endif /* (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) */
#endif /* ((key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE) || \
           (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
           (key_touch_ENABLE == key_touch_CSD_IDAC_AUTOCAL_EN)) */

/** \}
* \endif */

/***************************************
* Global software variables
***************************************/
extern uint32 key_touch_configCsd;
/* Interrupt handler */
extern CY_ISR_PROTO(key_touch_CSDPostSingleScan);
extern CY_ISR_PROTO(key_touch_CSDPostMultiScan);
#if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
extern CY_ISR_PROTO(key_touch_CSDPostMultiScanGanged);
#endif /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) */
#if (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN)
    extern uint8 key_touch_badConversionsNum;
#endif /* (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN) */

#endif /* End CY_CAPSENSE_key_touch_SENSINGCSD_LL_H */


/* [] END OF FILE */
