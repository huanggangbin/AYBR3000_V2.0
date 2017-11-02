//***************************************************************
// Description : œµÕ≥≈‰÷√
// Author      : TST
// Created     : 2014.04.23
// Modified    : None
// Revision    : 1.0
//***************************************************************
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "stm8l15x.h"
#include "stm8l15x_gpio.h"
#include "stm8l15x_exti.h"
#include "stm8l15x_clk.h"
#include "stm8l15x_lcd.h"
#include "stm8l15x_spi.h"

#define TIME_INIT_10MS 10
#define TIME_INIT_2MS 2

#define system_inter_close()  __asm("sim")
#define system_inter_open()  __asm("rim")

void Clock_Configuration(void);
void IWDG_Configuration(void);
void TIM4_Configuration(void);

void GPIO_Key_Sleep_Set(void);
void GPIO_Key_WakeUp_Set(void);
void GPIO_Configuration(void);

void System_UniqueDeviceID_Read(void);

void Array_Vary(u8 *array);
void delay_2us(u16 delay_cnt);
void Delay_MS(u16 n);
#endif

