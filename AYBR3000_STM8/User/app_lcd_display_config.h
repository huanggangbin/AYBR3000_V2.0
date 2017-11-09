#ifndef _APP_LCD_DISPLAY_CONFIG_H_
#define _APP_LCD_DISPLAY_CONFIG_H_
#include "types.h"
#include "LCD_driver.h"

typedef enum
{
    INDEX_ICON_QIANG,
    INDEX_ICON_RUO,
    INDEX_ICON_ZI_DONG,
    INDEX_ICON_LINE,
    INDEX_ICON_WEN_DU_SHE_DING,
    INDEX_ICON_DING_SHI_100,
    INDEX_ICON_DING_SHI_SHI_JIAN,
    INDEX_ICON_FENG_NUAN,
    INDEX_ICON_HUAN_QI,
    INDEX_ICON_XIN_FENG_QU_NUAN,
    INDEX_ICON_XIN_FENG,
    INDEX_ICON_BAI_DONG,
    INDEX_ICON_ZN_GAN_ZAO,
    INDEX_ICON_ZN_JING_HUA,
    INDEX_ICON_ZN_MU_YU,
    INDEX_ICON_COLON,
    INDEX_ICON_NUMBER,
}App_lcd_index_icon;

typedef enum
{
    INDEX_DIGIT_TUBE_HOUR_TENS,
    INDEX_DIGIT_TUBE_HOUR_ONES,
    INDEX_DIGIT_TUBE_MINUTE_TENS,
    INDEX_DIGIT_TUBE_MINUTE_ONES,
    INDEX_DIGIT_TUBE_WENDU_TENS,
    INDEX_DIGIT_TUBE_WENDU_ONES,
    INDEX_DIGIT_TUBE_DINGSHI_TENS,
    INDEX_DIGIT_TUBE_DiNGSHI_ONES,
    INDEX_DIGIT_TUBE_NUMBER,
}App_lcd_index_digit_tube;

typedef void (* App_lcd_icon_ctrl_func)(Switch s);
typedef void (* App_lcd_Tube_ctrl_func)(Tube_value v);

extern App_lcd_icon_ctrl_func icon_ctrl_func[INDEX_ICON_NUMBER];
extern App_lcd_Tube_ctrl_func digit_tube_ctrl_func[INDEX_DIGIT_TUBE_NUMBER];

#endif

