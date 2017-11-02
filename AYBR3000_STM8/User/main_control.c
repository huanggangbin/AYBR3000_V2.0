//***************************************************************
// Description : 系统处理
// Author      : TanShutian
// Created     : 2014.08.08
// Modified    : None
// Revision    : 1.0
//***************************************************************
#define __MAIN_CONTROL_C

#include "main_control.h"
#include "lcd_driver.h"

/*****************************************
  需要修改的地方
*****************************************/
  FunctionalState Key_WakeUP_Flag = DISABLE;
  FunctionalState Key_UpEvent_Flag_1 = DISABLE;
  FunctionalState Key_UpEvent_Flag_2 = DISABLE;
  FunctionalState Key_UpEvent_Flag_3 = DISABLE;
  u8 ComControl_Step = 0;


void Main_Control_TIM4_On(void) 
{
    CLK->PCKENR1 |= 0x04;      // 给TIM4提供时钟
    TIM4->CR1 |= 0x01 ;        // 开启定时器
}

void Main_Control_TIM4_Off(void) 
{
    TIM4->CR1 &= ~0x01 ;        // 停止定时器
    CLK->PCKENR1 &= ~0x04;      // 停止给TIM4提供时钟
}

/********************************************************/
// 睡眠控制
void Main_Control_Sleep(void) 
{

    if ( ComControl_Step != 6 ) {
        return;
    }

    if ( Main_Read_Sleep_Is_WaKeUpToSleepHigh() ) 
    {
        // 关闭定时器
        Main_Control_TIM4_Off();

        // LCD设置
        LCD_GLASS_Sleep();
    
        // 关闭RTC中断
        RTC_WakeUpCmd(DISABLE);
        
        MainControl_Sleep_State = STATE_SLEEP_HIGH;
        Key_WakeUP_Flag = ENABLE;

        // 进入睡眠
        PWR_FastWakeUpCmd(DISABLE);
    
        PWR_UltraLowPowerCmd(ENABLE);

        // MCU激活级别:
        // AL-0:主激活级别；
        // AL-1:中断激活级别；MCU可以直接回到低功耗模式而不需要运行主程序的；ISR可以进行相应判断，通过重设AL位来启动主程序。
        CFG->GCR |= CFG_GCR_AL;

        // 设置按键为中断输入
        GPIO_Key_Sleep_Set();
        
        nop();
        nop();
        halt();
        nop();
        nop();
        nop();

        LCD_GLASS_WakeUp();
        
        RTC_WakeUpCmd(ENABLE);
        
        // 按键动作唤醒
        // 开启定时器
        Main_Control_TIM4_On();
        MainControl_Sleep_State = STATE_WAKEUP_RUN;
        // 设置按键为不带中断输入
        GPIO_Key_WakeUp_Set();

        // 清除计数
        Main_ReSet_WaKeUpToSleepLow();
        Main_ReSet_WaKeUpToSleepHigh();
        Main_ReSet_ToDownLoadData();

        LCD_Set_BackLight_On();
    } 
    else if (Main_Read_Sleep_Is_WaKeUpToSleepLow()) 
    {
        // 关闭定时器
        Main_Control_TIM4_Off();
        
        MainControl_Sleep_State = STATE_SLEEP_LOW;
        // 设置按键为中断输入
        GPIO_Key_Sleep_Set();

        // 进入睡眠
        PWR_FastWakeUpCmd(DISABLE);
    
        PWR_UltraLowPowerCmd(ENABLE);

        // MCU激活级别:
        // AL-0:主激活级别；
        // AL-1:中断激活级别；MCU可以直接回到低功耗模式而不需要运行主程序的；ISR可以进行相应判断，通过重设AL位来启动主程序。
        CFG->GCR |= CFG_GCR_AL;
        
        nop();
        nop();
        nop();
        wfi();
        nop();
        nop();
        nop();

        // 按键动作唤醒
        // 开启定时器
        Main_Control_TIM4_On();
        MainControl_Sleep_State = STATE_WAKEUP_RUN;
        // 设置按键为不带中断输入
        GPIO_Key_WakeUp_Set();

        // 清除计数
        Main_ReSet_WaKeUpToSleepLow();
        
    }

}


/********************************************************/
// 睡眠控制
void Main_Control_Sleep_V2(void) 
{

    if ( ComControl_Step != 6 ) 
    {
        return;
    }

    if ( Main_Read_Sleep_Is_WaKeUpToSleepHigh() ) 
    {
        // 清除设置模式
        // 关闭定时器
        Main_Control_TIM4_Off();

        // LCD设置
        LCD_GLASS_Sleep();
        
        MainControl_Sleep_State = STATE_SLEEP_HIGH;
        Key_WakeUP_Flag = ENABLE;
        // 设置按键为中断输入
        System_Interr_Close();
        GPIO_Key_Sleep_Set();

        // 进入睡眠
        PWR_FastWakeUpCmd(DISABLE);
    
        PWR_UltraLowPowerCmd(ENABLE);

        // MCU激活级别:
        // AL-0:主激活级别；
        // AL-1:中断激活级别；MCU可以直接回到低功耗模式而不需要运行主程序的；ISR可以进行相应判断，通过重设AL位来启动主程序。
        CFG->GCR |= CFG_GCR_AL;
        
        nop();
        nop();
        nop();
        GPIO_IN_Set_Flag = 1;
        System_Interr_Open();
        halt();
        nop();
        nop();
        nop();

        LCD_GLASS_WakeUp();
        
        // 按键动作唤醒
        // 开启定时器
        Main_Control_TIM4_On();
        MainControl_Sleep_State = STATE_WAKEUP_RUN;
        // 设置按键为不带中断输入
        GPIO_Key_WakeUp_Set();

        // 清除计数
        Main_ReSet_WaKeUpToSleepLow();
        Main_ReSet_WaKeUpToSleepHigh();
        Main_ReSet_ToDownLoadData();

        // 修改为，有按键后在点亮屏幕
        // LCD_Set_BackLight_On();

        Key_UpEvent_Flag_1 = DISABLE;
        Key_UpEvent_Flag_2 = DISABLE;
        Key_UpEvent_Flag_3 = DISABLE;
    } 

}


