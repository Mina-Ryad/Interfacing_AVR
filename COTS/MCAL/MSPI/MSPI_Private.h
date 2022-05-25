/*
 * MPSI_Private.h
 *
 *  Created on: Nov 29, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MSPI_MSPI_PRIVATE_H_
#define MCAL_MSPI_MSPI_PRIVATE_H_


#define SPCR *((volatile u8 *)0x2D)
#define SPR0 BIT0
#define SPR1 BIT1
#define CPHA BIT2
#define CPOL BIT3
#define MSTR BIT4
#define DORD BIT5
#define SPE  BIT6
#define SPIE BIT7

#define SPSR *((volatile u8 *)0x2E)
#define SPI2X BIT0
#define WCOL BIT6
#define SPIF BIT7

#define SPDR *((volatile u8 *)0x2F)

/*SPI Interrupt Selection*/
#define MSPI_INTERRUPT_ENABELED		0
#define MSPI_INTERRUPT_DISABELED	1

/*SPI Status Selection*/
#define MSPI_ENABELED		0
#define MSPI_DISABELED		1

/* SPI Master/Slave Selection*/
#define MSPI_SET_MASTER		0
#define MSPI_SET_SLAVE		1

/* SPI Clock Polarity Selection*/
#define MSPI_CLOCK_POLARITY_LEADING_RISING		0
#define MSPI_CLOCK_POLARITY_LEADING_FALLING		1

/* SPI Clock Phase Selection*/
#define MSPI_CLOCK_PHASE_LEADING_SAMPLE		0
#define MSPI_CLOCK_PHASE_LEADING_SETUP		1

/**/
#define MSPI_CLOCK_RATE_4		0
#define MSPI_CLOCK_RATE_16		1
#define MSPI_CLOCK_RATE_64		2
#define MSPI_CLOCK_RATE_128		3
#define MSPI_CLOCK_RATE_2_D		4
#define MSPI_CLOCK_RATE_8_D		5
#define MSPI_CLOCK_RATE_32_D	6
#define MSPI_CLOCK_RATE_64_D	7

#endif /* MCAL_MSPI_MSPI_PRIVATE_H_ */
