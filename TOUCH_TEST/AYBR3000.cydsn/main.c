/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "A7105_driver.h"
#include "timing.h"
#include "key.h"
#include "simple_protocol.h"
CY_ISR_PROTO(time_1ms_Interrupt);
CY_ISR_PROTO(gio1_interrupt);
typedef struct
{
    uint8 zhaoming : 1;
    uint8 baidong  : 1;
    uint8 qiang    : 1;
    uint8 ruo      : 1;
    uint8 zidong   : 1;
    uint8 beep     : 1;
}Combine_function;

typedef enum
{
    DAI_JI,
    HUAN_QI,
    JING_HUA,
    XIN_FENG,
    FENG_NUAN,
    FENG_NUAN_QIANG,
    FENG_NUAN_RUO,
    CHUI_FENG,
    GAN_ZAO,
    DENG_NUAN_RUO,
    DENG_NUAN_QIANG,
    XIN_FENG_FENG_NUAN,
    ZHI_NENG_GAN_ZAO,
    ZHI_NENG_MU_YU_1,
    ZHI_NENG_MU_YU_2,
    ZHI_NENG_JING_HUA,
    CHUI_FENG_JING_HUA,
    FUNCTION_NUMBERS,
}Mutex_function_mode;

Mutex_function_mode mutex_function_mode = DAI_JI;

uint8 t = 0;
uint8 send_buffer[24] = {0}; 
uint8 send_show_buffer[16] = {0};
uint8 receive_buffer[24] = {0};
uint16 timer_count = 0;
uint8 src_ID[4] = {1, 2, 3, 4};
uint8 dest_ID[4] = {0};

#define TOUCH_TUNE_SWITCH
//#define SEND_TUNE_SWITCH
#define DATA_BUFFER_LENGTH   20


static void make_data(uint8 *buffer);

typedef enum
{
    READ_STATE,
    CONTROL,
    MATCH_CODE,
    CONNECT_NET,
    DISCONNECT_NET,
}Command_type;


Command_type *command_type = (Command_type *)&send_show_buffer[0];  //send_show_buffer[0];    这位是查询、控制、对码、配网、解绑
Combine_function *p_combine_function = (Combine_function *)&send_show_buffer[1];
Mutex_function_mode *p_mutex_function = (Mutex_function_mode *)&send_show_buffer[2];


uint8 *wendu = &send_show_buffer[3];        //温度
uint8 *dingshi = &send_show_buffer[4];        //时间
uint8 *xiaoshi = &send_show_buffer[5];
uint8 *fenzhong = &send_show_buffer[6];

uint8 time_feng_nuan = 90;    //60 - 120 
uint8 time_huan_qi = 30;      //30 - 60
uint8 time_xin_feng = 30;    //15 - 60
uint8 time_xin_feng_qu_nuan = 90;  //60 - 120
uint8 time_zhi_jing = 120;   //90 - 150
uint8 time_zhi_mu = 90;   //60 - 120

uint8 temp_xin_feng_qn = 35;   //30 - 40
uint8 temp_fengnuan = 35;

typedef enum
{
    GUAN_JI,
    ZHI_GAN,
    ZHI_JING,
    ZHI_MU,
}ZHI_NENG_MODE;
ZHI_NENG_MODE zhi_neng_mode = GUAN_JI;

typedef enum
{
    QAING,
    RUO,
    ZI_DONG,
}QIANG_RUO_MODE;
QIANG_RUO_MODE qiang_ruo_mode = QAING;
Bool send_flag = FALSE;


uint8 beij_s=0,beij_m=0,beij_h=12;
static uint8 timer_10ms=0;

Bool lcd_on = FALSE;
uint16 LCD_on_count = 0;

typedef enum
{
    WAIT_LONG_PRESS,
    WAIT_SHORT_PRESS,
    WAIT_MESSAGE,
}Match_code_state;
Match_code_state match_code_state = WAIT_LONG_PRESS;
Bool match_code = FALSE;
Timing_type match_code_wait;

static void beij_timer(void);
static void key_deal(void);
static void match_code_mode(void);

int main(void)
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    //A7105_init();
    key_init();
    //GIO1_ISR_Disable();         //端口默认电平是高电平，需要忽略这个下降沿
    //GIO1_Write(0);
    //GIO1_ISR_ClearPending();
    //GIO1_ISR_Enable();
    
    
#ifdef TOUCH_TUNE_SWITCH 
    
    EZI2C_Start(); /* Start EZI2C Component */
    /*
    * Set up communication and initialize data buffer to CapSense data structure
    * to use Tuner application
    */
    EZI2C_EzI2CSetBuffer1(sizeof(key_touch_dsRam), sizeof(key_touch_dsRam),(uint8 *)&key_touch_dsRam);

#endif
    Timer_1_Start();  //开定时器
    
    time_1ms_ISR_StartEx(time_1ms_Interrupt);      //自定义中断服务函数
    //GIO1_ISR_StartEx(gio1_interrupt);            //指定外部中断GIO1中断函数
    key_touch_Start(); /* Initialize Component */
    key_touch_ScanAllWidgets(); /* Scan all widgets */
#ifdef SEND_TUNE_SWITCH
    simple_protocol_init();
#endif
    (*fenzhong) = beij_m;
    (*xiaoshi) = beij_h;
    for(;;)
    {
        /* Do this only when a scan is done */
        if (timer_count >= 10)
        {   
            timer_count = 0;
            timer_10ms++;
            LCD_on_count++;
            
            if (LCD_on_count > 50000)
                LCD_on_count = 10000;
            
            if(key_touch_NOT_BUSY == key_touch_IsBusy()) 
            {
                key_touch_ProcessAllWidgets(); 
                
    #ifdef TOUCH_TUNE_SWITCH             
                key_touch_RunTuner(); 
    #endif
                key_scan();      //触控按键的状态已经更新
                
                key_touch_ScanAllWidgets(); 
            }
        }
        beij_timer();
        
        if (LCD_on_count > 800)
        {
            if (lcd_on)
            {
                lcd_on = FALSE;
            }
        }
        key_deal();
        match_code_mode();
        
        
        if (send_flag)
        {
            send_flag = FALSE;
            make_data(send_show_buffer);
            //simple_protocol_send(send_buffer, DATA_BUFFER_LENGTH); 
            make_data(send_show_buffer);
            //send_data_by_A7105(DATA_BUFFER_LENGTH, send_buffer);
        }
        #ifdef SEND_TUNE_SWITCH
        simple_protocol_process();
        #endif
        
        /* Place your application code here. */
    }
}

CY_ISR(time_1ms_Interrupt)
{
    timer_count++;
    timing_count();
    Timer_1_ClearInterrupt(Timer_1_INTR_MASK_TC);
}

CY_ISR(gio1_interrupt)
{
    A7105_update_wtr(TRUE);
    //GIO1_ClearInterrupt();
}


static void make_data(uint8 *buffer)
{
    uint8 i, check_sum = 0;
    
    
    send_buffer[0] = 0x5a;
    send_buffer[1] = 0x01;
    send_buffer[2] = src_ID[0];
    send_buffer[3] = src_ID[1];
    send_buffer[4] = src_ID[2];
    send_buffer[5] = src_ID[3];
    send_buffer[6] = dest_ID[0];
    send_buffer[7] = dest_ID[1];
    send_buffer[8] = dest_ID[2];
    send_buffer[9] = dest_ID[3];
    
    for (i = 0; i < DATA_BUFFER_LENGTH - 11; i++)
        send_buffer[10 + i] = buffer[i];
        
    for (i = 0; i < DATA_BUFFER_LENGTH - 1; i++)
        check_sum += send_buffer[i];
        
    send_buffer[DATA_BUFFER_LENGTH - 1] = ~check_sum + 1;
}

static void key_deal(void)
{
    Key_index i;
    for (i = 0; i < KEY_NUM; i++)
    {
        if (key_is_short_pressed(i))
        {
            /*
            LCD_on_count = 0;
            if (lcd_on == FALSE)
            {
                *command_type = READ_STATE;
                lcd_on = TRUE;
            }
            else
            {
               
            }*/
            *command_type = CONTROL; 
            switch(i)
            {
                case KEY_DIAN_YUAN: 
                    if (*p_mutex_function == DAI_JI)
                        *p_mutex_function = DAI_JI;
                    else
                        *p_mutex_function = DAI_JI;

                    send_flag = TRUE;
                    break;
                case KEY_FENG_NUAN: 
                    if (*p_mutex_function == FENG_NUAN)
                        *p_mutex_function = DAI_JI;
                    else
                    {
                        *p_mutex_function = FENG_NUAN;
                        p_combine_function->ruo = 0;
                        p_combine_function->zidong = 0;
                        p_combine_function->qiang = 1;
                    }
                    
                    (*wendu) = 35;        //温度
                    (*dingshi) = 90;        //时间
                    send_flag = TRUE;
                    break;
                case KEY_WENDU_JIA: 
                    if(*p_mutex_function == FENG_NUAN)
                    {
                        if ((*wendu) < 40)
                            (*wendu)++;
                    }
                    if(*p_mutex_function == XIN_FENG_FENG_NUAN)
                    {
                        if ((*wendu) < 40)
                            (*wendu)++;
                    }
                    send_flag = TRUE;
                    break;
                case KEY_WENDU_JIAN: 
                    if(*p_mutex_function == FENG_NUAN)
                    {
                        if ((*wendu) > 30)
                            (*wendu)--;
                    }
                    if(*p_mutex_function == XIN_FENG_FENG_NUAN)
                    {
                        if ((*wendu) > 30)
                            (*wendu)--;
                    }
                    send_flag = TRUE;
                    break;
                case KEY_XIN_FENG: 
                    if (*p_mutex_function == XIN_FENG)
                        *p_mutex_function = DAI_JI;
                    else
                    {
                        *p_mutex_function = XIN_FENG;
                        p_combine_function->qiang = 1;
                        p_combine_function->ruo = 0;
                        p_combine_function->zidong = 0;
                    }
                    (*wendu) = 0;        //温度
                    (*dingshi) = 30;        //时间
                    send_flag = TRUE;
                    break;
                case KEY_QING_RUO:
                    if ((*p_mutex_function != HUAN_QI)
                    &&(*p_mutex_function != XIN_FENG)
                    &&(*p_mutex_function != FENG_NUAN)
                    &&(*p_mutex_function != XIN_FENG_FENG_NUAN))
                    {break;}

                    p_combine_function->qiang = 0;
                    p_combine_function->ruo = 0;
                    p_combine_function->zidong = 0;
                    switch(qiang_ruo_mode)
                    {
                        case QAING: 
                            qiang_ruo_mode = RUO;
                            p_combine_function->ruo = 1;
                            break;
                        case RUO:
                            qiang_ruo_mode = ZI_DONG;
                            p_combine_function->zidong = 1;
                            break;
                        case ZI_DONG: 
                            p_combine_function->qiang = 1;
                            qiang_ruo_mode = QAING;
                            break;
                    }
                    send_flag = TRUE;
                    break;
                case KEY_HUAN_QI: 
                    if (*p_mutex_function == HUAN_QI)
                        *p_mutex_function = DAI_JI;
                    else
                    {
                        *p_mutex_function = HUAN_QI;
                        p_combine_function->qiang = 1;
                        p_combine_function->ruo = 0;
                        p_combine_function->zidong = 0;
                    }
                    p_combine_function->baidong = 0;
                    (*wendu) = 0;        //温度
                    (*dingshi) = 30;        //时间
                    send_flag = TRUE;
                    break;
                case KEY_XIN_FENG_QU_NUAN: 
                    if (*p_mutex_function == XIN_FENG_FENG_NUAN)
                        *p_mutex_function = DAI_JI;
                    else
                    {
                        *p_mutex_function = XIN_FENG_FENG_NUAN;
                        p_combine_function->qiang = 1;
                        p_combine_function->ruo = 0;
                        p_combine_function->zidong = 0;
                    }
                    (*wendu) = 35;        //温度
                    (*dingshi) = 90;        //时间
                    send_flag = TRUE;
                    break;
                case KEY_DINGSHI_JIA: 
                    if (*p_mutex_function == FENG_NUAN)
                    {
                        if ((*dingshi) < 120)
                            (*dingshi) += 15;
                    }
                    if (*p_mutex_function == XIN_FENG)
                    {
                        if ((*dingshi) < 60)
                            (*dingshi) += 15;
                    }
                    if (*p_mutex_function == HUAN_QI)
                    {
                        if ((*dingshi) < 60)
                            (*dingshi) += 15;
                    }
                    if (*p_mutex_function == XIN_FENG_FENG_NUAN)
                    {
                        if ((*dingshi) < 120)
                            (*dingshi) += 15;
                    }
                    if (*p_mutex_function == ZHI_NENG_JING_HUA)
                    {
                        if ((*dingshi) < 150)
                            (*dingshi) += 15;
                    }
                    if (*p_mutex_function == ZHI_NENG_MU_YU_1)
                    {
                        if ((*dingshi) < 120)
                            (*dingshi) += 15;
                    }
                    send_flag = TRUE;
                    break;
                case KEY_DINGSHI_JIAN: 
                    if (*p_mutex_function == FENG_NUAN)
                    {
                        if ((*dingshi) > 60)
                            (*dingshi) -= 15;
                    }
                    if (*p_mutex_function == XIN_FENG)
                    {
                        if ((*dingshi) > 15)
                            (*dingshi) -= 15;
                    }
                    if (*p_mutex_function == HUAN_QI)
                    {
                        if ((*dingshi) > 30)
                            (*dingshi) -= 15;
                    }
                    if (*p_mutex_function == XIN_FENG_FENG_NUAN)
                    {
                        if ((*dingshi) > 60)
                            (*dingshi) -= 15;
                    }
                    if (*p_mutex_function == ZHI_NENG_JING_HUA)
                    {
                        if ((*dingshi) > 90)
                            (*dingshi) -= 15;
                    }
                    if (*p_mutex_function == ZHI_NENG_MU_YU_1)
                    {
                        if ((*dingshi) > 60)
                            (*dingshi) -= 15;
                    }
                    send_flag = TRUE;
                    break;
                case KEY_BAI_DONG: 
                    if ((*p_mutex_function != XIN_FENG)
                    &&(*p_mutex_function != FENG_NUAN)
                    &&(*p_mutex_function != XIN_FENG_FENG_NUAN))
                    {break;}
                    if (p_combine_function->baidong)
                        p_combine_function->baidong = 0;
                    else
                        p_combine_function->baidong = 1;
                    send_flag = TRUE;
                    break;
                case KEY_ZHI_NENG: 
                    if ((*p_mutex_function == DAI_JI) 
                    ||(*p_mutex_function == ZHI_NENG_GAN_ZAO)
                    ||(*p_mutex_function == ZHI_NENG_JING_HUA)
                    ||(*p_mutex_function == ZHI_NENG_MU_YU_1))
                    {
                        switch(zhi_neng_mode)
                        {
                            case GUAN_JI: 
                                zhi_neng_mode = ZHI_GAN;
                                *p_mutex_function = ZHI_NENG_GAN_ZAO;
                                break;
                            case ZHI_GAN: 
                                zhi_neng_mode = ZHI_JING;
                                (*wendu) = 0;        //温度
                                (*dingshi) = 120;        //时间
                                *p_mutex_function = ZHI_NENG_JING_HUA;
                                break;
                            case ZHI_JING:
                                zhi_neng_mode = ZHI_MU;
                                (*wendu) = 0;        //温度
                                (*dingshi) = 90;        //时间
                                *p_mutex_function = ZHI_NENG_MU_YU_1;
                                break;
                            case ZHI_MU: 
                                zhi_neng_mode = GUAN_JI;
                                *p_mutex_function = DAI_JI;
                                break;
                        }
                    }
                    else
                    {
                        *p_mutex_function = DAI_JI;
                        zhi_neng_mode = GUAN_JI;
                    }
                    send_flag = TRUE;
                    break;
                default : break;
            }
        }
        
        if (key_is_long_pressed(KEY_DIAN_YUAN))
        {
            match_code = TRUE;
            *command_type = MATCH_CODE;
            send_flag = TRUE;
        }

        if (key_is_long_pressed(KEY_WENDU_JIA))
        {
            *command_type = CONNECT_NET;
            send_flag = TRUE;
        }
        if (key_is_long_pressed(KEY_WENDU_JIAN))
        {
            *command_type = DISCONNECT_NET;
            send_flag = TRUE;
        }
        
        if (*p_mutex_function == DAI_JI)
        {
            p_combine_function->qiang = 0;
            p_combine_function->ruo = 0;
            p_combine_function->zidong = 0;
            p_combine_function->baidong = 0;
            qiang_ruo_mode = QAING;
        }
    }
}
static void beij_timer(void)
{//100ms调用
    if(timer_10ms>=100){
        timer_10ms=0;
        beij_s++;
        if(beij_s>=60){
            beij_s=0;
            beij_m++;
            
            (*fenzhong) = beij_m;
            make_data(send_show_buffer);
            send_data_by_A7105(16, send_buffer);
            if(beij_m>=60){
                beij_h++;
                if(beij_h>=24){
                    beij_h=0;
                    (*xiaoshi) = beij_h;
                    make_data(send_show_buffer);
                    send_data_by_A7105(16, send_buffer);
                }
            }
        }
    }
}

static Bool ID_check_ok(uint8 * id1, uint8 * id2);

static void match_code_mode(void)
{
 
 
    switch(match_code_state)
    {
        case WAIT_LONG_PRESS: 
            if (match_code)
            {
                match_code = FALSE;
                match_code_state = WAIT_SHORT_PRESS;
                timing_set_counts(&match_code_wait, 3000);
            }
            break;
        case WAIT_SHORT_PRESS: 
            if (timing_count_end(&match_code_wait))
                match_code_state = WAIT_SHORT_PRESS;
            match_code_state = WAIT_MESSAGE;
            //if(key_is_short_pressed(KEY_QING_RUO)) {}
            break;
        case WAIT_MESSAGE:
            if (timing_count_end(&match_code_wait))
                match_code_state = WAIT_SHORT_PRESS;
            if (receive_data_by_A7105(16, receive_buffer))
            {
                if (ID_check_ok(&receive_buffer[6], src_ID))
                {
                    dest_ID[0] = receive_buffer[2];
                    dest_ID[1] = receive_buffer[3];
                    dest_ID[2] = receive_buffer[4];
                    dest_ID[3] = receive_buffer[5];
                }
                match_code_state = WAIT_SHORT_PRESS;
            }
            break;
    }
}

static Bool ID_check_ok(uint8 * id1, uint8 * id2)
{
    uint8 i;
    
    for (i = 0; i < 4; i++)
    {
        if (id1[i] != id2[i])
            return FALSE;
    }
    return TRUE;
}
//*[] END OF FILE */  

