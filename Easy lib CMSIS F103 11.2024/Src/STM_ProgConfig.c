/*
 * STM_ProgConfig.c
 *
 *  Created on: 17 окт. 2024 г.
 *      Author: Yuriy
 */

#include "STM_ProgConfig.h"

void STM_ini_SW(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;				// Включит алетренативные функции
	AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE;	// JTAG-DP отключен, SW-DP включен
}
