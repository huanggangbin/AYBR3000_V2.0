/***************************************************************************//**
* \file     key_touch_Filter.c
* \version  3.10
*
* \brief    This file contains the implementation source code to implement all 
*           firmware filters.
*
* \see      CapSense P4 v3.10 Datasheet
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

#include "key_touch_Filter.h"
#include "key_touch_Configuration.h"

#if (0 != (key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN))
    #include "key_touch_SmartSense_LL.h"
#endif /* (0 != (key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN)) */

#if (key_touch_ENABLE == key_touch_SELF_TEST_EN)
    #include "key_touch_SelfTest.h"
#endif

/*******************************************************************************
* Function Name: key_touch_FtInitialize
****************************************************************************//**
*
* \brief
*    Initializes all the firmware filter history, except the baseline filter.
*
* \details
*    Initializes all the firmware filter history, except the baseline filter.
*
*******************************************************************************/
void key_touch_FtInitialize(void)
{
    uint32 widgetId;
    uint32 sensorId;
    uint32 sensorsNumber;

    key_touch_FLASH_WD_STRUCT const *ptrWidget;
    key_touch_RAM_SNS_STRUCT *ptrSensor = NULL;
    key_touch_PTR_FILTER_VARIANT ptrFilterHistObj;
    
    #if key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN
        key_touch_RAM_WD_BASE_STRUCT *ptrWidgetRam;
        SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope = NULL;
    #endif /* #if key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN */
    
    for (widgetId = key_touch_TOTAL_WIDGETS; widgetId-- > 0u;)
    {
        ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];
        
        #if key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN
            ptrWidgetRam = ptrWidget->ptr2WdgtRam;
        #endif /* #if key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN */

        /* Find total amount of sensors in specified widget */   
        sensorsNumber = key_touch_GET_SNS_CNT_BY_PTR(ptrWidget);    
    
        for (sensorId = sensorsNumber; sensorId-- > 0u;) 
        {
            /* Find pointer to specified sensor object */
            ptrSensor = ptrWidget->ptr2SnsRam;
            ptrSensor = &ptrSensor[sensorId];
                        
            /* Find pointer to to specified filter sensor object */
            ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;

            #if key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN
                /* Find pointer to specified noise envelope sensor object */
                ptrNoiseEnvelope = ptrWidget->ptr2NoiseEnvlp;
                ptrNoiseEnvelope = &ptrNoiseEnvelope[sensorId];    
            #endif /* #if key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN */
            
            if ((key_touch_WD_TYPE_ENUM)ptrWidget->wdgtType != key_touch_WD_PROXIMITY_E)
            {
                #if (key_touch_REGULAR_SENSOR_EN)             
                    ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
                #endif /* (key_touch_REGULAR_SENSOR_EN) */
            }
            else
            {
                #if (key_touch_PROXIMITY_SENSOR_EN)             
                    ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
                #endif /* (key_touch_PROXIMITY_SENSOR_EN) */
            }
            
            #if (key_touch_REGULAR_RC_IIR_FILTER_EN || key_touch_PROX_RC_IIR_FILTER_EN)
                key_touch_InitializeIIRInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
            #endif /* (key_touch_REGULAR_RC_IIR_FILTER_EN || key_touch_PROX_RC_IIR_FILTER_EN) */                

            #if (key_touch_REGULAR_RC_MEDIAN_FILTER_EN || key_touch_PROX_RC_MEDIAN_FILTER_EN)
                key_touch_InitializeMedianInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
            #endif /* (key_touch_REGULAR_RC_MEDIAN_FILTER_EN || key_touch_PROX_RC_MEDIAN_FILTER_EN) */

            #if (key_touch_REGULAR_RC_AVERAGE_FILTER_EN || key_touch_PROX_RC_AVERAGE_FILTER_EN)
                key_touch_InitializeAverageInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
            #endif /* (key_touch_REGULAR_RC_AVERAGE_FILTER_EN || key_touch_PROX_RC_AVERAGE_FILTER_EN) */
            
            #if (key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN)
                if (key_touch_SENSE_METHOD_CSD_E ==
                    key_touch_GET_SENSE_METHOD(&key_touch_dsFlash.wdgtArray[widgetId]))
                {
                    SmartSense_InitializeNoiseEnvelope(ptrSensor->raw[0u], ptrWidgetRam->sigPFC, ptrNoiseEnvelope);
                }
            #endif /* #if key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN */
        }
    }   
}


/*******************************************************************************
* Function Name: key_touch_UpdateAllBaselines
****************************************************************************//**
*
* \brief    
*  Updates the baseline for all sensors in all widgets.
*
* \details
*  Updates the baseline for all sensors in all widgets. Baseline updating is a 
*  part of data processing performed by the process functions. So, no need to 
*  call this function except a specific process flow is implemented.
*  
*  This function ignores the value of the wdgtEnable register. Multiple calling 
*  of this function (or any other function with a baseline updating task) 
*  without scanning leads to unexpected behavior.
*
*  If Self-test library is enabled this function executes baseline duplication
*  test. Refer to key_touch_CheckBaselineDuplication() for details.
*
* \return   
*  Returns the status of the update baseline operation of all widgets:
*  - CYRET_SUCCESS if operation was successfully completed
*  - CYRET_BAD_DATA if baseline processing failed
*
*******************************************************************************/
cystatus key_touch_UpdateAllBaselines(void)
{
    uint32 widgetId; 
    cystatus bslnStatus = CYRET_SUCCESS;
    
    for(widgetId = key_touch_TOTAL_WIDGETS; widgetId-- > 0u;)
    {            
        bslnStatus |= key_touch_UpdateWidgetBaseline(widgetId);       
    }      
    
    return(bslnStatus);
}
  

/*******************************************************************************
* Function Name: key_touch_UpdateWidgetBaseline
****************************************************************************//**
*
* \brief    
*  Updates the baseline for all sensors in a widget specified by input parameter.
*
* \details  
*  This function performs exactly the same tasks as 
*  key_touch_UpdateAllBaselines(), but only for a specified widget.
*  
*  This function ignores the value of the wdgtEnable register. Multiple calling
*  of this function (or any other function with a baseline updating task) 
*  without scanning leads to unexpected behavior.
*
*  If Self-test library is enabled this function executes baseline duplication
*  test. Refer to key_touch_CheckBaselineDuplication() for details.
*
* \param widgetId 
*  Specify the ID number of the widget to update the baseline of all sensors
*  in the widget.
*  A macro for the widget ID can be found in the 
*  key_touch Configuration header file defined as 
*  key_touch_<WidgetName>_WDGT_ID.
*
* \return   
*  Returns the status of the specified widget update baseline operation:
*  - CYRET_SUCCESS if operation was successfully completed
*  - CYRET_BAD_DATA if baseline processing failed
*
*******************************************************************************/
cystatus key_touch_UpdateWidgetBaseline(uint32 widgetId)
{
    uint32 sensorId;       
    uint32 sensorsNumber;  

    key_touch_FLASH_WD_STRUCT const *ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];    
    cystatus bslnStatus = CYRET_SUCCESS;    
    
    /* Find total amount of sensors in specified widget */   
    sensorsNumber = key_touch_GET_SNS_CNT_BY_PTR(ptrWidget);    
    
    for(sensorId = sensorsNumber; sensorId-- > 0u;)
    {
        bslnStatus |= key_touch_UpdateSensorBaseline(widgetId, sensorId);    
    }

    return(bslnStatus);
}


/*******************************************************************************
* Function Name: key_touch_UpdateSensorBaseline
****************************************************************************//**
*
* \brief    
*  Updates the baseline for a sensor in a widget specified by input parameters.
*
* \details  
*  This function performs exactly the same tasks as
*  key_touch_UpdateAllBaselines() and 
*  key_touch_UpdateWidgetBaseline() but only for a specified sensor.
*  
*  This function ignores the value of the wdgtEnable register. Multiple calling 
*  of this function (or any other function with a baseline updating task) 
*  without scanning leads to unexpected behavior.
*
*  If Self-test library is enabled this function executes baseline duplication
*  test. Refer to key_touch_CheckBaselineDuplication() for details.
*
* \param   widgetId 
*  Specify the ID number of the widget to update the baseline of the sensor 
*  specified by the sensorId argument.
*  A macro for the widget ID can be found in the key_touch Configuration header 
*  file defined as key_touch_<WidgetName>_WDGT_ID. 
*
* \param   sensorId 
*  Specify the ID number of the sensor within the widget to update its baseline.
*  A macro for the sensor ID within a specified widget can be found in the 
*  key_touch Configuration header file defined as 
*  key_touch_<WidgetName>_SNS<SensorNumber>_ID
*
* \return   
*  Returns the status of the specified sensor update baseline operation:
*  - CYRET_SUCCESS if operation was successfully completed
*  - CYRET_BAD_DATA if baseline processing failed
*
*******************************************************************************/
cystatus key_touch_UpdateSensorBaseline(uint32 widgetId, uint32 sensorId)
{    
    uint32 result = CYRET_SUCCESS;
    
    key_touch_RAM_SNS_STRUCT *ptrSensor = NULL;    
    key_touch_FLASH_WD_STRUCT const *ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];    
    key_touch_RAM_WD_BASE_STRUCT *ptrWidgetRam = ptrWidget->ptr2WdgtRam;   

    /* Find pointer to specified sensor object */     
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];
    result = key_touch_FtUpdateBaseline(ptrWidgetRam, ptrSensor, (uint32)ptrWidget->wdgtType);
    
    #if (key_touch_ENABLE == key_touch_TST_BSLN_DUPLICATION_EN)
        if (CYRET_SUCCESS != result)
        {
            result = CYRET_BAD_DATA;
            key_touch_UpdateTestResultBaselineDuplication(widgetId, sensorId);           
        }
    #endif /* (key_touch_ENABLE == key_touch_TST_BSLN_DUPLICATION_EN) */

    return result;
}

/*******************************************************************************
* Function Name: key_touch_FtUpdateBaseline
****************************************************************************//**
*
* \brief
*  Updates the baseline for a sensor specified by an input parameter.
*
* \details
*  Check a matching of present baseline and its inverse duplication. If they 
*  match then updates the baseline for a sensor specified by an input parameter.  
*  If don't match the function return key_touch_TST_BSLN_DUPLICATION
*  result and don't update baseline.
*
* \param    ptrWidgetRam
*  The pointer to the widget RAM structure where all the widget parameters
*  are stored.
*
* \param    ptrSensor
*  The pointer to the sensor RAM structure where all the sensor parameters
*  are stored.
*
* \param    wdType
*  Specifies the type of a widget.
*
* \return   
*  Returns a status indicating whether the baseline has been updated:
*  - CYRET_SUCCESS if baseline updating was successful;
*  - key_touch_PROCESS_BASELINE_FAILED if present sensor's any channel
*    baseline and its inversion doesn't matched
*
*******************************************************************************/
uint32 key_touch_FtUpdateBaseline(
                                key_touch_RAM_WD_BASE_STRUCT *ptrWidgetRam,
                                key_touch_RAM_SNS_STRUCT *ptrSensor, 
                                uint32 wdType)
{         
    uint32 sign;
    uint32 difference;        
    uint32 channel;
    uint32 result = CYRET_SUCCESS;
    
    #if (key_touch_TOTAL_WIDGETS)  
        uint32 history;
    #endif /* (key_touch_TOTAL_WIDGETS) */    
    
    /* Apply baseline to every channel in sensor */
    for(channel = key_touch_NUM_SCAN_FREQS; channel-- > 0u;) 
    {               
        #if (key_touch_ENABLE == key_touch_TST_BSLN_DUPLICATION_EN)
            if (ptrSensor->bslnInv[channel] != ((uint16) ~(ptrSensor->bsln[channel])))
            {
                result = key_touch_PROCESS_BASELINE_FAILED;
            }
            else
            {
        #endif /* (key_touch_ENABLE == key_touch_TST_BSLN_DUPLICATION_EN) */

        /* Calculate signal value and its sign */
        if(ptrSensor->raw[channel] >= ptrSensor->bsln[channel])
        {
            difference = (uint32)ptrSensor->raw[channel] - (uint32)ptrSensor->bsln[channel];
            sign = 1u;
            ptrSensor->negBslnRstCnt[channel] = 0u;
        }
        else
        {
            difference = (uint32)ptrSensor->bsln[channel] - (uint32)ptrSensor->raw[channel];
            sign = 0u;
        }     
        
        /* Reset baseline if condition is met */ 
        if((sign == 0u) && (difference > (uint32) ptrWidgetRam->nNoiseTh))
        {
            if(ptrSensor->negBslnRstCnt[channel] >= ptrWidgetRam->lowBslnRst)
            {                
                key_touch_FtInitializeBaselineChannel(ptrSensor, wdType, channel);             
            }
            else
            {
                ptrSensor->negBslnRstCnt[channel]++;
            }
        }
        else
        {
            #if (!key_touch_SENSOR_AUTO_RESET_EN)
                /* Update baseline only if signal is in range between noiseThreshold and negativenoiseThreshold */
                if ((difference <= (uint32)ptrWidgetRam->noiseTh) ||
                    ((difference < (uint32) ptrWidgetRam->nNoiseTh) && (sign == 0u)))
                {
            #endif /* (key_touch_CSD_AUTO_RESET == key_touch_CSD_AUTO_RESET_DISABLE) */
            
            #if (key_touch_BASELINE_TYPE == key_touch_IIR_BASELINE)  
                /* Calculate baseline value */
                if ((key_touch_WD_TYPE_ENUM)wdType != key_touch_WD_PROXIMITY_E)
                {
                    #if (key_touch_REGULAR_SENSOR_EN) 
                        #if (key_touch_REGULAR_IIR_BL_TYPE == key_touch_IIR_FILTER_PERFORMANCE)                                    
                            history = (uint32) ptrSensor->bsln[channel] << 8u; 
                            history |= ptrSensor->bslnExt[channel];
                        #else
                            history = ptrSensor->bsln[channel];                                     
                        #endif /* (key_touch_REGULAR_IIR_BL_TYPE == key_touch_IIR_FILTER_PERFORMANCE) */                            
                    
                        history =  key_touch_FtIIR1stOrder(
                                        (uint32)ptrSensor->raw[channel],
                                        history, 
                                        key_touch_REGULAR_IIR_BL_N, 
                                        key_touch_REGULAR_IIR_BL_SHIFT);
                                                   
                        #if (key_touch_REGULAR_IIR_BL_TYPE == key_touch_IIR_FILTER_PERFORMANCE)                                    
                            ptrSensor->bsln[channel] = LO16(history >> 8u);
                            ptrSensor->bslnExt[channel] = LO8(history);
                        #else
                            ptrSensor->bsln[channel] = LO16(history);
                        #endif /* (key_touch_REGULAR_IIR_BL_TYPE == key_touch_IIR_FILTER_PERFORMANCE) */
                    #endif /* (key_touch_REGULAR_SENSOR_EN) */
                }
                else 
                {
                    #if (key_touch_PROXIMITY_SENSOR_EN)     
                        #if (key_touch_PROX_IIR_BL_TYPE == key_touch_IIR_FILTER_PERFORMANCE)                                
                            history = (uint32) ptrSensor->bsln[channel] << 8u; 
                            history |= ptrSensor->bslnExt[channel];
                        #else
                            history = (uint32) ptrSensor->bsln[channel];                                    
                        #endif /* (key_touch_PROX_IIR_BL_TYPE == key_touch_IIR_FILTER_PERFORMANCE) */ 
                        
                        history = key_touch_FtIIR1stOrder((uint32)ptrSensor->raw[channel], history, key_touch_PROX_IIR_BL_N , key_touch_PROX_IIR_BL_SHIFT);
                        
                        #if (key_touch_PROX_IIR_BL_TYPE == key_touch_IIR_FILTER_PERFORMANCE)                                
                            ptrSensor->bsln[channel] = LO16(history >> 8u);
                            ptrSensor->bslnExt[channel] = LO8(history);
                        #else
                            ptrSensor->bsln[channel] = LO16(history);
                        #endif /* (key_touch_PROX_IIR_BL_TYPE == key_touch_IIR_FILTER_PERFORMANCE) */        
                    #endif /* (key_touch_PROX_SENSOR_EN)   */
                }
            #else /* (key_touch_CSD_BASELINE_TYPE == key_touch_IIR_BASELINE)  */
                
                /******************************************************************
                * This is the place where the bucket algorithm should be implemented.
                * The bucket method will be implemented in future component version.
                *******************************************************************/
                
            #endif /* (key_touch_CSD_BASELINE_TYPE == key_touch_IIR_BASELINE)  */
                    
            #if (!key_touch_SENSOR_AUTO_RESET_EN)
                }
            #endif /* (!key_touch_SENSOR_AUTO_RESET_EN) */
        }
                
        #if (key_touch_ENABLE == key_touch_TST_BSLN_DUPLICATION_EN)
            /* Update baseline inversion of every channel in sensor */    
            ptrSensor->bslnInv[channel] = ~(ptrSensor->bsln[channel]);
            }
        #endif /* (key_touch_ENABLE == key_touch_TST_BSLN_DUPLICATION_EN) */

    }
    return result;    
}


/*******************************************************************************
* Function Name: key_touch_InitializeAllBaselines
****************************************************************************//**
*
* \brief    
*  Initializes (or re-initialize) the baseline of all sensors of all widgets.
*
* \details  
*  Initializes the baseline for all sensors of all widgets. Also, this function
*  can be used to re-initialize baselines. key_touch_Start() calls this 
*  API as part of key_touch operation initialization.
*
*******************************************************************************/
void key_touch_InitializeAllBaselines(void)
{
    uint32 widgetId;    
    
    for(widgetId = key_touch_TOTAL_WIDGETS; widgetId-- > 0u;)
    {
        key_touch_InitializeWidgetBaseline(widgetId); 
    }
}


/*******************************************************************************
* Function Name: key_touch_InitializeWidgetBaseline
****************************************************************************//**
*
* \brief    
*  Initializes (or re-initialize) the baseline of all sensors in a widget 
*  specified by input parameter. 
*
* \details  
*  Initializes (or re-initializes) the baseline for all sensors of the 
*  specified widget.
*
* \param  widgetId 
*  Specify the ID number of a widget to initialize the baseline of all sensors
*  in the widget. 
*  A macro for the widget ID can be found in the 
*  key_touch Configuration header file defined as 
*  key_touch_<WidgetName>_WDGT_ID.
*
*******************************************************************************/
void key_touch_InitializeWidgetBaseline(uint32 widgetId)
{   
    uint32 sensorId;
    uint32 sensorsNumber;
  
    key_touch_FLASH_WD_STRUCT const *ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];

    /* Find total amount of sensors in specified widget */   
    sensorsNumber = key_touch_GET_SNS_CNT_BY_PTR(ptrWidget);    
    
    for(sensorId = sensorsNumber; sensorId-- > 0u;)
    {
        key_touch_InitializeSensorBaseline(widgetId, sensorId);   
    }
}


/*******************************************************************************
* Function Name: key_touch_InitializeSensorBaseline
****************************************************************************//**
*
* \brief
*  Initializes (or re-initialize) the baseline of a sensor in a widget specified
*  by input parameters.
*
* \details  
*  Initializes (or re-initializes) the baseline for a specified sensor within
*  a specified widget.
*
* \param    widgetId 
*  Specify the ID number of a widget to initialize the baseline of all sensors
*  in the widget.
*  A macro for the widget ID can be found in the 
*  key_touch Configuration header file defined as 
*  key_touch_<WidgetName>_WDGT_ID.
*  
* \param    sensorId 
*  Specify the ID number of the sensor within the widget to initialize its 
*  baseline.
*  A macro for the sensor ID within a specified widget can be found in the 
*  key_touch Configuration header file defined as 
*  key_touch_<WidgetName>_SNS<SensorNumber>_ID
*
*******************************************************************************/
void key_touch_InitializeSensorBaseline(uint32 widgetId, uint32 sensorId)
{      
    key_touch_RAM_SNS_STRUCT *ptrSensor = NULL;    
    key_touch_FLASH_WD_STRUCT const *ptrWidget = NULL;
    ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];

    /* Find pointer to specified sensor object */     
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];

    key_touch_FtInitializeBaseline(ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: key_touch_FtInitializeBaseline
****************************************************************************//**
*
* \brief    Initializes the baseline history for a sensor indicated by an input
*           parameter.
*
* \details  Initializes the baseline history for a sensor indicated by an input
*           parameter.
*
* \param    *ptrSensor The pointer to the sensor RAM object.
* \param    wdType     Specifies the type of a widget.
*
*******************************************************************************/
CY_INLINE void key_touch_FtInitializeBaseline(key_touch_RAM_SNS_STRUCT *ptrSensor, uint32 wdType) 
{
    uint32 channel;

    /* Apply baseline initialization to every channel in sensor */    
    for(channel = key_touch_NUM_SCAN_FREQS; channel-- > 0u;) 
    {
        key_touch_FtInitializeBaselineChannel(ptrSensor, wdType, channel); 
    }
}


/*******************************************************************************
* Function Name: key_touch_FtInitializeBaselineChannel
****************************************************************************//**
*
* \brief    Initializes the baseline history for a sensor indicated by an input
*           parameter.
*
* \details  Initializes the baseline history for a sensor indicated by an input
*           parameter.
*
* \param    *ptrSensor The pointer to the sensor RAM object.
* \param    wdType     Specifies the type of a widget.
* \param    channel    Specifies the number of the channel to be initialized.
*
*******************************************************************************/
void key_touch_FtInitializeBaselineChannel(key_touch_RAM_SNS_STRUCT *ptrSensor, uint32 wdType, uint32 channel) 
{
    #if (key_touch_BASELINE_TYPE == key_touch_IIR_BASELINE)  
        if ((key_touch_WD_TYPE_ENUM)wdType != key_touch_WD_PROXIMITY_E)
        {
            #if (key_touch_REGULAR_SENSOR_EN)
                #if (key_touch_REGULAR_IIR_BL_TYPE == key_touch_IIR_FILTER_PERFORMANCE)                    
                    ptrSensor->bslnExt[channel] = 0u;                
                #endif /* (key_touch_REGULAR_IIR_BL_TYPE == key_touch_IIR_FILTER_PERFORMANCE) */
            #endif /* (key_touch_REGULAR_SENSOR_EN) */
        }
        else
        {
            #if (key_touch_PROXIMITY_SENSOR_EN)     
                #if (key_touch_PROX_IIR_BL_TYPE == key_touch_IIR_FILTER_PERFORMANCE)                   
                    ptrSensor->bslnExt[channel] = 0u;               
                #endif /* (key_touch_PROX_IIR_BL_TYPE == key_touch_IIR_FILTER_PERFORMANCE) */
            #endif /* (key_touch_PROX_SENSOR_EN) */
        }
    #else
        /* key_touch_BASELINE_TYPE == key_touch_BUCKET_BASELINE */        
        ptrSensor->bslnExt[channel] = 0u;        
    #endif /* (key_touch_BASELINE_TYPE == key_touch_IIR_BASELINE) */      
    
    ptrSensor->bsln[channel] = ptrSensor->raw[channel]; 
    
    #if (key_touch_ENABLE == key_touch_TST_BSLN_DUPLICATION_EN)
    /* Update baseline inversion of the channel in sensor */    
        ptrSensor->bslnInv[channel] = ~(ptrSensor->bsln[channel]);
    #endif /* (key_touch_ENABLE == key_touch_TST_BSLN_DUPLICATION_EN) */

    ptrSensor->negBslnRstCnt[channel] = 0u;
}


#if (key_touch_REGULAR_RC_IIR_FILTER_EN || key_touch_PROX_RC_IIR_FILTER_EN)

/*******************************************************************************
* Function Name: key_touch_InitializeIIR
****************************************************************************//**
*
* \brief    Initialize the IIR filter history.
*
* \details  Initialize the IIR filter history.
*
* \param    widgetId Specifies the ID number of the widget.
* \param    sensorId Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void key_touch_InitializeIIR(uint32 widgetId, uint32 sensorId)
{   
    key_touch_FLASH_WD_STRUCT const *ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];      
    key_touch_RAM_SNS_STRUCT *ptrSensor = NULL;    
    key_touch_PTR_FILTER_VARIANT ptrFilterHistObj; 
              
    /* Find pointer to specified sensor object */     
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];
        
    /* Find pointer to specified filter sensor object */     
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;
    
    if ((key_touch_WD_TYPE_ENUM)ptrWidget->wdgtType != key_touch_WD_PROXIMITY_E)
    {
        #if (key_touch_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (key_touch_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (key_touch_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (key_touch_PROXIMITY_SENSOR_EN) */
    }    
    
    key_touch_InitializeIIRInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: key_touch_RunIIR
****************************************************************************//**
*
* \brief    Executes the IIR filter algorithm on a sensor indicated by an input
*           parameter. 
*
* \details  Executes the IIR filter algorithm on a sensor indicated by an input
*           parameter. 
*
* \param    widgetId Specifies the ID number of the widget.
* \param    sensorId Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void key_touch_RunIIR(uint32 widgetId, uint32 sensorId)
{
    key_touch_FLASH_WD_STRUCT const *ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];      
    key_touch_RAM_SNS_STRUCT *ptrSensor = NULL;    
    key_touch_PTR_FILTER_VARIANT ptrFilterHistObj; 
              
    /* Find pointer to specified sensor object */     
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];
        
    /* Find pointer to specified filter sensor object */     
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;
    
    if ((key_touch_WD_TYPE_ENUM)ptrWidget->wdgtType != key_touch_WD_PROXIMITY_E)
    {
        #if (key_touch_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (key_touch_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (key_touch_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (key_touch_PROXIMITY_SENSOR_EN) */
    }    
    
    key_touch_RunIIRInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}
    
/*******************************************************************************
* Function Name: key_touch_InitializeIIRInternal
****************************************************************************//**
*
* \brief    Initializes the IIR filter history.
*
* \details  Initializes the IIR filter history.
*
* \param    ptrFilterHistObj The pointer to the filter RAM object of the sensor.
* \param    ptrSensorObj     The pointer to the sensor RAM object of the sensor.
* \param    wdType           Specifies the type of a widget.                                  
*
*******************************************************************************/
void key_touch_InitializeIIRInternal(key_touch_PTR_FILTER_VARIANT ptrFilterHistObj,
                                            key_touch_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    uint32 channel;

    for(channel = key_touch_NUM_SCAN_FREQS; channel-- > 0u;)
    {
        if ((key_touch_WD_TYPE_ENUM)wdType != key_touch_WD_PROXIMITY_E)
        {
            #if (key_touch_REGULAR_SENSOR_EN && key_touch_REGULAR_RC_IIR_FILTER_EN)
                #if (key_touch_REGULAR_IIR_RC_TYPE == key_touch_IIR_FILTER_PERFORMANCE)
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].iirHistory = ptrSensorObj->raw[channel];
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].iirHistoryLow = 0u;
                #else
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].iirHistory = ptrSensorObj->raw[channel] << key_touch_REGULAR_IIR_RC_SHIFT;                   
                #endif /* (key_touch_REGULAR_IIR_RC_TYPE == key_touch_IIR_FILTER_PERFORMANCE) */
            #endif /* (key_touch_REGULAR_SENSOR_EN) */    
        }
        else
        {
            #if (key_touch_PROXIMITY_SENSOR_EN && key_touch_PROX_RC_IIR_FILTER_EN)
                #if (key_touch_PROX_IIR_RC_TYPE == key_touch_IIR_FILTER_PERFORMANCE)
                    ptrFilterHistObj.ptrProx->proxChannel[channel].iirHistory = ptrSensorObj->raw[channel];
                    ptrFilterHistObj.ptrProx->proxChannel[channel].iirHistoryLow = 0u;    
                #else
                    ptrFilterHistObj.ptrProx->proxChannel[channel].iirHistory = ptrSensorObj->raw[channel] << key_touch_PROX_IIR_RC_SHIFT;                                   
                #endif /* (key_touch_PROX_IIR_RC_TYPE == key_touch_IIR_FILTER_PERFORMANCE) */
            #endif /* (key_touch_PROX_SENSOR_EN) */
        }    
    }    
}
 

/*******************************************************************************
* Function Name: key_touch_RunIIRInternal
****************************************************************************//**
*
* \brief    Run the IIR filter.
*
* \details  Run the IIR filter.
*
* \param    ptrFilterHistObj The pointer to the filter RAM object of the sensor.
* \param    ptrSensorObj     The pointer to the sensor RAM object of the sensor.
* \param    wdType           Specifies the type of a widget.
*
*******************************************************************************/    
void key_touch_RunIIRInternal(key_touch_PTR_FILTER_VARIANT ptrFilterHistObj, 
                                     key_touch_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{        
    uint32 channel;
    uint32 temp;

    for(channel = key_touch_NUM_SCAN_FREQS; channel-- > 0u;)
    {
        if ((key_touch_WD_TYPE_ENUM)wdType != key_touch_WD_PROXIMITY_E)
        {
            #if (key_touch_REGULAR_SENSOR_EN && key_touch_REGULAR_RC_IIR_FILTER_EN)
                #if (key_touch_REGULAR_IIR_RC_TYPE == key_touch_IIR_FILTER_PERFORMANCE)
                    temp = ((uint32)ptrFilterHistObj.ptrRegular->regularChannel[channel].iirHistory << key_touch_REGULAR_IIR_RC_SHIFT);
                    temp |= ptrFilterHistObj.ptrRegular->regularChannel[channel].iirHistoryLow;
                    temp = key_touch_FtIIR1stOrder((uint32)ptrSensorObj->raw[channel],
                                                        temp,
                                                        key_touch_REGULAR_IIR_RC_N,
                                                        key_touch_REGULAR_IIR_RC_SHIFT);
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].iirHistory = LO16(temp >>key_touch_REGULAR_IIR_RC_SHIFT);
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].iirHistoryLow = LO8(temp);
                    ptrSensorObj->raw[channel] = LO16(temp >>key_touch_REGULAR_IIR_RC_SHIFT);
                #else
                    temp =key_touch_FtIIR1stOrder((uint32)ptrSensorObj->raw[channel],
                                                        (uint32)ptrFilterHistObj.ptrRegular->regularChannel[channel].iirHistory,
                                                        key_touch_REGULAR_IIR_RC_N,
                                                        key_touch_REGULAR_IIR_RC_SHIFT);
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].iirHistory = LO16(temp);
                    ptrSensorObj->raw[channel] = LO16(temp >>key_touch_REGULAR_IIR_RC_SHIFT);
                #endif /* (key_touch_REGULAR_IIR_RC_TYPE == key_touch_IIR_FILTER_PERFORMANCE) */
            #endif /* (key_touch_REGULAR_SENSOR_EN) */    
        }
        else
        {
            #if (key_touch_PROXIMITY_SENSOR_EN && key_touch_PROX_RC_IIR_FILTER_EN)
                #if (key_touch_PROX_IIR_RC_TYPE == key_touch_IIR_FILTER_PERFORMANCE)
                    temp =  ptrFilterHistObj.ptrProx->proxChannel[channel].iirHistory << key_touch_PROX_IIR_RC_SHIFT;
                    temp |= ptrFilterHistObj.ptrProx->proxChannel[channel].iirHistoryLow;
                    temp =key_touch_FtIIR1stOrder((uint32)ptrSensorObj->raw[channel],
                                                        temp,
                                                        key_touch_PROX_IIR_RC_N,
                                                        key_touch_PROX_IIR_RC_SHIFT);
                    ptrFilterHistObj.ptrProx->proxChannel[channel].iirHistory = LO16(temp >>key_touch_PROX_IIR_RC_SHIFT);
                    ptrFilterHistObj.ptrProx->proxChannel[channel].iirHistoryLow = LO8(temp);
                    ptrSensorObj->raw[channel] = LO16(temp >>key_touch_PROX_IIR_RC_SHIFT);
                #else
                    temp =key_touch_FtIIR1stOrder((uint32)ptrSensorObj->raw[channel],
                                                        (uint32)ptrFilterHistObj.ptrProx->proxChannel[channel].iirHistory, 
                                                        key_touch_PROX_IIR_RC_N,
                                                        key_touch_PROX_IIR_RC_SHIFT);
                    ptrFilterHistObj.ptrProx->proxChannel[channel].iirHistory = LO16(temp);
                    ptrSensorObj->raw[channel] = LO16(temp >>key_touch_PROX_IIR_RC_SHIFT);
                #endif /* (key_touch_PROX_IIR_RC_TYPE == key_touch_IIR_FILTER_PERFORMANCE) */
            #endif /* (key_touch_PROX_SENSOR_EN) */
        }    
    }        
}    
#endif /* #if (key_touch_REGULAR_RC_IIR_FILTER_EN || key_touch_PROX_RC_IIR_FILTER_EN) */


#if (key_touch_REGULAR_RC_MEDIAN_FILTER_EN || key_touch_PROX_RC_MEDIAN_FILTER_EN)

/*******************************************************************************
* Function Name: key_touch_InitializeMedian
****************************************************************************//**
*
* \brief    Initializes the Median filter history.
*
* \details  Initializes the Median filter history.
*
* \param    widgetId Specifies the ID number of the widget.
* \param    sensorId Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void key_touch_InitializeMedian(uint32 widgetId, uint32 sensorId)
{
    key_touch_FLASH_WD_STRUCT const *ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];      
    key_touch_RAM_SNS_STRUCT *ptrSensor = NULL;    
    key_touch_PTR_FILTER_VARIANT ptrFilterHistObj; 
              
    /* Find pointer to specified sensor object */     
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];
    
    /* Find pointer to specified filter sensor object */     
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;
    
    if ((key_touch_WD_TYPE_ENUM)ptrWidget->wdgtType != key_touch_WD_PROXIMITY_E)
    {
        #if (key_touch_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (key_touch_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (key_touch_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (key_touch_PROXIMITY_SENSOR_EN) */
    }
    
    key_touch_InitializeMedianInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}     


/*******************************************************************************
* Function Name: key_touch_RunMedian
****************************************************************************//**
*
* \brief    Executes the Median filter algorithm on a sensor indicated by an input 
*           parameter. 
*
* \details  Executes the Median filter algorithm on a sensor indicated by an input 
*           parameter. 
*
* \param    widgetId Specifies the ID number of the widget.
* \param    sensorId Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void key_touch_RunMedian(uint32 widgetId, uint32 sensorId)
{
    key_touch_FLASH_WD_STRUCT const *ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];      
    key_touch_RAM_SNS_STRUCT *ptrSensor = NULL;    
    key_touch_PTR_FILTER_VARIANT ptrFilterHistObj; 
              
    /* Find pointer to specified sensor object */     
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];
    
    /* Find pointer to specified filter sensor object */     
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;
    
    if ((key_touch_WD_TYPE_ENUM)ptrWidget->wdgtType != key_touch_WD_PROXIMITY_E)
    {
        #if (key_touch_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (key_touch_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (key_touch_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (key_touch_PROXIMITY_SENSOR_EN) */
    }
    
    key_touch_RunMedianInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}
   

/*******************************************************************************
* Function Name: key_touch_InitializeMedianInternal
****************************************************************************//**
*
* \brief    Initializes the Median filter.
*
* \details  Initializes the Median filter.
*
* \param    ptrFilterHistObj The pointer to the filter RAM object of the sensor.
* \param    ptrSensorObj     The pointer to the sensor RAM object of the sensor.
* \param    wdType           Specifies the type of a widget.
*
*******************************************************************************/
void key_touch_InitializeMedianInternal(key_touch_PTR_FILTER_VARIANT ptrFilterHistObj,
                                               key_touch_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    uint32 channel;

    for(channel = key_touch_NUM_SCAN_FREQS; channel-- > 0u;)
    {
        if ((key_touch_WD_TYPE_ENUM)wdType != key_touch_WD_PROXIMITY_E)
        {
            #if (key_touch_REGULAR_SENSOR_EN && key_touch_REGULAR_RC_MEDIAN_FILTER_EN)
                ptrFilterHistObj.ptrRegular->regularChannel[channel].medHistory[0u] = ptrSensorObj->raw[channel];
                ptrFilterHistObj.ptrRegular->regularChannel[channel].medHistory[1u] = ptrSensorObj->raw[channel];
            #endif /* (key_touch_REGULAR_SENSOR_EN) */
        }
        else
        {
            #if (key_touch_PROXIMITY_SENSOR_EN && key_touch_PROX_RC_MEDIAN_FILTER_EN)
                ptrFilterHistObj.ptrProx->proxChannel[channel].medHistory[0u] = ptrSensorObj->raw[channel];
                ptrFilterHistObj.ptrProx->proxChannel[channel].medHistory[1u] = ptrSensorObj->raw[channel];
            #endif /* (key_touch_PROXIMITY_SENSOR_EN) */               
        }
    }
}


/*******************************************************************************
* Function Name: key_touch_RunMedianInternal
****************************************************************************//**
*
* \brief    Runs the Median filter.
*
* \details  Runs the Median filter.
*
* \param    ptrFilterHistObj The pointer to the filter RAM object of the sensor.
* \param    ptrSensorObj     The pointer to the sensor RAM object of the sensor.
* \param    wdType           Specifies the type of a widget.
*
*******************************************************************************/
void key_touch_RunMedianInternal(key_touch_PTR_FILTER_VARIANT ptrFilterHistObj,
                                        key_touch_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    uint32 channel;
    
    #if ((key_touch_REGULAR_SENSOR_EN && key_touch_REGULAR_RC_MEDIAN_FILTER_EN) || \
         (key_touch_PROXIMITY_SENSOR_EN && key_touch_PROX_RC_MEDIAN_FILTER_EN))
        uint32 temp;
    #endif
    
    for(channel = key_touch_NUM_SCAN_FREQS; channel-- > 0u;)
    {    
        if ((key_touch_WD_TYPE_ENUM)wdType != key_touch_WD_PROXIMITY_E)
        {                                             
            #if (key_touch_REGULAR_SENSOR_EN && key_touch_REGULAR_RC_MEDIAN_FILTER_EN)
                temp = key_touch_FtMedian((uint32)ptrSensorObj->raw[channel],\
                                                 (uint32)ptrFilterHistObj.ptrRegular->regularChannel[channel].medHistory[0u],\
                                                 (uint32)ptrFilterHistObj.ptrRegular->regularChannel[channel].medHistory[1u]);
                ptrFilterHistObj.ptrRegular->regularChannel[channel].medHistory[1u] = \
                ptrFilterHistObj.ptrRegular->regularChannel[channel].medHistory[0u];
                ptrFilterHistObj.ptrRegular->regularChannel[channel].medHistory[0u] = ptrSensorObj->raw[channel];
                ptrSensorObj->raw[channel] = LO16(temp);
            #endif /* (key_touch_REGULAR_SENSOR_EN) */     
        }
        else 
        {                   
            #if (key_touch_PROXIMITY_SENSOR_EN && key_touch_PROX_RC_MEDIAN_FILTER_EN)
                temp = key_touch_FtMedian((uint32)ptrSensorObj->raw[channel],\
                                                 (uint32)ptrFilterHistObj.ptrProx->proxChannel[channel].medHistory[0u],\
                                                 (uint32)ptrFilterHistObj.ptrProx->proxChannel[channel].medHistory[1u]);
                ptrFilterHistObj.ptrProx->proxChannel[channel].medHistory[1u] = \
                ptrFilterHistObj.ptrProx->proxChannel[channel].medHistory[0u];
                ptrFilterHistObj.ptrProx->proxChannel[channel].medHistory[0u] = ptrSensorObj->raw[channel];
                ptrSensorObj->raw[channel] = LO16(temp);
            #endif /* (key_touch_PROXIMITY_SENSOR_EN) */               
        }
    }
}
#endif /* (key_touch_REGULAR_RC_MEDIAN_FILTER_EN || key_touch_PROX_RC_MEDIAN_FILTER_EN) */


#if (key_touch_REGULAR_RC_AVERAGE_FILTER_EN || key_touch_PROX_RC_AVERAGE_FILTER_EN)

/*******************************************************************************
* Function Name: key_touch_InitializeAverage
****************************************************************************//**
*
* \brief    Initializes the average filter history.
*
* \details  Initializes the average filter history.
*
* \param    widgetId Specifies the ID number of the widget.
* \param    sensorId Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void key_touch_InitializeAverage(uint32 widgetId, uint32 sensorId)
{
    key_touch_FLASH_WD_STRUCT const *ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];      
    key_touch_RAM_SNS_STRUCT *ptrSensor = NULL;
    key_touch_PTR_FILTER_VARIANT ptrFilterHistObj;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];
    
    /* Find pointer to specified filter sensor object */
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;

    if ((key_touch_WD_TYPE_ENUM)ptrWidget->wdgtType != key_touch_WD_PROXIMITY_E)
    {
        #if (key_touch_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (key_touch_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (key_touch_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (key_touch_PROXIMITY_SENSOR_EN) */
    }

    key_touch_InitializeAverageInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: key_touch_RunAverage
****************************************************************************//**
*
* \brief    Executes the average filter algorithm on a sensor indicated by an input 
*           parameter. 
*
* \details  Executes the average filter algorithm on a sensor indicated by an input 
*           parameter. 
*
* \param    widgetId Specifies the ID number of the widget.
* \param    sensorId Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void key_touch_RunAverage(uint32 widgetId, uint32 sensorId)
{
    key_touch_FLASH_WD_STRUCT const *ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];      
    key_touch_RAM_SNS_STRUCT *ptrSensor = NULL;    
    key_touch_PTR_FILTER_VARIANT ptrFilterHistObj; 
              
    /* Find pointer to specified sensor object */     
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];
    
    /* Find pointer to specified filter sensor object */     
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;
    
    if ((key_touch_WD_TYPE_ENUM)ptrWidget->wdgtType != key_touch_WD_PROXIMITY_E)
    {
        #if (key_touch_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (key_touch_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (key_touch_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (key_touch_PROXIMITY_SENSOR_EN) */
    }
    
    key_touch_RunAverageInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: key_touch_InitializeAverageInternal
****************************************************************************//**
*
* \brief    Initializes the average filter.
*
* \details  Initializes the average filter.
*
* \param    ptrFilterHistObj The pointer to the filter RAM object of the sensor.
* \param    ptrSensorObj     The pointer to the sensor RAM object of the sensor.
* \param    wdType           Specifies the type of a widget.
*
*******************************************************************************/
void key_touch_InitializeAverageInternal(key_touch_PTR_FILTER_VARIANT ptrFilterHistObj,\
                                                  key_touch_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    uint32 channel;

    for(channel = key_touch_NUM_SCAN_FREQS; channel-- > 0u;)
    {
        if ((key_touch_WD_TYPE_ENUM)wdType != key_touch_WD_PROXIMITY_E)
        {
            #if (key_touch_REGULAR_SENSOR_EN && key_touch_REGULAR_RC_AVERAGE_FILTER_EN)
                ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[0] = ptrSensorObj->raw[channel];
                #if (key_touch_REGULAR_AVERAGE_LEN == key_touch_AVERAGE_FILTER_LEN_4)
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[1u] = ptrSensorObj->raw[channel];
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[2u] = ptrSensorObj->raw[channel];
                #endif /* key_touch_REGULAR_AVERAGE_LEN == key_touch_AVERAGE_FILTER_LEN_4 */
            #endif /* (key_touch_REGULAR_SENSOR_EN) */      
        }
        else
        {
            #if (key_touch_PROXIMITY_SENSOR_EN && key_touch_PROX_RC_AVERAGE_FILTER_EN)
                ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[0] = ptrSensorObj->raw[channel];
                    #if (key_touch_PROX_AVERAGE_LEN == key_touch_AVERAGE_FILTER_LEN_4)
                        ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[1u] = ptrSensorObj->raw[channel];
                        ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[2u] = ptrSensorObj->raw[channel];
                    #endif /* key_touch_REGULAR_AVERAGE_LEN == key_touch_AVERAGE_FILTER_LEN_4 */
            #endif /* (key_touch_PROXIMITY_SENSOR_EN) */
        }
    }
}


/*******************************************************************************
* Function Name: key_touch_RunAverageInternal
****************************************************************************//**
*
* \brief    Runs the average filter.
*
* \details  Runs the average filter.
*
* \param    ptrFilterHistObj The pointer to the filter RAM object of the sensor.
* \param    ptrSensorObj     The pointer to the sensor RAM object of the sensor.
* \param    wdType           Specifies the type of a widget.
*
*******************************************************************************/
void key_touch_RunAverageInternal(key_touch_PTR_FILTER_VARIANT ptrFilterHistObj,\
                                           key_touch_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    uint32 channel;
    uint32 temp;

    for(channel = key_touch_NUM_SCAN_FREQS; channel-- > 0u;)
    {
        if ((key_touch_WD_TYPE_ENUM)wdType != key_touch_WD_PROXIMITY_E)
        {
            #if (key_touch_REGULAR_SENSOR_EN && key_touch_REGULAR_RC_AVERAGE_FILTER_EN)
                #if (key_touch_REGULAR_AVERAGE_LEN == key_touch_AVERAGE_FILTER_LEN_2)
                    temp = ((uint32)ptrSensorObj->raw[channel] + 
                            (uint32)ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[0]) >> 1u;
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[0] = ptrSensorObj->raw[channel];
                    ptrSensorObj->raw[channel] = LO16(temp);
                #else
                    temp = ((uint32)ptrSensorObj->raw[channel] + 
                            (uint32)ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[0] + 
                            (uint32)ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[1u] + 
                            (uint32)ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[2u]) >> 2u;

                    ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[2u] =
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[1u];
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[1u] =
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[0];
                    ptrFilterHistObj.ptrRegular->regularChannel[channel].avgHistory[0] = ptrSensorObj->raw[channel];
                    ptrSensorObj->raw[channel] = LO16(temp);
                #endif /* key_touch_REGULAR_AVERAGE_LEN == key_touch_AVERAGE_FILTER_LEN_4 */
            #endif /* (key_touch_REGULAR_SENSOR_EN) */
        }
        else 
        {
            #if (key_touch_PROXIMITY_SENSOR_EN && key_touch_PROX_RC_AVERAGE_FILTER_EN)
                #if (key_touch_PROX_AVERAGE_LEN == key_touch_AVERAGE_FILTER_LEN_2)     
                    temp = ((uint32)ptrSensorObj->raw[channel] + 
                            (uint32)ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[0]) >> 1u;
                    ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[0] = ptrSensorObj->raw[channel];
                    ptrSensorObj->raw[channel] = LO16(temp);
                #else
                    temp = ((uint32)ptrSensorObj->raw[channel] + 
                            (uint32)ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[0] +
                            (uint32)ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[1u] +
                            (uint32)ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[2u]) >> 2u;
                    
                    ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[2u] =
                    ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[1u];
                    ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[1u] =
                    ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[0];
                    ptrFilterHistObj.ptrProx->proxChannel[channel].avgHistory[0] = ptrSensorObj->raw[channel];
                    ptrSensorObj->raw[channel] = LO16(temp);
                #endif /* key_touch_PROX_AVERAGE_LEN == key_touch_AVERAGE_FILTER_LEN_4 */
            #endif /* (key_touch_PROXIMITY_SENSOR_EN) */
        }
    }
}
#endif /* (key_touch_REGULAR_RC_AVERAGE_FILTER_EN || key_touch_PROX_RC_AVERAGE_FILTER_EN) */


#if ((key_touch_REGULAR_RC_FILTER_EN || key_touch_PROX_RC_FILTER_EN))
/*******************************************************************************
* Function Name: key_touch_FtRunEnabledFilters
****************************************************************************//**
*
* \brief    Runs all enabled filters.
*
* \details  Runs all enabled filters.
*
* \param    widgetId Specifies the ID number of a widget to update the IIR filter history.*
* \param    sensorId Specifies the ID number of a sensor in the widget to update the IIR 
*           filter history.
*
*******************************************************************************/
void key_touch_FtRunEnabledFilters(uint32 widgetId, uint32 sensorId)
{
    key_touch_FLASH_WD_STRUCT const *ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];      
    key_touch_RAM_SNS_STRUCT *ptrSensor = NULL;    
    key_touch_PTR_FILTER_VARIANT ptrFilterHistObj; 
              
    /* Find pointer to specified sensor object */     
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];
    
    /* Find pointer to specified filter sensor object */     
    ptrFilterHistObj.ptr = ptrWidget->ptr2FltrHistory;
    
    if ((key_touch_WD_TYPE_ENUM)ptrWidget->wdgtType != key_touch_WD_PROXIMITY_E)
    {
        #if (key_touch_REGULAR_SENSOR_EN)
            ptrFilterHistObj.ptrRegular = &ptrFilterHistObj.ptrRegular[sensorId];
        #endif /* (key_touch_REGULAR_SENSOR_EN) */
    }
    else
    {
        #if (key_touch_PROXIMITY_SENSOR_EN)
            ptrFilterHistObj.ptrProx = &ptrFilterHistObj.ptrProx[sensorId];
        #endif /* (key_touch_PROXIMITY_SENSOR_EN) */
    }
    
    key_touch_FtRunEnabledFiltersInternal(ptrFilterHistObj, ptrSensor, (uint32)ptrWidget->wdgtType);
}


/*******************************************************************************
* Function Name: key_touch_FtRunEnabledFiltersInternal
****************************************************************************//**
*
* \brief    Runs all enabled filters.
*
* \details  Runs all enabled filters.
*
* \param    ptrFilterHistObj The pointer to the filter RAM object of the sensor.
* \param    ptrSensorObj     The pointer to the sensor RAM object of the sensor.
* \param    wdType           Specifies the type of a widget.
*
*******************************************************************************/
void key_touch_FtRunEnabledFiltersInternal(key_touch_PTR_FILTER_VARIANT ptrFilterHistObj, 
                                                  key_touch_RAM_SNS_STRUCT *ptrSensorObj, uint32 wdType)
{
    #if (key_touch_REGULAR_RC_MEDIAN_FILTER_EN || key_touch_PROX_RC_MEDIAN_FILTER_EN)
        key_touch_RunMedianInternal(ptrFilterHistObj, ptrSensorObj, wdType);
    #endif /* (key_touch_REGULAR_RC_MEDIAN_FILTER_EN || key_touch_PROX_RC_MEDIAN_FILTER_EN) */
    
    #if (key_touch_REGULAR_RC_IIR_FILTER_EN || key_touch_PROX_RC_IIR_FILTER_EN)    
        key_touch_RunIIRInternal(ptrFilterHistObj, ptrSensorObj, wdType);
    #endif /* (key_touch_REGULAR_RC_IIR_FILTER_EN || key_touch_PROX_RC_IIR_FILTER_EN) */ 

    #if (key_touch_REGULAR_RC_AVERAGE_FILTER_EN || key_touch_PROX_RC_AVERAGE_FILTER_EN)
        key_touch_RunAverageInternal(ptrFilterHistObj, ptrSensorObj, wdType);
    #endif /* (key_touch_REGULAR_RC_AVERAGE_FILTER_EN || key_touch_PROX_RC_AVERAGE_FILTER_EN) */            
}
#endif /* (key_touch_REGULAR_RC_FILTER_EN || key_touch_PROX_RC_FILTER_EN) */


#if (key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN)
/*******************************************************************************
* Function Name: key_touch_RunNoiseEnvelope
****************************************************************************//**
*
* \brief    Executes the noise envelope  filter algorithm on a sensor indicated by 
*           an input parameter to measure the pk-to-pk noise in the sensor raw count.
*
* \details  Executes the noise envelope  filter algorithm on a sensor indicated by 
*           an input parameter to measure the pk-to-pk noise in the sensor raw count.
*
* \param    widgetId Specifies the ID number of the widget.
* \param    sensorId Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void key_touch_RunNoiseEnvelope(uint32 widgetId, uint32 sensorId)
{
    key_touch_FLASH_WD_STRUCT const *ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];
    key_touch_RAM_WD_BASE_STRUCT *ptrWidgetRam = ptrWidget->ptr2WdgtRam;
    key_touch_RAM_SNS_STRUCT *ptrSensor = NULL;    
    SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope = NULL;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];
    
    /* Find pointer to specified filter sensor object */
    ptrNoiseEnvelope = ptrWidget->ptr2NoiseEnvlp;
    ptrNoiseEnvelope = &ptrNoiseEnvelope[sensorId];    

    SmartSense_RunNoiseEnvelope(ptrSensor->raw[0u], ptrWidgetRam->sigPFC, ptrNoiseEnvelope);
}


/*******************************************************************************
* Function Name: key_touch_InitializeNoiseEnvelope
****************************************************************************//**
*
* \brief    Initializes the noise-envelope filter
*
* \details  Initializes the noise-envelope filter
*
* \param    widgetId Specifies the ID number of the widget.
* \param    sensorId Specifies the ID number of the sensor in the widget.
*
*******************************************************************************/
void key_touch_InitializeNoiseEnvelope(uint32 widgetId, uint32 sensorId)
{
    key_touch_FLASH_WD_STRUCT const *ptrWidget = &key_touch_dsFlash.wdgtArray[widgetId];
    key_touch_RAM_WD_BASE_STRUCT *ptrWidgetRam = ptrWidget->ptr2WdgtRam;
    key_touch_RAM_SNS_STRUCT *ptrSensor = NULL;    
    SMARTSENSE_CSD_NOISE_ENVELOPE_STRUCT *ptrNoiseEnvelope = NULL;

    /* Find pointer to specified sensor object */
    ptrSensor = ptrWidget->ptr2SnsRam;
    ptrSensor = &ptrSensor[sensorId];
    
    /* Find pointer to specified filter sensor object */
    ptrNoiseEnvelope = ptrWidget->ptr2NoiseEnvlp;
    ptrNoiseEnvelope = &ptrNoiseEnvelope[sensorId];    

    SmartSense_InitializeNoiseEnvelope(ptrSensor->raw[0u], ptrWidgetRam->sigPFC, ptrNoiseEnvelope);
}
#endif /* #if key_touch_CSD_AUTOTUNE & key_touch_CSD_SS_TH_EN */


#if (key_touch_POS_MEDIAN_FILTER_EN || key_touch_REGULAR_RC_MEDIAN_FILTER_EN || key_touch_PROX_RC_MEDIAN_FILTER_EN)
/*******************************************************************************
* Function Name: key_touch_FtMedian
****************************************************************************//**
*
* \brief    Return the median value from the three passed arguments.
*
* \details  Return the median value from the three passed arguments.
*
* \param    x1 The first value to be compared.
* \param    x2 The second value to be compared.
* \param    x3 The third value to be compared.
*
* \return   Returns the median value of input arguments.
*
*******************************************************************************/
uint32 key_touch_FtMedian(uint32 x1, uint32 x2, uint32 x3)
{
    uint32 tmp;

    if (x1 > x2)
    {
        tmp = x2;
        x2 = x1;
        x1 = tmp;
    }

    if (x2 > x3)
    {
        x2 = x3;
    }

    return ((x1 > x2) ? x1 : x2);
}
#endif /*key_touch_POS_MEDIAN_FILTER_EN || key_touch_REGULAR_RC_MEDIAN_FILTER_EN || key_touch_PROX_RC_MEDIAN_FILTER_EN*/


/*******************************************************************************
* Function Name: key_touch_FtIIR1stOrder
****************************************************************************//**
*
* \brief    Return the filtered data by the IIR 1-st order algorithm
*
* \details  Return the filtered data by the IIR 1-st order algorithm
*
* \param    input      The data to be filtered.
* \param    prevOutput The previous filtered data.
* \param    n          The IIR filter coefficient (n/256).
* \param    shift      The parameter is used to shift input data to have free LSB 
*                       bits for a fraction storage of the filter output calculation.
*
* \return   Returns the filtered data.
*
*******************************************************************************/
uint32 key_touch_FtIIR1stOrder(uint32 input, uint32 prevOutput, uint32 n, uint32 shift)
{   
    uint32 output;
   
    /*
    * n - IIR filter coefficient (n/256)
    * shift - Used to shift input data to have free LSB bits
    * for fraction storage of filter output calculation
    */
    output = ((n * (input << shift)) + ((key_touch_IIR_COEFFICIENT_K - n) * prevOutput)) >> 8u;
    
    /* Shift operation of output will be done in upper level API if needed */
    return output;
}


#if (key_touch_POS_JITTER_FILTER_EN)
/*******************************************************************************
* Function Name: key_touch_FtJitter
****************************************************************************//**
*
* \brief    Returns the filtered data by the jitter algorithm.
*
* \details  Returns the filtered data by the jitter algorithm.
*
* \param    input      The data to be filtered.
* \param    prevOutput The previous filtered data.
*
*
* \return   Returns the filtered data.
*
*******************************************************************************/
uint32 key_touch_FtJitter(uint32 input, uint32 prevOutput)
{
    if (prevOutput > input)
    {
        input++;
    }
    else if (prevOutput < input)
    {
        input--;
    }
    else
    { 
        /* Nothing to do - MISRA 14.1 requirement*/
    }
    return input;
}
#endif /* key_touch_POS_JITTER_FILTER_EN */


/* [] END OF FILE */
