#include "datalink_protocol.h"
#include <string.h>

static App_protocol send_frame;
static App_protocol receive_frame;

void datalink_protocol_init(void)
{
    memset(&send_frame, 0, sizeof(App_protocol));
    memset(&receive_frame, 0, sizeof(App_protocol));
    
    send_frame.header = 0xAA;
    send_frame.f_type = FRAME_TYPE_REQ;
    send_frame.src_ID[0] = 11;
    send_frame.src_ID[1] = 22;
    send_frame.src_ID[2] = 33;
    send_frame.src_ID[3] = 44;
}

void datalink_protocol_process(void)
{
    if (receive_data_by_A7105(sizeof(App_protocol), (uint8 *)&receive_frame))
    {
        if (receive_frame.header != send_frame.header)
            return;
        if (receive_frame.f_type!= FRAME_TYPE_ACK)
            return;
        if (receive_frame.dest_ID[0] != send_frame.src_ID[0])
            return;
        if (receive_frame.dest_ID[1] != send_frame.src_ID[1])
            return;
        if (receive_frame.dest_ID[2] != send_frame.src_ID[2])
            return;
        if (receive_frame.dest_ID[3] != send_frame.src_ID[3])
            return;
        //后面还有check_sum的计算
    }
}

bool datalink_protocol_send(uint8 * data, uint8 length)
{
    uint8 i, check_sum = 0;
    uint8 * buffer = (uint8 *)&send_frame;
    
    if (data == NULL)
        return FALSE;
    if (length >10)
        return FALSE;
    
    for (i = 0; i < length; i++)
        send_frame.data[i] = data[i];
    
    //check_sum的添加
    for (i = 0; i < length + PROTOCOL_HEAD_LENGTH; i++)
        check_sum += buffer[i];

    buffer[length + PROTOCOL_HEAD_LENGTH] = ~check_sum + 1;

    send_data_by_A7105(sizeof(App_protocol), (uint8 *)&send_frame);

    return TRUE;
}

bool datalink_protocol_receive(uint8 * data, uint8 length)
{
    uint8 i;

    if (data == NULL)
        return FALSE;
    if (length >10)
        return FALSE;
        
    for (i = 0; i < length; i++)
    {
        
    }
        return TRUE;
}

