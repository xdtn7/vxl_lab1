/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//---------------------------------------

//Exercise 1

//---------------------------------------

void exercise_1 () {
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_5, GPIO_PIN_RESET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_6, GPIO_PIN_SET) ;
	  HAL_Delay (2000) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_5, GPIO_PIN_SET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_6, GPIO_PIN_RESET) ;
	  HAL_Delay (2000) ;

}

//---------------------------------------

//Exercise 2

//---------------------------------------


void exercise_2 () {
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_5, GPIO_PIN_RESET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_6, GPIO_PIN_SET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_7, GPIO_PIN_SET) ;
	  HAL_Delay (5000) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_5, GPIO_PIN_SET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_7, GPIO_PIN_RESET) ;
	  HAL_Delay (3000) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_6, GPIO_PIN_RESET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_7, GPIO_PIN_SET) ;
	  HAL_Delay (2000) ;

}

//---------------------------------------

//Exercise 3

//---------------------------------------


void exercise_3 (){
	  //RED1
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_5, GPIO_PIN_RESET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_6, GPIO_PIN_SET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_7, GPIO_PIN_SET) ;
	  //GREEN2
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_8, GPIO_PIN_SET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_9, GPIO_PIN_SET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_10, GPIO_PIN_RESET) ;

	  HAL_Delay (3000) ;
	  //YELLOW2
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_9, GPIO_PIN_RESET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_10, GPIO_PIN_SET) ;

	  HAL_Delay (2000) ;
	  //RED2
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_8, GPIO_PIN_RESET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_9, GPIO_PIN_SET) ;
	  //GREEN1
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_5, GPIO_PIN_SET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_7, GPIO_PIN_RESET) ;

	  HAL_Delay (2000) ;
	  //YELLOW1
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_6, GPIO_PIN_RESET) ;
	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_7, GPIO_PIN_SET) ;
	  HAL_Delay (3000) ;
}

//---------------------------------------

//Exercise 4

//---------------------------------------


uint8_t counter = 0;
uint8_t valueToDisplay = 0;
uint8_t value1 = 0;
uint8_t value2 = 0;

void exercise_4 (){
	  valueToDisplay = (valueToDisplay + 1) % 10;
	  display7SEG(valueToDisplay);
	  HAL_Delay(1000);

}

//---------------------------------------

//Exercise 5

//---------------------------------------


void exercise_5 (){
	  //Init
	  const uint8_t TRAFFIC_LIGHT_MAX[3] = {5, 3, 2}; //RED, GREEN, YELLOW

	  counter = 0;

	  uint8_t state1 = 0; //RED
	  value1 = TRAFFIC_LIGHT_MAX[state1]+1;
	  update_light_led_buffer(state1, 0);

	  uint8_t state2 = 1; //GREEN
	  value2 = TRAFFIC_LIGHT_MAX[state2]+1;
	  update_light_led_buffer(state2, 1);

	  //Loop
	  while(1){

		  if(counter == 0){
			  value1--;
			  value2--;
			  if(!value1) {
				  state1 = (state1+1)%3;
				  value1 = TRAFFIC_LIGHT_MAX[state1];
				  update_light_led_buffer(state1, 0);

			  }
			  if(!value2) {
				  state2 = (state2+1)%3;
				  value2 = TRAFFIC_LIGHT_MAX[state2];
				  update_light_led_buffer(state2, 1);

			  }
			  if(!update_seven_segment_led_buffer(value1, 0) ||
					  !update_seven_segment_led_buffer(value2, 1))
				  printf("ERROR DETECTED");


		  }
		  else {
			  seven_segment_led_driver();
			  transport_light_led_driver();

		  }
		  HAL_Delay(10);
		  counter = (counter+1)%100;
	  }

 }

//---------------------------------------

//Exercise 10

//---------------------------------------


void exercise_10 (){
	  uint8_t HRS_MAX = 12;
	  uint8_t MIN_MAX = 60;
	  uint8_t SEC_MAX = 60;
	  uint8_t HRS = 0;
	  uint8_t MIN = 59;
	  uint8_t SEC = 10;
	  uint8_t NUMBER_OF_LEDS = 12;

	  clearAllClock();
	  setNumberOnClock(SEC / (SEC_MAX / NUMBER_OF_LEDS) );
	  setNumberOnClock(MIN / (MIN_MAX / NUMBER_OF_LEDS) );

	  while(1){
		  //UPDATE SECOND
		  clearNumberOnClock(SEC / (SEC_MAX / NUMBER_OF_LEDS) );
		  SEC = (SEC+1) % SEC_MAX;
		  setNumberOnClock(SEC / (SEC_MAX / NUMBER_OF_LEDS) );

		  //UPDATE MINUTE
		  if(!SEC) {
			  clearNumberOnClock(MIN / (MIN_MAX / NUMBER_OF_LEDS) );
			  MIN = (MIN+1) % MIN_MAX;
			  setNumberOnClock(MIN / (MIN_MAX / NUMBER_OF_LEDS) );
			  if(!MIN) {
			  			  clearNumberOnClock(HRS );
			  			  HRS = (HRS+1) % HRS_MAX;
			  			  setNumberOnClock(HRS );
			  }
			  else setNumberOnClock(HRS );
		  }
		  else {
			  setNumberOnClock(MIN / (MIN_MAX / NUMBER_OF_LEDS) );
			  setNumberOnClock(HRS );
		  }



		  HAL_Delay(50);
	  }

	  //test
	  while(0){
		  for(int i=0; i< 12; i++){
			  setNumberOnClock(i);
			  HAL_Delay(500);
		  }
	  }
	  while(0){

		  //UPDATE SECOND
		  clearNumberOnClock(SEC / (SEC_MAX / NUMBER_OF_LEDS) );
		  SEC = (SEC+1) % SEC_MAX;
		  setNumberOnClock(SEC / (SEC_MAX / NUMBER_OF_LEDS) );

		  //UPDATE MINUTE
		  if(!SEC) {
			  clearNumberOnClock(MIN / (MIN_MAX / NUMBER_OF_LEDS) );
			  MIN = (MIN+1) % MIN_MAX;
			  setNumberOnClock(MIN / (MIN_MAX / NUMBER_OF_LEDS) );
		  }
		  else setNumberOnClock(MIN / (MIN_MAX / NUMBER_OF_LEDS) );

		  //UPDATE HOUR
		  if(!MIN) {
			  clearNumberOnClock(HRS );
			  HRS = (HRS+1) % HRS_MAX;
			  setNumberOnClock(HRS );
		  }
		  else setNumberOnClock(HRS );

		  HAL_Delay(500);
	  }
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  exercise_10();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA3 PA4 PA5 PA6
                           PA7 PA8 PA9 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10
                           PB11 PB12 PB13 PB3
                           PB4 PB5 PB6 PB7
                           PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
                          |GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
