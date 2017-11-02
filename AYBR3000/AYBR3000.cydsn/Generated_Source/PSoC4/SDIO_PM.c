/*******************************************************************************
* File Name: SDIO.c  
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
#include "SDIO.h"

static SDIO_BACKUP_STRUCT  SDIO_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: SDIO_Sleep
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
*  \snippet SDIO_SUT.c usage_SDIO_Sleep_Wakeup
*******************************************************************************/
void SDIO_Sleep(void)
{
    #if defined(SDIO__PC)
        SDIO_backup.pcState = SDIO_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            SDIO_backup.usbState = SDIO_CR1_REG;
            SDIO_USB_POWER_REG |= SDIO_USBIO_ENTER_SLEEP;
            SDIO_CR1_REG &= SDIO_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SDIO__SIO)
        SDIO_backup.sioState = SDIO_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        SDIO_SIO_REG &= (uint32)(~SDIO_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: SDIO_Wakeup
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
*  Refer to SDIO_Sleep() for an example usage.
*******************************************************************************/
void SDIO_Wakeup(void)
{
    #if defined(SDIO__PC)
        SDIO_PC = SDIO_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            SDIO_USB_POWER_REG &= SDIO_USBIO_EXIT_SLEEP_PH1;
            SDIO_CR1_REG = SDIO_backup.usbState;
            SDIO_USB_POWER_REG &= SDIO_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SDIO__SIO)
        SDIO_SIO_REG = SDIO_backup.sioState;
    #endif
}


/* [] END OF FILE */
