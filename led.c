#include "LED.h"

void LED_Init(void) {
	// [TODO] -> Done, need to check (same as lab 3)
	
	// Enable GPIO Clocks
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; //port A
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN; //port C
	
	// Initialize Green LED
	GPIOA->MODER &=~(3UL<<10);	//shift by 10 because MODER5 corresponds to register 10 and 11
	GPIOA->MODER |= 1UL<<10;		//set mode to output (01)
	GPIOA->OTYPER &=~(1UL<<5);	//set output type to be push pull (0)
	GPIOA->PUPDR &=~(1UL<<10);	//set pull up/ pull down type to be no PUPD (00)
}

void Green_LED_Off(void) {
	// [TODO] -> Done (same as lab 3)
	GPIOA->ODR &= ~GPIO_ODR_OD5;
}

void Green_LED_On(void) {
	// [TODO] -> Done (same as lab 3)
	GPIOA->ODR |= GPIO_ODR_OD5;
}

void Green_LED_Toggle(void) {
	// [TODO] -> Done (same as lab 3)
	GPIOA->ODR ^= GPIO_ODR_OD5;
}
