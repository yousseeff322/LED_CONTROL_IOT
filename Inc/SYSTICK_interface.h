/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 14 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/



#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


#define MSTK_INT_EN   1
#define MSTK_INT_DIS  0


/* Apply Clock choice from configuration file
   Disable SysTick interrupt
   Disable Systick                          */
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks );
void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
void MSTK_VidSetCallBack( void (*ptr)(void) ) ;

u32  MSTK_u32GetRemainingTime(void);
void MSTK_VidINTStatus( u8 Copy_u8Status ) ;


void SysTick_Handler(void);




#endif
