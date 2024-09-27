/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 4 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define     GPIOA  0
#define     GPIOB  1
#define     GPIOC  2


#define HIGH_PORTL 0x00FF
#define HIGH_PORTH 0xFF00


#define   PIN0     0
#define   PIN1     1
#define   PIN2     2
#define   PIN3     3
#define   PIN4     4
#define   PIN5     5
#define   PIN6     6
#define   PIN7     7
#define   PIN8     8
#define   PIN9     9
#define   PIN10    10
#define   PIN11    11
#define   PIN12    12
#define   PIN13    13
#define   PIN14    14
#define   PIN15    15



#define  OUT_SPEED_10MHZ_PP				0b0001
#define  OUT_SPEED_10MHZ_OD				0b0101
#define  OUT_SPEED_10MHZ_AFPP			0b1001
#define  OUT_SPEED_10MHZ_AFOD			0b1101

#define  OUT_SPEED_2MHZ_PP				0b0010
#define  OUT_SPEED_2MHZ_OD				0b0110
#define  OUT_SPEED_2MHZ_AFPP			0b1010
#define  OUT_SPEED_2MHZ_AFOD			0b1110


#define  OUT_SPEED_50MHZ_PP				0b0011
#define  OUT_SPEED_50MHZ_OD				0b0111
#define  OUT_SPEED_50MHZ_AFPP			0b1011
#define  OUT_SPEED_50MHZ_AFOD			0b1111



#define INPUT_ANALOG					0b0000
#define INPUT_FLOATING					0b0100
#define INPUT_PULL_UP_DOWN				0b1000


#define GPIO_HIGH 		1
#define GPIO_LOW 		0

#define GPIO_LOCK			1
#define GPIO_NOTLOCK 		0


#define HIGH_PORTL 0x00FF
#define HIGH_PORTH 0xFF00



#define HIGH 		1
#define LOW 		0



void MGPIO_VidSetPinDirection  ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode  );
void MGPIO_VidSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value );
u8   MGPIO_u8GetPinValue       ( u8 Copy_u8Port , u8 Copy_u8Pin                     );


void MGPIO_VidSetPortDirection ( u8 Copy_u8Port , u8 Copy_u8Position , u8 Copy_u8Mode   );
void MGPIO_VidSetPortValue     ( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value );
u16  MGPIO_u16GetPortValue      ( u8 Copy_u8Port , u8 Copy_u8Position                   );




#endif
