/*
 * HSTEPPER_Interface.h
 *
 *  Created on: Nov 17, 2021
 *      Author: Mina-Ryad
 */

#ifndef HAL_HSTEPPER_HSTEPPER_INTERFACE_H_
#define HAL_HSTEPPER_HSTEPPER_INTERFACE_H_

/*Stepper Motor Initialization*/
void HStepper_VidInit(void);

/*Stepper Motor Angle and Speed Control*/
void HStepper_VidForward_Angle_delay(u32 Copy_u32Angle,u16 Copy_u16ForwardSpeed);




#endif /* HAL_HSTEPPER_HSTEPPER_INTERFACE_H_ */
