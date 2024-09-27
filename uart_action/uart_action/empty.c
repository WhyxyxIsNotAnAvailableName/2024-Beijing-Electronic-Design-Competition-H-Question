/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti_msp_dl_config.h"
#include "math.h"
#include "my_fun.h"
#include "Lcd.h"
#include "stdio.h"
#define PI 3.1415926

char chL[10];
char chR[10];
char yaw[10];
uint8_t flag_start = 0;
uint8_t task = 0;
uint8_t step = 0;
uint8_t jishu = 0;
uint8_t sheng_guang_flag = 0;
uint8_t jiu_imu = 0;
uint8_t single = 1;
uint16_t speed_ = 1450;
uint16_t speed_4 = 2000;
uint16_t speed_4_wd = 1500;
uint16_t cha_su = 150;
float zhuan_jiao = -142.5;
extern uint16_t loadvalue_L;
extern uint16_t loadvalue_R;
extern uint32_t freq_new_L;
extern uint32_t freq_new_R;
extern car_ car;


extern  uint16_t get_adc1;
extern  uint16_t get_adc2;
void set_zero();

int main(void)
{
    SYSCFG_DL_init();
    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
        Lcd_Init();
    Lcd_Clear(RED);
    //左轮灰度
    while(DL_GPIO_readPins(next_PORT,next_PIN_13_PIN)){
    DL_ADC12_enableConversions(ADC12_1_INST);
    DL_ADC12_startConversion(ADC12_1_INST);
    delay_us(1);
    get_adc1 = DL_ADC12_getMemResult(ADC12_1_INST, DL_ADC12_MEM_IDX_0);//DL_ADC12_MEM_IDX_0是左轮那边的传感器
    sprintf(chL, "%0.6d", get_adc1);
    Gui_DrawFont_GBK16(20, 40, RED, GRAY1, chL);
    sprintf(chR, "%0.6d", yz_L);
    Gui_DrawFont_GBK16(20, 60, RED, GRAY1, chR);
    if(!DL_GPIO_readPins(add_PORT,add_PIN_11_PIN)){
        yz_L += 200;
        delay_cycles(20000000);
    }
    if(!DL_GPIO_readPins(sub_PORT,sub_PIN_12_PIN)){
        yz_L -= 200;
        delay_cycles(20000000);
    }
    }
    delay_cycles(40000000);
    Lcd_Clear(RED);
    
    //右轮灰度
    while(DL_GPIO_readPins(next_PORT,next_PIN_13_PIN)){
    DL_ADC12_enableConversions(ADC12_1_INST);
    DL_ADC12_startConversion(ADC12_1_INST);
    delay_us(1);
    //DL_ADC12_MEM_IDX_0是左轮那边的传感器
    get_adc2 = DL_ADC12_getMemResult(ADC12_1_INST, DL_ADC12_MEM_IDX_1);
    sprintf(chL, "%0.6d", get_adc2);
    Gui_DrawFont_GBK16(20, 60, RED, GRAY1, chL);
    sprintf(chR, "%0.6d", yz_R);
    Gui_DrawFont_GBK16(20, 80, RED, GRAY1, chR);
    if(!DL_GPIO_readPins(add_PORT,add_PIN_11_PIN)){
        yz_R += 200;
        delay_cycles(20000000);
    }
    if(!DL_GPIO_readPins(sub_PORT,sub_PIN_12_PIN)){
        yz_R -= 200;
        delay_cycles(20000000);
    }
    }
    delay_cycles(40000000);
    Lcd_Clear(RED);
    
    //转角速度（容易卡死的那个）
    while(DL_GPIO_readPins(next_PORT,next_PIN_13_PIN)){
    sprintf(chL, "%0.6d", speed_);
    Gui_DrawFont_GBK16(20, 60, RED, GRAY1, chL);
    if(!DL_GPIO_readPins(add_PORT,add_PIN_11_PIN)){
        speed_ += 50;
        delay_cycles(20000000);
    }
    if(!DL_GPIO_readPins(sub_PORT,sub_PIN_12_PIN)){
        speed_ -= 50;
        delay_cycles(20000000);
    }
    }
    delay_cycles(40000000);
    Lcd_Clear(RED);
    
    //4的直道速度
    while(DL_GPIO_readPins(next_PORT,next_PIN_13_PIN)){
    sprintf(chL, "%0.6d", speed_4);
    Gui_DrawFont_GBK16(20, 60, RED, GRAY1, chL);
    if(!DL_GPIO_readPins(add_PORT,add_PIN_11_PIN)){
        speed_4 += 50;
        delay_cycles(20000000);
    }
    if(!DL_GPIO_readPins(sub_PORT,sub_PIN_12_PIN)){
        speed_4 -= 50;
        delay_cycles(20000000);
    }
    }
    delay_cycles(40000000);
    Lcd_Clear(RED);
    
    //4的弯道主速度
    while(DL_GPIO_readPins(next_PORT,next_PIN_13_PIN)){
    sprintf(chL, "%0.6d", speed_4_wd);
    Gui_DrawFont_GBK16(20, 60, RED, GRAY1, chL);
    if(!DL_GPIO_readPins(add_PORT,add_PIN_11_PIN)){
        speed_4_wd += 50;
        delay_cycles(20000000);
    }
    if(!DL_GPIO_readPins(sub_PORT,sub_PIN_12_PIN)){
        speed_4_wd -= 50;
        delay_cycles(20000000);
    }
    }
    delay_cycles(40000000);
    Lcd_Clear(RED);
    
    //4的弯道差速
    while(DL_GPIO_readPins(next_PORT,next_PIN_13_PIN)){
    sprintf(chL, "%0.6d", cha_su);
    Gui_DrawFont_GBK16(20, 60, RED, GRAY1, chL);
    if(!DL_GPIO_readPins(add_PORT,add_PIN_11_PIN)){
        cha_su += 50;
        delay_cycles(20000000);
    }
    if(!DL_GPIO_readPins(sub_PORT,sub_PIN_12_PIN)){
        cha_su -= 50;
        delay_cycles(20000000);
    }
    }
    delay_cycles(40000000);
    Lcd_Clear(RED);
    
    //神秘转角
    while(DL_GPIO_readPins(next_PORT,next_PIN_13_PIN)){
    sprintf(chL, "%0.6f", zhuan_jiao);
    Gui_DrawFont_GBK16(20, 60, RED, GRAY1, chL);
    if(!DL_GPIO_readPins(add_PORT,add_PIN_11_PIN)){
        zhuan_jiao += 0.5;
        delay_cycles(20000000);
    }
    if(!DL_GPIO_readPins(sub_PORT,sub_PIN_12_PIN)){
        zhuan_jiao -= 0.5;
        delay_cycles(20000000);
    }
    }
    delay_cycles(40000000);
    Lcd_Clear(RED);
    
    while(flag_start == 0){
      delay_cycles(10);
      }
    DL_TimerA_startCounter(PWM_0_INST);
    DL_TimerA_startCounter(PWM_1_INST);
    set_zero();

    
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);//100ms定时器
    NVIC_EnableIRQ(COMPARE_0_INST_INT_IRQN);
    NVIC_EnableIRQ(COMPARE_1_INST_INT_IRQN);
    
    DL_TimerG_startCounter(TIMER_0_INST);
    DL_TimerG_startCounter(COMPARE_0_INST);
    DL_TimerG_startCounter(COMPARE_1_INST);
    loadvalue_L = DL_TimerG_getLoadValue(COMPARE_0_INST);
    loadvalue_R = DL_TimerG_getLoadValue(COMPARE_1_INST);

    /*判断task*/
    while(task == 0){
        task = Adc_Get_Once();
    }
    delay_cycles(40000000);
    LED_On(1);    sheng_guang_flag = 1;
    jishu++;

//    while(1){    
//    DL_ADC12_enableConversions(ADC12_1_INST);
//    DL_ADC12_startConversion(ADC12_1_INST);
//    delay_us(1);
//    get_adc1 = DL_ADC12_getMemResult(ADC12_1_INST, DL_ADC12_MEM_IDX_0);
//    get_adc2 = DL_ADC12_getMemResult(ADC12_1_INST, DL_ADC12_MEM_IDX_1);
//    }
    
    
    while (1) {        
        
//      sprintf(chL, "%0.6d", step);
//      Gui_DrawFont_GBK16(20, 40, RED, GRAY1, chL);
      
      
//        sprintf(chL, "%0.6d", freq_new_L);
//        sprintf(chR, "%0.6d", freq_new_R);
//        
//        sprintf(chL, "%0.6d", dutyL);
//        sprintf(chR, "%0.6d", dutyR);
//        
//        sprintf(yaw, "%0.6f", car.yaw);
//        
//        Gui_DrawFont_GBK16(20, 40, RED, GRAY1, chL);
//        Gui_DrawFont_GBK16(20, 60, RED, GRAY1, chR);
//        Gui_DrawFont_GBK16(20, 80, RED, GRAY1, yaw);
        
              get_hong_wai1();
        switch(task){
            case task1:{
              cal_duty_imu_bmq(0);
                  if(/*cm_20 * 5 < freq_new_L && cm_20 * 5 < freq_new_R && */is_any_black()){
                         set_zero();
                          LED_On(1);    sheng_guang_flag = 1;
                          while(1){delay_cycles(10);}
                    }
              break;
            }
            case task2:{
              switch(step){
                  case 0:{
                      cal_duty_imu_bmq(0);
                   // cal_duty_bmq();
                      if(is_any_black()){
                        LED_On(1);    sheng_guang_flag = 1;
                        step = 1;set_zero();
                     normal_speed_L = 2150 - 400 - 100;
                    normal_speed_R = 1850 - 400 - 100;
                      }
                        break;
                  }
                  case 1:{
                    cal_duty_hei_xian();
                    if(((car.yaw > 90 && car.yaw < 180) || (car.yaw < -90 && car.yaw > -180)) && is_any_black() == 0){
                      set_zero();
                      while(!((car.yaw > -180 && car.yaw < -178.5) || (car.yaw < 180 && car.yaw >178.5))){
                            DL_TimerA_setCaptureCompareValue(PWM_0_INST,speed_,DL_TIMER_CC_0_INDEX); 
                            DL_TimerA_setCaptureCompareValue(PWM_1_INST,0,DL_TIMER_CC_0_INDEX);
                      }
                      set_zero();
                    normal_speed_L = 2000;
                    normal_speed_R = 2000;
                    dutyL = 2000;
                    dutyR = 2000;
                        step = 2;
                        LED_On(1);    sheng_guang_flag = 1;
                        set_zero();
                    }
                    break;
                  }
                  case 2:{
                    cal_duty_imu_bmq(-180);
                    if(is_any_black()){
                      LED_On(1);    sheng_guang_flag = 1;
                        step = 3;
                    normal_speed_L = 2150 - 400 - 100;
                    normal_speed_R = 1850 - 400 - 100;
                    }
                    break;
                  }
                   case 3:{
                      cal_duty_hei_xian();
                      if( ((car.yaw < 10 && car.yaw > 0) || (car.yaw > -10 && car.yaw < 0)) && is_any_black() == 0){
                          LED_On(1);    sheng_guang_flag = 1;
                         set_zero();
                          while(1){delay_cycles(10);}
                      }
                      break;
                    }
                break;
              }
              break;
            }
            case task3:{
              switch(step){
              case 0:{
                while(single && (!(car.yaw > -40.66 && car.yaw < -36.66))){
                    DL_TimerA_setCaptureCompareValue(PWM_0_INST,speed_,DL_TIMER_CC_0_INDEX); 
                    DL_TimerA_setCaptureCompareValue(PWM_1_INST,0,DL_TIMER_CC_0_INDEX);
                }
                single = 0;
                normal_speed_L = 2000;
                normal_speed_R = 2000;
                cal_duty_imu_bmq(-38.66);
                if(is_any_black()){
                  LED_On(1);    sheng_guang_flag = 1;
                  set_zero();
                  while(!(car.yaw > 18 && car.yaw < 22)){
                    DL_TimerA_setCaptureCompareValue(PWM_0_INST,0,DL_TIMER_CC_0_INDEX); 
                    DL_TimerA_setCaptureCompareValue(PWM_1_INST,speed_,DL_TIMER_CC_0_INDEX);
                  }
                  set_zero();
                  step = 1;
                  single = 1;
                  dutyL = 0;
                  dutyR = 0;
                  normal_speed_L = 1850 - 400 - 100;
                  normal_speed_R = 2150 - 400 - 100;
                }
                break;
              }
              case 1:{
                cal_duty_hei_xian();
                if(((car.yaw > 90 && car.yaw < 180) || (car.yaw < -90 && car.yaw > -180)) && is_any_black() == 0){
                 LED_On(1);    sheng_guang_flag = 1;
                  set_zero();
                  step = 2;  
                  normal_speed_L = 0;
                  normal_speed_R = 0;
                  dutyL = 0;
                  dutyR = 0;
                }
                break;
              }
              case 2:{
                while(single && (!(car.yaw > -145 && car.yaw < -141))){
                    DL_TimerA_setCaptureCompareValue(PWM_0_INST,0,DL_TIMER_CC_0_INDEX); 
                    DL_TimerA_setCaptureCompareValue(PWM_1_INST,speed_,DL_TIMER_CC_0_INDEX);
                }
                single = 0;
                normal_speed_L = 2000;
                normal_speed_R = 2000;
                cal_duty_imu_bmq(-143.34);
                if(is_any_black()){
                 LED_On(1);    sheng_guang_flag = 1;
                  set_zero();
                  while(!(car.yaw > 158 && car.yaw < 162)){
                    DL_TimerA_setCaptureCompareValue(PWM_0_INST,speed_,DL_TIMER_CC_0_INDEX); 
                    DL_TimerA_setCaptureCompareValue(PWM_1_INST,0,DL_TIMER_CC_0_INDEX);
                  }
                  set_zero();
                  dutyL = 0;
                  dutyR = 0;
                  normal_speed_L = 2150 - 400 - 100;
                  normal_speed_R = 1850 - 400 - 100;
                  set_zero();
                  step = 3;  
                }
                break;
              }
              case 3:{
                cal_duty_hei_xian();
                if(is_any_black() == 0 && ((car.yaw < 90 && car.yaw > 0) || (car.yaw > -90 && car.yaw < 0))){
                    LED_On(1);    sheng_guang_flag = 1;
                  set_zero();
                  while(1){delay_cycles(10);};
                }
                break;
              }
              }
            break;
            }
            case task4:{
                if(jishu >= 17){
                  while (1){
                    set_zero();
                  delay_cycles(10);}
                }
              switch(step){
              case 0:{
                while(single && (!(car.yaw > -40.66 && car.yaw < -36.66))){
                    DL_TimerA_setCaptureCompareValue(PWM_0_INST,speed_,DL_TIMER_CC_0_INDEX); 
                    DL_TimerA_setCaptureCompareValue(PWM_1_INST,0,DL_TIMER_CC_0_INDEX);
                }
                single = 0;
                normal_speed_L = speed_4;
                normal_speed_R = speed_4;
                cal_duty_imu_bmq(-38.66);
                if(is_any_black()){
                  LED_On(1);    sheng_guang_flag = 1; jishu++;
                  set_zero();
                  while(!(car.yaw > 18 && car.yaw < 22)){
                    DL_TimerA_setCaptureCompareValue(PWM_0_INST,0,DL_TIMER_CC_0_INDEX); 
                    DL_TimerA_setCaptureCompareValue(PWM_1_INST,speed_,DL_TIMER_CC_0_INDEX);
                  }
                  set_zero();
                  step = 1;
                  single = 1;
                  dutyL = 0;
                  dutyR = 0;
                  normal_speed_L = speed_4_wd - cha_su;
                  normal_speed_R = speed_4_wd + cha_su;
                }
                break;
              }
              case 1:{
                cal_duty_hei_xian();
                if(((car.yaw > 90 && car.yaw < 180) || (car.yaw < -90 && car.yaw > -180)) && is_any_black() == 0){
                 LED_On(1);    sheng_guang_flag = 1; jishu++;
                  set_zero();
                  step = 2;  
                  normal_speed_L = 0;
                  normal_speed_R = 0;
                  dutyL = 0;
                  dutyR = 0;
                }
                break;
              }
              case 2:{
                while(single && (!(car.yaw > (zhuan_jiao - 2) && car.yaw < (zhuan_jiao + 2) ))){
                    DL_TimerA_setCaptureCompareValue(PWM_0_INST,0,DL_TIMER_CC_0_INDEX); 
                    DL_TimerA_setCaptureCompareValue(PWM_1_INST,speed_,DL_TIMER_CC_0_INDEX);
                }
                single = 0;
                normal_speed_L = speed_4;
                normal_speed_R = speed_4;
                cal_duty_imu_bmq(zhuan_jiao);
                if(is_any_black()){
                  set_zero();
                 LED_On(1);    sheng_guang_flag = 1; jishu++;
                  while(!(car.yaw > 158 && car.yaw < 162)){
                    DL_TimerA_setCaptureCompareValue(PWM_0_INST,speed_,DL_TIMER_CC_0_INDEX); 
                    DL_TimerA_setCaptureCompareValue(PWM_1_INST,0,DL_TIMER_CC_0_INDEX);
                  }
                  set_zero();
                  dutyL = 0;
                  dutyR = 0;
                  normal_speed_L = speed_4_wd - cha_su;
                  normal_speed_R = speed_4_wd + cha_su;
                  set_zero();
                  step = 3;  
                }
                break;
              }
              case 3:{
                cal_duty_hei_xian1();
                if(is_any_black() == 0 && ((car.yaw < 90 && car.yaw > 0) || (car.yaw > -90 && car.yaw < 0))){
                    LED_On(1);    sheng_guang_flag = 1; jishu++;
                  set_zero();
                  while(!((car.yaw > -5 && car.yaw < 0) || (car.yaw > 0 && car.yaw < 5))){
                    DL_TimerA_setCaptureCompareValue(PWM_0_INST,speed_,DL_TIMER_CC_0_INDEX); 
                    DL_TimerA_setCaptureCompareValue(PWM_1_INST,0,DL_TIMER_CC_0_INDEX);
                  }
                  set_zero();
                  dutyL = 0;
                  dutyR = 0;
                  step = 0;
                }
                break;
              }
              }
            break;
            }
        }
      set_duty();
    }
}

void set_zero(){
    DL_TimerA_setCaptureCompareValue(PWM_0_INST,0,DL_TIMER_CC_0_INDEX); 
    DL_TimerA_setCaptureCompareValue(PWM_1_INST,0,DL_TIMER_CC_0_INDEX); 
}