#ifndef _APP_PROTOCOL_H_
#define _APP_PROTOCOL_H_
#include "types.h"
#include "datalink_protocol.h"

#include <string.h>

typedef enum
{
    FUNC_READ_STATE,
    FUNC_CONTROL,
    FUNC_MATCH_CODE,
}Send_function_type;

typedef struct
{
    uint8 zhao_ming : 1;
    uint8 bai_dong  : 1;
    uint8 qiang     : 1;
    uint8 ruo       : 1;
    uint8 zi_dong   : 1;
    uint8 beep      : 1;
}Non_mutex_function;

typedef enum
{
    MUTEX_DAI_JI,
    MUTEX_HUAN_QI,
    MUTEX_JING_HUA,
    MUTEX_XIN_FENG,
    MUTEX_FENG_NUAN,
    MUTEX_FENG_NUAN_QIANG,
    MUTEX_FENG_NUAN_RUO,
    MUTEX_CHUI_FENG,
    MUTEX_GAN_ZAO,
    MUTEX_DENG_NUAN_RUO,
    MUTEX_DENG_NUAN_QIANG,
    MUTEX_XIN_FENG_FENG_NUAN,
    MUTEX_ZHI_NENG_GAN_ZAO,
    MUTEX_ZHI_NENG_MU_YU_1,
    MUTEX_ZHI_NENG_MU_YU_2,
    MUTEX_ZHI_NENG_JING_HUA,
    MUTEX_CHUI_FENG_JING_HUA,
    MUTEX_FUNC_NUMBER,
}Mutex_function;

typedef struct
{
    Send_function_type func_type;
    Non_mutex_function non_mutex_func;
    Mutex_function mutex_func;
    uint8 temp;
    uint8 ding_shi;
    uint8 time_hour;
    uint8 time_minute;
    uint8 no_use[2];
}App_frame;

extern void app_protocol_init(void);
extern void app_protocol_send(void);
extern App_frame app_frame;

#endif

