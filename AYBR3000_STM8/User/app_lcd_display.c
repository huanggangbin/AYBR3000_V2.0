#include "app_lcd_display.h"

static App_lcd_icon icons[INDEX_ICON_NUMBER];
static App_lcd_digit_tube digit_tubes[INDEX_DIGIT_TUBE_NUMBER];

static void app_lcd_icon_blink(App_lcd_index_icon i);
static void app_lcd_digit_tube_blink(App_lcd_index_digit_tube i);

void app_lcd_display_init(void)
{
    uint8 i;
    
    memset(&icons, 0, sizeof (App_lcd_index_icon) * INDEX_ICON_NUMBER);
    memset(&digit_tubes, 0, sizeof (App_lcd_index_digit_tube) * INDEX_DIGIT_TUBE_NUMBER);
    
    for (i = INDEX_ICON_QIANG; i < INDEX_ICON_NUMBER; i++)
    {
        icons[i].control_func = icon_ctrl_func[i];
        icons[i].blink_half_period = 500;
    }
    for (i = INDEX_DIGIT_TUBE_HOUR_TENS; i < INDEX_DIGIT_TUBE_NUMBER; i++)
    {
        digit_tubes[i].control_func = digit_tube_ctrl_func[i];
        digit_tubes[i].blink_half_period = 500;
        digit_tubes[i].value = VALUE_INIT;
    }
    icons[INDEX_ICON_LINE].state = ICON_STATE_ON;
    icons[INDEX_ICON_WEN_DU_SHE_DING].state = ICON_STATE_ON;
    icons[INDEX_ICON_DING_SHI_SHI_JIAN].state = ICON_STATE_ON;

    LCD_driver_refresh();
}

void app_lcd_display_process(void)
{
    App_lcd_index_icon i;
    
    for (i = INDEX_ICON_QIANG; i < INDEX_ICON_NUMBER; i++)
    {
        switch(icons[i].state)
        {
            case ICON_STATE_OFF:
                icons[i].control_func(OFF);
                break;
            case ICON_STATE_ON:
                icons[i].control_func(ON);
                break;
            case ICON_STATE_BLINK:
                app_lcd_icon_blink(i);
                break;
        }
    }
    
    App_lcd_index_digit_tube j;
    for (j = INDEX_DIGIT_TUBE_HOUR_TENS; j < INDEX_DIGIT_TUBE_NUMBER; j++)
    {
        switch(digit_tubes[j].state)
        {
            case DIGIT_TUBE_STATE_OFF:
            case DIGIT_TUBE_STATE_ON:
                digit_tubes[j].control_func(digit_tubes[j].value);
                break;
            case DIGIT_TUBE_STATE_BLINK:
                app_lcd_digit_tube_blink(j);
                break;
        }
    }
    LCD_driver_refresh();
}

void app_lcd_display_set_icon(App_lcd_index_icon i, App_lcd_icon_state state)
{
    icons[i].state = state;
}

void app_lcd_display_set_digit_tube(App_lcd_index_digit_tube i, App_lcd_digit_tube_state state, Tube_value value)
{
    digit_tubes[i].value = value;
    digit_tubes[i].state = state;
}

void app_lcd_display_refresh(void)
{
    LCD_driver_refresh();
}

static void app_lcd_icon_blink(App_lcd_index_icon i)
{
    switch(icons[i].blink_state)
    {
        case APP_LCD_BLINK_INIT: 
            icons[i].blink_state = APP_LCD_BLINK_OFF;
            timing_set_counts(&icons[i].blink_timing, icons[i].blink_half_period);
            icons[i].control_func(OFF);
            break;
        case APP_LCD_BLINK_ON: 
            
            if (timing_count_end(&icons[i].blink_timing))
            {
                icons[i].blink_state = APP_LCD_BLINK_OFF;
                icons[i].control_func(OFF);
                timing_set_counts(&icons[i].blink_timing, icons[i].blink_half_period);
            }
            break;
        case APP_LCD_BLINK_OFF: 
            if (timing_count_end(&icons[i].blink_timing))
            {
                icons[i].blink_state = APP_LCD_BLINK_ON;
                icons[i].control_func(ON);
                timing_set_counts(&icons[i].blink_timing, icons[i].blink_half_period);
            }
            break;
    }
    
}

static void app_lcd_digit_tube_blink(App_lcd_index_digit_tube i)
{
    switch(digit_tubes[i].blink_state)
    {
        case APP_LCD_BLINK_INIT: 
            digit_tubes[i].blink_state = APP_LCD_BLINK_OFF;
            timing_set_counts(&digit_tubes[i].blink_timing, digit_tubes[i].blink_half_period);
            digit_tubes[i].control_func(VALUE_NULL);
            break;
        case APP_LCD_BLINK_ON: 
            if (timing_count_end(&digit_tubes[i].blink_timing))
            {
                digit_tubes[i].blink_state = APP_LCD_BLINK_OFF;
                digit_tubes[i].control_func(VALUE_NULL);
                timing_set_counts(&digit_tubes[i].blink_timing, digit_tubes[i].blink_half_period);
            }
            break;
        case APP_LCD_BLINK_OFF: 
            if (timing_count_end(&digit_tubes[i].blink_timing))
            {
                digit_tubes[i].blink_state = APP_LCD_BLINK_ON;
                digit_tubes[i].control_func(digit_tubes[i].value);
                timing_set_counts(&icons[i].blink_timing, digit_tubes[i].blink_half_period);
            }
            break;
    }
}

