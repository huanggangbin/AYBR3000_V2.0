#ifndef _APP_LCD_DISPLAY_H_
#define _APP_LCD_DISPLAY_H_
#include "stm8l15x.h"
#include <string.h>
#include "timing.h"
   
#include "app_lcd_display_config.h"

typedef enum
{
    ICON_STATE_OFF,
    ICON_STATE_ON,
    ICON_STATE_BLINK,
}App_lcd_icon_state;

typedef enum
{
    APP_LCD_BLINK_INIT,
    APP_LCD_BLINK_ON,
    APP_LCD_BLINK_OFF,
}App_lcd_blink_state;

typedef struct
{
    App_lcd_icon_state state;
    App_lcd_icon_ctrl_func control_func;
    //闪烁相关的变量
    App_lcd_blink_state blink_state;
    uint16 blink_half_period;
    Timing_type blink_timing;
}App_lcd_icon;

typedef enum
{
    DIGIT_TUBE_STATE_OFF,
    DIGIT_TUBE_STATE_ON,
    DIGIT_TUBE_STATE_BLINK,
}App_lcd_digit_tube_state;

typedef struct
{
    App_lcd_digit_tube_state state;
    App_lcd_Tube_ctrl_func control_func;
    Tube_value value;
    //闪烁相关的变量
    App_lcd_blink_state blink_state;
    uint16 blink_half_period;
    Timing_type blink_timing;
}App_lcd_digit_tube;


extern void app_lcd_display_init(void);
extern void app_lcd_display_process(void);
extern void app_lcd_display_set_icon(App_lcd_index_icon i, App_lcd_icon_state state);
extern void app_lcd_display_set_digit_tube(App_lcd_index_digit_tube i, App_lcd_digit_tube_state state, Tube_value value);
extern void app_lcd_display_refresh(void);
#endif

