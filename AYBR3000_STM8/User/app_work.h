#ifndef _APP_WORK_H_
#define _APP_WORK_H_
#include "types.h"
#include "LCD_driver.h"
#include "app_protocol.h"
#include "app_lcd_display.h"

//ö�ٳ����еĹ���ģʽ
typedef enum
{
    APP_MODE_IDLE,
    APP_MODE_FENG_NUAN,
    APP_MODE_XIN_FENG_QU_NUAN,
    APP_MODE_XIN_FENG,
    APP_MODE_HUAN_QI,
    APP_MODE_GAN_ZAO,
    APP_MODE_JING_HUA,
    APP_MODE_MU_YU,
    APP_MODE_NUMBER,
}App_work_mode;

typedef enum
{
    APP_EVENT_NO,
    APP_EVENT_DIAN_YUAN,
    APP_EVENT_FENG_NUAN,
    APP_EVENT_XIN_FENG_QU_NUAN,
    APP_EVENT_XIN_FENG,
    APP_EVENT_HUAN_QI,
    APP_EVENT_ZHI_NENG,
    APP_EVENT_QIANG_RUO,
    APP_EVENT_BAI_DONG,
    APP_EVENT_WEN_DU_JIA,
    APP_EVENT_WEN_DU_JIAN,
    APP_EVENT_DING_SHI_JIA,
    APP_EVENT_DING_SHI_JIAN,
}App_work_event;
//ģʽ״̬��¼
typedef enum
{
    APP_CHUI_FENG_INIT,
    APP_CHUI_FENG_QIANG,
    APP_CHUI_FENG_RUO,
    APP_CHUI_FENG_ZI_DONG,
}App_chui_feng_mode;

typedef struct
{
    App_chui_feng_mode cf_mode;
    Switch bai_dong;
    uint8 wen_du;
    uint8 ding_shi;
}App_work_status;

//ģʽ�������ò���
typedef enum
{
    APP_QIANG_RUO_CONFIG_A,  //��ǿ��
    APP_QIANG_RUO_CONFIG_B,  //ǿ����
    APP_QIANG_RUO_CONFIG_C,  //ǿ�������Զ�
}App_qiang_ruo_config;

typedef struct 
{
    FunctionalState state;                
    uint8 high;
    uint8 low;
    uint8 init;
}App_value_config;

typedef struct
{
    App_qiang_ruo_config qr_config;        //�Ƿ���ǿ������
    FunctionalState bai_dong_state;              //�Ƿ��аڶ�����
    App_value_config wen_du_value;
    App_value_config ding_shi_value;
}App_mode_config;

extern void app_work_mode_init(void);
extern void app_work_mode_process(void);
extern void app_work_mode_event_set(App_work_event e);

#endif

