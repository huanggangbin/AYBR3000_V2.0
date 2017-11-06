#include "app_time.h"
#include "app_lcd_display.h"

static App_set_time_mode time_set_mode;
static App_set_time_command command;
static App_set_time time;

static const uint8 add_period =  250 / APP_TIME_SCHEDULE_PERIOD;

static void app_time_display(void);
static void app_time_send(void);
static void app_time_mode_deal(void);
static void app_time_normal_command_deal(void);

void app_time_init(void)
{
    time_set_mode.mode = APP_TIME_MODE_INIT;
    time_set_mode.fast = APP_TIME_FAST_NO;
    command = APP_TIME_CMD_NO;
    time.hour = 12;
    time.minute = 0;
}

void app_time_process(void)
{
    //正常命令处理
    app_time_normal_command_deal();
    //状态处理
    app_time_mode_deal();

    if (command != APP_TIME_CMD_NO)    //如果本次处理有命令到达
    {
        command = APP_TIME_CMD_NO;   //命令处理后清空
        //时间发送
        app_time_send();
    }

    //时间显示
    app_time_display();
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

static void app_time_display(void)
{
    static Tube_value number_to_tube[10] = {VALUE_0,VALUE_1,VALUE_2,VALUE_3,VALUE_4,VALUE_5,VALUE_6,VALUE_7,VALUE_8,VALUE_9};
    
    switch(time_set_mode.mode)
    {
        case APP_TIME_MODE_INIT:
            app_lcd_display_set_icon(INDEX_ICON_COLON, ICON_STATE_BLINK);
            app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_HOUR_TENS, DIGIT_TUBE_STATE_ON, number_to_tube[time.hour / 10]);
            app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_HOUR_ONES, DIGIT_TUBE_STATE_ON, number_to_tube[time.hour % 10]);
            app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_MINUTE_TENS, DIGIT_TUBE_STATE_ON, number_to_tube[time.minute / 10]);
            app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_MINUTE_ONES, DIGIT_TUBE_STATE_ON, number_to_tube[time.minute % 10]);
            break;
        case APP_TIME_MODE_HOUR:
            app_lcd_display_set_icon(INDEX_ICON_COLON, ICON_STATE_ON);
            app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_HOUR_TENS, DIGIT_TUBE_STATE_BLINK, number_to_tube[time.hour / 10]);
            app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_HOUR_ONES, DIGIT_TUBE_STATE_BLINK, number_to_tube[time.hour % 10]);
            app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_MINUTE_TENS, DIGIT_TUBE_STATE_ON, number_to_tube[time.minute / 10]);
            app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_MINUTE_ONES, DIGIT_TUBE_STATE_ON, number_to_tube[time.minute % 10]);
            break;
        case APP_TIME_MODE_MINUTE:
            app_lcd_display_set_icon(INDEX_ICON_COLON, ICON_STATE_ON);
            app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_HOUR_TENS, DIGIT_TUBE_STATE_ON, number_to_tube[time.hour / 10]);
            app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_HOUR_ONES, DIGIT_TUBE_STATE_ON, number_to_tube[time.hour % 10]);
            app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_MINUTE_TENS, DIGIT_TUBE_STATE_BLINK, number_to_tube[time.minute / 10]);
            app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_MINUTE_ONES, DIGIT_TUBE_STATE_BLINK, number_to_tube[time.minute % 10]);
            break;
    }
    app_lcd_display_refresh();
}

static void app_time_send(void)
{
    app_frame_send.time_hour = time.hour;
    app_frame_send.time_minute = time.minute;
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
            //定时状态busy下,按下了除定时+/-,温度+,长按温度+以外的键，会发送这个命令
            time_set_mode.mode = APP_TIME_MODE_INIT;
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



