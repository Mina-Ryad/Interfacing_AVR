
#include "..\..\LIB\LSTD_TYPES.h"
#include "..\..\MCAL\MDIO\MDIO_Interface.h"
#include "HLED_Config.h"
#include "HLED_Interface.h"

void HLED_VidInit(LED_t *Copy_Led)
{
	MDIO_Error_State_SetPinDirection(Copy_Led->Copy_u8Pin, Copy_Led->Copy_u8Port, PIN_OUTPUT);
}
void HLED_VidLed_On(LED_t *Copy_Led)
{
	MDIO_Error_State_SetPinValue(Copy_Led->Copy_u8Pin, Copy_Led->Copy_u8Port, PIN_HIGH);
}
void HLED_VidLed_Off(LED_t *Copy_Led)
{
	MDIO_Error_State_SetPinValue(Copy_Led->Copy_u8Pin, Copy_Led->Copy_u8Port, PIN_LOW);
}
void HLED_VidLed_Toggle(LED_t *Copy_Led)
{
	static u8 Flag=0;
	if(Flag==0)
	{
		MDIO_Error_State_SetPinValue(LED_1_PIN, LED_1_PORT, PIN_HIGH);
		Flag=1;
	}
	else if(Flag==1)
	{
		MDIO_Error_State_SetPinValue(LED_1_PIN, LED_1_PORT, PIN_LOW);
		Flag=0;
	}
}
