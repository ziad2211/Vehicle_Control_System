/*
 * Vehicle_functions.h
 *
 *  Created on: Apr 2, 2022
 *      Author: Ziad Abdallah
 *     Project: Mini Project 1_Vehicle Control System_C Programming
 */

#ifndef VEHICLE_FUNCTIONS_H_
#define VEHICLE_FUNCTIONS_H_

#include <stdio.h>
#include "STD_TYPES.h"
#include "Vehicle_types.h"
#include "Vehicle_cfg.h"

void print_MainMenu(void);
void print_ActionsMenu(void);
void print_DashBoard(const VEHICLE_t *vehicle);
void turnOFF_vehicle (VEHICLE_t *vehicle);
uint8_t room_temp (uint8_t temp);
uint8_t engine_temp (uint8_t temp);

/*Pointer to functions of calculating temperatures*/
extern uint8_t (*calculate_temp[2]) (uint8_t);

#endif /* VEHICLE_FUNCTIONS_H_ */
