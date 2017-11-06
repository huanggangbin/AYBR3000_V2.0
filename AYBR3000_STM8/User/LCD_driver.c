#include "LCD_driver.h"

static uint8 lcd_ram_buffer[14];           //只用到前14个Byte
uint8 ram_offset[COM_NUM][SEG_NUM];

static void segment_set(uint8 com, uint8 seg, Switch value);
static void ram_offset_init(void);

void LCD_driver_init(void)
{
    ram_offset_init();
}

static void ram_offset_init(void)
{
    uint8 i, j, k = 0;

    for (i = 0; i < COM_NUM; i++)
        for (j = 0; j < SEG_NUM; j++)
        {
            ram_offset[i][j] = k;
            k++;
        }
}

Switch value_define[VALUE_NUMS][POINT_NUMBERS] = 
{
    //A    B    C    D    E    F    G
    {OFF, OFF, OFF, OFF, OFF, OFF,   OFF},       // 数码管灭
    {OFF, OFF, OFF, OFF, OFF, ON,   OFF},       // 数码管'-'
    {ON,  ON,   ON,  ON,  ON,   OFF,   ON},       // 数码管'0'
    {OFF,ON,   ON,  OFF, OFF,  OFF,  OFF},      // 数码管'1'
    {ON,  ON,  OFF, ON,   ON,   ON,   OFF },      // 数码管'2'
    {ON,  ON,  ON,  ON,   OFF,  ON,   OFF},      // 数码管'3'
    {OFF,ON,   ON,  OFF, OFF,  ON,   ON},      // 数码管'4'
    {ON,  OFF, ON,  ON,  OFF,   ON,  ON},      // 数码管'5'
    {ON,  OFF, ON,  ON,  ON,    ON,   ON},      // 数码管'6'
    {ON,  ON,  ON,  OFF, OFF,  OFF,  OFF},      // 数码管'7'
    {ON,  ON,  ON,  ON,  ON,    ON,   ON},      // 数码管'8'
    {ON,  ON,  ON,  ON,  OFF,  ON,   ON},      // 数码管'9'
};

static Point icons[ICON_NUMBERS] = {
    {1, 5},       // T1
    {2, 5},       // T2
    {3, 5},       // T3
    {4, 5},       // T4
    {1, 14},     // T5
    {1, 16},     // T6
    {1, 18},     // T7
    {1, 20},     // T8
    {1, 22},     // T9
    {2, 22},     // T10
    {3, 22},     // T11
    {4, 22},     // T12
    {1, 23},     // T13
    {2, 23},     // T14
    {3, 23},     // T15
    {4, 23},     // T16
    {1, 10},     // COL
};

Point tubes[TUBE_NUMBERS][POINT_NUMBERS] = {
   //A    B    C    D    E    F    G   
    {{4, 7}, {3, 7}, {2, 7}, {1, 7}, {2, 6}, {3, 6}, {4, 6}},                  // 1    
    {{4, 9}, {3, 9}, {2, 9}, {1, 9}, {2, 8}, {3, 8}, {4, 8}},                  // 2
    {{4, 11}, {3, 11}, {2, 11}, {1, 11}, {2, 10}, {3, 10}, {4, 10}},      // 3
    {{4, 13}, {3, 13}, {2, 13}, {1, 13}, {2, 12}, {3, 12}, {4, 12}},      // 4
    {{4, 15}, {3, 15}, {2, 15}, {1, 15}, {2, 14}, {3, 14}, {4, 14}},      // 5
    {{4, 17}, {3, 17}, {2, 17}, {1, 17}, {2, 16}, {3, 16}, {4, 16}},      // 6
    {{4, 19}, {3, 19}, {2, 19}, {1, 19}, {2, 18}, {3, 18}, {4, 18}},      // 7
    {{4, 21}, {3, 21}, {2, 21}, {1, 21}, {2, 20}, {3, 20}, {4, 20}},      // 8
};

void icon_set(ICON_index index, Switch value)
{
    segment_set(icons[index].com, icons[index].seg, value);
}

void digital_tube_set(Digital_tube_index index, Tube_value value)
{
    uint8 i = 0;
    
    for (i = 0; i < POINT_NUMBERS; i++)
    {
        segment_set(tubes[index][i].com, tubes[index][i].seg, value_define[value][i]);
    }
}

void LCD_driver_refresh(void)
{
    LCD_GLASS_Refresh(lcd_ram_buffer, 14);
}

static void segment_set(uint8 com, uint8 seg, Switch value) 
{
    uint8 c, s;
    c = com - 1;
    s = seg - 5;
    
    if (value)                                                                                                                                             
        lcd_ram_buffer[ram_offset[c][s] / 8] |= (1 << (ram_offset[c][s] % 8));    
    else                                                                                                                                                      
        lcd_ram_buffer[ram_offset[c][s] / 8] &= ~(1 << (ram_offset[c][s] % 8));
 }
 