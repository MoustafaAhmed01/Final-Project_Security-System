/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: I2C.h
 *
 * Description: types for AVR
 *
 * Date Created: 15/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

#ifndef TWI_H_
#define TWI_H_

/**-------------------------INCLUDES Section------------------------**/
#include "std_types.h"
/**-------------------------Definitions & Config Section------------**/

/* I2C Status Bits in the TWSR Register */
#define TWI_START         0x08 /* start has been sent */
#define TWI_REP_START     0x10 /* repeated start */
#define TWI_MT_SLA_W_ACK  0x18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_R_ACK  0x40 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define TWI_MT_DATA_ACK   0x28 /* Master transmit data and ACK has been received from Slave. */
#define TWI_MR_DATA_ACK   0x50 /* Master received data and send ACK to slave. */
#define TWI_MR_DATA_NACK  0x58 /* Master received data but doesn't send ACK to slave. */

/**-------------------------Enum Section----------------------------**/
typedef enum
{
	TWI_INT_DISABLED,TWI_INT_ENABLED
}TWI_INT;
/*-------------------------------------------------------------------*/

typedef enum
{
	ACK_OFF,ACK_ON
}TWI_ACK_EN;
/*-------------------------------------------------------------------*/

typedef enum
{
	TWI_DISABLED,TWI_ENABLED
}TWI_CONTROL;
/*-------------------------------------------------------------------*/

typedef enum
{
	F_I2C_1,F_I2C_4,F_I2C_16,F_I2C_64
}TWI_PRESCALER;
/*-------------------------------------------------------------------*/

typedef enum
{
	CALL_RECOGNITION_OFF,CALL_RECOGNITION_ON
}TWI_CALL_REC;
/**-------------------------Struct Section--------------------------**/
/* Please Copy the below comment before Initializing TWI */
/*
 * file name: twi.h
 *  -> Structure Configuration:
 *
 *  interruptControl :
 *  ackControl :
 *  twiControl :
 *  prescalerControl :
 *  callRecControl :
 *  address :
 *  bit_rate :
 */
typedef struct
{
	TWI_INT			interruptControl;
	TWI_ACK_EN		ackControl;
	TWI_CONTROL		twiControl;
	TWI_PRESCALER	prescalerControl;
	TWI_CALL_REC	callRecControl;
	uint8 address;
	uint8 bit_rate;

}TWI_ConfigType;
/**-------------------------Function Dec. Section-------------------**/
/*
 * Description:
 * Initializing I2C Registers
 */
void TWI_init(const TWI_ConfigType *Config_Ptr);
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Getting ready to send and being a master
 */
void TWI_start(void);
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Stopping the connection with slave
 */
void TWI_stop(void);
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Sending byte
 */
void TWI_writeByte(uint8 data);
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Read the received value and then send ACK
 */
uint8 TWI_readByteWithACK(void);
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Read the received value and Don't send ACK
 */
uint8 TWI_readByteWithNACK(void);
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Checking on the status of the register
 */
uint8 TWI_getStatus(void);
/*-------------------------------------------------------------------*/

/**-------------------------END-------------------------------------**/

#endif /* TWI_H_ */
