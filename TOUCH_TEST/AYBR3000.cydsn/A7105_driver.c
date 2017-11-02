/*********************************************************************
**    Device:    A7105                                                    
**    File:    A7105_driver.c                                                  
**                                                                    
**    Description:                                                     
**    This file is a sample code for your    reference.                    
**                                                                    
**    Copyright (C) 2008 AMICCOM Corp.                                
**                                                                    
*********************************************************************/

#include "A7105_driver.h"
#include <GIO1_ISR.h>

static Bool buffer_length_ok(uint8 length);
static Bool CRC_check_ok(void);

/*********************************************************************
* 模块初始化函数
*********************************************************************/
void A7105_init(void)
{
    SDIO_DDR_OUT();
    SCS_PIN_HIGH();
    SCK_PIN_LOW();
    SDIO_PIN_HIGH();
   
    A7105_Reset();        //reset A7105 RF chip
    A7105_WriteID();    //write ID code
    A7105_Config();        //config A7105 chip
    A7105_Calibration();        //calibration IF,vco, vcoc
    
    StrobeCmd(CMD_STBY);

    A7105_WriteReg(TXTEST_REG, 0x17 );                  //    TX power = 0dBm
    A7105_WriteReg(DATARATE_REG, 9);                   //    Data rate = 50K
    A7105_WriteReg(MODECTRL_REG, 0x62);               //    FIFO mode
    A7105_WriteReg(PLL1_REG, 99 );                            // set radio channel,设置信道频率
    A7105_WriteReg(CODE1_REG, 0x0F);                       //使能CRC校验
    /*这里等待帧格式确定在设置payload length*/
    A7105_WriteReg(FIFO1_REG, 20-1); // set FIFO payload length
}

/*********************************************************************
** 发送数据
*********************************************************************/
void send_data_by_A7105(uint8 buffer_length, uint8 send_buffer[]) 
{
    if (buffer_length_ok(buffer_length) && send_buffer != NULL)
    {
        StrobeCmd(CMD_TFR);
        WriteFIFO(buffer_length, send_buffer); 
        
        StrobeCmd(CMD_STBY);   //若当前是RX状态,是无法直接切换到TX状态的
        StrobeCmd(CMD_TX);
        //while(RF_WTR());// 浮空输入脚,A7105发送开始拉高,发送结束拉低
        //发送完成会自动回到之前的状态StandBy
    }
    else
    {
    }
}

Bool receive_data_by_A7105(uint8 buffer_length, uint8 receive_buffer[])
{
    Bool ret = FALSE;
    
    if (buffer_length_ok(buffer_length) && receive_buffer != NULL)
    {
//GIO1_ClearInterrupt();
//GIO1_ISR_ClearPending();
//GIO1_ISR_Enable();
        StrobeCmd(CMD_RX);
        if (A7105_read_wtr())          // 浮空输入脚,A7105接收开始拉高接收结束拉低
        {
            A7105_update_wtr(FALSE);
//GIO1_ISR_Disable();
            if (CRC_check_ok())
            {
                ReadFIFO(buffer_length, receive_buffer);
                StrobeCmd(CMD_RFR);
                ret = TRUE;

            }
            else
            {
                
            }
        }
        //接收够payload 长度后,会自动从RX状态返回到STANDBY状态
    }
    else
    {
    }

    return ret;
}

void A7105_sleep(void)
{
    StrobeCmd(CMD_SLEEP);
}

void A7105_wakeup(void)
{
    StrobeCmd(CMD_STBY);
}

static Bool buffer_length_ok(uint8 length)
{
    if (length >= 0 && length <= MAX_BUFFER_SIZE)
        return TRUE;
    else
        return FALSE;
}

static Bool CRC_check_ok(void)
{
    uint8 temp;
    
    temp = A7105_ReadReg(MODE_REG);
    
    if (temp & 0x20)
        return FALSE;
    else
        return TRUE;
}

