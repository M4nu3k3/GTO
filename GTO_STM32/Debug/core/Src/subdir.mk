################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../core/Src/bouton.c \
../core/Src/config.c \
../core/Src/deep.c \
../core/Src/dma.c \
../core/Src/eleves.c \
../core/Src/fonts.c \
../core/Src/fonts_8x12.c \
../core/Src/gto.c \
../core/Src/led.c \
../core/Src/main.c \
../core/Src/matieres.c \
../core/Src/notesmath.c \
../core/Src/spi.c \
../core/Src/st7789v.c \
../core/Src/stm32g4xx_hal_msp.c \
../core/Src/stm32g4xx_it.c \
../core/Src/syscalls.c \
../core/Src/sysmem.c \
../core/Src/system_stm32g4xx.c 

OBJS += \
./core/Src/bouton.o \
./core/Src/config.o \
./core/Src/deep.o \
./core/Src/dma.o \
./core/Src/eleves.o \
./core/Src/fonts.o \
./core/Src/fonts_8x12.o \
./core/Src/gto.o \
./core/Src/led.o \
./core/Src/main.o \
./core/Src/matieres.o \
./core/Src/notesmath.o \
./core/Src/spi.o \
./core/Src/st7789v.o \
./core/Src/stm32g4xx_hal_msp.o \
./core/Src/stm32g4xx_it.o \
./core/Src/syscalls.o \
./core/Src/sysmem.o \
./core/Src/system_stm32g4xx.o 

C_DEPS += \
./core/Src/bouton.d \
./core/Src/config.d \
./core/Src/deep.d \
./core/Src/dma.d \
./core/Src/eleves.d \
./core/Src/fonts.d \
./core/Src/fonts_8x12.d \
./core/Src/gto.d \
./core/Src/led.d \
./core/Src/main.d \
./core/Src/matieres.d \
./core/Src/notesmath.d \
./core/Src/spi.d \
./core/Src/st7789v.d \
./core/Src/stm32g4xx_hal_msp.d \
./core/Src/stm32g4xx_it.d \
./core/Src/syscalls.d \
./core/Src/sysmem.d \
./core/Src/system_stm32g4xx.d 


# Each subdirectory must supply rules for building sources it contributes
core/Src/%.o core/Src/%.su core/Src/%.cyclo: ../core/Src/%.c core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../core/Inc -I../drivers/stm32g4xx_hal/Inc -I../drivers/stm32g4xx_hal/Inc/Legacy -I../drivers/cmsis/Device/ST/STM32G4xx/Include -I../drivers/cmsis/Include -I../app -I../drivers/bsp -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-core-2f-Src

clean-core-2f-Src:
	-$(RM) ./core/Src/bouton.cyclo ./core/Src/bouton.d ./core/Src/bouton.o ./core/Src/bouton.su ./core/Src/config.cyclo ./core/Src/config.d ./core/Src/config.o ./core/Src/config.su ./core/Src/deep.cyclo ./core/Src/deep.d ./core/Src/deep.o ./core/Src/deep.su ./core/Src/dma.cyclo ./core/Src/dma.d ./core/Src/dma.o ./core/Src/dma.su ./core/Src/eleves.cyclo ./core/Src/eleves.d ./core/Src/eleves.o ./core/Src/eleves.su ./core/Src/fonts.cyclo ./core/Src/fonts.d ./core/Src/fonts.o ./core/Src/fonts.su ./core/Src/fonts_8x12.cyclo ./core/Src/fonts_8x12.d ./core/Src/fonts_8x12.o ./core/Src/fonts_8x12.su ./core/Src/gto.cyclo ./core/Src/gto.d ./core/Src/gto.o ./core/Src/gto.su ./core/Src/led.cyclo ./core/Src/led.d ./core/Src/led.o ./core/Src/led.su ./core/Src/main.cyclo ./core/Src/main.d ./core/Src/main.o ./core/Src/main.su ./core/Src/matieres.cyclo ./core/Src/matieres.d ./core/Src/matieres.o ./core/Src/matieres.su ./core/Src/notesmath.cyclo ./core/Src/notesmath.d ./core/Src/notesmath.o ./core/Src/notesmath.su ./core/Src/spi.cyclo ./core/Src/spi.d ./core/Src/spi.o ./core/Src/spi.su ./core/Src/st7789v.cyclo ./core/Src/st7789v.d ./core/Src/st7789v.o ./core/Src/st7789v.su ./core/Src/stm32g4xx_hal_msp.cyclo ./core/Src/stm32g4xx_hal_msp.d ./core/Src/stm32g4xx_hal_msp.o ./core/Src/stm32g4xx_hal_msp.su ./core/Src/stm32g4xx_it.cyclo ./core/Src/stm32g4xx_it.d ./core/Src/stm32g4xx_it.o ./core/Src/stm32g4xx_it.su ./core/Src/syscalls.cyclo ./core/Src/syscalls.d ./core/Src/syscalls.o ./core/Src/syscalls.su ./core/Src/sysmem.cyclo ./core/Src/sysmem.d ./core/Src/sysmem.o ./core/Src/sysmem.su ./core/Src/system_stm32g4xx.cyclo ./core/Src/system_stm32g4xx.d ./core/Src/system_stm32g4xx.o ./core/Src/system_stm32g4xx.su

.PHONY: clean-core-2f-Src

