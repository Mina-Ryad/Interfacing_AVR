/*
 * MEXTI_Private.h
 *
 *  Created on: Nov 15, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_

/*MCU Control Register – MCUCR*/
#define MCUCR *((volatile u8* )0x55)

/*MCU Control and Status Register – MCUCSR*/
#define MCUCSR *((volatile u8* )0x54)

/*General Interrupt Control Register – GICR*/
#define GICR *((volatile u8* )0x5B)

/*General Interrupt Flag Register – GIFR*/
#define GIFR *((volatile u8* )0x5A)

/*INTF0: External Interrupt Flag 0*/
#define INTF0 PIN6
/*INTF1: External Interrupt Flag 1*/
#define INTF1 PIN7
/*INTF2: External Interrupt Flag 2*/
#define INTF2 PIN5

/*External Interrupt 0 Control Bits*/
#define ISC00 PIN0
#define ISC01 PIN1

/*External Interrupt 1 Control Bits*/
#define ISC10 PIN2
#define ISC11 PIN3

/*External Interrupt 2 Control Bit */
#define ISC2 PIN6

/*General Intrrupt Control Bits*/
#define INT0 PIN6
#define INT1 PIN7
#define INT2 PIN5

/*External Interrupt Selection*/
#define EXTI0 0
#define EXTI1 1
#define EXTI2 2

/*External Interrupt Modes Selection*/
#define MEXTI_LOW_LEVEL				0
#define MEXTI_ANY_LOGICAL_CHANGE	1
#define MEXTI_FALLING_EDGE			2
#define MEXTI_RISING_EDGE			3

#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
