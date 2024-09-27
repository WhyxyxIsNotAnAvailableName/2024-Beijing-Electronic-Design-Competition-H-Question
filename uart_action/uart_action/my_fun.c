#include "ti_msp_dl_config.h"
#include "math.h"
#include "my_fun.h"
#include "Lcd.h"
#include "stdio.h"
#define PI 3.1415926
uint16_t yz_R = 3000;
uint16_t yz_L = 2600;

//右轮：黑色2770，2420，白色：3500左轮：白色3150，3000黑色：2300，2900
 union
{
    uint8_t data[24];
    float data_float[6];
} ACTION_vaule;

car_ car;
/// @brief Action接收值
uint8_t Action_ch = 0; // 接受值
/// @brief Action接收标志
 uint8_t Action_flag = 0; // 接收标志
/// @brief Action接收状态机
 uint8_t Action_step = 0; // 状态机
/// @brief Action接收计数
 uint8_t Action_count = 0; // 计数

uint8_t HW[10] = {0};
 
 int16_t dutyL = 0;//4000是满占空比，0是零占空比
 int16_t dutyR = 0;
 uint32_t aa = 0;
 float kp_heixian = 0.01;
 float kp_imu = 20;
 float kp_bmq = 3;
 float kp_jiu_pian = 45;

 uint8_t ADC_FLAG;
 uint16_t gAdcResult;
int16_t normal_speed_L= 2000;
int16_t normal_speed_R= 2000;
  uint16_t get_adc1 = 0;
  uint16_t get_adc2 = 0;
extern uint32_t freq_new_L;
extern uint32_t freq_new_R;

void ACTION_Analyze(void)
{
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);
    
    switch (Action_step)
    {
    case 0:
        if (Action_ch == 0x0d)
        {
            Action_step++;
        }
        else
        {
            Action_step = 0;
        }
        break;
    case 1:
        if (Action_ch == 0x0A)
        {
            Action_count = 0;
            Action_step++;
        }
        else if (Action_ch == 0x0D)
        {
            // Action_step = 1;
        }
        else
        {
            Action_step = 0;
        }
        break;
    case 2:
        ACTION_vaule.data[Action_count] = Action_ch;
        Action_count++;
        if (Action_count >= 24 /*24*/)
        {
            Action_count = 0;
            Action_step++;
        }
        break;
    case 3:
        if (Action_ch == 0x0A)
        {
            Action_step++;
        }
        else
        {
            Action_step = 0;
        }
        break;
    case 4:
        if (Action_ch == 0x0D)
        {
            car.yaw = ACTION_vaule.data_float[0] /* / 180.0f * PI*/;
//            if(car.yaw < 0 )
//              car.yaw += 2 * PI;
//            car.x = ACTION_vaule.data_float[3] / 1000;
//            car.y = ACTION_vaule.data_float[4] / 1000;
//            car.Vw = ACTION_vaule.data_float[5] / 180.0f * PI;
        }
        Action_step = 0;
        break;
    default:
        Action_step = 0;
        break;
    }
}

void get_hong_wai(void){
    DL_GPIO_setPins (GPIOA,LEDON_PIN_8_PIN);

  DL_GPIO_initDigitalOutput(A_0_PIN_0_IOMUX);
  DL_GPIO_initDigitalOutput(A_1_PIN_1_IOMUX);
  DL_GPIO_initDigitalOutput(A_2_PIN_2_IOMUX);
  DL_GPIO_initDigitalOutput(A_3_PIN_3_IOMUX);
  DL_GPIO_initDigitalOutput(A_4_PIN_4_IOMUX);
  DL_GPIO_initDigitalOutput(A_5_PIN_5_IOMUX);
  DL_GPIO_initDigitalOutput(A_6_PIN_6_IOMUX);
  DL_GPIO_initDigitalOutput(A_7_PIN_7_IOMUX);
  
  DL_GPIO_setPins (GPIOA,A_0_PIN_0_PIN);
  DL_GPIO_setPins (GPIOA,A_1_PIN_1_PIN);
  DL_GPIO_setPins (GPIOA,A_2_PIN_2_PIN);
  DL_GPIO_setPins (GPIOA,A_3_PIN_3_PIN);
  DL_GPIO_setPins (GPIOA,A_4_PIN_4_PIN);
  DL_GPIO_setPins (GPIOA,A_5_PIN_5_PIN);
  DL_GPIO_setPins (GPIOA,A_6_PIN_6_PIN);
  DL_GPIO_setPins (GPIOA,A_7_PIN_7_PIN);
  
  DL_GPIO_enableOutput (GPIOA,A_0_PIN_0_PIN /*| A_1_PIN_1_PIN | A_2_PIN_2_PIN | A_3_PIN_3_PIN | A_4_PIN_4_PIN | A_5_PIN_5_PIN | A_6_PIN_6_PIN | A_7_PIN_7_PIN*/);

  delay_us(10);
  
  //  DL_GPIO_initDigitalOutputFeatures(A_0_PIN_0_IOMUX, DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_DOWN, DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_ENABLE);
//  DL_GPIO_clearPins (GPIOA,A_0_PIN_0_PIN);
//  DL_GPIO_clearPins (GPIOA,A_1_PIN_1_PIN);
//  DL_GPIO_clearPins (GPIOA,A_2_PIN_2_PIN);
//  DL_GPIO_clearPins (GPIOA,A_3_PIN_3_PIN);
//  DL_GPIO_clearPins (GPIOA,A_4_PIN_4_PIN);
//  DL_GPIO_clearPins (GPIOA,A_5_PIN_5_PIN);
//  DL_GPIO_clearPins (GPIOA,A_6_PIN_6_PIN);
//  DL_GPIO_clearPins (GPIOA,A_7_PIN_7_PIN);
//  
//    delay_us(1);
            
    DL_GPIO_initDigitalInput(A_0_PIN_0_IOMUX);
    DL_GPIO_initDigitalInput(A_1_PIN_1_IOMUX);
    DL_GPIO_initDigitalInput(A_2_PIN_2_IOMUX);
    DL_GPIO_initDigitalInput(A_3_PIN_3_IOMUX);
    DL_GPIO_initDigitalInput(A_4_PIN_4_IOMUX);
    DL_GPIO_initDigitalInput(A_5_PIN_5_IOMUX);
    DL_GPIO_initDigitalInput(A_6_PIN_6_IOMUX);
    DL_GPIO_initDigitalInput(A_7_PIN_7_IOMUX);
    
        delay_cycles(40 );
        
     aa =  DL_GPIO_readPins (GPIOA,A_0_PIN_0_PIN);
     HW[0] =  DL_GPIO_readPins (GPIOA,A_0_PIN_0_PIN);
     HW[1] = DL_GPIO_readPins (GPIOA,A_1_PIN_1_PIN);
     HW[2] = DL_GPIO_readPins (GPIOA,A_2_PIN_2_PIN);
     HW[3] = DL_GPIO_readPins (GPIOA,A_3_PIN_3_PIN);
     HW[4] =  DL_GPIO_readPins (GPIOA,A_4_PIN_4_PIN);
     HW[5] =  DL_GPIO_readPins (GPIOA,A_5_PIN_5_PIN);
     HW[6] =  DL_GPIO_readPins (GPIOA,A_6_PIN_6_PIN);
     HW[7] =  DL_GPIO_readPins (GPIOA,A_7_PIN_7_PIN);
     
     DL_GPIO_clearPins (GPIOA,LEDON_PIN_8_PIN);

}
void get_hong_wai1(void){
  if(DL_GPIO_readPins (A_0_PORT,A_0_PIN_0_PIN)){
    HW[0] = white;
   // Gui_DrawFont_GBK16(4, 64, WHITE, GRAY1, "0");
  }
  else {
    HW[0] = black;
    //Gui_DrawFont_GBK16(4, 64, BLACK, GRAY1, "0");
  }
  if(DL_GPIO_readPins (A_1_PORT,A_1_PIN_1_PIN)){
  //  Gui_DrawFont_GBK16(20, 64, WHITE, GRAY1, "1");
    HW[1] = white;
  }
  else {
    HW[1] = black;
   // Gui_DrawFont_GBK16(20, 64, BLACK, GRAY1, "1");
  }
  if(DL_GPIO_readPins (A_2_PORT,A_2_PIN_2_PIN)){
        //Gui_DrawFont_GBK16(36, 64, WHITE, GRAY1, "2");
        HW[2] = white;
  }
  else {
        HW[2] = black;
            //Gui_DrawFont_GBK16(36, 64, BLACK, GRAY1, "2");
  }
  if(DL_GPIO_readPins (A_3_PORT,A_3_PIN_3_PIN)){
       // Gui_DrawFont_GBK16(52, 64, WHITE, GRAY1, "3");
        HW[3] = white;
  }
  else {
        HW[3] = black;
           // Gui_DrawFont_GBK16(52, 64, BLACK, GRAY1, "3");
  }
  if(DL_GPIO_readPins (A_4_PORT,A_4_PIN_4_PIN)){
        HW[4] = white;
          //  Gui_DrawFont_GBK16(68, 64, WHITE, GRAY1, "4");
  }
  else {
        HW[4] = black;
            //Gui_DrawFont_GBK16(68, 64, BLACK, GRAY1, "4");
  }
  if(DL_GPIO_readPins (A_5_PORT,A_5_PIN_5_PIN)){
        //Gui_DrawFont_GBK16(84, 64, WHITE, GRAY1, "5");
        HW[5] = white;
  }
  else {
        HW[5] = black;
            //Gui_DrawFont_GBK16(84, 64, BLACK, GRAY1, "5");
  }
  if(DL_GPIO_readPins (A_6_PORT,A_6_PIN_6_PIN)){
      //  Gui_DrawFont_GBK16(100, 64, WHITE, GRAY1, "6");
        HW[6] = white;
  }
  else {
        HW[6] = black;
            //Gui_DrawFont_GBK16(100, 64, BLACK, GRAY1, "6");
  }
  if(DL_GPIO_readPins (A_7_PORT,A_7_PIN_7_PIN)){
       // Gui_DrawFont_GBK16(116, 64, WHITE, GRAY1, "7");
        HW[7] = white;
  }
  else {
      HW[7] = black;
        //  Gui_DrawFont_GBK16(116, 64, BLACK, GRAY1, "7");
  }
    DL_ADC12_enableConversions(ADC12_1_INST);
    DL_ADC12_startConversion(ADC12_1_INST);
    delay_us(1);
    get_adc1 = DL_ADC12_getMemResult(ADC12_1_INST, DL_ADC12_MEM_IDX_0);
    get_adc2 = DL_ADC12_getMemResult(ADC12_1_INST, DL_ADC12_MEM_IDX_1);
    if(get_adc1 > yz_L){//左轮
        HW[8] = white;
    }
    else{
        HW[8] = black;
    }
    if(get_adc2 > yz_R){//右轮
        HW[9] = white;
    }
    else{
        HW[9] = black;
    }
//  if(DL_GPIO_readPins (A_7_PORT,A_7_PIN_7_PIN)){
//       // Gui_DrawFont_GBK16(116, 64, WHITE, GRAY1, "7");
//        HW[8] = white;
//  }
//  else {
//      HW[8] = black;
//        //  Gui_DrawFont_GBK16(116, 64, BLACK, GRAY1, "7");
//  }
//  if(DL_GPIO_readPins (A_7_PORT,A_7_PIN_7_PIN)){
//       // Gui_DrawFont_GBK16(116, 64, WHITE, GRAY1, "7");
//        HW[9] = white;
//  }
//  else {
//      HW[9] = black;
//        //  Gui_DrawFont_GBK16(116, 64, BLACK, GRAY1, "7");
//  }
}

void delay_us(uint32_t Data)
{
    delay_cycles(Data*27);
}

void delay_ms(uint32_t Data)
{
    delay_cycles(Data*27000);
}

void cal_duty_hei_xian(void){
    //假设A0在车的最左边，A7在车的最右边
    int16_t num = 0;//num趋于零
    //A8是左轮旁边的，A9是右轮旁边的
    for(uint8_t i = 0;i < 10;i++){
      if(HW[i] == black){
        switch(i){
        case 0:
          num = -650;
          break;
        case 7:
          num = 650;
          break;
        case 1:
          num = -650;
          break;
        case 6:
          num = 650;
          break;
        case 2:
          num = -550;
          break;
        case 5:
          num = 550;
          break;
        case 3:
          num = -420;
          break;
        case 4:
          num = 420;
          break;
        case 8:
          num = -650;
          break;
        case 9:
          num = 650;
          break;
        }
                break;
      }
    }
    //num大于0了是左边黑的多，应该要加快右轮，num范围是±6000
    dutyR = normal_speed_R - num;// * kp_heixian;
    dutyL = normal_speed_L + num;// * kp_heixian;
}

void cal_duty_hei_xian1(void){
    //假设A0在车的最左边，A7在车的最右边
    int16_t num = 0;//num趋于零
    //A8是左轮旁边的，A9是右轮旁边的
    for(uint8_t i = 0;i < 10;i++){
      if(HW[i] == black){
        switch(i){
        case 0:
          num = -675;
          break;
        case 7:
          num = 675;
          break;
        case 1:
          num = -650;
          break;
        case 6:
          num = 650;
          break;
        case 2:
          num = -550;
          break;
        case 5:
          num = 550;
          break;
        case 3:
          num = -420;
          break;
        case 4:
          num = 420;
          break;
        case 8:
          num = -650;
          break;
        case 9:
          num = 650;
          break;
        }
                break;
      }
    }
    //num大于0了是左边黑的多，应该要加快右轮，num范围是±6000
    dutyR = normal_speed_R - num;// * kp_heixian;
    dutyL = normal_speed_L + num;// * kp_heixian;
}

void cal_duty_imu_bmq(float aim_angle){
    if(car.yaw == 0)
    {
    car.yaw += 0.01;
    }
    float num1 = aim_angle - car.yaw;//num趋于aim_angle，逆时针是加，顺时针是减
    //假设aim是0，此时的angle大于0，说明逆时针偏了，应该左轮快一点
    //int32_t num2 = 0;//freq_new_L - freq_new_R;
//    if(fabs(num1) > 3){
//        num2 = 0;
//    }
     if(fabs(num1) < 3){
      num1 *= 5;
    }
    else if(fabs(num1) < 10){
      num1 *= 4;
    }
    if((aim_angle >= 0 && car.yaw > 0) ||(aim_angle <= 0 && car.yaw < 0)){
    dutyR = normal_speed_R + (num1) * kp_imu;
    dutyL = normal_speed_L - (num1) * kp_imu;
    return;
    }
    else if(aim_angle > 0 && car.yaw < 0){
      if(num1 > 180){
        dutyL = normal_speed_L + (360 - num1) * kp_imu;
        dutyR = normal_speed_R - (360 - num1) * kp_imu;
      }
      else {
        dutyR = normal_speed_R + num1 * kp_imu;
        dutyL = normal_speed_L - num1 * kp_imu;
      }
    return;
    }    
    else if(aim_angle < 0 && car.yaw > 0){
      if(num1 < -180){
        dutyR = normal_speed_R+ (360 + num1) * kp_imu;
        dutyL = normal_speed_L- (360 + num1) * kp_imu;
      }
      else{
        dutyL = normal_speed_L - num1 * kp_imu;
        dutyR = normal_speed_R + num1 * kp_imu;
      }
    return;
    }
}

void cal_duty_bmq(void){
    int32_t num2 = freq_new_L - freq_new_R;
    dutyR = normal_speed_R + kp_bmq * num2;
    dutyL = normal_speed_L - kp_bmq * num2;
    return;
}

void imu_jiu_pian(float aim_angle){
    

}
void set_duty(void){
  if(dutyL > 4000)
    dutyL = 4000;
  else if(dutyL < 0)
    dutyL = 0;
  if(dutyR > 4000)
    dutyR = 4000;
  else if(dutyR < 0)
    dutyR = 0;
          DL_TimerA_setCaptureCompareValue(PWM_0_INST,dutyL,DL_TIMER_CC_0_INDEX); 
          DL_TimerA_setCaptureCompareValue(PWM_1_INST,dutyR,DL_TIMER_CC_0_INDEX); 
}

uint8_t is_any_black(void){
  for(uint8_t i = 0;i < 10;i++){
    if(HW[i] == black){
        return 1;
    }
  }
    return 0;
}

void LED_On(uint8_t flag)
{
  if(flag){
    DL_GPIO_setPins(GPIO_PORT, GPIO_LED_PIN);
  DL_Timer_startCounter(PWM_Buzzer_INST);
  }
  else{
    DL_GPIO_clearPins(GPIO_PORT, GPIO_LED_PIN);
   DL_Timer_stopCounter(PWM_Buzzer_INST);
  }
}

uint8_t Adc_Get_Once(void)
{
    DL_ADC12_enableConversions(ADC12_0_INST);
    DL_ADC12_startConversion(ADC12_0_INST);
    gAdcResult = DL_ADC12_getMemResult(ADC12_0_INST, DL_ADC12_MEM_IDX_0);
    
    if (gAdcResult > 3500){
      ADC_FLAG = 0;
    }else if (gAdcResult > 2800){
      ADC_FLAG = 1;
    }else if (gAdcResult > 2300){
      ADC_FLAG = 2;
    }else if (gAdcResult > 1800){
      ADC_FLAG = 3;
    }else if (gAdcResult > 1300){
      ADC_FLAG = 4;
    }else if (gAdcResult > 900){
      ADC_FLAG = 5;
    }else if (gAdcResult > 300){
      ADC_FLAG = 6;
    }
    
    return ADC_FLAG;
}