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
#include "key.h"


static Key_event_handler event_handlers[KEY_NUMBER][KEY_EVENT_NUMBER - 1];     //KEY_STUCK不需要event handler

#define  KEY_COMBINE_MAX_NUMBER 3u
static uint8 combine_key_number = 0;

static Key_combine combine_keys[KEY_COMBINE_MAX_NUMBER];
static void key_event_deal(Key_Index i, Key_event e);
static void key_combine_deal(Key_Index i, Key_Index j);
static void key_conbine_check(void);

Key keys[KEY_NUMBER];
Key_state state[KEY_NUMBER];

const uint8 key_debounce_time = 20 / KEY_MODULE_SCHEDULE_PERIOD;
const uint16 key_long_press_time = 3000 / KEY_MODULE_SCHEDULE_PERIOD;
const uint16 key_stuck_time = 10000 / KEY_MODULE_SCHEDULE_PERIOD;

void key_init(void)
{
    Key_Index i;
    
    memset(keys, 0, sizeof (Key) * KEY_NUMBER);
    for (i = 0; i < KEY_NUMBER; i++)
    {
        keys[i].pin = input_pins[i];
        keys[i].active_level = LEVEL_HIGH;
        keys[i].level_time = 0;
        state[i] = KEY_RELEASE;
    }
}

void key_process(void)
{
    Key_Index i;
    
    for (i = 0; i < KEY_NUMBER; i++)
    {
        keys[i].current_level = keys[i].pin();

        if (keys[i].current_level == keys[i].previous_level)
        {
            keys[i].level_time++;
            if (keys[i].level_time < key_debounce_time)
                continue;
            
            //此时keys[i].level_time >= 消抖时间
            switch(state[i])
            {
                case KEY_RELEASE: 
                    if (keys[i].current_level == keys[i].active_level)
                    {
                        state[i] = KEY_PRESS;
                        key_conbine_check();
                    }
                    break;
                case KEY_PRESS: 
                    if (keys[i].current_level != keys[i].active_level)
                    {
                        state[i] = KEY_RELEASE;
                        key_event_deal(i, KEY_EVENT_SHORT_PRESS);
                    }
                    else
                    {
                        if (keys[i].level_time > key_long_press_time)
                        {
                            state[i] = KEY_LONG_PRESS;
                            key_event_deal(i, KEY_EVENT_LONG_PRESS);
                        }
                    }
                    break;
                case KEY_LONG_PRESS:
                    if (keys[i].current_level != keys[i].active_level)
                    {
                        state[i] = KEY_RELEASE;
                        key_event_deal(i, KEY_EVENT_LONG_RELEASE);
                    }
                    else
                    {
                        if (keys[i].level_time > key_stuck_time)
                        {
                            state[i] = KEY_STUCK;
                        }
                    }
                    break;
                case KEY_STUCK:
                    if (keys[i].current_level != keys[i].active_level)
                        state[i] = KEY_RELEASE;
                    //防止level_time变量发生上溢
                    if (keys[i].level_time > 50000u)
                        keys[i].level_time = 15000;
                    break;
            }
        }
        else
        {
            keys[i].level_time = 0;
            keys[i].previous_level = keys[i].current_level;
        }
    }
    
}

Bool key_add_event_handler(Key_Index i, Key_event e, Key_event_handler h)
{
    if (i >= KEY_NUMBER || e >= KEY_EVENT_NUMBER)
        return FALSE;
    else
    {
        event_handlers[i][e] = h;
        return TRUE;
    }
}

Bool key_add_combine_handler(Key_Index i, Key_Index j, Key_conbine_handler h)
{
    Key_Index key1, key2;
    
    if (combine_key_number >= KEY_COMBINE_MAX_NUMBER)
        return FALSE;
    if (i == j)
        return FALSE;
    if (h == NULL)
        return FALSE;
    
    key1 = MIN(i, j);
    key2 = MAX(i, j);
    combine_keys[combine_key_number].key1 = key1;
    combine_keys[combine_key_number].key2 = key2;
    combine_keys[combine_key_number].handler = h;
    combine_keys[combine_key_number].state = COMBINE_DISABLE;
    combine_key_number++;
    
    return TRUE;
}

static void key_event_deal(Key_Index i, Key_event e)
{
    if (i >= KEY_NUMBER || e >= KEY_EVENT_NUMBER)
        return;
    if (event_handlers[i][e] != NULL)
        event_handlers[i][e]();
}

static void key_combine_deal(Key_Index i, Key_Index j)
{
    uint8 n;
    Key_Index key1, key2;
    
    if (i == j)
        return;
    
    key1 = MIN(i, j);
    key2 = MAX(i, j);
    for (n = 0; n < combine_key_number; n++)
    {
        if (combine_keys[n].handler == NULL)
            continue;
        if (combine_keys[n].key1 == key1 && combine_keys[n].key2 == key2)
            combine_keys[n].handler();
    }
   
}

static void key_conbine_check(void)
{
    Key_Index i, key1, key2;
    uint8 key_count;
    
    for (i = 0, key_count = 0; i < KEY_NUMBER; i++)
    {
        if (state[i] != KEY_PRESS && state[i] != KEY_LONG_PRESS)
           continue;
        key_count++;
        if (key_count == 1)
            key1 = i;
        if (key_count == 2)
            key2 = i;
    }
    
    if (key_count == 2)
    {
        key_combine_deal(key1, key2);
        state[key1] = KEY_STUCK;
        state[key2] = KEY_STUCK;
        keys[i].level_time = 10000;
        keys[i].level_time = 10000;
    }
}

/* [] END OF FILE */
