/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 4 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


typedef struct{

	volatile u32 CRL  ;//0x00
	volatile u32 CRH  ;//0x04
	volatile u32 IDR  ;//0x08
	volatile u32 ODR  ;
	volatile u32 BSRR ;
	volatile u32 BRR  ;
	volatile u32 LCKR ;

}GPIO;

#define MGPIOA ((volatile GPIO*)0x40010800)
#define MGPIOB ((volatile GPIO*)0x40010C00)
#define MGPIOC ((volatile GPIO*)0x40011000)

#endif
