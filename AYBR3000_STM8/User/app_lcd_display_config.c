#include "app_lcd_display_config.h"

App_lcd_icon_ctrl_func icon_ctrl_func[INDEX_ICON_NUMBER];
App_lcd_Tube_ctrl_func digit_tube_ctrl_func[INDEX_DIGIT_TUBE_NUMBER];

static void control_func_qiang(Switch s);
static void control_func_ruo(Switch s);
static void control_func_zi_dong(Switch s);
static void control_func_line(Switch s);
static void control_func_wen_du_she_ding(Switch s);
static void control_func_ding_shi_100(Switch s);
static void control_func_ding_shi_shi_jian(Switch s);
static void control_func_feng_nuan(Switch s);
static void control_func_huan_qi(Switch s);
static void control_func_xin_feng_qu_nuan(Switch s);
static void control_func_xin_feng(Switch s);
static void control_func_bai_dong(Switch s);
static void control_func_ZN_gan_zao(Switch s);
static void control_func_ZN_jing_hua(Switch s);
static void control_func_ZN_mu_yu(Switch s);
static void control_func_colon(Switch s);

App_lcd_icon_ctrl_func icon_ctrl_func[INDEX_ICON_NUMBER] = 
{
    control_func_qiang,                                              
    control_func_ruo,
    control_func_zi_dong,
    control_func_line,
    control_func_wen_du_she_ding,
    control_func_ding_shi_100,
    control_func_ding_shi_shi_jian,
    control_func_feng_nuan,
    control_func_huan_qi,
    control_func_xin_feng_qu_nuan,
    control_func_xin_feng,
    control_func_bai_dong,
    control_func_ZN_gan_zao,
    control_func_ZN_jing_hua,
    control_func_ZN_mu_yu,
    control_func_colon,
};

static void control_func_hour_tens(Tube_value v);
static void control_func_hour_ones(Tube_value v);
static void control_func_minute_tens(Tube_value v);
static void control_func_minute_ones(Tube_value v);
static void control_func_wen_du_tens(Tube_value v);
static void control_func_wen_du_ones(Tube_value v);
static void control_func_ding_shi_tens(Tube_value v);
static void control_func_ding_shi_ones(Tube_value v);

App_lcd_Tube_ctrl_func digit_tube_ctrl_func[INDEX_DIGIT_TUBE_NUMBER] =
{
    control_func_hour_tens,             
    control_func_hour_ones,
    control_func_minute_tens,
    control_func_minute_ones,
    control_func_wen_du_tens,
    control_func_wen_du_ones,
    control_func_ding_shi_tens,
    control_func_ding_shi_ones,
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

static void control_func_hour_tens(Tube_value v)
{
    digital_tube_set(TUBE1, v);
}

static void control_func_hour_ones(Tube_value v)
{
    digital_tube_set(TUBE2, v);
}

static void control_func_minute_tens(Tube_value v)
{
    digital_tube_set(TUBE3, v);
}

static void control_func_minute_ones(Tube_value v)
{
    digital_tube_set(TUBE4, v);
}
static void control_func_wen_du_tens(Tube_value v)
{
   digital_tube_set(TUBE5, v);
}
static void control_func_wen_du_ones(Tube_value v)
{
   digital_tube_set(TUBE6, v);
}
static void control_func_ding_shi_tens(Tube_value v)
{
    digital_tube_set(TUBE7, v);
}

static void control_func_ding_shi_ones(Tube_value v)
{
    digital_tube_set(TUBE8, v);
}
