//***************************************************************
// Description : LCD´¦Àí
// Author      : TST
// Created     : 2016.02.13
// Modified    : None
// Revision    : 1.0
//***************************************************************

#ifndef _LCD_FIRMWARE_H_
#define _LCD_FIRMWARE_H_

#include "system.h"
#include "types.h"
#define LCD_Set_BackLight_On()                  GPIOF->ODR |= GPIO_Pin_0
#define LCD_Set_BackLight_Off()                  GPIOF->ODR &= ~GPIO_Pin_0

void LCD_GLASS_Init(void);
void LCD_GLASS_Sleep(void);
void LCD_GLASS_WakeUp(void);

void LCD_GLASS_Refresh(uint8 * buffer, uint8 len);
//void LCD_GLASS_Control(void);
//void LCD_GLASS_Refresh_Time(void);

#endif

