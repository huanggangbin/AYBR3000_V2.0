/*******************************************************************************
* File Name: SCS.c  
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
#include "SCS.h"

static SCS_BACKUP_STRUCT  SCS_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: SCS_Sleep
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
*  \snippet SCS_SUT.c usage_SCS_Sleep_Wakeup
*******************************************************************************/
void SCS_Sleep(void)
{
    #if defined(SCS__PC)
        SCS_backup.pcState = SCS_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            SCS_backup.usbState = SCS_CR1_REG;
            SCS_USB_POWER_REG |= SCS_USBIO_ENTER_SLEEP;
            SCS_CR1_REG &= SCS_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SCS__SIO)
        SCS_backup.sioState = SCS_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        SCS_SIO_REG &= (uint32)(~SCS_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: SCS_Wakeup
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
*  Refer to SCS_Sleep() for an example usage.
*******************************************************************************/
void SCS_Wakeup(void)
{
    #if defined(SCS__PC)
        SCS_PC = SCS_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            SCS_USB_POWER_REG &= SCS_USBIO_EXIT_SLEEP_PH1;
            SCS_CR1_REG = SCS_backup.usbState;
            SCS_USB_POWER_REG &= SCS_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SCS__SIO)
        SCS_SIO_REG = SCS_backup.sioState;
    #endif
}


/* [] END OF FILE */
