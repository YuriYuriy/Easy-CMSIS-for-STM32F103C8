/*
 * STM_SysTicks.h
 *
 *  Created on: 17 окт. 2024 г.
 *      Author: Yuriy
 */

#ifndef INC_STM_SYSTICKS_H_
#define INC_STM_SYSTICKS_H_

#include "main.h"

//#define STM_F_CPU 72000UL // kHz
//#define STM_F_CPU 64000UL // kHz
//#define STM_F_CPU 32000UL // kHz
//#define STM_F_CPU 16000UL // kHz
//#define STM_F_CPU 8000UL // kHz

#define STM_TICKS (STM_F_CPU)-1

void STM_ini_SysTicks(void);
void SysTick_Handler(void);

uint32_t STM_get_SysTicks_ms(void);

#endif /* INC_STM_SYSTICKS_H_ */
