#ifndef _TYPES_H_
#define _TYPES_H_

#include "stddef.h"

/*!< Unsigned integer types  */
typedef unsigned char    uint8;
typedef unsigned short    uint16;
typedef unsigned long    uint32;

typedef enum
{
    OFF = 0,
    ON = !OFF,
}Switch;

typedef enum
{
    FALSE = 0,
    TRUE = !FALSE,
}Bool;

typedef enum
{
    RESET = 0, 
    SET = !RESET,
}BitStatus;

typedef enum
{
    LEVEL_LOW = 0,
    LEVEL_HIGH = !LEVEL_LOW,
}Level;

#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

#endif 

