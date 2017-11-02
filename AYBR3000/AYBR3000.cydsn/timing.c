#include "timing.h"

static uint16 counter = 0;
static uint16 timing_get_count(void);
/*
**1ms增加一次
*/
inline void timing_count(void)
{
    counter++;
}
/*
**获取counter当前值
*/
static uint16 timing_get_count(void)
{    
    return counter;
}

/*
**设置定时长度,
*/
void timing_set_counts(Timing_type *pdata, uint16 set_count)
{   
    pdata->old_count = timing_get_count();   
    pdata->set_count = set_count;    
    pdata->count_end = FALSE;
}

/*
**定时时间到
*/
Bool timing_count_end(Timing_type *pdata)
{   
    uint16 temp = 0;
    if ((pdata->count_end) == FALSE)    
    {        
        temp = timing_get_count() - (pdata->old_count);
        if (temp > (pdata->set_count))        
        {            
            pdata->count_end  = TRUE;       
        }          
    }   
    return (pdata->count_end);
}
