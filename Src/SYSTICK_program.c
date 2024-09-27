/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 14 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#include "STD_type.h"
#include "BIT_math.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


/* Define Callback Global Variable */
static void(*MSTK_CallBack)(void);

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;

void MSTK_voidInit(void)
{
#if MSTK_CLK_SRC == MSTK_SRC_AHB
    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
	MSTK -> CTRL = 0x00000004;
#else
    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
	MSTK -> CTRL = 0x00000002;

#endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks) {
    /* Load ticks to the load register */
    MSTK->LOAD = Copy_u32Ticks;

    /* Start Timer */
    SET_BIT(MSTK->CTRL, 0);

    /* Wait till the COUNTFLAG is set */
    while ((GET_BIT(MSTK->CTRL, 16)) == 0) {}

    /* Clear the load and current value registers */
    MSTK->LOAD = 0;
    MSTK->VAL = 0;

    SET_BIT(MSTK->CTRL, 0);

    /* Stop Timer */
    CLR_BIT(MSTK->CTRL, 0);  // Clear the enable bit to stop the timer

    /* Clear the load and current value registers */
    MSTK->LOAD = 0;
    MSTK->VAL = 0;
}

void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;

	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);

	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;

	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL, 1);
}

void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;

	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);

	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;

	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL, 1);
}

void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(MSTK->CTRL, 1);

	/* Stop Timer */
	SET_BIT(MSTK->CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
}

u32  MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;

	Local_u32ElapsedTime = MSTK -> LOAD - MSTK -> VAL ;

	return Local_u32ElapsedTime;
}

u32  MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime;

	Local_u32RemainTime = MSTK -> VAL ;

	return Local_u32RemainTime;
}

void SysTick_Handler(void)
{
	MSTK_CallBack();

}

void MSTK_VidSetCallBack( void (*ptr)(void) ){

	MSTK_CallBack = ptr;
}

void MSTK_VidINTStatus( u8 Copy_u8Status ){

	 MSTK->CTRL &= ~( 1 << 1 );
	 MSTK->CTRL |=  ( Copy_u8Status << 1 );

}
