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
  ret &= ledInit();

  ret &= usbInit();
  ret &= usbBegin(USB_CDC_MODE);
  ret &= uartOpen(_DEF_UART1, 57600);
  ret &= uartInit();

  return ret;
}

