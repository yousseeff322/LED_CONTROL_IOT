#include "STD_type.h"
#include "BIT_MATH.h"
#include "FunHelp.h"
#include "DELAY_INTERFACE.h"
#include "DIO_interface.h"
#include "USART_interface.h"
#include "NVIC_interface.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "ESP8266_interface.h"

void Animation1(void);
void Animation2(void);
void Animation3(void);

void main ( void ){

    /***********************Local Variable*************************/
    u8 LOC_u8Data = 0;
    u8 previousData = 0;
    /***********************Clock initialization*************************/
    /* Initialize RCC */
    MRCC_VidInit();
    MRCC_VidEnablePeripheralClock(RCC_APB2, GPIOA_RCC);
    MRCC_VidEnablePeripheralClock(RCC_APB2, USART1_RCC);
    MRCC_VidEnablePeripheralClock(RCC_APB2, AFIO_RCC);

    // Configure UART pins
    MGPIO_VidSetPinDirection(GPIOA, PIN9, OUT_SPEED_2MHZ_AFPP);   // USART TX
    MGPIO_VidSetPinDirection(GPIOA, PIN10, INPUT_FLOATING);        // USART RX

    // Set LED pins
    for (u8 i = 0; i < 8; i++) {
        MGPIO_VidSetPinDirection(GPIOA, i, OUT_SPEED_2MHZ_PP);
    }

    MNVIC_VidSetPriority(USART1_IRQ, 1, NO_SUB_PRIORITY, GROUP3);
    MNVIC_VidEnablePeripheral(USART1_IRQ);
    /* Initialize UART */
    MUSART_VidInit();
    /* Initialize ESP8266 */
    ESP8266_VidInit();

    /* Connect to WIFI Network */
    ESP8266_VidConnectToWiFi((u8*)"Orange-Youssef", (u8*)"yyyy2121");

    while(1){

        /* Connecting To SERVER marwan1.atwebpages.com */
        ESP8266_VidConnectToSrvTcp((u8*)"185.176.43.98", (u8*)"80");

        /* Fetch data from SERVER marwan1.atwebpages.com */
        LOC_u8Data = ESP8266_u8ReceiveHttpReq((u8*)"iot-youssef.atwebpages.com", (u8*)"50");

        // Stay in the function while LOC_u8Data remains unchanged
        if (LOC_u8Data == '0'){
            do {
                for (u8 i = 0; i < 8; i++) {
                    MGPIO_VidSetPinValue(GPIOA, i, LOW);
                }
                // Fetch the new data again to check for changes
                previousData = LOC_u8Data;
                LOC_u8Data = ESP8266_u8ReceiveHttpReq((u8*)"iot-youssef.atwebpages.com", (u8*)"50");
            } while (LOC_u8Data == previousData);
        }
        else if (LOC_u8Data == '1'){
            do {
                for (u8 i = 0; i < 8; i++) {
                    MGPIO_VidSetPinValue(GPIOA, i, HIGH);
                }
                // Fetch the new data again to check for changes
                previousData = LOC_u8Data;
                LOC_u8Data = ESP8266_u8ReceiveHttpReq((u8*)"iot-youssef.atwebpages.com", (u8*)"50");
            } while (LOC_u8Data == previousData);
        }
        else if (LOC_u8Data == '2'){
            do {
                Animation2();
                // Fetch the new data again to check for changes
                previousData = LOC_u8Data;
                LOC_u8Data = ESP8266_u8ReceiveHttpReq((u8*)"iot-youssef.atwebpages.com", (u8*)"50");
            } while (LOC_u8Data == previousData);
        }
        else if (LOC_u8Data == '3'){
            do {
                Animation1();
                // Fetch the new data again to check for changes
                previousData = LOC_u8Data;
                LOC_u8Data = ESP8266_u8ReceiveHttpReq((u8*)"iot-youssef.atwebpages.com", (u8*)"50");
            } while (LOC_u8Data == previousData);
        }
        else if (LOC_u8Data == '4'){
            do {
                Animation3();
                // Fetch the new data again to check for changes
                previousData = LOC_u8Data;
                LOC_u8Data = ESP8266_u8ReceiveHttpReq((u8*)"iot-youssef.atwebpages.com", (u8*)"50");
            } while (LOC_u8Data == previousData);
        }
    }
}

// Animation 1: Forward and backward (already implemented)
void Animation1(void) {
    // Forward direction (from PA0 to PA7)
    for (u8 i = 0; i < 8; i++) {
        MGPIO_VidSetPinValue(GPIOA, i, HIGH);
        MSTK_voidSetBusyWait(200000);
        MGPIO_VidSetPinValue(GPIOA, i, LOW);
    }
    // Backward direction (from PA7 to PA0)
    for (u8 i = 7; i > 0; i--) {
        MGPIO_VidSetPinValue(GPIOA, i, HIGH);
        MSTK_voidSetBusyWait(200000);
        MGPIO_VidSetPinValue(GPIOA, i, LOW);
    }
}

// Animation 2: Circular motion (like a rotating effect)
void Animation2(void) {
    for (u8 i = 0; i < 8; i++) {
        MGPIO_VidSetPinValue(GPIOA, i, HIGH);  // Turn on current LED
        MSTK_voidSetBusyWait(200000);          // Delay
        MGPIO_VidSetPinValue(GPIOA, i, LOW);   // Turn off current LED
    }
}

// Animation 3: All LEDs blink simultaneously
void Animation3(void) {
    for (u8 i = 0; i < 8; i++) {
        MGPIO_VidSetPinValue(GPIOA, i, HIGH);  // Turn on all LEDs
    }
    MSTK_voidSetBusyWait(500000);              // Delay

    for (u8 i = 0; i < 8; i++) {
        MGPIO_VidSetPinValue(GPIOA, i, LOW);   // Turn off all LEDs
    }
    MSTK_voidSetBusyWait(250000);              // Delay
}
