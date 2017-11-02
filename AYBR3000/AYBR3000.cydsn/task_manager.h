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
#ifndef _TASK_MANAGER_H_
#define _TASK_MANAGER_H_
    
    
#include "types.h"
typedef void (* pfunc)(void);

void task_init(void);
void task_main(void);
Bool task_add(pfunc task, uint16 schedule_time);
void task_1ms_updater(void);


#endif
/* [] END OF FILE */
