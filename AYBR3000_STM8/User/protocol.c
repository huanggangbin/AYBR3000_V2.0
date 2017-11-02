#include "protocol.h"
#include <string.h>

static App_protocol protocol;

void protocol_init(void)
{
    memset(&protocol, 0, sizeof(App_protocol));
    protocol.header = 0xAA;
    protocol.f_type = FRAME_TYPE_REQ;
    protocol.src_ID[0] = 11;
    protocol.src_ID[1] = 22;
    protocol.src_ID[2] = 33;
    protocol.src_ID[3] = 44;
}

void protocol_process(void)
{
    
}


