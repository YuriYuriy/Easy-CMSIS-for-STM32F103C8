/*
 * STM_TIM.c
 *
 *  Created on: 23 нояб. 2024 г.
 *      Author: Yuriy
 */

#include "STM_TIM.h"

//RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; - Подключение тактирование таймера TIM2

void STM_ini_TIM2_PWM(void)
{	
	TIM2->PSC = 0;							//Деление частоты
	TIM2->ARR = 10000-1; 					//До скольки счет (макс. 65535)
	TIM2->CCMR1 |= TIM_CCMR1_OC1M;			//Режим ШИМ прямой
	TIM2->CCER |= TIM_CCER_CC1E;			//Выход ШИМ
	//TIM2->CR1 |= 1; 						//Запуск таймера
	//TIM2->CCR1 = 5000-1; 					//Коэф. заполнения ШИМ
}


