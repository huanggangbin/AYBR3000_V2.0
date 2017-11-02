#ifndef _A7105_DRIVER_H_
#define _A7105_DRIVER_H_
#include "A7105_firmware_lib.h"

extern void A7105_init(void);
extern void send_data_by_A7105(uint8 buffer_length, uint8 send_buffer[]);
extern bool receive_data_by_A7105(uint8 buffer_length, uint8 receive_buffer[]);
extern void A7105_sleep(void);
extern void A7105_wakeup(void);

#endif

