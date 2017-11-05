#include "app_lcd_display_config.h"

static void control_func_qiang(Switch s);
static void control_func_zi_dong(Switch s);
static void control_func_line(Switch s);
static void control_func_ding_shi_100(Switch s);
static void control_func_wen_du_she_ding(Switch s);
static void control_func_feng_nuan(Switch s);
static void control_func_huan_qi(Switch s);
static void control_func_xin_feng_qu_nuan(Switch s);
static void control_func_xin_feng(Switch s);
static void control_func_bai_dong(Switch s);
static void control_func_ZN_gan_zao(Switch s);
static void control_func_ZN_jing_hua(Switch s);
static void control_func_ZN_mu_yu(Switch s);
static void control_func_colon(Switch s);
static void control_func_hour(Switch s);
static void control_func_minute(Switch s);

App_lcd_ctrl_func work_unit_ctrl_func[APP_LCD_WORK_UNIT_NUMBER] = 
{
    control_func_qiang,
    control_func_zi_dong,
    control_func_line,
    control_func_ding_shi_100,
    control_func_wen_du_she_ding,
    control_func_feng_nuan,
    control_func_huan_qi,
    control_func_xin_feng_qu_nuan,
    control_func_xin_feng,
    control_func_bai_dong,
    control_func_ZN_gan_zao,
    control_func_ZN_jing_hua,
    control_func_ZN_mu_yu,
};

App_lcd_ctrl_func time_unit_ctrl_func[APP_LCD_TIME_UNIT_NUMBER] =
{
    control_func_colon,
    control_func_hour,
    control_func_minute,
};

static void control_func_qiang(Switch s)
{
    icon_set(ICON1, s);
}

static void control_func_ruo(Switch s)
{
    icon_set(ICON2, s);
}
static void control_func_zi_dong(Switch s)
{
    icon_set(ICON3, s);
}
static void control_func_line(Switch s)
{
    icon_set(ICON5, s);
}

static void control_func_wen_du_she_ding(Switch s)
{
    icon_set(ICON6, s);
}
static void control_func_ding_shi_100(Switch s)
{
    icon_set(ICON7, s);
}

static void control_func_ding_shi_shi_jian(Switch s)
{
    icon_set(ICON8, s);
}
static void control_func_feng_nuan(Switch s)
{
    icon_set(ICON9, s);
}
static void control_func_huan_qi(Switch s)
{
    icon_set(ICON10, s);
}
static void control_func_xin_feng_qu_nuan(Switch s)
{
    icon_set(ICON11, s);
}
static void control_func_xin_feng(Switch s)
{
    icon_set(ICON12, s);
}
static void control_func_bai_dong(Switch s)
{
    icon_set(ICON13, s);
}
static void control_func_ZN_gan_zao(Switch s)
{
    icon_set(ICON14, s);
}
static void control_func_ZN_jing_hua(Switch s)
{
    icon_set(ICON15, s);
}
static void control_func_ZN_mu_yu(Switch s)
{
    icon_set(ICON16, s);
}
static void control_func_colon(Switch s)
{
    icon_set(ICON17, s);
}

static Tube_value number_to_value[10] = {VALUE_0, VALUE_1, VALUE_2, VALUE_3, VALUE_4, VALUE_5, VALUE_6, VALUE_7, VALUE_8, VALUE_9};
static void control_func_hour(Switch s)
{
    uint8 ones_place, tens_place;
    
    ones_place = APP_LCD_GET_TIME_HOUR() % 10;
    tens_place = APP_LCD_GET_TIME_HOUR() / 10;
    
    if (s == ON)
    {   
        digital_tube_set(TUBE1, number_to_value[tens_place]);
        digital_tube_set(TUBE2, number_to_value[ones_place]);
    }
    else
    {
        digital_tube_set(TUBE1, VALUE_NULL);
        digital_tube_set(TUBE2, VALUE_NULL);
    }
}
static void control_func_minute(Switch s)
{
    uint8 ones_place, tens_place;
    
    ones_place = APP_LCD_GET_TIME_MINUTE() % 10;
    tens_place = APP_LCD_GET_TIME_MINUTE() / 10;
    
    if (s == ON)
    {   
        digital_tube_set(TUBE3, number_to_value[tens_place]);
        digital_tube_set(TUBE4, number_to_value[ones_place]);
    }
    else
    {
        digital_tube_set(TUBE3, VALUE_NULL);
        digital_tube_set(TUBE4, VALUE_NULL);
    }
}


