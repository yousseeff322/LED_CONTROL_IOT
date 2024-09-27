/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 2 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_





/* Peripheral Enable/Disable Definitions */
#define ENABLE_PERIPHERAL     1
#define DISABLE_PERIPHERAL    0
#define RESET_PERIPHERAL      2

/* RCC Bus Types */
#define RCC_AHB              0
#define RCC_APB1             1
#define RCC_APB2             2

/********************************************************************************************/
/*                             Clock Factor for PLL Options:                                */
/*  PLL_CLOCK_MULTIPLE_BY_2  | PLL_CLOCK_MULTIPLE_BY_3  | PLL_CLOCK_MULTIPLE_BY_4            */
/*  PLL_CLOCK_MULTIPLE_BY_5  | PLL_CLOCK_MULTIPLE_BY_6  | PLL_CLOCK_MULTIPLE_BY_7            */
/*  PLL_CLOCK_MULTIPLE_BY_8  | PLL_CLOCK_MULTIPLE_BY_9  | PLL_CLOCK_MULTIPLE_BY_10           */
/*  PLL_CLOCK_MULTIPLE_BY_11 | PLL_CLOCK_MULTIPLE_BY_12 | PLL_CLOCK_MULTIPLE_BY_13           */
/*  PLL_CLOCK_MULTIPLE_BY_14 | PLL_CLOCK_MULTIPLE_BY_15 | PLL_CLOCK_MULTIPLE_BY_16           */
/********************************************************************************************/
#define NO_CLOCK_FACTOR                         0b0000
#define PLL_CLOCK_MULTIPLE_BY_2                 0b0000
#define PLL_CLOCK_MULTIPLE_BY_3                 0b0001
#define PLL_CLOCK_MULTIPLE_BY_4                 0b0010
#define PLL_CLOCK_MULTIPLE_BY_5                 0b0011
#define PLL_CLOCK_MULTIPLE_BY_6                 0b0100
#define PLL_CLOCK_MULTIPLE_BY_7                 0b0101
#define PLL_CLOCK_MULTIPLE_BY_8                 0b0110
#define PLL_CLOCK_MULTIPLE_BY_9                 0b0111
#define PLL_CLOCK_MULTIPLE_BY_10                0b1000
#define PLL_CLOCK_MULTIPLE_BY_11                0b1001
#define PLL_CLOCK_MULTIPLE_BY_12                0b1010
#define PLL_CLOCK_MULTIPLE_BY_13                0b1011
#define PLL_CLOCK_MULTIPLE_BY_14                0b1100
#define PLL_CLOCK_MULTIPLE_BY_15                0b1101
#define PLL_CLOCK_MULTIPLE_BY_16                0b1110

/**********************************************************************/
/*                        Clock Security System                       */
/* Enable/Disable:                                                     */
/* 1- ENABLE_CLOCK_SECURITY_SYSTEM: Automatically switches to HSI if   */
/*    HSE fails or when exiting STOP/Standby modes.                    */
/* 2- DISABLE_CLOCK_SECURITY_SYSTEM: No automatic clock switching.     */
/**********************************************************************/
#define DISABLE_CLOCK_SECURITY_SYSTEM           0
#define ENABLE_CLOCK_SECURITY_SYSTEM            1

/**********************************************************************/
/*                 Peripheral Clock Enable for AHB Bus                */
/**********************************************************************/
#define SDIO_RCC           0
#define DMA1_RCC           2
#define DMA2_RCC           3
#define FPEC_RCC           7
#define CRC_RCC            8
#define FSMC_RCC           8
#define ETHERNET_RCC       10

/**********************************************************************/
/*                 Peripheral Clock Enable for APB2 Bus               */
/**********************************************************************/
#define AFIO_RCC           0
#define EXTI_RCC           1
#define GPIOA_RCC          2
#define GPIOB_RCC          3
#define GPIOC_RCC          4
#define GPIOD_RCC          5
#define GPIOE_RCC          6
#define GPIOF_RCC          7
#define GPIOG_RCC          8
#define ADC1_RCC           9
#define ADC2_RCC           10
#define TIM1_RCC           11
#define SPI1_RCC           12
#define TIM8_RCC           13
#define USART1_RCC         14
#define ADC3_RCC           15
#define TIM9_RCC           17
#define TIM10_RCC          18
#define TIM11_RCC          19

/**********************************************************************/
/*                 Peripheral Clock Enable for APB1 Bus               */
/**********************************************************************/
#define TIM2_RCC           0
#define TIM3_RCC           1
#define TIM4_RCC           2
#define TIM5_RCC           3
#define TIM6_RCC           4
#define TIM7_RCC           5
#define TIM12_RCC          6
#define TIM13_RCC          7
#define TIM14_RCC          9
#define WWDG_RCC           11
#define SPI2_RCC           14
#define SPI3_RCC           15
#define USART2_RCC         17
#define USART3_RCC         18
#define UART4_RCC          19
#define UART5_RCC          20
#define I2C1_RCC           21
#define I2C2_RCC           22
#define USB_RCC            23
#define CAN_RCC            25
#define BKP_RCC            27
#define PWR_RCC            28
#define DAC_RCC            29

/**********************************************************************/
/*                      ADC Prescaler Options                         */
/*                                                                    */
/*   - ADC_PRESCALER_DIV2:  PCLK2 divided by 2                        */
/*   - ADC_PRESCALER_DIV4:  PCLK2 divided by 4                        */
/*   - ADC_PRESCALER_DIV6:  PCLK2 divided by 6                        */
/*   - ADC_PRESCALER_DIV8:  PCLK2 divided by 8                        */
/**********************************************************************/
#define ADC_PRESCALER_DIV2   0
#define ADC_PRESCALER_DIV4   1
#define ADC_PRESCALER_DIV6   2
#define ADC_PRESCALER_DIV8   3






void MRCC_VidInit( void );

void MRCC_VidEnablePeripheralClock ( u8 Copy_u8PeripheralBus  , u8 Copy_u8Peripheral );
void MRCC_VidDisablePeripheralClock( u8 Copy_u8PeripheralBus  , u8 Copy_u8Peripheral );
void MRCC_voidSetADCPrescaler(u16 Copy_u16Prescaler) ;





#endif
