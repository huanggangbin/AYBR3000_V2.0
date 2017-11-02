//***************************************************************
// Description : ������
// Author      : TST
// Created     : 2014.04.23
// Modified    : None
// Revision    : 1.0
//***************************************************************
#include "stm8l15x.h"
#include "system.h"
#include "stm8l15x_itc.h"
#include "types.h"
#include "A7105_driver.h"
#include "LCD_driver.h"
#include "RTC_driver.h"
#include "simple_protocol.h"
#include "task_manager.h"
#include "app_key.h"
#include "protocol.h"
//˯����صĴ���ο�main_control()

RTC_TimeTypeDef RTC_TIME_USER;
u8 RTC_Write_Event = DISABLE;          // ʵʱʱ��д���¼�

void mcu_init(void);
uint8 send_buf[20] = {0};
uint8 temp;

int main(void) 
{
    
    system_inter_close();    /*�ж�����*/
    mcu_init();
    A7105_init();
    LCD_driver_init();
    system_inter_open(); 
    
    task_init();
    app_time_init();
    app_work_mode_init();
    app_key_init();
    protocol_init();
    
    task_add(app_key_process, 10);
    task_add(app_time_process, 10);
    task_add(app_work_mode_process, 10);
    
    while(1)
    {
        task_process();
    }
}

void mcu_init(void)
{
    Clock_Configuration();  /*TIM4�ṩ�ڲ�����8Mʱ�ӣ�RTCģ���ṩ32.768K�ⲿ����ʱ��*/
    GPIO_Configuration();
    TIM4_Configuration();
    LCD_GLASS_Init();
}

