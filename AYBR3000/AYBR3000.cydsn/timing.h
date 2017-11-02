#ifndef _TIMING_H_
#define _TIMING_H_

#include "types.h"

typedef struct 
{    
    Bool  count_end;    
    uint16  old_count;    
    uint16  set_count;
}Timing_type;

/*
**1ms中断中调用
*/
extern inline void timing_count(void);
/*
**设置定时长度,
*/
extern void timing_set_counts(Timing_type *pdata, uint16 set_count);
/*
**定时时间到
*/
extern Bool timing_count_end(Timing_type *pdata);
#endif

