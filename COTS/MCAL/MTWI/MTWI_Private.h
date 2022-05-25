/*
 * MTWI_Private.h
 *
 *  Created on: Nov 30, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MTWI_MTWI_PRIVATE_H_
#define MCAL_MTWI_MTWI_PRIVATE_H_

#define TWBR *((volatile u8*)0x20)

#define TWCR *((volatile u8*)0x56)
#define TWIE	BIT0
#define TWEN	BIT2
#define TWWC	BIT3
#define TWSTO	BIT4
#define TWSTA 	BIT5
#define TWEA 	BIT6
#define TWINT 	BIT7

#define TWSR *((volatile u8*)0x21)
#define TWPS0 BIT0
#define TWPS1 BIT1
#define TWS3 BIT3
#define TWS4 BIT4
#define TWS5 BIT5
#define TWS6 BIT6
#define TWS7 BIT7

#define TWDR *((volatile u8*)0x23)
#define TWAR *((volatile u8*)0x22)

#define START_ACK			 0x08
#define REPEATED_START_ACK	 0x10

#define SLAVE_ADDRESS_AND_WRITE_ACK 0x18
#define SLAVE_ADDRESS_AND_READ_ACK	0x40

#define MASTER_WRITE_BYTE_ACK		0x28
#define MASTER_READ_BYTE_ACK		0x50

#endif /* MCAL_MTWI_MTWI_PRIVATE_H_ */
