#define white 1
#define black 0
#define cm_20 355
//2000占空比对应0.36m/s
//#define HW1_num 600
//#define HW1_num 400
//#define HW1_num 200

#define task1 1
#define task2 2
#define task3 3
#define task4 4

void ACTION_Analyze(void);
void get_hong_wai(void);
void delay_us(uint32_t Data);
void delay_ms(uint32_t Data);
void get_hong_wai1(void);
void set_duty(void);
void cal_duty_hei_xian(void);
void cal_duty_imu_bmq(float aim_angle);
uint8_t is_any_black(void);
void LED_On(uint8_t flag);
uint8_t Adc_Get_Once(void);
void cal_duty_bmq(void);
void cal_duty_hei_xian1(void);

extern uint8_t HW[10];
extern uint8_t Action_ch; // 接受值
extern float kp;
extern int16_t dutyL;//4000是满占空比，0是零占空比
extern int16_t dutyR;
extern int16_t normal_speed_L;
extern int16_t normal_speed_R;
extern  float kp_imu;
extern uint16_t yz_R ;
extern uint16_t yz_L ;
typedef struct{
    float yaw;
    float x;
    float y;
    float Vw;
}car_;

