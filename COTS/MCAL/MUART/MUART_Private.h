/*
 * MUART_Private.h
 *
 *  Created on: Nov 25, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MUART_MUART_PRIVATE_H_
#define MCAL_MUART_MUART_PRIVATE_H_

/*USART I/O Data Register*/
#define UDR   *((volatile u8 *)0x2C)

/*USART Control and Status Register A*/
#define UCSRA *((volatile u8 *)0x2B)
#define MPCM	BIT0
#define U2X		BIT1
#define PE		BIT2
#define DOR		BIT3
#define FE		BIT4
#define UDRE	BIT5
#define TXC		BIT6
#define RXC		BIT7

/*USART Control and Status Register B*/
#define UCSRB *((volatile u8 *)0x2A)
#define TXB8		BIT0
#define RXB8		BIT1
#define UCSZ2		BIT2
#define TXEN		BIT3
#define RXEN		BIT4
#define UDRIE		BIT5
#define TXCIE		BIT6
#define RXCIE		BIT7

/*USART Control and Status Register C*/
#define UCSRC *((volatile u8 *)0x40)
#define UCPOL		BIT0
#define UCSZ0		BIT1
#define UCSZ1		BIT2
#define USBS		BIT3
#define UPM0		BIT4
#define UPM1		BIT5
#define UMSEL		BIT6
#define URSEL		BIT7

/*USART Baud Rate Registers – UBRRL and UBRRH*/
#define UBRRH *((volatile u8 *)0x40)
#define UBRRL *((volatile u16 *)0x29)


#define UART_ASYNCHRONOUS_MODE 0
#define UART_SYNCHRONOUS_MODE 1

/* UART Parity mode options:*/
#define UART_PARITY_MODE_DISABELED	0
#define UART_PARITY_MODE_EVEN		1
#define UART_PARITY_MODE_ODD		2

#define UART_CHAR_SIZE_5		0
#define UART_CHAR_SIZE_6		1
#define UART_CHAR_SIZE_7		2
#define UART_CHAR_SIZE_8		3
#define UART_CHAR_SIZE_9		4

#define RX_INTERRUPT_ENABLED		0
#define RX_INTERRUPT_DISABELED		1

#define TX_INTERRUPT_ENABLED		0
#define TX_INTERRUPT_DISABELED		1

#define UDR_INTERRUPT_ENABLED		0
#define UDR_INTERRUPT_DISABELED		1

#endif /* MCAL_MUART_MUART_PRIVATE_H_ */
