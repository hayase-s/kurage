################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc.c \
../Src/aqm1248a.c \
../Src/font.c \
../Src/gpio.c \
../Src/main.c \
../Src/mode.c \
../Src/myassign.c \
../Src/spi.c \
../Src/stm32f3xx_hal_msp.c \
../Src/stm32f3xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f3xx.c \
../Src/tim.c \
../Src/usart.c 

OBJS += \
./Src/adc.o \
./Src/aqm1248a.o \
./Src/font.o \
./Src/gpio.o \
./Src/main.o \
./Src/mode.o \
./Src/myassign.o \
./Src/spi.o \
./Src/stm32f3xx_hal_msp.o \
./Src/stm32f3xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f3xx.o \
./Src/tim.o \
./Src/usart.o 

C_DEPS += \
./Src/adc.d \
./Src/aqm1248a.d \
./Src/font.d \
./Src/gpio.d \
./Src/main.d \
./Src/mode.d \
./Src/myassign.d \
./Src/spi.d \
./Src/stm32f3xx_hal_msp.d \
./Src/stm32f3xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f3xx.d \
./Src/tim.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F303x8 -I"/Users/kanako/Desktop/Mice/first/first/Inc" -I"/Users/kanako/Desktop/Mice/first/first/Drivers/STM32F3xx_HAL_Driver/Inc" -I"/Users/kanako/Desktop/Mice/first/first/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"/Users/kanako/Desktop/Mice/first/first/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"/Users/kanako/Desktop/Mice/first/first/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


