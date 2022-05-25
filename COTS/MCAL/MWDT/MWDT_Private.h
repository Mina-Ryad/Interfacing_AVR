/*
 * MWDT_Private.h
 *
 *  Created on: Nov 24, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MWDT_MWDT_PRIVATE_H_
#define MCAL_MWDT_MWDT_PRIVATE_H_

/*Watchdog Timer Control Register*/
#define WDTCR		*((volatile u8*)0x41)
#define WDP0		PIN0
#define WDP1		PIN1
#define WDP2		PIN2
#define WDE			PIN3
#define WDTOE		PIN4

/* Setting these two bits at the same instruction and then clearing WDE, disables WDT
 * WDTOE: Watchdog Turn-off Enable
 * WDE: Watchdog Enable
 * */
#define MWDT_DISABLE_MASK 0b00011000


#endif /* MCAL_MWDT_MWDT_PRIVATE_H_ */
