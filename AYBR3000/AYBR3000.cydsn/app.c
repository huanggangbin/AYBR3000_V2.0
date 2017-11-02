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
#include "app.h"
#include "key.h"
uint8 app_send_buffer[10];

APP_KEY_HANDLER_DEFINE(short_press_dian_yuan, VALUE_SHORT_PRESS_DIAN_YUAN);
APP_KEY_HANDLER_DEFINE(short_press_feng_nuan, VALUE_SHORT_PRESS_FENG_NUAN);
APP_KEY_HANDLER_DEFINE(short_press_wen_du_jia, VALUE_SHORT_PRESS_WENDU_JIA);
APP_KEY_HANDLER_DEFINE(short_press_wen_du_jian, VALUE_SHORT_PRESS_WENDU_JIAN);
APP_KEY_HANDLER_DEFINE(short_press_xin_feng, VALUE_SHORT_PRESS_XIN_FENG);
APP_KEY_HANDLER_DEFINE(short_press_qiang_ruo, VALUE_SHORT_PRESS_QING_RUO);
APP_KEY_HANDLER_DEFINE(short_press_huan_qi, VALUE_SHORT_PRESS_HUAN_QI);
APP_KEY_HANDLER_DEFINE(short_press_xin_feng_qu_nuan, VALUE_SHORT_PRESS_XIN_FENG_QU_NUAN);
APP_KEY_HANDLER_DEFINE(short_press_ding_shi_jia, VALUE_SHORT_PRESS_DINGSHI_JIA);
APP_KEY_HANDLER_DEFINE(short_press_ding_shi_jian, VALUE_SHORT_PRESS_DINGSHI_JIAN);
APP_KEY_HANDLER_DEFINE(short_press_bai_dong, VALUE_SHORT_PRESS_BAI_DONG);
APP_KEY_HANDLER_DEFINE(short_press_zhi_neng, VALUE_SHORT_PRESS_ZHI_NENG);

APP_KEY_HANDLER_DEFINE(long_press_wen_du_jia, VALUE_LONG_PRESS_WEN_DU_JIA);
APP_KEY_HANDLER_DEFINE(long_press_ding_shi_jia, VALUE_LONG_PRESS_DING_SHI_JIA);
APP_KEY_HANDLER_DEFINE(long_press_ding_shi_jian, VALUE_LONG_PRESS_DING_SHI_JIAN);

APP_KEY_HANDLER_DEFINE(long_release_ding_shi_jia,  VALUE_LONG_RELEASE_DING_SHI_JIA);
APP_KEY_HANDLER_DEFINE(long_release_ding_shi_jian, VALUE_LONG_RELEASE_DING_SHI_JIAN);

APP_KEY_HANDLER_DEFINE(combine_wen_jia_ding_jia, VALUE_COMBINE_WA_DA);
APP_KEY_HANDLER_DEFINE(combine_wen_jian_ding_jian, VALUE_COMBINE_WM_DM);
APP_KEY_HANDLER_DEFINE(combine_ding_jian_dian_yuan, VALUE_COMBINE_DM_DIAN_YUAN);

void app_init(void)
{
    key_add_event_handler(KEY_DIAN_YUAN, KEY_EVENT_SHORT_PRESS, APP_KEY_HANDlER(short_press_dian_yuan));
    key_add_event_handler(KEY_FENG_NUAN, KEY_EVENT_SHORT_PRESS, APP_KEY_HANDlER(short_press_feng_nuan));
    key_add_event_handler(KEY_WENDU_JIA, KEY_EVENT_SHORT_PRESS, APP_KEY_HANDlER(short_press_wen_du_jia));
    key_add_event_handler(KEY_WENDU_JIAN, KEY_EVENT_SHORT_PRESS, APP_KEY_HANDlER(short_press_wen_du_jian));
    key_add_event_handler(KEY_XIN_FENG, KEY_EVENT_SHORT_PRESS, APP_KEY_HANDlER(short_press_xin_feng));
    key_add_event_handler(KEY_QING_RUO, KEY_EVENT_SHORT_PRESS, APP_KEY_HANDlER(short_press_qiang_ruo));
    key_add_event_handler(KEY_HUAN_QI, KEY_EVENT_SHORT_PRESS, APP_KEY_HANDlER(short_press_huan_qi));
    key_add_event_handler(KEY_XIN_FENG_QU_NUAN, KEY_EVENT_SHORT_PRESS, APP_KEY_HANDlER(short_press_xin_feng_qu_nuan));
    key_add_event_handler(KEY_DINGSHI_JIA, KEY_EVENT_SHORT_PRESS, APP_KEY_HANDlER(short_press_ding_shi_jia));
    key_add_event_handler(KEY_DINGSHI_JIAN, KEY_EVENT_SHORT_PRESS, APP_KEY_HANDlER(short_press_ding_shi_jian));
    key_add_event_handler(KEY_BAI_DONG, KEY_EVENT_SHORT_PRESS, APP_KEY_HANDlER(short_press_bai_dong));
    key_add_event_handler(KEY_ZHI_NENG, KEY_EVENT_SHORT_PRESS, APP_KEY_HANDlER(short_press_zhi_neng));
    
    key_add_event_handler(KEY_WENDU_JIA, KEY_EVENT_LONG_PRESS, APP_KEY_HANDlER(long_press_wen_du_jia));
    key_add_event_handler(KEY_DINGSHI_JIA, KEY_EVENT_LONG_PRESS, APP_KEY_HANDlER(long_press_ding_shi_jia));
    key_add_event_handler(KEY_DINGSHI_JIAN, KEY_EVENT_LONG_PRESS, APP_KEY_HANDlER(long_press_ding_shi_jian));
    
    key_add_event_handler(KEY_DINGSHI_JIA, KEY_EVENT_LONG_RELEASE, APP_KEY_HANDlER(long_release_ding_shi_jia));
    key_add_event_handler(KEY_DINGSHI_JIAN, KEY_EVENT_LONG_RELEASE, APP_KEY_HANDlER(long_release_ding_shi_jian));
    
    key_add_combine_handler(KEY_WENDU_JIA, KEY_DINGSHI_JIA, APP_KEY_HANDlER(combine_wen_jia_ding_jia));
    key_add_combine_handler(KEY_WENDU_JIAN, KEY_DINGSHI_JIAN, APP_KEY_HANDlER(combine_wen_jian_ding_jian));
    key_add_combine_handler(KEY_DINGSHI_JIAN, KEY_DIAN_YUAN, APP_KEY_HANDlER(combine_ding_jian_dian_yuan));
}


/* [] END OF FILE */
