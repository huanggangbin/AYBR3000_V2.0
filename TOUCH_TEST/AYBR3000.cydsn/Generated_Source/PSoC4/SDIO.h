/*******************************************************************************
* File Name: SDIO.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SDIO_H) /* Pins SDIO_H */
#define CY_PINS_SDIO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SDIO_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} SDIO_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   SDIO_Read(void);
void    SDIO_Write(uint8 value);
uint8   SDIO_ReadDataReg(void);
#if defined(SDIO__PC) || (CY_PSOC4_4200L) 
    void    SDIO_SetDriveMode(uint8 mode);
#endif
void    SDIO_SetInterruptMode(uint16 position, uint16 mode);
uint8   SDIO_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void SDIO_Sleep(void); 
void SDIO_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(SDIO__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define SDIO_DRIVE_MODE_BITS        (3)
    #define SDIO_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SDIO_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the SDIO_SetDriveMode() function.
         *  @{
         */
        #define SDIO_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define SDIO_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define SDIO_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define SDIO_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define SDIO_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define SDIO_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define SDIO_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define SDIO_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define SDIO_MASK               SDIO__MASK
#define SDIO_SHIFT              SDIO__SHIFT
#define SDIO_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SDIO_SetInterruptMode() function.
     *  @{
     */
        #define SDIO_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define SDIO_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define SDIO_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define SDIO_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(SDIO__SIO)
    #define SDIO_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(SDIO__PC) && (CY_PSOC4_4200L)
    #define SDIO_USBIO_ENABLE               ((uint32)0x80000000u)
    #define SDIO_USBIO_DISABLE              ((uint32)(~SDIO_USBIO_ENABLE))
    #define SDIO_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define SDIO_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define SDIO_USBIO_ENTER_SLEEP          ((uint32)((1u << SDIO_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << SDIO_USBIO_SUSPEND_DEL_SHIFT)))
    #define SDIO_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << SDIO_USBIO_SUSPEND_SHIFT)))
    #define SDIO_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << SDIO_USBIO_SUSPEND_DEL_SHIFT)))
    #define SDIO_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(SDIO__PC)
    /* Port Configuration */
    #define SDIO_PC                 (* (reg32 *) SDIO__PC)
#endif
/* Pin State */
#define SDIO_PS                     (* (reg32 *) SDIO__PS)
/* Data Register */
#define SDIO_DR                     (* (reg32 *) SDIO__DR)
/* Input Buffer Disable Override */
#define SDIO_INP_DIS                (* (reg32 *) SDIO__PC2)

/* Interrupt configuration Registers */
#define SDIO_INTCFG                 (* (reg32 *) SDIO__INTCFG)
#define SDIO_INTSTAT                (* (reg32 *) SDIO__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define SDIO_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(SDIO__SIO)
    #define SDIO_SIO_REG            (* (reg32 *) SDIO__SIO)
#endif /* (SDIO__SIO_CFG) */

/* USBIO registers */
#if !defined(SDIO__PC) && (CY_PSOC4_4200L)
    #define SDIO_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define SDIO_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define SDIO_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define SDIO_DRIVE_MODE_SHIFT       (0x00u)
#define SDIO_DRIVE_MODE_MASK        (0x07u << SDIO_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins SDIO_H */


/* [] END OF FILE */
