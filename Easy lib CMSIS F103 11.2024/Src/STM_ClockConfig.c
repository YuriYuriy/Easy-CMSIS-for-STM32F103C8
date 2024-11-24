/*
 * STM_ClockConfig.c
 *
 *  Created on: 17 окт. 2024 г.
 *      Author: Yuriy
 */

#include "STM_ClockConfig.h"

void STM_ini_Clock_72(void)
{
	RCC->CR |= RCC_CR_HSEON; 						//Внешнее тактирование от высокочастотного кварца 8 МГц HSE
	while ((RCC->CR & (RCC_CR_HSERDY)) == RESET); 	//Ожидание готовности тактирования HSE

	FLASH->ACR |= FLASH_ACR_LATENCY_2; 				//Задержка флеш

	RCC->CFGR |= RCC_CFGR_PLLMULL9; 				//Множитель  PLL на 9
	RCC->CFGR |= RCC_CFGR_PLLSRC; 					//Тактирование от внешнего кварца HSE
	RCC->CR |= RCC_CR_PLLON; 						//Запуск мультиплексора PLL
	while ((RCC->CR & (RCC_CR_PLLRDY)) == RESET);	//Ожидание готовности PLL

	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; 				//Делитель APB1 на 2
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; 				//Делитель APB2 на 0
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1; 				//Делитель AHB на 0

	RCC->CFGR |= RCC_CFGR_SW_PLL; 					//Мультиплексор тактирование от PLL
	while ((RCC->CFGR & RCC_CFGR_SWS_Msk)
			!= (0x02 << RCC_CFGR_SWS_Pos)); 		//Ожидание готовности мультиплексора
	RCC->CR &= ~(RCC_CR_HSION_Msk); 				//Тактирование от внутреней RC-цепи 8 МГц HSI
}

void STM_ini_Clock_64(void)
{
	RCC->CR |= RCC_CR_HSEON; 						//Внешнее тактирование от высокочастотного кварца 8 МГц HSE
	while ((RCC->CR & (RCC_CR_HSERDY)) == RESET); 	//Ожидание готовности тактирования HSE

	FLASH->ACR |= FLASH_ACR_LATENCY_2; 				//Задержка флеш

	RCC->CFGR |= RCC_CFGR_PLLMULL8; 				//Множитель PLL на 8
	RCC->CFGR |= RCC_CFGR_PLLSRC; 					//Тактирование от внешнего кварца HSE
	RCC->CR |= RCC_CR_PLLON; 						//Запуск мультиплексора PLL
	while ((RCC->CR & (RCC_CR_PLLRDY)) == RESET); 	//Ожидание готовности PLL

	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;				//Делитель APB1 на 2
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; 				//Делитель APB2 на 0
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1; 				//Делитель AHB на 0

	RCC->CFGR |= RCC_CFGR_SW_PLL; 					//Мультиплексор тактирование от PLL
	while ((RCC->CFGR & RCC_CFGR_SWS_Msk)
			!= (0x02 << RCC_CFGR_SWS_Pos)); 		//Ожидание готовности мультиплексора
	RCC->CR &= ~(RCC_CR_HSION_Msk); 				//Тактирование от внутреней RC-цепи 8 МГц HSI
}

void STM_ini_Clock_32(void)
{
	RCC->CR |= RCC_CR_HSEON; 						//Внешнее тактирование от высокочастотного кварца 8 МГц HSE
	while ((RCC->CR & (RCC_CR_HSERDY)) == RESET); 	//Ожидание готовности тактирования HSE

	FLASH->ACR |= FLASH_ACR_LATENCY_2; 				//Задержка флеш

	RCC->CFGR |= RCC_CFGR_PLLMULL4; 				//Множитель PLL на 4
	RCC->CFGR |= RCC_CFGR_PLLSRC; 					//Тактирование от внешнего кварца HSE
	RCC->CR |= RCC_CR_PLLON; 						//Запуск мультиплексора PLL
	while ((RCC->CR & (RCC_CR_PLLRDY)) == RESET); 	//Ожидание готовности PLL

	RCC->CFGR |= RCC_CFGR_PPRE1_DIV1; 				//Делитель APB1 на 0
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; 				//Делитель APB2 на 0
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1; 				//Делитель AHB на 0

	RCC->CFGR |= RCC_CFGR_SW_PLL; 					//Мультиплексор тактирование от PLL
	while ((RCC->CFGR & RCC_CFGR_SWS_Msk)
			!= (0x02 << RCC_CFGR_SWS_Pos)); 		//Ожидание готовности мультиплексора
	RCC->CR &= ~(RCC_CR_HSION_Msk); 				//Тактирование от внутреней RC-цепи 8 МГц HSI
}

void STM_ini_Clock_16(void)
{
	RCC->CR |= RCC_CR_HSEON; 						//Внешнее тактирование от высокочастотного кварца 8 МГц HSE
	while ((RCC->CR & (RCC_CR_HSERDY)) == RESET); 	//Ожидание готовности тактирования HSE

	FLASH->ACR |= FLASH_ACR_LATENCY_2; 				//Задержка флеш

	RCC->CFGR |= RCC_CFGR_PLLMULL2; 				//Множитель PLL на 2
	RCC->CFGR |= RCC_CFGR_PLLSRC; 					//Тактирование от внешнего кварца HSE
	RCC->CR |= RCC_CR_PLLON; 						//Запуск мультиплексора PLL
	while ((RCC->CR & (RCC_CR_PLLRDY)) == RESET); 	//Ожидание готовности PLL

	RCC->CFGR |= RCC_CFGR_PPRE1_DIV1; 				//Делитель APB1 на 0
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;				//Делитель APB2 на 0
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1; 				//Делитель AHB на 0

	RCC->CFGR |= RCC_CFGR_SW_PLL; 					//Мультиплексор тактирование от PLL
	while ((RCC->CFGR & RCC_CFGR_SWS_Msk)
			!= (0x02 << RCC_CFGR_SWS_Pos)); 		//Ожидание готовности мультиплексора
	RCC->CR &= ~(RCC_CR_HSION_Msk); 				//Тактирование от внутреней RC-цепи 8 МГц HSI
}

void STM_ini_Clock_8(void)
{
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_HSE_DIV2; 		//Делитель HSE на 2
	RCC->CR |= RCC_CR_HSEON; 						//Внешнее тактирование от высокочастотного кварца 8 МГц HSE
	while ((RCC->CR & (RCC_CR_HSERDY)) == RESET); 	//Ожидание готовности тактирования HSE

	FLASH->ACR |= FLASH_ACR_LATENCY_2; 				//Задержка флеш

	RCC->CFGR |= RCC_CFGR_PLLMULL2; 				//Множитель PLL на 2
	RCC->CFGR |= RCC_CFGR_PLLSRC; 					//Тактирование от внешнего кварца HSE
	RCC->CR |= RCC_CR_PLLON; 						//Запуск мультиплексора PLL
	while ((RCC->CR & (RCC_CR_PLLRDY)) == RESET); 	//Ожидание готовности PLL

	RCC->CFGR |= RCC_CFGR_PPRE1_DIV1; 				//Делитель APB1 на 0
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; 				//Делитель APB2 на 0
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1; 				//Делитель AHB на 0

	RCC->CFGR |= RCC_CFGR_SW_PLL; 					//Мультиплексор тактирование от PLL
	while ((RCC->CFGR & RCC_CFGR_SWS_Msk)
			!= (0x02 << RCC_CFGR_SWS_Pos)); 		//Ожидание готовности мультиплексора
	RCC->CR &= ~(RCC_CR_HSION_Msk); 				//Тактирование от внутреней RC-цепи 8 МГц HSI
}

void STM_ini_testClock_PLLDIV2(void)
{
	RCC->CFGR |= RCC_CFGR_MCOSEL_PLL_DIV2;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOA->CRH |= GPIO_CRH_MODE8;
	GPIOA->CRH |= GPIO_CRH_CNF8_1;
}

