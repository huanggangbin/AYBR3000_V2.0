/***************************************************************************//**
* \file key_touch_INT.c
* \version 3.10
*
* \brief
*   This file contains the source code for implementation of the CapSense component
*   Interrupt Service Routine (ISR).
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
#include "cytypes.h"
#include "cyfitter.h"
#include "key_touch_Configuration.h"
#include "key_touch_Sensing.h"
#include "cyapicallbacks.h"

/*******************************************************************************
* Static Function Prototypes
*******************************************************************************/
/**
* \if SECTION_CAPSENSE_INTERNAL
* \addtogroup group_capsense_internal
* \{
*/

#if (((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD_CSX_EN)) && \
     (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN))
    static void key_touch_SsNextFrequencyScan(void);
#endif /* (((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD_CSX_EN)) && \
            (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)) */

#if ((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD_CSX_EN))
    CY_INLINE static void key_touch_SsCSDPostScan(void);
    CY_INLINE static void key_touch_SsCSDInitNextScan(void);
#endif /* ((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD_CSX_EN)) */ 

#if (key_touch_ENABLE == key_touch_CSD2X_EN)
    #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
        CY_INLINE static void key_touch_SsCSD2XCheckNextScan(void);
        static void key_touch_SsCSD2XNextFrequencyScan(void);
    #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */
    CY_INLINE static void key_touch_SsCSD2XInitNextScan(void);
#endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

   
/** \}
* \endif */


/**
* \if SECTION_CAPSENSE_INTERRUPT
* \addtogroup group_capsense_interrupt
* \{
*/


#if ((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD_CSX_EN))

#if (key_touch_ENABLE == key_touch_CSDV2)
    /*  CSDv2 HW IP block part */

    /*******************************************************************************
    * Function Name: key_touch_CSDPostSingleScan
    ****************************************************************************//**
    *
    * \brief
    *  This is an internal ISR function for single-sensor scanning implementation.
    *
    * \details
    *  This ISR handler is triggered when the user calls the
    *  key_touch_CSDScanExt() function.
    *
    *  The following tasks are performed for CSDv1 HW IP block:
    *    1. Disable the CSD interrupt
    *    2. Read the Counter register and update the data structure with raw data
    *    3. Connect the Vref buffer to the AMUX bus
    *    4. Update the Scan Counter
    *    5. Reset the BUSY flag
    *    6. Enable the CSD interrupt.
    *
    *  The following tasks are performed for CSDv2 HW IP block:
    *    1. Check if the raw data is not noisy
    *    2. Read the Counter register and update the data structure with raw data
    *    3. Configure and start the scan for the next frequency if the
    *      multi-frequency is enabled
    *    4. Update the Scan Counter
    *    5. Reset the BUSY flag
    *    6. Enable the CSD interrupt.
    *
    *  The ISR handler changes IMO and initializes scanning for the next frequency
    *  channels when multi-frequency scanning is enabled.
    *
	*  This function has two Macro Callbacks that allow calling the user code
    *  from macros specified in a component's generated code. Refer to the 
    *  \ref group_capsense_macrocallbacks section of PSoC Creator User Guide 
    *  for details. 
    *
    *******************************************************************************/
    CY_ISR(key_touch_CSDPostSingleScan)
    {
        #ifdef key_touch_ENTRY_CALLBACK
            key_touch_EntryCallback();
        #endif /* key_touch_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(key_touch_INTR_PTR, key_touch_INTR_SET_MASK);

    #if (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN)
        if ((key_touch_CSD_NOISE_METRIC_TH < ((CY_GET_REG32(key_touch_RESULT_VAL1_PTR) &
                                                    key_touch_RESULT_VAL1_BAD_CONVS_MASK) >>
                                                    key_touch_RESULT_VAL1_BAD_CONVS_SHIFT)) &&
                                                    (0u < key_touch_badConversionsNum))
        {
            /* Decrement bad conversions number */
            key_touch_badConversionsNum--;

            /* Start the re-scan */
            CY_SET_REG32(key_touch_SEQ_START_PTR, key_touch_SEQ_START_AZ0_SKIP_MASK |
                                                         key_touch_SEQ_START_AZ1_SKIP_MASK |
                                                         key_touch_SEQ_START_START_MASK);
        }
        else
        {
    #endif /* (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN) */

            key_touch_SsCSDPostScan();

            #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
                if (key_touch_FREQ_CHANNEL_2 > key_touch_scanFreqIndex)
                {
                    /* Scan the next channel */
                    key_touch_SsNextFrequencyScan();
                }
                else
                {
                    /* All channels are scanned. Set IMO to zero channel */
                    key_touch_scanFreqIndex = key_touch_FREQ_CHANNEL_0;
                    key_touch_SsChangeImoFreq(key_touch_FREQ_CHANNEL_0);

                    #if (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN)
                        /*  Disable CSDv2 block */
                        CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd);
                    #endif /* (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN) */

                    /* Update Scan Counter */
                    key_touch_dsRam.scanCounter++;

                    /* Sensor is totally scanned. Reset BUSY flag */
                    key_touch_dsRam.status &= ~(key_touch_SW_STS_BUSY | key_touch_WDGT_SW_STS_BUSY);
                }
            #else
                {
                    #if (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN)
                        /*  Disable CSDv2 block */
                        CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd);
                    #endif /* (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN) */

                    /* Update Scan Counter */
                    key_touch_dsRam.scanCounter++;

                    /* Sensor is totally scanned. Reset BUSY flag */
                    key_touch_dsRam.status &= ~(key_touch_SW_STS_BUSY | key_touch_WDGT_SW_STS_BUSY);
                }
            #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */
    #if (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN)
        }
    #endif /* (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN) */

        #ifdef key_touch_EXIT_CALLBACK
            key_touch_ExitCallback();
        #endif /* key_touch_EXIT_CALLBACK */
    }


    /*******************************************************************************
    * Function Name: key_touch_CSDPostMultiScan
    ****************************************************************************//**
    *
    * \brief
    *  This is an internal ISR function for multiple-sensor scanning 
    *  implementation.
    *
    * \details
    *  This ISR handler is triggered when the user calls the
    *  key_touch_Scan() or key_touch_ScanAllWidgets() APIs.
    *  
    *  The following tasks are performed:
    *    1. Disable the CSD interrupt
    *    2. Read the Counter register and update the data structure with raw data
    *    3. Connect the Vref buffer to the AMUX bus
    *    4. Disable the CSD block (after the widget has been scanned)
    *    5. Update Scan Counter
    *    6. Reset the BUSY flag
    *    7. Enable the CSD interrupt.
    *
    *  The ISR handler initializes scanning for the previous sensor when the 
    *  widget has more than one sensor.
    *  The ISR handler initializes scanning for the next widget when the
    *  key_touch_ScanAllWidgets() APIs are called and the project has
    *  more than one widget.
    *  The ISR handler changes the IMO and initializes scanning for the next
    *  frequency channels when multi-frequency scanning is enabled.
    *
    *  This function has two Macro Callbacks that allow calling the user 
    *  code from macros specified in a component's generated code. Refer to the 
    *  \ref group_capsense_macrocallbacks section of PSoC Creator User Guide 
    *  for details.
    *
    *******************************************************************************/
    CY_ISR(key_touch_CSDPostMultiScan)
    {
        /*  Declare and initialise ptr to sensor IO structure to appropriate address        */
        key_touch_FLASH_IO_STRUCT const *curSnsIOPtr = (key_touch_FLASH_IO_STRUCT const *)
                                                          key_touch_dsFlash.wdgtArray[key_touch_widgetIndex].ptr2SnsFlash
                                                          + key_touch_sensorIndex;

        #ifdef key_touch_ENTRY_CALLBACK
            key_touch_EntryCallback();
        #endif /* key_touch_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(key_touch_INTR_PTR, key_touch_INTR_SET_MASK);

        #if (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN)
            if ((key_touch_CSD_NOISE_METRIC_TH < ((CY_GET_REG32(key_touch_RESULT_VAL1_PTR) &
                                                      key_touch_RESULT_VAL1_BAD_CONVS_MASK) >>
                                                      key_touch_RESULT_VAL1_BAD_CONVS_SHIFT)) &&
                                                      (0u < key_touch_badConversionsNum))
            {
                /* Decrement bad conversions number */
                key_touch_badConversionsNum--;

                /* Start the re-scan */
                CY_SET_REG32(key_touch_SEQ_START_PTR, key_touch_SEQ_START_AZ0_SKIP_MASK |
                                                             key_touch_SEQ_START_AZ1_SKIP_MASK |
                                                             key_touch_SEQ_START_START_MASK);
            }
            else
            {
        #endif /* (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN) */

            key_touch_SsCSDPostScan();

            #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
                /* Disable sensor when all frequency channels are scanned */
                if (key_touch_FREQ_CHANNEL_2 == key_touch_scanFreqIndex)
                {
                    /* Disable sensor */
                    key_touch_CSDDisconnectSns(curSnsIOPtr);
                }
            #else
                /* Disable sensor */
                key_touch_CSDDisconnectSns(curSnsIOPtr);
            #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

            #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
                if (key_touch_FREQ_CHANNEL_2 > key_touch_scanFreqIndex)
                {
                     /* Scan the next channel */
                    key_touch_SsNextFrequencyScan();
                }
                else
                {
                     /* All channels are scanned. Set IMO to zero channel */
                    key_touch_scanFreqIndex = key_touch_FREQ_CHANNEL_0;
                    key_touch_SsChangeImoFreq(key_touch_FREQ_CHANNEL_0);

                     /* Scan the next sensor */
                    key_touch_SsCSDInitNextScan();
                }
            #else
                /* Scan the next sensor */
                key_touch_SsCSDInitNextScan();
            #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */
        #if (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN)
            }
        #endif /* (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN) */

        #ifdef key_touch_EXIT_CALLBACK
            key_touch_ExitCallback();
        #endif /* key_touch_EXIT_CALLBACK */
    }


    #if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
    /*******************************************************************************
    * Function Name: key_touch_CSDPostMultiScanGanged
    ****************************************************************************//**
    *
    * \brief
    *  This is an internal ISR function for multiple-sensor scanning 
    *  implementation for ganged sensors.
    *
    * \details
    *  This ISR handler is triggered when the user calls the
    *  key_touch_Scan() API for a ganged sensor or the
    *  key_touch_ScanAllWidgets() API in the project with ganged sensors.
    *
    *  The following tasks are performed:
    *    1. Disable the CSD interrupt
    *    2. Read the Counter register and update the data structure with raw data
    *    3. Connect the Vref buffer to the AMUX bus
    *    4. Disable the CSD block (after the widget has been scanned)
    *    5. Update Scan Counter
    *    6. Reset the BUSY flag
    *    7. Enable the CSD interrupt.
    *
    *  The ISR handler initializes scanning for the previous sensor when the
    *  widget has more than one sensor.
    *  The ISR handler initializes scanning for the next widget when the
    *  key_touch_ScanAllWidgets() APIs are called and the project has 
    *  more than one widget.
    *  The ISR handler changes the IMO and initializes scanning for the next 
    *  frequency channels when multi-frequency scanning is enabled.
    *
    *  This function has two Macro Callbacks that allow calling the user 
    *  code from macros specified in a component's generated code. Refer to the 
    *  \ref group_capsense_macrocallbacks section of PSoC Creator User Guide 
    *  for details.
    *
    *******************************************************************************/
    CY_ISR(key_touch_CSDPostMultiScanGanged)
    {
        #ifdef key_touch_ENTRY_CALLBACK
            key_touch_EntryCallback();
        #endif /* key_touch_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(key_touch_INTR_PTR, key_touch_INTR_SET_MASK);

        #if (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN)
            if ((key_touch_CSD_NOISE_METRIC_TH < ((CY_GET_REG32(key_touch_RESULT_VAL1_PTR) &
                                                      key_touch_RESULT_VAL1_BAD_CONVS_MASK) >>
                                                      key_touch_RESULT_VAL1_BAD_CONVS_SHIFT)) &&
                                                      (0u < key_touch_badConversionsNum))
            {
                /* Decrement bad conversions number */
                key_touch_badConversionsNum--;

                /* Start the re-scan */
                CY_SET_REG32(key_touch_SEQ_START_PTR, key_touch_SEQ_START_AZ0_SKIP_MASK |
                                                             key_touch_SEQ_START_AZ1_SKIP_MASK |
                                                             key_touch_SEQ_START_START_MASK);
            }
            else
            {
        #endif /* (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN) */

            key_touch_SsCSDPostScan();

            #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
                if (key_touch_FREQ_CHANNEL_2 == key_touch_scanFreqIndex)
                {
                    key_touch_SsCSDDisconnectSnsExt((uint32)key_touch_widgetIndex, (uint32)key_touch_sensorIndex);
                }
            #else
                key_touch_SsCSDDisconnectSnsExt((uint32)key_touch_widgetIndex, (uint32)key_touch_sensorIndex);
            #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

            #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
                if (key_touch_FREQ_CHANNEL_2 > key_touch_scanFreqIndex)
                {
                     /* Scan the next channel */
                    key_touch_SsNextFrequencyScan();
                }
                else
                {
                    /* All channels are scanned. Set IMO to zero channel */
                    key_touch_scanFreqIndex = key_touch_FREQ_CHANNEL_0;
                    key_touch_SsChangeImoFreq(key_touch_FREQ_CHANNEL_0);

                     /* Scan the next sensor */
                    key_touch_SsCSDInitNextScan();
                }
            #else
                 /* Scan the next sensor */
                key_touch_SsCSDInitNextScan();
            #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */
        #if (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN)
            }
        #endif /* (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN) */

        #ifdef key_touch_EXIT_CALLBACK
            key_touch_ExitCallback();
        #endif /* key_touch_EXIT_CALLBACK */
    }
    #endif /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) */

#else
    /* CSDv1 part */

    /*******************************************************************************
    * Function Name: key_touch_CSDPostSingleScan
    ****************************************************************************//**
    *
    * \brief
    *  This is an internal ISR function for single-sensor scanning implementation.
    *
    * \details
    *  This ISR handler is triggered when the user calls the
    *  key_touch_CSDScanExt() function.
    *
    *  The following tasks are performed for CSDv1 HW IP block:
    *    1. Disable the CSD interrupt
    *    2. Read the Counter register and update the data structure with raw data
    *    3. Connect the Vref buffer to the AMUX bus
    *    4. Update the Scan Counter
    *    5. Reset the BUSY flag
    *    6. Enable the CSD interrupt.
    *
    *  The following tasks are performed for CSDv2 HW IP block:
    *    1. Check if the raw data is not noisy
    *    2. Read the Counter register and update the data structure with raw data
    *    3. Configure and start the scan for the next frequency if the
    *      multi-frequency is enabled
    *    4. Update the Scan Counter
    *    5. Reset the BUSY flag
    *    6. Enable the CSD interrupt.
    *
    *  The ISR handler changes IMO and initializes scanning for the next frequency
    *  channels when multi-frequency scanning is enabled.
    *
	*  This function has two Macro Callbacks that allow calling the user code
    *  from macros specified in a component's generated code. Refer to the 
    *  \ref group_capsense_macrocallbacks section of PSoC Creator User Guide 
    *  for details. 
    *
    *******************************************************************************/
    CY_ISR(key_touch_CSDPostSingleScan)
    {
        #ifdef key_touch_ENTRY_CALLBACK
            key_touch_EntryCallback();
        #endif /* key_touch_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(key_touch_INTR_PTR, key_touch_INTR_SET_MASK);

        /* Read Rawdata */
        key_touch_SsCSDPostScan();

        #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
            if (key_touch_FREQ_CHANNEL_2 > key_touch_scanFreqIndex)
            {
                /*  Connect Vref Buffer to AMUX bus. CSDv1 block is enabled */
                CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd | key_touch_CTANK_PRECHARGE_CONFIG_CSD_EN);

                key_touch_SsNextFrequencyScan();
            }
            else
            {
                key_touch_scanFreqIndex = key_touch_FREQ_CHANNEL_0;
                key_touch_SsChangeImoFreq(key_touch_FREQ_CHANNEL_0);

                #if (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN)
                    /*  Disable CSDv1 block. Connect Vref Buffer to AMUX bus */
                    #if ((key_touch_CSH_PRECHARGE_IO_BUF == key_touch_CSD_CSH_PRECHARGE_SRC) &&\
                         (key_touch_ENABLE == key_touch_CSD_SHIELD_TANK_EN))
                        CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd | key_touch_CMOD_PRECHARGE_CONFIG);
                    #else
                        CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd | key_touch_CTANK_PRECHARGE_CONFIG);
                    #endif /* ((key_touch_CSH_PRECHARGE_IO_BUF == key_touch_CSD_CSH_PRECHARGE_SRC) &&\
                               (key_touch_ENABLE == key_touch_CSD_SHIELD_TANK_EN)) */
                #else
                    /*  Connect Vref Buffer to AMUX bus. CSDv1 block is enabled */
                    CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd | key_touch_CTANK_PRECHARGE_CONFIG_CSD_EN);
                #endif /* (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN) */

                /* Update Scan Counter */
                key_touch_dsRam.scanCounter++;

                /* Sensor is totally scanned. Reset BUSY flag */
                key_touch_dsRam.status &= ~(key_touch_SW_STS_BUSY | key_touch_WDGT_SW_STS_BUSY);
            }
        #else
            {
                #if (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN)
                    /*  Disable CSDv1 block. Connect Vref Buffer to AMUX bus */
                    #if ((key_touch_CSH_PRECHARGE_IO_BUF == key_touch_CSD_CSH_PRECHARGE_SRC) &&\
                         (key_touch_ENABLE == key_touch_CSD_SHIELD_TANK_EN))
                        CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd | key_touch_CMOD_PRECHARGE_CONFIG);
                    #else
                        CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd | key_touch_CTANK_PRECHARGE_CONFIG);
                    #endif /* ((key_touch_CSH_PRECHARGE_IO_BUF == key_touch_CSD_CSH_PRECHARGE_SRC) &&\
                               (key_touch_ENABLE == key_touch_CSD_SHIELD_TANK_EN)) */
                #else
                    /*  Connect Vref Buffer to AMUX bus. CSDv1 block is enabled */
                    CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd | key_touch_CTANK_PRECHARGE_CONFIG_CSD_EN);
                #endif /* (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN) */

                /* Update Scan Counter */
                key_touch_dsRam.scanCounter++;

                /* Sensor is totally scanned. Reset BUSY flag */
                key_touch_dsRam.status &= ~(key_touch_SW_STS_BUSY | key_touch_WDGT_SW_STS_BUSY);
            }
        #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

        #ifdef key_touch_EXIT_CALLBACK
            key_touch_ExitCallback();
        #endif /* key_touch_EXIT_CALLBACK */
    }


    /*******************************************************************************
    * Function Name: key_touch_CSDPostMultiScan
    ****************************************************************************//**
    *
    * \brief
    *  This is an internal ISR function for multiple-sensor scanning 
    *  implementation.
    *
    * \details
    *  This ISR handler is triggered when the user calls the
    *  key_touch_Scan() or key_touch_ScanAllWidgets() APIs.
    *  
    *  The following tasks are performed:
    *    1. Disable the CSD interrupt
    *    2. Read the Counter register and update the data structure with raw data
    *    3. Connect the Vref buffer to the AMUX bus
    *    4. Disable the CSD block (after the widget has been scanned)
    *    5. Update Scan Counter
    *    6. Reset the BUSY flag
    *    7. Enable the CSD interrupt.
    *
    *  The ISR handler initializes scanning for the previous sensor when the 
    *  widget has more than one sensor.
    *  The ISR handler initializes scanning for the next widget when the
    *  key_touch_ScanAllWidgets() APIs are called and the project has
    *  more than one widget.
    *  The ISR handler changes the IMO and initializes scanning for the next
    *  frequency channels when multi-frequency scanning is enabled.
    *
    *  This function has two Macro Callbacks that allow calling the user 
    *  code from macros specified in a component's generated code. Refer to the 
    *  \ref group_capsense_macrocallbacks section of PSoC Creator User Guide 
    *  for details.
    *
    *******************************************************************************/
    CY_ISR(key_touch_CSDPostMultiScan)
    {
        /*  Declare and initialise ptr to sensor IO structure to appropriate address        */
        key_touch_FLASH_IO_STRUCT const *curSnsIOPtr = (key_touch_FLASH_IO_STRUCT const *)
                                                          key_touch_dsFlash.wdgtArray[key_touch_widgetIndex].ptr2SnsFlash
                                                          + key_touch_sensorIndex;

        #ifdef key_touch_ENTRY_CALLBACK
            key_touch_EntryCallback();
        #endif /* key_touch_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(key_touch_INTR_PTR, key_touch_INTR_SET_MASK);

         /* Read Rawdata */
        key_touch_SsCSDPostScan();

        /*  Connect Vref Buffer to AMUX bus */
        CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd | key_touch_CTANK_PRECHARGE_CONFIG_CSD_EN);

        #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
            /* Disable sensor when all frequency channels are scanned */
            if (key_touch_FREQ_CHANNEL_2 == key_touch_scanFreqIndex)
            {
                /* Disable sensor */
                key_touch_CSDDisconnectSns(curSnsIOPtr);
            }
        #else
            /* Disable sensor */
            key_touch_CSDDisconnectSns(curSnsIOPtr);
        #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

        #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
            if (key_touch_FREQ_CHANNEL_2 > key_touch_scanFreqIndex)
            {
                 /* Scan the next channel */
                key_touch_SsNextFrequencyScan();
            }
            else
            {
                 /* All channels are scanned. Set IMO to zero channel */
                key_touch_scanFreqIndex = key_touch_FREQ_CHANNEL_0;
                key_touch_SsChangeImoFreq(key_touch_FREQ_CHANNEL_0);

                 /* Scan the next sensor */
                key_touch_SsCSDInitNextScan();
            }
        #else
            /* Scan the next sensor */
            key_touch_SsCSDInitNextScan();
        #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

        #ifdef key_touch_EXIT_CALLBACK
            key_touch_ExitCallback();
        #endif /* key_touch_EXIT_CALLBACK */
    }


    #if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
    /*******************************************************************************
    * Function Name: key_touch_CSDPostMultiScanGanged
    ****************************************************************************//**
    *
    * \brief
    *  This is an internal ISR function for multiple-sensor scanning 
    *  implementation for ganged sensors.
    *
    * \details
    *  This ISR handler is triggered when the user calls the
    *  key_touch_Scan() API for a ganged sensor or the
    *  key_touch_ScanAllWidgets() API in the project with ganged sensors.
    *
    *  The following tasks are performed:
    *    1. Disable the CSD interrupt
    *    2. Read the Counter register and update the data structure with raw data
    *    3. Connect the Vref buffer to the AMUX bus
    *    4. Disable the CSD block (after the widget has been scanned)
    *    5. Update Scan Counter
    *    6. Reset the BUSY flag
    *    7. Enable the CSD interrupt.
    *
    *  The ISR handler initializes scanning for the previous sensor when the
    *  widget has more than one sensor.
    *  The ISR handler initializes scanning for the next widget when the
    *  key_touch_ScanAllWidgets() APIs are called and the project has 
    *  more than one widget.
    *  The ISR handler changes the IMO and initializes scanning for the next 
    *  frequency channels when multi-frequency scanning is enabled.
    *
    *  This function has two Macro Callbacks that allow calling the user 
    *  code from macros specified in a component's generated code. Refer to the 
    *  \ref group_capsense_macrocallbacks section of PSoC Creator User Guide 
    *  for details.
    *
    *******************************************************************************/
    CY_ISR(key_touch_CSDPostMultiScanGanged)
    {
        #ifdef key_touch_ENTRY_CALLBACK
            key_touch_EntryCallback();
        #endif /* key_touch_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(key_touch_INTR_PTR, key_touch_INTR_SET_MASK);

         /* Read Rawdata */
        key_touch_SsCSDPostScan();

        /*  Connect Vref Buffer to AMUX bus */
        CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd | key_touch_CTANK_PRECHARGE_CONFIG_CSD_EN);

        #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
            if (key_touch_FREQ_CHANNEL_2 == key_touch_scanFreqIndex)
            {
                key_touch_SsCSDDisconnectSnsExt((uint32)key_touch_widgetIndex, (uint32)key_touch_sensorIndex);
            }
        #else
            key_touch_SsCSDDisconnectSnsExt((uint32)key_touch_widgetIndex, (uint32)key_touch_sensorIndex);
        #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

        #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
            if (key_touch_FREQ_CHANNEL_2 > key_touch_scanFreqIndex)
            {
                 /* Scan the next channel */
                key_touch_SsNextFrequencyScan();
            }
            else
            {
                /* All channels are scanned. Set IMO to zero channel */
                key_touch_scanFreqIndex = key_touch_FREQ_CHANNEL_0;
                key_touch_SsChangeImoFreq(key_touch_FREQ_CHANNEL_0);

                 /* Scan the next sensor */
                key_touch_SsCSDInitNextScan();
            }
        #else
             /* Scan the next sensor */
            key_touch_SsCSDInitNextScan();
        #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

        #ifdef key_touch_EXIT_CALLBACK
            key_touch_ExitCallback();
        #endif /* key_touch_EXIT_CALLBACK */
    }
    #endif /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) */

#endif /* (key_touch_ENABLE == key_touch_CSDV2) */

#endif /* ((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD_CSX_EN)) */

/** \}
 * \endif */


#if ((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD_CSX_EN))

/*******************************************************************************
* Function Name: key_touch_SsCSDPostScan
****************************************************************************//**
*
* \brief
*   This function reads rawdata and releases required HW resources after scan.
*
* \details
*   This function performs following tasks after scan:
*   - Reads SlotResult from Raw Counter;
*   - Inits bad Conversions number;
*   - Disconnects Vrefhi from AMUBUF positive input;
*   - Disconnects AMUBUF output from CSDBUSB with sych PHI2+HSCMP;
*   - Opens HCBV and HCBG switches.
*
*******************************************************************************/
CY_INLINE static void key_touch_SsCSDPostScan(void)
{
    #if (key_touch_ENABLE == key_touch_CSDV2)

        uint32 tmpRawData;
        uint32 tmpMaxCount;
        key_touch_RAM_WD_BASE_STRUCT const *ptrWdgt = (key_touch_RAM_WD_BASE_STRUCT *)
                                            key_touch_dsFlash.wdgtArray[key_touch_widgetIndex].ptr2WdgtRam;

        /* Read SlotResult from Raw Counter */
        tmpRawData = key_touch_RESULT_VAL1_VALUE_MASK & CY_GET_REG32(key_touch_COUNTER_PTR);

        tmpMaxCount = ((1uL << ptrWdgt->resolution) - 1uL);
        if(tmpRawData < tmpMaxCount)
        {
            key_touch_curRamSnsPtr->raw[key_touch_scanFreqIndex] = LO16(tmpRawData);
        }
        else
        {
            key_touch_curRamSnsPtr->raw[key_touch_scanFreqIndex] = LO16(tmpMaxCount);
        }

        #if (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN)
            /*  Init bad Conversions number */
            key_touch_badConversionsNum = key_touch_BAD_CONVERSIONS_NUM;
        #endif /* (key_touch_ENABLE == key_touch_CSD_NOISE_METRIC_EN) */

        #if ((key_touch_ENABLE == key_touch_CSD_SHIELD_EN) && \
             (key_touch_2000_MV <= key_touch_CYDEV_VDDA_MV))
            /*  Disconnect Vrefhi from AMUBUF positive input. Disconnect AMUBUF output from CSDBUSB with sych PHI2+HSCMP  */
            CY_SET_REG32(key_touch_SW_AMUXBUF_SEL_PTR, key_touch_SW_AMUXBUF_SEL_SW_DEFAULT);
        #endif /* ((key_touch_ENABLE == key_touch_CSD_SHIELD_EN) && \
                   (key_touch_2000_MV <= key_touch_CYDEV_VDDA_MV)) */

        #if (key_touch_ENABLE == key_touch_CSD_SHIELD_EN)
            /* Open HCBV and HCBG switches */
            CY_SET_REG32(key_touch_SW_SHIELD_SEL_PTR, key_touch_SW_SHIELD_SEL_SW_HCBV_STATIC_OPEN |
                                                             key_touch_SW_SHIELD_SEL_SW_HCBG_STATIC_OPEN);
        #endif /* (key_touch_ENABLE == key_touch_CSD_SHIELD_EN) */

    #else

        /* Read SlotResult from Raw Counter */
       key_touch_curRamSnsPtr->raw[key_touch_scanFreqIndex] = (uint16)CY_GET_REG32(key_touch_COUNTER_PTR);

    #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
}


/*******************************************************************************
* Function Name: key_touch_SsCSDInitNextScan
****************************************************************************//**
*
* \brief
*   This function initializes the next sensor scan.
*
* \details
*   The function decrements the sensor index, updates sense clock for matrix
*   or touchpad widgets only, sets up Compensation IDAC, enables the sensor and
*   scans it. When all sensors are scanned it continues to set up the next widget
*   until all widgets are scanned. The CSD block is disabled when all widgets are
*   scanned.
*
*******************************************************************************/
CY_INLINE static void key_touch_SsCSDInitNextScan(void)
{
    /*  Declare and initialise ptr to widget and sensor structures to appropriate address */
    #if (((key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) || \
             (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN))) || \
         (((key_touch_DISABLE == key_touch_CSD_COMMON_SNS_CLK_EN) && \
           (key_touch_ENABLE == key_touch_CSDV2) && \
          (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)))))
        key_touch_RAM_WD_BASE_STRUCT *ptrWdgt = (key_touch_RAM_WD_BASE_STRUCT *)
                                                        key_touch_dsFlash.wdgtArray[key_touch_widgetIndex].ptr2WdgtRam;
    #endif /* ((((key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) && \
               (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)))) || \
               (((key_touch_DISABLE == key_touch_CSD_COMMON_SNS_CLK_EN) && \
               (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN))) && \
               (key_touch_CLK_SOURCE_DIRECT == key_touch_CSD_SNS_CLK_SOURCE))) */

    /* Check if all sensors are scanned in widget */
    if (((uint8)key_touch_dsFlash.wdgtArray[(key_touch_widgetIndex)].totalNumSns - 1u) > key_touch_sensorIndex)
    {
        /*  Decrement snsIndex to configure next sensor in widget */
        key_touch_sensorIndex++;

        /*  Update global pointer to key_touch_RAM_SNS_STRUCT to current sensor  */
        key_touch_curRamSnsPtr = (key_touch_RAM_SNS_STRUCT *)
                                                  key_touch_dsFlash.wdgtArray[key_touch_widgetIndex].ptr2SnsRam
                                                  + key_touch_sensorIndex;

        /* Configure clock divider to row or column */
        #if ((key_touch_DISABLE == key_touch_CSD_COMMON_SNS_CLK_EN) && \
             (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)))
            if ((key_touch_WD_TOUCHPAD_E == (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[(key_touch_widgetIndex)].wdgtType) ||
                (key_touch_WD_MATRIX_BUTTON_E == (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[(key_touch_widgetIndex)].wdgtType))
            {
                key_touch_SsCSDConfigClock();

                #if (key_touch_ENABLE == key_touch_CSDV2)
                     /* Set up scanning resolution */
                    key_touch_SsCSDCalculateScanDuration(ptrWdgt);
                #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
            }
        #endif /* ((key_touch_DISABLE == key_touch_CSD_COMMON_SNS_CLK_EN) && \
                   (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)))) */

        /* Setup Compensation IDAC for next sensor in widget */
        #if ((key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) || \
             (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)))
            key_touch_SsCSDSetUpIdacs(ptrWdgt);
        #endif /* ((key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) || \
             (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)))*/

        /* Enable sensor */
        key_touch_SsCSDConnectSensorExt((uint32)key_touch_widgetIndex, (uint32)key_touch_sensorIndex);

        /* Proceed scanning */
        key_touch_SsCSDStartSample();
    }
    /*    Call scan next widget API if requested, if not, complete the scan  */
    else
    {
        key_touch_sensorIndex = 0u;

        /* Current widget is totally scanned. Reset WIDGET BUSY flag */
        key_touch_dsRam.status &= ~key_touch_WDGT_SW_STS_BUSY;

        /* Check if all widgets have been scanned */
        if (key_touch_ENABLE == key_touch_requestScanAllWidget)
        {
            /* Configure and begin scanning next widget */
            key_touch_SsPostAllWidgetsScan();
        }
        else
        {
            #if (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN)
                #if (key_touch_ENABLE == key_touch_CSDV2)
                    /*  Disable the CSD block */
                    CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd);
                #else
                    /*  Disable the CSD block. Connect Vref Buffer to AMUX bus */
                    #if ((key_touch_CSH_PRECHARGE_IO_BUF == key_touch_CSD_CSH_PRECHARGE_SRC) &&\
                         (key_touch_ENABLE == key_touch_CSD_SHIELD_TANK_EN))
                        CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd | key_touch_CMOD_PRECHARGE_CONFIG);
                    #else
                        CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd | key_touch_CTANK_PRECHARGE_CONFIG);
                    #endif /* ((key_touch_CSH_PRECHARGE_IO_BUF == key_touch_CSD_CSH_PRECHARGE_SRC) &&\
                               (key_touch_ENABLE == key_touch_CSD_SHIELD_TANK_EN)) */
                #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
            #endif /* (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN) */

            /* All widgets are totally scanned. Reset BUSY flag */
            key_touch_dsRam.status &= ~key_touch_SW_STS_BUSY;

            /* Update scan Counter */
            key_touch_dsRam.scanCounter++;
        }
    }
}

#if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
    /*******************************************************************************
    * Function Name: key_touch_SsNextFrequencyScan
    ****************************************************************************//**
    *
    * \brief
    *   This function scans the sensor on the next frequency channel.
    *
    * \details
    *   The function increments the frequency channel, changes IMO and initializes
    *   the scanning process of the same sensor.
    *
    *******************************************************************************/
    static void key_touch_SsNextFrequencyScan(void)
    {
        key_touch_RAM_WD_BASE_STRUCT const *ptrWdgt = (key_touch_RAM_WD_BASE_STRUCT *)
                                                        key_touch_dsFlash.wdgtArray[key_touch_widgetIndex].ptr2WdgtRam;

        key_touch_scanFreqIndex++;

        /* Set Immunity */
        key_touch_SsChangeImoFreq((uint32)key_touch_scanFreqIndex);

        /* Update IDAC registers */
        key_touch_SsCSDSetUpIdacs(ptrWdgt);

        /* Proceed scanning */
        key_touch_SsCSDStartSample();
    }
#endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

#endif /* ((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD_CSX_EN)) */


#if (key_touch_ENABLE == key_touch_CSD2X_EN)

    /*******************************************************************************
    * Function Name: key_touch_CSD0PostMultiScan
    ****************************************************************************//**
    *
    * \brief
    *   This is an internal ISR function for multiple-sensor scanning implementation
    *
    * \details
    *   This ISR handler is triggered when the user calls the
    *   key_touch_Scan() or key_touch_ScanAllWidgets() APIs.
    *   The following tasks are performed:
    *   - Clear pending interrupt
    *   - Read the Counter register and update the data structure with raw data
    *   - Connect the Vref buffer to the AMUX bus
    *   - Disable the CSD block (after the widget has been scanned)
    *   - Update Scan Counter
    *   - Reset the BUSY flag
    *
    *   The ISR handler changes the IMO and initializes scanning for the next frequency
    *   channels when multi-frequency scanning is enabled.
    *
    *   This function has two Macro Callbacks that allow to call user code from macros
    *   specified in a component's generated code. Refer to Macro Callbacks section
    *   of PSoC Creator User Guide for details.
    *
    *******************************************************************************/
    CY_ISR(key_touch_CSD0PostMultiScan)
    {
        #ifdef key_touch_ENTRY_CALLBACK
            key_touch_EntryCallback();
        #endif /* key_touch_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(key_touch_CSD0_INTR_PTR, key_touch_INTR_SET_MASK);
        CyIntClearPending(key_touch_ISR0_NUMBER);

        /* Read Rawdata */
        key_touch_curRamSnsPtr0->raw[key_touch_scanFreqIndex] = (uint16)CY_GET_REG32(key_touch_CSD0_COUNTER_PTR);

        /*  Connect Vref Buffer to AMUX bus */
        CY_SET_REG32(key_touch_CSD0_CONFIG_PTR, key_touch_configCsd0 | key_touch_CTANK0_PRECHARGE_CONFIG_CSD_EN);

        /* The sensor0 of current scan slot is scanned. Reset CSD0 BUSY flag */
        key_touch_dsRam.status &= ~key_touch_STATUS_CSD0_MASK;
        
        #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
            /* Scan the next channel or slot */
            key_touch_SsCSD2XCheckNextScan();
        #else
            /* Scan the next slot */
            key_touch_SsCSD2XInitNextScan();
        #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

        #ifdef key_touch_EXIT_CALLBACK
            key_touch_ExitCallback();
        #endif /* key_touch_EXIT_CALLBACK */
    }


    /*******************************************************************************
    * Function Name: key_touch_CSD1PostMultiScan
    ****************************************************************************//**
    *
    * \brief
    *   This is an internal ISR function for multiple-sensor scanning implementation
    *
    * \details
    *   This ISR handler is triggered when the user calls the
    *   key_touch_Scan() or key_touch_ScanAllWidgets() APIs.
    *   The following tasks are performed:
    *   - Clear pending interrupt
    *   - Read the Counter register and update the data structure with raw data
    *   - Connect the Vref buffer to the AMUX bus
    *   - Disable the CSD block (after the widget has been scanned)
    *   - Update Scan Counter
    *   - Reset the BUSY flag
    *
    *   The ISR handler changes the IMO and initializes scanning for the next frequency
    *   channels when multi-frequency scanning is enabled.
    *
    *   This function has two Macro Callbacks that allow to call user code from macros
    *   specified in a component's generated code. Refer to Macro Callbacks section
    *   of PSoC Creator User Guide for details.
    *
    *******************************************************************************/
    CY_ISR(key_touch_CSD1PostMultiScan)
    {
        #ifdef key_touch_ENTRY_CALLBACK
            key_touch_EntryCallback();
        #endif /* key_touch_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(key_touch_CSD1_INTR_PTR, key_touch_INTR_SET_MASK);
        CyIntClearPending(key_touch_ISR1_NUMBER);

        /* Read Rawdata */
        key_touch_curRamSnsPtr1->raw[key_touch_scanFreqIndex] = (uint16)CY_GET_REG32(key_touch_CSD1_COUNTER_PTR);

        /*  Connect Vref Buffer to AMUX bus */
        CY_SET_REG32(key_touch_CSD1_CONFIG_PTR, key_touch_configCsd1 | key_touch_CTANK1_PRECHARGE_CONFIG_CSD_EN);

        /* The sensor0 of current scan slot is scanned. Reset CSD1 BUSY flag */
        key_touch_dsRam.status &= ~key_touch_STATUS_CSD1_MASK;
        
        #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
            /* Scan the next channel or slot */
            key_touch_SsCSD2XCheckNextScan();
        #else
            /* Scan the next slot */
            key_touch_SsCSD2XInitNextScan();
        #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

        #ifdef key_touch_EXIT_CALLBACK
            key_touch_ExitCallback();
        #endif /* key_touch_EXIT_CALLBACK */
    }


    #if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
        /*******************************************************************************
        * Function Name: key_touch_CSD0PostMultiScanGanged
        ****************************************************************************//**
        *
        * \brief
        *   This is an internal ISR function for multiple-sensor scanning implementation
        *
        * \details
        *   This ISR handler is triggered when the user calls the
        *   key_touch_Scan() or key_touch_ScanAllWidgets() APIs.
        *   The following tasks are performed:
        *   - Clear pending interrupt
        *   - Read the Counter register and update the data structure with raw data
        *   - Connect the Vref buffer to the AMUX bus
        *   - Disable the CSD block (after the widget has been scanned)
        *   - Update Scan Counter
        *   - Reset the BUSY flag
        *
        *   The ISR handler changes the IMO and initializes scanning for the next frequency
        *   channels when multi-frequency scanning is enabled.
        *
        *   This function has two Macro Callbacks that allow to call user code from macros
        *   specified in a component's generated code. Refer to Macro Callbacks section
        *   of PSoC Creator User Guide for details.
        *
        *******************************************************************************/
        CY_ISR(key_touch_CSD0PostMultiScanGanged)
        {
            #ifdef key_touch_ENTRY_CALLBACK
                key_touch_EntryCallback();
            #endif /* key_touch_ENTRY_CALLBACK */

            /* Clear pending interrupt */
            CY_SET_REG32(key_touch_CSD0_INTR_PTR, key_touch_INTR_SET_MASK);
            CyIntClearPending(key_touch_ISR0_NUMBER);

            /* Read Rawdata */
            key_touch_curRamSnsPtr0->raw[key_touch_scanFreqIndex] = (uint16)CY_GET_REG32(key_touch_CSD0_COUNTER_PTR);

            /*  Connect Vref Buffer to AMUX bus */
            CY_SET_REG32(key_touch_CSD0_CONFIG_PTR, key_touch_configCsd0 | key_touch_CTANK0_PRECHARGE_CONFIG_CSD_EN);

            /* The sensor0 of current scan slot is scanned. Reset CSD0 BUSY flag */
            key_touch_dsRam.status &= ~key_touch_STATUS_CSD0_MASK;
            
            #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
                /* Scan the next channel or slot */
                key_touch_SsCSD2XCheckNextScan();
            #else
                /* Scan the next slot */
                key_touch_SsCSD2XInitNextScan();
            #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

            #ifdef key_touch_EXIT_CALLBACK
                key_touch_ExitCallback();
            #endif /* key_touch_EXIT_CALLBACK */
        }


        /*******************************************************************************
        * Function Name: key_touch_CSD1PostMultiScanGanged
        ****************************************************************************//**
        *
        * \brief
        *   This is an internal ISR function for multiple-sensor scanning implementation
        *
        * \details
        *   This ISR handler is triggered when the user calls the
        *   key_touch_Scan() or key_touch_ScanAllWidgets() APIs.
        *   The following tasks are performed:
        *   - Clear pending interrupt
        *   - Read the Counter register and update the data structure with raw data
        *   - Connect the Vref buffer to the AMUX bus
        *   - Disable the CSD block (after the widget has been scanned)
        *   - Update Scan Counter
        *   - Reset the BUSY flag
        *
        *   The ISR handler changes the IMO and initializes scanning for the next frequency
        *   channels when multi-frequency scanning is enabled.
        *
        *   This function has two Macro Callbacks that allow to call user code from macros
        *   specified in a component's generated code. Refer to Macro Callbacks section
        *   of PSoC Creator User Guide for details.
        *
        *******************************************************************************/
        CY_ISR(key_touch_CSD1PostMultiScanGanged)
        {
            #ifdef key_touch_ENTRY_CALLBACK
                key_touch_EntryCallback();
            #endif /* key_touch_ENTRY_CALLBACK */

            /* Clear pending interrupt */
            CY_SET_REG32(key_touch_CSD1_INTR_PTR, key_touch_INTR_SET_MASK);
            CyIntClearPending(key_touch_ISR1_NUMBER);

            /* Read Rawdata */
            key_touch_curRamSnsPtr1->raw[key_touch_scanFreqIndex] = (uint16)CY_GET_REG32(key_touch_CSD1_COUNTER_PTR);

            /*  Connect Vref Buffer to AMUX bus */
            CY_SET_REG32(key_touch_CSD1_CONFIG_PTR, key_touch_configCsd1 | key_touch_CTANK1_PRECHARGE_CONFIG_CSD_EN);

            /* The sensor0 of current scan slot is scanned. Reset CSD1 BUSY flag */
            key_touch_dsRam.status &= ~key_touch_STATUS_CSD1_MASK;
            
            #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
                /* Scan the next channel or slot */
                key_touch_SsCSD2XCheckNextScan();
            #else
                /* Scan the next slot */
                key_touch_SsCSD2XInitNextScan();
            #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

            #ifdef key_touch_EXIT_CALLBACK
                key_touch_ExitCallback();
            #endif /* key_touch_EXIT_CALLBACK */
        }
    #endif /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) */


    /*******************************************************************************
    * Function Name: key_touch_SsCSD2XInitNextScan
    ****************************************************************************//**
    *
    * \brief
    *   This function initializes the next slot scan.
    *
    * \details
    *   The function checks if all slots scan is requested and configures the 
    *   next slot. If the all slots are scanned the function disables the CSD block 
    *   updates the scan Counter and resets the BUSY flag.
    * 
    *******************************************************************************/
    CY_INLINE static void key_touch_SsCSD2XInitNextScan(void)
    {
        if (0u == (key_touch_dsRam.status & (key_touch_STATUS_CSD0_MASK | key_touch_STATUS_CSD1_MASK)))
        {
            #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
                 /* All channels are scanned. Set IMO to zero channel */
                key_touch_scanFreqIndex = key_touch_FREQ_CHANNEL_0;
                key_touch_SsChangeImoFreq(key_touch_FREQ_CHANNEL_0);
            #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

            /* Check if all slots have been scanned */
            if (key_touch_ENABLE == key_touch_requestScanAllWidget)
            {
                /* Current slot is scanned. Reset WIDGET BUSY flag */
                key_touch_dsRam.status &= ~key_touch_WDGT_SW_STS_BUSY;
                
                /* Configure and begin scanning next slot */
                key_touch_SsPostAllWidgetsScan();  
            }
            else
            {
                #if (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN)
                    /*  Disable the CSD blocks. Connect Vref Buffer to AMUX bus */
                    CY_SET_REG32(key_touch_CSD0_CONFIG_PTR, key_touch_configCsd0 | key_touch_CTANK0_PRECHARGE_CONFIG);
                    CY_SET_REG32(key_touch_CSD1_CONFIG_PTR, key_touch_configCsd1 | key_touch_CTANK1_PRECHARGE_CONFIG);
                #endif /* (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN) */

                /* All widgets are totally scanned. Reset BUSY flag */
                key_touch_dsRam.status &= ~(key_touch_SW_STS_BUSY | key_touch_WDGT_SW_STS_BUSY);
                
                /* Update scan Counter */
                key_touch_dsRam.scanCounter++;
            }
        }
    }


    #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
        /*******************************************************************************
        * Function Name: key_touch_SsCSD2XCheckNextScan
        ****************************************************************************//**
        *
        * \brief
        *   This function initializes the next channel or slot scan.
        *
        * \details
        *   The function checks if all channels are scanned and initializes the next 
        *   slot scan.
        * 
        *******************************************************************************/
        CY_INLINE static void key_touch_SsCSD2XCheckNextScan(void)
        {
            if (key_touch_FREQ_CHANNEL_2 > key_touch_scanFreqIndex)
            {
                 /* Scan the next channel */
                key_touch_SsCSD2XNextFrequencyScan();
            }
            else
            {
                 /* Scan the slot sensor */
                key_touch_SsCSD2XInitNextScan();   
            } 
        }


        /*******************************************************************************
        * Function Name: key_touch_SsCSD2XNextFrequencyScan
        ****************************************************************************//**
        *
        * \brief
        *   This function scans the sensor on the next frequency channel.
        *
        * \details
        *   The function increments the frequency channel, changes IMO and initializes 
        *   the scanning process of the same sensor.
        * 
        *******************************************************************************/
        static void key_touch_SsCSD2XNextFrequencyScan(void)
        {
            if (0u == (key_touch_dsRam.status & (key_touch_STATUS_CSD0_MASK | key_touch_STATUS_CSD1_MASK)))
            {        
                key_touch_scanFreqIndex++;
                
                /* Set Immunity */
                key_touch_SsChangeImoFreq((uint32)key_touch_scanFreqIndex);
                
                /* Proceed scanning */
                key_touch_SsCSD2XStartSample();
            }  
        }
    #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */    
#endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */


/* [] END OF FILE */
