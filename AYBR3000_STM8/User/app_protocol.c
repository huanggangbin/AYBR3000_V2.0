#include "app_protocol.h"

//ģ�����澡����Ҫ����״̬!!,���ڲ�����һ��˽�нṹ

void app_protocol_init(App_frame * pframe)
{
    memset(pframe, 0, sizeof (App_frame));
}

void app_protocol_send(App_frame * pframe)
{
    protocol_send((uint8 *)&pframe, sizeof ((App_frame));
}
