//***************************************************************
// Description : 系统配置
// Author      : TST
// Created     : 2014.04.23
// Modified    : None
// Revision    : 1.0
//***************************************************************

#include "system.h"
#include "stm8l15x_iwdg.h"
#include "main_control.h"
#include "stm8l15x_spi.h"

void Clock_Configuration(void) 
{

    u16 delay = 0;
    
    while ( delay < 50000 ) 
    {
        delay++;
        asm("nop");
    }//上电延时50000个指令周期
    
    CLK_LSEConfig(CLK_LSE_ON);   //配置外部低速时钟打开，32.768K
    while (CLK_GetFlagStatus(CLK_FLAG_LSERDY) == RESET);            //判断外部低速晶振准备完毕flag
    CLK_RTCClockConfig(CLK_RTCCLKSource_LSE, CLK_RTCCLKDiv_1);          //RTC时钟源LSE，分频因子

    CLK->CKDIVR = 0x01;                  // 主时钟2分频,8M, 周期125ns
    CLK->ICKCR  = 0x11;                  // 启用内部RC=16mhz
    while( (CLK->ICKCR & 0x02)==0 );     // 等待时钟稳定

    CLK->PCKENR1 = 0x04;                 // 给TIM4提供时钟
}


void IWDG_Configuration(void) 
{
    #define RELOAD_VALUE   0xFF

    /* Enable IWDG (the LSI oscillator will be enabled by hardware) */
    IWDG_Enable();

    /* IWDG timeout equal to 214 ms (the timeout may varies due to LSI frequency
     dispersion) */
    /* Enable write access to IWDG_PR and IWDG_RLR registers */
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);

    /* IWDG configuration: IWDG is clocked by LSI = 38KHz */
    IWDG_SetPrescaler(IWDG_Prescaler_256);

    /* IWDG timeout equal to 214.7 ms (the timeout may varies due to LSI frequency dispersion) */
    /* IWDG timeout = (RELOAD_VALUE + 1) * Prescaler / LSI 
                  = (254 + 1) * 128 / 38 000 
                  = 214.7 ms */
    IWDG_SetReload((u8)RELOAD_VALUE);

    /* Reload IWDG counter */
    IWDG_ReloadCounter();
}

// 100us时钟基准
void TIM4_Configuration(void) 
{ 
       
    TIM4_SetCounter(0);  //counter值递增
    TIM4_TimeBaseInit(TIM4_Prescaler_32, 249);   //32预分频, 自动重装值249
    TIM4->EGR = 0x01;       //手动重置counter中的值(包括预分频器中的计数)
    TIM4_ITConfig(TIM4_IT_Update, ENABLE);
    TIM4_ARRPreloadConfig(ENABLE);    //直接写影子寄存器的值还是预装载寄存器的值
    //影子寄存器溢出的时候，会从预装载寄存器拷贝
    TIM4_ClearFlag(TIM4_FLAG_Update);
    TIM4_Cmd(ENABLE);
    
}

void GPIO_Key_Sleep_Set(void) 
{
    
    GPIOG->ODR &= ~GPIO_Pin_7;
    GPIOG->ODR &= ~GPIO_Pin_6;
    GPIOG->ODR &= ~GPIO_Pin_5;
    GPIOG->ODR &= ~GPIO_Pin_4;

    // 配置为悬浮中断输入
    GPIO_Init(GPIOC, GPIO_Pin_3, GPIO_Mode_In_FL_IT);
    GPIO_Init(GPIOC, GPIO_Pin_1, GPIO_Mode_In_FL_IT);
    GPIO_Init(GPIOC, GPIO_Pin_0, GPIO_Mode_In_FL_IT);

    EXTI_DeInit();

    EXTI->CR1 = 0xAA;
    EXTI->CR2 = 0xAA;
    EXTI->CR3 = 0xAA;
    EXTI->CR4 = 0x0A;
    //EXTI_SetPinSensitivity(GPIO_Pin_3, EXTI_Trigger_Falling);
    //EXTI_SetPinSensitivity(GPIO_Pin_1, EXTI_Trigger_Falling);
    //EXTI_SetPinSensitivity(GPIO_Pin_0, EXTI_Trigger_Falling);

    GPIO_IN_ReSet_Flag = 0;

    GPIO_Init(GPIOF, GPIO_Pin_7, GPIO_Mode_Out_OD_HiZ_Fast);        // SDO
    GPIOF->ODR &= ~GPIO_Pin_7;
}

void GPIO_Key_WakeUp_Set(void) 
{
    GPIOG->ODR |= GPIO_Pin_7;
    GPIOG->ODR |= GPIO_Pin_6;
    GPIOG->ODR |= GPIO_Pin_5;
    GPIOG->ODR |= GPIO_Pin_4;

    // 配置为悬浮不带中断输入
    GPIO_Init(GPIOC, GPIO_Pin_3, GPIO_Mode_In_FL_No_IT);
    GPIO_Init(GPIOC, GPIO_Pin_1, GPIO_Mode_In_FL_No_IT);
    GPIO_Init(GPIOC, GPIO_Pin_0, GPIO_Mode_In_FL_No_IT);

    GPIO_IN_ReSet_Flag = 1;

    GPIO_Init(GPIOF, GPIO_Pin_7, GPIO_Mode_In_FL_No_IT);        // SDO
}

void GPIO_Configuration(void) 
{
    
    // LED背光
    GPIOF->ODR &= ~GPIO_Pin_0;
    GPIO_Init(GPIOF, GPIO_Pin_0, GPIO_Mode_Out_PP_High_Fast);
    //LCD稳压电路开关
    GPIOD->ODR &= ~GPIO_Pin_6;
    GPIO_Init(GPIOD, GPIO_Pin_6, GPIO_Mode_Out_PP_High_Fast);
    
    //简易自制数据传输口
    GPIOA->ODR &= ~GPIO_Pin_0;
    GPIOA->ODR &= ~GPIO_Pin_0;
    GPIO_Init(GPIOC, GPIO_Pin_1, GPIO_Mode_In_FL_IT);
    GPIO_Init(GPIOC, GPIO_Pin_0, GPIO_Mode_In_FL_No_IT);
    //A7105的4根数据线
    GPIOA->ODR &= ~GPIO_Pin_0;
    GPIOD->ODR &= ~GPIO_Pin_7;
    GPIOC->ODR &= ~GPIO_Pin_2;
    GPIOC->ODR &= ~GPIO_Pin_7;
    GPIO_Init(GPIOA, GPIO_Pin_3, GPIO_Mode_Out_PP_High_Fast);    //SCS
    GPIO_Init(GPIOD, GPIO_Pin_7, GPIO_Mode_In_PU_IT);   //GIO1
    GPIO_Init(GPIOC, GPIO_Pin_2, GPIO_Mode_In_PU_No_IT);   //SDIO
    GPIO_Init(GPIOC, GPIO_Pin_7, GPIO_Mode_Out_PP_High_Fast);   //SCK
    //唤醒口，低电平有效 
    GPIOE->ODR |= GPIO_Pin_7;
    GPIO_Init(GPIOE, GPIO_Pin_7, GPIO_Mode_Out_PP_High_Fast);
    //GIO1脚上的下降沿中断
    EXTI_DeInit();
    EXTI_SetPinSensitivity(EXTI_Pin_7, EXTI_Trigger_Falling);           //GIO1脚的下降沿中断
    EXTI_SetPinSensitivity(EXTI_Pin_1, EXTI_Trigger_Rising);            //CLOCK脚的上升沿中断
}

