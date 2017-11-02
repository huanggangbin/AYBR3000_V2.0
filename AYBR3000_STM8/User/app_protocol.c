#include "app_protocol.h"

//模块里面尽量不要包含状态!!,如内部定义一个私有结构

void app_protocol_init(App_frame * pframe)
{
    memset(pframe, 0, sizeof (App_frame));
}

void app_protocol_send(App_frame * pframe)
{
    protocol_send((uint8 *)&pframe, sizeof ((App_frame));
}
