#include "Lcd.h"
#include "Font.h"
#include "my_fun.h"

void  SPI_WriteData(u8 Data)
{
    LCD_CS_CLR;    
    DL_SPI_transmitData8(SPI_0_INST, Data);
    while(DL_SPI_isBusy(SPI_0_INST));
    LCD_CS_SET;
}

//向液晶屏写一个8位指令
void Lcd_WriteIndex(u8 Index)
{
  //SPI 写命令时序开始
    LCD_CS_CLR;
    LCD_DC_CLR;
    SPI_WriteData(Index);
    LCD_DC_SET;
    LCD_CS_SET;
}

//向液晶屏写一个8位数据
void Lcd_WriteData(u8 Data)
{
   LCD_CS_CLR;
   SPI_WriteData(Data);
   LCD_CS_SET; 
}
//向液晶屏写一个16位数据
void LCD_WriteData_16Bit(u16 Data)
{
   LCD_CS_CLR;
	 SPI_WriteData(Data>>8); 	//写入高8位数据
	 SPI_WriteData(Data); 			//写入低8位数据
   LCD_CS_SET; 
}

void Lcd_WriteReg(u8 Index,u8 Data)
{
  Lcd_WriteIndex(Index);
  Lcd_WriteData(Data);
}

void Lcd_Reset(void)
{
  LCD_RST_CLR;
  delay_ms(100);
  LCD_RST_SET;
  delay_ms(50);
}

//LCD Init For 1.44Inch LCD Panel with ST7735R.
void Lcd_Init(void)
{	
  Lcd_Reset(); //Reset before LCD Init.
  
  //LCD Init For 1.44Inch LCD Panel with ST7735R.
  Lcd_WriteIndex(0x11);//Sleep exit 
  delay_ms (120);
  
  //ST7735R Frame Rate
  Lcd_WriteIndex(0xB1); 
  Lcd_WriteData(0x01); 
  Lcd_WriteData(0x2C); 
  Lcd_WriteData(0x2D); 
  
  Lcd_WriteIndex(0xB2); 
  Lcd_WriteData(0x01); 
  Lcd_WriteData(0x2C); 
  Lcd_WriteData(0x2D); 
  
  Lcd_WriteIndex(0xB3); 
  Lcd_WriteData(0x01); 
  Lcd_WriteData(0x2C); 
  Lcd_WriteData(0x2D); 
  Lcd_WriteData(0x01); 
  Lcd_WriteData(0x2C); 
  Lcd_WriteData(0x2D); 
  
  Lcd_WriteIndex(0xB4); //Column inversion 
  Lcd_WriteData(0x07); 
  
  //ST7735R Power Sequence
  Lcd_WriteIndex(0xC0); 
  Lcd_WriteData(0xA2); 
  Lcd_WriteData(0x02); 
  Lcd_WriteData(0x84); 
  Lcd_WriteIndex(0xC1); 
  Lcd_WriteData(0xC5); 
  
  Lcd_WriteIndex(0xC2); 
  Lcd_WriteData(0x0A); 
  Lcd_WriteData(0x00); 
  
  Lcd_WriteIndex(0xC3); 
  Lcd_WriteData(0x8A); 
  Lcd_WriteData(0x2A); 
  Lcd_WriteIndex(0xC4); 
  Lcd_WriteData(0x8A); 
  Lcd_WriteData(0xEE); 
  
  Lcd_WriteIndex(0xC5); //VCOM 
  Lcd_WriteData(0x0E); 
  
  Lcd_WriteIndex(0x36); //MX, MY, RGB mode 
  Lcd_WriteData(0xC8); 
  
  //ST7735R Gamma Sequence
  Lcd_WriteIndex(0xe0); 
  Lcd_WriteData(0x0f); 
  Lcd_WriteData(0x1a); 
  Lcd_WriteData(0x0f); 
  Lcd_WriteData(0x18); 
  Lcd_WriteData(0x2f); 
  Lcd_WriteData(0x28); 
  Lcd_WriteData(0x20); 
  Lcd_WriteData(0x22); 
  Lcd_WriteData(0x1f); 
  Lcd_WriteData(0x1b); 
  Lcd_WriteData(0x23); 
  Lcd_WriteData(0x37); 
  Lcd_WriteData(0x00); 	
  Lcd_WriteData(0x07); 
  Lcd_WriteData(0x02); 
  Lcd_WriteData(0x10); 
  
  Lcd_WriteIndex(0xe1); 
  Lcd_WriteData(0x0f); 
  Lcd_WriteData(0x1b); 
  Lcd_WriteData(0x0f); 
  Lcd_WriteData(0x17); 
  Lcd_WriteData(0x33); 
  Lcd_WriteData(0x2c); 
  Lcd_WriteData(0x29); 
  Lcd_WriteData(0x2e); 
  Lcd_WriteData(0x30); 
  Lcd_WriteData(0x30); 
  Lcd_WriteData(0x39); 
  Lcd_WriteData(0x3f); 
  Lcd_WriteData(0x00); 
  Lcd_WriteData(0x07); 
  Lcd_WriteData(0x03); 
  Lcd_WriteData(0x10);  
  
  Lcd_WriteIndex(0x2a);
  Lcd_WriteData(0x00);
  Lcd_WriteData(0x00);
  Lcd_WriteData(0x00);
  Lcd_WriteData(0x7f);
  
  Lcd_WriteIndex(0x2b);
  Lcd_WriteData(0x00);
  Lcd_WriteData(0x00);
  Lcd_WriteData(0x00);
  Lcd_WriteData(0x9f);
  
  Lcd_WriteIndex(0xF0); //Enable test command  
  Lcd_WriteData(0x01); 
  Lcd_WriteIndex(0xF6); //Disable ram power save mode 
  Lcd_WriteData(0x00); 
  
  Lcd_WriteIndex(0x3A); //65k mode 
  Lcd_WriteData(0x05); 
  
  
  Lcd_WriteIndex(0x29);//Display on	 
}


/*************************************************
函数名：LCD_Set_Region
功能：设置lcd显示区域，在此区域写点数据自动换行
入口参数：xy起点和终点
返回值：无
*************************************************/
void Lcd_SetRegion(u16 x_start,u16 y_start,u16 x_end,u16 y_end)
{		
  Lcd_WriteIndex(0x2a);
  Lcd_WriteData(0x00);
  Lcd_WriteData(x_start+2);
  Lcd_WriteData(0x00);
  Lcd_WriteData(x_end+2);
  
  Lcd_WriteIndex(0x2b);
  Lcd_WriteData(0x00);
  Lcd_WriteData(y_start+3);
  Lcd_WriteData(0x00);
  Lcd_WriteData(y_end+3);
  
  Lcd_WriteIndex(0x2c);
  
}

/*************************************************
函数名：LCD_Set_XY
功能：设置lcd显示起始点
入口参数：xy坐标
返回值：无
*************************************************/
void Lcd_SetXY(u16 x,u16 y)
{
  Lcd_SetRegion(x,y,x,y);
}


/*************************************************
函数名：LCD_DrawPoint
功能：画一个点
入口参数：无
返回值：无
*************************************************/
void Gui_DrawPoint(u16 x,u16 y,u16 Data)
{
  Lcd_SetRegion(x,y,x+1,y+1);
  LCD_WriteData_16Bit(Data);
  
}    

/*************************************************
函数名：Lcd_Clear
功能：全屏清屏函数
入口参数：填充颜色COLOR
返回值：无
*************************************************/
void Lcd_Clear(u16 Color)               
{	
  unsigned int i,m;
  Lcd_SetRegion(0,0,X_MAX_PIXEL-1,Y_MAX_PIXEL-1);
  Lcd_WriteIndex(0x2C);
  for(i=0;i<X_MAX_PIXEL;i++)
    for(m=0;m<Y_MAX_PIXEL;m++)
    {	
      LCD_WriteData_16Bit(Color);
    }   
}


//从ILI93xx读出的数据为GBR格式，而我们写入的时候为RGB格式。
//通过该函数转换
//c:GBR格式的颜色值
//返回值：RGB格式的颜色值
u16 LCD_BGR2RGB(u16 c)
{
  u16  r,g,b,rgb;   
  b=(c>>0)&0x1f;
  g=(c>>5)&0x3f;
  r=(c>>11)&0x1f;	 
  rgb=(b<<11)+(g<<5)+(r<<0);		 
  return(rgb);

}
void Gui_Circle(u16 X,u16 Y,u16 R,u16 fc) 
{//Bresenham算法 
    unsigned short  a,b; 
    int c; 
    a=0; 
    b=R; 
    c=3-2*R; 
    while (a<b) 
    { 
        Gui_DrawPoint(X+a,Y+b,fc);     //        7 
        Gui_DrawPoint(X-a,Y+b,fc);     //        6 
        Gui_DrawPoint(X+a,Y-b,fc);     //        2 
        Gui_DrawPoint(X-a,Y-b,fc);     //        3 
        Gui_DrawPoint(X+b,Y+a,fc);     //        8 
        Gui_DrawPoint(X-b,Y+a,fc);     //        5 
        Gui_DrawPoint(X+b,Y-a,fc);     //        1 
        Gui_DrawPoint(X-b,Y-a,fc);     //        4 

        if(c<0) c=c+4*a+6; 
        else 
        { 
            c=c+4*(a-b)+10; 
            b-=1; 
        } 
       a+=1; 
    } 
    if (a==b) 
    { 
        Gui_DrawPoint(X+a,Y+b,fc); 
        Gui_DrawPoint(X+a,Y+b,fc); 
        Gui_DrawPoint(X+a,Y-b,fc); 
        Gui_DrawPoint(X-a,Y-b,fc); 
        Gui_DrawPoint(X+b,Y+a,fc); 
        Gui_DrawPoint(X-b,Y+a,fc); 
        Gui_DrawPoint(X+b,Y-a,fc); 
        Gui_DrawPoint(X-b,Y-a,fc); 
    } 
	
} 
//画线函数，使用Bresenham 画线算法
void Gui_DrawLine(u16 x0, u16 y0,u16 x1, u16 y1,u16 Color)   
{
int dx,             // difference in x's
    dy,             // difference in y's
    dx2,            // dx,dy * 2
    dy2, 
    x_inc,          // amount in pixel space to move during drawing
    y_inc,          // amount in pixel space to move during drawing
    error,          // the discriminant i.e. error i.e. decision variable
    index;          // used for looping	


	Lcd_SetXY(x0,y0);
	dx = x1-x0;//计算x距离
	dy = y1-y0;//计算y距离

	if (dx>=0)
	{
		x_inc = 1;
	}
	else
	{
		x_inc = -1;
		dx    = -dx;  
	} 
	
	if (dy>=0)
	{
		y_inc = 1;
	} 
	else
	{
		y_inc = -1;
		dy    = -dy; 
	} 

	dx2 = dx << 1;
	dy2 = dy << 1;

	if (dx > dy)//x距离大于y距离，那么每个x轴上只有一个点，每个y轴上有若干个点
	{//且线的点数等于x距离，以x轴递增画点
		// initialize error term
		error = dy2 - dx; 

		// draw the line
		for (index=0; index <= dx; index++)//要画的点数不会超过x距离
		{
			//画点
			Gui_DrawPoint(x0,y0,Color);
			
			// test if error has overflowed
			if (error >= 0) //是否需要增加y坐标值
			{
				error-=dx2;

				// move to next line
				y0+=y_inc;//增加y坐标值
			} // end if error overflowed

			// adjust the error term
			error+=dy2;

			// move to the next pixel
			x0+=x_inc;//x坐标值每次画点后都递增1
		} // end for
	} // end if |slope| <= 1
	else//y轴大于x轴，则每个y轴上只有一个点，x轴若干个点
	{//以y轴为递增画点
		// initialize error term
		error = dx2 - dy; 

		// draw the line
		for (index=0; index <= dy; index++)
		{
			// set the pixel
			Gui_DrawPoint(x0,y0,Color);

			// test if error overflowed
			if (error >= 0)
			{
				error-=dy2;

				// move to next line
				x0+=x_inc;
			} // end if error overflowed

			// adjust the error term
			error+=dx2;

			// move to the next pixel
			y0+=y_inc;
		} // end for
	} // end else |slope| > 1
}



void Gui_box(u16 x, u16 y, u16 w, u16 h,u16 bc)
{
//	Gui_DrawLine(x,y,x+w,y,0xEF7D);
//	Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0x2965);
//	Gui_DrawLine(x,y+h,x+w,y+h,0x2965);
//	Gui_DrawLine(x,y,x,y+h,0xEF7D);
	Gui_DrawLine(x,y,x+w,y,bc);
	Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,bc);
	Gui_DrawLine(x,y+h,x+w,y+h,bc);
	Gui_DrawLine(x,y,x,y+h,bc);
  
    Gui_DrawLine(x+1,y+1,x+1+w-2,y+1+h-2,bc);
}
void Gui_box2(u16 x,u16 y,u16 w,u16 h, u8 mode)
{
	if (mode==0)	{
		Gui_DrawLine(x,y,x+w,y,0xEF7D);
		Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0x2965);
		Gui_DrawLine(x,y+h,x+w,y+h,0x2965);
		Gui_DrawLine(x,y,x,y+h,0xEF7D);
		}
	if (mode==1)	{
		Gui_DrawLine(x,y,x+w,y,0x2965);
		Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0xEF7D);
		Gui_DrawLine(x,y+h,x+w,y+h,0xEF7D);
		Gui_DrawLine(x,y,x,y+h,0x2965);
	}
	if (mode==2)	{
		Gui_DrawLine(x,y,x+w,y,0xffff);
		Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0xffff);
		Gui_DrawLine(x,y+h,x+w,y+h,0xffff);
		Gui_DrawLine(x,y,x,y+h,0xffff);
	}
}


/**************************************************************************************
功能描述: 在屏幕显示一凸起的按钮框
输    入: u16 x1,y1,x2,y2 按钮框左上角和右下角坐标
输    出: 无
**************************************************************************************/
void DisplayButtonDown(u16 x1,u16 y1,u16 x2,u16 y2)
{
	Gui_DrawLine(x1,  y1,  x2,y1, GRAY2);  //H
	Gui_DrawLine(x1+1,y1+1,x2,y1+1, GRAY1);  //H
	Gui_DrawLine(x1,  y1,  x1,y2, GRAY2);  //V
	Gui_DrawLine(x1+1,y1+1,x1+1,y2, GRAY1);  //V
	Gui_DrawLine(x1,  y2,  x2,y2, WHITE);  //H
	Gui_DrawLine(x2,  y1,  x2,y2, WHITE);  //V
}

/**************************************************************************************
功能描述: 在屏幕显示一凹下的按钮框
输    入: u16 x1,y1,x2,y2 按钮框左上角和右下角坐标
输    出: 无
**************************************************************************************/
void DisplayButtonUp(u16 x1,u16 y1,u16 x2,u16 y2)
{
	Gui_DrawLine(x1,  y1,  x2,y1, WHITE); //H
	Gui_DrawLine(x1,  y1,  x1,y2, WHITE); //V
	
	Gui_DrawLine(x1+1,y2-1,x2,y2-1, GRAY1);  //H
	Gui_DrawLine(x1,  y2,  x2,y2, GRAY2);  //H
	Gui_DrawLine(x2-1,y1+1,x2-1,y2, GRAY1);  //V
    Gui_DrawLine(x2  ,y1  ,x2,y2, GRAY2); //V
}


void Gui_DrawFont_GBK16(u16 x, u16 y, u16 fc, u16 bc, u8 *s)
{
	unsigned char i,j;
	unsigned short k,x0;
	x0=x;

	while(*s) 
	{	
		if((*s) < 128) 
		{
			k=*s;
			if (k==13) 
			{
				x=x0;
				y+=16;
			}
			else 
			{
				if (k>32) k-=32; else k=0;
	
			    for(i=0;i<16;i++)
				for(j=0;j<8;j++) 
					{
				    	if(asc16[k*16+i]&(0x80>>j))	Gui_DrawPoint(x+j,y+i,fc);
						else 
						{
							if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
						}
					}
				x+=8;
			}
			s++;
		}
			
		else 
		{
		

			for (k=0;k<hz16_num;k++) 
			{
			  if ((hz16[k].Index[0]==*(s))&&(hz16[k].Index[1]==*(s+1)))
			  { 
				    for(i=0;i<16;i++)
				    {
						for(j=0;j<8;j++) 
							{
						    	if(hz16[k].Msk[i*2]&(0x80>>j))	Gui_DrawPoint(x+j,y+i,fc);
								else {
									if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
								}
							}
						for(j=0;j<8;j++) 
							{
						    	if(hz16[k].Msk[i*2+1]&(0x80>>j))	Gui_DrawPoint(x+j+8,y+i,fc);
								else 
								{
									if (fc!=bc) Gui_DrawPoint(x+j+8,y+i,bc);
								}
							}
				    }
				}
			  }
			s+=2;x+=16;
		} 
		
	}
}

void Gui_DrawFont_GBK24(u16 x, u16 y, u16 fc, u16 bc, u8 *s)
{
	unsigned char i,j;
	unsigned short k;

	while(*s) 
	{
		if( *s < 0x80 ) 
		{
			k=*s;
			if (k>32) k-=32; else k=0;

		    for(i=0;i<16;i++)
			for(j=0;j<8;j++) 
				{
			    	if(asc16[k*16+i]&(0x80>>j))	
					Gui_DrawPoint(x+j,y+i,fc);
					else 
					{
						if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
					}
				}
			s++;x+=8;
		}
		else 
		{

			for (k=0;k<hz24_num;k++) 
			{
			  if ((hz24[k].Index[0]==*(s))&&(hz24[k].Index[1]==*(s+1)))
			  { 
				    for(i=0;i<24;i++)
				    {
						for(j=0;j<8;j++) 
							{
						    	if(hz24[k].Msk[i*3]&(0x80>>j))
								Gui_DrawPoint(x+j,y+i,fc);
								else 
								{
									if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
								}
							}
						for(j=0;j<8;j++) 
							{
						    	if(hz24[k].Msk[i*3+1]&(0x80>>j))	Gui_DrawPoint(x+j+8,y+i,fc);
								else {
									if (fc!=bc) Gui_DrawPoint(x+j+8,y+i,bc);
								}
							}
						for(j=0;j<8;j++) 
							{
						    	if(hz24[k].Msk[i*3+2]&(0x80>>j))	
								Gui_DrawPoint(x+j+16,y+i,fc);
								else 
								{
									if (fc!=bc) Gui_DrawPoint(x+j+16,y+i,bc);
								}
							}
				    }
			  }
			}
			s+=2;x+=24;
		}
	}
}
void Gui_DrawFont_Num32(u16 x, u16 y, u16 fc, u16 bc, u16 num)
{
	unsigned char i,j,k,c;
	//lcd_text_any(x+94+i*42,y+34,32,32,0x7E8,0x0,sz32,knum[i]);
//	w=w/8;

    for(i=0;i<32;i++)
	{
		for(j=0;j<4;j++) 
		{
			c=*(sz32+num*32*4+i*4+j);
			for (k=0;k<8;k++)	
			{
	
		    	if(c&(0x80>>k))	Gui_DrawPoint(x+j*8+k,y+i,fc);
				else {
					if (fc!=bc) Gui_DrawPoint(x+j*8+k,y+i,bc);
				}
			}
		}
	}
}

