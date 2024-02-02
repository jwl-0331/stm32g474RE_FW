/*
 * ap.c
 *
 *  Created on: Feb 2, 2024
 *      Author: mm940
 */
#include "ap.h"


static uint32_t g_LEDOnTime = 1000;
static uint32_t g_LEDOffTime = 200;
static uint32_t nextmill = 0;
void apInit(void)
{

}

void apMain(void)
{

  //uint32_t pre_time = millis();
  while(1)
  {
    /* LED Non blocking toggle*/
    /*
    if(millis()-pre_time >= 500)
    {
      pre_time = millis();
      ledToggle(_DEF_LED1);
    }
    */

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
  }
}

