/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
CAN_HandleTypeDef hcan;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define ACC 	1
#define NoACC   0


unsigned char TX_DATA[8];
uint8_t  FrameNo=0;
uint8_t RX_DATA[8];
uint32_t RXID,RXDLC=0;
uint8_t Speed;

void CAN_TX(uint32_t ID, uint8_t DLC, uint8_t *payload, uint8_t polling_EN){

	uint8_t no_free_txMailBox=0;
	uint32_t pTxMailbox;
	CAN_TxHeaderTypeDef pHeader;

	pHeader.DLC=DLC;
	pHeader.IDE=CAN_ID_STD;
	pHeader.RTR=CAN_RTR_DATA;
	pHeader.StdId=ID;


	no_free_txMailBox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan);
	/*get the number of the free mailboxes*/

	if(no_free_txMailBox){

		//request a transmission of a new message
		if(HAL_CAN_AddTxMessage(&hcan,&pHeader,payload,&pTxMailbox)  != HAL_OK){

			Error_Handler();
		}

		if(polling_EN)
		{
			//wait until Tx mailboxes is transmitted
			while(HAL_CAN_IsTxMessagePending(&hcan, pTxMailbox));
		}


	}
}

void CAN_RX_Filter_init(uint16_t STD_Filter_ID, uint16_t STD_Filter_MASK){

CAN_FilterTypeDef sFilterConfig;

sFilterConfig.FilterActivation=CAN_FILTER_ENABLE;
sFilterConfig.FilterBank=0;
sFilterConfig.FilterFIFOAssignment=CAN_FILTER_FIFO0;

sFilterConfig.FilterMaskIdLow=0x0000;
sFilterConfig.FilterMaskIdHigh=STD_Filter_MASK<<5;
sFilterConfig.FilterIdHigh=STD_Filter_ID<<5;
sFilterConfig.FilterIdLow=0x0000;

sFilterConfig.FilterMode=CAN_FILTERMODE_IDMASK;
sFilterConfig.FilterScale=CAN_FILTERSCALE_32BIT;


if(HAL_CAN_ConfigFilter(&hcan, &sFilterConfig) != HAL_OK)
	Error_Handler();

}



void CAN_RX(uint32_t* ID, uint32_t *DLC, uint8_t payload[], uint8_t polling_EN){

	CAN_RxHeaderTypeDef pHeader;

	if(polling_EN)
	{
		while(HAL_CAN_GetRxFifoFillLevel(&hcan,CAN_FILTER_FIFO0)==0);
	}

	if(HAL_CAN_GetRxMessage(&hcan,CAN_FILTER_FIFO0,&pHeader,payload) != HAL_OK)
		Error_Handler();

	*ID=pHeader.StdId;
	*DLC=pHeader.DLC;


}


void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef * hcan){

}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef * hcan){

	CAN_RX(&RXID,&RXDLC,RX_DATA,0);
	Speed=RX_DATA[0];
}

void HAL_CAN_ErrorCallback(CAN_HandleTypeDef * hcan){

	if((hcan->ErrorCode & HAL_CAN_ERROR_TX_TERR0) == HAL_CAN_ERROR_TX_TERR0){

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
  MX_CAN_Init();
  /* USER CODE BEGIN 2 */

  CAN_RX_Filter_init(0x3AB, 0x7FF);//rx filter

  if( HAL_CAN_ActivateNotification(&hcan, (CAN_IT_TX_MAILBOX_EMPTY|CAN_IT_RX_FIFO0_MSG_PENDING) ) != HAL_OK)
  {

	  Error_Handler();
  }

  if(HAL_CAN_Start(&hcan) != HAL_OK)
  {

	  Error_Handler();
  }


  TX_DATA[0]=ACC;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  HAL_Delay(1000);
	  CAN_TX(0x030, 1, TX_DATA, 0);
	  TX_DATA[0] ^=1;
    /* USER CODE BEGIN 3 */
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
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */

  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */

  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 1;
  hcan.Init.Mode = CAN_MODE_LOOPBACK;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_6TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_1TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = DISABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = ENABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */

  /* USER CODE END CAN_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
