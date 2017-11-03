#ifndef _APP_LCD_DISPLAY_H_
#define _APP_LCD_DISPLAY_H_
#include "stm8l15x.h"
#include "types.h"
#include <string.h>

typedef void (* Control_func)(Switch s);
typedef void (* App_lcd_func)(App_lcd_unit_index unit, Control_func control_func);

typedef enum
{
    APP_LCD_UINT_QIANG,
    APP_LCD_UINT_RUO,
    APP_LCD_UINT_ZI_DONG,
    APP_LCD_UINT_BAI_DONG_UNUSED,
    APP_LCD_UINT_LINE,
    APP_LCD_UINT_DING_SHI_100,
    APP_LCD_UINT_WEN_DU_SHE_DING,
    APP_LCD_UINT_FENG_NUAN,
    APP_LCD_UINT_HUAN_QI,
    APP_LCD_UINT_XIN_FENG_QU_NUAN,
    APP_LCD_UINT_XIN_FENG,
    APP_LCD_UINT_BAI_DONG,
    APP_LCD_UINT_ZN_GAN_ZAO,
    APP_LCD_UINT_ZN_JING_HUA,
    APP_LCD_UINT_ZN_MU_YU,
}App_lcd_work_unit_index;

typedef struct
{
    App_lcd_work_unit_index unit;
    Control_func control_func;
    Switch state;
}App_lcd_work_unit;

typedef enum
{
    APP_LCD_UNIT_COLON,
    APP_LCD_UNIT_HOUR,
    APP_LCD_UNIT_MINUTE,
}App_lcd_time_unit_index;

typedef struct
{
    App_lcd_time_unit_index unit;
    Control_func control_func;
    Switch state;
    //闪烁相关的变量
    FunctionalState blink;
    App_lcd_func blink_func;
}App_lcd_time_unit;

#endif

