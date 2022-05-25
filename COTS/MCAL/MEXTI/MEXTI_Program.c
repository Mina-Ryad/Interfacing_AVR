/*
 * MEXTI_Program.c
 *
 *  Created on: Nov 15, 2021
 *      Author: Mina-Ryad
 */
#include "..\..\LIB\LSTD_TYPES.h"
#include "..\..\LIB\LBIT_MATH.h"

#include "..\MDIO\MDIO_Interface.h"
#include "MEXTI_Private.h"
#include "MEXTI_Config.h"
#include "MEXTI_Interface.h"

/*Pointer to Function Declaration (Call Back Function Pointer)*/
void (*CallBackFunction)(void);

/*ISR External Interrupt 0 Declaration */
void __vector_1(void)   __attribute__((signal));

/*ISR External Interrupt 1 Declaration */
void __vector_2(void)   __attribute__((signal));

/*ISR External Interrupt 2 Declaration */
void __vector_3(void)   __attribute__((signal));

/******************************/
/** External Intrrupt 0 Init **/
/******************************/

/* External Intrrupt 0 Sense Control
 * ---------------------------------
 *	ISC01 ISC00 Description
 *	--------------------------------------------------------------------
 *	  0     0     The low level of INT0 generates an interrupt request.
 *	  0     1     Any logical change on INT0 generates an interrupt request.
 *	  1     0     The falling edge of INT0 generates an interrupt request.
 *	  1     1     The rising edge of INT0 generates an interrupt request.
*/
void MEXTI0_VidInit(void)
{
#if MEXTI0_SET_SENSE_CONTROL == MEXTI_LOW_LEVEL
	CLR_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#elif MEXTI0_SET_SENSE_CONTROL == MEXTI_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#elif MEXTI0_SET_SENSE_CONTROL == MEXTI_FALLING_EDGE
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#elif MEXTI0_SET_SENSE_CONTROL == MEXTI_RISING_EDGE
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#else
	#error "Sense Control Option is Not Valid..."
#endif

	/* Enable EXTI0*/
	SET_BIT(GICR,INT0);
}

/******************************/
/** External Intrrupt 0 Init **/
/******************************/

/* Interrupt 1 Sense Control
 * ISC11 ISC10 Description
 *   0     0      The low level of INT1 generates an interrupt request.
 *   0     1      Any logical change on INT1 generates an interrupt request.
 *   1     0      The falling edge of INT1 generates an interrupt request.
 *   1     1      The rising edge of INT1 generates an interrupt request.
 * */

void MEXTI1_VidInit(void)
{
#if MEXTI1_SET_SENSE_CONTROL == MEXTI_LOW_LEVEL
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif MEXTI1_SET_SENSE_CONTROL == MEXTI_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif MEXTI1_SET_SENSE_CONTROL == MEXTI_FALLING_EDGE
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#elif MEXTI1_SET_SENSE_CONTROL == MEXTI_RISING_EDGE
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#else
	#error "Sense Control Option is Not Valid..."
#endif

	/* Enable EXTI0*/
	SET_BIT(GICR,INT1);
}

/******************************/
/** External Intrrupt 0 Init **/
/******************************/

/* Bit 6 – ISC2: Interrupt Sense Control 2
 * --------------------------------------------------------------------------
 * If ISC2 is written to zero, a falling edge on INT2 activates the interrupt.
 * If ISC2 is written to one, a rising edge on INT2 activates the interrupt.
*/
void MEXTI2_VidInit(void)
{

#if MEXTI2_SET_SENSE_CONTROL == MEXTI_FALLING_EDGE
	CLR_BIT(MCUCSR,ISC2);
#elif MEXTI2_SET_SENSE_CONTROL == MEXTI_RISING_EDGE
	SET_BIT(MCUCSR,ISC2);
#else
	#error "Sense Control Option is Not Valid..."
#endif

	/* Enable EXTI0*/
	SET_BIT(GICR,INT2);
}

/************************************/
/** Select Sense Control Function ***/
/************************************/

/*	Interrupt 0 Sense Control
 * **************************
 * • Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0
 * ----------------------------------------------------------------------
 *  ISC01 ISC00 Description
 * 	---------------------------------------------------------------------
 * 	  0     0     The low level of INT0 generates an interrupt request.
 * 	  0     1     Any logical change on INT0 generates an interrupt request.
 * 	  1     0     The falling edge of INT0 generates an interrupt request.
 * 	  1     1     The rising edge of INT0 generates an interrupt request.
 *------------------------------------------------------------------------
 * Interrupt 1 Sense Control
 * *************************
 * ISC11 ISC10 Description
 * -----------------------------------------------------------------------
 *   0     0      The low level of INT1 generates an interrupt request.
 *   0     1      Any logical change on INT1 generates an interrupt request.
 *   1     0      The falling edge of INT1 generates an interrupt request.
 *   1     1      The rising edge of INT1 generates an interrupt request.
 *-------------------------------------------------------------------------
 * Interrupt Sense Control 2
 * *************************
 * Bit 6 – ISC2:
 * --------------------------------------------------------------------------
 * If ISC2 is written to zero, a falling edge on INT2 activates the interrupt.
 * If ISC2 is written to one, a rising edge on INT2 activates the interrupt.
 */
void MEXTI_VidSenseControl(u8 Copy_u8EXTIE_ID, u8 Copy_u8SenseControl)
{
	switch (Copy_u8EXTIE_ID)
	{
	case EXTI0:
		if (Copy_u8SenseControl == MEXTI_LOW_LEVEL)
		{
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
		}
		else if (Copy_u8SenseControl == MEXTI_ANY_LOGICAL_CHANGE)
		{
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
		}
		else if (Copy_u8SenseControl == MEXTI_FALLING_EDGE)
		{
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
		}
		else if (Copy_u8SenseControl == MEXTI_RISING_EDGE)
		{
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	case EXTI1:
		if (Copy_u8SenseControl == MEXTI_LOW_LEVEL)
		{
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
		}
		else if (Copy_u8SenseControl == MEXTI_ANY_LOGICAL_CHANGE)
		{
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
		}
		else if (Copy_u8SenseControl == MEXTI_FALLING_EDGE)
		{
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}
		else if (Copy_u8SenseControl == MEXTI_RISING_EDGE)
		{
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	case EXTI2:
		if (Copy_u8SenseControl == MEXTI_FALLING_EDGE)
		{
			CLR_BIT(MCUCSR,ISC2);
		}
		else if (Copy_u8SenseControl == MEXTI_RISING_EDGE)
		{
			SET_BIT(MCUCSR,ISC2);
		}
		else
		{
			/*Do Nothing */
		}
		break;
	}
}

/********************************************/
/**** External Interrupt 0 Set Call Back ****/
/********************************************/
void EXTI0_Set_CallBackFunction(void(*Copy_VidCallBcakFunction)(void))
{
	CallBackFunction = Copy_VidCallBcakFunction ;
}

/********************************************/
/**** External Interrupt 1 Set Call Back ****/
/********************************************/
void EXTI1_Set_CallBackFunction(void(*Copy_VidCallBcakFunction)(void))
{
	CallBackFunction = Copy_VidCallBcakFunction ;
}

/********************************************/
/**** External Interrupt 2 Set Call Back ****/
/********************************************/
void EXTI2_Set_CallBackFunction(void(*Copy_VidCallBcakFunction)(void))
{
	CallBackFunction = Copy_VidCallBcakFunction ;
}

/************************************************/
/**ISR External Interrupt 0 Interrupt Function **/
/************************************************/
void __vector_1(void)
{
	CallBackFunction();
}

/************************************************/
/**ISR External Interrupt 1 Interrupt Function **/
/************************************************/
void __vector_2(void)
{
	CallBackFunction();
}

/************************************************/
/**ISR External Interrupt 2 Interrupt Function **/
/************************************************/
void __vector_3(void)
{
	CallBackFunction();
}

