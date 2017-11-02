#ifndef _SIMPLE_PROTOCOL_H_
#define _SIMPLE_PROTOCOL_H_
#include "SIMPLE_CLOCK.h"
#include "SIMPLE_DATA.h"
#include "timing.h"
#include "types.h"
    
void simple_protocol_send_header(void);
void simple_protocol_send_byte(void);

#define simple_protocol_set_pin_data(level) SIMPLE_DATA_Write(level)
#define simple_protocol_set_pin_clock(level) SIMPLE_CLOCK_Write(level)
#define PACKET_MAX_LEN 10
#define PACKET_HEADER_LEN 2
typedef struct
{
    enum {
        IDLE,
        HEADER_HIGH,
        HEADER_LOW,
        DATA,
    }state;
    enum {
        ENTER,
        IN,
        EXIT
    }action;
}Simple_protocol_state;

#pragma pack(1)    /*将对齐方式改为一个字节*/
typedef  struct
{
    uint8   header;
    uint8   length;
    uint8   buf[PACKET_MAX_LEN - PACKET_HEADER_LEN];
}Simple_protocol_format;
#pragma pack()    /*恢复之前的对齐方式*/

void simple_protocol_init(void);
void simple_protocol_process(void);
Bool simple_protocol_send(uint8 *buffer, uint8 len);
#endif

