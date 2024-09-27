#include "ti_msp_dl_config.h"

#ifndef __LCD_H_
#define __LCD_H_

#ifndef u8
#define u8 uint8_t
#endif
#ifndef u16
#define u16 uint16_t
#endif

#define RED  	0xf800
#define GREEN	0x07e0
#define BLUE 	0x001f
#define WHITE	0xffff
#define BLACK	0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   	//灰色0 3165 00110 001011 00101
#define GRAY1   0x8410      	//灰色1      00000 000000 00000
#define GRAY2   0x4208      	//灰色2  1111111111011111

#define X_MAX_PIXEL	        128
#define Y_MAX_PIXEL	        128

#define LCD_DC_CLR      DL_GPIO_clearPins(GPIO_TFT_PORT, GPIO_TFT_DC_PIN)
#define LCD_DC_SET      DL_GPIO_setPins(GPIO_TFT_PORT, GPIO_TFT_DC_PIN)

#define LCD_RST_CLR     DL_GPIO_clearPins(GPIO_TFT_PORT, GPIO_TFT_RES_PIN)
#define LCD_RST_SET     DL_GPIO_setPins(GPIO_TFT_PORT, GPIO_TFT_RES_PIN)

#define LCD_CS_CLR     DL_GPIO_clearPins(GPIO_TFT_PORT, GPIO_TFT_CS_PIN)
#define LCD_CS_SET     DL_GPIO_setPins(GPIO_TFT_PORT, GPIO_TFT_CS_PIN)

void SPI_WriteData(u8 Data);
void Lcd_WriteIndex(u8 Index);
void Lcd_WriteData(u8 Data);
void LCD_WriteData_16Bit(u16 Data);
void Lcd_WriteReg(u8 Index,u8 Data);
void Lcd_Reset(void);
void Lcd_Init(void);
void Lcd_SetRegion(u16 x_start,u16 y_start,u16 x_end,u16 y_end);
void Lcd_SetXY(u16 x,u16 y);
void Gui_DrawPoint(u16 x,u16 y,u16 Data);
void Lcd_Clear(u16 Color);

u16 LCD_BGR2RGB(u16 c);
void Gui_Circle(u16 X,u16 Y,u16 R,u16 fc); 
void Gui_DrawLine(u16 x0, u16 y0,u16 x1, u16 y1,u16 Color);  
void Gui_box(u16 x, u16 y, u16 w, u16 h,u16 bc);
void Gui_box2(u16 x,u16 y,u16 w,u16 h, u8 mode);
void DisplayButtonDown(u16 x1,u16 y1,u16 x2,u16 y2);
void DisplayButtonUp(u16 x1,u16 y1,u16 x2,u16 y2);
void Gui_DrawFont_GBK16(u16 x, u16 y, u16 fc, u16 bc, u8 *s);
void Gui_DrawFont_GBK24(u16 x, u16 y, u16 fc, u16 bc, u8 *s);
void Gui_DrawFont_Num32(u16 x, u16 y, u16 fc, u16 bc, u16 num);


#endif