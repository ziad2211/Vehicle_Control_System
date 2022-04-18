/*
 * Vehicle_functions.c
 *
 *  Created on: Apr 2, 2022
 *      Author: Ziad Abdallah
 *     Project: Mini Project 1_Vehicle Control System_C Programming
 */


#include "Vehicle_functions.h"

uint8_t (*calculate_temp[2]) (uint8_t) =
{
		room_temp,
#if (WITH_ENGINE_TEMP_CONTROLLER == STD_ON)
		engine_temp
#endif
};

void print_MainMenu(void)
{
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n");
	printf("> ");
	return;
}

void print_ActionsMenu(void)
{
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light color\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
#if (WITH_ENGINE_TEMP_CONTROLLER == STD_ON)
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
#endif
	printf("> ");
	return;
}

void print_DashBoard(const VEHICLE_t *vehicle)
{
	if(vehicle->engine_status == ENGINE_ON)
	{
		printf("\t\t          Engine: ON\n");
	}
	else
	{
		printf("\t\t          Engine: OFF\n");
	}

	if(vehicle->ac_status == AC_ON)
	{
		printf("\t\t              AC: ON\n");
	}
	else
	{
		printf("\t\t              AC: OFF\n");
	}

	printf("\t           Vehicle Speed: %hhu Km/hr\n",vehicle->speed_KMperH);
	printf("\t\tRoom Temperature: %hhu C\n",vehicle->room_temp_celsius);
#if (WITH_ENGINE_TEMP_CONTROLLER == STD_ON)
	if(vehicle->engine_temp_ctrl_status == STD_ON)
	{
		printf("   Engine Temperature Controller: ON\n");
	}
	else
	{
		printf("   Engine Temperature Controller: OFF\n");
	}
	printf("\t      Engine Temperature: %u C\n", vehicle->engine_temp_celsius);
#endif
	printf("\n");
}


void turnOFF_vehicle (VEHICLE_t *vehicle)
{
	printf("\nStopping the vehicle\n");
	vehicle->speed_KMperH = 0;

	printf("Turning off AC\n");
	vehicle->ac_status = AC_OFF;

#if (WITH_ENGINE_TEMP_CONTROLLER == STD_ON)
	printf("Turning off engine temperature controller\n");
	vehicle->engine_temp_ctrl_status = STD_OFF;
#endif

	printf("Turning off the engine\n");
	vehicle->engine_status = ENGINE_OFF;
}

uint8_t room_temp (uint8_t temp)
{
	/*Calculate the room temperature in celsius as per the given equation*/
	uint8_t result = (temp*(5.0/4.0))+1;
	return result;
}

#if (WITH_ENGINE_TEMP_CONTROLLER == STD_ON)
uint8_t engine_temp (uint8_t temp)
{
	/*Calculate the engine temperature in celsius as per the given equation*/
	uint8_t result = (temp*(5.0/4.0))+1;
	return result;
}
#endif
