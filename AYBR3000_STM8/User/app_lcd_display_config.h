#ifndef _APP_LCD_DISPLAY_CONFIG_H_
#define _APP_LCD_DISPLAY_CONFIG_H_
#include "types.h"
#include "LCD_driver.h"
#include "app_time.h"

typedef enum
{
    APP_LCD_WORK_UINT_QIANG,
    APP_LCD_WORK_UINT_RUO,
    APP_LCD_WORK_UINT_ZI_DONG,
    APP_LCD_WORK_UINT_BAI_DONG_UNUSED,
    APP_LCD_WORK_UINT_LINE,
    APP_LCD_WORK_UINT_WEN_DU_SHE_DING,
    APP_LCD_WORK_UINT_DING_SHI_100,
    APP_LCD_WORK_UNIT_DING_SHI_SHI_JIAN,
    APP_LCD_WORK_UINT_FENG_NUAN,
    APP_LCD_WORK_UINT_HUAN_QI,
    APP_LCD_WORK_UINT_XIN_FENG_QU_NUAN,
    APP_LCD_WORK_UINT_XIN_FENG,
    APP_LCD_WORK_UINT_BAI_DONG,
    APP_LCD_WORK_UINT_ZN_GAN_ZAO,
    APP_LCD_WORK_UINT_ZN_JING_HUA,
    APP_LCD_WORK_UINT_ZN_MU_YU,
    APP_LCD_WORK_UNIT_NUMBER,
}App_lcd_work_unit_index;

typedef enum
{
    APP_LCD_TIME_UNIT_COLON,
    APP_LCD_TIME_UNIT_HOUR,
    APP_LCD_TIME_UNIT_MINUTE,
    APP_LCD_TIME_UNIT_NUMBER,
}App_lcd_time_unit_index;

#define APP_LCD_GET_TIME_HOUR()     app_time_get_hour()
#define APP_LCD_GET_TIME_MINUTE()       app_time_get_mimute()
typedef void (* App_lcd_ctrl_func)(Switch s);

extern App_lcd_ctrl_func work_unit_ctrl_func[APP_LCD_WORK_UNIT_NUMBER];
extern App_lcd_ctrl_func time_unit_ctrl_func[APP_LCD_TIME_UNIT_NUMBER];
#endif
