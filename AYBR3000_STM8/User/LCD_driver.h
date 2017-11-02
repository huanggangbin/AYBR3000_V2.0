#ifndef _LCD_DRIVER_H_
#define _LCD_DRIVER_H_
#include "LCD_firmware.h"
#include "types.h"

typedef enum
{
    ICON1,
    ICON2,
    ICON3,
    ICON4,
    ICON5,
    ICON6,
    ICON7,
    ICON8,
    ICON9,
    ICON10,
    ICON11,
    ICON12,
    ICON13,
    ICON14,
    ICON15,
    ICON16, 
    ICON17,   //COL
    ICON_NUMBERS,
}ICON_index;

typedef struct
{
        uint8 com;
        uint8 seg;
}Point;

typedef enum
{
    TUBE1,
    TUBE2,
    TUBE3,
    TUBE4,
    TUBE5,
    TUBE6,
    TUBE7,
    TUBE8,
    TUBE_NUMBERS,
}Digital_tube_index;

typedef enum
{
    VALUE_NULL,
    VALUE_0,
    VALUE_1,
    VALUE_2,
    VALUE_3,
    VALUE_4,
    VALUE_5,
    VALUE_6,
    VALUE_7,
    VALUE_8,
    VALUE_9,
    VALUE_NUMS,
}Tube_value;

typedef enum
{
    POINT_A,
    POINT_B,
    POINT_C,
    POINT_D,
    POINT_E,
    POINT_F,
    POINT_G,
    POINT_NUMBERS,
}Point_index;

typedef struct
{
    Point p[POINT_NUMBERS];
}Tube;

#define COM_NUM   4
#define SEG_NUM   28

extern uint8 lcd_ram_buffer[14];
extern uint8 ram_offset[COM_NUM][SEG_NUM];

extern void LCD_driver_init(void);
extern void icon_set(ICON_index index, Switch value);
extern void digital_tube_set(Digital_tube_index index, Tube_value value);
extern void LCD_driver_refresh(void);
#endif

