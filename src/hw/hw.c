/*
 * hw.c
 *
 *  Created on: Feb 2, 2024
 *      Author: mm940
 */
#include "hw.h"
button_event_t btn_evt;

bool hwInit(void)
{
  bool ret = true;

  ret &= bspInit();
  ret &= rtcInit();
  ret &= swtimerInit();
#ifdef _USE_HW_RESET
  ret &= resetInit();
#endif
#ifdef _USE_HW_RESET
  if (resetGetCount() == 2)
  {
    // Jump To SystemBootloader
    resetToSystemBoot();
  }
#endif
  ret &= flashInit();
  ret &= buttonInit();
  ret &= buttonEventInit(&btn_evt, 5);
  ret &= ledInit();
  ret &= usbInit();
  ret &= usbBegin(USB_CDC_MODE);
  ret &= uartInit();
  ret &= logInit();
  ret &= cliInit();
  /* Reset Test */
  uartPrintf(_DEF_UART1, "Reset Count : %d\n", resetGetCount());
  return ret;
}

