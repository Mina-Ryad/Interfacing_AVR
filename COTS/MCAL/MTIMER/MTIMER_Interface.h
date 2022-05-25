/*
 * MTIMER_Interface.h
 *
 *  Created on: Nov 18, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MTIMER_MTIMER_INTERFACE_H_
#define MCAL_MTIMER_MTIMER_INTERFACE_H_

/*-----------------------------------------------------------------------------------*/
/*-------------------------------------- TIMER 0 ------------------------------------*/
/*-----------------------------------------------------------------------------------*/

/*******************************/
/*** Timer 0 Initialization ****/
/*******************************/
void MTIMER0_VidInit(void);

/*******************************/
/*** Set Preload Function ******/
/*******************************/
void MTIMER0_VidSetPreload(u8 Copy_u8Preload);

/*********************************/
/*** Set CTC Value Function ******/
/*********************************/
void MTIMER0_VidSetCTCValue(u8 Copy_u8SetCTCValue);

/*********************************/
/****** CTC Set Call Back ********/
/*********************************/
void MTIMER0_VidCTC_SetCallBack(void(*Copy_VidCallBack)(void));

/*********************************/
/**** Over Flow Set Call Back ****/
/*********************************/
void MTIMER0_VidOverFlow_SetCallBack(void(*Copy_VidCallBack)(void));


/*-----------------------------------------------------------------------------------*/
/*-------------------------------------- TIMER 1 ------------------------------------*/
/*-----------------------------------------------------------------------------------*/

/*******************************/
/*** Timer 1 Initialization ****/
/*******************************/
void MTIMER1_VidInit(void);

/*******************************/
/*** Set Preload Function ******/
/*******************************/
void MTIMER1_VidSetPreload(u16 Copy_u16Preload);

/*********************************/
/*** Set CTC_A Value Function ******/
/*********************************/
void MTIMER1_VidSetCTC_A_Value(u16 Copy_u16SetCTCValue);

/*********************************/
/*** Set CTC_B Value Function ******/
/*********************************/
void MTIMER1_VidSetCTC_B_Value(u16 Copy_u16SetCTCValue);

/***************************************************/
/**ICU ISR passing address of Application Function**/
/***************************************************/
void MTIMER1_VidICU_SetCallBack(void(*Copy_VidCallBack)(void));

/*****************************************************/
/**CTC_A ISR passing address of Application Function**/
/*****************************************************/
void MTIMER1_VidCTC_A_SetCallBack(void(*Copy_VidCallBack)(void));

/*****************************************************/
/**CTC_B ISR passing address of Application Function**/
/*****************************************************/
void MTIMER1_VidCTC_B_SetCallBack(void(*Copy_VidCallBack)(void));

/********************************************************/
/**OverFlow ISR passing address of Application Function**/
/********************************************************/
void MTIMER1_VidOverFlow_SetCallBack(void(*Copy_VidCallBack)(void));

/*********************************/
/*** Set ICR Value Function ******/
/*********************************/
void MTIMER1_VidSetICRValue(u16 Copy_u16SetCTCValue);

#endif /* MCAL_MTIMER_MTIMER_INTERFACE_H_ */
