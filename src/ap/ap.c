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
  uartOpen(_DEF_UART1, 115200);
  //cliOpen(_DEF_UART1, 115200);
}

void apMain(void)
{
  /* Reset Test */
  uartPrintf(_DEF_UART1, "Reset Count : %d\n", resetGetCount());
  logPrintf("log Test\n");
  uint32_t pre_time1 = millis();
  uint32_t pre_time2 = millis();
  while(1)
  {
    /* LED Non blocking toggle*/
    /* Using Reg to toggle */
    /*
    if(millis()-pre_time1 >= 500)
    {
      pre_time1 = millis();
      //ledToggle(_DEF_LED1);
      gpio_out_toggle(GPIOA, GPIO_PIN_5);
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
    /* UART TEST*/
    /*
    if (uartAvailable(_DEF_UART1) > 0)
    {
      uint8_t rx_data;
      // 데이터를 읽어온다
      rx_data = uartRead(_DEF_UART1);

      uartPrintf(_DEF_UART1, "Rx : 0x%X, %c\n", rx_data, rx_data);
    }
    */

    /* FLASH Test*/
    /*
    if(uartAvailable(_DEF_UART1) > 0)
    {
      int8_t rx_data;

      rx_data = uartRead(_DEF_UART1);
      // read
      if(rx_data == '1')
      {
        uint32_t buf[12];
        uartPrintf(_DEF_UART1, "Read...\n");
        flashRead(0x08000000 + (1024*60), &buf[0], 12);
        for(int i=0; i<12; i++)
        {
          uartPrintf(_DEF_UART1, "0x%X : 0x%X\n", 0x08000000 + (1024*60) + i, buf[i]);
        }
      }
      //erase - flash 특성상 지우면 0xffff , erase 특정 구간에서 erase fail 이유 ?
      if(rx_data == '2')
      {
        uartPrintf(_DEF_UART1,"Erase...\n");
        //지우고자하는 시작 주소 , length
        //if(flashErase(0x8000000 + (1024 * 60), 12) == true)
        //if(flashErase(0x08000000, 12) == true)
        if(flashErase(0x8000000 + (1024 * 60), 12) == true)
        {
          uartPrintf(_DEF_UART1,"Erase OK\n");
        }
        else
        {
          uartPrintf(_DEF_UART1,"Erase Fail\n");
        }
      }
      // write
      if(rx_data == '3')
      {
        uint8_t buf[32];


        for(int i =0; i < 32; i++)
        {
          buf[i] = i;
        }

        uartPrintf(_DEF_UART1,"Write...\n");

        if(flashWrite(0x8000000 + (60*1024), buf, 32) == true)
        {
          uartPrintf(_DEF_UART1,"Write OK\n");
        }
        else
        {
          uartPrintf(_DEF_UART1,"Write Fail\n");
        }
      }
    }
    */
    //cliMain();

  }
}

