/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: Buzzer.h
 *
 * Description: types for AVR
 *
 * Date Created: 28/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

/**-------------------------INCLUDES Section------------------------**/
#include "std_types.h"
/**-------------------------Definitions & Config Section------------**/
#define BUZZER_PORT_ID	PORTA_ID
#define BUZZER_PIN_ID	PIN0_ID
/**-------------------------Enum Section----------------------------**/

/**-------------------------Function Dec. Section-------------------**/
/*
 * Description:
 * Initializing Buzzer Pins
 */
void Buzzer_init();
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Turning Buzzer ON
 */
void Buzzer_on(void);
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Turning Buzzer OFF
 */
void Buzzer_off(void);
/**-------------------------END-------------------------------------**/


#endif /* BUZZER_H_ */
