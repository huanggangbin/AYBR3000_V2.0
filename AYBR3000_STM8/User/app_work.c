#include "app_work.h"

static App_mode_config mode_configs[APP_MODE_NUMBER] = 
{
    {APP_QIANG_RUO_CONFIG_A, DISABLE, {DISABLE, 0 , 0 , 0 }, {DISABLE, 0, 0  , 0  }},//APP_MODE_IDLE,
    {APP_QIANG_RUO_CONFIG_C, ENABLE , {ENABLE,  30, 40, 35}, {ENABLE, 60, 120, 90 }},//APP_MODE_FENG_NUAN,
    {APP_QIANG_RUO_CONFIG_B, DISABLE, {DISABLE, 0 , 0 , 0 }, {ENABLE, 30, 60 , 30 }},//APP_MODE_XIN_FENG_QU_NUAN,
    {APP_QIANG_RUO_CONFIG_C, ENABLE , {ENABLE,  30, 40, 35}, {ENABLE, 60, 120, 90 }},//APP_MODE_XIN_FENG,
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
    status;
    work_mode;
}

static void app_work_mode_send(void)
{
    
}

