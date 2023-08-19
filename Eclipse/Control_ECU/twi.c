/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: I2C.c
 *
 * Description: types for AVR
 *
 * Date Created: 15/10/2022
 *
 * Author: Moustafa Ahmed
 *
 *******************************************************************************/

/**-------------------------INCLUDES Section------------------------**/
#include "Libraries.h"
#include "GPIO.h"
#include "twi.h"

/**-------------------------Function Definition Section-------------**/

/*
 * Description:
 * Initializing I2C Registers
 */
void TWI_init(const TWI_ConfigType *Config_Ptr)
{
	/* Choosing the bit rate */
	TWBR = (TWBR & 0x00) | (Config_Ptr->bit_rate);

	/* Choosing Ack */
	TWCR = (TWCR & 0xBF) | ((Config_Ptr->ackControl)<<TWEA);

	/* Selecting the prescaler value */
	TWSR = (TWSR & 0xFC) | ((Config_Ptr->prescalerControl));

	/* Identifying my self */
	TWAR = (TWAR & 0x01) | ((Config_Ptr->address)<<1);

	/* Enabling General Call Recognition */
	TWAR = (TWAR & 0xFE) | ((Config_Ptr->callRecControl));

	/* Interrupt Enable */
	TWCR = (TWCR & 0xFE) | ((Config_Ptr->interruptControl));

	/* Enable TWI */
	TWCR = (TWCR & 0xFB) | ((Config_Ptr->twiControl)<<TWEN);

}
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Getting ready to send and being a master
 */
void TWI_start(void)
{
	/*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	/* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
	while(BIT_IS_CLEAR(TWCR,TWINT));
}
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Stopping the connection with slave
 */
void TWI_stop(void)
{
	/*
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Sending byte
 */
void TWI_writeByte(uint8 data)
{
    /* Put data On TWI data Register */
    TWDR = data;
    /*
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Read the received value and then send ACK
 */
uint8 TWI_readByteWithACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Read the received value and Don't send ACK
 */
uint8 TWI_readByteWithNACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}
/*-------------------------------------------------------------------*/
/*
 * Description:
 * Checking on the status of the register
 */
uint8 TWI_getStatus(void)
{
    uint8 status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR & 0xF8;
    return status;
}
/*-------------------------------------------------------------------*/

/**---------------------------------END-----------------------------**/
