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
#ifndef _KEY_CONFIG_H_
#define _KEY_CONFIG_H_
    
#include "project.h"
#include "types.h"
typedef Level (* Pin_input)(void);

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
    KEY_NUMBER,
}Key_Index;

extern Pin_input input_pins[KEY_NUMBER];
#endif
/* [] END OF FILE */
