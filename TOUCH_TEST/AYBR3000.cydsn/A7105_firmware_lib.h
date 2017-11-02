/*********************************************************************                                                                     **
**    Device:    A7105
**    File:    A7105REG.h
**
**    Description:
**    RF Chip-A7105 Definitions
**
**    Copyright (C) 2008 AMICCOM Corp.
**
*********************************************************************/


#ifndef    _A7105REG_H_
#define    _A7105REG_H_
#include "types.h"
#include "GIO1.h"
#include "SCK.h"
#include "SCS.h"
#include "SDIO.h"
 // A7105各寄存器地址定义

typedef enum
{
    MODE_REG = 0x00,
    MODECTRL_REG = 0x01,
    CALIBRATION_REG = 0x02,
    FIFO1_REG = 0x03,
    FIFO2_REG = 0x04,
    FIFO_REG = 0x05,
    IDCODE_REG = 0x06,
    RCOSC1_REG = 0x07,
    RCOSC2_REG = 0x08,
    RCOSC3_REG = 0x09,
    CKO_REG = 0x0A,
    GPIO1_REG = 0x0B,
    GPIO2_REG = 0x0C,
    CLOCK_REG =   0x0D,
    DATARATE_REG = 0x0E,
    PLL1_REG = 0x0F,
    PLL2_REG = 0x10,
    PLL3_REG = 0x11,
    PLL4_REG = 0x12,
    PLL5_REG = 0x13,
    TX1_REG = 0x14,
    TX2_REG = 0x15,
    DELAY1_REG = 0x16,
    DELAY2_REG = 0x17,
    RX_REG = 0x18,
    RXGAIN1_REG = 0x19,
    RXGAIN2_REG = 0x1A,
    RXGAIN3_REG = 0x1B,
    RXGAIN4_REG = 0x1C,
    RSSI_REG = 0x1D,
    ADC_REG = 0x1E,
    CODE1_REG = 0x1F,
    CODE2_REG = 0x20,
    CODE3_REG = 0x21,
    IFCAL1_REG = 0x22,
    IFCAL2_REG = 0x23,
    VCOCCAL_REG = 0x24,
    VCOCAL1_REG = 0x25,
    VCOCAL2_REG = 0x26,
    BATTERY_REG = 0x27,
    TXTEST_REG = 0x28,
    RXDEM1_REG = 0x29,
    RXDEM2_REG = 0x2A,
    CPC_REG = 0x2B,
    CRYSTALTEST_REG = 0x2C,
    PLLTEST_REG = 0x2D,
    VCOTEST1_REG = 0x2E,
    VCOTEST2_REG = 0x2F,
    IFAT_REG = 0x30,
    RSCALE_REG = 0x31,
    FILTERTEST_REG = 0x32,
    REG_NUMBER
}A7105_REG;

//  A7105的strobe command定义

typedef enum
{
    CMD_SLEEP = 0x80,     //1000,xxxx    SLEEP mode
    CMD_IDLE = 0x90,       //1001,xxxx    IDLE mode
    CMD_STBY = 0xA0,      //1010,xxxx    Standby    mode
    CMD_PLL =  0xB0,       //1011,xxxx    PLL    mode
    CMD_RX = 0xC0,          //1100,xxxx    RX mode
    CMD_TX = 0xD0,          //1101,xxxx   TX mode            0xD0    //1101,xxxx    TX mode
    CMD_TFR = 0xE0,       //1110,xxxx    TX FIFO    reset
    CMD_RFR = 0xF0,       //1111,xxxx    RX FIFO    reset
}A7105_CMD;

// A7105下层接口定义

#define A7105_NOP()                  asm("nop")
#define A7105_CLEAR_WDT()                  asm("nop")
//用于指示芯片射频packet收发完成,(WTR一直是输入脚)
#define GIO1_IN()                       (GIO1_Read())
#define RF_WTR()                        GIO1_Read()


//数据起止信号,(一直是发送脚)
#define SCS_PIN_HIGH()                 (SCS_Write(1))
#define SCS_PIN_LOW()                  (SCS_Write(0))
//数据同步时钟,(一直是发送脚)
#define SCK_PIN_HIGH()                 (SCK_Write(1))
#define SCK_PIN_LOW()                  (SCK_Write(0))

//数据发送引脚
#define SDIO_DDR_OUT()              asm("nop")
#define SDIO_PIN_HIGH()             (SDIO_Write(1))
#define SDIO_PIN_LOW()              (SDIO_Write(0))

//数据接收引脚
#define SDIO_DDR_IN()               asm("nop")
#define SDIO_IN()                   (SDIO_Read())

// A7105收发,软件buffer,长度设定

#define MAX_BUFFER_SIZE 64u


extern void A7105_Config(void);
extern void A7105_Calibration(void);
extern uint8 A7105_ReadReg(uint8 addr);
extern void A7105_WriteReg(A7105_REG addr,    uint8 dataByte);
extern void StrobeCmd(A7105_CMD cmd);
extern void A7105_Reset(void);
extern void A7105_WriteID(void);
//void A7105_ReadID(void);
extern void WriteFIFO(uint8 length, uint8 pbuf[]);
extern void ReadFIFO(uint8 length, uint8 pbuf[]);

extern uint8 A7105_read_wtr(void);
extern void A7105_update_wtr(Bool value);

#endif

