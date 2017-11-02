#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_
#include "types.h"

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

extern void protocol_init(void);
extern void protocol_process(void);

#endif

