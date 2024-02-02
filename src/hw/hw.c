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

  return ret;
}

