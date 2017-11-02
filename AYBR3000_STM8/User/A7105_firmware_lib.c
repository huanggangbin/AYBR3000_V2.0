/*********************************************************************
**    Device:    A7105_firmware_lib.c                              
**    File:    main.c                                                    
**                                                                    
**    Description:                                                     
**    This file is a sample code for your    reference.                    
**                                                                    
**    Copyright (C) 2008 AMICCOM Corp.                                
**                                                                    
*********************************************************************/
#include "A7105_firmware_lib.h"

/*********************************************************************
** RF ID code
*********************************************************************/
const uint8 ID_Tab[4] =
{
    0x54, 0x75, 0xC5, 0x2A
};

/*********************************************************************
**                                     NOTE                                     
**          THIS CONFIG TABLE    ONLY USE ON    RF CRYSTAL = 16MHz                 
*********************************************************************/
const uint8 parameters_Config[REG_NUMBER] =
{
    //    value  address    name                    note
    //    ----     ----    ----                    ----
    0x00, // 0x00    RESET register,            //写零复位,不用初始化            
    //各种状态标志,FEC校验,CRC校验 ,芯片使能, 内部晶振使能, 锁相环使能, TRX使能, 收/发标志
    0x62, // 0x01    MODE register,        FIFO模式,进入RX模式后(自动检测RSSI, RF本地晶振会自动偏移一个IF频率)
    0x00, // 0x02    CALIBRATION    register,    only read, not use on config
    0x3F, // 0x03    FIFO1 register,           //64KB   FIFO内部缓存
    0x00, // 0x04    FIFO2 register,          //用easy FIFO, 不使用segment FIFO
    0x00, // 0x05    FIFO register,            //不用初始化,用于队列的读写,顺序都是BYTE0 -> BYTE7
    0x00, // 0x06    IDDATA register,        //不用初始化,用于向芯片写/读ID号,顺序byte 0 -> byte3
    0x00, // 0x07    RCOSC1 register,       //保留内部使用
    0x00, // 0x08    RCOSC2 register,       //保留内部使用
    0x00, // 0x09    RCOSC3 register,       //BBCKS1 BBCKS0, 建议设置为[00]  , 内部数字线路的频率选择Fsyck / 8
    0x00, // 0x0A    CKO    register,         //CKO管脚时钟输出功能
    0x01, // 0x0B    GIO1 register            //GIO1脚设为WTR功能,使能GIO1脚的输出
    0x01, // 0x0C    GIO2 register            //GIO2脚设为WTR功能,使能GIO2脚的输出
    0x05, // 0x0D    CLOCK register,         //外部时钟源,晶振时钟源,Fsyck = Fmclk / 2
    0x00, // 0x0E    DATARATE register,        //数据传输速率设置
    0x50, // 0x0F    PLL1 register,                 //频率设定= 基频 + 频道间距*频道号
    0x9E, // 0x10    PLL2 register,                 //
    0x4B, // 0x11    PLL3 register,                 //推荐值,LO 基频整数部分设置
    0x00, // 0x12    PLL4 register,                 //频率补偿,支持第精度的石英振荡器
    0x02, // 0x13    PLL5 register,                 //频率补偿,读取计算频率漂移,重新设定频率
    0x16, // 0x14    TX1    register,               //频率偏差、调制选择、滤波使能
    0x2B, // 0x15    TX2    register,                //
    0x12, // 0x16    DELAY1 register,             //一些时钟延时设置
    0x00, // 0x17    DELAY2 register,                //
    0x62, // 0x18    RX register,                       // AIF使能启用自动中频(调制后的频率)偏移,ULS位(收发主仆角色互换设置)
    0x80, // 0x19    RXGAIN1    register,           //
    0x80, // 0x1A    RXGAIN2    register,           保留内部使用
    0x00, // 0x1B    RXGAIN3    register,           保留内部使用
    0x0A, // 0x1C    RXGAIN4    register,           保留内部使用,必须设置0x0A
    0x32, // 0x1D    RSSI register,                     //载波侦测CD阈值设置,当前频道是否忙碌
    0xC3, // 0x1E    ADC    register,                   //接收信号强度RSSI检测
    0x0F, // 0x1F    CODE1 register,                  //CRC校验,(7,4)海明码编码,PN7数据加密,    FIFO发送相关,数据包格式
    0x16, // 0x20    CODE2 register,                  //FIFO发送相关,ID, preamble检测
    0x00, // 0x21    CODE3 register,                  //FIFO发送相关,数据加密种子设置
    0x00, // 0x22    IFCAL1 register,                  //IF filter校正相关
    0x00, // 0x23    IFCAL2 register,                  only read,  IF filter calibration deviation
    0x00, // 0x24    VCOCCAL    register,           //VCO current校正     
    0x00, // 0x25    VCOCAL1    register,           //VCO bank校正
    0x3B, // 0x26    VCOCAL2    register,           //VCO bank校正
    0x00, // 0x27    BATTERY    register,           //电压检测相关
    0x1F, // 0x28    TXTEST register,                //发送信号增益和电流值设置
    0x47, // 0x29    RXDEM1 register,              //preamble后面8位数据的电流平均值
    0x80, // 0x2A    RXDEM2 register,              //测试用,解调器修复模式直流电流值设定
    0x03, // 0x2B    CPC    register,                 //PLL电荷泵设置
    0x01, // 0x2C    CRYSTAL    register,          //内部保留,必须设置为0x01
    0x45, // 0x2D    PLLTEST    register,          //内部保留,必须设置为0x45
    0x18, // 0x2E    VCOTEST1 register,          //内部保留,必须设置为0x18
    0x00, // 0x2F    VCOTEST2 register,          //内部保留,必须设置为0x00
    0x01, // 0x30    IFAT register,                  //内部保留,必须设置为0x01
    0x0F, // 0x31    RSCALE register,             //内部保留,必须设置为0x0F
    0x00, // 0x32    FILTERTEST                   //内部保留,必须设置为0x00
};
/*从1ms中断中读取wtr的状态*/
bool A7105_wtr_status = FALSE;

/*********************************************************************
**    static function Declaration
*********************************************************************/
static uint8 ByteRead(void);
static void ByteSend(uint8 data);
static inline void Wait_Bit_n_clear(uint8 reg_data, uint8 nbit);
static inline void SelVCOBand(uint8 vb1, uint8 vb2);
static inline void Error_State(void);

/************************************************************************
**    A7105_WriteReg
************************************************************************/
void A7105_WriteReg(A7105_REG addr,    uint8 dataByte)
{
    SCS_PIN_LOW();

    addr |= 0x00; //bit cmd=0,r/w=0寄存器命令, 写

    ByteSend(addr);

    A7105_NOP();
    ByteSend(dataByte);
    
    SCS_PIN_HIGH();
}

/************************************************************************
**    A7105_ReadReg
************************************************************************/
uint8 A7105_ReadReg(uint8 addr)
{
    uint8 tmp;

    SCS_PIN_LOW();

    addr |= 0x40; //bit cmd=0,r/w=1寄存器命令,读
    ByteSend(addr);
    A7105_NOP();
    //read data
    tmp = ByteRead();
    
    SCS_PIN_HIGH();
    return tmp;
}

/*********************************************************************
** Strobe Command
*********************************************************************/
void StrobeCmd(A7105_CMD cmd)
{
    SCS_PIN_LOW();
    
    ByteSend(cmd);
    
    SCS_PIN_HIGH();
}

/************************************************************************
**    WriteID
************************************************************************/
void A7105_WriteID(void)
{
    uint8 i;
    uint8 addr;
    
    //send address 0x06, bit cmd=0, r/w=0
    addr = IDCODE_REG; 
    SCS_PIN_LOW();
    ByteSend(addr);
    for (i=0; i < 4; i++)
        ByteSend(ID_Tab[i]);
    SCS_PIN_HIGH();
}

/************************************************************************
**    Reset_RF
************************************************************************/
void A7105_Reset(void)
{
    //reset    RF chip
    A7105_WriteReg(MODE_REG, 0x00);    
}

/*********************************************************************
** A7105_Config
*********************************************************************/
void A7105_Config(void)
{
    uint8 i;
    //0x00 mode    register, for reset
    //0x05 fifo    data register
    //0x06 id code register
    //0x23 IF calibration II, only read
    //0x32 filter test register

    //下面对各寄存器作初始化FIFO模式,四线SPI
    //部分不需要初始化的跳过
    for (i=0x01; i<=0x04; i++)
        A7105_WriteReg(i, parameters_Config[i]);

    for (i=0x07; i<=0x22; i++)
        A7105_WriteReg(i, parameters_Config[i]);

    for (i=0x24; i<=0x31; i++)
        A7105_WriteReg(i, parameters_Config[i]);
    
}


/*********************************************************************
** SelVCOBand
*********************************************************************/
void SelVCOBand(uint8 vb1, uint8 vb2)
{
    uint8 diff1,diff2;

    if (vb1>=4)
        diff1 = vb1-4;
    else
        diff1 = 4-vb1;

    if (vb2>=4)
        diff2 = vb2-4;
    else
        diff2 = 4-vb2;

    if (diff1 == diff2 || diff1 > diff2)
        A7105_WriteReg(VCOCAL1_REG, (vb1 | 0x08));//manual setting vb1 value
    else
        A7105_WriteReg(VCOCAL1_REG, (vb2 | 0x08));//manual setting vb2 value
}

/*********************************************************************
** calibration
*********************************************************************/
void A7105_Calibration(void)
{
    uint8 tmp;
    uint8 fbcf;
    uint8 vb1,vbcf1;
    uint8 vb2,vbcf2;

    StrobeCmd(CMD_STBY); //calibration @STB    state

    //calibration IF procedure
    A7105_WriteReg(CALIBRATION_REG, 0x01);   
    Wait_Bit_n_clear(CALIBRATION_REG, 0x01);

    //for check
    tmp = A7105_ReadReg(IFCAL1_REG);
    //fb = tmp & 0x0F;   //读寄存器,得AFB的值
    
    fbcf = (tmp >> 4) & 0x01;   //取得FBCF位

    if (fbcf == SET)
    {
        Error_State();
    }

    //calibration vcoc procedure
    A7105_WriteReg(VCOCCAL_REG, 0x13);    //manual    VCOC=3
    

    //CALIBRATIOIN VCOB procedure
    A7105_WriteReg(VCOCAL2_REG, 0x3B);    //VTL=3,    VTH=7   设置上/下位门坎电压
    //在这个频率下进行VCOB校正
    A7105_WriteReg(PLL1_REG, 0);        //setting 2400MHz                F_offset = 0M hz
    A7105_WriteReg(CALIBRATION_REG, 0x02);   //选择校正VCOB
    Wait_Bit_n_clear(CALIBRATION_REG, 0x02);    //等待VCOB校正完毕

    //这个是VCOB的校验结果
    tmp = A7105_ReadReg(VCOCAL1_REG);
    vb1 = tmp & 0x07;    //自动校正的数值
    vbcf1 = (tmp >> 3) & 0x01;    //校正是否成功
    //dvt1 = (tmp >> 4) & 0x03;   //digital VCO tuning voltage output

    //换个频率进行VCOC校正
    A7105_WriteReg(PLL1_REG, 160); //setting 2480MHz     160 * 500K = 80M
    A7105_WriteReg(CALIBRATION_REG, 0x02);
    Wait_Bit_n_clear(CALIBRATION_REG, 0x02);

    tmp = A7105_ReadReg(VCOCAL1_REG);
    vb2 = tmp & 0x07;
    vbcf2 = (tmp >> 3) & 0x01;
    //dvt2 = (tmp >> 4) & 0x03;

    SelVCOBand(vb1, vb2);

    if (vbcf1 == SET && vbcf2 == SET)   //若两次都失败
    {
        Error_State();
        while(1);
    }
}


/************************************************************************
**    ByteSend
************************************************************************/
static void ByteSend(uint8 data)
{
    uint8 i;

    for(i = 0; i < 8; i++)
    {
        //先发送数据的最高有效位
        if(data & 0x80)                 
            SDIO_PIN_HIGH();
        else
            SDIO_PIN_LOW();

        A7105_NOP();
        SCK_PIN_HIGH();
        A7105_NOP();
        SCK_PIN_LOW();
        data = data << 1;
    }
}
//**********************************************************************
//    WriteFIFO
//**********************************************************************
void WriteFIFO(uint8 length, uint8 pbuf[])
{
    uint8 i;
    
    A7105_WriteReg( FIFO1_REG, length-1);    // set FIFO length
    
    SCS_PIN_LOW();
    ByteSend(FIFO_REG);  //写0x05h这个地址的data_register
    for(i=0; i <length; i++)
        ByteSend(pbuf[i]);
    SCS_PIN_HIGH();
}

//**********************************************************************
//    ByteRead
//**********************************************************************
static uint8 ByteRead(void)
{
    uint8 i,tmp = 0;
    
    SDIO_PIN_HIGH(); //sdio pull high

    SDIO_DDR_IN();

    
    for(i = 0; i < 8; i++)
    {
        if(SDIO_IN())    
            tmp = (tmp << 1) | 0x01;
        else
            tmp = tmp << 1;
            
        SCK_PIN_HIGH();//上升沿读取数据
        A7105_NOP();
        SCK_PIN_LOW();//RF IC会在SCK下降沿,将数据放到SDIO
    }
    SDIO_DDR_OUT();
        
    SDIO_PIN_LOW();
    return tmp;
}

/**********************************************************************
**    ReadFIFO
**********************************************************************/
void ReadFIFO(uint8 length, uint8 pbuf[])
{
    uint8 i;

    SCS_PIN_LOW();
    
    ByteSend(FIFO_REG | 0x40);      //0x40是读取标志
    for(i = 0; i <length; i++)
        pbuf[i] = ByteRead();
        
    SCS_PIN_HIGH();
}
/************************************************************************
**   uint8 A7105_read_wtr(void)
************************************************************************/
uint8 A7105_read_wtr(void)
{
    return A7105_wtr_status;
}
/************************************************************************
**   void update_wtr(void)
************************************************************************/
void A7105_update_wtr(bool value)
{
    A7105_wtr_status = value;
}

/************************************************************************
**   GIO1引脚下降沿中断开关
************************************************************************/
void A7105_GIOx_interrupt_switch(Switch s)
{
    if (s == ON)
        GIOx_interrupt_on();
    else
        GIOx_interrupt_off();
}

/************************************************************************
**    WaitBit_n_clear()
************************************************************************/
void Wait_Bit_n_clear(uint8 reg, uint8 nbit)
{
    while(A7105_ReadReg(reg) & nbit) { 
        ; 
    }
}
/*********************************************************************
** Error_State
*********************************************************************/
static inline void Error_State(void)
{
    /*添加错误显示*/
    /*添加错误处理*/
    while (TRUE) {
        ;
    }
}

