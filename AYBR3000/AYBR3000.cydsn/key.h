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
#ifndef _KEY_H_
#define _KEY_H_
#include "types.h"
#include "key_config.h"

typedef enum
{
    KEY_RELEASE,         //按键默认状态
    KEY_PRESS,   
    KEY_LONG_PRESS,
    KEY_STUCK
}Key_state;

typedef enum
{
    KEY_EVENT_SHORT_PRESS,
    KEY_EVENT_LONG_PRESS,
    KEY_EVENT_LONG_RELEASE,
    KEY_EVENT_STUCK,
    KEY_EVENT_NUMBER
}Key_event;

typedef struct
{
    uint8 previous_level : 1;
    uint8 current_level  : 1;
    uint8 active_level   : 1;
    uint16 level_time;
    Pin_input pin;
}Key;


typedef void (* Key_event_handler)(void);
typedef void (* Key_conbine_handler)(void);

typedef enum
{
    COMBINE_DISABLE,
    COMBINE_ENABLE,
}Key_combine_state;

typedef struct
{
    Key_Index key1;
    Key_Index key2;
    Key_conbine_handler handler;
    Key_combine_state state;
}Key_combine;

#define KEY_MODULE_SCHEDULE_PERIOD 10
void key_init(void);
void key_process(void);
extern Bool key_add_event_handler(Key_Index i, Key_event e, Key_event_handler h);
extern Bool key_add_combine_handler(Key_Index i, Key_Index j, Key_conbine_handler h);
#endif
/* [] END OF FILE */
