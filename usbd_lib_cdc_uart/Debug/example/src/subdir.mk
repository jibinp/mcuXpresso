################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../example/src/cdc_desc.c \
../example/src/cdc_main.c \
../example/src/cdc_uart.c \
../example/src/cr_startup_lpc175x_6x.c \
../example/src/sysinit.c 

OBJS += \
./example/src/cdc_desc.o \
./example/src/cdc_main.o \
./example/src/cdc_uart.o \
./example/src/cr_startup_lpc175x_6x.o \
./example/src/sysinit.o 

C_DEPS += \
./example/src/cdc_desc.d \
./example/src/cdc_main.d \
./example/src/cdc_uart.d \
./example/src/cr_startup_lpc175x_6x.d \
./example/src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
example/src/%.o: ../example/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M3 -I"/home/jibin/Desktop/jibin/myWorks/mcuXpresso/lpc_chip_175x_6x/inc" -I"/home/jibin/Desktop/jibin/myWorks/mcuXpresso/lpc_board_nxp_lpcxpresso_1769/inc" -I"/home/jibin/Desktop/jibin/myWorks/mcuXpresso/usbd_lib_cdc_uart/example/inc" -I"/home/jibin/Desktop/jibin/myWorks/mcuXpresso/lpc_chip_175x_6x/inc/usbd" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

