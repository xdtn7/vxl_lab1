#include "main.h"
#include "led_display.h"


#define	NUMBER_OF_ELEMENT						12

#define CLOCK_1_A			GPIO_PIN_0
#define CLOCK_1_A_PORT		GPIOB
#define CLOCK_1_B			GPIO_PIN_1
#define CLOCK_1_B_PORT		GPIOB
#define CLOCK_1_C			GPIO_PIN_2
#define CLOCK_1_C_PORT		GPIOB
#define CLOCK_1_D			GPIO_PIN_3
#define CLOCK_1_D_PORT		GPIOB
#define CLOCK_1_E			GPIO_PIN_4
#define CLOCK_1_E_PORT		GPIOB
#define CLOCK_1_F			GPIO_PIN_5
#define CLOCK_1_F_PORT		GPIOB
#define CLOCK_1_G			GPIO_PIN_6
#define CLOCK_1_G_PORT		GPIOB
#define CLOCK_1_H			GPIO_PIN_7
#define CLOCK_1_H_PORT		GPIOB
#define CLOCK_1_I			GPIO_PIN_8
#define CLOCK_1_I_PORT		GPIOB
#define CLOCK_1_K			GPIO_PIN_9
#define CLOCK_1_K_PORT		GPIOB
#define CLOCK_1_L			GPIO_PIN_10
#define CLOCK_1_L_PORT		GPIOB
#define CLOCK_1_M			GPIO_PIN_11
#define CLOCK_1_M_PORT		GPIOB

//common Anode
//static uint8_t sevenSegmentLEDConversion[NUMBER_OF_DECIMAL_DIGITS] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

//common Cathode
static uint16_t clockConversion[NUMBER_OF_ELEMENT] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800};

void clearLed(uint16_t temp){

	if(temp & 0x01)
		HAL_GPIO_WritePin(CLOCK_1_A_PORT, CLOCK_1_A, SET);

	else if(temp & 0x02)
		HAL_GPIO_WritePin(CLOCK_1_B_PORT, CLOCK_1_B, SET);

	else if(temp & 0x04)
		HAL_GPIO_WritePin(CLOCK_1_C_PORT, CLOCK_1_C, SET);

	else if(temp & 0x08)
		HAL_GPIO_WritePin(CLOCK_1_D_PORT, CLOCK_1_D, SET);

	else if(temp & 0x10)
		HAL_GPIO_WritePin(CLOCK_1_E_PORT, CLOCK_1_E, SET);

	else if(temp & 0x20)
		HAL_GPIO_WritePin(CLOCK_1_F_PORT, CLOCK_1_F, SET);

//	//temp = 0x3f
	else if(temp & 0x40) //true or false?
 		HAL_GPIO_WritePin(CLOCK_1_G_PORT, CLOCK_1_G, SET);

	else if(temp & 0x80) //what is the value of temp & 0x01 = 0x01 --> TRUE
		HAL_GPIO_WritePin(CLOCK_1_H_PORT, CLOCK_1_H, SET);

	else if(temp & 0x100)
		HAL_GPIO_WritePin(CLOCK_1_I_PORT, CLOCK_1_I, SET);

	else if(temp & 0x200)
		HAL_GPIO_WritePin(CLOCK_1_K_PORT, CLOCK_1_K, SET);

	else if(temp & 0x400)
		HAL_GPIO_WritePin(CLOCK_1_L_PORT, CLOCK_1_L, SET);

	else if(temp & 0x800)
		HAL_GPIO_WritePin(CLOCK_1_M_PORT, CLOCK_1_M, SET);

}

void setLed(uint16_t temp){

	if(temp & 0x01)
		HAL_GPIO_WritePin(CLOCK_1_A_PORT, CLOCK_1_A, RESET);

	else if(temp & 0x02)
		HAL_GPIO_WritePin(CLOCK_1_B_PORT, CLOCK_1_B, RESET);

	else if(temp & 0x04)
		HAL_GPIO_WritePin(CLOCK_1_C_PORT, CLOCK_1_C, RESET);

	else if(temp & 0x08)
		HAL_GPIO_WritePin(CLOCK_1_D_PORT, CLOCK_1_D, RESET);

	else if(temp & 0x10)
		HAL_GPIO_WritePin(CLOCK_1_E_PORT, CLOCK_1_E, RESET);

	else if(temp & 0x20)
		HAL_GPIO_WritePin(CLOCK_1_F_PORT, CLOCK_1_F, RESET);

//	//temp = 0x3f
	else if(temp & 0x40) //true or false?
 		HAL_GPIO_WritePin(CLOCK_1_G_PORT, CLOCK_1_G, RESET);

	else if(temp & 0x80) //what is the value of temp & 0x01 = 0x01 --> TRUE
		HAL_GPIO_WritePin(CLOCK_1_H_PORT, CLOCK_1_H, RESET);

	else if(temp & 0x100)
		HAL_GPIO_WritePin(CLOCK_1_I_PORT, CLOCK_1_I, RESET);

	else if(temp & 0x200)
		HAL_GPIO_WritePin(CLOCK_1_K_PORT, CLOCK_1_K, RESET);

	else if(temp & 0x400)
		HAL_GPIO_WritePin(CLOCK_1_L_PORT, CLOCK_1_L, RESET);

	else if(temp & 0x800)
		HAL_GPIO_WritePin(CLOCK_1_M_PORT, CLOCK_1_M, RESET);

}

void clearAllClock(){
	for(int num = 0; num < NUMBER_OF_ELEMENT ; num++){
		clearLed(clockConversion[num]);
	}

}

void setNumberOnClock(int num){
	if (num >= NUMBER_OF_ELEMENT ) return;
	setLed(clockConversion[num]);
}

void clearNumberOnClock(int num){
	if (num >= NUMBER_OF_ELEMENT ) return;
	clearLed(clockConversion[num]);
}


