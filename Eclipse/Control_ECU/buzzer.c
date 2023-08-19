/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: Buzzer.c
 *
 * Description: types for AVR
 *
 * Date Created: 28/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

/**-------------------------INCLUDES Section------------------------**/
#include "Libraries.h"
#include "GPIO.h"
#include "buzzer.h"

/**-------------------------Function Definition Section-------------**/

/*
 * Description:
 * Initializing Buzzer Pins
 */
void Buzzer_init()
{
	/* Setting up the Pin direction */
	GPIO_setupPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);

	/* Turning Buzzer OFF at first */
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Turning Buzzer ON
 */
void Buzzer_on(void)
{
	/* Setting Buzzer Pin to high */
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
}
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Turning Buzzer OFF
 */
void Buzzer_off(void)
{
	/* Turning Buzzer OFF at first */
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}
/**---------------------------------END-----------------------------**/
