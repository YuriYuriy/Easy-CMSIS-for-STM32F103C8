/*
 * STM_SPI.h
 *
 *  Created on: 18 окт. 2024 г.
 *      Author: Yuriy
 */

#ifndef STM_SPI_H_
#define STM_SPI_H_

#include "main.h"

void STM_ini_SPI1_8bit(void);
void STM_ini_SPI1_16bit(void);

void STM_ini_SPI1_8bit_NSS(void);
void STM_ini_SPI1_16bit_NSS(void);

void STM_write_SPI1(uint16_t data);
uint16_t STM_read_SPI1(void);

#endif /* STM_SPI_H_ */
