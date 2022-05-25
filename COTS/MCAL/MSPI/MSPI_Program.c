/*
 * MSPI_Program.c
 *
 *  Created on: Nov 29, 2021
 *      Author: Mina-Ryad
 */

#include "..\..\LIB\LSTD_TYPES.h"
#include "..\..\LIB\LBIT_MATH.h"
#include "MSPI_Private.h"
#include "MSPI_Config.h"

/*Pointer to Function Declaration (Call Back Function Pointer)*/
void (*MSPI_CallBack)(void);

/*SPI ISR Interrupt Declaration */
void __vector_12(void) __attribute__((signal));

/*****************************/
/**SPI Master Initialization**/
/*****************************/
void MSPI_VidMasterInit(void)
{
	/*DORD: Data Order*/
#if MSPI_DATA_ORDER == MSPI_DATA_ORDER_LSB
	SET_BIT(SPCR,DORD);
#elif MSPI_DATA_ORDER == MSPI_DATA_ORDER_MSB
	CLR_BIT(SPCR,DORD);
#endif

	/* CPOL: Clock Polarity
	 * CPOL Functionality
	 * ------------------
	 * CPOL --- Leading Edge --- Trailing Edge
	 *  0       Rising           Falling
	 *  1       Falling          Rising
	 */
#if MSPI_CLOCK_POLARITY == MSPI_CLOCK_POLARITY_LEADING_RISING
	CLR_BIT(SPCR,CPOL);
#elif MSPI_CLOCK_POLARITY == MSPI_CLOCK_POLARITY_LEADING_FALLING
	SET_BIT(SPCR,CPOL);
#endif

	/* CPHA: Clock Phase
	 * CPHA Functionality
	 * ------------------
	 * CPHA --- Leading Edge --- Trailing Edge
	 *  0       Sample           Setup
	 *  1       Setup            Sample
	 * */
#if MSPI_CLOCK_PHASE == MSPI_CLOCK_PHASE_LEADING_SAMPLE
	SET_BIT(SPCR,CPHA);
#elif MSPI_CLOCK_PHASE == MSPI_CLOCK_PHASE_LEADING_SETUP
	CLR_BIT(SPCR,CPHA);
#endif

	/*SPR1, SPR0: SPI Clock Rate Select 1 and 0
	 * Relationship Between SCK and the Oscillator Frequency
	 * -----------------------------------------------------
	 * SPI2X SPR1 SPR0 --- SCK Frequency
	 *   0    0    0       fosc/4
	 *   0    0    1       fosc/16
	 *   0    1    0       fosc/64
	 *   0    1    1       fosc/128
	 *   1    0    0       fosc/2
	 *   1    0    1       fosc/8
	 *   1    1    0       fosc/32
	 *   1    1    1       fosc/64
	 * */
#if MSPI_CLOCK_RATE == MSPI_CLOCK_RATE_4
	CLR_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
#elif MSPI_CLOCK_RATE == MSPI_CLOCK_RATE_16
	SET_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
#elif MSPI_CLOCK_RATE == MSPI_CLOCK_RATE_64
	CLR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
#elif MSPI_CLOCK_RATE == MSPI_CLOCK_RATE_128
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
#elif MSPI_CLOCK_RATE == MSPI_CLOCK_RATE_2_D
	CLR_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
#elif MSPI_CLOCK_RATE == MSPI_CLOCK_RATE_8_D
	SET_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
#elif MSPI_CLOCK_RATE == MSPI_CLOCK_RATE_32_D
	CLR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
#elif MSPI_CLOCK_RATE == MSPI_CLOCK_RATE_64_D
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
#endif

	/*SPIE: SPI Interrupt Enable*/
#if MSPI_INTERRUPT == MSPI_INTERRUPT_ENABELED
	SET_BIT(SPCR,SPIE);
#elif MSPI_INTERRUPT == MSPI_INTERRUPT_DISABELED
	CLR_BIT(SPCR,SPIE);
#endif

	/*MSTR: Master Select*/
	SET_BIT(SPCR,MSTR);

	/*SPE: SPI Enable*/
#if MSPI_STATUS == MSPI_ENABELED
	SET_BIT(SPCR,SPE);
#elif MSPI_STATUS == MSPI_DISABELED
	CLR_BIT(SPCR,SPE);
#endif
}

/****************************/
/**SPI Slave Initialization**/
/****************************/
void MSPI_VidSlaveInit(void)
{
	/*DORD: Data Order*/
#if MSPI_DATA_ORDER == MSPI_DATA_ORDER_LSB
	SET_BIT(SPCR,DORD);
#elif MSPI_DATA_ORDER == MSPI_DATA_ORDER_MSB
	CLR_BIT(SPCR,DORD);
#endif

	/* CPOL: Clock Polarity
	 * CPOL Functionality
	 * ------------------
	 * CPOL --- Leading Edge --- Trailing Edge
	 *  0       Rising           Falling
	 *  1       Falling          Rising
	 */
#if MSPI_CLOCK_POLARITY == MSPI_CLOCK_POLARITY_LEADING_RISING
	CLR_BIT(SPCR,CPOL);
#elif MSPI_CLOCK_POLARITY == MSPI_CLOCK_POLARITY_LEADING_FALLING
	SET_BIT(SPCR,CPOL);
#endif

	/* CPHA: Clock Phase
	 * CPHA Functionality
	 * ------------------
	 * CPHA --- Leading Edge --- Trailing Edge
	 *  0       Sample           Setup
	 *  1       Setup            Sample
	 * */
#if MSPI_CLOCK_PHASE == MSPI_CLOCK_PHASE_LEADING_SAMPLE
	SET_BIT(SPCR,CPHA);
#elif MSPI_CLOCK_PHASE == MSPI_CLOCK_PHASE_LEADING_SETUP
	CLR_BIT(SPCR,CPHA);
#endif

	/*SPIE: SPI Interrupt Enable*/
#if MSPI_INTERRUPT == MSPI_INTERRUPT_ENABELED
	SET_BIT(SPCR,SPIE);
#elif MSPI_INTERRUPT == MSPI_INTERRUPT_DISABELED
	CLR_BIT(SPCR,SPIE);
#endif

	/*MSTR: Slave Select*/
	CLR_BIT(SPCR,MSTR);

	/*SPE: SPI Enable*/
#if MSPI_STATUS == MSPI_ENABELED
	SET_BIT(SPCR,SPE);
#elif MSPI_STATUS == MSPI_DISABELED
	CLR_BIT(SPCR,SPE);
#endif
}


/*************************/
/**SPI Send Receive Data**/
/*************************/
u8 MSPI_u8SendReceiveData(u8 Copy_u8Send_Data)
{
	SPDR = Copy_u8Send_Data;
	/*wait on SPI Interrupt Flag is set to one*/
	while (GET_BIT(SPSR,SPIF)==0);
	return SPDR;
}

/***************/
/**Return SPDR**/
/***************/
u8 MSPI_u8ReturnSPDR(void)
{
	return SPDR;
}

/***************/
/**Write SPDR **/
/***************/
void MSPI_VidWriteSPDR(u8 Copy_u8WriteSPDR)
{
	SPDR = Copy_u8WriteSPDR;
}

/***********************************************/
/**SPI passing address of Application Function**/
/***********************************************/
void MSPI_SetCallBack(void(*Copy_VidCallBack)(void))
{
	MSPI_CallBack = Copy_VidCallBack;
}

/*******************************/
/**ISR SPI Interrupt Function **/
/*******************************/
void __vector_12(void)
{
	MSPI_CallBack();
}
