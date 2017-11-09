#include "app_protocol.h"


App_frame app_frame_send;
App_frame app_frame_receive;

void app_protocol_init(void)
{
    memset(&app_frame_send, 0, sizeof (App_frame));
    memset(&app_frame_receive, 0, sizeof (App_frame));
}

void app_protocol_send(void)
{
    datalink_protocol_send((uint8 *)&app_frame_send, sizeof (App_frame));
}

bool app_protocol_receive(void)
{
    return datalink_protocol_receive((uint8 *)&app_frame_send, sizeof (App_frame));
}

