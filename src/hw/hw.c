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
  ret &= swtimerInit();


#ifdef _USE_HW_RESET
  ret &= resetInit();  // 500 ms delay
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
  ret &= logInit();
  ret &= cliInit();
  return ret;
}
