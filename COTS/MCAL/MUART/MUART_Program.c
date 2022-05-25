/*
TXEN * MUART_Program.c
 *
 *  Created on: Nov 25, 2021
 *      Author: Mina-Ryad
 */

#include "..\..\LIB\LSTD_TYPES.h"
#include "..\..\LIB\LBIT_MATH.h"
#include "MUART_Private.h"
#include "MUART_Config.h"

/*Pointer to Function Declaration (Call Back Function Pointer)*/
void (*MUART_RX_CallBack)(void);

/*Pointer to Function Declaration (Call Back Function Pointer)*/
void (*MUART_TX_CallBack)(void);

/*Pointer to Function Declaration (Call Back Function Pointer)*/
void (*MUART_UDR_Empty_CallBack)(void);

/*ISR RX Complete*/
void __vector_13(void)  __attribute__((signal));

/*ISR TX Complete*/
void __vector_15(void)  __attribute__((signal));

/*ISR UDR Empty Complete*/
void __vector_14(void)  __attribute__((signal));


/***********************/
/* UART Initialization */
/***********************/
void MUART_VidInit(void)
{
	u8 LOC_u8Copy_UCSRC = 0;

/*Select UART Mode
 * UMSEL Mode
 *   0   Asynchronous Operation
 *   1   Synchronous Operation
 * */
	#if UART_SET_MODE == UART_ASYNCHRONOUS_MODE
		CLR_BIT(LOC_u8Copy_UCSRC, UMSEL);
	#elif UART_SET_MODE == UART_SYNCHRONOUS_MODE
		SET_BIT(LOC_u8Copy_UCSRC,UMSEL);
	#else
	#error "UART Mode is not valid...."
	#endif

/*Select UART Parity Mode
 * UPM1 UPM0 Parity Mode
 *  0    0   Disabled
 *  0    1   Reserved
 *  1    0   Enabled, Even Parity
 *  1    1   Enabled, Odd Parity
 * */
	#if UART_SET_PARITY_MODE == UART_PARITY_MODE_DISABELED
		CLR_BIT(LOC_u8Copy_UCSRC,UPM0);
		CLR_BIT(LOC_u8Copy_UCSRC,UPM1);
	#elif UART_SET_PARITY_MODE == UART_PARITY_MODE_EVEN
		CLR_BIT(LOC_u8Copy_UCSRC,UPM0);
		SET_BIT(LOC_u8Copy_UCSRC,UPM1);
	#elif UART_SET_PARITY_MODE == UART_PARITY_MODE_EVEN
		SET_BIT(LOC_u8Copy_UCSRC,UPM0);
		SET_BIT(LOC_u8Copy_UCSRC,UPM1);
	#else
	#error "UART Parity Mode is not valid...."
	#endif

/*Select Stop Bit
 * USBS Stop Bit(s)
 *  0   1-bit
 *  1   2-bit
 * */
	#if UART_STOP_BIT == UART_STOP_ONE_BIT
		CLR_BIT(LOC_u8Copy_UCSRC,USBS);
	#elif UART_STOP_BIT == UART_STOP_TWO_BIT
		CLR_BIT(LOC_u8Copy_UCSRC,USBS);
	#error "UART Stop is not valid...."
	#endif

	/*Select Char Size*UCSZ Bits Settings
	 * UCSZ2 UCSZ1 UCSZ0 Character Size
	 *   0     0     0   5-bit
	 *   0     0     1   6-bit
	 *   0     1     0   7-bit
	 *   0     1     1   8-bit
	 *   1     1     1   9-bit
	 * */
	#if UART_SET_CHAR_SIZE == UART_CHAR_SIZE_5
		CLR_BIT(LOC_u8Copy_UCSRC,UCSZ0);
		CLR_BIT(LOC_u8Copy_UCSRC,UCSZ1);
		CLR_BIT(USCRB,UCSZ2);
	#elif UART_SET_CHAR_SIZE == UART_CHAR_SIZE_6
		CLR_BIT(LOC_u8Copy_UCSRC,UCSZ0);
		SET_BIT(LOC_u8Copy_UCSRC,UCSZ1);
		CLR_BIT(USCRB,UCSZ2);
	#elif UART_SET_CHAR_SIZE == UART_CHAR_SIZE_7
		SET_BIT(LOC_u8Copy_UCSRC,UCSZ0);
		CLR_BIT(LOC_u8Copy_UCSRC,UCSZ1);
		CLR_BIT(USCRB,UCSZ2);
	#elif UART_SET_CHAR_SIZE == UART_CHAR_SIZE_8
		SET_BIT(LOC_u8Copy_UCSRC,UCSZ0);
		SET_BIT(LOC_u8Copy_UCSRC,UCSZ1);
		CLR_BIT(UCSRB,UCSZ2);
	#elif UART_SET_CHAR_SIZE == UART_CHAR_SIZE_9
		CLR_BIT(LOC_u8Copy_UCSRC,UCSZ0);
		CLR_BIT(LOC_u8Copy_UCSRC,UCSZ1);
		CLR_BIT(USCRB,UCSZ2);
	#error "UART Stop is not valid...."
	#endif


	/*Set Bit 7 to select UCSRC register*/
	/*URSEL: Register Select
	 * This bit selects between accessing the UCSRC or the UBRRH Register. It is read as
	 * one when reading UCSRC. The URSEL must be one when writing the UCSRC.
	 * */
	SET_BIT(LOC_u8Copy_UCSRC,URSEL);
	UCSRC = LOC_u8Copy_UCSRC;

	/* Set Baud Rate @ 16 MHz
	 * -------------------------------------
	 * Baud Rate (bps) -- U2X = 0 -- U2X = 1
	 * -------------------------------------
	 * 					  UBRR       UBRR
	 * -------------------------------------
	 *     2400           416        832
	 *     4800           207        416
	 *     9600           103        207
	 *     14.4k          68         138
	 *     19.2k          51         103
	 *     28.8k          34         68
	 *     38.4k          25         51
	 *     57.6k          16         34
	 *     76.8k          12         25
	 *     115.2k         8          16
	 *     230.4k         3          8
	 *     250k           3          7
	 *     0.5M           1          3
	 *     1M             0          1
	 * */
	/* Set Baud Rate @ 1 MHz
	 * -------------------------------------
	 * Baud Rate (bps) -- U2X = 0 -- U2X = 1
	 * -------------------------------------
	 * 					  UBRR       UBRR
	 * -------------------------------------
	 *     2400           207        416
	 *     4800           103        207
	 *     9600           51         103
	 *     14.4k          34         68
	 *     19.2k          25         51
	 *     28.8k          16         34
	 *     38.4k          12         25
	 *     57.6k          8          16
	 *     76.8k          6          12
	 *     115.2k         3          8
	 *     230.4k         1          3
	 *     250k           1          3
	 *     0.5M           0          1
	 *     1M             -          0
	 * */
	CLR_BIT(UCSRA,U2X);
	UBRRL = 6;

	/*RXCIE: RX Complete Interrupt Enable*/
#if RX_INTERRUPT == RX_INTERRUPT_ENABLED
	SET_BIT(UCSRB,RXCIE);
#elif RX_INTERRUPT == RX_INTERRUPT_DISABELED
	SET_BIT(UCSRB,RXCIE);
#endif

	/*TXCIE: TX Complete Interrupt Enable*/
#if TX_INTERRUPT == TX_INTERRUPT_ENABLED
	SET_BIT(UCSRB,TXCIE);
#elif TX_INTERRUPT == TX_INTERRUPT_DISABELED
	SET_BIT(UCSRB,TXCIE);
#endif

	/*UDRIE: USART Data Register Empty Interrupt Enable*/
#if UDR_INTERRUPT == UDR_INTERRUPT_ENABLED
	SET_BIT(UCSRB,UDRIE);
#elif UDR_INTERRUPT == UDR_INTERRUPT_DISABELED
	SET_BIT(UCSRB,UDRIE);
#endif

	/* RXEN: Receiver Enable
	 * TXEN: Transmitter Enable
	*/
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
}

void MUART_VidSendChar(u8 Copy_u8Data)
{
	/*Wait until Register Empty is set*/
	/*UDRE: USART Data Register Empty*/
	while(GET_BIT(UCSRA,UDRE) == 0) ;
	UDR=Copy_u8Data;
}

void MUART_VidSendString(u8*Copy_u8Array)
{
	u8 LOC_u8Counter=0;
	while(1)
	{
		MUART_VidSendChar(Copy_u8Array[LOC_u8Counter]);
		if(Copy_u8Array[LOC_u8Counter]=='\t')
		{
			break;
		}
		LOC_u8Counter++;
	}
}

u8 MUART_u8RecieveData(void)
{
	/*Wait until USART Receive Complete*/
	/*RXC: USART Receive Complete*/
	while(GET_BIT(UCSRA,RXC) == 0);
	return UDR;
}

/*void MUART_VidSendString(u8 *Copy_u8Data)
{
	u8 LOC_CharCount=0;
	while(Copy_u8Data[LOC_CharCount]!=NULL)
	{
		MUART_VidSendChar(Copy_u8Data[LOC_CharCount]);
		LOC_CharCount++;
	}
}*/

/*RX*/
void MUART_RX_SetCallBack(void(*Copy_VidCallBack)(void))
{
	MUART_RX_CallBack = Copy_VidCallBack;
}

void __vector_13(void)
{
	MUART_RX_CallBack();
}

/*TX*/
void MUART_TX_SetCallBack(void(*Copy_VidCallBack)(void))
{
	MUART_TX_CallBack = Copy_VidCallBack;
}

void __vector_15(void)
{
	MUART_TX_CallBack();
}

/*UDR_Empty*/
void MUART_UDR_Empty_SetCallBack(void(*Copy_VidCallBack)(void))
{
	MUART_UDR_Empty_CallBack = Copy_VidCallBack;
}

void __vector_14(void)
{
	MUART_UDR_Empty_CallBack();
}
