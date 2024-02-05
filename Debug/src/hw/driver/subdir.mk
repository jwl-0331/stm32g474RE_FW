################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/driver/cdc.c \
../src/hw/driver/led.c \
../src/hw/driver/uart.c \
../src/hw/driver/usb.c 

OBJS += \
./src/hw/driver/cdc.o \
./src/hw/driver/led.o \
./src/hw/driver/uart.o \
./src/hw/driver/usb.o 

C_DEPS += \
./src/hw/driver/cdc.d \
./src/hw/driver/led.d \
./src/hw/driver/uart.d \
./src/hw/driver/usb.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/driver/%.o src/hw/driver/%.su src/hw/driver/%.cyclo: ../src/hw/driver/%.c src/hw/driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32G474xx -c -I"C:/CubeWorspace/stm32g474_fw/src" -I"C:/CubeWorspace/stm32g474_fw/src/common/core" -I"C:/CubeWorspace/stm32g474_fw/src/lib/cube_g474/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/CubeWorspace/stm32g474_fw/src/lib/cube_g474/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/CubeWorspace/stm32g474_fw/src/lib/cube_g474/USB_Device/App" -I"C:/CubeWorspace/stm32g474_fw/src/lib/cube_g474/USB_Device/Target" -I"C:/CubeWorspace/stm32g474_fw/src/common/include" -I"C:/CubeWorspace/stm32g474_fw/src/lib/cube_g474/Drivers/CMSIS/Device/ST/STM32G4xx/Include" -I"C:/CubeWorspace/stm32g474_fw/src/lib/cube_g474/Drivers/CMSIS/Include" -I"C:/CubeWorspace/stm32g474_fw/src/lib/cube_g474/Drivers/STM32G4xx_HAL_Driver/Inc" -I"C:/CubeWorspace/stm32g474_fw/src/ap" -I"C:/CubeWorspace/stm32g474_fw/src/bsp" -I"C:/CubeWorspace/stm32g474_fw/src/common" -I"C:/CubeWorspace/stm32g474_fw/src/hw" -I"C:/CubeWorspace/stm32g474_fw/src/lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src-2f-hw-2f-driver

clean-src-2f-hw-2f-driver:
	-$(RM) ./src/hw/driver/cdc.cyclo ./src/hw/driver/cdc.d ./src/hw/driver/cdc.o ./src/hw/driver/cdc.su ./src/hw/driver/led.cyclo ./src/hw/driver/led.d ./src/hw/driver/led.o ./src/hw/driver/led.su ./src/hw/driver/uart.cyclo ./src/hw/driver/uart.d ./src/hw/driver/uart.o ./src/hw/driver/uart.su ./src/hw/driver/usb.cyclo ./src/hw/driver/usb.d ./src/hw/driver/usb.o ./src/hw/driver/usb.su

.PHONY: clean-src-2f-hw-2f-driver

