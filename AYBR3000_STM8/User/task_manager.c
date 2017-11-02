#include "task_manager.h"
#include "string.h"

typedef struct
{
    pfunc task;           
    uint16 schedule_period;
    uint16 old_time;
}Task;

#define TASK_MAX_NUMBER 20

typedef struct
{
    Task task_list[TASK_MAX_NUMBER];        
    uint8 task_nunber;      
    uint16 time_counter;
    uint16 prev_time_counter;
}Task_manager;

static Task_manager task_manager;

void task_init(void)
{
    memset(&task_manager, 0, sizeof(Task_manager));
}

void task_process(void)
{
    uint8 i = 0;
    uint16 temp = 0;
    
    if (task_manager.time_counter == task_manager.prev_time_counter)
        return;
    task_manager.prev_time_counter = task_manager.time_counter;
    
    for (i = 0; i < task_manager.task_nunber; i++)
    {
        temp = task_manager.time_counter - task_manager.task_list[i].old_time;
        if (temp < task_manager.task_list[i].schedule_period)
            continue;
        else        //调用周期到来
        {
            task_manager.task_list[i].old_time = task_manager.time_counter;
            task_manager.task_list[i].task();
        }
    }
}

/*这个函数放在1ms的中断里面*/
void task_1ms_updater(void)
{
    task_manager.time_counter++;
}

bool task_add(pfunc task, uint16 schedule_period)
{
    if (task == NULL || schedule_period == 0)
        return FALSE;
    if (task_manager.task_nunber >= TASK_MAX_NUMBER - 1)
        return FALSE;
    
    task_manager.task_list[task_manager.task_nunber].task = task;
	
    task_manager.task_list[task_manager.task_nunber].schedule_period = schedule_period;
    task_manager.task_nunber++;
	
	//防止同一周期的task的old_time相同
	task_manager.task_list[task_manager.task_nunber].old_time = task_manager.time_counter + task_manager.task_nunber;
    
    return TRUE;
}

