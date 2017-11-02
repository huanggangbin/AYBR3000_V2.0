//***************************************************************
// Description : RTC¥¶¿Ì
// Author      : TST
// Created     : 2016.02.20
// Modified    : None
// Revision    : 1.0
//***************************************************************

#ifndef _RTC_DRIVER_H_
#define _RTC_DRIVER_H_

#include "system.h"



extern RTC_TimeTypeDef RTC_TIME_USER;
extern u8 RTC_Write_Event;

void Driver_RTC_Init(void);
void Driver_RTC_Process(void);

#endif

