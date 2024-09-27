/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 8 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_



/* IRQ Numbers for STM32F103C8T6 */

#define WWDG_IRQ                    0
#define PVD_IRQ                     1
#define TAMPER_IRQ                  2
#define RTC_IRQ                     3
#define FLASH_IRQ                   4
#define RCC_IRQ                     5
#define EXTI0_IRQ                   6
#define EXTI1_IRQ                   7
#define EXTI2_IRQ                   8
#define EXTI3_IRQ                   9
#define EXTI4_IRQ                   10
#define DMA1_Channel1_IRQ           11
#define DMA1_Channel2_IRQ           12
#define DMA1_Channel3_IRQ           13
#define DMA1_Channel4_IRQ           14
#define DMA1_Channel5_IRQ           15
#define DMA1_Channel6_IRQ           16
#define DMA1_Channel7_IRQ           17
#define ADC1_2_IRQ                  18
#define USB_HP_CAN_TX_IRQ           19
#define USB_LP_CAN_RX0_IRQ          20
#define CAN_RX1_IRQ                 21
#define CAN_SCE_IRQ                 22
#define EXTI9_5_IRQ                 23
#define TIM1_BRK_IRQ                24
#define TIM1_UP_IRQ                 25
#define TIM1_TRG_COM_IRQ            26
#define TIM1_CC_IRQ                 27
#define TIM2_IRQ                    28
#define TIM3_IRQ                    29
#define TIM4_IRQ                    30
#define I2C1_EV_IRQ                 31
#define I2C1_ER_IRQ                 32
#define I2C2_EV_IRQ                 33
#define I2C2_ER_IRQ                 34
#define SPI1_IRQ                    35
#define SPI2_IRQ                    36
#define USART1_IRQ                  37
#define USART2_IRQ                  38
#define USART3_IRQ                  39
#define EXTI15_10_IRQ               40
#define RTC_Alarm_IRQ               41
#define USBWakeUp_IRQ               42


///////////////////////////////////////////////////////////////////////////////////
#define NO_SUB_PRIORITY 0

/////////////////////////
#define PEND_SV        -6
#define SYSTICK        -5
////////////////////////////
#define SV_CALL        -4
/////////////////////////
#define MEMORY_MANAGE  -3
#define BUS_FAULT      -2
#define USAGE_FAULT    -1
/////////////////////////

//GROUP 3
//Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ( (Copy_u8Group - 0x05FA0300) / 256 )  ;

//u8 Priority   = ( Copy_u8SubPriority | (Copy_u8GroupPriority << 4) )  ;
// 0x100 Hex  ---> 256 Decimal
#define GROUP3     0x05FA0300//0 bit for sub & 4 bit For group   << 0
#define GROUP4     0x05FA0400//1 bit for sub & 3 bit For group   << 1
#define GROUP5     0x05FA0500//2 bit for sub & 2 bit For group   << 2
#define GROUP6     0x05FA0600//3 bit for sub & 1 bit For group   << 3
#define GROUP7     0x05FA0700//4 bit for sub & 0 bit For group   << 4



void MNVIC_VidEnablePeripheral  ( u8 Copy_u8INTID );

void MNVIC_VidDisablePeripheral ( u8 Copy_u8INTID );

void MNVIC_VidSetPending        ( u8 Copy_u8INTID );

void MNVIC_VidClearPending      ( u8 Copy_u8INTID );

u8   MNVIC_u8GetActive          ( u8 Copy_u8INTID );

void MNVIC_VidSetPriority( s8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u8Group );





#endif
