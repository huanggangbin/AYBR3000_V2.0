/*******************************************************************************
* File Name: SIMPLE_CLOCK.h  
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

#if !defined(CY_PINS_SIMPLE_CLOCK_ALIASES_H) /* Pins SIMPLE_CLOCK_ALIASES_H */
#define CY_PINS_SIMPLE_CLOCK_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define SIMPLE_CLOCK_0			(SIMPLE_CLOCK__0__PC)
#define SIMPLE_CLOCK_0_PS		(SIMPLE_CLOCK__0__PS)
#define SIMPLE_CLOCK_0_PC		(SIMPLE_CLOCK__0__PC)
#define SIMPLE_CLOCK_0_DR		(SIMPLE_CLOCK__0__DR)
#define SIMPLE_CLOCK_0_SHIFT	(SIMPLE_CLOCK__0__SHIFT)
#define SIMPLE_CLOCK_0_INTR	((uint16)((uint16)0x0003u << (SIMPLE_CLOCK__0__SHIFT*2u)))

#define SIMPLE_CLOCK_INTR_ALL	 ((uint16)(SIMPLE_CLOCK_0_INTR))


#endif /* End Pins SIMPLE_CLOCK_ALIASES_H */


/* [] END OF FILE */
