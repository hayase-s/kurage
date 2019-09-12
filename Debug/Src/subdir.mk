################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AD.c \
../Src/Traacceleration.c \
../Src/adc.c \
../Src/aqm1248a.c \
../Src/buzzer.c \
../Src/dma.c \
../Src/font.c \
../Src/gpio.c \
../Src/hidarite.c \
../Src/main.c \
../Src/map.c \
../Src/mode.c \
../Src/modeselect.c \
../Src/motor.c \
../Src/myassign.c \
../Src/spi.c \
../Src/stm32f3xx_hal_msp.c \
../Src/stm32f3xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f3xx.c \
../Src/tim.c \
../Src/turn.c \
../Src/usart.c \
../Src/wall.c 

OBJS += \
./Src/AD.o \
./Src/Traacceleration.o \
./Src/adc.o \
./Src/aqm1248a.o \
./Src/buzzer.o \
./Src/dma.o \
./Src/font.o \
./Src/gpio.o \
./Src/hidarite.o \
./Src/main.o \
./Src/map.o \
./Src/mode.o \
./Src/modeselect.o \
./Src/motor.o \
./Src/myassign.o \
./Src/spi.o \
./Src/stm32f3xx_hal_msp.o \
./Src/stm32f3xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f3xx.o \
./Src/tim.o \
./Src/turn.o \
./Src/usart.o \
./Src/wall.o 

C_DEPS += \
./Src/AD.d \
./Src/Traacceleration.d \
./Src/adc.d \
./Src/aqm1248a.d \
./Src/buzzer.d \
./Src/dma.d \
./Src/font.d \
./Src/gpio.d \
./Src/hidarite.d \
./Src/main.d \
./Src/map.d \
./Src/mode.d \
./Src/modeselect.d \
./Src/motor.d \
./Src/myassign.d \
./Src/spi.d \
./Src/stm32f3xx_hal_msp.d \
./Src/stm32f3xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f3xx.d \
./Src/tim.d \
./Src/turn.d \
./Src/usart.d \
./Src/wall.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F303x8 -I"/Users/kanako/git/kurage/Inc" -I"/Users/kanako/git/kurage/Drivers/STM32F3xx_HAL_Driver/Inc" -I"/Users/kanako/git/kurage/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"/Users/kanako/git/kurage/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"/Users/kanako/git/kurage/Drivers/CMSIS/Include"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


