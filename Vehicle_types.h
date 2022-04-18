/*
 * Vehicle_types.h
 *
 *  Created on: Apr 2, 2022
 *      Author: Ziad Abdallah
 *     Project: Mini Project 1_Vehicle Control System_C Programming
 *
 */

#ifndef VEHICLE_TYPES_H_
#define VEHICLE_TYPES_H_

#include "STD_TYPES.h"
#include "Vehicle_cfg.h"

/***Vehicle data types***/
/*Engine Status*/
typedef enum
{
	ENGINE_OFF,
	ENGINE_ON
}ENGINE_STATUS_t;

/*AC Status*/
typedef enum
{
	AC_OFF,
	AC_ON
}AC_STATUS_t;

/*Vehicle structure*/
typedef struct Vehicle
{
	ENGINE_STATUS_t engine_status;	//Engine status(ON/OFF)
	uint8_t speed_KMperH; 			//Speed in Km/hr.
	AC_STATUS_t ac_status;			//AC status (ON/OFF)
	uint8_t room_temp_celsius;		//Room temperature in celsius

#if (WITH_ENGINE_TEMP_CONTROLLER==1)

	uint8_t engine_temp_celsius;	//Engine temperature in celsius
	bool engine_temp_ctrl_status;	//Engine temperature controller status (ON/OFF)

#endif

}VEHICLE_t;

#endif /* VEHICLE_TYPES_H_ */
