/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "STD_type.h"

#include "DIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"

#include "DAC_interface.h"
#include "DAC_config.h"

#include "song.h"

volatile u32 Song_Counter = 0;

void DAC_CALLBACK( void ){

	MGPIO_VidSetPortValue( DAC_PORT , DAC_PORT_LH , Song_Array[ Song_Counter ] );
	Song_Counter++;

	if( Song_Counter == Song_Length ){
		Song_Counter = 0;
	}

}

void MDAC_VidInit( void ){

	MGPIO_VidSetPortDirection( DAC_PORT , DAC_PORT_LH , OUT_SPEED_10MHZ_PP );
	MSTK_voidInit();

}

void MDAC_VidPlay( void ){

	MSTK_VidSetCallBack( DAC_CALLBACK );
	MSTK_voidSetBusyWait( 125 );

}
