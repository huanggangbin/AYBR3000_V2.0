//***************************************************************
// Description : RTC处理
// Author      : TST
// Created     : 2016.02.20
// Modified    : None
// Revision    : 1.0
//***************************************************************

#include "RTC_driver.h"

void Driver_RTC_Init(void) {
    RTC_InitTypeDef RTC_InitStr;
    u8 count;
    RTC_DateTypeDef RTC_DateStr;

    
    //CLK_RTCClockConfig(CLK_RTCCLKSource_LSE, CLK_RTCCLKDiv_1);
    //while (CLK_GetFlagStatus(CLK_FLAG_LSERDY) == RESET);

    RTC_WakeUpCmd(DISABLE);      //关闭RTC的Wakeup Unit
    CLK_PeripheralClockConfig(CLK_Peripheral_RTC, ENABLE);     //使能RTC外设的时钟  
    RTC_WakeUpClockConfig(RTC_WakeUpClock_RTCCLK_Div16);

    RTC_ITConfig(RTC_IT_WUT, ENABLE);
    
    while ( RTC_GetFlagStatus(RTC_FLAG_WUTWF) == RESET ) 
    {
        //CLK_PeripheralClockConfig(CLK_Peripheral_RTC, ENABLE);
        //RTC_WakeUpClockConfig(RTC_WakeUpClock_RTCCLK_Div16);

        //RTC_ITConfig(RTC_IT_WUT, ENABLE);
    };

    RTC_SetWakeUpCounter(1023);
    
    RTC_WakeUpCmd(ENABLE);


    //ITC_SetSoftwarePriority(RTC_IRQn, ITC_PriorityLevel_3);//优先级

    // 初始化
    RTC_InitStr.RTC_HourFormat = RTC_HourFormat_24;
    RTC_InitStr.RTC_AsynchPrediv = 0x1F;
    RTC_InitStr.RTC_SynchPrediv = 0x03FF;

    count = 5;
    while ( count ) 
    {
        if ( RTC_Init(&RTC_InitStr) != ERROR ) 
        {
            break;
        }
        count--;
    }

    // 日期
    RTC_DateStructInit(&RTC_DateStr);
    RTC_DateStr.RTC_WeekDay = RTC_Weekday_Friday;
    RTC_DateStr.RTC_Date = 1;
    RTC_DateStr.RTC_Month = RTC_Month_April;
    RTC_DateStr.RTC_Year = 16;

    count = 5;
    while ( count ) 
    {
        if ( RTC_SetDate(RTC_Format_BIN, &RTC_DateStr) != ERROR ) 
        {
            break;
        }
        count--;
    }

    // 时间
    RTC_TimeStructInit(&RTC_TIME_USER);
    RTC_TIME_USER.RTC_Seconds = 0;
    RTC_TIME_USER.RTC_Minutes = 0;
    RTC_TIME_USER.RTC_Hours = 12;
    RTC_TIME_USER.RTC_H12 = RTC_H12_AM;

    count = 5;
    while ( count ) 
    {
        if ( RTC_SetTime(RTC_Format_BIN, &RTC_TIME_USER) != ERROR ) 
        {
            break;
        }
        count--;
    }
    
}

void Driver_RTC_Process(void) 
{

    if ( RTC_Write_Event != DISABLE ) 
    {
        RTC_TIME_USER.RTC_Seconds = 0;
        RTC_TIME_USER.RTC_Minutes = 12;
        RTC_TIME_USER.RTC_Hours = 12;
        RTC_SetTime(RTC_Format_BIN, &RTC_TIME_USER);
        RTC_Write_Event = DISABLE;
    } 
    else 
    {
        RTC_GetTime(RTC_Format_BIN, &RTC_TIME_USER);

        if ( RTC_TIME_USER.RTC_Seconds < 60 ) {
            //LCD_Dis_Second = RTC_TIME_USER.RTC_Seconds;'
            ;
        }

        if ( RTC_TIME_USER.RTC_Minutes < 60 ) {
            //LCD_Dis_Minute = RTC_TIME_USER.RTC_Minutes;
            ;
        }

        if ( RTC_TIME_USER.RTC_Hours < 24 ) {
            //LCD_Dis_Hour = RTC_TIME_USER.RTC_Hours;
            ;
        }
    }
}

