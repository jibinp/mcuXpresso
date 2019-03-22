/*
===============================================================================
 Name        : proj_jibin_freertosBlink01.c
 Author      : $(jibin)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "board.h"
#include "FreeRTOS.h"
#include "task.h"

static void prvSetupHardware(void)
	{
	SystemCoreClockUpdate();
	Board_Init();

    //At the start all the leds are off
	Board_LED_Set(0, false);
	Board_LED_Set(1, false);
	Board_LED_Set(2, false);
	}

/*
  Task 1 defining.
  Trun on RED Led and then turn off the same.
  In this time both GREEN and BLUE Led is turned off
*/
static void redLEDTask(void *pvParameters)
	{
	while (1)
		{
		Board_LED_Set(1, 1);
		Board_LED_Set(2, 1);

		Board_LED_Set(0, 0);
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(0, 1);
		vTaskDelay(configTICK_RATE_HZ);

		vTaskDelay(configTICK_RATE_HZ*2);
		vTaskDelay(configTICK_RATE_HZ*2);
		}
	}

/*
  Task 2 defining.
  Trun on GREEN Led and then turn off the same.
  In this time both RED and BLUE Led is turned off
*/
static void greenLEDTask(void *pvParameters)
	{
	while (1)
		{
		Board_LED_Set(0, 1);
		Board_LED_Set(2, 1);

		vTaskDelay(configTICK_RATE_HZ*2);

		Board_LED_Set(1, 0);
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(1, 1);
		vTaskDelay(configTICK_RATE_HZ);

		vTaskDelay(configTICK_RATE_HZ*2);
		}
	}
/*
  Task 3 defining.
  Trun on BLUE Led and then turn off the same.
  In this time both RED and GREEN Led is turned off
*/
static void blueLEDTask(void *pvParameters)
	{
	while (1)
		{
		Board_LED_Set(0, 1);
		Board_LED_Set(1, 1);

		vTaskDelay(configTICK_RATE_HZ*2);
		vTaskDelay(configTICK_RATE_HZ*2);

		Board_LED_Set(2, 0);
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(2, 1);
		vTaskDelay(configTICK_RATE_HZ);
		}
	}

int main(void)
	{
	prvSetupHardware();

	// RED Led  thread
	xTaskCreate(redLEDTask, (signed char *) "redLEDTask",	configMINIMAL_STACK_SIZE, NULL, 1,
	(xTaskHandle *) NULL);

	// GREEN Led  thread
	xTaskCreate(greenLEDTask, (signed char *) "greenLEDTask",	configMINIMAL_STACK_SIZE, NULL, 2,
	(xTaskHandle *) NULL);

	// BLUE Led  thread
	xTaskCreate(blueLEDTask, (signed char *) "blueLEDTask",	configMINIMAL_STACK_SIZE, NULL, 3,
	(xTaskHandle *) NULL);

	vTaskStartScheduler();
	return 1;
	}
