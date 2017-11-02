#ifndef _TASK_MANAGER_H_
#define _TASK_MANAGER_H_

#include "types.h"
typedef void (* pfunc)(void);

void task_init(void);
void task_process(void);
bool task_add(pfunc task, uint16 schedule_time);
void task_1ms_updater(void);

#endif

