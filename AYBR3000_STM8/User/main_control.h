//***************************************************************
// Description : ÏµÍ³´¦Àí
// Author      : TanShutian
// Created     : 2014.08.08
// Modified    : None
// Revision    : 1.0
//***************************************************************

#ifndef __MAIN_CONTROL_H
#define __MAIN_CONTROL_H

#include "system.h"


typedef enum {
    MODE_STATE_NONE = 0,
    NOMALMODE_STATE_JH,
    NOMALMODE_STATE_FN,
    NOMALMODE_STATE_CF,
    NOMALMODE_STATE_HQ,
    NOMALMODE_STATE_XF,
    NOMALMODE_STATE_GZ,

    AUTOMODE_STATE_MY,
    AUTOMODE_STATE_XS,
    AUTOMODE_STATE_JH,
    AUTOMODE_STATE_HQ
} Mode_State_TypeDef;


typedef enum {
    STATE_WAKEUP_RUN = 0,            // Õý³£¹¤×÷
    STATE_SLEEP_LOW,                 // Çá¶ÈË¯Ãß×´Ì¬£¬±³¹âÁÁ
    STATE_SLEEP_LOW_05,              // Çá¶ÈË¯Ãß×´Ì¬£¬0.5Ãë»½ÐÑ¸üÐÂLCD
    STATE_SLEEP_LOW_10,              // Çá¶ÈË¯Ãß×´Ì¬£¬10Ãë»½ÐÑ¸üÐÂLCD¼°²ÎÊý
    STATE_SLEEP_HIGH,                // ÖØ¶ÈË¯Ãß×´Ì¬£¬±³¹âÃð
} MainControl_Sleep_State_TypeDef;


#define MAIN_SLEEP_TIME_3S          30
#define MAIN_SLEEP_TIME_10S         100
#define MAIN_SLEEP_TIME_30S         300


#ifdef __MAIN_CONTROL_C

u8 RC_Light_State = DISABLE;                                                // Ò£¿ØÆ÷ÕÕÃ÷×´Ì¬
u8 RC_Light_State_Flag = DISABLE;                                           //  ÀäÅ¯
u8 RC_HeatLight_State = DISABLE;                                            // Ò£¿ØÆ÷µÆÅ¯×´Ì¬
Mode_State_TypeDef Mode_State = MODE_STATE_NONE;
Mode_State_TypeDef Mode_State_Old = MODE_STATE_NONE;

MainControl_Sleep_State_TypeDef MainControl_Sleep_State = STATE_WAKEUP_RUN;    // Ë¯Ãß×´Ì¬±êÊ¶
u16 MainControl_WaKeUpToSleepLow_TimeCount = 0;
u16 MainControl_WaKeUpToSleepHigh_TimeCount = 0;
u16 MainControl_ToDownLoadData_TimeCount = 0;

u8 GPIO_IN_Set_Flag = 0;
u8 GPIO_IN_ReSet_Flag = 0;

#else

extern u8 RC_Light_State;
extern u8 RC_Light_State_Flag;
extern u8 RC_HeatLight_State;
extern Mode_State_TypeDef Mode_State;
extern Mode_State_TypeDef Mode_State_Old;

extern MainControl_Sleep_State_TypeDef MainControl_Sleep_State;
extern u16 MainControl_WaKeUpToSleepLow_TimeCount;
extern u16 MainControl_WaKeUpToSleepHigh_TimeCount;
extern u16 MainControl_ToDownLoadData_TimeCount;

extern u8 GPIO_IN_Set_Flag;
extern u8 GPIO_IN_ReSet_Flag;

#endif

#define Main_Read_Sleep_Is_WaKeUpToSleepLow()      (MainControl_WaKeUpToSleepLow_TimeCount > MAIN_SLEEP_TIME_3S)
#define Main_Read_Sleep_Is_WaKeUpToSleepHigh()     (MainControl_WaKeUpToSleepHigh_TimeCount > 100)
#define Main_Read_Sleep_Is_ToDownLoadData()        (MainControl_ToDownLoadData_TimeCount > MAIN_SLEEP_TIME_3S)

#define Main_ReSet_WaKeUpToSleepLow()               (MainControl_WaKeUpToSleepLow_TimeCount = 0)
#define Main_ReSet_WaKeUpToSleepHigh()              (MainControl_WaKeUpToSleepHigh_TimeCount = 0)
#define Main_ReSet_ToDownLoadData()                 (MainControl_ToDownLoadData_TimeCount = 0)



void Main_Control_Sleep(void);
void Main_Control_Sleep_V2(void);

#endif

