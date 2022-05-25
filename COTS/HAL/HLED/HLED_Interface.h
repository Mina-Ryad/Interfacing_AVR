#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_

typedef struct{
	u8 Copy_u8Port;
	u8 Copy_u8Pin;
}LED_t;

#define HLED_PORT1 0
#define HLED_PORT2 1
#define HLED_PORT3 2
#define HLED_PORT4 3

typedef enum{
	LED0 = 0,
	LED1,
	LED2,
	LED3,
	LED4,
	LED5,
	LED6,
	LED7
}E_Led_t;

void HLED_VidInit(LED_t *Copy_Led);
void HLED_VidLed_On(LED_t *Copy_Led);
void HLED_VidLed_Off(LED_t *Copy_Led);
void HLED_VidLed_Toggle(LED_t *Copy_Led);

#endif