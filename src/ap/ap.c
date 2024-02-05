/*
 * ap.c
 *
 *  Created on: Feb 2, 2024
 *      Author: mm940
 */
#include "ap.h"

/* for duration blink*/
/*
static uint32_t g_LEDOnTime = 1000;
static uint32_t g_LEDOffTime = 200;
static uint32_t nextmill = 0;
*/

void apInit(void)
{
  uartOpen(_DEF_UART2, 115200);
}

void apMain(void)
{
  uint32_t pre_time = millis();
  while(1)
  {
    /* LED Non blocking toggle*/
    /* Using Reg to toggle */
    if(millis()-pre_time >= 500)
    {
      pre_time = millis();
      //ledToggle(_DEF_LED1);
      gpio_out_toggle(GPIOA, GPIO_PIN_5);
    }
    /* LED On Off - by time*/
    /*
    bool blinkOn = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);
    if(blinkOn && millis() > nextmill)
    {
      ledOff(_DEF_LED1);
      blinkOn = false;
      nextmill = millis() + g_LEDOffTime;
    }
    else if(!blinkOn && millis() > nextmill)
    {
      ledOn(_DEF_LED1);
      blinkOn = true;
      nextmill = millis() + g_LEDOnTime;
    }
    */
    if (uartAvailable(_DEF_UART2) > 0)
    {
      uint8_t rx_data;
      // 데이터를 읽어온다
      rx_data = uartRead(_DEF_UART2);

      uartPrintf(_DEF_UART2, "Rx : 0x%d\n", rx_data);
    }
  }
}

