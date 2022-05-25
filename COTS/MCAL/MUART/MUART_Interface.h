/*
 * MUART_Interface.h
 *
 *  Created on: Nov 25, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MUART_MUART_INTERFACE_H_
#define MCAL_MUART_MUART_INTERFACE_H_

void MUART_VidInit(void);

void MUART_VidSendChar(u8 Copy_u8Data);

u8 MUART_u8RecieveData(void);

void MUART_VidSendString(u8 *Copy_u8Data);

void MUART_RX_SetCallBack(void(*Copy_VidCallBack)(void));

void MUART_TX_SetCallBack(void(*Copy_VidCallBack)(void));

void MUART_UDR_Empty_SetCallBack(void(*Copy_VidCallBack)(void));

void MUART_VidSendString(u8*Copy_u8Array);

#endif /* MCAL_MUART_MUART_INTERFACE_H_ */
