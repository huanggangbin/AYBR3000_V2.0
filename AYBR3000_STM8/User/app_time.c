#include "app_time.h"

static App_set_time_mode time_set_mode;
static App_set_time_command command;
static App_set_time time;

static const uint8 add_period =  250 / APP_TIME_SCHEDULE_PERIOD;

static void app_time_display(void);
static void app_time_send(void);
static void app_time_mode_deal(void);
static void app_time_abnormal_command_deal(void);
static void app_time_normal_command_deal(void);

void app_time_init(void)
{
    time_set_mode.mode = APP_TIME_MODE_INIT;
    time_set_mode.fast = APP_TIME_FAST_NO;
    command = APP_TIME_CMD_NO;
    time.hour = 0;
    time.minute = 0;
}

void app_time_process(void)
{
    //���������
    app_time_normal_command_deal();
    //״̬����
    app_time_mode_deal();

    if (command != APP_TIME_CMD_NO)    //������δ����������
    {
        command = APP_TIME_CMD_NO;   //���������
        //ʱ����ʾ
        app_time_display();
        //ʱ�䷢��
        app_time_send();
    }
}

void app_time_event_set(App_set_time_command cmd)
{
    command = cmd;
}

bool app_time_mode_busy(void)
{
    if (time_set_mode.mode !=  APP_TIME_MODE_INIT)
        return TRUE;
    else
        return FALSE;
}

uint8 app_time_get_hour(void)
{
    return time.hour;
}
uint8 app_time_get_mimute(void)
{
    return time.minute;
}

static void app_time_display(void)
{
    
    app_lcd_display_set_time(App_lcd_time_unit_index unit, App_lcd_time_state state);
}

static void app_time_send(void)
{
    app_frame.time_hour = time.hour;
    app_frame.time_minute = time.minute;
}

static void app_time_normal_command_deal(void)
{
    switch(command)
    {
        case APP_TIME_CMD_NO: 
            break;
        case APP_TIME_CMD_START: 
            if (time_set_mode.mode == APP_TIME_MODE_INIT)
                time_set_mode.mode = APP_TIME_MODE_HOUR;
            break;
        case APP_TIME_CMD_CHANGE: 
            if (time_set_mode.mode == APP_TIME_MODE_HOUR)
                time_set_mode.mode = APP_TIME_MODE_MINUTE;
            else if (time_set_mode.mode == APP_TIME_MODE_MINUTE)
                time_set_mode.mode = APP_TIME_MODE_INIT;
            break;
        case APP_TIME_CMD_END:
            //��ʱ״̬busy��,�����˳���ʱ+/-,�¶�+,�����¶�+����ļ����ᷢ���������
            time_set_mode.mode == APP_TIME_MODE_INIT;
            break;
        case APP_TIME_CMD_ADD: 
            if (time_set_mode.mode == APP_TIME_MODE_HOUR)
            {
                if (time.hour < 60)
                    time.hour++;
            }
            else if (time_set_mode.mode == APP_TIME_MODE_MINUTE)
            {
                if (time.minute < 60)
                    time.minute++;
            }
            break;
        case APP_TIME_CMD_MINUS: 
            if (time_set_mode.mode == APP_TIME_MODE_HOUR)
            {
                if (time.hour > 0)
                    time.hour--;
            }
            else if (time_set_mode.mode == APP_TIME_MODE_MINUTE)
            {
                if (time.minute > 0)
                    time.minute--;
            }
            break;
        case APP_TIME_CMD_FAST_ADD: 
            time_set_mode.fast = APP_TIME_FAST_ADD;
        case APP_TIME_CMD_FAST_MINUS:
            time_set_mode.fast = APP_TIME_FAST_MINUS;
            break;
        case APP_TIME_CMD_FAST_STOP:
            time_set_mode.fast = APP_TIME_FAST_NO;
            break;
    
    }
}

static void app_time_mode_deal(void)
{
    switch(time_set_mode.mode)
    {
        static uint16 fast_mode_count = 0;
        
        case APP_TIME_MODE_INIT: 
            break;
        case APP_TIME_MODE_HOUR: 
            switch(time_set_mode.fast)
            {
                case APP_TIME_FAST_NO:
                    fast_mode_count = 0;
                    break;
                case APP_TIME_FAST_ADD: 
                    fast_mode_count++;
                    if (fast_mode_count >= add_period)
                    {
                        if (time.hour == 23)
                            time.hour = 0;
                        else
                            time.hour++;
                    }
                    break;
                case APP_TIME_FAST_MINUS:
                    fast_mode_count++;
                    if (fast_mode_count >= add_period)
                    {
                        if (time.hour == 0)
                            time.hour = 23;
                        else
                            time.hour--;
                    }
                    break;
            }
            break;
        case APP_TIME_MODE_MINUTE: 
            switch(time_set_mode.fast)
            {
                case APP_TIME_FAST_NO:
                    fast_mode_count = 0;
                    break;
                case APP_TIME_FAST_ADD: 
                    fast_mode_count++;
                    if (fast_mode_count >= add_period)
                    {
                        if (time.minute == 59)
                            time.minute = 0;
                        else
                            time.minute++;
                    }
                    break;
                case APP_TIME_FAST_MINUS:
                    fast_mode_count++;
                    if (fast_mode_count >= add_period)
                    {
                        if (time.minute == 0)
                            time.minute = 59;
                        else
                            time.minute--;
                    }
                    break;
            }
            break;
    }
}



