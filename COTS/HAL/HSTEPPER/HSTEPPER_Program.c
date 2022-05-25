/*
 * HSTEPPER_Program.c
 *
 *  Created on: Nov 17, 2021
 *      Author: Mina-Ryad
 */

#include "..\..\LIB\LSTD_TYPES.h"
#include "..\..\LIB\LBIT_MATH.h"

#include "..\..\MCAL\MDIO\MDIO_Config.h"
#include "..\..\MCAL\MDIO\MDIO_Interface.h"
#include "HSTEPPER_Config.h"

#include "util\delay.h"



void HStepper_VidInit(void)
{
	MDIO_Error_State_SetPinDirection(HSTEPPER_BLUE,MDIO_PORTD,PIN_OUTPUT);
	MDIO_Error_State_SetPinDirection(HSTEPPER_PINK,MDIO_PORTD,PIN_OUTPUT);
	MDIO_Error_State_SetPinDirection(HSTEPPER_YELLOW,MDIO_PORTD,PIN_OUTPUT);
	MDIO_Error_State_SetPinDirection(HSTEPPER_ORANGE,MDIO_PORTD,PIN_OUTPUT);
}

void HStepper_VidForward_Angle_delay (u32 Copy_u32Angle,u16 Copy_u16ForwardSpeed)
{
	u8 LOC_u8LoopCounter;
	u32 LOC_u32LoopMaximum;
	/* 1 step = 0.176 degree */
	/* (Angle / 1_Step_Angle) */
	LOC_u32LoopMaximum=((Copy_u32Angle*1000)/(176))/4;

	for( LOC_u8LoopCounter=0;LOC_u8LoopCounter<=LOC_u32LoopMaximum;LOC_u8LoopCounter++)
	{
		MDIO_Error_State_SetPinValue(HSTEPPER_BLUE,MDIO_PORTD,PIN_LOW);
		MDIO_Error_State_SetPinValue(HSTEPPER_PINK,MDIO_PORTD,PIN_HIGH);
		MDIO_Error_State_SetPinValue(HSTEPPER_YELLOW,MDIO_PORTD,PIN_HIGH);
		MDIO_Error_State_SetPinValue(HSTEPPER_ORANGE,MDIO_PORTD,PIN_HIGH);
		_delay_ms(Copy_u16ForwardSpeed);

		MDIO_Error_State_SetPinValue(HSTEPPER_BLUE,MDIO_PORTD,PIN_HIGH);
		MDIO_Error_State_SetPinValue(HSTEPPER_PINK,MDIO_PORTD,PIN_LOW);
		MDIO_Error_State_SetPinValue(HSTEPPER_YELLOW,MDIO_PORTD,PIN_HIGH);
		MDIO_Error_State_SetPinValue(HSTEPPER_ORANGE,MDIO_PORTD,PIN_HIGH);
		_delay_ms(Copy_u16ForwardSpeed);

		MDIO_Error_State_SetPinValue(HSTEPPER_BLUE,MDIO_PORTD,PIN_HIGH);
		MDIO_Error_State_SetPinValue(HSTEPPER_PINK,MDIO_PORTD,PIN_HIGH);
		MDIO_Error_State_SetPinValue(HSTEPPER_YELLOW,MDIO_PORTD,PIN_LOW);
		MDIO_Error_State_SetPinValue(HSTEPPER_ORANGE,MDIO_PORTD,PIN_HIGH);
		_delay_ms(Copy_u16ForwardSpeed);

		MDIO_Error_State_SetPinValue(HSTEPPER_BLUE,MDIO_PORTD,PIN_HIGH);
		MDIO_Error_State_SetPinValue(HSTEPPER_PINK,MDIO_PORTD,PIN_HIGH);
		MDIO_Error_State_SetPinValue(HSTEPPER_YELLOW,MDIO_PORTD,PIN_HIGH);
		MDIO_Error_State_SetPinValue(HSTEPPER_ORANGE,MDIO_PORTD,PIN_LOW);
		_delay_ms(Copy_u16ForwardSpeed);
	}
}
