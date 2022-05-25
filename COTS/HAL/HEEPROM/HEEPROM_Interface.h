/*
 * EEPROM_Interface.h
 *
 *  Created on: Nov 30, 2021
 *      Author: Mina-Ryad
 */

#ifndef HAL_HEEPROM_HEEPROM_INTERFACE_H_
#define HAL_HEEPROM_HEEPROM_INTERFACE_H_

/*Send Byte to EEPROM*/
void HEEPROM_VidSendDataByte(u8 Copy_u8LocationAddress, u8 Copy_u8ChipNumber,u8 Copy_u8BlockNumber, u8 Copy_u8Data);
/*Read Byte from EEPROM*/
u8 HEEPROM_VidReadDataByte(u8 Copy_u8LocationAddress, u8 Copy_u8ChipNumber,u8 Copy_u8BlockNumber);

#endif /* HAL_HEEPROM_HEEPROM_INTERFACE_H_ */
