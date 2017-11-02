/***************************************************************************//**
* \file key_touch_Sensing.c
* \version 3.10
*
* \brief
*   This file contains the source of functions common for
*   different sensing methods.
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

#include "cyfitter.h"
#include "key_touch_Structure.h"
#include "key_touch_Configuration.h"
#include "key_touch_Sensing.h"
#if (key_touch_ENABLE == key_touch_SELF_TEST_EN)
    #include "key_touch_SelfTest.h"
#endif

/***************************************
* API Constants
***************************************/

#define key_touch_WIDGET_NUM_32                          (32u)
#define key_touch_WIDGET_NUM_32_DIV_SHIFT                (5u)
#define key_touch_WIDGET_NUM_32_MASK                     (0x0000001FLu)
#define key_touch_CALIBRATION_RESOLUTION                 (12u)
#define key_touch_COARSE_TRIM_THRESHOLD_1                (40u)
#define key_touch_COARSE_TRIM_THRESHOLD_2                (215u)
#define key_touch_FREQUENCY_OFFSET_5                     (20u)
#define key_touch_FREQUENCY_OFFSET_10                    (40u)
#define key_touch_CALIBRATION_FREQ_KHZ                   (1500u)
#define key_touch_CALIBRATION_MD                         (2u)
#define key_touch_MIN_IMO_FREQ_KHZ                       (6000u)
#define key_touch_CSD_AUTOTUNE_CAL_LEVEL                 (key_touch_CSD_RAWCOUNT_CAL_LEVEL)
#define key_touch_CP_MIN                                 (0u)
#define key_touch_CP_MAX                                 (65000Lu)
#define key_touch_CP_ERROR                               (4000Lu)
#if (key_touch_ENABLE == key_touch_CSD2X_EN)
    #define key_touch_TOTAL_SLOTS                        (key_touch_TOTAL_SCAN_SLOTS)
#else
    #define key_touch_TOTAL_SLOTS                        (key_touch_TOTAL_WIDGETS)
#endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

#define key_touch_CLK_SOURCE_LFSR_SCALE_OFFSET           (4u)

#if (key_touch_CLK_SOURCE_DIRECT != key_touch_CSD_SNS_CLK_SOURCE)
    #if (key_touch_ENABLE == key_touch_CSDV2)
        #define key_touch_PRS_FACTOR_DIV                 (2u)
    #else
        #define key_touch_PRS_FACTOR_DIV                 (1u)
    #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
#else
    #define key_touch_PRS_FACTOR_DIV                     (0u)
#endif /* (key_touch_CLK_SOURCE_DIRECT != key_touch_CSD_SNS_CLK_SOURCE) */

#define key_touch_FLIP_FLOP_DIV                          (1u)

#define key_touch_MOD_CSD_CLK_12000KHZ                   (12000uL)
#define key_touch_MOD_CSD_CLK_24000KHZ                   (24000uL)
#define key_touch_MOD_CSD_CLK_48000KHZ                   (48000uL)

#if ((key_touch_CLK_SOURCE_PRS8 == key_touch_CSD_SNS_CLK_SOURCE) || \
    (key_touch_CLK_SOURCE_PRS12 == key_touch_CSD_SNS_CLK_SOURCE) || \
    (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE))
    #define key_touch_FACTOR_FILTER_DELAY_12MHZ          (2u)
#else
    #define key_touch_FACTOR_FILTER_DELAY_12MHZ          (4u)
#endif /* (key_touch_CLK_SOURCE_DIRECT != key_touch_CSD_SNS_CLK_SOURCE) */

#define key_touch_FACTOR_MOD_SNS                         (8u)
#define key_touch_UINT8_MAX_VAL                          (0xFFu)
#define key_touch_MSB_OFFSET                             (8u)

/*****************************************************************************/
/* Enumeration types definition                                               */
/*****************************************************************************/

typedef enum
{
    key_touch_RES_PULLUP_E   = 0x02u,
    key_touch_RES_PULLDOWN_E = 0x03u
} key_touch_PORT_TEST_DM;

typedef enum
{
    key_touch_STS_RESET      = 0x01u,
    key_touch_STS_NO_RESET   = 0x02u
} key_touch_TEST_TYPE;


/*******************************************************************************
* Static Function Prototypes
*******************************************************************************/
/**
* \if SECTION_CAPSENSE_INTERNAL
* \addtogroup group_capsense_internal
* \{
*/

#if (key_touch_DISABLE == key_touch_CSDV2)
    static void key_touch_SsTrimIdacs(void);
    #if ((key_touch_ENABLE == key_touch_CSX_EN) || \
         (key_touch_IDAC_SINKING == key_touch_CSD_IDAC_CONFIG))
        static void key_touch_SsTrimIdacsSinking(void);
    #endif /* ((key_touch_ENABLE == key_touch_CSX_EN) || \
               (key_touch_IDAC_SINKING == key_touch_CSD_IDAC_CONFIG)) */
    #if ((key_touch_ENABLE == key_touch_CSX_EN) || \
         (key_touch_IDAC_SOURCING == key_touch_CSD_IDAC_CONFIG))
        static void key_touch_SsTrimIdacsSourcing(void);
    #endif /* ((key_touch_ENABLE == key_touch_CSX_EN) || \
               (key_touch_IDAC_SOURCING == key_touch_CSD_IDAC_CONFIG)) */
#endif /* (key_touch_ENABLE == key_touch_CSDV2) */
#if ((key_touch_ENABLE == key_touch_CSD_CSX_EN) || \
     (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
     (key_touch_ENABLE == key_touch_ADC_EN))
    #if (key_touch_ENABLE == key_touch_CSD_EN)
        static void key_touch_SsCSDDisableMode(void);
    #endif /* (key_touch_ENABLE == key_touch_CSD_EN) */
    #if (key_touch_ENABLE == key_touch_CSX_EN)
        static void key_touch_SsDisableCSXMode(void);
    #endif /* (key_touch_ENABLE == key_touch_CSX_EN) */
#endif /* ((key_touch_ENABLE == key_touch_CSD_CSX_EN) || \
           (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
           (key_touch_ENABLE == key_touch_ADC_EN)) */
#if (key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE)
    #if (key_touch_ENABLE == key_touch_CSD2X_EN)
        static void key_touch_SsSetCSD0DirectClockMode(void);
        static void key_touch_SsSetCSD1DirectClockMode(void);
    #else
        static void key_touch_SsSetDirectClockMode(void);
    #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
#endif /* (key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE) */

#if(((key_touch_ENABLE == key_touch_CSX_EN) && \
     (key_touch_ENABLE == key_touch_CSDV2) && \
     (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSX_TX_CLK_SOURCE)) ||\
    ((key_touch_ENABLE == key_touch_CSD_EN) && \
     (key_touch_ENABLE == key_touch_CSDV2) && \
     (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE)))
    static CY_INLINE uint8 key_touch_SsCalcLfsrSize(uint32 snsClkDivider, uint32 conversionsNum);
    static CY_INLINE uint8 key_touch_SsCalcLfsrScale(uint32 snsClkDivider, uint8 lfsrSize);
#endif /* (((key_touch_ENABLE == key_touch_CSX_EN) && \
            (key_touch_ENABLE == key_touch_CSDV2) && \
            (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSX_TX_CLK_SOURCE)) ||\
           ((key_touch_ENABLE == key_touch_CSD_EN) && \
            (key_touch_ENABLE == key_touch_CSDV2) && \
            (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE))) */
#if ((key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE) && \
    (key_touch_ENABLE == key_touch_CSD2X_EN))
    static void key_touch_SsSetEqualSlotClock(void);
#endif /* ((key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE) \
           (key_touch_ENABLE == key_touch_CSD2X_EN)) */
#if ((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD2X_EN))
    static void key_touch_SsSetWidgetSenseClkSrc(uint32 wdgtIndex, key_touch_RAM_WD_BASE_STRUCT * ptrWdgt);
#endif /* ((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD2X_EN)) */

#if ((key_touch_ENABLE == key_touch_CSX_EN) && (key_touch_ENABLE == key_touch_CSDV2))
    static void key_touch_SsSetWidgetTxClkSrc(uint32 wdgtIndex, key_touch_RAM_WD_BASE_STRUCT * ptrWdgt);
#endif /* ((key_touch_ENABLE == key_touch_CSX_EN) && (key_touch_ENABLE == key_touch_CSDV2)) */

/** \}
* \endif */

/*******************************************************************************
* Define module variables
*******************************************************************************/

#if ((key_touch_ENABLE == key_touch_CSD_CSX_EN) || \
     (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
     (key_touch_ENABLE == key_touch_ADC_EN))
    key_touch_SENSE_METHOD_ENUM key_touch_currentSenseMethod = key_touch_UNDEFINED_E;
#endif /* ((key_touch_ENABLE == key_touch_CSD_CSX_EN) || \
           (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
           (key_touch_ENABLE == key_touch_ADC_EN))) */

#if(key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
    /*  Module variable keep track of frequency hopping channel index   */
    uint8 key_touch_scanFreqIndex = 0u;
    /*  Variable keep frequency offsets */
    uint8 key_touch_immunity[key_touch_NUM_SCAN_FREQS] = {0u, 0u, 0u};
#else
    /* const allows C-compiler to do optimization */
    const uint8 key_touch_scanFreqIndex = 0u;
#endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

/* Global software variables */
#if (key_touch_ENABLE == key_touch_CSD2X_EN)
    volatile uint8 key_touch_widgetIndex0 = 0u;    /* Index of the scanning widget0 */
    volatile uint8 key_touch_sensorIndex0 = 0u;    /* Index of the scanning sensor0 */
    volatile uint8 key_touch_widgetIndex1 = 0u;    /* Index of the scanning widget1 */
    volatile uint8 key_touch_sensorIndex1 = 0u;    /* Index of the scanning sensor1 */
#else
    volatile uint8 key_touch_widgetIndex = 0u;    /* Index of the scanning widget */
    volatile uint8 key_touch_sensorIndex = 0u;    /* Index of the scanning sensor */
#endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
uint8 key_touch_requestScanAllWidget = 0u;
#if (key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE)
    uint8 key_touch_prescalersTuningDone = 0u;
#endif /* (key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE) */

/* Pointer to RAM_SNS_STRUCT structure  */
#if (key_touch_ENABLE == key_touch_CSD2X_EN)
    key_touch_RAM_SNS_STRUCT *key_touch_curRamSnsPtr0;
    key_touch_RAM_SNS_STRUCT *key_touch_curRamSnsPtr1;
#else
    key_touch_RAM_SNS_STRUCT *key_touch_curRamSnsPtr;
#endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

#if ((key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) || \
     (key_touch_ENABLE == key_touch_CSX_EN))
    /*  Pointer to Flash structure holding configuration of widget to be scanned  */
    #if (key_touch_ENABLE == key_touch_CSD2X_EN)
         key_touch_FLASH_WD_STRUCT const *key_touch_curFlashWdgtPtr0 = 0u;
         key_touch_FLASH_WD_STRUCT const *key_touch_curFlashWdgtPtr1 = 0u;
    #else
         key_touch_FLASH_WD_STRUCT const *key_touch_curFlashWdgtPtr = 0u;
    #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
#endif /* ((key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) || \
           (key_touch_ENABLE == key_touch_CSX_EN))  */
#if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
    /*  Pointer to Flash structure holding info of sensor to be scanned  */
    #if (key_touch_ENABLE == key_touch_CSD2X_EN)
        key_touch_FLASH_SNS_STRUCT const *key_touch_curFlashSnsPtr0 = 0u;
        key_touch_FLASH_SNS_STRUCT const *key_touch_curFlashSnsPtr1 = 0u;
    #else
        key_touch_FLASH_SNS_STRUCT const *key_touch_curFlashSnsPtr = 0u;
    #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
#endif /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) */
/*  Pointer to Flash structure to hold Sns electrode that was connected previously  */
#if (key_touch_ENABLE == key_touch_CSD2X_EN)
    key_touch_FLASH_IO_STRUCT const *key_touch_curSnsIOPtr0;
    key_touch_FLASH_IO_STRUCT const *key_touch_curSnsIOPtr1;
#else
    key_touch_FLASH_IO_STRUCT const *key_touch_curSnsIOPtr;
#endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

/*******************************************************************************
* Function Name: key_touch_IsBusy
****************************************************************************//**
*
* \brief
*  Returns the current status of the component (scan completed or scan in
*  progress).
*
* \details
*  This function returns the status of the hardware block whether a scan is
*  currently in progress or not. If the component is busy, no new scan or setup
*  widgets should be made. It is recommended using the critical section (i.e.
*  disable global interrupt) in the application when the device transitions from
*  the active mode to sleep or deep sleep mode.
*
* \return
*  Returns the current status of the component:
*    - key_touch_NOT_BUSY if there is no scan in progress and a next scan
*      can be initiated.
*    - key_touch_SW_STS_BUSY if the previous scanning is not completed
*      and the hardware block is busy.
*
*******************************************************************************/
uint32 key_touch_IsBusy(void)
{
    return ((*(volatile uint32 *)&key_touch_dsRam.status) & key_touch_SW_STS_BUSY);
}

/*******************************************************************************
* Function Name: key_touch_SetupWidget
****************************************************************************//**
*
* \brief
*  Performs the initialization required to scan the specified widget.
*
* \details
*  This function prepares the component to scan all sensors in the specified
*  widget, by executing the following tasks.
*    1. Re-initialize the hardware if it is not configured to perform the
*       sensing method used by the specified widget, this happens only if the
*       CSD and CSX methods are used in the component.
*    2. Initialize the hardware with specific sensing configuration (e.g.
*       sensor clock, scan resolution) used by the widget.
*    3. Disconnect all previously connected electrodes, if the electrodes
*       connected by the key_touch_CSDSetupWidgetExt(),
*       key_touch_CSXSetupWidgetExt() or key_touch_CSDConnectSns()
*       functions and not disconnected.
*
*  This function does not start sensor scanning, the key_touch_Scan()
*  function must be called to start the scan sensors in the widget. If this
*  function is called more than once, it does not break the component operation,
*  but only the last initialized widget is in effect.

*
* \param wdgtIndex
*  Specify the ID number of the widget to be initialized for scanning.
*  A macro for the widget ID can be found in the
*  key_touch Configuration header file defined as
*  key_touch_<WidgetName>_WDGT_ID
*
* \return
*  Returns the status of the widget setting up operation:
*    - CYRET_SUCCESS if the operation is successfully completed.
*    - CYRET_BAD_PARAM if the widget is invalid or if the specified widget is
*      disabled
*    - CYRET_INVALID_STATE if the previous scanning is not completed and the
*      hardware block is busy.
*    - CYRET_UNKNOWN if an unknown sensing method is used by the widget or
*      other spurious errors.
*
**********************************************************************************/
cystatus key_touch_SetupWidget(uint32 wdgtIndex)
{
    cystatus widgetStatus;

    if (key_touch_WDGT_SW_STS_BUSY == (key_touch_dsRam.status & key_touch_WDGT_SW_STS_BUSY))
    {
        /* Previous widget is being scanned. Return error. */
        widgetStatus = CYRET_INVALID_STATE;
    }
    /*
     *  Check if widget id is valid, specified widget is enabled and widget did not
     *  detect any fault conditions if BIST is enabled. If all conditions are met,
     *  set widgetStatus as good, if not, set widgetStatus as bad.
     */
    else if ((key_touch_TOTAL_SLOTS > wdgtIndex) &&
        (0uL != key_touch_GET_WIDGET_EN_STATUS(wdgtIndex)))

    {
        widgetStatus = CYRET_SUCCESS;
    }
    else
    {
        widgetStatus = CYRET_BAD_PARAM;
    }

    /*
     * Check widgetStatus flag that is set earlier, if flag is good, then set up only
     * widget
     */
    if (CYRET_SUCCESS == widgetStatus)
    {
        /*  Check if CSD2X is enabled   */
        #if (key_touch_ENABLE == key_touch_CSD2X_EN)

            widgetStatus = key_touch_SetupWidget2x(wdgtIndex);

        #elif (key_touch_ENABLE == key_touch_CSD_CSX_EN)
            /*  Check widget sensing method is CSX and call CSX APIs    */
            if (key_touch_SENSE_METHOD_CSX_E ==
                key_touch_GET_SENSE_METHOD(&key_touch_dsFlash.wdgtArray[wdgtIndex]))
            {
                /*  Set up widget for CSX scan  */
                key_touch_CSXSetupWidget(wdgtIndex);
            }
            /*  Check widget sensing method is CSD and call appropriate API */
            else if (key_touch_SENSE_METHOD_CSD_E ==
                     key_touch_GET_SENSE_METHOD(&key_touch_dsFlash.wdgtArray[wdgtIndex]))
            {
                /*  Set up widget for CSD scan  */
                key_touch_CSDSetupWidget(wdgtIndex);
            }
            else
            {
                /*  Sensing method is invalid, return error to caller  */
                widgetStatus = CYRET_UNKNOWN;
            }
        #elif (key_touch_ENABLE == key_touch_CSD_EN)
            /*  Set up widget for scan */
            key_touch_CSDSetupWidget(wdgtIndex);
        #elif (key_touch_ENABLE == key_touch_CSX_EN)
            /*  Set up widgets for scan     */
            key_touch_CSXSetupWidget(wdgtIndex);
        #else
            widgetStatus = CYRET_UNKNOWN;
            #error "No sensing method enabled, component cannot work in this mode"
        #endif  /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
    }

    return (widgetStatus);
}


/*******************************************************************************
* Function Name: key_touch_Scan
****************************************************************************//**
*
* \brief
*  Initiates scan of all sensors in the widget which is initialized by
*  key_touch_SetupWidget(), if the no scan is in progress.
*
* \details
*  This function should be called only after the key_touch_SetupWidget()
*  function is called to start the scanning of the sensors in the widget. The
*  status of a sensor scan must be checked using the key_touch_IsBusy()
*  API prior to starting a next scan or setting up another widget.
*
* \return
*  Returns the status of the scan initiation operation:
*    - CYRET_SUCCESS if scanning is successfully started.
*    - CYRET_INVALID_STATE if the previous scanning is not completed and the
*      hardware block is busy.
*    - CYRET_UNKNOWN if an unknown sensing method is used by the widget.
*
********************************************************************************/
cystatus key_touch_Scan(void)
{
    cystatus scanStatus = CYRET_SUCCESS;

    if (key_touch_WDGT_SW_STS_BUSY == (key_touch_dsRam.status & key_touch_WDGT_SW_STS_BUSY))
    {
        /* Previous widget is being scanned. Return error. */
        scanStatus = CYRET_INVALID_STATE;
    }
    else
    {
        /*  If CSD2X is enabled, call CSD2X scan    */
    #if (key_touch_ENABLE == key_touch_CSD2X_EN)
        scanStatus = key_touch_Scan2x();

    /*  If both CSD and CSX are enabled, call scan API based on widget sensing method    */
    #elif (key_touch_ENABLE == key_touch_CSD_CSX_EN)
        /*  Check widget sensing method and call appropriate APIs   */
        switch (key_touch_currentSenseMethod)
        {
            case key_touch_SENSE_METHOD_CSX_E:
                key_touch_CSXScan();
                break;

            case key_touch_SENSE_METHOD_CSD_E:
                 key_touch_CSDScan();
                break;

            default:
                scanStatus = CYRET_UNKNOWN;
                break;
        }

    /*  If only CSD is enabled, call CSD scan   */
    #elif (key_touch_ENABLE == key_touch_CSD_EN)
        key_touch_CSDScan();

    /*  If only CSX is enabled, call CSX scan   */
    #elif (key_touch_ENABLE == key_touch_CSX_EN)
        key_touch_CSXScan();

    #else
        scanStatus = CYRET_UNKNOWN;
        #error "No sensing method enabled, component cannot work in this mode"
    #endif  /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
    }

    return (scanStatus);
}


/*******************************************************************************
* Function Name: key_touch_ScanAllWidgets
****************************************************************************//**
*
* \brief
*  Initializes the first enabled widget and scans of all the sensors in the
*  widget, then the same process is repeated for all widgets in the component.
*  I.e. scan all the widgets in the component.
*
* \details
*  This function initializes a widget and scans all the sensors in the widget,
*  and then repeats the same for all the widgets in the component. The tasks of
*  the key_touch_SetupWidget() and key_touch_Scan() functions are
*  executed by these functions. The status of a sensor scan must be checked
*  using the key_touch_IsBusy() API prior to starting a next scan
*  or setting up another widget.
*
* \return
*  Returns the status of operation:
*    - CYRET_SUCCESS if scanning is successfully started.
*    - CYRET_BAD_PARAM if all the widgets are disabled.
*    - CYRET_INVALID_STATE if the previous scanning is not completed and the HW block is busy.
*    - CYRET_UNKNOWN if there are unknown errors.
*
*******************************************************************************/
cystatus key_touch_ScanAllWidgets(void)
{
    cystatus scanStatus = CYRET_UNKNOWN;

    uint32 wdgtIndex;

    if (key_touch_SW_STS_BUSY == (key_touch_dsRam.status & key_touch_SW_STS_BUSY))
    {
        /* Previous widget is being scanned. Return error. */
        scanStatus = CYRET_INVALID_STATE;
    }
    else
    {
        /*
         *  Set up widget first widget.
         *  If widget returned error, set up next, continue same until widget does not return error.
         */
        for (wdgtIndex = 0u;
             wdgtIndex < key_touch_TOTAL_SLOTS;
             wdgtIndex++)
        {

            scanStatus = key_touch_SetupWidget(wdgtIndex);

            if (CYRET_SUCCESS == scanStatus)
            {
                #if (0u != (key_touch_TOTAL_SLOTS - 1u))
                    /* If there are more than one widget to be scanned, request callback to scan next widget */
                    if ((key_touch_TOTAL_SLOTS - 1u) > wdgtIndex)
                    {
                         /* Request callback to scan next widget in ISR */
                        key_touch_requestScanAllWidget = key_touch_ENABLE;
                    }
                    else
                    {
                        /* Request to exit in ISR (Do not scan the next widgets) */
                        key_touch_requestScanAllWidget = key_touch_DISABLE;
                    }
                #else
                    {
                        /* Request to exit in ISR (We have only one widget) */
                        key_touch_requestScanAllWidget = key_touch_DISABLE;
                    }
                #endif  /* (0u != (key_touch_TOTAL_SLOTS - 1u)) */

                /*  Initiate scan and quit loop */
                scanStatus = key_touch_Scan();

                break;
            }
        }
    }

    return (scanStatus);
}


/*******************************************************************************
* Function Name: key_touch_SsInitialize
****************************************************************************//**
*
* \brief
*   Performs hardware and firmware initialization required for proper operation
*   of the key_touch component. This function is called from
*   the key_touch_Start() API prior to calling any other APIs of the component.
*
* \details
*   Performs hardware and firmware initialization required for proper operation
*   of the key_touch component. This function is called from
*   the key_touch_Start() API prior to calling any other APIs of the component.
*   1. The function initializes immunity offsets when the frequency hopping is
*      enabled.
*   2. Depending on the configuration, the function initializes the CSD block
*      for the CSD2X, CSD, CSX, or CSD+CSX modes.
*   3. The function updates the dsRam.wdgtWorking variable with 1 when Self Test
*      is enabled.
*
*   Calling the key_touch_Start API is the recommended method to initialize
*   the key_touch component at power-up. The key_touch_SsInitialize()
*   API should not be used for initialization, resume, or wake-up operations.
*   The dsRam.wdgtWorking variable is updated.
*
* \return status
*   Returns status of operation:
*   - Zero        - Indicates successful initialization.
*   - Non-zero    - One or more errors occurred in the initialization process.
*
*******************************************************************************/
cystatus key_touch_SsInitialize(void)
{
    cystatus initStatus = CYRET_SUCCESS;

    #if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
        key_touch_immunity[key_touch_FREQ_CHANNEL_0] = (uint8)CY_GET_REG32(CY_SYS_CLK_IMO_TRIM1_PTR);
        if (key_touch_COARSE_TRIM_THRESHOLD_1 > key_touch_immunity[key_touch_FREQ_CHANNEL_0])
        {
            key_touch_immunity[key_touch_FREQ_CHANNEL_1] =
            key_touch_immunity[key_touch_FREQ_CHANNEL_0] + key_touch_FREQUENCY_OFFSET_5;
            key_touch_immunity[key_touch_FREQ_CHANNEL_2] =
            key_touch_immunity[key_touch_FREQ_CHANNEL_0] + key_touch_FREQUENCY_OFFSET_10;
        }
        else if (key_touch_COARSE_TRIM_THRESHOLD_2 > key_touch_immunity[key_touch_FREQ_CHANNEL_0])
        {
            key_touch_immunity[key_touch_FREQ_CHANNEL_1] =
            key_touch_immunity[key_touch_FREQ_CHANNEL_0] - key_touch_FREQUENCY_OFFSET_5;
            key_touch_immunity[key_touch_FREQ_CHANNEL_2] =
            key_touch_immunity[key_touch_FREQ_CHANNEL_0] + key_touch_FREQUENCY_OFFSET_5;
        }
        else
        {
            key_touch_immunity[key_touch_FREQ_CHANNEL_1] =
            key_touch_immunity[key_touch_FREQ_CHANNEL_0] - key_touch_FREQUENCY_OFFSET_5;
            key_touch_immunity[key_touch_FREQ_CHANNEL_2] =
            key_touch_immunity[key_touch_FREQ_CHANNEL_0] - key_touch_FREQUENCY_OFFSET_10;
        }
    #endif /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */

    #if (key_touch_DISABLE == key_touch_CSDV2)
        key_touch_SsTrimIdacs();
    #endif /* (key_touch_ENABLE == key_touch_CSDV2) */

    #if((key_touch_ENABLE == key_touch_CSD_EN) ||\
    ((key_touch_ENABLE == key_touch_CSX_EN) && (key_touch_ENABLE == key_touch_CSDV2)))
        key_touch_SsInitializeSourceSenseClk();
    #endif /* ((key_touch_ENABLE == key_touch_CSD_EN) ||\
              ((key_touch_ENABLE == key_touch_CSX_EN) && (key_touch_ENABLE == key_touch_CSDV2))) */

    /*
     *  Check if CSD2X is enabled, if yes, initialize key_touch component
     *  for CSD2x operation
     */
    #if (key_touch_ENABLE == key_touch_CSD2X_EN)
        /*
         *  Check if CSX or CSD enable along with CSD2X, if yes, provide the error
         *  message as CSD2X can not coexist with CSD or CSX
         */
        #if (key_touch_ENABLE == key_touch_CSX_EN)
            #error "CSD2X and CSX can not be enabled together"
            initStatus = CYRET_UNKNOWN;
        #elif (key_touch_ENABLE == key_touch_CSD_EN)
            #error "CSD2X and CSD can not be enabled together"
            initStatus = CYRET_UNKNOWN;
        #endif /* (key_touch_CSX_EN == key_touch_ENABLE) */

        /* Initialize both CSD blocks for CSD2X scanning    */
        key_touch_CSD2XInitialize();

    #elif ((key_touch_ENABLE == key_touch_CSD_CSX_EN) || \
            (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
            (key_touch_ENABLE == key_touch_ADC_EN))

        /* Set all IO states to default state  */
        key_touch_SsSetIOsInDefaultState();
        /*
         * CSD hardware block is initialized in the Setup Widget based
         * on widget sensing method. Release previously captured HW resources
         * if it is second call of key_touch_Start() function.
         */
        key_touch_SsSwitchSensingMode(key_touch_UNDEFINED_E);
    #elif (key_touch_ENABLE == key_touch_CSD_EN)
        /*  Initialize CSD block for CSD scanning   */
        key_touch_SsCSDInitialize();

    #elif (key_touch_ENABLE == key_touch_CSX_EN)
        /*  Initialize CSD block for CSX scanning   */
        key_touch_CSXInitialize();

    #else
        #error "No sensing method enabled, component cannot work in this mode"
        initStatus = CYRET_UNKNOWN;
    #endif  /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

    return (initStatus);
}


/*******************************************************************************
* Function Name: key_touch_SetPinState
****************************************************************************//**
*
* \brief
*  Sets the state (drive mode and output state) of port pin used by a sensor.
*  The possible states are GND, Shield, High-Z, Tx or Rx, sensor. If the sensor
*  specified in the input parameter is a ganged sensor, then state of all pins
*  associated with ganged sensor is updated.
*
* \details
*  This function sets a specified state to the specified sensor pin. If the
*  sensor is a ganged sensor, then the specified state is also set for all
*  ganged pins of this sensor. Scanning should be completed before calling
*  this API.
*
*  The key_touch_SHIELD and key_touch_SENSOR states are not
*  allowed if there is no CSD widget configured in the user¡¯s project.
*  The key_touch_TX_PIN and key_touch_RX_PIN states are not
*  allowed if there is no CSX widget configured in the user¡¯s project.
*
*  It is not recommended to call this function directly from the application
*  layer. This function should be used to implement only the user¡¯s specific
*  use cases. Functions that perform a setup and scan of the sensor/widget
*  automatically set needed pin states. They do not take into account changes
*  in the design made by the key_touch_SetPinState() function.
*
*  \param wdgtIndex
*  Specify the ID number of the widget to change the pin state of the specified
*  sensor.
*  A macro for the widget ID can be found in the key_touch Configuration header
*  file defined as key_touch_<WidgetName>_WDGT_ID.
*
*  \param snsIndex
*  Specify the ID number of the sensor within the widget to change its pin
*  state.
*  A macro for the sensor ID within a specified widget can be found in the
*  key_touch Configuration header file defined as
*  key_touch_<WidgetName>_SNS<SensorNumber>_ID
*
*  \param state
*   Specify the state of the sensor that needs to be set:
*     1. key_touch_GROUND - The pin is connected to ground.
*     2. key_touch_HIGHZ - The drive mode of the pin is set to High-Z
*        Analog.
*     3. key_touch_SHIELD - The shield signal is routed to the pin (only
*        in CSD sensing method when shield electrode is enabled).
*     4. key_touch_SENSOR ¨C The pin is connected to the scanning bus
*        (only in CSD sensing method).
*     5. key_touch_TX_PIN ¨C The TX signal is routed to the sensor
*        (only in CSX sensing method).
*     6. key_touch_RX_PIN ¨C The pin is connected to the scanning bus
*        (only in CSX sensing method).
*
*******************************************************************************/
void key_touch_SetPinState(uint32 wdgtIndex, uint32 snsIndex, uint32 state)
{
    key_touch_FLASH_IO_STRUCT const *curSnsIOPtr;
    #if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
        key_touch_FLASH_SNS_STRUCT const *curFlashSnsPtr;
        uint32 tempVal;
    #endif /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) */
    uint32 newRegisterValue;
    uint8  interruptState;
    uint32 pinHSIOMShift;
    uint32 pinModeShift;

    #if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
        /* Check ganged sns flag  */
        if (key_touch_GANGED_SNS_MASK == (key_touch_dsFlash.wdgtArray[wdgtIndex].staticConfig &
            key_touch_GANGED_SNS_MASK))
        {
            curFlashSnsPtr = key_touch_dsFlash.wdgtArray[wdgtIndex].ptr2SnsFlash;
            curFlashSnsPtr += snsIndex;
            curSnsIOPtr = &key_touch_ioList[curFlashSnsPtr->firstPinId];

            /* Get number of ganged pins  */
            tempVal = curFlashSnsPtr->numPins;
        }
        else
        {
            curSnsIOPtr = (key_touch_FLASH_IO_STRUCT const *)
                                    key_touch_dsFlash.wdgtArray[wdgtIndex].ptr2SnsFlash + snsIndex;
            /* There are no ganged pins */
            tempVal = 1u;
        }
    #else
        curSnsIOPtr = (key_touch_FLASH_IO_STRUCT const *)
                                    key_touch_dsFlash.wdgtArray[wdgtIndex].ptr2SnsFlash + snsIndex;
    #endif  /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) */

    #if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
        /* Reconfigure all ganged sensors  */
        do
        {
    #endif  /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) */

            /* Get HSIOM and port mode shifts */
            pinHSIOMShift = (uint32)curSnsIOPtr->hsiomShift;
            pinModeShift = (uint32)curSnsIOPtr->shift;

            /* Reset HSIOM register */
            CY_SET_REG32(curSnsIOPtr->hsiomPtr, CY_GET_REG32(curSnsIOPtr->hsiomPtr) & ~(key_touch_HSIOM_SEL_MASK << pinHSIOMShift));

            switch (state)
            {
            case key_touch_GROUND:
                interruptState = CyEnterCriticalSection();

                /* Update port configuration register (drive mode) for sensor */
                newRegisterValue = CY_GET_REG32(curSnsIOPtr->pcPtr);
                newRegisterValue &= ~(key_touch_GPIO_PC_MASK << pinModeShift);
                newRegisterValue |= (key_touch_SNS_GROUND_CONNECT << pinModeShift);
                CY_SET_REG32(curSnsIOPtr->pcPtr, newRegisterValue);

                CyExitCriticalSection(interruptState);

                /* Set logic 0 to port data register */
                CY_SET_REG32(curSnsIOPtr->drPtr, CY_GET_REG32(curSnsIOPtr->drPtr) & (uint32)~(uint32)((uint32)1u << curSnsIOPtr->drShift));
                break;

            case key_touch_HIGHZ:
                interruptState = CyEnterCriticalSection();

                /* Update port configuration register (drive mode) for sensor */
                newRegisterValue = CY_GET_REG32(curSnsIOPtr->pcPtr);
                newRegisterValue &= ~(key_touch_GPIO_PC_MASK << pinModeShift);
                CY_SET_REG32(curSnsIOPtr->pcPtr, newRegisterValue);

                CyExitCriticalSection(interruptState);

                /* Set logic 0 to port data register */
                CY_SET_REG32(curSnsIOPtr->drPtr, CY_GET_REG32(curSnsIOPtr->drPtr) & (uint32)~(uint32)((uint32)1u << curSnsIOPtr->drShift));
                break;

            #if (key_touch_ENABLE == key_touch_CSD_SHIELD_EN)
                case key_touch_SHIELD:
                    /* Set drive mode to Analog */
                    CY_SET_REG32(curSnsIOPtr->pcPtr, CY_GET_REG32(curSnsIOPtr->pcPtr) &
                               ~(key_touch_GPIO_PC_MASK <<(curSnsIOPtr->shift)));

                    /* Set appropriate bit in HSIOM register to configure pin to shield mode */
                    CY_SET_REG32(curSnsIOPtr->hsiomPtr, CY_GET_REG32(curSnsIOPtr->hsiomPtr) |
                                                       (key_touch_HSIOM_SEL_CSD_SHIELD << pinHSIOMShift));
                    break;
            #endif  /* (key_touch_ENABLE == key_touch_CSD_SHIELD_EN) */

            #if ((key_touch_ENABLE == key_touch_CSD_EN) || \
                 (key_touch_ENABLE == key_touch_CSD_CSX_EN))
                case key_touch_SENSOR:
                    /* Enable sensor */
                    key_touch_CSDConnectSns(curSnsIOPtr);
                    break;
            #endif  /* ((key_touch_ENABLE == key_touch_CSD_EN) || \
                        (key_touch_ENABLE == key_touch_CSD_CSX_EN)) */

            #if ((key_touch_ENABLE == key_touch_CSX_EN) || \
                 (key_touch_ENABLE == key_touch_CSD_CSX_EN))
                case key_touch_TX_PIN:
                    CY_SET_REG32(curSnsIOPtr->hsiomPtr, CY_GET_REG32(curSnsIOPtr->hsiomPtr) | (key_touch_HSIOM_SEL_CSD_SENSE << pinHSIOMShift));
                    CY_SET_REG32(curSnsIOPtr->pcPtr, CY_GET_REG32(curSnsIOPtr->pcPtr) | (key_touch_GPIO_STRGDRV << pinModeShift));
                    break;

                case key_touch_RX_PIN:
                    CY_SET_REG32(curSnsIOPtr->hsiomPtr, CY_GET_REG32(curSnsIOPtr->hsiomPtr) | (key_touch_HSIOM_SEL_AMUXA << pinHSIOMShift));
                    CY_SET_REG32(curSnsIOPtr->pcPtr, CY_GET_REG32(curSnsIOPtr->pcPtr) & ~(key_touch_GPIO_PC_MASK << pinModeShift));
                    break;
            #endif  /* ((key_touch_ENABLE == key_touch_CSX_EN) || \
                        (key_touch_ENABLE == key_touch_CSD_CSX_EN)) */

            default:
                /* Wrong input */
                break;
            }

    #if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
            curSnsIOPtr++;
            tempVal--;
        } while (0u != tempVal);
    #endif  /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN) */
}


#if ((key_touch_ENABLE == key_touch_CSD_CSX_EN) || \
     (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
     (key_touch_ENABLE == key_touch_ADC_EN))

    #if (key_touch_ENABLE == key_touch_CSD_EN)
        /*******************************************************************************
        * Function Name: key_touch_SsCSDDisableMode
        ****************************************************************************//**
        *
        * \brief
        *  This function disables CSD mode.
        *
        * \details
        *  To disable CSD mode the following tasks are performed:
        *  1. Disconnect Cmod from AMUXBUS-A;
        *  2. Disconnect previous CSX electrode if it has been connected;
        *  3. Disconnect Csh from AMUXBUS-B;
        *  4. Disable Shield Electrodes.
        *
        *******************************************************************************/
        static void key_touch_SsCSDDisableMode(void)
        {
            uint32 newRegValue;

            /* Disconnect Cmod from AMUXBUS-A using HSIOM registers */
            newRegValue = CY_GET_REG32(key_touch_CMOD_HSIOM_PTR);
            newRegValue &= (uint32)(~(uint32)key_touch_CMOD_HSIOM_MASK);
            CY_SET_REG32(key_touch_CMOD_HSIOM_PTR, newRegValue);

            #if ((key_touch_ENABLE == key_touch_CSDV2) && \
                 ((key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) && \
                 (key_touch_ENABLE == key_touch_CSD_DEDICATED_IDAC_COMP_EN)))
                /* Disconnect IDACA and IDACB */
                newRegValue = CY_GET_REG32(key_touch_SW_REFGEN_SEL_PTR);
                newRegValue &= (uint32)(~key_touch_SW_REFGEN_SEL_SW_IAIB_MASK);
                CY_SET_REG32(key_touch_SW_REFGEN_SEL_PTR, newRegValue);
            #endif /* ((key_touch_ENABLE == key_touch_CSDV2) && \
                       ((key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) && \
                       (key_touch_ENABLE == key_touch_CSD_DEDICATED_IDAC_COMP_EN))) */

            /* Disconnect previous CSD electrode if it has been connected */
            key_touch_SsCSDElectrodeCheck();

            /* Disconnect Csh from AMUXBUS-B */
            #if ((key_touch_ENABLE == key_touch_CSD_SHIELD_EN) && \
                 (key_touch_ENABLE == key_touch_CSD_SHIELD_TANK_EN))
                newRegValue = CY_GET_REG32(key_touch_CSH_HSIOM_PTR);
                newRegValue &= (uint32)(~(uint32)(key_touch_CSH_TO_AMUXBUS_B_MASK << key_touch_CSH_HSIOM_SHIFT));
                CY_SET_REG32(key_touch_CSH_HSIOM_PTR, newRegValue);
            #endif /* ((key_touch_ENABLE == key_touch_CSD_SHIELD_EN) && \
                       (key_touch_ENABLE == key_touch_CSD_SHIELD_TANK_EN)) */

            #if ((key_touch_ENABLE == key_touch_CSD_SHIELD_EN) && \
                 (0u != key_touch_CSD_TOTAL_SHIELD_COUNT))
                key_touch_SsCSDDisableShieldElectrodes();
            #endif /* ((key_touch_ENABLE == key_touch_CSD_SHIELD_EN) && \
                       (0u != key_touch_CSD_TOTAL_SHIELD_COUNT)) */
        }
    #endif /* (key_touch_ENABLE == key_touch_CSD_EN) */


    #if (key_touch_ENABLE == key_touch_CSX_EN)
        /*******************************************************************************
        * Function Name: key_touch_SsDisableCSXMode
        ****************************************************************************//**
        *
        * \brief
        *  This function disables CSX mode.
        *
        * \details
        *  To disable CSX mode the following tasks are performed:
        *  1. Disconnect CintA and CintB from AMUXBUS-A
        *  2. Disconnect previous CSX electrode if it has been connected
        *
        *******************************************************************************/
        static void key_touch_SsDisableCSXMode(void)
        {
            uint32 newRegValue;

            /*  Disconnect CintA from AMUXBUS-A using HSIOM registers.   */
            newRegValue = CY_GET_REG32(key_touch_CintA_HSIOM_PTR);
            newRegValue &= (uint32)(~(uint32)key_touch_CintA_HSIOM_MASK);
            CY_SET_REG32(key_touch_CintA_HSIOM_PTR, newRegValue);

            /*  Disconnect CintB from AMUXBUS-A using HSIOM registers.   */
            newRegValue = CY_GET_REG32(key_touch_CintB_HSIOM_PTR);
            newRegValue &= (uint32)(~(uint32)key_touch_CintB_HSIOM_MASK);
            CY_SET_REG32(key_touch_CintB_HSIOM_PTR, newRegValue);

            /* Disconnect previous CSX electrode if it has been connected */
            key_touch_CSXElectrodeCheck();
        }
    #endif /* (key_touch_ENABLE == key_touch_CSX_EN) */


    /*******************************************************************************
    * Function Name: key_touch_SsSwitchSensingMode
    ****************************************************************************//**
    *
    * \brief
    *  This function changes the mode for case when both CSD and CSX widgets are
    *  scanned.
    *
    * \details
    *  To switch to the CSD mode the following tasks are performed:
    *  1. Disconnect CintA and CintB from AMUXBUS-A;
    *  2. Disconnect previous CSD electrode if it has been connected;
    *  3. Initialize CSD mode.
    *
    *  To switch to the CSX mode the following tasks are performed:
    *  1. Disconnect Cmod from AMUXBUS-A;
    *  2. Disconnect previous CSX electrode if it has been connected;
    *  3. Initialize CSX mode.
    *
    * \param mode Specifies the scan mode:
    *           -  (1) key_touch_SENSE_METHOD_CSD_E
    *           -  (2) key_touch_SENSE_METHOD_CSX_E
    *           -  (3) key_touch_SENSE_METHOD_BIST_E
    *
    *******************************************************************************/
    void key_touch_SsSwitchSensingMode(key_touch_SENSE_METHOD_ENUM mode)
    {
        if (key_touch_currentSenseMethod != mode)
        {
            /* The requested mode differes to the current one. Disable the current mode */
            if (key_touch_SENSE_METHOD_CSD_E ==  key_touch_currentSenseMethod)
            {
                #if (key_touch_ENABLE == key_touch_CSD_EN)
                    key_touch_SsCSDDisableMode();
                #endif /* (key_touch_ENABLE == key_touch_CSD_EN) */
            }
            else if (key_touch_SENSE_METHOD_CSX_E ==  key_touch_currentSenseMethod)
            {
                #if (key_touch_ENABLE == key_touch_CSX_EN)
                    key_touch_SsDisableCSXMode();
                #endif /* (key_touch_ENABLE == key_touch_CSX_EN) */
            }
            else if (key_touch_SENSE_METHOD_BIST_E ==  key_touch_currentSenseMethod)
            {
                #if (key_touch_ENABLE == key_touch_SELF_TEST_EN)
                    key_touch_BistDisableMode();
                #endif /* (key_touch_ENABLE == key_touch_CSX_EN) */
            }
            else
            {
                #if (key_touch_ENABLE == key_touch_ADC_EN)
                    /* Release ADC resources */
                    (void)key_touch_AdcReleaseResources();
                #endif /* (key_touch_ENABLE == key_touch_ADC_EN) */
            }

            /* Enable the specified mode */
            if (key_touch_SENSE_METHOD_CSD_E == mode)
            {
                #if (key_touch_ENABLE == key_touch_CSD_EN)
                    /* Initialize CSD mode to guarantee configured CSD mode */
                    key_touch_SsCSDInitialize();
                    key_touch_currentSenseMethod = key_touch_SENSE_METHOD_CSD_E;
                #endif /* (key_touch_ENABLE == key_touch_CSD_EN) */
            }
            else if (key_touch_SENSE_METHOD_CSX_E == mode)
            {
                #if (key_touch_ENABLE == key_touch_CSX_EN)
                    /* Initialize CSX mode to guarantee configured CSX mode */
                    key_touch_CSXInitialize();
                    key_touch_currentSenseMethod = key_touch_SENSE_METHOD_CSX_E;
                #endif /* (key_touch_ENABLE == key_touch_CSX_EN) */
            }
            else if (key_touch_SENSE_METHOD_BIST_E == mode)
            {
                #if (key_touch_ENABLE == key_touch_SELF_TEST_EN)
                    /* Initialize CSX mode to guarantee configured CSX mode */
                    key_touch_BistInitialize();
                    key_touch_currentSenseMethod = key_touch_SENSE_METHOD_BIST_E;
                #endif /* (key_touch_ENABLE == key_touch_CSX_EN) */
            }
            else
            {
                key_touch_currentSenseMethod = key_touch_UNDEFINED_E;
            }
        }
    }
#endif  /* ((key_touch_ENABLE == key_touch_CSD_CSX_EN) || \
            (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
            (key_touch_ENABLE == key_touch_ADC_EN)) */

#if ((key_touch_ENABLE == key_touch_CSX_EN) || \
     (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
     (key_touch_ENABLE == key_touch_ADC_EN))
    /*******************************************************************************
    * Function Name: key_touch_SsSetIOsInDefaultState
    ****************************************************************************//**
    *
    * \brief
    *   Sets all electrodes into a default state.
    *
    * \details
    *   Sets all IOs into a default state:
    *   - HSIOM   - Disconnected, the GPIO mode.
    *   - DM      - Strong drive.
    *   - State   - Zero.
    *
    *   It is not recommended to call this function directly from the application
    *   layer.
    *
    *******************************************************************************/
    void key_touch_SsSetIOsInDefaultState(void)
    {
        key_touch_FLASH_IO_STRUCT const *ioPtr = &key_touch_ioList[0u];
        uint32 loopIndex;
        uint32 regValue;

        /*  Loop through all electrodes */
        for (loopIndex = 0u; loopIndex < key_touch_TOTAL_ELECTRODES; loopIndex++)
        {
            /*  1. Disconnect HSIOM
                2. Set strong DM
                3. Set pin state to logic 0     */
            regValue = CY_GET_REG32 (ioPtr->hsiomPtr);
            regValue &= ~(ioPtr->hsiomMask);
            CY_SET_REG32 (ioPtr->hsiomPtr, regValue);

            regValue = CY_GET_REG32 (ioPtr->pcPtr);
            regValue &= ~(key_touch_GPIO_PC_MASK << ioPtr->shift);
            regValue |=  (key_touch_GPIO_STRGDRV << ioPtr->shift);
            CY_SET_REG32 (ioPtr->pcPtr, regValue);

            regValue = CY_GET_REG32 (ioPtr->drPtr);
            regValue &= ~(ioPtr->mask);
            CY_SET_REG32 (ioPtr->drPtr, regValue);

            /*  Get next electrode  */
            ioPtr++;
        }
    }
#endif /* ((key_touch_ENABLE == key_touch_CSX_EN) || \
          (key_touch_ENABLE == key_touch_SELF_TEST_EN) || \
          (key_touch_ENABLE == key_touch_ADC_EN)) */


#if (key_touch_ENABLE == key_touch_ADC_EN)
/*******************************************************************************
* Function Name: key_touch_SsReleaseResources()
****************************************************************************//**
*
* \brief
*  This function sets the resources that do not belong to the CSDv2 HW block to
*  default state.
*
* \details
*  The function performs following tasks:
*  1. Checks if CSD block busy and returns error if it is busy
*  2. Disconnects integration capacitors (CintA, CintB for CSX mode and
*     Cmod for CSD mode)
*  3. Disconnect electroded if they have been connected.
*
* \return
*   Returns the status of operation:
*   - Zero        - Resources released successfully.
*   - Non-zero    - One or more errors occurred in releasing process.
*
*******************************************************************************/
cystatus key_touch_SsReleaseResources(void)
{
    cystatus busyStatus = CYRET_SUCCESS;

    if (key_touch_SW_STS_BUSY == (key_touch_dsRam.status & key_touch_SW_STS_BUSY))
    {
        /* Previous widget is being scanned. Return error. */
        busyStatus = CYRET_INVALID_STATE;
    }
    else
    {
        #if (key_touch_ENABLE == key_touch_CSX_EN)
            key_touch_SsDisableCSXMode();
        #endif /* (key_touch_ENABLE == key_touch_CSX_EN) */

        #if (key_touch_ENABLE == key_touch_CSD_EN)
            key_touch_SsCSDDisableMode();
        #endif /* (key_touch_ENABLE == key_touch_CSD_EN) */

        #if (key_touch_ENABLE == key_touch_SELF_TEST_EN)
            key_touch_BistDisableMode();
        #endif /* (key_touch_ENABLE == key_touch_SELF_TEST_EN) */

        #if ((key_touch_ENABLE == key_touch_CSD_EN) && \
             (key_touch_ENABLE == key_touch_CSD_SHIELD_EN) &&  \
             (key_touch_SNS_CONNECTION_SHIELD == key_touch_CSD_INACTIVE_SNS_CONNECTION))
            key_touch_SsSetIOsInDefaultState();
        #endif /* ((key_touch_ENABLE == key_touch_CSD_EN) && \
             (key_touch_DISABLE != key_touch_CSD_SHIELD_EN) &&  \
             (key_touch_SNS_CONNECTION_SHIELD == key_touch_CSD_INACTIVE_SNS_CONNECTION)) */

        /*
         * Reset of the currentSenseMethod variable to make sure that the next
         * call of SetupWidget() API setups the correct widget mode
         */
        key_touch_currentSenseMethod = key_touch_UNDEFINED_E;
    }

    return busyStatus;
}
#endif /* (key_touch_ENABLE == key_touch_ADC_EN) */


/*******************************************************************************
* Function Name: key_touch_SsPostAllWidgetsScan
****************************************************************************//**
*
* \brief
*   The ISR function for multiple widget scanning implementation.
*
* \details
*   This is the function used by the key_touch ISR to implement multiple widget
*   scanning.
*   Should not be used by the application layer.
*
*******************************************************************************/
void key_touch_SsPostAllWidgetsScan(void)
{
    #if (key_touch_DISABLE == key_touch_CSD2X_EN)
        /*
        *   1. Increment widget index
        *   2. Check if all widgets are scanned
        *   3. If all widgets are not scanned, set up and scan next widget
        */
        #if (1u != key_touch_TOTAL_WIDGETS)
            cystatus postScanStatus;

            do
            {
                key_touch_widgetIndex++;

                postScanStatus = key_touch_SetupWidget((uint32)key_touch_widgetIndex);

                if (CYRET_SUCCESS == postScanStatus)
                {
                    if((key_touch_TOTAL_WIDGETS - 1u) == key_touch_widgetIndex)
                    {
                        /* The last widget will be scanned. Reset flag to skip configuring the next widget setup in ISR. */
                        key_touch_requestScanAllWidget = key_touch_DISABLE;
                    }
                    (void)key_touch_Scan();
                }
                else if((key_touch_TOTAL_WIDGETS - 1u) == key_touch_widgetIndex)
                {
                    #if ((key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN) && \
                         (key_touch_ENABLE == key_touch_CSD_EN))
                        if (key_touch_SENSE_METHOD_CSD_E ==
                             key_touch_GET_SENSE_METHOD(&key_touch_dsFlash.wdgtArray[key_touch_widgetIndex]))
                        {
                            /*  Disable the CSD block */
                            CY_SET_REG32(key_touch_CONFIG_PTR, key_touch_configCsd);
                        }
                    #endif /* ((key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN) && \
                               (key_touch_ENABLE == key_touch_CSD_EN)) */

                    /* All widgets are totally processed. Reset BUSY flag */
                    key_touch_dsRam.status &= ~key_touch_SW_STS_BUSY;

                    /* Update status with with the failure */
                    key_touch_dsRam.status &= ~key_touch_STATUS_ERR_MASK;
                    key_touch_dsRam.status |= ((postScanStatus & key_touch_STATUS_ERR_SIZE) << key_touch_STATUS_ERR_SHIFT);

                    /* Set postScanStatus to exit the while loop */
                    postScanStatus = CYRET_SUCCESS;
                }
                else
                {
                    /* Update status with with the failure. Configure the next widget in while() loop */
                    key_touch_dsRam.status &= ~key_touch_STATUS_ERR_MASK;
                    key_touch_dsRam.status |= ((postScanStatus & key_touch_STATUS_ERR_SIZE) << key_touch_STATUS_ERR_SHIFT);
                }
            } while (CYRET_SUCCESS != postScanStatus);
        #endif /* (1u != key_touch_TOTAL_WIDGETS) */
    #else
        #if (1u != key_touch_TOTAL_SLOTS)
            cystatus postScanStatus = CYRET_SUCCESS;

            do
            {
                if ((key_touch_TOTAL_SLOTS - 1u) > key_touch_slotIndex)
                {
                    key_touch_slotIndex++;
                    postScanStatus = key_touch_SetupWidget((uint32)key_touch_slotIndex);


                    if (CYRET_SUCCESS == postScanStatus)
                    {
                        if((key_touch_TOTAL_SLOTS - 1u) == key_touch_slotIndex)
                        {
                            /* The last slot will be scanned. Reset flag to skip configuring the next widget setup in ISR. */
                            key_touch_requestScanAllWidget = key_touch_DISABLE;
                        }
                        (void)key_touch_Scan();
                    }
                    else if((key_touch_TOTAL_SLOTS - 1u) == key_touch_slotIndex)
                    {
                        #if (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN)
                            /*  Disable the CSD blocks */
                            CY_SET_REG32(key_touch_CSD0_CONFIG_PTR, key_touch_configCsd0);
                            CY_SET_REG32(key_touch_CSD1_CONFIG_PTR, key_touch_configCsd1);
                        #endif /* (key_touch_ENABLE == key_touch_BLOCK_OFF_AFTER_SCAN_EN) */

                        /* All widgets are totally processed. Reset BUSY flag */
                        key_touch_dsRam.status &= ~key_touch_SW_STS_BUSY;

                        /* Update status with with the failure */
                        key_touch_dsRam.status &= ~key_touch_STATUS_ERR_MASK;
                        key_touch_dsRam.status |= ((postScanStatus & key_touch_STATUS_ERR_SIZE) << key_touch_STATUS_ERR_SHIFT);

                        /* Set postScanStatus to exit the while loop */
                        postScanStatus = CYRET_SUCCESS;
                    }
                    else
                    {
                        /* Update status with with the failure. Configure the next widget in while() loop */
                        key_touch_dsRam.status &= ~key_touch_STATUS_ERR_MASK;
                        key_touch_dsRam.status |= ((postScanStatus & key_touch_STATUS_ERR_SIZE) << key_touch_STATUS_ERR_SHIFT);
                    }
                }
            } while (CYRET_SUCCESS != postScanStatus);
        #endif /* (1u != key_touch_TOTAL_SLOTS) */
    #endif /* (key_touch_CSD2X_EN == key_touch_DISABLE) */
}


/*******************************************************************************
* Function Name: key_touch_SsIsrInitialize
****************************************************************************//**
*
* \brief
*   Enables and initializes for the function pointer for a callback for the ISR.
*
* \details
*   The  "address" is a special type cyisraddress defined by Cylib. This function
*   is used by component APIs and should not be used by an application program for
*   proper working of the component.
*
* \param  address The address of the function to be called when interrupt is fired.
*
*******************************************************************************/
void key_touch_SsIsrInitialize(cyisraddress address)
{
#if (key_touch_ENABLE == key_touch_CSD2X_EN)
    key_touch_ISR0_StartEx(address);
    key_touch_ISR1_StartEx(address);
#else
    key_touch_ISR_StartEx(address);
#endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
}


/*******************************************************************************
* Function Name: key_touch_SsSetModClkClockDivider
****************************************************************************//**
*
* \brief
*   Sets the divider values for the modulator clock and then starts
*   the modulator clock.
*
* \details
*   It is not recommended to call this function directly by the application layer.
*   It is used by initialization, widget APIs or wakeup functions to
*   enable the clocks.
*
* \param
*   modClk The divider value for the modulator clock.
*
*******************************************************************************/
void key_touch_SsSetModClkClockDivider(uint32 modClk)
{
#if (key_touch_ENABLE == key_touch_IS_M0S8PERI_BLOCK)
    /*  Stop modulator clock   */
    CY_SET_REG32(key_touch_MODCLK_CMD_PTR,
                 ((uint32)key_touch_ModClk__DIV_ID <<
                 key_touch_MODCLK_CMD_DIV_SHIFT)|
                 ((uint32)key_touch_MODCLK_CMD_DISABLE_MASK));

    /*
     * Set divider value for sense modClk.
     * 1u is subtracted from modClk because Divider register value 0 corresponds
     * to dividing by 1.
     */
    CY_SET_REG32(key_touch_MODCLK_DIV_PTR, ((modClk - 1u) << 8u));

    /*  Check whether previous modulator clock start command has finished. */
    while(0u != (CY_GET_REG32(key_touch_MODCLK_CMD_PTR) & key_touch_MODCLK_CMD_ENABLE_MASK))
    {
        /*  Wait until previous modulator clock start command has finished. */
    }

    /*  Start modulator clock, aligned to HFCLK */
    CY_SET_REG32(key_touch_MODCLK_CMD_PTR,
                 (uint32)(((uint32)key_touch_ModClk__DIV_ID << key_touch_MODCLK_CMD_DIV_SHIFT) |
                  ((uint32)key_touch_ModClk__PA_DIV_ID << key_touch_MODCLK_CMD_PA_DIV_SHIFT) |
                  key_touch_MODCLK_CMD_ENABLE_MASK));
#else
    uint32 newRegValue;

    /* Clear bit to disable ModClk clock. */
    CY_SET_REG32(key_touch_MODCLK_CMD_PTR,
                 CY_GET_REG32(key_touch_MODCLK_CMD_PTR) &
                 (uint32)(~key_touch_ModClk__ENABLE_MASK));

    /*
     * Update ModClk clock divider.
     * 1u is subtracted from modClk because Divider register value has range (0-65535).
     */
    newRegValue = CY_GET_REG32(key_touch_MODCLK_DIV_PTR) & (uint32)(~(uint32)key_touch_ModClk__DIVIDER_MASK);
    newRegValue |= (modClk - 1u);
    CY_SET_REG32(key_touch_MODCLK_DIV_PTR, newRegValue);

    /* Set bit to enable ModClk clock. */
    CY_SET_REG32(key_touch_MODCLK_CMD_PTR,
                 CY_GET_REG32(key_touch_MODCLK_CMD_PTR) |
                key_touch_ModClk__ENABLE_MASK);
#endif /* (key_touch_ENABLE == key_touch_IS_M0S8PERI_BLOCK) */
}


/*******************************************************************************
* Function Name: key_touch_SsSetSnsClockDivider
****************************************************************************//**
*
* \brief
*   Sets the divider values for the sense clock and then starts
*   the sense clock.
*
* \details
*   It is not recommended to call this function directly by the application layer.
*   It is used by initialization, widget APIs or wakeup functions to
*   enable the clocks.
*
* \param
*   snsClk The divider value for the sense clock.
*
*******************************************************************************/
void key_touch_SsSetSnsClockDivider(uint32 snsClk)
{
#if (key_touch_ENABLE == key_touch_CSDV2)
    uint32 newRegValue;

    /*
     * Set divider value for sense clock.
     * 1u is subtracted from snsClk because SENSE_DIV value 0 corresponds
     * to dividing by 1.
     */
    newRegValue = CY_GET_REG32(key_touch_SENSE_PERIOD_PTR);
    newRegValue &= (uint32)(~key_touch_SENSE_PERIOD_SENSE_DIV_MASK);
    newRegValue |= snsClk - 1u;
    CY_SET_REG32(key_touch_SENSE_PERIOD_PTR, newRegValue);
#else
    #if (key_touch_ENABLE == key_touch_IS_M0S8PERI_BLOCK)
        /*  Stop sense clock clock   */
        CY_SET_REG32(key_touch_SNSCLK_CMD_PTR,
                     ((uint32)key_touch_SnsClk__DIV_ID <<
                     key_touch_SNSCLK_CMD_DIV_SHIFT)|
                     ((uint32)key_touch_SNSCLK_CMD_DISABLE_MASK));

        /*
         * Set divider value for sense clock.
         * 1u is subtracted from snsClk because Divider register value 0 corresponds
         * to dividing by 1.
         */
        CY_SET_REG32(key_touch_SNSCLK_DIV_PTR, ((snsClk - 1u) << 8u));

        /*  Check whether previous sense clock start command has finished. */
        while(0u != (CY_GET_REG32(key_touch_SNSCLK_CMD_PTR) & key_touch_SNSCLK_CMD_ENABLE_MASK))
        {
            /*  Wait until previous sense clock start command has finished. */
        }

        /* Start sense clock aligned to previously started modulator clock. */
        CY_SET_REG32(key_touch_SNSCLK_CMD_PTR,
                     (uint32)(((uint32)key_touch_SnsClk__DIV_ID << key_touch_SNSCLK_CMD_DIV_SHIFT) |
                      ((uint32)key_touch_ModClk__PA_DIV_ID << key_touch_SNSCLK_CMD_PA_DIV_SHIFT) |
                      key_touch_SNSCLK_CMD_ENABLE_MASK));
    #else
        uint32 newRegValue;

        /* Clear bit to disable SnsClk clock. */
        CY_SET_REG32(key_touch_SNSCLK_CMD_PTR,
                     CY_GET_REG32(key_touch_SNSCLK_CMD_PTR) &
                     (uint32)(~(uint32)key_touch_SnsClk__ENABLE_MASK));

        /*
         * Update snsClk clock divider.
         * 1u is subtracted from snsClk because Divider register value has range (0-65535).
         */
        newRegValue = CY_GET_REG32(key_touch_SNSCLK_DIV_PTR) & (uint32)(~(uint32)key_touch_SnsClk__DIVIDER_MASK);
        newRegValue |= (snsClk - 1u);
        CY_SET_REG32(key_touch_SNSCLK_DIV_PTR, newRegValue);

        /* Set bit to enable SnsClk clock. */
        CY_SET_REG32(key_touch_SNSCLK_CMD_PTR,
                     CY_GET_REG32(key_touch_SNSCLK_CMD_PTR) |
                    key_touch_SnsClk__ENABLE_MASK);
    #endif /* (key_touch_ENABLE == key_touch_IS_M0S8PERI_BLOCK) */
#endif /* (key_touch_ENABLE == key_touch_CSDV2) */
}


/*******************************************************************************
* Function Name: key_touch_SsSetClockDividers
****************************************************************************//**
*
* \brief
*   Sets the divider values for sense and modulator clocks and then starts
*   a modulator clock-phase aligned to HFCLK and sense clock-phase aligned to
*   the modulator clock.
*
* \details
*   It is not recommended to call this function directly by the application layer.
*   It is used by initialization, widget APIs or wakeup functions to
*   enable the clocks.
*
* \param
*   snsClk The divider value for the sense clock.
*   modClk The divider value for the modulator clock.
*
*******************************************************************************/
void key_touch_SsSetClockDividers(uint32 snsClk, uint32 modClk)
{
    /* Configure Mod clock */
    key_touch_SsSetModClkClockDivider(modClk);

    /* Configure Sns clock */
    key_touch_SsSetSnsClockDivider(snsClk);
}


#if ((key_touch_ENABLE == key_touch_CSD_IDAC_AUTOCAL_EN) || \
     (key_touch_ENABLE == key_touch_CSX_IDAC_AUTOCAL_EN))
    /*******************************************************************************
    * Function Name: key_touch_CalibrateWidget
    ****************************************************************************//**
    *
    * \brief
    *  Calibrates the IDACs for all sensors in the specified widget to default
    *  target (85%) value, this function detects sensing method used by the
    *  widget prior to calibration.
    *
    * \details
    *  This function performs exactly the same tasks as
    *  key_touch_CalibrateAllWidgets, but only for a specified widget.
    *  This function detects the sensing method used by the widgets and takes
    *  into account the Enable compensation IDAC parameter.
    *
    *  This function is available when the CSD and/or CSX Enable IDAC
    *  auto-calibration parameter is enabled.

    *
    * \param wdgtIndex
    *  Specify the ID number of the widget to calibrate its raw count.
    *  A macro for the widget ID can be found in the
    *  key_touch Configuration header file defined as
    *  key_touch_<WidgetName>_WDGT_ID.
    *
    * \return
    *  Returns the status of the specified widget calibration:
    *    - CYRET_SUCCESS if operation is successfully completed.
    *    - CYRET_BAD_PARAM if the input parameter is invalid.
    *    - CYRET_BAD_DATA if the calibration failed and the component may not
    *      operate as expected.
    *
    *******************************************************************************/
    cystatus key_touch_CalibrateWidget(uint32 wdgtIndex)
    {
        cystatus calibrateStatus = CYRET_SUCCESS;

        do
        {
            if (key_touch_TOTAL_WIDGETS <= wdgtIndex)
            {
                calibrateStatus = CYRET_BAD_PARAM;
            }

            /*
             *  Check if widget id is valid, specified widget did not
             *  detect any faults conditions if BIST is enabled.
             */
            #if (key_touch_ENABLE == key_touch_SELF_TEST_EN)
                if (0u != key_touch_GET_WIDGET_EN_STATUS(wdgtIndex))
                {
                    calibrateStatus = CYRET_SUCCESS;
                }
                else
                {
                    calibrateStatus = CYRET_INVALID_STATE;
                }
            #endif  /* (key_touch_ENABLE == key_touch_SELF_TEST_EN) */

            if (CYRET_SUCCESS != calibrateStatus)
            {
                /* Exit from the loop because of a fail */
                break;
            }
            
            /* If CSD2X is enabled, calibrate CSD sensor    */
            #if (key_touch_ENABLE == key_touch_CSD2X_EN)
                /* Calibrate CSD2X slot */
                calibrateStatus = key_touch_CSD2XCalibrateWidget(wdgtIndex, key_touch_CSD_RAWCOUNT_CAL_LEVEL);

            /*  If both CSD and CSX are enabled, calibrate widget using sensing method */
            #elif (key_touch_ENABLE == key_touch_CSD_CSX_EN)

                /* Check widget sensing method and call appropriate APIs */
                #if (key_touch_ENABLE == key_touch_CSX_IDAC_AUTOCAL_EN)
                    if (key_touch_SENSE_METHOD_CSX_E ==
                        key_touch_GET_SENSE_METHOD(&key_touch_dsFlash.wdgtArray[wdgtIndex]))
                    {
                        /* Calibrate CSX widget  */
                       key_touch_CSXCalibrateWidget(wdgtIndex, key_touch_CSX_RAWCOUNT_CAL_LEVEL);
                    }
                #endif  /* (key_touch_ENABLE == key_touch_CSX_IDAC_AUTOCAL_EN) */

                #if (key_touch_ENABLE == key_touch_CSD_IDAC_AUTOCAL_EN)
                    if (key_touch_SENSE_METHOD_CSD_E ==
                        key_touch_GET_SENSE_METHOD(&key_touch_dsFlash.wdgtArray[wdgtIndex]))
                    {
                        /* Calibrate CSD widget */
                        calibrateStatus = key_touch_CSDCalibrateWidget(wdgtIndex, key_touch_CSD_RAWCOUNT_CAL_LEVEL);
                    }
                #endif  /* (key_touch_ENABLE == key_touch_CSD_IDAC_AUTOCAL_EN) */

            /*  If only CSD is enabled, calibrate CSD sensor  */
            #elif (key_touch_ENABLE == key_touch_CSD_EN)
                calibrateStatus = key_touch_CSDCalibrateWidget(wdgtIndex, key_touch_CSD_RAWCOUNT_CAL_LEVEL);

            /*  If only CSX is enabled, call CSX scan   */
            #elif (key_touch_ENABLE == key_touch_CSX_EN)
                key_touch_CSXCalibrateWidget(wdgtIndex, key_touch_CSX_RAWCOUNT_CAL_LEVEL);

            #else
                calibrateStatus = CYRET_UNKNOWN;
            #endif  /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

             /* Update CRC */
            #if (key_touch_ENABLE ==key_touch_TST_WDGT_CRC_EN)
                key_touch_DsUpdateWidgetCrc(wdgtIndex);
            #endif /* (key_touch_ENABLE ==key_touch_TST_WDGT_CRC_EN) */

        } while (0u);

        return calibrateStatus;
    }


    /*******************************************************************************
    * Function Name: key_touch_CalibrateAllWidgets
    ****************************************************************************//**
    *
    * \brief
    *  Calibrates the IDACs for all widgets in the component to default target
    *  (85%) value, this function detects sensing method used by the widgets
    *  prior to calibration.
    *
    * \details
    *  Calibrates the IDACs for all widgets in the component to the default
    *  target (85% of maximum possible raw count) value. This function detects
    *  the sensing method used by the widgets and takes into account the Enable
    *  compensation IDAC parameter.
    *
    *  This function is available when the CSD and/or CSX Enable IDAC
    *  auto-calibration parameter is enabled.
    *
    * \return
    *  Returns the status of the calibration process:
    *    - CYRET_SUCCESS if the operation is successfully completed.
    *    - CYRET_BAD_DATA if the calibration failed and the component may not
    *      operate as expected.
    *
    *******************************************************************************/
    cystatus key_touch_CalibrateAllWidgets(void)
    {
        cystatus calibrateStatus = CYRET_SUCCESS;
        uint32 wdgtIndex;

        for (wdgtIndex = 0u; wdgtIndex < key_touch_TOTAL_WIDGETS; wdgtIndex++)
        {
            calibrateStatus |= key_touch_CalibrateWidget(wdgtIndex);
        }

        return calibrateStatus;
    }
#endif /* ((key_touch_ENABLE == key_touch_CSD_IDAC_AUTOCAL_EN) ||
           (key_touch_ENABLE == key_touch_CSX_IDAC_AUTOCAL_EN)) */


#if (key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE)
    #if (key_touch_ENABLE == key_touch_CSD2X_EN)
        /*******************************************************************************
        * Function Name: key_touch_SsSetEqualSlotClock
        ****************************************************************************//**
        *
        * \brief
        *  This function sets sense clocks to be equal on both CSD blocks.
        *
        * \details
        *  This function sets clock dividers to equal
        *  to widget divider that has higher value.
        *
        *
        *******************************************************************************/
        static void key_touch_SsSetEqualSlotClock(void)
        {
            key_touch_RAM_WD_BASE_STRUCT *ptrCSD0Wdgt = 0u;
            key_touch_RAM_WD_BASE_STRUCT *ptrCSD1Wdgt = 0u;
            uint32 widgetIndex;
            uint32 emptySlot;

            /* Make sure that sense clocks are equal on both CSD blocks */
            for (widgetIndex = 0u; widgetIndex < key_touch_TOTAL_WIDGETS; widgetIndex++)
            {
                emptySlot = 0u;
                for (key_touch_slotIndex = 0u; key_touch_slotIndex < key_touch_TOTAL_SLOTS; key_touch_slotIndex++)
                {
                    key_touch_widgetIndex0 = key_touch_scanSlots[key_touch_slotIndex].csd0WidgetId;
                    key_touch_sensorIndex0 = key_touch_scanSlots[key_touch_slotIndex].csd0SensorId;

                    key_touch_widgetIndex1 = key_touch_scanSlots[key_touch_slotIndex].csd1WidgetId;
                    key_touch_sensorIndex1 = key_touch_scanSlots[key_touch_slotIndex].csd1SensorId;

                    if (key_touch_EMPTY_SLOT == key_touch_widgetIndex0)
                    {
                        emptySlot++;
                    }

                    if (key_touch_EMPTY_SLOT == key_touch_widgetIndex1)
                    {
                        emptySlot++;
                    }

                    if (0u == emptySlot)
                    {
                        ptrCSD0Wdgt = (key_touch_RAM_WD_BASE_STRUCT *)
                                       key_touch_dsFlash.wdgtArray[key_touch_widgetIndex0].ptr2WdgtRam;
                        ptrCSD1Wdgt = (key_touch_RAM_WD_BASE_STRUCT *)
                                       key_touch_dsFlash.wdgtArray[key_touch_widgetIndex1].ptr2WdgtRam;

                        #if (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)
                            /* Check if current slot for CSD0 block has a row */
                            if (key_touch_dsFlash.wdgtArray[key_touch_widgetIndex0].numCols <= key_touch_sensorIndex0)
                            {
                                /* Check if current slot for CSD1 block has a row */
                                if (key_touch_dsFlash.wdgtArray[key_touch_widgetIndex1].numCols <= key_touch_sensorIndex1)
                                {
                                    /* Both slots have the rows. Compare rowSnsClk and reassign the higher divider to widget with the lower divider */
                                    if (ptrCSD0Wdgt->rowSnsClk < ptrCSD1Wdgt->rowSnsClk)
                                    {
                                        ptrCSD0Wdgt->rowSnsClk = ptrCSD1Wdgt->rowSnsClk;
                                    }
                                    else
                                    {
                                        ptrCSD1Wdgt->rowSnsClk = ptrCSD0Wdgt->rowSnsClk;
                                    }
                                }
                                else
                                {
                                    /* CSD0 block has the row and CSD1 block has the column. Compare rowSnsClk and snsClk */
                                    if (ptrCSD0Wdgt->rowSnsClk < ptrCSD1Wdgt->snsClk)
                                    {
                                        ptrCSD0Wdgt->rowSnsClk = ptrCSD1Wdgt->snsClk;
                                    }
                                    else
                                    {
                                        ptrCSD1Wdgt->snsClk = ptrCSD0Wdgt->rowSnsClk;
                                    }
                                }
                            }
                            else
                            {
                                /* Check if current slot for CSD1 block has a row */
                                if (key_touch_dsFlash.wdgtArray[key_touch_widgetIndex1].numCols <= key_touch_sensorIndex1)
                                {
                                    /* CSD0 block has the column and CSD1 block has the row. Compare snsClk and rowSnsClk */
                                    if (ptrCSD0Wdgt->snsClk < ptrCSD1Wdgt->rowSnsClk)
                                    {
                                        ptrCSD0Wdgt->snsClk = ptrCSD1Wdgt->rowSnsClk;
                                    }
                                    else
                                    {
                                        ptrCSD1Wdgt->rowSnsClk = ptrCSD0Wdgt->snsClk;
                                    }
                                }
                                else
                                {
                                    /* Both slots have the columns. Compare snsClk and reassign the higher divider to widget with the lower divider */
                                    if (ptrCSD0Wdgt->snsClk < ptrCSD1Wdgt->snsClk)
                                    {
                                        ptrCSD0Wdgt->snsClk = ptrCSD1Wdgt->snsClk;
                                    }
                                    else
                                    {
                                        ptrCSD1Wdgt->snsClk = ptrCSD0Wdgt->snsClk;
                                    }
                                }
                            }
                        #else
                            /* Compare snsClk and reassign the higher divider to widget with the lower divider */
                            if (ptrCSD0Wdgt->snsClk < ptrCSD1Wdgt->snsClk)
                            {
                                ptrCSD0Wdgt->snsClk = ptrCSD1Wdgt->snsClk;
                            }
                            else
                            {
                                ptrCSD1Wdgt->snsClk = ptrCSD0Wdgt->snsClk;
                            }
                        #endif /* (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN) */
                    }
                }
            }
        }


        /*******************************************************************************
        * Function Name: key_touch_SsSetCSD0DirectClockMode
        ****************************************************************************//**
        *
        * \brief
        *  Sets Direct Clock Mode.
        *
        * \details
        *  For CSDv1: Resets PRS bit in key_touch_configCsd variable;
        *
        *******************************************************************************/
        static void key_touch_SsSetCSD0DirectClockMode(void)
        {
            #if (key_touch_DISABLE == key_touch_CSDV2)
                key_touch_configCsd0 = key_touch_configCsd0 &(uint32)~(key_touch_CONFIG_PRS_SELECT_MASK);
            #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
        }


        /*******************************************************************************
        * Function Name: key_touch_SsSetCSD1DirectClockMode
        ****************************************************************************//**
        *
        * \brief
        *  Sets Direct Clock Mode.
        *
        * \details
        *  For CSDv1: Resets PRS bit in key_touch_configCsd variable;
        *
        *******************************************************************************/
        static void key_touch_SsSetCSD1DirectClockMode(void)
        {
            #if (key_touch_DISABLE == key_touch_CSDV2)
                key_touch_configCsd1 = key_touch_configCsd1 &(uint32)~(key_touch_CONFIG_PRS_SELECT_MASK);
            #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
        }
    #else


        /*******************************************************************************
        * Function Name: key_touch_SsSetDirectClockMode
        ****************************************************************************//**
        *
        * \brief
        *  Sets Direct Clock Mode.
        *
        * \details
        *  For CSDv1: Resets PRS bit in key_touch_configCsd variable;
        *  For CSDv2: Resets key_touch_SENSE_PERIOD_SEL_LFSR_MSB_MASK and
        *  key_touch_SENSE_PERIOD_SEL_LFSR_MSB_MASK bits in
        *  key_touch_SENSE_PERIOD register.
        *
        *******************************************************************************/
        static void key_touch_SsSetDirectClockMode(void)
        {
            #if (key_touch_ENABLE == key_touch_CSDV2)
                CY_SET_REG32(key_touch_SENSE_PERIOD_PTR, CY_GET_REG32(key_touch_SENSE_PERIOD_PTR) &
                                                                     (uint32)~(key_touch_SENSE_PERIOD_SEL_LFSR_MSB_MASK | \
                                                                     key_touch_SENSE_PERIOD_LFSR_SIZE_MASK));
            #else
                key_touch_configCsd = key_touch_configCsd &(uint32)~(key_touch_CONFIG_PRS_SELECT_MASK);
            #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
        }
    #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */


    /*******************************************************************************
    * Function Name: key_touch_SsAutoTune
    ****************************************************************************//**
    *
    * \brief
    *  This API performs the parameters auto-tuning for the optimal key_touch operation.
    *
    * \details
    *  This API performs the following:
    *  - Calibrates Modulator and Compensation IDACs.
    *  - Tunes the Sense Clock optimal value to get a Sense Clock period greater than
    *     2*5*R*Cp.
    *  - Calculates the resolution for the optimal finger capacitance.
    *
    * \return
    *   Returns the status of operation:
    *   - Zero     - All the widgets are auto-tuned successfully.
    *   - Non-zero - Auto-tuning failed for any widget.
    *
    *******************************************************************************/
    cystatus key_touch_SsAutoTune(void)
    {
        cystatus autoTuneStatus = CYRET_SUCCESS;
        uint32 wdgtIndex;
        uint32 cp = 0uL;
        #if (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)
            uint32 cpRow = 0uL;
        #endif /* (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN) */
        key_touch_RAM_WD_BASE_STRUCT *ptrWdgt;
        AUTO_TUNE_CONFIG_TYPE autoTuneConfig;
        #if (key_touch_ENABLE == key_touch_CSD2X_EN)
            uint32 csdBlockID;
        #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

        /* Configure common config variables */
        autoTuneConfig.snsClkConstantR = key_touch_CSD_SNSCLK_R_CONST;
        autoTuneConfig.vRef = key_touch_CSD_VREF_MV;
        #if (key_touch_DISABLE == key_touch_CSD2X_EN)
            autoTuneConfig.iDacGain = key_touch_CSD_IDAC_GAIN_VALUE_NA * key_touch_CSD_DUAL_IDAC_FACTOR;
        #endif /* (key_touch_DISABLE == key_touch_CSD2X_EN) */
        autoTuneConfig.calTarget = key_touch_CSD_AUTOTUNE_CAL_LEVEL;

        /* Calculate snsClk Input Clock in KHz */
        #if (key_touch_ENABLE == key_touch_CSDV2)
            /*  Dividers are chained (CSDV2). Flip flop is not available */
            autoTuneConfig.snsClkInputClock = (CYDEV_BCLK__HFCLK__KHZ / key_touch_dsRam.modCsdClk);
        #elif ((key_touch_ENABLE == key_touch_IS_M0S8PERI_BLOCK) && (key_touch_DISABLE == CY_PSOC4_4000))
            /*  Dividers are not chained */
            autoTuneConfig.snsClkInputClock = CYDEV_BCLK__HFCLK__KHZ >> key_touch_FLIP_FLOP_DIV;
        #elif (key_touch_ENABLE == key_touch_IS_M0S8PERI_BLOCK)
            /*  Dividers are not chained (PSoC 4000) */
            autoTuneConfig.snsClkInputClock = CYDEV_BCLK__HFCLK__KHZ >> key_touch_FLIP_FLOP_DIV;
        #else
            /*  Dividers are chained (PSoC 4100, PSoC 4200) */
            autoTuneConfig.snsClkInputClock = (CYDEV_BCLK__HFCLK__KHZ / key_touch_dsRam.modCsdClk) >> key_touch_FLIP_FLOP_DIV;
        #endif /* (key_touch_ENABLE == key_touch_CSDV2) */

        /* If both CSD and CSX are enabled, calibrate widget using sensing method */
        #if (key_touch_ENABLE == key_touch_CSD_CSX_EN)
            /* Initialize CSD mode */
            key_touch_SsCSDInitialize();
        #endif /* (key_touch_ENABLE == key_touch_CSD_CSX_EN) */

        /* Set flag to calibrate in PWM mode only */
        key_touch_prescalersTuningDone = key_touch_DISABLE;

        /* Switch charge clock source to direct clock mode */
        #if (key_touch_ENABLE == key_touch_CSD2X_EN)
            key_touch_SsSetCSD0DirectClockMode();
            key_touch_SsSetCSD1DirectClockMode();
        #else
            key_touch_SsSetDirectClockMode();
        #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */


        /* Tune sense clock for all widgets */
        for (wdgtIndex = 0u; wdgtIndex < key_touch_TOTAL_WIDGETS; wdgtIndex++)
        {
            if (key_touch_SENSE_METHOD_CSD_E ==
                key_touch_GET_SENSE_METHOD(&key_touch_dsFlash.wdgtArray[wdgtIndex]))
            {
                ptrWdgt = (key_touch_RAM_WD_BASE_STRUCT *)
                          key_touch_dsFlash.wdgtArray[wdgtIndex].ptr2WdgtRam;

                #if (key_touch_ENABLE == key_touch_CSD2X_EN)
                    csdBlockID = key_touch_dsFlash.wdgtArray[wdgtIndex].csdblk;

                    if (key_touch_CSD0_BLOCK_ID == csdBlockID)
                    {
                        autoTuneConfig.iDacGain = key_touch_CSD0_IDAC_GAIN_VALUE_NA * key_touch_CSD_DUAL_IDAC_FACTOR;
                    }
                    else
                    {
                        autoTuneConfig.iDacGain = key_touch_CSD1_IDAC_GAIN_VALUE_NA * key_touch_CSD_DUAL_IDAC_FACTOR;
                    }
                #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

                /* Set calibration resolution to 12 bits */
                ptrWdgt->resolution = key_touch_CALIBRATION_RESOLUTION;

                /* Set Sense clock frequency to 1.5 MHz */
                #if (key_touch_ENABLE == key_touch_CSD_COMMON_SNS_CLK_EN)
                    key_touch_dsRam.snsCsdClk = (uint8)((uint32)autoTuneConfig.snsClkInputClock /
                                                       key_touch_CALIBRATION_FREQ_KHZ);
                #elif (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)
                    if ((key_touch_WD_TOUCHPAD_E == (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[(wdgtIndex)].wdgtType) ||
                        (key_touch_WD_MATRIX_BUTTON_E == (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[(wdgtIndex)].wdgtType))
                    {
                        ptrWdgt->rowSnsClk = (uint8)((uint32)autoTuneConfig.snsClkInputClock /
                                             key_touch_CALIBRATION_FREQ_KHZ);
                    }
                    ptrWdgt->snsClk = (uint8)((uint32)autoTuneConfig.snsClkInputClock /
                                      key_touch_CALIBRATION_FREQ_KHZ);
                #else
                    ptrWdgt->snsClk = (uint8)((uint32)autoTuneConfig.snsClkInputClock /
                                      key_touch_CALIBRATION_FREQ_KHZ);
                #endif /*  (key_touch_ENABLE == key_touch_CSD_COMMON_SNS_CLK_EN) */

                /* Calibrate CSD widget to 85% */
                #if (key_touch_ENABLE == key_touch_CSD2X_EN)
                    (void)key_touch_CSD2XCalibrateWidget(wdgtIndex, key_touch_CSD_AUTOTUNE_CAL_LEVEL);
                #else
                    (void)key_touch_CSDCalibrateWidget(wdgtIndex, key_touch_CSD_AUTOTUNE_CAL_LEVEL);
                #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

                #if (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)
                    if ((key_touch_WD_TOUCHPAD_E == (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[(wdgtIndex)].wdgtType) ||
                        (key_touch_WD_MATRIX_BUTTON_E == (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[(wdgtIndex)].wdgtType))
                    {
                        /* Get pointer to Modulator IDAC for columns */
                        autoTuneConfig.ptrModIDAC = &ptrWdgt->rowIdacMod[0u];

                        /* Get pointer to Sense Clock Divider for columns */
                        autoTuneConfig.ptrSenseClk = &ptrWdgt->rowSnsClk;

                        /* Find correct sense clock value */
                        cpRow = SmartSense_TunePrescalers(&autoTuneConfig);

                        if ((key_touch_CP_MAX + key_touch_CP_ERROR) <= cpRow)
                        {
                            autoTuneStatus = CYRET_BAD_DATA;
                        }

                        #if (key_touch_ENABLE == key_touch_CSDV2)
                            /* Make sure that ModClk >= 4 * rowSnsClk for ModClk <= 12 MHz and rowSnsClk <= 6MHz */
                            if (autoTuneConfig.snsClkInputClock <= key_touch_MOD_CSD_CLK_24000KHZ)
                            {
                                if (ptrWdgt->rowSnsClk < key_touch_FACTOR_FILTER_DELAY_12MHZ)
                                {
                                    ptrWdgt->rowSnsClk = key_touch_FACTOR_FILTER_DELAY_12MHZ;
                                }
                            }
                            else if (autoTuneConfig.snsClkInputClock <= key_touch_MOD_CSD_CLK_48000KHZ)
                            {
                                if (ptrWdgt->rowSnsClk < key_touch_FACTOR_MOD_SNS)
                                {
                                    ptrWdgt->rowSnsClk = key_touch_FACTOR_MOD_SNS;
                                }
                            }
                            else
                            {
                                /* rowSnsClk is valid*/
                            }
                        #else
                            #if (key_touch_ENABLE == key_touch_IS_M0S8PERI_BLOCK)
                                /* Make sure that ModClk >= 2 * rowSnsClk */
                                if (key_touch_dsRam.modCsdClk >= ((uint8)(ptrWdgt->rowSnsClk << key_touch_FLIP_FLOP_DIV)))
                                {
                                     ptrWdgt->rowSnsClk = key_touch_dsRam.modCsdClk;
                                }
                            #else
                                /* Sense clock never equals to Modulator clock for chained dividers because of Flip Flop */
                            #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
                        #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
                    }
                #endif /* (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN) */

                /* Get pointer to Modulator IDAC  for rows */
                autoTuneConfig.ptrModIDAC = &ptrWdgt->idacMod[0u];

                /* Get pointer to Sense Clock Divider for columns */
                autoTuneConfig.ptrSenseClk = &ptrWdgt->snsClk;

                /* Find correct sense clock value */
                cp = SmartSense_TunePrescalers(&autoTuneConfig);

                if ((key_touch_CP_MAX + key_touch_CP_ERROR) <= cp)
                {
                    autoTuneStatus = CYRET_BAD_DATA;
                }

                #if (key_touch_ENABLE == key_touch_CSDV2)
                    /* Make sure that ModClk >= 4 * SnsClk for ModClk <= 12 MHz and SnsClk <= 6MHz */
                    if (autoTuneConfig.snsClkInputClock <= key_touch_MOD_CSD_CLK_24000KHZ)
                    {
                        if (ptrWdgt->snsClk < key_touch_FACTOR_FILTER_DELAY_12MHZ)
                        {
                            ptrWdgt->snsClk = key_touch_FACTOR_FILTER_DELAY_12MHZ;
                        }
                    }
                    else if (autoTuneConfig.snsClkInputClock <= key_touch_MOD_CSD_CLK_48000KHZ)
                    {
                        if (ptrWdgt->snsClk < key_touch_FACTOR_MOD_SNS)
                        {
                            ptrWdgt->snsClk = key_touch_FACTOR_MOD_SNS;
                        }
                    }
                    else
                    {
                        /* SnsClk is valid*/
                    }
                #else
                    #if (key_touch_ENABLE == key_touch_IS_M0S8PERI_BLOCK)
                        /* Make sure that ModClk >= 2 * snsClk */
                        if (key_touch_dsRam.modCsdClk >= ((uint8)(ptrWdgt->snsClk << key_touch_FLIP_FLOP_DIV)))
                        {
                             ptrWdgt->snsClk = key_touch_dsRam.modCsdClk;
                        }
                    #else
                        /* Sense clock never equals to Modulator clock for chained dividers because of Flip Flop */
                    #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
                #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
            }
        }

        #if (key_touch_ENABLE == key_touch_CSD2X_EN)
            key_touch_SsSetEqualSlotClock();
        #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

        /* Set flag to indicate that calibration in PWM mode has been performed */
        key_touch_prescalersTuningDone = 1u;

        /* Multiply Clk divider to 2 for PRS mode to take into account average PRS frequency */
        autoTuneConfig.prsFactor = key_touch_PRS_FACTOR_DIV;

        /* Tune sensitivity and resolution for all widgets */
        for (wdgtIndex = 0u; wdgtIndex < key_touch_TOTAL_WIDGETS; wdgtIndex++)
        {
            if (key_touch_SENSE_METHOD_CSD_E ==
                key_touch_GET_SENSE_METHOD(&key_touch_dsFlash.wdgtArray[wdgtIndex]))
            {
                ptrWdgt = (key_touch_RAM_WD_BASE_STRUCT *)
                          key_touch_dsFlash.wdgtArray[wdgtIndex].ptr2WdgtRam;

                /* Get pointer to Modulator IDAC for rows */
                autoTuneConfig.ptrModIDAC = &ptrWdgt->idacMod[0u];

                /* Get pointer to maximum Sense Clock Divider (column or row) */
                autoTuneConfig.ptrSenseClk = &ptrWdgt->snsClk;

                /* Set parasitic capacitance for columns */
                autoTuneConfig.sensorCap = cp;

                #if (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)
                    if ((key_touch_WD_TOUCHPAD_E == (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[(wdgtIndex)].wdgtType) ||
                        (key_touch_WD_MATRIX_BUTTON_E == (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[(wdgtIndex)].wdgtType))

                    {
                        /* Set the minimum sense clock frequency to calculate the resolution */
                        if (ptrWdgt->snsClk < ptrWdgt->rowSnsClk)
                        {
                            /* Rewrite pointer to Sense Clock Divider for rows */
                            autoTuneConfig.ptrSenseClk = &ptrWdgt->rowSnsClk;

                            /* Set parasitic capacitance for rows */
                            autoTuneConfig.sensorCap = cpRow;
                        }
                    }
                #endif /* (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN) */

                /* Get finger capacitance */
                autoTuneConfig.fingerCap = ptrWdgt->fingerCap;

                /* Init pointer to sigPFC */
                autoTuneConfig.sigPFC = &ptrWdgt->sigPFC;

                #if (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE)
                    key_touch_SsSetWidgetSenseClkSrc(wdgtIndex, ptrWdgt);
                #endif /* (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE) */

                /* Calibrate CSD widget to 85% */
                #if (key_touch_ENABLE == key_touch_CSD2X_EN)
                    autoTuneStatus |=key_touch_CSD2XCalibrateWidget(wdgtIndex, key_touch_CSD_AUTOTUNE_CAL_LEVEL);
                #else
                    autoTuneStatus |= key_touch_CSDCalibrateWidget(wdgtIndex, key_touch_CSD_AUTOTUNE_CAL_LEVEL);
                #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */

                /* Find resolution */
                ptrWdgt->resolution = SmartSense_TuneSensitivity(&autoTuneConfig);

                #if (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE)
                    key_touch_SsSetWidgetSenseClkSrc(wdgtIndex, ptrWdgt);

                    #if (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)
                        if (((uint8)key_touch_CLK_SOURCE_DIRECT == ptrWdgt->snsClkSource) ||
                            ((uint8)key_touch_CLK_SOURCE_DIRECT == ptrWdgt->rowSnsClkSource))
                        {
                            /* Recalibrate CSD widget to 85% because source is changed to direct */
                            #if (key_touch_ENABLE == key_touch_CSD2X_EN)
                                autoTuneStatus |= key_touch_CSD2XCalibrateWidget(wdgtIndex, key_touch_CSD_AUTOTUNE_CAL_LEVEL);
                            #else
                                autoTuneStatus |= key_touch_CSDCalibrateWidget(wdgtIndex, key_touch_CSD_AUTOTUNE_CAL_LEVEL);
                            #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
                        }
                    #else
                        if ((uint8)key_touch_CLK_SOURCE_DIRECT == ptrWdgt->snsClkSource)
                        {
                            /* Recalibrate CSD widget to 85% because source is changed to direct */
                            #if (key_touch_ENABLE == key_touch_CSD2X_EN)
                                autoTuneStatus |= key_touch_CSD2XCalibrateWidget(wdgtIndex, key_touch_CSD_AUTOTUNE_CAL_LEVEL);
                            #else
                                autoTuneStatus |= key_touch_CSDCalibrateWidget(wdgtIndex, key_touch_CSD_AUTOTUNE_CAL_LEVEL);
                            #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
                        }
                    #endif /* (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN) */
                #endif /* (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE) */
                
                #if (key_touch_ENABLE == key_touch_TST_WDGT_CRC_EN)
                    key_touch_DsUpdateWidgetCrc(wdgtIndex);
                #endif /* (key_touch_ENABLE == key_touch_TST_WDGT_CRC_EN) */
            }
        }

        return autoTuneStatus;
    }
#endif /* (key_touch_CSD_SS_DIS != key_touch_CSD_AUTOTUNE)) */


#if (key_touch_DISABLE == key_touch_CSDV2)
    #if ((key_touch_ENABLE == key_touch_CSX_EN) || \
         (key_touch_IDAC_SINKING == key_touch_CSD_IDAC_CONFIG))
        /*******************************************************************************
        * Function Name: key_touch_SsTrimIdacsSinking
        ****************************************************************************//**
        *
        * \brief
        *  This function loads trim values from SFLASH rows to calibrate
        *  IDAC1 and IDAC2 for Sinking CSD Mode
        *
        * \details
        *  Function reads trim value from SFLASH and loads it into IDAC trim register.
        *  If Compensation IDAC is disabled the function loads trim values for IDAC1 only.
        *
        *******************************************************************************/
        static void key_touch_SsTrimIdacsSinking(void)
        {
            uint32 trimValue;

            #if (key_touch_ENABLE == key_touch_CSD2X_EN)

                /* iDAC0 Sinking Mode */
                trimValue = CY_GET_REG32(key_touch_CSD0_TRIM2_PTR) & ~key_touch_IDAC_TRIM2_MOD_SNK_MASK;
                trimValue |= ((uint32)CY_GET_REG8(key_touch_CSD0_SFLASH_TRIM2_PTR) &
                                                          key_touch_SFLASH_TRIM_IDAC_MOD_MASK) ;

                #if (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN)
                    /* iDAC1 Sinking Mode */
                    trimValue &= ~key_touch_IDAC_TRIM2_COMP_SNK_MASK;
                    trimValue |= ((uint32)CY_GET_REG8(key_touch_CSD0_SFLASH_TRIM2_PTR) &
                                                              key_touch_SFLASH_TRIM_IDAC_COMP_MASK);
                #endif /* (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) */

                /* Update IDAC trim bits for gain control in current sink mode */
                CY_SET_REG32(key_touch_CSD0_TRIM2_PTR, trimValue);

                /* iDAC2 Sinking Mode */
                trimValue = CY_GET_REG32(key_touch_CSD1_TRIM2_PTR) & ~key_touch_IDAC_TRIM2_MOD_SNK_MASK;
                trimValue |= ((uint32)CY_GET_REG8(key_touch_CSD1_SFLASH_TRIM2_PTR) &
                                                          key_touch_SFLASH_TRIM_IDAC_MOD_MASK) ;

                #if (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN)
                    /* iDAC3 Sinking Mode */
                    trimValue &= ~key_touch_IDAC_TRIM2_COMP_SNK_MASK;
                    trimValue |= ((uint32)CY_GET_REG8(key_touch_CSD1_SFLASH_TRIM2_PTR) &
                                                              key_touch_SFLASH_TRIM_IDAC_COMP_MASK);
                #endif /* (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) */

                /* Update IDAC trim bits for gain control in current sink mode */
                CY_SET_REG32(key_touch_CSD1_TRIM2_PTR, trimValue);

            #else

                /* Mod iDAC Sinking Mode */
                trimValue = CY_GET_REG32(key_touch_TRIM2_PTR) & ~key_touch_IDAC_TRIM2_MOD_SNK_MASK;
                trimValue |= ((uint32)CY_GET_REG8(key_touch_SFLASH_TRIM2_PTR) &
                                                          key_touch_SFLASH_TRIM_IDAC_MOD_MASK) ;

                #if (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN)
                    /* Comp iDAC Sinking Mode */
                    trimValue &= ~key_touch_IDAC_TRIM2_COMP_SNK_MASK;
                    trimValue |= ((uint32)CY_GET_REG8(key_touch_SFLASH_TRIM2_PTR) &
                                                              key_touch_SFLASH_TRIM_IDAC_COMP_MASK);
                #endif /* (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) */

                /* Update IDAC trim bits for gain control in current sink mode */
                CY_SET_REG32(key_touch_TRIM2_PTR, trimValue);

            #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN)) */
        }
    #endif /* ((key_touch_ENABLE == key_touch_CSX_EN) || \
               (key_touch_IDAC_SINKING == key_touch_CSD_IDAC_CONFIG)) */


    #if ((key_touch_ENABLE == key_touch_CSX_EN) || \
         (key_touch_IDAC_SOURCING == key_touch_CSD_IDAC_CONFIG))
        /*******************************************************************************
        * Function Name: key_touch_SsTrimIdacsSourcing
        ****************************************************************************//**
        *
        * \brief
        *  This function loads trim values from SFLASH rows to calibrate
        *  IDAC1 and IDAC2 for Sourcing CSD Mode
        *
        * \details
        *  Function reads trim value from SFLASH and loads it into IDAC trim register.
        *  If Compensation IDAC is disabled the function loads trim values for IDAC1 only.
        *
        *******************************************************************************/
        static void key_touch_SsTrimIdacsSourcing(void)
        {
            uint32 trimValue;

            #if (key_touch_ENABLE == key_touch_CSD2X_EN)

                /* iDAC0 Sourcing Mode */
                trimValue = CY_GET_REG32(key_touch_CSD0_TRIM1_PTR) & ~key_touch_IDAC_TRIM1_MOD_SRC_MASK;
                trimValue |= ((uint32)CY_GET_REG8(key_touch_CSD0_SFLASH_TRIM1_PTR) &
                                                          key_touch_SFLASH_TRIM_IDAC_MOD_MASK);

                #if (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN)
                     /* iDAC1 Sourcing Mode */
                    trimValue &= ~key_touch_IDAC_TRIM1_COMP_SRC_MASK;
                    trimValue |= ((uint32)CY_GET_REG8(key_touch_CSD0_SFLASH_TRIM1_PTR) &
                                                              key_touch_SFLASH_TRIM_IDAC_COMP_MASK);
                #endif /* (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) */

                /* Update IDAC trim bits for gain control in current source mode */
                CY_SET_REG32(key_touch_CSD0_TRIM1_PTR, trimValue);

                /* iDAC2 Sourcing Mode */
                trimValue = CY_GET_REG32(key_touch_CSD1_TRIM1_PTR) & ~key_touch_IDAC_TRIM1_MOD_SRC_MASK;
                trimValue |= ((uint32)CY_GET_REG8(key_touch_CSD1_SFLASH_TRIM1_PTR) &
                                                          key_touch_SFLASH_TRIM_IDAC_MOD_MASK);

                #if (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN)
                     /* iDAC3 Sourcing Mode */
                    trimValue &= ~key_touch_IDAC_TRIM1_COMP_SRC_MASK;
                    trimValue |= ((uint32)CY_GET_REG8(key_touch_CSD1_SFLASH_TRIM1_PTR) &
                                                              key_touch_SFLASH_TRIM_IDAC_COMP_MASK);
                #endif /* (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) */

                /* Update IDAC trim bits for gain control in current source mode */
                CY_SET_REG32(key_touch_CSD1_TRIM1_PTR, trimValue);

            #else

                /* Mod iDAC Sourcing Mode */
                trimValue = CY_GET_REG32(key_touch_TRIM1_PTR) & ~key_touch_IDAC_TRIM1_MOD_SRC_MASK;
                trimValue |= ((uint32)CY_GET_REG8(key_touch_SFLASH_TRIM1_PTR) &
                                                          key_touch_SFLASH_TRIM_IDAC_MOD_MASK);

                #if (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN)
                     /* Comp iDAC Sourcing Mode */
                    trimValue &= ~key_touch_IDAC_TRIM1_COMP_SRC_MASK;
                    trimValue |= ((uint32)CY_GET_REG8(key_touch_SFLASH_TRIM1_PTR) &
                                                              key_touch_SFLASH_TRIM_IDAC_COMP_MASK);
                #endif /* (key_touch_ENABLE == key_touch_CSD_IDAC_COMP_EN) */

                /* Update IDAC trim bits for gain control in current source mode */
                CY_SET_REG32(key_touch_TRIM1_PTR, trimValue);

            #endif /* (key_touch_ENABLE == key_touch_CSD2X_EN) */
        }
    #endif /* ((key_touch_ENABLE == key_touch_CSX_EN) || \
               (key_touch_IDAC_SOURCING == key_touch_CSD_IDAC_CONFIG)) */


    /*******************************************************************************
    * Function Name: key_touch_SsTrimIdacs
    ****************************************************************************//**
    *
    * \brief
    *  This function loads trim values from SFLASH rows to calibrate
    *  IDAC1 and IDAC2 for CSD Mode
    *
    * \details
    *  If CSX mode is enabled the function loads trim values for both sink and source
    *  mode. If CSX mode is disabled the function loads trim values for sink or
    *  source mode based on sink/source mode configuration.
    *  If Compensation IDAC is disabled the function loads trim values for IDAC1 only.
    *
    *******************************************************************************/
    static void key_touch_SsTrimIdacs(void)
    {
        #if (key_touch_ENABLE == key_touch_CSX_EN)
            key_touch_SsTrimIdacsSinking();
            key_touch_SsTrimIdacsSourcing();
        #elif (key_touch_IDAC_SINKING == key_touch_CSD_IDAC_CONFIG)
            key_touch_SsTrimIdacsSinking();
        #elif (key_touch_IDAC_SOURCING == key_touch_CSD_IDAC_CONFIG)
            key_touch_SsTrimIdacsSourcing();
        #else
            #error "Not supported Mode, component cannot work in this mode"
        #endif /* (key_touch_ENABLE == key_touch_CSX_EN) */
    }
#endif  /* (key_touch_DISABLE == key_touch_CSDV2) */


#if (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN)
    /*******************************************************************************
    * Function Name: key_touch_SsChangeImoFreq
    ****************************************************************************//**
    *
    * \brief
    *  This function changes the IMO frequency.
    *
    * \details
    *   The IMO frequency can have three offsets: 0%, -5% and +5%. The frequency
    *   trims are contained in the key_touch_immunity[value] array for each
    *   frequency channel.
    *
    * \param value The frequency channel ID.
    *
    *******************************************************************************/
    void key_touch_SsChangeImoFreq(uint32 value)
    {
        CY_SET_REG32(CY_SYS_CLK_IMO_TRIM1_PTR, key_touch_immunity[value]);
    }
#endif  /* (key_touch_ENABLE == key_touch_MULTI_FREQ_SCAN_EN) */


#if((key_touch_ENABLE == key_touch_CSD_EN) ||\
    (key_touch_ENABLE == key_touch_CSD2X_EN) ||\
    ((key_touch_ENABLE == key_touch_CSX_EN) && (key_touch_ENABLE == key_touch_CSDV2)))
/*******************************************************************************
* Function Name: key_touch_SsInitializeSourceSenseClk
****************************************************************************//**
*
* \brief
*  Sets a source for Sense Clk for all CSD widgets.
*
* \details
*  Updates snsClkSource and rowSnsClkSource with a source for the sense Clk.
*  for all CSD widgets.
*
*******************************************************************************/
void key_touch_SsInitializeSourceSenseClk(void)
{
    uint32 wdgtIndex;
    key_touch_RAM_WD_BASE_STRUCT *ptrWdgt;

    for (wdgtIndex = 0u; wdgtIndex < key_touch_TOTAL_WIDGETS; wdgtIndex++)
    {
        ptrWdgt = (key_touch_RAM_WD_BASE_STRUCT *)key_touch_dsFlash.wdgtArray[wdgtIndex].ptr2WdgtRam;
        if (key_touch_SENSE_METHOD_CSD_E ==
        key_touch_GET_SENSE_METHOD(&key_touch_dsFlash.wdgtArray[wdgtIndex]))
        {
            #if ((key_touch_ENABLE == key_touch_CSD_EN) || (key_touch_ENABLE == key_touch_CSD2X_EN))
                key_touch_SsSetWidgetSenseClkSrc(wdgtIndex, ptrWdgt);
            #endif /* ((key_touch_ENABLE == key_touch_CSD_EN) || key_touch_ENABLE == key_touch_CSD2X_EN)) */
        }
        else
        {
            #if ((key_touch_ENABLE == key_touch_CSX_EN) && (key_touch_ENABLE == key_touch_CSDV2))
                key_touch_SsSetWidgetTxClkSrc(wdgtIndex, ptrWdgt);
            #endif /* ((key_touch_ENABLE == key_touch_CSX_EN) && (key_touch_ENABLE == key_touch_CSDV2)) */
        }
        #if (key_touch_ENABLE == key_touch_TST_WDGT_CRC_EN)
            key_touch_DsUpdateWidgetCrc(wdgtIndex);
        #endif /* (key_touch_ENABLE == key_touch_TST_WDGT_CRC_EN) */
    }
}
#endif /* ((key_touch_ENABLE == key_touch_CSD_EN) ||\
           (key_touch_ENABLE == key_touch_CSD2X_EN) ||\
           ((key_touch_ENABLE == key_touch_CSX_EN) && (key_touch_ENABLE == key_touch_CSDV2))) */


#if ((key_touch_ENABLE == key_touch_CSD_EN) ||\
     (key_touch_ENABLE == key_touch_CSD2X_EN))
    /*******************************************************************************
    * Function Name: key_touch_SsSetWidgetSenseClkSrc
    ****************************************************************************//**
    *
    * \brief
    *  Sets a source for the sense clock for a widget.
    *
    * \param wdgtIndex
    *   Specifies the ID of the widget.
    * \param ptrWdgt
    *   The pointer to the RAM_WD_BASE_STRUCT structure.
    *
    * \details
    *  Updates snsClkSource and rowSnsClkSource with a source for the sense Clk for a
    *  widget.
    *
    *******************************************************************************/
    static void key_touch_SsSetWidgetSenseClkSrc(uint32 wdgtIndex, key_touch_RAM_WD_BASE_STRUCT * ptrWdgt)
    {
        uint8 lfsrSize;
        uint8 lfsrScale;

        #if(key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE)
            #if(key_touch_ENABLE == key_touch_CSDV2)
                uint32 conversionsNum;
            #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
            uint32 snsClkDivider;
        #endif /* (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE) */

        #if(key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE)
            snsClkDivider = key_touch_SsCSDGetColSnsClkDivider(wdgtIndex);

            #if(key_touch_ENABLE == key_touch_CSDV2)
                conversionsNum = key_touch_SsCSDGetNumberOfConversions(snsClkDivider, (uint32)ptrWdgt->resolution,
                                                                                             key_touch_CLK_SOURCE_DIRECT);
                lfsrSize = key_touch_SsCalcLfsrSize(snsClkDivider, conversionsNum);
                if (key_touch_CLK_SOURCE_DIRECT == lfsrSize)
                {
                    lfsrSize = key_touch_SsCSDCalcPrsSize(snsClkDivider, (uint32)ptrWdgt->resolution);
                }
                lfsrScale = key_touch_SsCalcLfsrScale(snsClkDivider, lfsrSize);
            #else
                lfsrSize = key_touch_SsCSDCalcPrsSize(snsClkDivider, (uint32)ptrWdgt->resolution);
                lfsrScale = 0u;
            #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
        #else
            lfsrSize = (uint8)key_touch_DEFAULT_MODULATION_MODE;
            lfsrScale = 0u;
            (void)wdgtIndex; /* This parameter is unused in such configurations */
        #endif /* (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE) */

        ptrWdgt->snsClkSource = lfsrSize | (uint8)(lfsrScale << key_touch_CLK_SOURCE_LFSR_SCALE_OFFSET);

        #if (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN))
            if ((key_touch_WD_TOUCHPAD_E == (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[wdgtIndex].wdgtType) ||
                (key_touch_WD_MATRIX_BUTTON_E == (key_touch_WD_TYPE_ENUM)key_touch_dsFlash.wdgtArray[wdgtIndex].wdgtType))
            {
                #if(key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE)
                    snsClkDivider = key_touch_SsCSDGetRowSnsClkDivider(wdgtIndex);

                    #if(key_touch_ENABLE == key_touch_CSDV2)
                        lfsrSize = key_touch_SsCalcLfsrSize(snsClkDivider, conversionsNum);
                        if (key_touch_CLK_SOURCE_DIRECT == lfsrSize)
                        {
                            lfsrSize = key_touch_SsCSDCalcPrsSize(snsClkDivider, (uint32)ptrWdgt->resolution);
                        }
                        lfsrScale = key_touch_SsCalcLfsrScale(snsClkDivider, lfsrSize);
                    #else
                        lfsrSize = key_touch_SsCSDCalcPrsSize(snsClkDivider, (uint32)ptrWdgt->resolution);
                        lfsrScale = 0u;
                    #endif /* (key_touch_ENABLE == key_touch_CSDV2) */
                #else
                    lfsrSize = (uint8)key_touch_DEFAULT_MODULATION_MODE;
                    lfsrScale = 0u;
                #endif /* (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE) */
                ptrWdgt->rowSnsClkSource = lfsrSize | (uint8)(lfsrScale << key_touch_CLK_SOURCE_LFSR_SCALE_OFFSET);
            }
        #endif /* (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)) */
    }
#endif /* ((key_touch_ENABLE == key_touch_CSD_EN) ||\
           (key_touch_ENABLE == key_touch_CSD2X_EN))*/


#if ((key_touch_ENABLE == key_touch_CSX_EN) && (key_touch_ENABLE == key_touch_CSDV2))
    /*******************************************************************************
    * Function Name: key_touch_SsSetWidgetTxClkSrc
    ****************************************************************************//**
    *
    * \brief
    *  Sets a source for the Tx clock for a widget.
    *
    * \param wdgtIndex
    *   Specifies the ID of the widget.
    * \param ptrWdgt
    *   The pointer to the RAM_WD_BASE_STRUCT structure.
    *
    * \details
    *  Updates snsClkSourcewith with a source for Tx Clk for a widget.
    *
    *******************************************************************************/
    static void key_touch_SsSetWidgetTxClkSrc(uint32 wdgtIndex, key_touch_RAM_WD_BASE_STRUCT * ptrWdgt)
    {
        uint8 lfsrSize;
        uint8 lfsrScale;

        #if(key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSX_TX_CLK_SOURCE)
            uint32 conversionsNum;
            uint32 snsClkDivider;
        #endif /* (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSX_TX_CLK_SOURCE) */

        #if(key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSX_TX_CLK_SOURCE)
            conversionsNum = (uint32)ptrWdgt->resolution;
            snsClkDivider = key_touch_SsCSXGetTxClkDivider(wdgtIndex);
            lfsrSize = key_touch_SsCalcLfsrSize(snsClkDivider, conversionsNum);
            lfsrScale = key_touch_SsCalcLfsrScale(snsClkDivider, lfsrSize);
        #else
            lfsrSize = (uint8)key_touch_CSX_TX_CLK_SOURCE;
            lfsrScale = 0u;
        #endif /* (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSX_TX_CLK_SOURCE) */

        ptrWdgt->snsClkSource = lfsrSize | (uint8)(lfsrScale << key_touch_CLK_SOURCE_LFSR_SCALE_OFFSET);
    }
#endif /* ((key_touch_ENABLE == key_touch_CSX_EN) && (key_touch_ENABLE == key_touch_CSDV2)) */


#if(((key_touch_ENABLE == key_touch_CSX_EN) && \
     (key_touch_ENABLE == key_touch_CSDV2) && \
     (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSX_TX_CLK_SOURCE)) ||\
    ((key_touch_ENABLE == key_touch_CSD_EN) && \
     (key_touch_ENABLE == key_touch_CSDV2) && \
     (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE)))
/*******************************************************************************
* Function Name: key_touch_SsCSDCalcLfsr
****************************************************************************//**
*
* \brief
*   This is an internal function that finds a SSC polynomial size in the Auto mode.
*
* \details
*   The SSC polynomial size in the auto mode is found based on the following
*   requirements:
*   - an LFSR value should be selected so that the max clock dither is limited with +/-10%.
*   - at least one full spread spectrum polynomial should pass during the scan time.
*   - the value of the number of conversions should be an integer multiple of the
*     repeat period of the programmed LFSR_SIZE.
*
* \param
*  snsClkDivider The divider value for the sense clock.
*  resolution The widget resolution.
*
* \return lfsrSize The LFSRSIZE value for the SENSE_PERIOD register.
*
*******************************************************************************/
static CY_INLINE  uint8 key_touch_SsCalcLfsrSize(uint32 snsClkDivider, uint32 conversionsNum)
{
    uint8 lfsrSize = 0u;

    /* Find LFSR value */
    if((key_touch_SNSCLK_SSC4_THRESHOLD <= snsClkDivider) &&
       (key_touch_SNSCLK_SSC4_PERIOD <= conversionsNum) &&
       (0uL == (conversionsNum % key_touch_SNSCLK_SSC4_PERIOD)))
    {
        lfsrSize = key_touch_CLK_SOURCE_SSC4;
    }
    else if((key_touch_SNSCLK_SSC3_THRESHOLD <= snsClkDivider) &&
            (key_touch_SNSCLK_SSC3_PERIOD <= conversionsNum) &&
            (0uL == (conversionsNum % key_touch_SNSCLK_SSC3_PERIOD)))
    {
        lfsrSize = key_touch_CLK_SOURCE_SSC3;
    }
    else if((key_touch_SNSCLK_SSC2_THRESHOLD <= snsClkDivider) &&
            (key_touch_SNSCLK_SSC2_PERIOD <= conversionsNum) &&
            (0uL == (conversionsNum % key_touch_SNSCLK_SSC2_PERIOD)))
    {
        lfsrSize = key_touch_CLK_SOURCE_SSC2;
    }
    else if((key_touch_SNSCLK_SSC1_THRESHOLD <= snsClkDivider) &&
            (key_touch_SNSCLK_SSC1_PERIOD <= conversionsNum) &&
            (0uL == (conversionsNum % key_touch_SNSCLK_SSC1_PERIOD)))
    {
        lfsrSize = key_touch_CLK_SOURCE_SSC1;
    }
    else
    {
        lfsrSize = (uint8)key_touch_CLK_SOURCE_DIRECT;
    }

    return (lfsrSize);
}


/*******************************************************************************
* Function Name: key_touch_SsCSDCalcLfsr
****************************************************************************//**
*
* \brief
*   This is an internal function that calculates the LFSR scale value.
*
* \details
*   The LFSR scale value is used to increase the clock dither if the desired dither
*   is wider than can be achieved with the current Sense Clock Divider and current LFSR
*   period.
*
*   This returns the LFSR scale value needed to keep the clock dither in
*   range +/-10%.
*
* \param
*  snsClkDivider The divider value for the sense clock.
*  lfsrSize The period of the LFSR sequence.
*           For devices with key_touch_CSDV2_REF9P6UA_EN = TRUE, the
*           mode parameters can take the following values:
*           key_touch_CLK_SOURCE_DIRECT The spreadspectrum is not used.
*           key_touch_CLK_SOURCE_SSC1   The length of LFSR sequence is 63 cycles.
*           key_touch_CLK_SOURCE_SSC2   The length of LFSR sequence is 127 cycles.
*           key_touch_CLK_SOURCE_SSC3   The length of LFSR sequence is 255 cycles.
*           key_touch_CLK_SOURCE_SSC4   The length of LFSR sequence is 511 cycles.
*
*           For devices with key_touch_CSDV2_REF9P6UA_EN = TRUE, the
*           mode parameters can take the following values:
*           key_touch_CLK_SOURCE_DIRECT The spreadspectrum is not used.
*           key_touch_CLK_SOURCE_SSC1   The length of LFSR sequence is 3 cycles.
*           key_touch_CLK_SOURCE_SSC2   The length of LFSR sequence is 7 cycles.
*           key_touch_CLK_SOURCE_SSC3   The length of LFSR sequence is 15 cycles.
*           key_touch_CLK_SOURCE_SSC4   The length of LFSR sequence is 31 cycles.
*
* \return The LFSR scale value needed to keep the clock dither in range +/-10%.
*
*******************************************************************************/
static CY_INLINE uint8 key_touch_SsCalcLfsrScale(uint32 snsClkDivider, uint8 lfsrSize)
{
    uint32 lfsrScale;
    uint32 lfsrRange;
    uint32 lfsrDither;

    /* Initialize the lfsrSize variable with the LFSR Range for given Lfsr Size. */
    switch(lfsrSize)
    {
        case key_touch_CLK_SOURCE_SSC1:
        {
            lfsrRange = key_touch_SNSCLK_SSC1_RANGE;
            break;
        }
        case key_touch_CLK_SOURCE_SSC2:
        {
            lfsrRange = key_touch_SNSCLK_SSC2_RANGE;
            break;
        }
        case key_touch_CLK_SOURCE_SSC3:
        {
            lfsrRange = key_touch_SNSCLK_SSC3_RANGE;
            break;
        }
        case key_touch_CLK_SOURCE_SSC4:
        {
            lfsrRange = key_touch_SNSCLK_SSC4_RANGE;
            break;
        }
        default:
        {
            lfsrRange = 0u;
            break;
        }
    }

    /* Calculate the LFSR Scale value that is required to keep the Clock dither
     * as close as possible to the +/-10% limit of the used frequency.
     */
    if((lfsrSize != key_touch_CLK_SOURCE_DIRECT) && (0u != lfsrRange))
    {
        /* Calculate the LFSR Dither in percents. */
        lfsrDither  = ((lfsrRange * 100uL) / snsClkDivider);
        lfsrScale = 0uL;
        
        while(lfsrDither < key_touch_LFSR_DITHER_PERCENTAGE)
        {
            lfsrScale++;
            lfsrDither <<=1uL;
        }

        if(lfsrDither > key_touch_LFSR_DITHER_PERCENTAGE)
        {
            lfsrScale--;
        }
    }
    else
    {
        lfsrScale = 0uL;
    }

    return ((uint8)lfsrScale);
}
#endif /* (((key_touch_ENABLE == key_touch_CSX_EN) &&  \
            (key_touch_ENABLE == key_touch_CSDV2) &&  \
            (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSX_TX_CLK_SOURCE)) ||\
          ((key_touch_ENABLE == key_touch_CSD_EN) &&  \
           (key_touch_ENABLE == key_touch_CSDV2) &&  \
           (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE))) */


#if ((key_touch_ENABLE == key_touch_CSD_EN) ||\
    (key_touch_ENABLE == key_touch_CSD2X_EN))
    /*******************************************************************************
    * Function Name: key_touch_SsClearCSDSensors
    ****************************************************************************//**
    *
    * \brief
    *  Resets all the CSD sensors to the non-sampling state by sequentially
    *  disconnecting all the sensors from the Analog MUX bus and putting them to
    *  an inactive state.
    *
    * \details
    *   The function goes through all the widgets and updates appropriate bits in
    *   the IO HSIOM, PC and DR registers depending on the Inactive sensor connection
    *   parameter. DR register bits are set to zero when the Inactive sensor
    *   connection is Ground or Hi-Z.
    *
    *******************************************************************************/
    void key_touch_SsClearCSDSensors(void)
    {
        uint32 wdgtIndex;
        uint32 snsIndex;

        #if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
            uint32 pinIndex;
        #endif /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)  */

        #if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
            /* Declare ptr to sensor IO structure */
            key_touch_FLASH_IO_STRUCT const *curDedicatedSnsIOPtr;
            /*  Pointer to Flash structure holding info of sensor to be scanned  */
            key_touch_FLASH_SNS_STRUCT const *curFlashSnsPtr;
        #endif /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)  */
        key_touch_FLASH_IO_STRUCT const *curSnsIOPtr;

        for (wdgtIndex = 0u; wdgtIndex < key_touch_TOTAL_WIDGETS; wdgtIndex++)
        {
            if (key_touch_SENSE_METHOD_CSD_E ==
                key_touch_GET_SENSE_METHOD(&key_touch_dsFlash.wdgtArray[wdgtIndex]))
            {
                curSnsIOPtr = (key_touch_FLASH_IO_STRUCT const *)
                                                key_touch_dsFlash.wdgtArray[wdgtIndex].ptr2SnsFlash;

                /* Go through all sensors in widget */
                for (snsIndex = 0u; snsIndex < (uint8)key_touch_dsFlash.wdgtArray[(wdgtIndex)].totalNumSns; snsIndex++)
                {
                    #if (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)
                        /* Check ganged sns flag  */
                        if (key_touch_GANGED_SNS_MASK == (key_touch_dsFlash.wdgtArray[wdgtIndex].staticConfig &
                                                                 key_touch_GANGED_SNS_MASK))
                        {
                            /* Get sns pointer */
                            curFlashSnsPtr = (key_touch_FLASH_SNS_STRUCT const *)
                                                               key_touch_dsFlash.wdgtArray[wdgtIndex].ptr2SnsFlash +
                                                               snsIndex;

                            for(pinIndex = 0u; pinIndex < curFlashSnsPtr->numPins; pinIndex++)
                            {
                                /* Get IO pointer for dedicated pin */
                                curDedicatedSnsIOPtr = &key_touch_ioList[curFlashSnsPtr->firstPinId + pinIndex];

                                /* Disconnect dedicated pin */
                                key_touch_CSDDisconnectSns(curDedicatedSnsIOPtr);
                            }
                        }
                        else
                        {
                            /* Disable sensor */
                            key_touch_CSDDisconnectSns(&curSnsIOPtr[snsIndex]);
                        }
                    #else
                        /* Disable sensor */
                        key_touch_CSDDisconnectSns(&curSnsIOPtr[snsIndex]);
                    #endif /* (key_touch_ENABLE == key_touch_CSD_GANGED_SNS_EN)  */
                }
            }
        }
    }

    /*******************************************************************************
    * Function Name: key_touch_SsCSDGetColSnsClkDivider
    ****************************************************************************//**
    *
    * \brief
    *  This function gets the Sense Clock Divider value for one-dimension widgets
    *  and Column Sense Clock divider value for two-dimension widgets.
    *
    * \details
    *  This function gets the Sense Clock Divider value based on the component
    *  configuration. The function is applicable for one-dimension widgets and for
    *  two-dimension widgets.
    *
    * \param
    *  wdgtIndex Specifies the ID of the widget.
    *
    * \return The Sense Clock Divider value for one-dimension widgets
    *         and the Column Sense Clock divider value for two-dimension widgets.
    *
    *******************************************************************************/
    uint32 key_touch_SsCSDGetColSnsClkDivider(uint32 wdgtIndex)
    {
        uint32 retVal;

        /* Get sense divider based on configuration */
        #if (key_touch_ENABLE != key_touch_CSD_COMMON_SNS_CLK_EN)
            key_touch_RAM_WD_BASE_STRUCT *ptrWdgt;

            ptrWdgt = (key_touch_RAM_WD_BASE_STRUCT *)
            key_touch_dsFlash.wdgtArray[wdgtIndex].ptr2WdgtRam;

            retVal = (uint32)(ptrWdgt->snsClk);
        #else
            retVal = (uint32)key_touch_dsRam.snsCsdClk;

            (void)wdgtIndex; /* This parameter is unused in such configurations */
        #endif /* (key_touch_ENABLE == key_touch_CSD_COMMON_SNS_CLK_EN) */

        return (retVal);
    }


    #if (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN))
        /*******************************************************************************
        * Function Name: key_touch_SsCSDGetRowSnsClkDivider
        ****************************************************************************//**
        *
        * \brief
        *  This function gets the Sense Clock Divider value for one-dimension widgets
        *  and the Column Sense Clock divider value for two-dimension widgets.
        *
        * \details
        *  This function gets the Sense Clock Divider value based on the component
        *  configuration. The function is applicable for one-dimension widgets and for
        *  two-dimension widgets.
        *
        * \param
        *  wdgtIndex Specifies the ID of the widget.
        *
        * \return The Sense Clock Divider value for one-dimension widgets
        *         and Column Sense Clock divider value for two-dimension widgets.
        *
        *******************************************************************************/
        uint32 key_touch_SsCSDGetRowSnsClkDivider(uint32 wdgtIndex)
        {
            uint32 retVal;

            /* Get sense divider based on configuration */
            #if (key_touch_ENABLE != key_touch_CSD_COMMON_SNS_CLK_EN)
                key_touch_RAM_WD_BASE_STRUCT *ptrWdgt;

                ptrWdgt = (key_touch_RAM_WD_BASE_STRUCT *)
                key_touch_dsFlash.wdgtArray[wdgtIndex].ptr2WdgtRam;

                retVal = ptrWdgt->rowSnsClk;
            #else
                retVal = (uint32)key_touch_dsRam.snsCsdClk;

                (void)wdgtIndex; /* This parameter is unused in such configurations */
            #endif /* (key_touch_ENABLE == key_touch_CSD_COMMON_SNS_CLK_EN) */

            return (retVal);
        }
    #endif /* (key_touch_ENABLE == (key_touch_CSD_MATRIX_WIDGET_EN | key_touch_CSD_TOUCHPAD_WIDGET_EN)) */

    #if (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE)
        /*******************************************************************************
        * Function Name: key_touch_SsCSDCalcPrsSize
        ****************************************************************************//**
        *
        * \brief
        *   The function finds PRS polynomial size in the Auto mode.
        *
        * \details
        *   The PRS polynomial size in the Auto mode is found based on the following
        *   requirements:
        *   - at least one full spread spectrum polynomial should pass during scan time.
        *
        * \param
        *  snsClkDivider The divider value for the sense clock.
        *  resolution The widget resolution.
        *
        * \return prsSize PRS value for SENSE_PERIOD register.
        *
        *******************************************************************************/
        uint8 key_touch_SsCSDCalcPrsSize(uint32 snsClkDivider, uint32 resolution)
        {
            uint32 prsSize;
            uint32 modClkDivider;

            #if (key_touch_ENABLE == key_touch_CSDV2)
                modClkDivider = 1uL;
            #else
                #if (key_touch_ENABLE == key_touch_IS_M0S8PERI_BLOCK)
                    modClkDivider = (uint32)key_touch_dsRam.modCsdClk;
                #else
                    modClkDivider = 1uL;
                #endif /* (key_touch_ENABLE == key_touch_IS_M0S8PERI_BLOCK) */
            #endif /* (key_touch_ENABLE == key_touch_CSDV2) */

            if ((snsClkDivider * key_touch_PRS_LENGTH_12_BITS) <
                (modClkDivider * ((0x00000001Lu << resolution) - 1u)))
            {
                /* Set PRS12 mode */
                prsSize = key_touch_PRS_12_CONFIG;
            }
            else if ((snsClkDivider * key_touch_PRS_LENGTH_8_BITS) <
                     (modClkDivider * ((0x00000001Lu << resolution) - 1u)))
            {
                /* Set PRS8 mode */
                prsSize = key_touch_PRS_8_CONFIG;
            }
            else
            {
                /* Set Direct clock mode */
                prsSize = key_touch_CLK_SOURCE_DIRECT;
            }

            return (uint8)prsSize;
        }
    #endif /* (key_touch_CLK_SOURCE_PRSAUTO == key_touch_CSD_SNS_CLK_SOURCE) */
#endif /* ((key_touch_ENABLE == key_touch_CSD_EN) ||\
           (key_touch_ENABLE == key_touch_CSD2X_EN)) */


/* [] END OF FILE */
