/*
 * bsp.c
 *
 *  Created on: Feb 2, 2024
 *      Author: mm940
 */
#include "bsp.h"
#include "usb_device.h"

void SystemClock_Config(void);

bool bspInit(void)
{
  __HAL_RCC_SYSCFG_CLK_ENABLE();


  HAL_Init();
  SystemClock_Config();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* USB - RESET 시 장치관리자 해제 연결 안될 시 */

  GPIO_InitTypeDef GPIO_InitStructure = {0, };
  // PA12(USB_DP) 출력 설정
  GPIO_InitStructure.Pin = GPIO_PIN_12;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

  //회로에 PULL UP 이 걸려있다면 - 내리고
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
  delay(100);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);

  // INPUT 으로 다시 변경
  GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

  MX_USB_Device_Init();

  return true;
}

void delay(uint32_t time_ms)
{
  HAL_Delay(time_ms);
}

uint32_t millis(void)
{
  return HAL_GetTick();
}


void SystemClock_Config(void)
{

  __HAL_RCC_GPIOC_CLK_ENABLE();

  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV2;
  RCC_OscInitStruct.PLL.PLLN = 8;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}


void Error_Handler(void)
{

}
