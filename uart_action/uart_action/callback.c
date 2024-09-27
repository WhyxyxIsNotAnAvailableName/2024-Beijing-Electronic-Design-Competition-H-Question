
#include "ti_msp_dl_config.h"
#include "math.h"
#include "my_fun.h"

#define PI 3.1415926

uint32_t time_new_L = 0;
uint32_t time_new_R = 0;

//uint32_t time_old_L = 0;

uint32_t overflow_L = 0;
uint32_t overflow_R = 0;

uint16_t loadvalue_L = 0;
uint16_t loadvalue_R = 0;

//uint32_t freq_old_L = 0;
uint32_t freq_new_L = 0;
uint32_t freq_new_R = 0;
uint16_t jishu_timer = 0;
extern uint8_t sheng_guang_flag;
extern uint8_t flag_start;

void UART_0_INST_IRQHandler(void){
  switch(DL_UART_Main_getPendingInterrupt(UART_0_INST)){
    case DL_UART_MAIN_IIDX_RX: 
      Action_ch = DL_UART_Main_receiveData(UART_0_INST);
      ACTION_Analyze();
      flag_start = 1;
      break;
  }

}

void COMPARE_0_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(COMPARE_0_INST)) {
        case DL_TIMERG_IIDX_ZERO:
            overflow_L++;
            break;
        default:
            break;
    }
    switch (DL_TimerG_getPendingInterrupt(COMPARE_1_INST)) {
        case DL_TIMERG_IIDX_ZERO:
            overflow_R++;
            break;
        default:
            break;
    }
}

void TIMER_0_INST_IRQHandler(void)
{
    switch (DL_TimerG_getPendingInterrupt(TIMER_0_INST)) {
        case DL_TIMERG_IIDX_ZERO:
            //DL_TimerG_stopCounter(COMPARE_0_INST);
            //DL_TimerG_stopCounter(COMPARE_1_INST);

            //time_old_L = time_new_L;
            time_new_L =  DL_TimerG_getTimerCount(COMPARE_0_INST);
            //freq_old_L = freq_new_L;
            freq_new_L += (loadvalue_L - time_new_L) + overflow_L * 65535;
            overflow_L = 0;
            DL_TimerG_setTimerCount(COMPARE_0_INST, loadvalue_L);
         
            //time_old_R = time_new_R;
            time_new_R =  DL_TimerG_getTimerCount(COMPARE_1_INST);
            //freq_old_R = freq_new_R;
            freq_new_R += (loadvalue_R - time_new_R) + overflow_R * 65535;
            overflow_R = 0;
            DL_TimerG_setTimerCount(COMPARE_1_INST, loadvalue_R);
            
            //DL_TimerG_startCounter(COMPARE_0_INST);
            //DL_TimerG_startCounter(COMPARE_1_INST);
            if(sheng_guang_flag){
              if(jishu_timer >= 6){
                LED_On(0);
                sheng_guang_flag = 0;
                jishu_timer = 0;
              }
              else 
                jishu_timer++;
            }
            break;
        default:
            break;
    }
}
