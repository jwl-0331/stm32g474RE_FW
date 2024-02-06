/*
 * hw.c
 *
 *  Created on: Feb 2, 2024
 *      Author: mm940
 */
#include "hw.h"

bool hwInit(void)
{
  bool ret = true;

  ret &= bspInit();
  ret &= rtcInit();
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
  ret &= ledInit();
  ret &= usbInit();
  ret &= usbBegin(USB_CDC_MODE);
  ret &= uartInit();
  ret &= uartOpen(_DEF_UART1, 115200);

  /* Reset Test */
  uartPrintf(_DEF_UART1, "Reset Count : %d\n", resetGetCount());
  return ret;
}

