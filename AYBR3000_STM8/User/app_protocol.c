#include "app_protocol.h"


App_frame app_frame;

void app_protocol_init(void)
{
    memset(&app_frame, 0, sizeof (App_frame));
}

void app_protocol_send(void)
{
    datalink_protocol_send((uint8 *)&app_frame, sizeof (App_frame));
}

