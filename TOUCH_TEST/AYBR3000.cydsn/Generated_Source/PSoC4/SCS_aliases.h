/*******************************************************************************
* File Name: SCS.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SCS_ALIASES_H) /* Pins SCS_ALIASES_H */
#define CY_PINS_SCS_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define SCS_0			(SCS__0__PC)
#define SCS_0_PS		(SCS__0__PS)
#define SCS_0_PC		(SCS__0__PC)
#define SCS_0_DR		(SCS__0__DR)
#define SCS_0_SHIFT	(SCS__0__SHIFT)
#define SCS_0_INTR	((uint16)((uint16)0x0003u << (SCS__0__SHIFT*2u)))

#define SCS_INTR_ALL	 ((uint16)(SCS_0_INTR))


#endif /* End Pins SCS_ALIASES_H */


/* [] END OF FILE */
