/*
 * reset.c
 *
 *  Created on: Feb 5, 2024
 *      Author: mm940
 */

#include "reset.h"
#include "rtc.h"
#ifdef _USE_HW_RESET


static uint32_t reset_count = 0;
static uint32_t run_timeout_count = 0;

static void resetToRunBoot(void);



void resetISR(void)
{
  if (run_timeout_count > 0)
  {
    run_timeout_count--;

    if (run_timeout_count == 0)
    {
      resetToRunBoot();
    }
  }
}


bool resetInit(void)
{
  bool ret = true;
  bool is_debug = false;

#if 1
  // 만약 디버거가 연결된 경우
  if (CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk)
  {
    is_debug = true;
  }

  // 만약 Reset 핀이 눌렸다면
  // 리셋 상태 레지스터 자기자신 + 1 을 준다.
  // 500ms 안에 여러번 누른경우 reset_count 값에 저장된다.
  if (RCC->CSR & (1<<26) && is_debug != true)
  {
    rtcBackupRegWrite(RESET_REG_COUNT, rtcBackupRegRead(RESET_REG_COUNT) + 1);
    delay(500);
    reset_count = rtcBackupRegRead(RESET_REG_COUNT);
  }
  //clear 다시 0으로
  rtcBackupRegWrite(RESET_REG_COUNT, 0);
#endif

  return ret;
}

uint32_t resetGetCount(void)
{
  return reset_count;
}

void resetToBoot(uint32_t timeout)
{
  if (timeout == 0)
  {
    resetToRunBoot();
  }
  else
  {
    run_timeout_count = timeout;
  }
}

void resetToSystemBoot(void)
{
  void (*SysMemBootJump)(void);
  volatile uint32_t addr = 0x1FFF0000; // System Boot Loader 주소


  HAL_RCC_DeInit();

  SysTick->CTRL = 0;
  SysTick->LOAD = 0;
  SysTick->VAL  = 0;

  // 인터럽트
  for (int i=0;i<8;i++)
  {
    NVIC->ICER[i]=0xFFFFFFFF;
    NVIC->ICPR[i]=0xFFFFFFFF;
    __DSB();
    __ISB();
  }

  SysMemBootJump = (void (*)(void)) (*((uint32_t *)(addr + 4)));

  // Main Stack 주소 셋팅
  __set_MSP(*(uint32_t *)addr);
  // Jump
  SysMemBootJump();
}


void resetToRunBoot(void)
{
  uint32_t reg;

  reg = rtcBackupRegRead(RESET_REG_PARAM);

  reg |= (1<<0);
  rtcBackupRegWrite(RESET_REG_PARAM, reg);
  NVIC_SystemReset();
}

#endif

