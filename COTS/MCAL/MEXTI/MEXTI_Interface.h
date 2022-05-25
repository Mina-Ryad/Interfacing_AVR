/*
 * MEXTI_Interface.h
 *
 *  Created on: Nov 15, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_

/*General Interrupt Flag Register*/
#define GENERAL_INTERRUPT_FLAG_REGISTER   GIFR
/*INTF0: External Interrupt Flag 0*/
#define EXTERNAL_INTERRUPT_FLAG_0   INTF0
/*INTF1: External Interrupt Flag 1*/
#define EXTERNAL_INTERRUPT_FLAG_1   INTF1
/*INTF2: External Interrupt Flag 2*/
#define EXTERNAL_INTERRUPT_FLAG_2   INTF2

/****************/
/** EXTI0 Init **/
/****************/
void MEXTI0_VidInit(void);

/* EXTI1 Init */
void MEXTI1_VidInit(void);

/****************/
/** EXTI2 Init **/
/****************/
void MEXTI2_VidInit(void);

/***********************************/
/***Select Sense Control Function **/
/***********************************/
void MEXTI_VidSenseControl(u8 Copy_u8EXTIE_ID, u8 Copy_u8SenseControl);

/***********************************/
/**General Interrupt Flag Register**/
/***********************************/
#define GENERAL_INTERRUPT_FLAG_REGISTER GIFR

/********************************************/
/**** External Interrupt 0 Set Call Back ****/
/********************************************/
void EXTI0_Set_CallBackFunction(void (*CallBackFunction)(void));

/********************************************/
/**** External Interrupt 1 Set Call Back ****/
/********************************************/
void EXTI1_Set_CallBackFunction(void (*CallBackFunction)(void));

/********************************************/
/**** External Interrupt 2 Set Call Back ****/
/********************************************/
void EXTI2_Set_CallBackFunction(void (*CallBackFunction)(void));

#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
