/*
 * STM_delay.c
 *
 *  Created on: 2 нояб. 2024 г.
 *      Author: Yuriy
 */

#include "STM_Delay.h"

uint32_t tick = 0;

void STM_delay_ms(uint32_t mseconds)
{
	while(mseconds >= 1)
	{
		if( (STM_get_SysTicks_ms() - tick) >= 1)
		{
			mseconds--;
			tick = STM_get_SysTicks_ms();
		}
	}
}
