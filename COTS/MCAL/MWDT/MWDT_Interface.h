/*
 * MWDT_Interface.h
 *
 *  Created on: Nov 24, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MWDT_MWDT_INTERFACE_H_
#define MCAL_MWDT_MWDT_INTERFACE_H_

void MWDT_VidEnable(void);

void MWDT_VidDisable(void);

/* Copy_u8SleepValue Options:
 * 1- 0-->16.3ms
 * 2- 1-->32.5ms
 * 3- 2-->65ms
 * 4- 3-->0.13
 * 5- 4-->0.26
 * 6- 5-->0.52
 * 7- 6-->1 s
 * 8- 7-->2.1 s
 * */
void MWDT_VidWDT_Sleep(u8 Copy_u8SleepValue);


#endif /* MCAL_MWDT_MWDT_INTERFACE_H_ */
