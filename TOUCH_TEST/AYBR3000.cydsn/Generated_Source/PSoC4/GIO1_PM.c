/*******************************************************************************
* File Name: GIO1.c  
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
#include "GIO1.h"

static GIO1_BACKUP_STRUCT  GIO1_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: GIO1_Sleep
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
*  \snippet GIO1_SUT.c usage_GIO1_Sleep_Wakeup
*******************************************************************************/
void GIO1_Sleep(void)
{
    #if defined(GIO1__PC)
        GIO1_backup.pcState = GIO1_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            GIO1_backup.usbState = GIO1_CR1_REG;
            GIO1_USB_POWER_REG |= GIO1_USBIO_ENTER_SLEEP;
            GIO1_CR1_REG &= GIO1_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(GIO1__SIO)
        GIO1_backup.sioState = GIO1_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        GIO1_SIO_REG &= (uint32)(~GIO1_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: GIO1_Wakeup
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
*  Refer to GIO1_Sleep() for an example usage.
*******************************************************************************/
void GIO1_Wakeup(void)
{
    #if defined(GIO1__PC)
        GIO1_PC = GIO1_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            GIO1_USB_POWER_REG &= GIO1_USBIO_EXIT_SLEEP_PH1;
            GIO1_CR1_REG = GIO1_backup.usbState;
            GIO1_USB_POWER_REG &= GIO1_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(GIO1__SIO)
        GIO1_SIO_REG = GIO1_backup.sioState;
    #endif
}


/* [] END OF FILE */
