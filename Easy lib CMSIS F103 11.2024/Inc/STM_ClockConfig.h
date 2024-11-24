/*
 * STM_ClockConfig.h
 *
 *  Created on: 17 окт. 2024 г.
 *      Author: Yuriy
 */

#ifndef INC_STM_CLOCKCONFIG_H_
#define INC_STM_CLOCKCONFIG_H_

#include "main.h"

void STM_ini_Clock_72(void);
void STM_ini_Clock_64(void);
void STM_ini_Clock_32(void);
void STM_ini_Clock_16(void);
void STM_ini_Clock_8(void);

void STM_ini_testClock_PLLDIV2(void);

#endif /* INC_STM_CLOCKCONFIG_H_ */
