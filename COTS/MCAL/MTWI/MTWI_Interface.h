/*
 * MTWI_Interface.h
 *
 *  Created on: Nov 30, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MTWI_MTWI_INTERFACE_H_
#define MCAL_MTWI_MTWI_INTERFACE_H_

typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteError,
	MasterReadByteError
}TWI_ErrorStatus;

/*TWI Init as master with set Master Address*/
void MTWI_VidInitMaster(u8 Copy_u8Address);

/*TWI Init as Slave with set Master Address*/
void MTWI_VidInitSlave(u8 Copy_u8Address);

TWI_ErrorStatus MTWI_SendStartCondition(void);

TWI_ErrorStatus MTWI_SendRepeatedStart(void);

TWI_ErrorStatus MTWI_SendSendSlaveAddressWithWrie(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus MTWI_SendSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus MTWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrorStatus MTWI_MasterReadDataByte(u8* Copy_pu8DataByte);

void MTWI_SendStopCondition(void);

#endif /* MCAL_MTWI_MTWI_INTERFACE_H_ */
