#include "app_work.h"
#include "app_lcd_display.h"

static App_mode_config mode_configs[APP_MODE_NUMBER] = 
{
    {APP_QIANG_RUO_CONFIG_A, DISABLE, {DISABLE, 0 , 0 , 0 }, {DISABLE, 0, 0  , 0  }},//APP_MODE_IDLE,
    {APP_QIANG_RUO_CONFIG_C, ENABLE , {ENABLE,  30, 40, 35}, {ENABLE, 60, 120, 90 }},//APP_MODE_FENG_NUAN,
    {APP_QIANG_RUO_CONFIG_B, DISABLE, {DISABLE, 0 , 0 , 0 }, {ENABLE, 30, 60 , 30 }},//APP_MODE_XIN_FENG,
    {APP_QIANG_RUO_CONFIG_C, ENABLE , {ENABLE,  30, 40, 35}, {ENABLE, 60, 120, 90 }},//APP_MODE_XIN_FENG_QU_NUAN,w
    {APP_QIANG_RUO_CONFIG_B, ENABLE , {DISABLE, 0 , 0 , 0 }, {ENABLE, 15, 60 , 30 }},//APP_MODE_HUAN_QI,
    {APP_QIANG_RUO_CONFIG_A, DISABLE, {DISABLE, 0 , 0 , 0 }, {ENABLE, 90, 150, 120}},//APP_MODE_GAN_ZAO,
    {APP_QIANG_RUO_CONFIG_A, DISABLE, {DISABLE, 0 , 0 , 0 }, {DISABLE, 0, 0  , 0  }},//APP_MODE_JING_HUA,
    {APP_QIANG_RUO_CONFIG_A, DISABLE, {DISABLE, 0 , 0 , 0 }, {ENABLE, 60, 120, 90 }},//APP_MODE_MU_YU,
};

static App_work_status status[APP_MODE_NUMBER];
static App_work_mode work_mode, previous_mode;
static App_work_event event;

static void app_work_mode_display(void);
static void app_work_mode_send(void);



void app_work_mode_init(void)
{
    App_work_mode i;
    
    for (i = APP_MODE_IDLE; i < APP_MODE_NUMBER; i++)
    {
        switch(mode_configs[i].qr_config)
        {
            case APP_QIANG_RUO_CONFIG_A: 
                status[i].cf_mode = APP_CHUI_FENG_INIT;
                break;
            case APP_QIANG_RUO_CONFIG_B: 
                status[i].cf_mode = APP_CHUI_FENG_RUO;
                break;
            case APP_QIANG_RUO_CONFIG_C: 
                status[i].cf_mode = APP_CHUI_FENG_ZI_DONG;
                break;
        }
        
        status[i].bai_dong = OFF;
        status[i].wen_du = mode_configs[i].wen_du_value.init;
        status[i].ding_shi = mode_configs[i].ding_shi_value.init;
    }
    work_mode = APP_MODE_IDLE;
    previous_mode = APP_MODE_IDLE;

}

void app_work_mode_process(void)
{
    switch(event)
    {
        case APP_EVENT_DIAN_YUAN: 
            if (work_mode ==  APP_MODE_IDLE)
                work_mode = previous_mode;
            else
                work_mode = APP_MODE_IDLE;
            break;
        case APP_EVENT_FENG_NUAN: 
            if (work_mode == APP_MODE_FENG_NUAN)
                work_mode = APP_MODE_IDLE;
            else
                work_mode = APP_MODE_FENG_NUAN;
            break;
        case APP_EVENT_XIN_FENG_QU_NUAN: 
            if (work_mode == APP_MODE_XIN_FENG_QU_NUAN)
                work_mode = APP_MODE_IDLE;
            else
                work_mode = APP_MODE_XIN_FENG_QU_NUAN;
            break;
        case APP_EVENT_XIN_FENG: 
            if (work_mode == APP_MODE_XIN_FENG)
                work_mode = APP_MODE_IDLE;
            else
                work_mode = APP_MODE_XIN_FENG;
            break;
        case APP_EVENT_HUAN_QI: 
            if (work_mode == APP_MODE_HUAN_QI)
                work_mode = APP_MODE_IDLE;
            else
                work_mode = APP_MODE_HUAN_QI;
            break;
        case APP_EVENT_ZHI_NENG: 
            switch(work_mode)
            {
                case APP_MODE_GAN_ZAO:
                    work_mode = APP_MODE_JING_HUA;
                    break;
                case APP_MODE_JING_HUA: 
                    work_mode = APP_MODE_MU_YU;
                    break;
                case APP_MODE_MU_YU: 
                    work_mode = APP_MODE_IDLE;
                    break;
                default: 
                    work_mode = APP_MODE_GAN_ZAO;
                    break;
            }
            break;
        case APP_EVENT_QIANG_RUO: 
            switch (mode_configs[work_mode].qr_config)
            {
                case APP_QIANG_RUO_CONFIG_A:
                    status[work_mode].cf_mode = APP_CHUI_FENG_INIT;
                    break;
                case APP_QIANG_RUO_CONFIG_B:
                    switch(status[work_mode].cf_mode)
                    {
                        case APP_CHUI_FENG_INIT: 
                            //不应该进入这里 
                            break;
                        case APP_CHUI_FENG_QIANG: 
                            status[work_mode].cf_mode = APP_CHUI_FENG_RUO;
                            break;
                        case APP_CHUI_FENG_RUO: 
                            status[work_mode].cf_mode = APP_CHUI_FENG_QIANG;
                            break;
                        case APP_CHUI_FENG_ZI_DONG: 
                            //不应该进入这里 
                            break;
                    }
                    break;
                case APP_QIANG_RUO_CONFIG_C:
                    switch(status[work_mode].cf_mode)
                    {
                        case APP_CHUI_FENG_INIT: 
                            //不应该进入这里 
                            break;
                        case APP_CHUI_FENG_QIANG: 
                            status[work_mode].cf_mode = APP_CHUI_FENG_RUO;
                            break;
                        case APP_CHUI_FENG_RUO: 
                            status[work_mode].cf_mode = APP_CHUI_FENG_ZI_DONG;
                            break;
                        case APP_CHUI_FENG_ZI_DONG: 
                            status[work_mode].cf_mode = APP_CHUI_FENG_QIANG;
                            break;
                    }
                    break;
            }
            break;
        case APP_EVENT_BAI_DONG: 
            if (mode_configs[work_mode].bai_dong_state == ENABLE)
            {
                if (status[work_mode].bai_dong == ON)
                    status[work_mode].bai_dong = OFF;
                else
                    status[work_mode].bai_dong = ON;
            }
            break;
        case APP_EVENT_WEN_DU_JIA: 
            if (mode_configs[work_mode].wen_du_value.state == ENABLE)
            {
                if (status[work_mode].wen_du < mode_configs[work_mode].wen_du_value.high)
                    status[work_mode].wen_du++;
            }   
            break;
        case APP_EVENT_WEN_DU_JIAN: 
            if (mode_configs[work_mode].wen_du_value.state == ENABLE)
            {
                if (status[work_mode].wen_du > mode_configs[work_mode].wen_du_value.low)
                    status[work_mode].wen_du--;
            } 
            break;
        case APP_EVENT_DING_SHI_JIA: 
            if (mode_configs[work_mode].ding_shi_value.state == ENABLE)
            {
                if (status[work_mode].ding_shi < mode_configs[work_mode].ding_shi_value.high)
                    status[work_mode].ding_shi += 15;
            }
            break;
        case APP_EVENT_DING_SHI_JIAN:
            if (mode_configs[work_mode].ding_shi_value.state == ENABLE)
            {
                if (status[work_mode].ding_shi > mode_configs[work_mode].ding_shi_value.low)
                    status[work_mode].ding_shi -= 15;
            }
            break;
        default :
            break;
    }
    
    if (event != APP_EVENT_NO)
    {
        event = APP_EVENT_NO; //事件处理之后清空
        
        //模式显示
        //模式参数发送
        app_work_mode_display();
        app_work_mode_send();
    }
}


void app_work_mode_event_set(App_work_event e)
{
    event = e;
}

static void app_work_mode_display(void)
{
    static Tube_value number_to_tube[10] = {VALUE_0,VALUE_1,VALUE_2,VALUE_3,VALUE_4,VALUE_5,VALUE_6,VALUE_7,VALUE_8,VALUE_9};

    if (status[work_mode].bai_dong == ON)
        app_lcd_display_set_icon(INDEX_ICON_BAI_DONG, ICON_STATE_ON);
    else
        app_lcd_display_set_icon(INDEX_ICON_BAI_DONG, ICON_STATE_OFF);
    
    switch(status[work_mode].cf_mode)
    {
        case APP_CHUI_FENG_INIT: 
            app_lcd_display_set_icon(INDEX_ICON_QIANG, ICON_STATE_OFF);
            app_lcd_display_set_icon(INDEX_ICON_RUO, ICON_STATE_OFF);
            app_lcd_display_set_icon(INDEX_ICON_ZI_DONG, ICON_STATE_OFF);
            break;
        case APP_CHUI_FENG_QIANG: 
            app_lcd_display_set_icon(INDEX_ICON_QIANG, ICON_STATE_ON);
            app_lcd_display_set_icon(INDEX_ICON_RUO, ICON_STATE_OFF);
            app_lcd_display_set_icon(INDEX_ICON_ZI_DONG, ICON_STATE_OFF);
            break;
        case APP_CHUI_FENG_RUO: 
            app_lcd_display_set_icon(INDEX_ICON_QIANG, ICON_STATE_OFF);
            app_lcd_display_set_icon(INDEX_ICON_RUO, ICON_STATE_ON);
            app_lcd_display_set_icon(INDEX_ICON_ZI_DONG, ICON_STATE_OFF);
            break;
        case APP_CHUI_FENG_ZI_DONG: 
            app_lcd_display_set_icon(INDEX_ICON_QIANG, ICON_STATE_OFF);
            app_lcd_display_set_icon(INDEX_ICON_RUO, ICON_STATE_OFF);
            app_lcd_display_set_icon(INDEX_ICON_ZI_DONG, ICON_STATE_ON);
            break;
    }

    //显示定时之前清空定时的百位显示
    app_lcd_display_set_icon(INDEX_ICON_DING_SHI_100, ICON_STATE_OFF);
    if (mode_configs[work_mode].ding_shi_value.state == ENABLE)
    {
        if (status[work_mode].ding_shi > 100)
            app_lcd_display_set_icon(INDEX_ICON_DING_SHI_100, ICON_STATE_ON);
        app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_DINGSHI_TENS, DIGIT_TUBE_STATE_ON, number_to_tube[(status[work_mode].ding_shi % 100) / 10]);
        app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_DiNGSHI_ONES, DIGIT_TUBE_STATE_ON, number_to_tube[(status[work_mode].ding_shi % 100) % 10]);
    }
    else
    {
        app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_DINGSHI_TENS, DIGIT_TUBE_STATE_ON, VALUE_INIT);
        app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_DiNGSHI_ONES, DIGIT_TUBE_STATE_ON, VALUE_INIT);
    }
    
    if (mode_configs[work_mode].wen_du_value.state == ENABLE)
    {
        app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_WENDU_TENS, DIGIT_TUBE_STATE_ON, number_to_tube[status[work_mode].wen_du / 10]);
        app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_WENDU_ONES, DIGIT_TUBE_STATE_ON, number_to_tube[status[work_mode].wen_du % 10]);
    }
    else
    {
        app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_WENDU_TENS, DIGIT_TUBE_STATE_ON, VALUE_INIT);
        app_lcd_display_set_digit_tube(INDEX_DIGIT_TUBE_WENDU_ONES, DIGIT_TUBE_STATE_ON, VALUE_INIT);
    }

    //将模式图标清空
    app_lcd_display_set_icon(INDEX_ICON_FENG_NUAN, ICON_STATE_OFF);
    app_lcd_display_set_icon(INDEX_ICON_XIN_FENG_QU_NUAN, ICON_STATE_OFF);
    app_lcd_display_set_icon(INDEX_ICON_XIN_FENG, ICON_STATE_OFF);
    app_lcd_display_set_icon(INDEX_ICON_HUAN_QI, ICON_STATE_OFF);
    app_lcd_display_set_icon(INDEX_ICON_ZN_GAN_ZAO, ICON_STATE_OFF);
    app_lcd_display_set_icon(INDEX_ICON_ZN_JING_HUA, ICON_STATE_OFF);
    app_lcd_display_set_icon(INDEX_ICON_ZN_MU_YU, ICON_STATE_OFF);
    switch(work_mode)
    {
        case APP_MODE_IDLE: break;
        case APP_MODE_FENG_NUAN: app_lcd_display_set_icon(INDEX_ICON_FENG_NUAN, ICON_STATE_ON); break;
        case APP_MODE_XIN_FENG_QU_NUAN: app_lcd_display_set_icon(INDEX_ICON_XIN_FENG_QU_NUAN, ICON_STATE_ON);break;
        case APP_MODE_XIN_FENG: app_lcd_display_set_icon(INDEX_ICON_XIN_FENG, ICON_STATE_ON);break;
        case APP_MODE_HUAN_QI: app_lcd_display_set_icon(INDEX_ICON_HUAN_QI, ICON_STATE_ON);break;
        case APP_MODE_GAN_ZAO: app_lcd_display_set_icon(INDEX_ICON_ZN_GAN_ZAO, ICON_STATE_ON);break;
        case APP_MODE_JING_HUA: app_lcd_display_set_icon(INDEX_ICON_ZN_JING_HUA, ICON_STATE_ON);break;
        case APP_MODE_MU_YU: app_lcd_display_set_icon(INDEX_ICON_ZN_MU_YU, ICON_STATE_ON);break;
        default : break;
    }
    app_lcd_display_refresh();
}

static void app_work_mode_send(void)
{
    app_frame_send.non_mutex_func.bai_dong = (uint8)status[work_mode].bai_dong;

    switch(status[work_mode].cf_mode)
    {
        case APP_CHUI_FENG_INIT: 
            app_frame_send.non_mutex_func.qiang = 0;
            app_frame_send.non_mutex_func.ruo = 0;
            app_frame_send.non_mutex_func.zi_dong = 0;
            break;
        case APP_CHUI_FENG_QIANG: 
            app_frame_send.non_mutex_func.qiang = 1;
            app_frame_send.non_mutex_func.ruo = 0;
            app_frame_send.non_mutex_func.zi_dong = 0;
            break;
        case APP_CHUI_FENG_RUO: 
            app_frame_send.non_mutex_func.qiang = 0;
            app_frame_send.non_mutex_func.ruo = 1;
            app_frame_send.non_mutex_func.zi_dong = 0;
            break;
        case APP_CHUI_FENG_ZI_DONG: 
            app_frame_send.non_mutex_func.qiang = 0;
            app_frame_send.non_mutex_func.ruo = 0;
            app_frame_send.non_mutex_func.zi_dong = 1;
            break;
    }
    
    app_frame_send.temp =  status[work_mode].wen_du;
    app_frame_send.ding_shi = status[work_mode].ding_shi;
    app_frame_send.func_type = FUNC_CONTROL;
    
    switch(work_mode)
    {
        case APP_MODE_IDLE: 
            app_frame_send.mutex_func = MUTEX_DAI_JI;
            break;
        case APP_MODE_FENG_NUAN: 
            app_frame_send.mutex_func = MUTEX_FENG_NUAN;
            break;
        case APP_MODE_XIN_FENG_QU_NUAN: 
            app_frame_send.mutex_func = MUTEX_XIN_FENG_FENG_NUAN;
            break;
        case APP_MODE_XIN_FENG: 
            app_frame_send.mutex_func = MUTEX_XIN_FENG;
            break;
        case APP_MODE_HUAN_QI: 
            app_frame_send.mutex_func = MUTEX_HUAN_QI;
            break;
        case APP_MODE_GAN_ZAO: 
            app_frame_send.mutex_func = MUTEX_ZHI_NENG_GAN_ZAO;
            break;
        case APP_MODE_JING_HUA: 
            app_frame_send.mutex_func = MUTEX_ZHI_NENG_JING_HUA;
            break;
        case APP_MODE_MU_YU: 
            app_frame_send.mutex_func = MUTEX_ZHI_NENG_MU_YU_1;
            break;
    }
    app_protocol_send();
}

