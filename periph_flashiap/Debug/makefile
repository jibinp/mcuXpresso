################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include example/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: periph_flashiap.axf

# Tool invocations
periph_flashiap.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/jibin/Desktop/jibin/myWorks/mcuXpresso/lpc_chip_175x_6x/Debug" -L"/home/jibin/Desktop/jibin/myWorks/mcuXpresso/lpc_board_nxp_lpcxpresso_1769/Debug" -Xlinker -Map="periph_flashiap.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "periph_flashiap_Debug.ld" -o "periph_flashiap.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) periph_flashiap.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "periph_flashiap.axf"; # arm-none-eabi-objcopy -v -O binary "periph_flashiap.axf" "periph_flashiap.bin" ; # checksum -p LPC1769 -d "periph_flashiap.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
