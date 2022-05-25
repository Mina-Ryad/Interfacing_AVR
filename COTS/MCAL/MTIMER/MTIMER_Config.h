/*
 * MTIMER_Config.h
 *
 *  Created on: Nov 18, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MTIMER_MTIMER_CONFIG_H_
#define MCAL_MTIMER_MTIMER_CONFIG_H_

/*-----------------------------------------------------------------------------------*/
/*-------------------------------------- TIMER 0 ------------------------------------*/
/*-----------------------------------------------------------------------------------*/

/*Timer 0 Prescaler Options:
 * ------------------------
 * 0- TIMER_STOPPED
 * 1- TIMER_NO_PRESCALER
 * 2- TIMER_8_PRESCALER
 * 3- TIMER_64_PRESCALER
 * 4- TIMER_256_PRESCALER
 * 5- TIMER_1024_PRESCALER
 * 6- TIMER_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE
 * 7- TIMER_EXTERNAL_CLOCK_SOURCE_RISING_EDGE
 * */
#define TIMER0_SET_PRESCALER TIMER_1024_PRESCALER

/*TIMER0 Modes Options:
 * -------------------
 * 1- TIMER0_NORMAL_MODE
 * 2- TIMER0_CTC_MODE
 * 3- TIMER0_PHASECORRECT_PWM_MODE
 * 4- TIMER0_FAST_PWM_MODE
 */

#define TIMER0_SET_MODE   TIMER0_NORMAL_MODE

/*Timer 0 CTC Interrupt Options:
 * ----------------------------
 * 1- TIMER0_SET_OVERFLOW_INTERRUPT_ENABELED
 * 2- TIMER0_SET_OVERFLOW_INTERRUPT_DISABLED
 * */
#define TIMER0_SET_OVERFLOW_INTERRUPT TIMER0_SET_OVERFLOW_INTERRUPT_ENABELED

/*Timer 0 CTC Interrupt Options:
 * ----------------------------
 * 1- TIMER0_SET_CTC_INTERRUPT_ENABELED
 * 2- TIMER0_SET_CTC_INTERRUPT_DISABLED
 * */
#define TIMER0_SET_CTC_INTERRUPT TIMER0_SET_CTC_INTERRUPT_DISABLED

/* Timer 0 CTC 0C0 Pin Options:
 * ---------------------------
 * 1- TIMER0_OC0_PIN_DISCONNECTED
 * 2- TIMER0_OC0_PIN_TOGGLE
 * 3- TIMER0_OC0_PIN_SET
 * 4- TIMER0_OC0_PIN_CLR
 * */
#define TIMER0_SET_OC0_PIN_MODE TIMER0_OC0_PIN_DISCONNECTED


/*-----------------------------------------------------------------------------------*/
/*-------------------------------------- TIMER 1 ------------------------------------*/
/*-----------------------------------------------------------------------------------*/

/*Timer 1 Prescaler Options:
 * ------------------------
 * 0- TIMER_STOPPED
 * 1- TIMER_NO_PRESCALER
 * 2- TIMER_8_PRESCALER
 * 3- TIMER_64_PRESCALER
 * 4- TIMER_256_PRESCALER
 * 5- TIMER_1024_PRESCALER
 * 6- TIMER_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE
 * 7- TIMER_EXTERNAL_CLOCK_SOURCE_RISING_EDGE
 * */
#define TIMER1_SET_PRESCALER TIMER_NO_PRESCALER

/*Timer 1 ICU Interrupt Options:
 * ----------------------------
 * 1- TIMER1_SET_ICU_INTERRUPT_ENABELED
 * 2- TIMER1_SET_ICU_INTERRUPT_DISABLED
 * */
#define TIMER1_SET_ICU_INTERRUPT TIMER1_SET_ICU_INTERRUPT_DISABLED

/*Timer 1 CTC_A Interrupt Options:
 * ----------------------------
 * 1- TIMER1_SET_CTC_A_INTERRUPT_ENABELED
 * 2- TIMER1_SET_CTC_A_INTERRUPT_DISABLED
 * */
#define TIMER1_SET_CTC_A_INTERRUPT TIMER1_SET_CTC_A_INTERRUPT_DISABLED

/*Timer 1 CTC_B Interrupt Options:
 * ----------------------------
 * 1- TIMER1_SET_CTC_B_INTERRUPT_ENABELED
 * 2- TIMER1_SET_CTC_B_INTERRUPT_DISABLED
 * */
#define TIMER1_SET_CTC_B_INTERRUPT TIMER1_SET_CTC_B_INTERRUPT_DISABLED

/*Timer 1 OverFlow Interrupt Options:
 * ----------------------------
 * 1- TIMER1_SET_OVERFLOW_INTERRUPT_ENABELED
 * 2- TIMER1_SET_OVERFLOW_INTERRUPT_DISABLED
 * */
#define TIMER1_SET_OVERFLOW_INTERRUPT TIMER1_SET_OVERFLOW_INTERRUPT_DISABLED

/*TIMER1 Modes Options:
 * -------------------
 * 0- TIMER1_NORMAL_MODE
 * 1- TIMER1_PWM_PHASE_CORRECT_8BIT
 * 2- TIMER1_PWM_PHASE_CORRECT_9BIT
 * 3- TIMER1_PWM_PHASE_CORRECT_10BIT
 * 4- TIMER1_CTC_MODE_OCR1A_TOP
 * 5- TIMER1_PWM_FAST_8BIT
 * 6- TIMER1_PWM_FAST_9BIT
 * 7- TIMER1_PWM_FAST_10BIT
 * 8- TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR1_TOP
 * 9- TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR1A_TOP
 * 10- TIMER1_PWM_PHASE_CORRECT_ICR1_TOP
 * 11- TIMER1_PWM_PHASE_CORRECT_OCR1A_TOP
 * 13-
 * 14- TIMER1_FAST_PWM_ICR1_TOP
 * 15- TIMER1_FAST_PWM_OCR1A_TOP
 */
#define TIMER1_SET_MODE   TIMER1_NORMAL_MODE

/* Timer 1 CTC 0C1A Pin Options:
 * ---------------------------
 * 1- TIMER1_OC1A_PIN_DISCONNECTED
 * 2- TIMER1_OC1A_PIN_TOGGLE
 * 3- TIMER1_OC1A_PIN_CLR
 * 4- TIMER1_OC1A_PIN_SET
 * */
#define TIMER1_SET_OC1A_PIN_MODE TIMER1_OC1A_PIN_DISCONNECTED

/* Timer 1 CTC OC1B Pin Options:
 * ---------------------------
 * 1- TIMER1_OC1B_PIN_DISCONNECTED
 * 2- TIMER1_OC1B_PIN_TOGGLE
 * 3- TIMER1_OC1B_PIN_CLR
 * 4- TIMER1_OC1B_PIN_SET
 * */
#define TIMER1_SET_OC1B_PIN_MODE TIMER1_OC1B_PIN_DISCONNECTED

#endif /* MCAL_MTIMER_MTIMER_CONFIG_H_ */
