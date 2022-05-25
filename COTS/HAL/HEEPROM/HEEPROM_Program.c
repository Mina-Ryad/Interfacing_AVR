/*
 * EEPROM_Program.c
 *
 *  Created on: Nov 30, 2021
 *      Author: Mina-Ryad
 */



#include "..\..\LIB\LSTD_TYPES.h"
#include "..\..\LIB\LBIT_MATH.h"

#include "..\..\MCAL\MTWI\MTWI_Private.h"
#include "..\..\MCAL\MTWI\MTWI_Interface.h"

#include "HEEPROM_Private.h"
#include "HEEPROM_Config.h"
#include "HEEPROM_Interface.h"

#include <util/delay.h>

/*Send Byte to EEPROM*/
void HEEPROM_VidSendDataByte(u8 Copy_u8LocationAddress, u8 Copy_u8ChipNumber,u8 Copy_u8BlockNumber, u8 Copy_u8Data)
{
	u8 LOC_u8AddressPacket=0;
	LOC_u8AddressPacket = EEPROM_FIXED_ADDRESS | (Copy_u8ChipNumber<<2);
	LOC_u8AddressPacket = LOC_u8AddressPacket | Copy_u8BlockNumber;
	/*Start Condition*/
	MTWI_SendStartCondition();
	/*Send Address Packet --> Address of Chip and block*/
	MTWI_SendSlaveAddressWithWrite(LOC_u8AddressPacket);
	/*Send the rest 8bit of Location Address*/
	MTWI_MasterWriteDataByte(Copy_u8LocationAddress);
	/*Send Data Byte to memory location*/
	MTWI_MasterWriteDataByte(Copy_u8Data);
	/*Stop Condition*/
	MTWI_SendStopCondition();
	/*Delay until the write cycle is finished*/
	_delay_ms(10);

}

/*Read Byte from EEPROM*/
u8 HEEPROM_VidReadDataByte(u8 Copy_u8LocationAddress, u8 Copy_u8ChipNumber,u8 Copy_u8BlockNumber)
{
	u8 LOC_u8AddressPacket=0;
	u8 LOC_u8DataByte;
	LOC_u8AddressPacket = EEPROM_FIXED_ADDRESS | (Copy_u8ChipNumber<<2);
	LOC_u8AddressPacket = LOC_u8AddressPacket | Copy_u8BlockNumber;
	/*Start Condition*/
	MTWI_SendStartCondition();
	/*Send Address Packet --> Address of Chip and block*/
	MTWI_SendSlaveAddressWithWrite(LOC_u8AddressPacket);
	/*Send the rest 8bit of Location Address*/
	MTWI_MasterWriteDataByte(Copy_u8LocationAddress);
	/*Send Repeated Start*/
	MTWI_SendRepeatedStart();
	/*Send Address Packet with read*/
	LOC_u8AddressPacket = EEPROM_FIXED_ADDRESS | (Copy_u8ChipNumber<<2);
	LOC_u8AddressPacket = LOC_u8AddressPacket | Copy_u8BlockNumber;
	/*Start Condition*/
	MTWI_SendStartCondition();
	/*Send Address Packet --> Address of Chip and block*/
	MTWI_SendSlaveAddressWithWrite(LOC_u8AddressPacket);
	/*Read the 8bit of Location Address*/
	MTWI_MasterReadDataByte(&LOC_u8DataByte);
	/*Stop Condition*/
	MTWI_SendStopCondition();

	return LOC_u8DataByte;
}
