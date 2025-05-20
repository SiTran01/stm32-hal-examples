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


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */


uint8_t flag=0;
uint8_t count1=0;
uint8_t count2=0;
uint8_t count3=0;
uint8_t count4=0;
uint8_t count5=0;

void ButtonCallback(Button_t* btn, ButtonPressType_t type) {
	switch (type) {
		case BUTTON_PressType_Double:
				count1+=10;
				break;
		case BUTTON_PressType_OnPressed:
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET); // ví d?: toggle dèn
				flag = 1;
				count1++;
				break;
		case BUTTON_PressType_Normal:
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET); // ví d?: toggle dèn
				flag = 2;
				count2++;
				break;
		case BUTTON_PressType_Long:
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
				flag = 3;
				count3++;
				// X? lý nh?n gi?
				break;
		case BUTTON_PressType_VeryLong:
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
				flag = 4;
				count4++;
				// X? lý nh?n gi?
				break;
		default:
				break;
		
	}
}

void ButtonCallback3(Button_t* btn, ButtonPressType_t type) {
	if(type == BUTTON_PressType_RepeatOnce) count5++;
	else count1++;
}

void ButtonCallback1(Button_t* btn, ButtonPressType_t type) {
//	switch (type) {
//		case BUTTON_PressType_OnPressed:
//				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET); // ví d?: toggle dèn
//				flag = 1;
//				count1++;
//				break;
//		case BUTTON_PressType_Normal:
//				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET); // ví d?: toggle dèn
//				flag = 2; 
//				count2++;
//				break;
//		case BUTTON_PressType_Long:
//				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
//				flag = 3;
//				count3++;
//				// X? lý nh?n gi?
//				break;
//		case BUTTON_PressType_VeryLong:
//				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
//				flag = 4;
//				count4++;
//				// X? lý nh?n gi?
//				break;
//		case BUTTON_PressType_RepeatOnce:
//				HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
//        count5++;
//        break;
//    case BUTTON_PressType_Repeat:
//				HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
//        count5++;
//        break;
////		default:
////				HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
////        count5++;
////				break;
//		
//	}
		if(type == BUTTON_PressType_RepeatOnce) count5++;
		
}


void BUTTON_Callback(Button_t* btn, ButtonPressType_t type)
{
	count5++;
    // M?c d?nh không làm gì
}


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
	
	
	Button_t* btn1 = BUTTON_Init(GPIOA, GPIO_PIN_0, 0, BUTTON_Mode_Click, ButtonCallback);
	SetTime_Click_mode(btn1, 200, 1000, 1500, 2000);

	
	Button_t* btn2 = BUTTON_Init(GPIOA, GPIO_PIN_1, 0, BUTTON_Mode_Hold, ButtonCallback3);
	SetTime_Hold_mode(btn2, 1000, 1000);
	


  while (1)
  {
    BUTTON_Update();
//		if(count4 == 2){
//			BUTTON_Deinit(btn2);
//			btn2 = NULL;
//		}else if(count4 == 4)
//		{
//			btn2 = BUTTON_Init(GPIOA, GPIO_PIN_1, 0, BUTTON_Mode_Hold, ButtonCallback3);
//			SetTime_Hold_mode(btn2, 1000, 500);
//		}
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

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
