#ifndef _APP_TIME_H_
#define _APP_TIME_H_
#include "types.h"
#include "timing.h"
#include "LCD_driver.h"
#include "app_protocol.h"

//时间设置模式定义
typedef enum
{
    APP_TIME_MODE_INIT,
    APP_TIME_MODE_HOUR,
    APP_TIME_MODE_MINUTE,
}App_time_mode;

typedef enum
{
    APP_TIME_FAST_NO,
    APP_TIME_FAST_ADD,
    APP_TIME_FAST_MINUS,
}App_time_fast;

typedef struct
{
    App_time_mode mode;
    App_time_fast fast;
    
}App_set_time_mode;

//时间设置事件定义
typedef enum
{
    APP_TIME_CMD_NO,
    
    APP_TIME_CMD_START,
    APP_TIME_CMD_CHANGE,
    APP_TIME_CMD_END,
    
    APP_TIME_CMD_ADD,
    APP_TIME_CMD_MINUS,
    APP_TIME_CMD_FAST_ADD,
    APP_TIME_CMD_FAST_MINUS,
    APP_TIME_CMD_FAST_STOP,
}App_set_time_command;

//时间设置参数定义
typedef struct
{
    uint8 hour;
    uint8 minute;
}App_set_time;

#define APP_TIME_SCHEDULE_PERIOD 10

extern void app_time_init(void);
extern void app_time_process(void);
extern void app_time_event_set(App_set_time_command cmd);
extern bool app_time_mode_busy(void);
extern uint8 app_time_get_hour(void);
extern uint8 app_time_get_mimute(void);
#endif

