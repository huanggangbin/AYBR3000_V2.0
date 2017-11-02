/*******************************************************************************
* File Name: GIO1.h  
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

#if !defined(CY_PINS_GIO1_ALIASES_H) /* Pins GIO1_ALIASES_H */
#define CY_PINS_GIO1_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define GIO1_0			(GIO1__0__PC)
#define GIO1_0_PS		(GIO1__0__PS)
#define GIO1_0_PC		(GIO1__0__PC)
#define GIO1_0_DR		(GIO1__0__DR)
#define GIO1_0_SHIFT	(GIO1__0__SHIFT)
#define GIO1_0_INTR	((uint16)((uint16)0x0003u << (GIO1__0__SHIFT*2u)))

#define GIO1_INTR_ALL	 ((uint16)(GIO1_0_INTR))


#endif /* End Pins GIO1_ALIASES_H */


/* [] END OF FILE */
