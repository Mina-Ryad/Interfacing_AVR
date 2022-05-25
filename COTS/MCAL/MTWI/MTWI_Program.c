/*
 * MTWI_Program.c
 *
 *  Created on: Nov 30, 2021
 *      Author: Mina-Ryad
 */

#include "..\..\LIB\LSTD_TYPES.h"
#include "..\..\LIB\LBIT_MATH.h"

#include "MTWI_Private.h"
#include "MTWI_Config.h"
#include "MTWI_Interface.h"

#include <util/delay.h>


/*TWI Init as master with set Master Address*/
void MTWI_VidInitMaster(u8 Copy_u8Address)
{
	/*Enable Acknowledge bit*/
	/*TWEA: TWI Enable Acknowledge Bit*/
	SET_BIT(TWCR,TWEA);

	/*Set SCL Frequency to 400KHz, with 16MHz CPU*/
	/*1- Set TWBR = 12*/
	TWBR=0;
	/*2- Clear the prescaler bits twps*/
	/*TWI Bit Rate Prescaler
	 * TWPS1 TWPS0 Prescaler Value
	 * 0 0 1
	 * 0 1 4
	 * 1 0 16
	 * 1 1 64*/
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);

	/*Set the required address in the 7MSB of TWAR*/
	TWAR=Copy_u8Address<<1;

	/*Enable TWI*/
	/*TWEN: TWI Enable Bit*/
	SET_BIT(TWCR,TWEN);

}

/*TWI Init as Slave with set Master Address*/
void MTWI_VidInitSlave(u8 Copy_u8Address)
{
	/*Enable Acknowledge bit*/
	/*TWEA: TWI Enable Acknowledge Bit*/
	SET_BIT(TWCR,TWEA);

	/*Set the required address in the 7MSB of TWAR*/
	TWAR=Copy_u8Address<<1;

	/*Enable TWI*/
	/*TWEN: TWI Enable Bit*/
	SET_BIT(TWCR,TWEN);

}

TWI_ErrorStatus MTWI_SendStartCondition(void)
{
	TWI_ErrorStatus LOC_Error = NoError;

	/*Send Start Condition*/
	/*TWSTA: TWI START Condition Bit*/
	SET_BIT(TWCR,TWSTA);

	/*Clear the Interrupt Flag to start the previous operation*/
	/*TWINT: TWI Interrupt Flag*/
	SET_BIT(TWCR,TWINT);

	/*wait untill the operation is finished and the flag is raised*/
	/*TWINT: TWI Interrupt Flag*/
	while(GET_BIT(TWCR,TWINT)==0);

	/*Check Operation Status*/
	if((TWSR&0xF8)!=START_ACK)
	{
		LOC_Error = StartConditionError;
	}
	else
	{
		/*Do Nothing*/
	}
	return LOC_Error;
}

TWI_ErrorStatus MTWI_SendRepeatedStart(void)
{
	TWI_ErrorStatus LOC_Error = NoError;

	/*Send Start Condition*/
	/*TWSTA: TWI START Condition Bit*/
	SET_BIT(TWCR,TWSTA);

	/*Clear the Interrupt Flag to start the previous operation*/
	/*TWINT: TWI Interrupt Flag*/
	SET_BIT(TWCR,TWINT);

	/*wait untill the operation is finished and the flag is raised*/
	/*TWINT: TWI Interrupt Flag*/
	while(GET_BIT(TWCR,TWINT)==0);

	/*Check Operation Status*/
	if((TWSR&0xF8)!=REPEATED_START_ACK)
	{
		LOC_Error = RepeatedStartError;
	}
	else
	{
		/*Do Nothing*/
	}
	return LOC_Error;
}

TWI_ErrorStatus MTWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus LOC_Error = NoError;

	/*Send 7bits Slave Address to the bus*/
	TWDR = Copy_u8SlaveAddress<<1;

	/*Set the Write request in ths LSB in data register*/
	CLR_BIT(TWDR,0);

	/*TWSTA: TWI START Condition Bit*/
	/*Clear Start Condition*/
	CLR_BIT(TWCR,TWSTA);

	/*Clear the Interrupt Flag to start the previous operation*/
	/*TWINT: TWI Interrupt Flag*/
	SET_BIT(TWCR,TWINT);

	/*wait until the operation is finished and the flag is raised*/
	/*TWINT: TWI Interrupt Flag*/
	while(GET_BIT(TWCR,TWINT)==0);

	/*Check Operation Status*/
	if((TWSR&0xF8)!=SLAVE_ADDRESS_AND_WRITE_ACK)
	{
		LOC_Error = SlaveAddressWithWriteError;
	}
	else
	{
		/*Do Nothing*/
	}
	return LOC_Error;
}

TWI_ErrorStatus MTWI_SendSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus LOC_Error = NoError;

	/*Send 7bits Slave Address to the bus*/
	TWDR = Copy_u8SlaveAddress<<1;

	/*Set the Write request in ths LSB in data register*/
	SET_BIT(TWDR,0);

	/*TWSTA: TWI START Condition Bit*/
	/*Clear Start Condition*/
	CLR_BIT(TWCR,TWSTA);

	/*Clear the Interrupt Flag to start the previous operation*/
	/*TWINT: TWI Interrupt Flag*/
	SET_BIT(TWCR,TWINT);

	/*wait untill the operation is finished and the flag is raised*/
	/*TWINT: TWI Interrupt Flag*/
	while(GET_BIT(TWCR,TWINT)==0);

	/*Check Operation Status*/
	if((TWSR&0xF8)!=SLAVE_ADDRESS_AND_READ_ACK)
	{
		LOC_Error = SlaveAddressWithReadError;
	}
	else
	{
		/*Do Nothing*/
	}
	return LOC_Error;
}

TWI_ErrorStatus MTWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrorStatus LOC_Error = NoError;

	/*Send 8bits Master Byte to the bus*/
	TWDR = Copy_u8DataByte;

	/*Clear the Interrupt Flag to start the previous operation*/
	/*TWINT: TWI Interrupt Flag*/
	SET_BIT(TWCR,TWINT);

	/*wait untill the operation is finished and the flag is raised*/
	/*TWINT: TWI Interrupt Flag*/
	while(GET_BIT(TWCR,TWINT)==0);

	/*Check Operation Status*/
	if((TWSR&0xF8)!=MASTER_WRITE_BYTE_ACK)
	{
		LOC_Error = MasterWriteByteError;
	}
	else
	{
		/*Do Nothing*/
	}
	return LOC_Error;
}

TWI_ErrorStatus MTWI_MasterReadDataByte(u8* Copy_pu8DataByte)
{
	TWI_ErrorStatus LOC_Error = NoError;

	/*Clear the Interrupt Flag to start the previous operation*/
	/*TWINT: TWI Interrupt Flag*/
	SET_BIT(TWCR,TWINT);

	/*wait untill the operation is finished and the flag is raised*/
	/*TWINT: TWI Interrupt Flag*/
	while(GET_BIT(TWCR,TWINT)==0);

	/*Check Operation Status*/
	if((TWSR&0xF8)!=MASTER_READ_BYTE_ACK)
	{
		LOC_Error = MasterReadByteError;
	}
	else
	{
		/*Read 8bits Master Byte to the bus*/
		*Copy_pu8DataByte = TWDR;
	}
	return LOC_Error;
}

void MTWI_SendStopCondition(void)
{
	/*Send Stop Condition on the bus*/
	/*TWSTO: TWI STOP Condition Bit*/
	SET_BIT(TWCR,TWSTO);

	/*Clear the Interrupt Flag to start the previous operation*/
	/*TWINT: TWI Interrupt Flag*/
	SET_BIT(TWCR,TWINT);
}
