#include "stm32l476xx.h"
#include "LED.h"
#include "SysClock.h"
#include "UART.h"
#include <string.h>
#include <stdio.h>

// Initializes USARTx
// USART2: UART Communication with Termite
// USART1: Bluetooth Communication with Phone
void Init_USARTx(int x) {
	if(x == 1) {
		UART1_Init();
		UART1_GPIO_Init();
		USART_Init(USART1);
	} else if(x == 2) {
		UART2_Init();
		UART2_GPIO_Init();
		USART_Init(USART2);
	} else {
		// Do nothing...
	}
}

int main(void) {
	System_Clock_Init(); // Switch System Clock = 80 MHz
	LED_Init();

	// Initialize UART -- change the argument depending on the part you are working on
	Init_USARTx(2);
	
	char rxByte;
	while(1) {
		// [TODO] -> Done
		printf("Type 'Y' to turn on the LED and 'N' to turn off the LED.\n");
		scanf("%c", &rxByte);
		if (rxByte == 'Y' || rxByte == 'y'){
			Green_LED_On();
			printf("The LED has turned on.\n");
		}
		else if (rxByte == 'N' || rxByte == 'n'){
			Green_LED_Off();
			printf("The LED has turned off.\n");
		}
		else{
			printf("Your input was invalid. Please try again.\n");
		}
		//Init_USARTx(1); //this line is since data from HC-05 can cause overflow, so re-initialize after every transaction to reset state
	}
}
