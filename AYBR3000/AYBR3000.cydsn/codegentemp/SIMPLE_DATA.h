/*******************************************************************************
* File Name: SIMPLE_DATA.h  
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

#if !defined(CY_PINS_SIMPLE_DATA_H) /* Pins SIMPLE_DATA_H */
#define CY_PINS_SIMPLE_DATA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SIMPLE_DATA_aliases.h"


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
} SIMPLE_DATA_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   SIMPLE_DATA_Read(void);
void    SIMPLE_DATA_Write(uint8 value);
uint8   SIMPLE_DATA_ReadDataReg(void);
#if defined(SIMPLE_DATA__PC) || (CY_PSOC4_4200L) 
    void    SIMPLE_DATA_SetDriveMode(uint8 mode);
#endif
void    SIMPLE_DATA_SetInterruptMode(uint16 position, uint16 mode);
uint8   SIMPLE_DATA_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void SIMPLE_DATA_Sleep(void); 
void SIMPLE_DATA_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(SIMPLE_DATA__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define SIMPLE_DATA_DRIVE_MODE_BITS        (3)
    #define SIMPLE_DATA_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SIMPLE_DATA_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the SIMPLE_DATA_SetDriveMode() function.
         *  @{
         */
        #define SIMPLE_DATA_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define SIMPLE_DATA_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define SIMPLE_DATA_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define SIMPLE_DATA_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define SIMPLE_DATA_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define SIMPLE_DATA_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define SIMPLE_DATA_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define SIMPLE_DATA_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define SIMPLE_DATA_MASK               SIMPLE_DATA__MASK
#define SIMPLE_DATA_SHIFT              SIMPLE_DATA__SHIFT
#define SIMPLE_DATA_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SIMPLE_DATA_SetInterruptMode() function.
     *  @{
     */
        #define SIMPLE_DATA_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define SIMPLE_DATA_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define SIMPLE_DATA_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define SIMPLE_DATA_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(SIMPLE_DATA__SIO)
    #define SIMPLE_DATA_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(SIMPLE_DATA__PC) && (CY_PSOC4_4200L)
    #define SIMPLE_DATA_USBIO_ENABLE               ((uint32)0x80000000u)
    #define SIMPLE_DATA_USBIO_DISABLE              ((uint32)(~SIMPLE_DATA_USBIO_ENABLE))
    #define SIMPLE_DATA_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define SIMPLE_DATA_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define SIMPLE_DATA_USBIO_ENTER_SLEEP          ((uint32)((1u << SIMPLE_DATA_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << SIMPLE_DATA_USBIO_SUSPEND_DEL_SHIFT)))
    #define SIMPLE_DATA_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << SIMPLE_DATA_USBIO_SUSPEND_SHIFT)))
    #define SIMPLE_DATA_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << SIMPLE_DATA_USBIO_SUSPEND_DEL_SHIFT)))
    #define SIMPLE_DATA_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(SIMPLE_DATA__PC)
    /* Port Configuration */
    #define SIMPLE_DATA_PC                 (* (reg32 *) SIMPLE_DATA__PC)
#endif
/* Pin State */
#define SIMPLE_DATA_PS                     (* (reg32 *) SIMPLE_DATA__PS)
/* Data Register */
#define SIMPLE_DATA_DR                     (* (reg32 *) SIMPLE_DATA__DR)
/* Input Buffer Disable Override */
#define SIMPLE_DATA_INP_DIS                (* (reg32 *) SIMPLE_DATA__PC2)

/* Interrupt configuration Registers */
#define SIMPLE_DATA_INTCFG                 (* (reg32 *) SIMPLE_DATA__INTCFG)
#define SIMPLE_DATA_INTSTAT                (* (reg32 *) SIMPLE_DATA__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define SIMPLE_DATA_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(SIMPLE_DATA__SIO)
    #define SIMPLE_DATA_SIO_REG            (* (reg32 *) SIMPLE_DATA__SIO)
#endif /* (SIMPLE_DATA__SIO_CFG) */

/* USBIO registers */
#if !defined(SIMPLE_DATA__PC) && (CY_PSOC4_4200L)
    #define SIMPLE_DATA_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define SIMPLE_DATA_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define SIMPLE_DATA_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define SIMPLE_DATA_DRIVE_MODE_SHIFT       (0x00u)
#define SIMPLE_DATA_DRIVE_MODE_MASK        (0x07u << SIMPLE_DATA_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins SIMPLE_DATA_H */


/* [] END OF FILE */
