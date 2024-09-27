# Smart LED Control System

## Overview
This project allows users to control an array of 8 LEDs connected to an STM32 microcontroller through a web interface. The control is achieved using an ESP8266 module to handle communication between the STM32 and a remote server. The website provides options to turn the LEDs on or off and trigger different LED animations.

## Features
- **Web-based LED control**: Users can remotely control the state of the LEDs (on/off).
- **Three LED animations**:
  1. **Animation 1**: Circular motion (LEDs turn on in sequence forward and backward).
  2. **Animation 2**: LEDs blink one by one in a circular motion.
  3. **Animation 3**: All LEDs blink simultaneously.
- **ESP8266 Communication**: Utilizes an ESP8266 to connect to a Wi-Fi network and communicate with the remote server.
- **STM32**: Handles the LED control and animation based on the commands received from the server.

## Hardware Components
- **STM32F103**: The microcontroller responsible for controlling the LEDs.
- **ESP8266**: Wi-Fi module for connecting to a network and communicating with a server.
- **8 LEDs**: Connected to the STM32's GPIO pins.
- **Power supply**: Suitable power source for the STM32 and ESP8266.

## Software Components
- **HTML/CSS/JavaScript Website**: Provides the user interface for controlling the LEDs.
- **Embedded C Code**: Runs on the STM32 and ESP8266 to control the LEDs based on the commands received.

## Circuit Setup
1. **STM32 GPIO Setup**: Connect 8 LEDs to the STM32's GPIOA pins (PA0-PA7).
2. **ESP8266 Setup**: Connect the ESP8266 to STM32’s UART pins (PA9 for TX and PA10 for RX).
3. **Power connections**: Provide suitable power to both STM32 and ESP8266 modules.

## How It Works
1. The ESP8266 connects to the specified Wi-Fi network.
2. The STM32 initializes the UART interface to communicate with the ESP8266.
3. The ESP8266 sends HTTP requests to fetch data from the server (`iot-youssef.atwebpages.com`).
4. Based on the data received, the STM32 performs the following actions:
   - Turns off all LEDs (`'0'`).
   - Turns on all LEDs (`'1'`).
   - Runs **Animation 1**: Circular LED motion (`'2'`).
   - Runs **Animation 2**: Blink one by one (`'3'`).
   - Runs **Animation 3**: Blink all LEDs simultaneously (`'4'`).
5. The user interacts with the website to trigger these commands.

## Website User Interface
The website provides buttons for:
- Turning LEDs on/off.
- Activating the three different animations.

### Website Preview:
![Website UI]("C:\Users\YOUSSEF\Pictures\Screenshots\Screenshot 2024-09-28 000622.png")

## Code Structure
The embedded code is divided into the following sections:
1. **ESP8266 Communication**: Manages the Wi-Fi connection and sending/receiving data to/from the server.
2. **USART Interface**: Used for serial communication between STM32 and ESP8266.
3. **GPIO Interface**: Controls the LED states on the STM32.
4. **LED Animations**: Functions to handle the three different LED animation patterns.

### Folders:
- **MCAL**: Microcontroller Abstraction Layer that contains drivers for hardware peripherals.
- **HAL**: Hardware Abstraction Layer for higher-level interfacing with devices.
- **LIB**: Libraries for utility functions and macros.

### Files:
- **main.c**: The main file where the execution starts.
- **ESP8266_interface.c**: Manages communication with the ESP8266.
- **USART_interface.c**: UART communication implementation.
- **GPIO_interface.c**: Manages LED control through GPIO pins.
- **Animations.c**: Functions for LED animations.
- **RCC_interface.c**: Handles clock configuration.

## Dependencies
The project depends on the following libraries:
- `STD_type.h` - Standard type definitions.
- `BIT_MATH.h` - Bit manipulation macros.
- `FunHelp.h` - Helper functions.
- `DELAY_INTERFACE.h` - Delay utilities.
- `DIO_interface.h` - Digital I/O interface for controlling the GPIO pins.
- `USART_interface.h` - UART communication interface for STM32.
- `NVIC_interface.h` - Nested Vectored Interrupt Controller (NVIC) for handling interrupts.
- `RCC_interface.h` - Clock configuration for STM32.
- `SYSTICK_interface.h` - System tick timer for delays.
- `ESP8266_interface.h` - ESP8266 module interface.

## How to Use
1. Power the STM32 and ESP8266 modules.
2. Ensure that the ESP8266 is connected to the Wi-Fi network (`Orange-Youssef`).
3. Access the web interface hosted on the server (`iot-youssef.atwebpages.com`).
4. Use the buttons to control the LEDs or trigger animations.



## Conclusion
This project showcases how to integrate an STM32 microcontroller with an ESP8266 module to control LEDs through a web interface. The system is scalable for more LEDs, additional animations, and smart home applications. With future improvements, this project can evolve into a more sophisticated IoT-based home automation system.
