/*******************************************************************************
* File Name: WAKE_UP.h  
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

#if !defined(CY_PINS_WAKE_UP_H) /* Pins WAKE_UP_H */
#define CY_PINS_WAKE_UP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "WAKE_UP_aliases.h"


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
} WAKE_UP_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   WAKE_UP_Read(void);
void    WAKE_UP_Write(uint8 value);
uint8   WAKE_UP_ReadDataReg(void);
#if defined(WAKE_UP__PC) || (CY_PSOC4_4200L) 
    void    WAKE_UP_SetDriveMode(uint8 mode);
#endif
void    WAKE_UP_SetInterruptMode(uint16 position, uint16 mode);
uint8   WAKE_UP_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void WAKE_UP_Sleep(void); 
void WAKE_UP_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(WAKE_UP__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define WAKE_UP_DRIVE_MODE_BITS        (3)
    #define WAKE_UP_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - WAKE_UP_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the WAKE_UP_SetDriveMode() function.
         *  @{
         */
        #define WAKE_UP_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define WAKE_UP_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define WAKE_UP_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define WAKE_UP_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define WAKE_UP_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define WAKE_UP_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define WAKE_UP_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define WAKE_UP_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define WAKE_UP_MASK               WAKE_UP__MASK
#define WAKE_UP_SHIFT              WAKE_UP__SHIFT
#define WAKE_UP_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in WAKE_UP_SetInterruptMode() function.
     *  @{
     */
        #define WAKE_UP_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define WAKE_UP_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define WAKE_UP_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define WAKE_UP_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(WAKE_UP__SIO)
    #define WAKE_UP_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(WAKE_UP__PC) && (CY_PSOC4_4200L)
    #define WAKE_UP_USBIO_ENABLE               ((uint32)0x80000000u)
    #define WAKE_UP_USBIO_DISABLE              ((uint32)(~WAKE_UP_USBIO_ENABLE))
    #define WAKE_UP_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define WAKE_UP_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define WAKE_UP_USBIO_ENTER_SLEEP          ((uint32)((1u << WAKE_UP_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << WAKE_UP_USBIO_SUSPEND_DEL_SHIFT)))
    #define WAKE_UP_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << WAKE_UP_USBIO_SUSPEND_SHIFT)))
    #define WAKE_UP_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << WAKE_UP_USBIO_SUSPEND_DEL_SHIFT)))
    #define WAKE_UP_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(WAKE_UP__PC)
    /* Port Configuration */
    #define WAKE_UP_PC                 (* (reg32 *) WAKE_UP__PC)
#endif
/* Pin State */
#define WAKE_UP_PS                     (* (reg32 *) WAKE_UP__PS)
/* Data Register */
#define WAKE_UP_DR                     (* (reg32 *) WAKE_UP__DR)
/* Input Buffer Disable Override */
#define WAKE_UP_INP_DIS                (* (reg32 *) WAKE_UP__PC2)

/* Interrupt configuration Registers */
#define WAKE_UP_INTCFG                 (* (reg32 *) WAKE_UP__INTCFG)
#define WAKE_UP_INTSTAT                (* (reg32 *) WAKE_UP__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define WAKE_UP_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(WAKE_UP__SIO)
    #define WAKE_UP_SIO_REG            (* (reg32 *) WAKE_UP__SIO)
#endif /* (WAKE_UP__SIO_CFG) */

/* USBIO registers */
#if !defined(WAKE_UP__PC) && (CY_PSOC4_4200L)
    #define WAKE_UP_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define WAKE_UP_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define WAKE_UP_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define WAKE_UP_DRIVE_MODE_SHIFT       (0x00u)
#define WAKE_UP_DRIVE_MODE_MASK        (0x07u << WAKE_UP_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins WAKE_UP_H */


/* [] END OF FILE */
