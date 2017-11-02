#ifndef _KEY_H_
#define _KEY_H_
#include "project.h"
#include "types.h"
extern unsigned char DATA_BUF[8];   /* temperary data RAM */

typedef enum {
    TYPE_LEVEL,
    TYPE_EDGE,
}Key_type;

typedef struct 
{
    uint8 current_level        : 1;
    uint8 previous_level      : 1;
    uint8 active_level          : 1;
    uint8 short_pressed      : 1;
    uint8 long_pressed        : 1;
    uint8 long_press_freed    :1;
}Keys;

/*按键定义*/
typedef enum
{
    KEY_DIAN_YUAN,
    KEY_FENG_NUAN,
    KEY_WENDU_JIA,
    KEY_WENDU_JIAN,
    KEY_XIN_FENG,
    KEY_QING_RUO,
    KEY_HUAN_QI,
    KEY_XIN_FENG_QU_NUAN,
    KEY_DINGSHI_JIA,
    KEY_DINGSHI_JIAN,
    KEY_BAI_DONG,
    KEY_ZHI_NENG,
    KEY_NUM
}Key_index;

/*参数配置部分*/
#define MODULE_CYCLE       10           //调度周期,ms

#define PIN_DIAN_YUAN() (key_touch_IsWidgetActive(key_touch_BUTTON0_WDGT_ID) != 0)
#define PIN_FENG_NUAN() (key_touch_IsWidgetActive(key_touch_BUTTON1_WDGT_ID) != 0)
#define PIN_WENDU_JIA() (key_touch_IsWidgetActive(key_touch_BUTTON2_WDGT_ID) != 0)
#define PIN_WENDU_JIAN() (key_touch_IsWidgetActive(key_touch_BUTTON3_WDGT_ID) != 0)
#define PIN_XIN_FENG() (key_touch_IsWidgetActive(key_touch_BUTTON4_WDGT_ID) != 0)
#define PIN_QING_RUO() (key_touch_IsWidgetActive(key_touch_BUTTON5_WDGT_ID) != 0)
#define PIN_HUAN_QI() (key_touch_IsWidgetActive(key_touch_BUTTON6_WDGT_ID) != 0)
#define PIN_XIN_FENG_QU_NUAN() (key_touch_IsWidgetActive(key_touch_BUTTON7_WDGT_ID) != 0)
#define PIN_DINGSHI_JIA() (key_touch_IsWidgetActive(key_touch_BUTTON8_WDGT_ID) != 0)
#define PIN_DINGSHI_JIAN() (key_touch_IsWidgetActive(key_touch_BUTTON9_WDGT_ID) != 0)
#define PIN_BAI_DONG() (key_touch_IsWidgetActive(key_touch_BUTTON10_WDGT_ID) != 0)
#define PIN_ZHI_NENG() (key_touch_IsWidgetActive(key_touch_BUTTON11_WDGT_ID) != 0)

/*
#define PIN_DIAN_YUAN() (key_touch_IsSensorActive(key_touch_BUTTON0_WDGT_ID, key_touch_BUTTON0_SNS0_ID))
#define PIN_FENG_NUAN() (key_touch_IsSensorActive(key_touch_BUTTON0_WDGT_ID, key_touch_BUTTON0_SNS1_ID))
#define PIN_WENDU_JIA() (key_touch_IsSensorActive(key_touch_BUTTON0_WDGT_ID, key_touch_BUTTON0_SNS2_ID))
#define PIN_WENDU_JIAN() (key_touch_IsSensorActive(key_touch_BUTTON0_WDGT_ID, key_touch_BUTTON0_SNS3_ID))
#define PIN_XIN_FENG() (key_touch_IsSensorActive(key_touch_BUTTON0_WDGT_ID, key_touch_BUTTON0_SNS4_ID))
#define PIN_QING_RUO() (key_touch_IsSensorActive(key_touch_BUTTON0_WDGT_ID, key_touch_BUTTON0_SNS5_ID))
#define PIN_HUAN_QI() (key_touch_IsSensorActive(key_touch_BUTTON0_WDGT_ID, key_touch_BUTTON0_SNS6_ID))
#define PIN_XIN_FENG_QU_NUAN() (key_touch_IsSensorActive(key_touch_BUTTON0_WDGT_ID, key_touch_BUTTON0_SNS7_ID))
#define PIN_DINGSHI_JIA() (key_touch_IsSensorActive(key_touch_BUTTON0_WDGT_ID, key_touch_BUTTON0_SNS8_ID))
#define PIN_DINGSHI_JIAN() (key_touch_IsSensorActive(key_touch_BUTTON0_WDGT_ID, key_touch_BUTTON0_SNS9_ID))
#define PIN_BAI_DONG() (key_touch_IsSensorActive(key_touch_BUTTON0_WDGT_ID, key_touch_BUTTON0_SNS10_ID))
#define PIN_ZHI_NENG() (key_touch_IsSensorActive(key_touch_BUTTON0_WDGT_ID, key_touch_BUTTON0_SNS11_ID))
*/
/**********************/
extern void key_init(void);
extern void key_scan(void);
extern Bool key_is_short_pressed(Key_index index);
extern Bool key_is_long_pressed(Key_index i);
extern Bool key_is_long_press_freed(Key_index i);
extern Bool key_is_pressing(Key_index index);
#endif

