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
#ifndef _APP_H_
#define _APP_H_
#include "simple_protocol.h"
    

#define APP_KEY_HANDLER_DEFINE(x, key_value)  \
    void app_key_##x##_handler(void)    \
    {   \
        app_send_buffer[0] = key_value;    \
        simple_protocol_send(app_send_buffer, 1);   \
    }

#define APP_KEY_HANDlER(x)  app_key_##x##_handler

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
    VALUE_NUMBER
}Key_value;
extern void app_init(void);   

#endif
/* [] END OF FILE */
