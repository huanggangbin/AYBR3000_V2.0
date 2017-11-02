/*******************************************************************************
* File Name: SDIO.h  
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

#if !defined(CY_PINS_SDIO_ALIASES_H) /* Pins SDIO_ALIASES_H */
#define CY_PINS_SDIO_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define SDIO_0			(SDIO__0__PC)
#define SDIO_0_PS		(SDIO__0__PS)
#define SDIO_0_PC		(SDIO__0__PC)
#define SDIO_0_DR		(SDIO__0__DR)
#define SDIO_0_SHIFT	(SDIO__0__SHIFT)
#define SDIO_0_INTR	((uint16)((uint16)0x0003u << (SDIO__0__SHIFT*2u)))

#define SDIO_INTR_ALL	 ((uint16)(SDIO_0_INTR))


#endif /* End Pins SDIO_ALIASES_H */


/* [] END OF FILE */
