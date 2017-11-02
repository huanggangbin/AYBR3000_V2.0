#ifndef _SIMPLE_PROTOCOL_H_
#define _SIMPLE_PROTOCOL_H_
#include "stm8l15x.h"
#include "timing.h"
#include "types.h"
#define PACKET_MAX_LEN 10
#define PACKET_HEADER_LEN 2

typedef struct
{
    enum {
        CLOCK_IDLE,
        CLOCK_HEADER,
        FRAME_HEADER,
        FRAME_LENGTH,
        FRAME_DATA,
        CHECKSUM
    }state;
    enum {
        ENTER,
        IN,
        EXIT
    }action;
}Simple_protocol_state;

//#pragma pack(1)    /*将对齐方式改为一个字节*/
typedef  struct
{
    uint8   header;
    uint8   length;
    uint8   data[PACKET_MAX_LEN - PACKET_HEADER_LEN];
}Simple_protocol_format;
//#pragma pack()    /*恢复之前的对齐方式*/

#define READ_CLOCK_PIN_LEVEL() (GPIOC->IDR & GPIO_Pin_1)
#define READ_DATA_PIN_LEVEL() (GPIOC->IDR & GPIO_Pin_0)

extern void receive_deal(void);
bool simple_protocol_data_received(void);

extern u8 receive_buffer[24];
#endif

