#include "STD_type.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "DELAY_INTERFACE.h"

#include "ESP8266_interface.h"
#include "ESP8266_config.h"
#include "ESP8266_private.h"


u8 volatile Iterator = 0  ;
u8 volatile DataCome[200] = {0};

void MUSART_CallBack(void) {
    if (Iterator < sizeof(DataCome) - 1) {  // Prevent overflow
        DataCome[Iterator] = MUSART1_u8ReadDataRegister();
        if (DataCome[Iterator] == '\n' || DataCome[Iterator] == '\r') {
            // Handle end of line or message termination here if needed
        }
        Iterator++;
        DataCome[Iterator] = '\0';  // Null terminate
    }
    MUSART1_VidClearFlags();
}


void ESP8266_VidInit ( void ){

	MUSART1_VidSetCallBack( MUSART_CallBack );

	/* Sending AT Command To Check ESP8266 Is Working Or Not  */
	MUSART1_VidSendStringSynch( (u8 *)"AT+RST\r\n" );

	_delay_ms( 5000 );	/* Clear ESP8266 Buffer */


	ESP8266_VidClearBuffer();
	/* Sending AT Command To Check ESP8266 Is Working Or Not  */
	MUSART1_VidSendStringSynch( (u8 *)"AT\r\n" );

	_delay_ms( 3000 );	/* Clear ESP8266 Buffer */


	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *)"AT+CWMODE=3\r\n" );
	_delay_ms( 3000 );

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *)"AT+CIPMODE=0\r\n" );
	_delay_ms( 3000 );

}

void ESP8266_VidConnectToWiFi ( u8 * SSID , u8 * Password ){

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *) "AT+CWJAP=\"" );
	MUSART1_VidSendStringSynch( (u8 *) SSID );
	MUSART1_VidSendStringSynch( (u8 *) "\",\"" );
	MUSART1_VidSendStringSynch( (u8 *) Password);
	MUSART1_VidSendStringSynch( (u8 *) "\"\r\n");
	_delay_ms( 8000 );

}


void ESP8266_VidConnectToSrvTcp ( u8 * Copy_u8Domain , u8 * Copy_u8Port ){

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *) "AT+CIPSTART=\"TCP\",\"" );
	MUSART1_VidSendStringSynch( (u8 *) Copy_u8Domain );
	MUSART1_VidSendStringSynch( (u8 *) "\"," );
	MUSART1_VidSendStringSynch( (u8 *) Copy_u8Port );
	MUSART1_VidSendStringSynch( (u8 *) "\r\n" );
	//_delay_ms( 5000 );

}

void ESP8266_VidSendHttpReq( u8 * Copy_u8Key , u8 * Copy_u8Data , u8 * Copy_u8Length ){

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *) "AT+CIPSEND=" );
	MUSART1_VidSendStringSynch( (u8 *) Copy_u8Length );
	MUSART1_VidSendStringSynch( (u8 *) "\r\n" );
	_delay_ms( 2000 );

	ESP8266_VidClearBuffer();

	MUSART1_VidSendStringSynch( (u8 *) "GET /update?api_key=" );
	MUSART1_VidSendStringSynch( (u8 *) Copy_u8Key );
	MUSART1_VidSendStringSynch( (u8 *) "&field1=" );
	MUSART1_VidSendStringSynch( (u8 *) Copy_u8Data );
	MUSART1_VidSendStringSynch( (u8 *) "\r\n" );
//	_delay_ms( 20000 );

}

u8 ESP8266_u8ReceiveHttpReq(u8 *Copy_u8ChannelID, u8 *Copy_u8Length) {
    ESP8266_VidClearBuffer();

    /* Send the command to start data transfer */
    MUSART1_VidSendStringSynch((u8 *)"AT+CIPSEND=");
    MUSART1_VidSendStringSynch(Copy_u8Length);
    MUSART1_VidSendStringSynch((u8 *)"\r\n");
    _delay_ms(500);

    ESP8266_VidClearBuffer();

    /* Send the HTTP GET request */
    MUSART1_VidSendStringSynch((u8 *)"GET http://");
    MUSART1_VidSendStringSynch(Copy_u8ChannelID);
    MUSART1_VidSendStringSynch((u8 *)"/status.txt\r\n");
   _delay_ms(750);  // Increased delay to wait for response




    /* Optionally return a specific byte if needed */
    return DataCome[69];
}





void ESP8266_VidClearBuffer ( void ){

	u8 LOC_u8Iterator1 = 0 ;
	Iterator     = 0 ;

	for( LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < 150 ; LOC_u8Iterator1++ ){

		DataCome[ LOC_u8Iterator1 ] = 0 ;

	}

}

