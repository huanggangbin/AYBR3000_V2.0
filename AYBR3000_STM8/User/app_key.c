#include "app_key.h"

typedef enum
{
    VALUE_SHORT_PRESS_DIAN_YUAN,
    VALUE_SHORT_PRESS_FENG_NUAN,
    VALUE_SHORT_PRESS_WENDU_JIA,
    VALUE_SHORT_PRESS_WENDU_JIAN,
    VALUE_SHORT_PRESS_XIN_FENG,
    VALUE_SHORT_PRESS_QING_RUO,
    VALUE_SHORT_PRESS_HUAN_QI,
    VALUE_SHORT_PRESS_XIN_FENG_QU_NUAN,
    VALUE_SHORT_PRESS_DINGSHI_JIA,
    VALUE_SHORT_PRESS_DINGSHI_JIAN,
    VALUE_SHORT_PRESS_BAI_DONG,
    VALUE_SHORT_PRESS_ZHI_NENG,
    
    VALUE_LONG_PRESS_WEN_DU_JIA,
    VALUE_LONG_PRESS_DING_SHI_JIA,
    VALUE_LONG_PRESS_DING_SHI_JIAN,
    
    VALUE_LONG_RELEASE_DING_SHI_JIA,
    VALUE_LONG_RELEASE_DING_SHI_JIAN,
    
    VALUE_COMBINE_WA_DA,
    VALUE_COMBINE_WM_DM,
    VALUE_COMBINE_DM_DIAN_YUAN,
    VALUE_CONBINE_QIANG_RUO_DIAN_YUAN,
    VALUE_NUMBER
}Key_value;

static Key_value key;

void app_key_init(void)
{
}

void app_key_process(void)
{
    if (simple_protocol_data_received())
    {
        key = (Key_value)receive_buffer[2];


        //定时模式下,异常按键处理
        if (app_time_mode_busy())
        {
            if (key != VALUE_SHORT_PRESS_WENDU_JIA
                && key != VALUE_SHORT_PRESS_DINGSHI_JIA
                && key != VALUE_SHORT_PRESS_DINGSHI_JIAN
                && key != VALUE_COMBINE_WA_DA
                && key != VALUE_COMBINE_WM_DM
                && key != VALUE_COMBINE_DM_DIAN_YUAN)
            {
                app_time_event_set(APP_TIME_CMD_END);
                return;
            }
        }
        
        //正常按键处理
        switch(key)
        {
            case VALUE_SHORT_PRESS_DIAN_YUAN:
                app_work_mode_event_set(APP_EVENT_DIAN_YUAN);
                break;
            case VALUE_SHORT_PRESS_FENG_NUAN:
                app_work_mode_event_set(APP_EVENT_FENG_NUAN);
                break;
            case VALUE_SHORT_PRESS_WENDU_JIA:  
                if (app_time_mode_busy())
                    app_time_event_set(APP_TIME_CMD_CHANGE);
                else
                    app_work_mode_event_set(APP_EVENT_WEN_DU_JIA);
                break;
            case VALUE_SHORT_PRESS_WENDU_JIAN:
                    app_work_mode_event_set(APP_EVENT_WEN_DU_JIAN);
                break;
            case VALUE_SHORT_PRESS_DINGSHI_JIA: 
                if (app_time_mode_busy())
                    app_time_event_set(APP_TIME_CMD_ADD);
                else
                    app_work_mode_event_set(APP_EVENT_DING_SHI_JIA);
                break;
            case VALUE_SHORT_PRESS_DINGSHI_JIAN:
                if (app_time_mode_busy())
                    app_time_event_set(APP_TIME_CMD_MINUS);
                else
                    app_work_mode_event_set(APP_EVENT_DING_SHI_JIAN);
                break;
            case VALUE_SHORT_PRESS_XIN_FENG:
                app_work_mode_event_set(APP_EVENT_XIN_FENG);
                break;
            case VALUE_SHORT_PRESS_QING_RUO:
                app_work_mode_event_set(APP_EVENT_QIANG_RUO);
                break;
            case VALUE_SHORT_PRESS_HUAN_QI:
                app_work_mode_event_set(APP_EVENT_HUAN_QI);
                break;
            case VALUE_SHORT_PRESS_XIN_FENG_QU_NUAN:
                app_work_mode_event_set(APP_EVENT_XIN_FENG_QU_NUAN);
                break;
            case VALUE_SHORT_PRESS_BAI_DONG:
                app_work_mode_event_set(APP_EVENT_BAI_DONG);
                break;
            case VALUE_SHORT_PRESS_ZHI_NENG:
                app_work_mode_event_set(APP_EVENT_ZHI_NENG);
                break;
            case VALUE_LONG_PRESS_WEN_DU_JIA:
                app_time_event_set(APP_TIME_CMD_START);
                break;
            case VALUE_LONG_PRESS_DING_SHI_JIA:
                app_time_event_set(APP_TIME_CMD_FAST_ADD);
                break;
            case VALUE_LONG_PRESS_DING_SHI_JIAN:
                app_time_event_set(APP_TIME_CMD_FAST_MINUS);
                break;
            case VALUE_LONG_RELEASE_DING_SHI_JIA:    //此处不要break
            case VALUE_LONG_RELEASE_DING_SHI_JIAN:
                app_time_event_set(APP_TIME_CMD_FAST_STOP);
                break;
            case VALUE_COMBINE_WA_DA:
                //发送配网报文
                nop();
                break;
            case VALUE_COMBINE_WM_DM:
                //发送解绑报文
                nop();
                break;
            case VALUE_COMBINE_DM_DIAN_YUAN:
                //恢复出厂设置
                nop();
                break;
            case VALUE_CONBINE_QIANG_RUO_DIAN_YUAN:
                //发送对码命令
                nop();
                break;
            default :
                break;
        }
    }
}

