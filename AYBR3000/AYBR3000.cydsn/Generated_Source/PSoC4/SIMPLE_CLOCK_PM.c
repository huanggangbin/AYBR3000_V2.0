/*******************************************************************************
* File Name: SIMPLE_CLOCK.c  
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
#include "SIMPLE_CLOCK.h"

static SIMPLE_CLOCK_BACKUP_STRUCT  SIMPLE_CLOCK_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: SIMPLE_CLOCK_Sleep
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
*  \snippet SIMPLE_CLOCK_SUT.c usage_SIMPLE_CLOCK_Sleep_Wakeup
*******************************************************************************/
void SIMPLE_CLOCK_Sleep(void)
{
    #if defined(SIMPLE_CLOCK__PC)
        SIMPLE_CLOCK_backup.pcState = SIMPLE_CLOCK_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            SIMPLE_CLOCK_backup.usbState = SIMPLE_CLOCK_CR1_REG;
            SIMPLE_CLOCK_USB_POWER_REG |= SIMPLE_CLOCK_USBIO_ENTER_SLEEP;
            SIMPLE_CLOCK_CR1_REG &= SIMPLE_CLOCK_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SIMPLE_CLOCK__SIO)
        SIMPLE_CLOCK_backup.sioState = SIMPLE_CLOCK_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        SIMPLE_CLOCK_SIO_REG &= (uint32)(~SIMPLE_CLOCK_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: SIMPLE_CLOCK_Wakeup
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
*  Refer to SIMPLE_CLOCK_Sleep() for an example usage.
*******************************************************************************/
void SIMPLE_CLOCK_Wakeup(void)
{
    #if defined(SIMPLE_CLOCK__PC)
        SIMPLE_CLOCK_PC = SIMPLE_CLOCK_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            SIMPLE_CLOCK_USB_POWER_REG &= SIMPLE_CLOCK_USBIO_EXIT_SLEEP_PH1;
            SIMPLE_CLOCK_CR1_REG = SIMPLE_CLOCK_backup.usbState;
            SIMPLE_CLOCK_USB_POWER_REG &= SIMPLE_CLOCK_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SIMPLE_CLOCK__SIO)
        SIMPLE_CLOCK_SIO_REG = SIMPLE_CLOCK_backup.sioState;
    #endif
}


/* [] END OF FILE */
