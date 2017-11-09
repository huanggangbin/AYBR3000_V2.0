#ifndef _DATALINK_PROTOCOL_H_
#define _DATALINK_PROTOCOL_H_
#include "types.h"
#include "A7105_driver.h"

typedef enum
{
    FRAME_TYPE_REQ = 0x01,
    FRAME_TYPE_ACK = 0x41,
}App_protocl_frame_type;

typedef struct
{
    uint8 header;
    App_protocl_frame_type f_type;
    uint8 src_ID[4];
    uint8 dest_ID[4];
    uint8 data[10];
}App_protocol;

#define PROTOCOL_HEAD_LENGTH 10u        //data[]前面的字节数

extern void datalink_protocol_init(void);
extern bool datalink_protocol_send(uint8 * data, uint8 length);
extern bool datalink_protocol_receive(uint8 * data, uint8 length);

#endif

