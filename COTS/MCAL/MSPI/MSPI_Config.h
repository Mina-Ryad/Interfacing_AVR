/*
 * MSPI_Config.h
 *
 *  Created on: Nov 29, 2021
 *      Author: Mina-Ryad
 */

#ifndef MCAL_MSPI_MSPI_CONFIG_H_
#define MCAL_MSPI_MSPI_CONFIG_H_

/* SPI Interrupt Options
 * 1- MSPI_INTERRUPT_ENABELED
 * 2- MSPI_INTERRUPT_DISABELED
 * */
#define MSPI_INTERRUPT MSPI_INTERRUPT_ENABELED

/* SPI Status Options
 * 1- MSPI_ENABELED
 * 2- MSPI_DISABELED
 * */
#define MSPI_STATUS MSPI_ENABELED

/* SPI Data Order options
 * 1- MSPI_DATA_ORDER_LSB
 * 2- MSPI_DATA_ORDER_MSB
 * */
#define MSPI_DATA_ORDER  MSPI_DATA_ORDER_LSB

/* SPI Master/Slave Options:
 * 1- MSPI_SET_MASTER
 * 2- MSPI_SET_SLAVE
 * */
#define MSPI_SET_MASTER_SLAVE  MSPI_SET_MASTER

/* SPI Clock Polarity Options:
 * 1- MSPI_CLOCK_POLARITY_LEADING_RISING
 * 2- MSPI_CLOCK_POLARITY_LEADING_FALLING
 * */
#define MSPI_CLOCK_POLARITY  MSPI_CLOCK_POLARITY_LEADING_RISING

/* SPI Clock Phase Options:
 * 1- MSPI_CLOCK_PHASE_LEADING_SAMPLE
 * 2- MSPI_CLOCK_PHASE_LEADING_SETUP
 * */
#define MSPI_CLOCK_PHASE  MSPI_CLOCK_PHASE_LEADING_SETUP

/* SPI Clock Rate Options:
 * 1- MSPI_CLOCK_RATE_4
 * 2- MSPI_CLOCK_RATE_16
 * 3- MSPI_CLOCK_RATE_64
 * 4- MSPI_CLOCK_RATE_128
 * 5- MSPI_CLOCK_RATE_2_D
 * 6- MSPI_CLOCK_RATE_8_D
 * 7- MSPI_CLOCK_RATE_32_D
 * 8- MSPI_CLOCK_RATE_64_D
 * */
#define MSPI_CLOCK_RATE  MSPI_CLOCK_RATE_4


#endif /* MCAL_MSPI_MSPI_CONFIG_H_ */