/*
 * MWDT_Program.c
 *
 *  Created on: Nov 24, 2021
 *      Author: Mina-Ryad
 */

#include "..\..\LIB\LSTD_TYPES.h"
#include "..\..\LIB\LBIT_MATH.h"

#include "MWDT_Private.h"
#include "MWDT_Config.h"
#include "..\MDIO\MDIO_Interface.h"

void MWDT_VidEnable(void)
{
	SET_BIT(WDTCR,WDE);
}

void MWDT_VidDisable(void)
{
	WDTCR |= MWDT_DISABLE_MASK;
	CLR_BIT(WDTCR,WDE);
}

/* Watchdog Timer Prescale Select:
 *
 * WDP2 WDP1 WDP0 --- Typical Time-out at VCC = 5.0V
 *  0    0    0       16.3 ms
 *  0    0    1       32.5 ms
 *  0    1    0       65 ms
 *  0    1    1       0.13 s
 *  1    0    0       0.26 s
 *  1    0    1       0.52 s
 *  1    1    0       1.0 s
 *  1    1    1       2.1 s
 */
void MWDT_VidWDT_Sleep(u8 Copy_u8SleepValue)
{
	if ( Copy_u8SleepValue == MWDT_PRESCALER_16_3_MS)
	{
		CLR_BIT(WDTCR, WDP0);
		CLR_BIT(WDTCR, WDP1);
		CLR_BIT(WDTCR, WDP2);
	}
	else if (Copy_u8SleepValue == MWDT_PRESCALER_32_5_MS)
	{
		SET_BIT(WDTCR, WDP0);
		CLR_BIT(WDTCR, WDP1);
		CLR_BIT(WDTCR, WDP2);
	}
	else if (Copy_u8SleepValue == MWDT_PRESCALER_65_MS)
	{
		CLR_BIT(WDTCR, WDP0);
		SET_BIT(WDTCR, WDP1);
		CLR_BIT(WDTCR, WDP2);
	}
	else if (Copy_u8SleepValue == MWDT_PRESCALER_130_MS)
	{
		SET_BIT(WDTCR, WDP0);
		SET_BIT(WDTCR, WDP1);
		CLR_BIT(WDTCR, WDP2);
	}
	else if (Copy_u8SleepValue == MWDT_PRESCALER_260_MS)
	{
		CLR_BIT(WDTCR, WDP0);
		CLR_BIT(WDTCR, WDP1);
		SET_BIT(WDTCR, WDP2);
	}
	else if (Copy_u8SleepValue == MWDT_PRESCALER_520_MS)
	{
		SET_BIT(WDTCR, WDP0);
		CLR_BIT(WDTCR, WDP1);
		SET_BIT(WDTCR, WDP2);
	}
	else if (Copy_u8SleepValue == MWDT_PRESCALER_1_S)
	{
		CLR_BIT(WDTCR, WDP0);
		SET_BIT(WDTCR, WDP1);
		SET_BIT(WDTCR, WDP2);
	}
	else if (Copy_u8SleepValue == MWDT_PRESCALER_2_1_S)
	{
		SET_BIT(WDTCR, WDP0);
		SET_BIT(WDTCR, WDP1);
		SET_BIT(WDTCR, WDP2);
	}
	else
	{
		/*DO Nothing*/
	}
}
