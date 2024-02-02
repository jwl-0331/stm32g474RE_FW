/*
 * led.c
 *
 *  Created on: Feb 2, 2024
 *      Author: mm940
 */

#include "led.h"

// Using Reg to Control LED
// LED periph uses APB2
// APB2PEIPH_BASE = PEIPH_BASE(0x40000000UL) + 0x00010000UL , 0x4001 0000
// 0x4001 0000 -  0x4001 6400 (APB2 - start)
// GPIOA -> 0x4800 0000 - 0x4800 03FF  size : 0x400
// #define GPIOA_BASE            (AHB2PERIPH_BASE + 0x0000UL)
// Using ODR reg to control
//#define GPIOA_BASE (APB2PERIPH_BASE+ 0x07FF)
typedef struct
{
  GPIO_TypeDef  *port;
  uint16_t    pin;
  GPIO_PinState on_state;
  GPIO_PinState off_state;
} led_table_t;

static const led_table_t led_tbl[LED_MAX_CH] =
{
    {GPIOA, GPIO_PIN_5, GPIO_PIN_SET, GPIO_PIN_RESET},
};




bool ledInit(void)
{
  GPIO_InitTypeDef GPIO_InitStructure = {0, };

  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;

  for (int i=0; i<LED_MAX_CH; i++)
  {
    GPIO_InitStructure.Pin = led_tbl[i].pin;
    HAL_GPIO_Init(led_tbl[i].port, &GPIO_InitStructure);

    ledOff(i);
  }
  return true;
}


void ledOn(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].on_state);
}

void ledOff(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, led_tbl[ch].off_state);
}

void ledToggle(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  HAL_GPIO_TogglePin(led_tbl[ch].port, led_tbl[ch].pin);
}

//#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
void gpio_on(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  GPIO_TypeDef *gpio = (void*)GPIOA_BASE;
  gpio->ODR |= GPIO_Pin;
}

void gpio_off(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  GPIO_TypeDef *gpio = (void*)GPIOA_BASE;
  gpio->ODR &= ~(GPIO_Pin);
}

//
void gpio_out_toggle(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  GPIO_TypeDef *gpio = (void*)GPIOA_BASE;
  gpio->ODR ^= GPIO_Pin;
}
