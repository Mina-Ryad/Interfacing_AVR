/*
 * MTIMER_Program.c
 *
 *  Created on: Nov 18, 2021
 *      Author: Mina-Ryad
 */


#include "..\..\LIB\LSTD_TYPES.h"
#include "..\..\LIB\LBIT_MATH.h"
#include "..\MDIO\MDIO_Interface.h"
#include "MTIMER_Private.h"
#include "MTIMER_Config.h"

/*-----------------------------------------------------------------------------------*/
/*-------------------------------------- TIMER 0 ------------------------------------*/
/*-----------------------------------------------------------------------------------*/

/*Pointer to Function Declaration (Call Back Function Pointer)*/
void (*MTIMER0_CallBack)(void);

/*ISR CTC Interrupt Declaration */
void __vector_10(void) __attribute__((signal));

/*ISR OverFlow Interrupt Declaration */
void __vector_11(void) __attribute__((signal));

/*******************************/
/*** Timer 0 Initialization ****/
/*******************************/
void MTIMER0_VidInit(void)
{
	/*Select Prescaling */
	TCCR0 &= TIMER_CLOCK_SELECT_MASK;
	TCCR0 |= TIMER0_SET_PRESCALER;

/* Waveform Generation Mode Bit Description
 * -------------------------------------------------------------------------------------------------
 * WGM01  WGM00 Timer/Counter Mode of Operation--TOP-----Update of OCR0--TOV0 Flag Set-on
 * -------------------------------------------------------------------------------------------------
 *   0       0        Normal                     0xFF     Immediate           MAX
 *   0       1        PWM, Phase Correct         0xFF     TOP                BOTTOM
 *   1       0        CTC                        OCR0     Immediate           MAX
 *   1       1        Fast PWM                   0xFF     TOP                 MAX
*/

#if TIMER0_SET_MODE == TIMER0_NORMAL_MODE
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif TIMER0_SET_MODE == TIMER0_PWM_PAHSE_CORRECT_MODE
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#elif TIMER0_SET_MODE == TIMER0_CTC_MODE
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
#elif TIMER0_SET_MODE == TIMER0_FAST_PWM_MODE
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
#else
	#error "Timer0 Mode is Not Valid..."
#endif

/* Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
 * When the TOIE0 bit is written to one, and the I-bit in the Status Register is set (one), the
 * Timer/Counter0 Overflow interrupt is enabled. The corresponding interrupt is executed if
 * an overflow in Timer/Counter0 occurs, i.e., when the TOV0 bit is set in the
 * Timer/Counter Interrupt Flag Register – TIFR.
* */
#if TIMER0_SET_OVERFLOW_INTERRUPT == TIMER0_SET_OVERFLOW_INTERRUPT_ENABELED
	SET_BIT(TIMSK,TOIE0);
#elif TIMER0_SET_OVERFLOW_INTERRUPT == TIMER0_SET_OVERFLOW_INTERRUPT_DISABLED
	CLR_BIT(TIMSK,TOIE0);
#else
	#error "Timer0 Set OverFlow Interrupt is Not Valid..."
#endif

/*	Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
 * --------------------------------------------------------------------
 * When the OCIE0 bit is written to one, and the I-bit in the Status Register is set (one), the
 * Timer/Counter0 Compare Match interrupt is enabled. The corresponding interrupt is
 * executed if a compare match in Timer/Counter0 occurs,
 */
#if TIMER0_SET_CTC_INTERRUPT == TIMER0_SET_CTC_INTERRUPT_ENABELED
	SET_BIT(TIMSK,OCIE0);
#elif TIMER0_SET_CTC_INTERRUPT == TIMER0_SET_CTC_INTERRUPT_DISABLED
	CLR_BIT(TIMSK,OCIE0);
#else
	#error "Timer0 Set CTC Interrupt is Not Valid..."
#endif

/* Compare Output Mode, non-PWM Mode
	COM01 COM00 Description
	  0     0       Normal port operation, OC0 disconnected.
	  0     1       Toggle OC0 on compare match
	  1     0       Clear OC0 on compare match
	  1     1       Set OC0 on compare match
*/
#if TIMER0_SET_OC0_PIN_MODE == TIMER0_OC0_PIN_DISCONNECTED
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif TIMER0_SET_OC0_PIN_MODE == TIMER0_OC0_PIN_TOGGLE
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
#elif TIMER0_SET_OC0_PIN_MODE == TIMER0_OC0_PIN_SET
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#elif TIMER0_SET_OC0_PIN_MODE == TIMER0_OC0_PIN_CLR
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
#else
	#error "TIMER0 CTC OC0 Mode is not valid..."
#endif
}

/*******************************/
/*** Set Preload Function ******/
/*******************************/
void MTIMER0_VidSetPreload(u8 Copy_u8Preload)
{
	TCNT0 = Copy_u8Preload;
}

/*********************************/
/*** Set CTC Value Function ******/
/*********************************/
void MTIMER0_VidSetCTCValue(u8 Copy_u8SetCTCValue)
{
	OCR0 = Copy_u8SetCTCValue;
}

/***************************************************/
/**CTC ISR passing address of Application Function**/
/***************************************************/
void MTIMER0_VidCTC_SetCallBack(void(*Copy_VidCallBack)(void))
{
	MTIMER0_CallBack = Copy_VidCallBack;
}

/********************************************************/
/**OverFlow ISR passing address of Application Function**/
/********************************************************/
void MTIMER0_VidOverFlow_SetCallBack(void(*Copy_VidCallBack)(void))
{
	MTIMER0_CallBack = Copy_VidCallBack;
}

/*******************************/
/**ISR CTC Interrupt Function **/
/*******************************/
void __vector_10(void)
{
	MTIMER0_CallBack();
}

/************************************/
/**ISR OverFlow Interrupt Function **/
/************************************/
void __vector_11(void)
{
	MTIMER0_CallBack();
}

/*-----------------------------------------------------------------------------------*/
/*-------------------------------------- TIMER 1 ------------------------------------*/
/*-----------------------------------------------------------------------------------*/

/*Pointer to Function Declaration (Call Back Function Pointer)*/
void (*MTIMER1_CallBack)(void);

/*ISR ICU Interrupt Declaration */
void __vector_6(void) __attribute__((signal));

/*ISR CTC-A Interrupt Declaration */
void __vector_7(void) __attribute__((signal));

/*ISR CTC-B Interrupt Declaration */
void __vector_8(void) __attribute__((signal));

/*ISR OverFlow Interrupt Declaration */
void __vector_9(void) __attribute__((signal));

/*******************************/
/*** Timer 1 Initialization ****/
/*******************************/
void MTIMER1_VidInit(void)
{
	/*Select Prescaling */
	TCCR1B &= TIMER_CLOCK_SELECT_MASK;
	TCCR1B |= TIMER1_SET_PRESCALER;

	/* Waveform Generation Mode Bit Description(1)
	 * --------------------------------------------------------------------------------------------------------------------
	 * Mode WGM13 WGM12  WGM11 WGM10 ---- Timer/Counter Mode of Operation ---- TOP ---- Update of OCR1x -- TOV1 Flag Set on
	 * --------------------------------------------------------------------------------------------------------------------
	 *  0     0     0     0     0         Normal                               0xFFFF   Immediate          MAX
	 *  1     0     0     0     1         PWM, Phase Correct, 8-bit            0x00FF   TOP                BOTTOM
	 *  2     0     0     1     0         PWM, Phase Correct, 9-bit            0x01FF   TOP                BOTTOM
	 *  3     0     0     1     1         PWM, Phase Correct, 10-bit           0x03FF   TOP                BOTTOM
	 *  4     0     1     0     0         CTC                                  OCR1A    Immediate          MAX
	 *  5     0     1     0     1         Fast PWM, 8-bit                      0x00FF   TOP                TOP
	 *  6     0     1     1     0         Fast PWM, 9-bit                      0x01FF   TOP                TOP
	 *  7     0     1     1     1         Fast PWM, 10-bit                     0x03FF   TOP                TOP
	 *  8     1     0     0     0         PWM, Phase and Frequency Correct     ICR1     BOTTOM             BOTTOM
	 *  9     1     0     0     1         PWM, Phase and Frequency Correct     OCR1A    BOTTOM             BOTTOM
	 *  10    1     0     1     0         PWM, Phase Correct                   ICR1     TOP                BOTTOM
	 *  11    1     0     1     1         PWM, Phase Correct                   OCR1A    TOP                BOTTOM
	 *  12    1     1     0     0         CTC                                  ICR1     Immediate          MAX
	 *  13    1     1     0     1         Reserved – – –
	 *  14    1     1     1     0         Fast PWM                             ICR1     TOP                TOP
	 *  15    1     1     1     1         Fast PWM                             OCR1A    TOP                TOP
	*/

	#if TIMER1_SET_MODE == TIMER1_NORMAL_MODE
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_8BIT
		SET_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_9BIT
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_10BIT
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_CTC_MODE_OCR1A_TOP
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_PWM_FAST_8BIT
		SET_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_PWM_FAST_9BIT
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_PWM_FAST_10BIT
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR1_TOP
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR1A_TOP
		SET_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_ICR1_TOP
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_PWM_PHASE_CORRECT_OCR1A_TOP
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_FAST_PWM_ICR1_TOP
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_SET_MODE == TIMER1_FAST_PWM_OCR1A_TOP
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
	#else
		#error "Timer1 Mode is Not Valid..."
	#endif

	/* TICIE1: Timer/Counter1, Input Capture Interrupt Enable*/
	#if TIMER1_SET_ICU_INTERRUPT == TIMER1_SET_ICU_INTERRUPT_ENABELED
		SET_BIT(TIMSK,TICIE1);
	#elif TIMER1_SET_ICU_INTERRUPT == TIMER1_SET_ICU_INTERRUPT_DISABLED
		CLR_BIT(TIMSK,TICIE1);
	#else
		#error "Timer 1 Set ICU Interrupt is Not Valid..."
	#endif

	/* OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable*/
	#if TIMER1_SET_CTC_A_INTERRUPT == TIMER1_SET_CTC_A_INTERRUPT_ENABELED
		SET_BIT(TIMSK,OCIE1A);
	#elif TIMER1_SET_CTC_A_INTERRUPT == TIMER1_SET_CTC_A_INTERRUPT_DISABLED
		CLR_BIT(TIMSK,OCIE1A);
	#else
		#error "Timer 1 Set CTC_A Interrupt is Not Valid..."
	#endif

	/* OCIE1B: Timer/Counter1, Output Compare B Match Interrupt Enable*/
	#if TIMER1_SET_CTC_B_INTERRUPT == TIMER1_SET_CTC_B_INTERRUPT_ENABELED
		SET_BIT(TIMSK,OCIE1B);
	#elif TIMER1_SET_CTC_B_INTERRUPT == TIMER1_SET_CTC_B_INTERRUPT_DISABLED
		CLR_BIT(TIMSK,OCIE1B);
	#else
		#error "Timer 1 Set CTC_B Interrupt is Not Valid..."
	#endif

	/* TOIE1: Timer/Counter1, Overflow Interrupt Enable*/
	#if TIMER1_SET_OVERFLOW_INTERRUPT == TIMER1_SET_OVERFLOW_INTERRUPT_ENABELED
		SET_BIT(TIMSK,TOIE1);
	#elif TIMER1_SET_OVERFLOW_INTERRUPT == TIMER1_SET_OVERFLOW_INTERRUPT_DISABLED
		CLR_BIT(TIMSK,TOIE1);
	#else
		#error "Timer 1 Set OverFlow Interrupt is Not Valid..."
	#endif

	/*Compare Output Mode, non-PWM
	  ---------------------------------------------------------------------------------------------
	  COM1A1/COM1B1 --- COM1A0/COM1B0 --- Description
	  ---------------------------------------------------------------------------------------------
			0                 0           Normal port operation, OC1A/OC1B disconnected.
			0                 1           Toggle OC1A/OC1B on compare match
			1                 0           Clear OC1A/OC1B on compare match (Set output to low level)
			1                 1           Set OC1A/OC1B on compare match (Set output to high level)
	*/
	/* PIN OC1 A*/
	#if TIMER1_SET_OC1A_PIN_MODE == TIMER1_OC1A_PIN_DISCONNECTED
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
	#elif TIMER1_SET_OC1A_PIN_MODE == TIMER1_OC1A_PIN_TOGGLE
		SET_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
	#elif TIMER1_SET_OC1A_PIN_MODE == TIMER1_OC1A_PIN_CLR
		CLR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
	#elif TIMER1_SET_OC1A_PIN_MODE == TIMER1_OC1A_PIN_SET
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
	#else
		#error "TIMER 1 CTC OC1_A Mode is not valid..."
	#endif
	/* PIN OC1 B*/
	#if TIMER1_SET_OC1B_PIN_MODE == TIMER1_OC1B_PIN_DISCONNECTED
		CLR_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1B1);
	#elif TIMER1_SET_OC1B_PIN_MODE == TIMER1_OC1B_PIN_TOGGLE
		SET_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1B1);
	#elif TIMER1_SET_OC1B_PIN_MODE == TIMER1_OC1B_PIN_CLR
		CLR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
	#elif TIMER1_SET_OC1B_PIN_MODE == TIMER1_OC1B_PIN_SET
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
	#else
		#error "TIMER 1 CTC OC1_B Mode is not valid..."
	#endif
}

/*******************************/
/*** Set Preload Function ******/
/*******************************/
void MTIMER1_VidSetPreload(u16 Copy_u16Preload)
{
	TCNT1 = Copy_u16Preload;
}

/*********************************/
/*** Set CTC_A Value Function ******/
/*********************************/
void MTIMER1_VidSetCTC_A_Value(u16 Copy_u16SetCTCValue)
{
	OCR1A = Copy_u16SetCTCValue;
}

/*********************************/
/*** Set CTC_B Value Function ******/
/*********************************/
void MTIMER1_VidSetCTC_B_Value(u16 Copy_u16SetCTCValue)
{
	OCR1B = Copy_u16SetCTCValue;
}

/*********************************/
/*** Set ICR Value Function ******/
/*********************************/
void MTIMER1_VidSetICRValue(u16 Copy_u16SetCTCValue)
{
	ICR1 = Copy_u16SetCTCValue;
}

/***************************************************/
/**ICU ISR passing address of Application Function**/
/***************************************************/
void MTIMER1_VidICU_SetCallBack(void(*Copy_VidCallBack)(void))
{
	MTIMER1_CallBack = Copy_VidCallBack;
}

/*****************************************************/
/**CTC_A ISR passing address of Application Function**/
/*****************************************************/
void MTIMER1_VidCTC_A_SetCallBack(void(*Copy_VidCallBack)(void))
{
	MTIMER1_CallBack = Copy_VidCallBack;
}

/*****************************************************/
/**CTC_B ISR passing address of Application Function**/
/*****************************************************/
void MTIMER1_VidCTC_B_SetCallBack(void(*Copy_VidCallBack)(void))
{
	MTIMER1_CallBack = Copy_VidCallBack;
}

/********************************************************/
/**OverFlow ISR passing address of Application Function**/
/********************************************************/
void MTIMER1_VidOverFlow_SetCallBack(void(*Copy_VidCallBack)(void))
{
	MTIMER1_CallBack = Copy_VidCallBack;
}

/*******************************/
/**ISR ICU Interrupt Function **/
/*******************************/
void __vector_6(void)
{
	MTIMER1_CallBack();
}

/**********************************/
/** ISR CTC_A Interrupt Function **/
/**********************************/
void __vector_7(void)
{
	MTIMER1_CallBack();
}
/*********************************/
/**ISR CTC_B Interrupt Function **/
/*********************************/
void __vector_8(void)
{
	MTIMER1_CallBack();
}

/************************************/
/**ISR OverFlow Interrupt Function **/
/************************************/
void __vector_9(void)
{
	MTIMER1_CallBack();
}





