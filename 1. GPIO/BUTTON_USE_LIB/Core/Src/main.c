/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "button.h"
uint8_t flag=0;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);


void Hold_ButtonHandler1(Button_t* btn, ButtonPressType_t type) {
	if(type == BUTTON_PressType_RepeatOnce) HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
//	else HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}

void Toggle_ButtonHandler1(Button_t* btn, ButtonPressType_t type) {
	switch (type) {
		default:
				HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
				break;
	}
}


void Hold_ButtonHandler10(Button_t* btn, ButtonPressType_t type) {
	if(type == BUTTON_PressType_RepeatOnce) HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
//	else HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}


void Hold_ButtonHandler9(Button_t* btn, ButtonPressType_t type) {
	if(type == BUTTON_PressType_RepeatOnce) HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
//	else HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}



void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  UNUSED(GPIO_Pin);
	if(GPIO_Pin == GPIO_PIN_0)
		flag =1;
}




int main(void)
{

  HAL_Init();

  SystemClock_Config();
	MX_GPIO_Init();
	
	// button 1
	Button_t* btn2 = BUTTON_Init(GPIOA, GPIO_PIN_1, 0, BUTTON_Mode_Toggle, Toggle_ButtonHandler1);
	SetTime_Toggle_mode(btn2, 100, 1000, 2000, 5000);
	Set_DebounceTime(btn2, 50);			

	// button 2
	Button_t* btn1 = BUTTON_Init(GPIOA, GPIO_PIN_0, 0, BUTTON_Mode_Hold, Hold_ButtonHandler1);
	SetTime_Hold_mode(btn1, 1000, 200); 	//	1000 is time to enable REPEAT,  200 time every REPEAT
	Set_DebounceTime(btn1, 30);					// set Debounce time for btn1 10-50(ms)
	
	Button_t* btn3 = BUTTON_Init(GPIOA, GPIO_PIN_1, 0, BUTTON_Mode_Toggle, Toggle_ButtonHandler1);
	SetTime_Toggle_mode(btn3, 100, 1000, 2000, 5000);
	Set_DebounceTime(btn3, 50);	
	Button_t* btn4 = BUTTON_Init(GPIOA, GPIO_PIN_2, 0, BUTTON_Mode_Toggle, Toggle_ButtonHandler1);
	SetTime_Toggle_mode(btn4, 100, 1000, 2000, 5000);
	Set_DebounceTime(btn4, 50);	
	Button_t* btn5 = BUTTON_Init(GPIOA, GPIO_PIN_3, 0, BUTTON_Mode_Toggle, Toggle_ButtonHandler1);
	
	Button_t* btn6 = BUTTON_Init(GPIOA, GPIO_PIN_4, 0, BUTTON_Mode_Toggle, Toggle_ButtonHandler1);
	Button_t* btn7 = BUTTON_Init(GPIOA, GPIO_PIN_5, 0, BUTTON_Mode_Toggle, Toggle_ButtonHandler1);
	Button_t* btn8 = BUTTON_Init(GPIOA, GPIO_PIN_6, 0, BUTTON_Mode_Toggle, Toggle_ButtonHandler1);
	Button_t* btn9 = BUTTON_Init(GPIOA, GPIO_PIN_7, 0, BUTTON_Mode_Toggle, Toggle_ButtonHandler1);
	Button_t* btn10 = BUTTON_Init(GPIOA, GPIO_PIN_8, 0, BUTTON_Mode_Toggle, Toggle_ButtonHandler1);
	
	
	


  while (1)
  {
    if (flag) {
        BUTTON_Update();
        flag = 0;     
    }
  }
 
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
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
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
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
