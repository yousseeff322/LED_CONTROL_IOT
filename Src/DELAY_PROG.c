/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include"STD_type.h"

#include"SYSTICK_INTERFACE.h"

#include"DELAY_INTERFACE.h"



/* Function to create a millisecond delay */
void _delay_ms(u32 Copy_u32Time) {
    /* Initialize SYSTICK */
    MSTK_voidInit();

    /* Disable Interrupts for busy-wait */
    MSTK_VidINTStatus(MSTK_INT_DIS);

    /* Set a busy-wait delay for milliseconds (1 ms = 1000 microseconds) */
    MSTK_voidSetBusyWait(Copy_u32Time * 1000);

    /* Wait until the timer finishes (handled by MSTK_voidSetBusyWait) */
}

/* Function to create a microsecond delay */
void _delay_us(u32 Copy_u32Time) {
    /* Initialize SYSTICK */
    MSTK_voidInit();

    /* Disable Interrupts for busy-wait */
    MSTK_VidINTStatus(MSTK_INT_DIS);

    /* Set a busy-wait delay for microseconds */
    MSTK_voidSetBusyWait(Copy_u32Time);

    /* Wait until the timer finishes (handled by MSTK_voidSetBusyWait) */
}
