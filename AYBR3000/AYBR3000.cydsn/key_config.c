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
#include "key_config.h"



static Level pin_dian_yuan(void);
static Level pin_feng_nuan(void);
static Level pin_wendu_jia(void);
static Level pin_wendu_jian(void);
static Level pin_xin_feng(void);
static Level pin_qiang_ruo(void);
static Level pin_huan_qi(void);
static Level pin_xin_feng_qu_nuan(void);
static Level pin_dingshi_jia(void);
static Level pin_dingshi_jian(void);
static Level pin_bai_dong(void);
static Level pin_zhi_neng(void);

Pin_input input_pins[KEY_NUMBER] = 
{
    pin_dian_yuan,
    pin_feng_nuan, 
    pin_wendu_jia,
    pin_wendu_jian,
    pin_xin_feng,
    pin_qiang_ruo,
    pin_huan_qi,
    pin_xin_feng_qu_nuan,
    pin_dingshi_jia,
    pin_dingshi_jian,
    pin_bai_dong,
    pin_zhi_neng,
};


static Level pin_dian_yuan(void)
{
    if (key_touch_IsWidgetActive(key_touch_BUTTON0_WDGT_ID))
        return LEVEL_HIGH;
    else
        return LEVEL_LOW;
}

static Level pin_feng_nuan(void)
{
    if (key_touch_IsWidgetActive(key_touch_BUTTON1_WDGT_ID))
        return LEVEL_HIGH;
    else
        return LEVEL_LOW;
}

static Level pin_wendu_jia(void)
{
    if (key_touch_IsWidgetActive(key_touch_BUTTON2_WDGT_ID))
        return LEVEL_HIGH;
    else
        return LEVEL_LOW;
}

static Level pin_wendu_jian(void)
{
    if (key_touch_IsWidgetActive(key_touch_BUTTON3_WDGT_ID))
        return LEVEL_HIGH;
    else
        return LEVEL_LOW;
}

static Level pin_xin_feng(void)
{
    if (key_touch_IsWidgetActive(key_touch_BUTTON4_WDGT_ID))
        return LEVEL_HIGH;
    else
        return LEVEL_LOW;
}

static Level pin_qiang_ruo(void)
{
    if (key_touch_IsWidgetActive(key_touch_BUTTON5_WDGT_ID))
        return LEVEL_HIGH;
    else
        return LEVEL_LOW;
}

static Level pin_huan_qi(void)
{
    if (key_touch_IsWidgetActive(key_touch_BUTTON6_WDGT_ID))
        return LEVEL_HIGH;
    else
        return LEVEL_LOW;
}

static Level pin_xin_feng_qu_nuan(void)
{
    if (key_touch_IsWidgetActive(key_touch_BUTTON7_WDGT_ID))
        return LEVEL_HIGH;
    else
        return LEVEL_LOW;
}

static Level pin_dingshi_jia(void)
{
    if (key_touch_IsWidgetActive(key_touch_BUTTON8_WDGT_ID))
        return LEVEL_HIGH;
    else
        return LEVEL_LOW;
}

static Level pin_dingshi_jian(void)
{
    if (key_touch_IsWidgetActive(key_touch_BUTTON9_WDGT_ID))
        return LEVEL_HIGH;
    else
        return LEVEL_LOW;
}

static Level pin_bai_dong(void)
{
    if (key_touch_IsWidgetActive(key_touch_BUTTON10_WDGT_ID))
        return LEVEL_HIGH;
    else
        return LEVEL_LOW;
}

static Level pin_zhi_neng(void)
{
    if (key_touch_IsWidgetActive(key_touch_BUTTON11_WDGT_ID))
        return LEVEL_HIGH;
    else
        return LEVEL_LOW;
}
/* [] END OF FILE */
