/*
 * STM_SysTicks.c
 *
 *  Created on: 17 окт. 2024 г.
 *      Author: Yuriy
 */

#include "STM_SysTicks.h"

uint32_t STM_sysTicks_ms = 0;

void STM_ini_SysTicks(void)
{
	SysTick->LOAD |= STM_TICKS;
	
	SysTick->VAL |= STM_TICKS;
	
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk 
				  | SysTick_CTRL_TICKINT_Msk 
				  | SysTick_CTRL_CLKSOURCE_Msk;
}

void SysTick_Handler(void)
{
	STM_sysTicks_ms++;
}

uint32_t STM_get_SysTicks_ms()
{
	return(STM_sysTicks_ms);
}
