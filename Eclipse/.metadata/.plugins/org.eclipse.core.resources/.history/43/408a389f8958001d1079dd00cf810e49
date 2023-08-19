/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: keypad.h
 *
 * Description: types for AVR
 *
 * Date Created: 15/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

/**-------------------------INCLUDES Section------------------------**/
#include "std_types.h"
/**-------------------------Definitions & Config Section------------**/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                   4
#define KEYPAD_NUM_ROWS                   4

/* Keypad Port Configurations */
#define KEYPAD_ROW_PORT_ID                PORTB_ID
#define KEYPAD_FIRST_ROW_PIN_ID           PIN0_ID

#define KEYPAD_COL_PORT_ID                PORTB_ID
#define KEYPAD_FIRST_COL_PIN_ID           PIN4_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH

/**-------------------------Function Dec. Section-------------------**/

/* Public functions prototypes: */
uint8 Keypad_getPressedKey();

/**---------------------------------END-----------------------------**/

#endif /* KEYPAD_H_ */
