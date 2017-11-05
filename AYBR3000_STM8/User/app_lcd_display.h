#ifndef _APP_LCD_DISPLAY_H_
#define _APP_LCD_DISPLAY_H_
#include "stm8l15x.h"
#include <string.h>
#include "timing.h"
#include "app_lcd_display_config.h"

typedef struct
{
    App_lcd_ctrl_func control_func;
    Switch state;
}App_lcd_work_unit;

typedef enum
{
    APP_LCD_BLINK_INIT,
    APP_LCD_BLINK_ON,
    APP_LCD_BLINK_OFF,
}App_lcd_blink_state;

typedef enum
{
    UINT_TIME_OFF,
    UINT_TIME_ON,
    UINT_TIME_BLINK,
}App_lcd_time_state;

typedef struct
{
    App_lcd_time_unit_index unit;
    App_lcd_ctrl_func control_func;
    App_lcd_time_state state;
    //闪烁相关的变量
    App_lcd_blink_state blink_state;
    Timing_type blink_timing;
}App_lcd_time_unit;

extern void app_lcd_display_init(void);
extern void app_lcd_display_process(void);
extern void app_lcd_display_set_work(App_lcd_work_unit_index unit, Switch state);
extern void app_lcd_display_set_time(App_lcd_time_unit_index unit, App_lcd_time_state state);
#endif

