/*
 * main.c
 *
 *  Created on: Apr 2, 2022
 *      Author: Ziad Abdallah
 *     Project:	Mini Project 1_Vehicle Control System_C Programming
 *
 */


/***included files***/
#include <stdio.h>
#include "STD_TYPES.h"
#include "Vehicle_cfg.h"
#include "Vehicle_types.h"
#include "Vehicle_functions.h"

int main(void)
{

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	/*****User Inputs*****/
	uint8_t user_input = '\0';			//stores the user's choice from the menus
	uint8_t traffic_light = '\0';		//stores the color of the traffic light (Green 'g', Orange 'o', Red 'r')
	bool terminate_flag = FALSE;		//Raise this flag if the user chooses to quit/terminate the system

	/*****Vehicle Structure*****/
	VEHICLE_t vehicle = {
			INITIAL_ENGINE_STATUS,
			INITIAL_SPEED,
			INITIAL_AC_STATUS,
			INTIAL_ROOM_TEMP,
#if (WITH_ENGINE_TEMP_CONTROLLER==STD_ON)
			INITIAL_ENGINE_TEMP,
			INITIAL_ENGINE_TEMP_CTRL
#endif
	};

	/*
	 *
	 * Start the system
	 *
	 * */
	while(terminate_flag != TRUE) //Quit the system if the user choose c from main menu
	{
		/*Take the user letter of choice from the main menu.*/
		print_MainMenu();
		scanf(" %c",&user_input);

		/*Perform the user choice from the main menu*/
		switch(user_input)
		{
		/*The user chose to turn on the engine*/
		case 'a':
		case 'A':
			printf("\nTurning on the engine...\n\n");
			vehicle.engine_status = ENGINE_ON;
			print_DashBoard(&vehicle);
			break;

		/*The user chose to turn off the engine*/
		case 'b':
		case 'B':
			printf("\nTurning off the engine...\n\n");
			break; //go back to the beginning of the system loop

		/*The user chose to quit/terminate the system*/
		case 'c':
		case 'C':
			printf("\nTerminating the system...\n\n");
			terminate_flag = TRUE;
			break;	//quit the system while loop -> return 0 -> terminate the system.

		default:
			printf("\nNOT AVAILABLE! Please choose one of the available options\n\n");
			break;
		}

		/*
		 * Engine is ON
		 * Start of the actions menu until the user turn off the engine
		 *
		 * */
		while(vehicle.engine_status == ENGINE_ON)
		{
			print_ActionsMenu();
			scanf( " %c",&user_input);
			switch(user_input)
			{
			/*a. The user chose to turn off the vehicle*/
			case 'a':
			case 'A':
				turnOFF_vehicle(&vehicle);
				break; //break the switch cases -> repeat the system while loop

			/*b. The user chose to set the traffic light color*/
			case 'b':
			case 'B':
				printf("Enter the required color: ");
				scanf(" %c",&traffic_light);
				//Green traffic light - speed = 100 Km/hr
				if((traffic_light=='g')||(traffic_light=='G'))
				{
					vehicle.speed_KMperH = SPEED_GREEN;
				}
				//Orange traffic light - speed = 30 Km/hr
				else if((traffic_light=='o')||(traffic_light=='O'))
				{
					vehicle.speed_KMperH = SPEED_ORANGE;
				}
				//Red traffic light - speed = 0 Km/hr
				else if((traffic_light=='r')||(traffic_light=='R'))
				{
					vehicle.speed_KMperH = SPEED_RED;
				}
				break;

			/*c. The user chose to set room temperature*/
			case 'c':
			case 'C':
				printf("Enter room temperature: ");
				scanf(" %hhu", &vehicle.room_temp_celsius);
				if((vehicle.room_temp_celsius<MIN_ROOM_TEMP)||(vehicle.room_temp_celsius>MAX_ROOM_TEMP))
				{
					vehicle.ac_status = AC_ON;
					vehicle.room_temp_celsius = SETPOINT_ROOM_TEMP;
				}
				else
				{
					vehicle.ac_status = AC_OFF;
				}
				break;

				/*The user chose to set engine temperature*/
#if (WITH_ENGINE_TEMP_CONTROLLER==STD_ON)
			case 'd':
			case 'D':
				printf("Enter engine temperature: ");
				scanf(" %hhu",&vehicle.engine_temp_celsius);
				if((vehicle.engine_temp_celsius<MIN_ENGINE_TEMP)||(vehicle.engine_temp_celsius>MAX_ENGINE_TEMP))
				{
					vehicle.engine_temp_ctrl_status = STD_ON;
					vehicle.engine_temp_celsius = SETPOINT_ENGINE_TEMP;
				}
				else
				{
					vehicle.engine_temp_ctrl_status = STD_OFF;
				}
				break;
#endif
			default:
				printf("NOT AVAILABLE! Please choose one of the available options");
				break;
			}

			/*Calculate temperatures at certain speed as per requirements*/
			if(vehicle.speed_KMperH==SPEED_TRIG)
			{
				vehicle.ac_status = AC_ON;
				vehicle.room_temp_celsius = (*calculate_temp[ROOM])(vehicle.room_temp_celsius);
#if (WITH_ENGINE_TEMP_CONTROLLER == STD_ON)
				vehicle.engine_temp_ctrl_status = STD_ON;
				vehicle.engine_temp_celsius = (*calculate_temp[ENGINE])(vehicle.engine_temp_celsius);
#endif
			}
			print_DashBoard(&vehicle);
		}
		/*
		 * Engine is OFF
		 * End of the actions menu until the user turn off the engine
		 *
		 * */
	}
	/*
	 *
	 * End of the system
	 *
	 * */
	printf("System is terminated!");
	return 0;
}
