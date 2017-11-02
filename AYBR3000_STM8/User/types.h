#ifndef _TYPES_H_
#define _TYPES_H_

#include "stddef.h"
#include "stm8l15x.h"
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
    LEVEL_LOW = 0,
    LEVEL_HIGH = !LEVEL_LOW,
}Level;

#endif 

