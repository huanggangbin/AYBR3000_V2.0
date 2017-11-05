#include "app_lcd_display.h"



static App_lcd_time_unit time_unit[APP_LCD_WORK_UNIT_NUMBER];
static App_lcd_work_unit work_unit[APP_LCD_TIME_UNIT_NUMBER];
static void app_lcd_time_process(void);
static void app_lcd_work_process(void);

void app_lcd_display_init(void)
{
    uint8 i;
    
    memset(&work_unit, 0, sizeof (App_lcd_work_unit) * APP_LCD_WORK_UNIT_NUMBER);
    memset(&time_unit, 0, sizeof (App_lcd_time_unit) * APP_LCD_TIME_UNIT_NUMBER);
    
    for (i = APP_LCD_WORK_UINT_QIANG; i < APP_LCD_WORK_UNIT_NUMBER; i++)
        work_unit[i].control_func = work_unit_ctrl_func[i];

    for (i = APP_LCD_TIME_UNIT_COLON; i < APP_LCD_TIME_UNIT_NUMBER; i++)
        time_unit[i].control_func = time_unit_ctrl_func[i];
}

void app_lcd_display_process(void)
{
    app_lcd_time_process();
    app_lcd_work_process();
}

void app_lcd_display_set_work(App_lcd_work_unit_index unit, Switch state)
{
    work_unit[unit].state = state;
}
void app_lcd_display_set_time(App_lcd_time_unit_index unit, App_lcd_time_state state)
{
    time_unit[unit].state = state;
}

static void app_lcd_time_process(void)
{
    App_lcd_time_unit_index i;
  
    for (i = APP_LCD_TIME_UNIT_COLON; i < APP_LCD_TIME_UNIT_NUMBER; i++)
    {
        switch(time_unit[i].state)
        {
            case UINT_TIME_OFF:
                time_unit[i].control_func(OFF);
                break;
            case UINT_TIME_ON:
                time_unit[i].control_func(ON);
                break;
            case UINT_TIME_BLINK:
                if (time_unit[i].state != UINT_TIME_BLINK)
                    break;
                switch(time_unit[i].blink_state)
                {
                    case APP_LCD_BLINK_INIT: 
                        time_unit[i].blink_state = APP_LCD_BLINK_OFF;
                        timing_set_counts(&time_unit[i].blink_timing, 250);
                        time_unit[i].control_func(OFF);
                        break;
                    case APP_LCD_BLINK_ON: 
                        
                        if (timing_count_end(&time_unit[i].blink_timing))
                        {
                            time_unit[i].blink_state = APP_LCD_BLINK_OFF;
                            time_unit[i].control_func(OFF);
                            timing_set_counts(&time_unit[i].blink_timing, 250);
                        }
                        break;
                    case APP_LCD_BLINK_OFF: 
                        if (timing_count_end(&time_unit[i].blink_timing))
                        {
                            time_unit[i].blink_state = APP_LCD_BLINK_ON;
                            time_unit[i].control_func(ON);
                            timing_set_counts(&time_unit[i].blink_timing, 250);
                        }
                        break;
                }
                break;
        }
    }
}

static void app_lcd_work_process(void)
{
    App_lcd_work_unit_index i;
    for (i = APP_LCD_WORK_UINT_QIANG; i < APP_LCD_WORK_UNIT_NUMBER; i++)
            work_unit[i].control_func(work_unit[i].state);
}
