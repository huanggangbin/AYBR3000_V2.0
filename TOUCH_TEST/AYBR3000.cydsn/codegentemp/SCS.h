/*******************************************************************************
* File Name: SCS.h  
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

#if !defined(CY_PINS_SCS_H) /* Pins SCS_H */
#define CY_PINS_SCS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SCS_aliases.h"


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
} SCS_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   SCS_Read(void);
void    SCS_Write(uint8 value);
uint8   SCS_ReadDataReg(void);
#if defined(SCS__PC) || (CY_PSOC4_4200L) 
    void    SCS_SetDriveMode(uint8 mode);
#endif
void    SCS_SetInterruptMode(uint16 position, uint16 mode);
uint8   SCS_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void SCS_Sleep(void); 
void SCS_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(SCS__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define SCS_DRIVE_MODE_BITS        (3)
    #define SCS_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SCS_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the SCS_SetDriveMode() function.
         *  @{
         */
        #define SCS_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define SCS_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define SCS_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define SCS_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define SCS_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define SCS_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define SCS_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define SCS_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define SCS_MASK               SCS__MASK
#define SCS_SHIFT              SCS__SHIFT
#define SCS_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SCS_SetInterruptMode() function.
     *  @{
     */
        #define SCS_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define SCS_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define SCS_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define SCS_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(SCS__SIO)
    #define SCS_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(SCS__PC) && (CY_PSOC4_4200L)
    #define SCS_USBIO_ENABLE               ((uint32)0x80000000u)
    #define SCS_USBIO_DISABLE              ((uint32)(~SCS_USBIO_ENABLE))
    #define SCS_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define SCS_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define SCS_USBIO_ENTER_SLEEP          ((uint32)((1u << SCS_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << SCS_USBIO_SUSPEND_DEL_SHIFT)))
    #define SCS_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << SCS_USBIO_SUSPEND_SHIFT)))
    #define SCS_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << SCS_USBIO_SUSPEND_DEL_SHIFT)))
    #define SCS_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(SCS__PC)
    /* Port Configuration */
    #define SCS_PC                 (* (reg32 *) SCS__PC)
#endif
/* Pin State */
#define SCS_PS                     (* (reg32 *) SCS__PS)
/* Data Register */
#define SCS_DR                     (* (reg32 *) SCS__DR)
/* Input Buffer Disable Override */
#define SCS_INP_DIS                (* (reg32 *) SCS__PC2)

/* Interrupt configuration Registers */
#define SCS_INTCFG                 (* (reg32 *) SCS__INTCFG)
#define SCS_INTSTAT                (* (reg32 *) SCS__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define SCS_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(SCS__SIO)
    #define SCS_SIO_REG            (* (reg32 *) SCS__SIO)
#endif /* (SCS__SIO_CFG) */

/* USBIO registers */
#if !defined(SCS__PC) && (CY_PSOC4_4200L)
    #define SCS_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define SCS_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define SCS_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define SCS_DRIVE_MODE_SHIFT       (0x00u)
#define SCS_DRIVE_MODE_MASK        (0x07u << SCS_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins SCS_H */


/* [] END OF FILE */
