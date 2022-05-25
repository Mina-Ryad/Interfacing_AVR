/*
 * MSPI_Interface.h
 *
 *  Created on: Nov 29, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MSPI_MSPI_INTERFACE_H_
#define MCAL_MSPI_MSPI_INTERFACE_H_

/*****************************/
/**SPI Master Initialization**/
/*****************************/
void MSPI_VidMasterInit(void);

/****************************/
/**SPI Slave Initialization**/
/****************************/
void MSPI_VidSlaveInit(void);

/*************************/
/**SPI Send Receive Data**/
/*************************/
u8 MSPI_u8SendReceiveData(u8 Copy_u8Send_Data);

/***************/
/**Return SPDR**/
/***************/
u8 MSPI_u8ReturnSPDR(void);

/***************/
/**Write SPDR **/
/***************/
void MSPI_VidWriteSPDR(u8 Copy_u8WriteSPDR);

/***********************************************/
/**SPI passing address of Application Function**/
/***********************************************/
void MSPI_SetCallBack(void(*Copy_VidCallBack)(void));

#endif /* MCAL_MSPI_MSPI_INTERFACE_H_ */
