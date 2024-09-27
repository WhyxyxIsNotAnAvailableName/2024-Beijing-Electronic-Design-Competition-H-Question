/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
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

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_0 */
#define PWM_0_INST                                                         TIMA0
#define PWM_0_INST_IRQHandler                                   TIMA0_IRQHandler
#define PWM_0_INST_INT_IRQN                                     (TIMA0_INT_IRQn)
#define PWM_0_INST_CLK_FREQ                                             80000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_0_C0_PORT                                                 GPIOA
#define GPIO_PWM_0_C0_PIN                                          DL_GPIO_PIN_8
#define GPIO_PWM_0_C0_IOMUX                                      (IOMUX_PINCM19)
#define GPIO_PWM_0_C0_IOMUX_FUNC                     IOMUX_PINCM19_PF_TIMA0_CCP0
#define GPIO_PWM_0_C0_IDX                                    DL_TIMER_CC_0_INDEX

/* Defines for PWM_1 */
#define PWM_1_INST                                                         TIMA1
#define PWM_1_INST_IRQHandler                                   TIMA1_IRQHandler
#define PWM_1_INST_INT_IRQN                                     (TIMA1_INT_IRQn)
#define PWM_1_INST_CLK_FREQ                                             80000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_1_C0_PORT                                                 GPIOA
#define GPIO_PWM_1_C0_PIN                                         DL_GPIO_PIN_15
#define GPIO_PWM_1_C0_IOMUX                                      (IOMUX_PINCM37)
#define GPIO_PWM_1_C0_IOMUX_FUNC                     IOMUX_PINCM37_PF_TIMA1_CCP0
#define GPIO_PWM_1_C0_IDX                                    DL_TIMER_CC_0_INDEX

/* Defines for PWM_Buzzer */
#define PWM_Buzzer_INST                                                    TIMG8
#define PWM_Buzzer_INST_IRQHandler                              TIMG8_IRQHandler
#define PWM_Buzzer_INST_INT_IRQN                                (TIMG8_INT_IRQn)
#define PWM_Buzzer_INST_CLK_FREQ                                        20000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_Buzzer_C0_PORT                                            GPIOB
#define GPIO_PWM_Buzzer_C0_PIN                                    DL_GPIO_PIN_15
#define GPIO_PWM_Buzzer_C0_IOMUX                                 (IOMUX_PINCM32)
#define GPIO_PWM_Buzzer_C0_IOMUX_FUNC                IOMUX_PINCM32_PF_TIMG8_CCP0
#define GPIO_PWM_Buzzer_C0_IDX                               DL_TIMER_CC_0_INDEX



/* Defines for COMPARE_0 */
#define COMPARE_0_INST                                                   (TIMG6)
#define COMPARE_0_INST_IRQHandler                               TIMG6_IRQHandler
#define COMPARE_0_INST_INT_IRQN                                 (TIMG6_INT_IRQn)
/* GPIO defines for channel 0 */
#define GPIO_COMPARE_0_C0_PORT                                             GPIOB
#define GPIO_COMPARE_0_C0_PIN                                      DL_GPIO_PIN_2
#define GPIO_COMPARE_0_C0_IOMUX                                  (IOMUX_PINCM15)
#define GPIO_COMPARE_0_C0_IOMUX_FUNC                 IOMUX_PINCM15_PF_TIMG6_CCP0

/* Defines for COMPARE_1 */
#define COMPARE_1_INST                                                   (TIMG0)
#define COMPARE_1_INST_IRQHandler                               TIMG0_IRQHandler
#define COMPARE_1_INST_INT_IRQN                                 (TIMG0_INT_IRQn)
/* GPIO defines for channel 0 */
#define GPIO_COMPARE_1_C0_PORT                                             GPIOA
#define GPIO_COMPARE_1_C0_PIN                                     DL_GPIO_PIN_12
#define GPIO_COMPARE_1_C0_IOMUX                                  (IOMUX_PINCM34)
#define GPIO_COMPARE_1_C0_IOMUX_FUNC                 IOMUX_PINCM34_PF_TIMG0_CCP0




/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG7)
#define TIMER_0_INST_IRQHandler                                 TIMG7_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG7_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                         (39999U)



/* Defines for UART_0 */
#define UART_0_INST                                                        UART3
#define UART_0_INST_IRQHandler                                  UART3_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART3_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_25
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_26
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM55)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM59)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM55_PF_UART3_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM59_PF_UART3_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_80_MHZ_115200_BAUD                                      (43)
#define UART_0_FBRD_80_MHZ_115200_BAUD                                      (26)




/* Defines for SPI_0 */
#define SPI_0_INST                                                         SPI1
#define SPI_0_INST_IRQHandler                                   SPI1_IRQHandler
#define SPI_0_INST_INT_IRQN                                       SPI1_INT_IRQn
#define GPIO_SPI_0_PICO_PORT                                              GPIOB
#define GPIO_SPI_0_PICO_PIN                                       DL_GPIO_PIN_8
#define GPIO_SPI_0_IOMUX_PICO                                   (IOMUX_PINCM25)
#define GPIO_SPI_0_IOMUX_PICO_FUNC                   IOMUX_PINCM25_PF_SPI1_PICO
/* GPIO configuration for SPI_0 */
#define GPIO_SPI_0_SCLK_PORT                                              GPIOB
#define GPIO_SPI_0_SCLK_PIN                                       DL_GPIO_PIN_9
#define GPIO_SPI_0_IOMUX_SCLK                                   (IOMUX_PINCM26)
#define GPIO_SPI_0_IOMUX_SCLK_FUNC                   IOMUX_PINCM26_PF_SPI1_SCLK



/* Defines for ADC12_0 */
#define ADC12_0_INST                                                        ADC1
#define ADC12_0_INST_IRQHandler                                  ADC1_IRQHandler
#define ADC12_0_INST_INT_IRQN                                    (ADC1_INT_IRQn)
#define ADC12_0_ADCMEM_0                                      DL_ADC12_MEM_IDX_0
#define ADC12_0_ADCMEM_0_REF                     DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC12_0_ADCMEM_0_REF_VOLTAGE                                          -1 // VDDA cannot be determined
#define GPIO_ADC12_0_C2_PORT                                               GPIOA
#define GPIO_ADC12_0_C2_PIN                                       DL_GPIO_PIN_17

/* Defines for ADC12_1 */
#define ADC12_1_INST                                                        ADC0
#define ADC12_1_INST_IRQHandler                                  ADC0_IRQHandler
#define ADC12_1_INST_INT_IRQN                                    (ADC0_INT_IRQn)
#define ADC12_1_ADCMEM_0                                      DL_ADC12_MEM_IDX_0
#define ADC12_1_ADCMEM_0_REF                     DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC12_1_ADCMEM_0_REF_VOLTAGE                                          -1 // VDDA cannot be determined
#define ADC12_1_ADCMEM_1                                      DL_ADC12_MEM_IDX_1
#define ADC12_1_ADCMEM_1_REF                     DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC12_1_ADCMEM_1_REF_VOLTAGE                                          -1 // VDDA cannot be determined
#define GPIO_ADC12_1_C0_PORT                                               GPIOA
#define GPIO_ADC12_1_C0_PIN                                       DL_GPIO_PIN_27
#define GPIO_ADC12_1_C5_PORT                                               GPIOB
#define GPIO_ADC12_1_C5_PIN                                       DL_GPIO_PIN_24



/* Port definition for Pin Group A_0 */
#define A_0_PORT                                                         (GPIOA)

/* Defines for PIN_0: GPIOA.22 with pinCMx 47 on package pin 18 */
#define A_0_PIN_0_PIN                                           (DL_GPIO_PIN_22)
#define A_0_PIN_0_IOMUX                                          (IOMUX_PINCM47)
/* Port definition for Pin Group A_1 */
#define A_1_PORT                                                         (GPIOB)

/* Defines for PIN_1: GPIOB.19 with pinCMx 45 on package pin 16 */
#define A_1_PIN_1_PIN                                           (DL_GPIO_PIN_19)
#define A_1_PIN_1_IOMUX                                          (IOMUX_PINCM45)
/* Port definition for Pin Group A_2 */
#define A_2_PORT                                                         (GPIOB)

/* Defines for PIN_2: GPIOB.20 with pinCMx 48 on package pin 19 */
#define A_2_PIN_2_PIN                                           (DL_GPIO_PIN_20)
#define A_2_PIN_2_IOMUX                                          (IOMUX_PINCM48)
/* Port definition for Pin Group A_3 */
#define A_3_PORT                                                         (GPIOB)

/* Defines for PIN_3: GPIOB.18 with pinCMx 44 on package pin 15 */
#define A_3_PIN_3_PIN                                           (DL_GPIO_PIN_18)
#define A_3_PIN_3_IOMUX                                          (IOMUX_PINCM44)
/* Port definition for Pin Group A_4 */
#define A_4_PORT                                                         (GPIOA)

/* Defines for PIN_4: GPIOA.24 with pinCMx 54 on package pin 25 */
#define A_4_PIN_4_PIN                                           (DL_GPIO_PIN_24)
#define A_4_PIN_4_IOMUX                                          (IOMUX_PINCM54)
/* Port definition for Pin Group A_5 */
#define A_5_PORT                                                         (GPIOB)

/* Defines for PIN_5: GPIOB.12 with pinCMx 29 on package pin 64 */
#define A_5_PIN_5_PIN                                           (DL_GPIO_PIN_12)
#define A_5_PIN_5_IOMUX                                          (IOMUX_PINCM29)
/* Port definition for Pin Group A_6 */
#define A_6_PORT                                                         (GPIOB)

/* Defines for PIN_6: GPIOB.1 with pinCMx 13 on package pin 48 */
#define A_6_PIN_6_PIN                                            (DL_GPIO_PIN_1)
#define A_6_PIN_6_IOMUX                                          (IOMUX_PINCM13)
/* Port definition for Pin Group A_7 */
#define A_7_PORT                                                         (GPIOB)

/* Defines for PIN_7: GPIOB.4 with pinCMx 17 on package pin 52 */
#define A_7_PIN_7_PIN                                            (DL_GPIO_PIN_4)
#define A_7_PIN_7_IOMUX                                          (IOMUX_PINCM17)
/* Port definition for Pin Group LEDON */
#define LEDON_PORT                                                       (GPIOA)

/* Defines for PIN_8: GPIOA.13 with pinCMx 35 on package pin 6 */
#define LEDON_PIN_8_PIN                                         (DL_GPIO_PIN_13)
#define LEDON_PIN_8_IOMUX                                        (IOMUX_PINCM35)
/* Port definition for Pin Group dir_L */
#define dir_L_PORT                                                       (GPIOB)

/* Defines for PIN_9: GPIOB.16 with pinCMx 33 on package pin 4 */
#define dir_L_PIN_9_PIN                                         (DL_GPIO_PIN_16)
#define dir_L_PIN_9_IOMUX                                        (IOMUX_PINCM33)
/* Port definition for Pin Group dir_R */
#define dir_R_PORT                                                       (GPIOB)

/* Defines for PIN_10: GPIOB.13 with pinCMx 30 on package pin 1 */
#define dir_R_PIN_10_PIN                                        (DL_GPIO_PIN_13)
#define dir_R_PIN_10_IOMUX                                       (IOMUX_PINCM30)
/* Port definition for Pin Group GPIO */
#define GPIO_PORT                                                        (GPIOA)

/* Defines for LED: GPIOA.28 with pinCMx 3 on package pin 35 */
#define GPIO_LED_PIN                                            (DL_GPIO_PIN_28)
#define GPIO_LED_IOMUX                                            (IOMUX_PINCM3)
/* Port definition for Pin Group add */
#define add_PORT                                                         (GPIOB)

/* Defines for PIN_11: GPIOB.22 with pinCMx 50 on package pin 21 */
#define add_PIN_11_PIN                                          (DL_GPIO_PIN_22)
#define add_PIN_11_IOMUX                                         (IOMUX_PINCM50)
/* Port definition for Pin Group sub */
#define sub_PORT                                                         (GPIOB)

/* Defines for PIN_12: GPIOB.26 with pinCMx 57 on package pin 28 */
#define sub_PIN_12_PIN                                          (DL_GPIO_PIN_26)
#define sub_PIN_12_IOMUX                                         (IOMUX_PINCM57)
/* Port definition for Pin Group next */
#define next_PORT                                                        (GPIOB)

/* Defines for PIN_13: GPIOB.27 with pinCMx 58 on package pin 29 */
#define next_PIN_13_PIN                                         (DL_GPIO_PIN_27)
#define next_PIN_13_IOMUX                                        (IOMUX_PINCM58)
/* Port definition for Pin Group GPIO_TFT */
#define GPIO_TFT_PORT                                                    (GPIOB)

/* Defines for RES: GPIOB.7 with pinCMx 24 on package pin 59 */
#define GPIO_TFT_RES_PIN                                         (DL_GPIO_PIN_7)
#define GPIO_TFT_RES_IOMUX                                       (IOMUX_PINCM24)
/* Defines for DC: GPIOB.6 with pinCMx 23 on package pin 58 */
#define GPIO_TFT_DC_PIN                                          (DL_GPIO_PIN_6)
#define GPIO_TFT_DC_IOMUX                                        (IOMUX_PINCM23)
/* Defines for CS: GPIOB.0 with pinCMx 12 on package pin 47 */
#define GPIO_TFT_CS_PIN                                          (DL_GPIO_PIN_0)
#define GPIO_TFT_CS_IOMUX                                        (IOMUX_PINCM12)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_0_init(void);
void SYSCFG_DL_PWM_1_init(void);
void SYSCFG_DL_PWM_Buzzer_init(void);
void SYSCFG_DL_COMPARE_0_init(void);
void SYSCFG_DL_COMPARE_1_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_SPI_0_init(void);
void SYSCFG_DL_ADC12_0_init(void);
void SYSCFG_DL_ADC12_1_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
