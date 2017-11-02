/*******************************************************************************
* File Name: SIMPLE_DATA.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SIMPLE_DATA.h"

static SIMPLE_DATA_BACKUP_STRUCT  SIMPLE_DATA_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: SIMPLE_DATA_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet SIMPLE_DATA_SUT.c usage_SIMPLE_DATA_Sleep_Wakeup
*******************************************************************************/
void SIMPLE_DATA_Sleep(void)
{
    #if defined(SIMPLE_DATA__PC)
        SIMPLE_DATA_backup.pcState = SIMPLE_DATA_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            SIMPLE_DATA_backup.usbState = SIMPLE_DATA_CR1_REG;
            SIMPLE_DATA_USB_POWER_REG |= SIMPLE_DATA_USBIO_ENTER_SLEEP;
            SIMPLE_DATA_CR1_REG &= SIMPLE_DATA_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SIMPLE_DATA__SIO)
        SIMPLE_DATA_backup.sioState = SIMPLE_DATA_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        SIMPLE_DATA_SIO_REG &= (uint32)(~SIMPLE_DATA_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: SIMPLE_DATA_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to SIMPLE_DATA_Sleep() for an example usage.
*******************************************************************************/
void SIMPLE_DATA_Wakeup(void)
{
    #if defined(SIMPLE_DATA__PC)
        SIMPLE_DATA_PC = SIMPLE_DATA_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            SIMPLE_DATA_USB_POWER_REG &= SIMPLE_DATA_USBIO_EXIT_SLEEP_PH1;
            SIMPLE_DATA_CR1_REG = SIMPLE_DATA_backup.usbState;
            SIMPLE_DATA_USB_POWER_REG &= SIMPLE_DATA_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SIMPLE_DATA__SIO)
        SIMPLE_DATA_SIO_REG = SIMPLE_DATA_backup.sioState;
    #endif
}


/* [] END OF FILE */
