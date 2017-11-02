#include "simple_protocol.h"

static Timing_type header_time;
static Simple_protocol_state send_state;
static Bool flag_send = FALSE;
static uint8 send_buffer[PACKET_MAX_LEN];

static inline void send_byte(uint8 data);
static inline void delay_50_us(void);


void simple_protocol_init(void)
{
    uint8 i;
    uint8 *p = (uint8 *)&header_time;
    
    for (i = 0; i < sizeof (Timing_type); i++)
        p[i] = 0;
    send_state.state = IDLE;
}

void simple_protocol_process(void)
{
    
    uint8 i = 0;
    static Simple_protocol_format *pbuf = (Simple_protocol_format *)send_buffer;
    
    switch (send_state.state)
    {
        case IDLE: 
            if (flag_send)
            {
                flag_send = FALSE;
                send_state.state = HEADER_HIGH;
                send_state.action = ENTER;
            }
            break;
        case HEADER_HIGH: 
            switch(send_state.action)
            {
                case ENTER: 
                    simple_protocol_set_pin_clock(LEVEL_HIGH);
                    timing_set_counts(&header_time, 5);
                    send_state.action = IN; 
                    break;
                case IN: 
                    if (timing_count_end(&header_time))
                        send_state.action = EXIT;
                    break;
                case EXIT: 
                    send_state.state = HEADER_LOW;
                    send_state.action = ENTER;
                    break;
            }
            break;
        case HEADER_LOW: 
            switch(send_state.action)
            {
                case ENTER: 
                    simple_protocol_set_pin_clock(LEVEL_LOW);
                    timing_set_counts(&header_time, 5);
                    send_state.action = IN; 
                    break;
                case IN: 
                    if (timing_count_end(&header_time))
                        send_state.action = EXIT;
                    break;
                case EXIT: 
                    send_state.state = DATA;
                    send_state.action = ENTER;
                    break;
            }
            break;
        case DATA: 
            switch (send_state.action)
            {
                case ENTER:
                    send_state.action = IN; 
                    break;
                case IN:
                    for (i = 0; i < pbuf->length; i++)
                        send_byte(send_buffer[i]);
                    send_state.action = EXIT;
                    break;
                case EXIT:
                    send_state.state = IDLE;
                    break;
            }
            break;
    }
} 

Bool simple_protocol_send(uint8 *buffer, uint8 len)
{
    Simple_protocol_format *pbuf = (Simple_protocol_format *)send_buffer;
    uint8 i, check_sum = 0;
    
    if (send_state.state == IDLE)
    {
        pbuf->header = 0x5a;
        pbuf->length = len + 3;
        for (i = 0; i < pbuf->length - PACKET_HEADER_LEN - 1; i++)
            pbuf->buf[i] = buffer[i];
        
        for (i = 0; i < pbuf->length - 1; i++)
            check_sum += send_buffer[i];

        send_buffer[pbuf->length - 1] = check_sum;
        flag_send = TRUE;
        return TRUE;
    }
    else
        return FALSE;
}

static inline void send_byte(uint8 data)
{
    uint8 i = 0, temp;
    temp = data;
    for (i = 0; i < 8; i++)
    {
        if (temp & 0x01)
            simple_protocol_set_pin_data(LEVEL_HIGH);
        else
            simple_protocol_set_pin_data(LEVEL_LOW);
        delay_50_us();
        simple_protocol_set_pin_clock(LEVEL_HIGH);
        delay_50_us();
        temp >>= 1u;
        delay_50_us();
        simple_protocol_set_pin_clock(LEVEL_LOW);
        delay_50_us();
    }
}

static inline void delay_50_us(void)
{
    uint8 i = 0;
    
    for (i = 0; i < 100; i++)
        asm("nop");
}