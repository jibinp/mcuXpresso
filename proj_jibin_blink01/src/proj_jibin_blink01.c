/*
===============================================================================
 Name        : proj_jibin_blink01.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

//Declaring the delay function
void myDelay(uint32_t);

int main(void)
    {
    #if defined (__USE_LPCOPEN)
        // Read clock settings and update SystemCoreClock variable
        SystemCoreClockUpdate();
        #if !defined(NO_BOARD_LIB)
            // Set up and initialize all required blocks and
            // functions related to the board hardware
            Board_Init();
            // Set the LED to the state of "On"
            //   Board_LED_Set(0, true);
        #endif
    #endif

    //Initializing the GPIO pins
    Chip_GPIO_WriteDirBit(LPC_GPIO, 0, 22, true);
    Chip_GPIO_WriteDirBit(LPC_GPIO, 3, 25, true);
    Chip_GPIO_WriteDirBit(LPC_GPIO, 3, 26, true);

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    //Initializing and defining the delay value
    int dlyVl = 6500012/2;
    int dlyVl_1 = 650001/2;

    //Turn offing the LEDs
    Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 1);
    Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 1);
    Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 1);

    // Enter an infinite loop, just incrementing a counter
    while(1)
        {
    	//printf(i);
    	//printf("\n");
        //Turning on the Red LED
        Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 0);
        myDelay(dlyVl);
        //Turning off the Red LED
        Chip_GPIO_WritePortBit(LPC_GPIO, 0, 22, 1);
        myDelay(dlyVl_1);

        //Turning on the Green LED
        Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 0);
        myDelay(dlyVl);
        //Turning off the Green LED
        Chip_GPIO_WritePortBit(LPC_GPIO, 3, 25, 1);
        myDelay(dlyVl_1);

        //Turning on the Blue LED
        Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 0);
        myDelay(dlyVl);
        //Turning off the Blue LED
        Chip_GPIO_WritePortBit(LPC_GPIO, 3, 26, 1);
        myDelay(dlyVl_1);

        i++ ;
        }
    return 0 ;
    }

//Defining the delay function
void myDelay(uint32_t dly)
    {
    for(uint32_t i=0; i<dly; i++);
    }
