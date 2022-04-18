/*
 * Vehicle_cfg.h
 *
 *  Created on: Apr 2, 2022
 *      Author: Ziad Abdallah
 *     Project: Mini Project 1_Vehicle Control System_C Programming
 */

#ifndef VEHICLE_CFG_H_
#define VEHICLE_CFG_H_

/***STD_ON and STD_OFF***/
#define STD_ON							1
#define STD_OFF							0

#define WITH_ENGINE_TEMP_CONTROLLER		STD_ON

/***Initial values of vehicle structure***/
#define INITIAL_SPEED					0			//Initial speed in Km/hr.
#define INITIAL_ENGINE_STATUS			ENGINE_OFF
#define INITIAL_AC_STATUS				AC_OFF
#define INTIAL_ROOM_TEMP				20			//Initial room temperature in celsius
#define INITIAL_ENGINE_TEMP				125			//Initial engine temperature in celsius
#define INITIAL_ENGINE_TEMP_CTRL		STD_OFF

/***Setpoints Values***/
/*Room Temperature*/
#define SETPOINT_ROOM_TEMP				20			//Setpoint of room temperature in celsius
#define MIN_ROOM_TEMP					10			//Min. room temperature in celsius
#define MAX_ROOM_TEMP					30			//Max. room temperature in celsius

/*Engine Temperature*/
#define SETPOINT_ENGINE_TEMP			125			//Setpoint of engine temperature in celsius
#define MIN_ENGINE_TEMP					100			//Min. engine temperature in celsius
#define MAX_ENGINE_TEMP					150			//MAX. engine temperature in celsius

/*Vehicle speed*/
#define SPEED_TRIG						30			//the speed in Km/hr that trigers the AC and engine temp ctrl
#define SPEED_GREEN						100			//the speed in Km/hr when the traffic light is green
#define SPEED_ORANGE					30			//the speed in Km/hr when the traffic light is orange
#define SPEED_RED						0			//the speed in Km/hr when the traffic light is red

/**Locations Indecies**/
#define ROOM							0			//the index of the function that is related to the room (e.g: room temperature)
#define ENGINE							1			//the index of the function that is related to the engine (e.g: engine temperature)
#endif /* VEHICLE_CFG_H_ */
