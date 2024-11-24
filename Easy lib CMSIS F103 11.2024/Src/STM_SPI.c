/*
 * STM_SPI.c
 *
 *  Created on: 18 окт. 2024 г.
 *      Author: Yuriy
 */

#include "STM_SPI.h"

// Использующиеся выводы:
// PA7 - MOSI
// PA6 - MISO
// PA5 - SCK
// PA4 - NSS
//RCC->APB2ENR |= RCC_APB2ENR_SPI1EN | RCC_APB2ENR_IOPAEN; - Включаем тактирование SPI1 и GPIOA 

/*
SPI control register 1 SPI1->CR1

Bit 15 BIDIMODE: Bidirectional data mode enable
0: 2-line unidirectional data mode selected
1: 1-line bidirectional data mode selected

Bit 14 BIDIOE: Output enable in bidirectional mode
0: Output disabled (receive-only mode)
1: Output enabled (transmit-only mode)

Bit 13 CRCEN: Hardware CRC calculation enable
0: CRC calculation disabled
1: CRC calculation enabled

Bit 12 CRCNEXT: CRC transfer next
0: Data phase (no CRC phase)
1: Next transfer is CRC (CRC phase)

Bit 11 DFF: Data frame format
0: 8-bit data frame format is selected for transmission/reception
1: 16-bit data frame format is selected for transmission/reception

Bit 10 RXONLY: Receive only
0: Full duplex (Transmit and receive)
1: Output disabled (Receive-only mode)

Bit 9 SSM: Software slave management
0: Software slave management disabled
1: Software slave management enabled

Bit 8 SSI: Internal slave select
This bit has an effect only when the SSM bit is set. The value of this bit is forced onto the
NSS pin and the IO value of the NSS pin is ignored.

Bit 7 LSBFIRST: Frame format
0: MSB transmitted first
1: LSB transmitted first

Bit 6 SPE: SPI enable
0: Peripheral disabled
1: Peripheral enabled

Bits 5:3 BR[2:0]: Baud rate control
000: fPCLK/2
001: fPCLK/4
010: fPCLK/8
011: fPCLK/16
100: fPCLK/32
101: fPCLK/64
110: fPCLK/128
111: fPCLK/256

Bit 2 MSTR: Master selection
0: Slave configuration
1: Master configuration
Bit1 CPOL: Clock polarity
0: CK to 0 when idle
1: CK to 1 when idle

Bit 0 CPHA: Clock phase
0: The first clock transition is the first data capture edge
1: The second clock transition is the first data capture edge
*/
		
void STM_iniPins_SPI1(void)
{

	GPIOA->CRL |= GPIO_CRL_CNF5_1     		//Альтернативная функция тяни-толкай
			   | GPIO_CRL_MODE5 			//50МГц

	           | GPIO_CRL_CNF6_0 			//Плавающий вход

	           | GPIO_CRL_CNF7_1 			//Альтернативная функция тяни-толкай
	           | GPIO_CRL_MODE7;			//50МГц
}

void STM_ini_SPI1_master_8bit(void)
{
	STM_iniPins_SPI1();

	SPI1->CR1 |= SPI_CR1_SSM       			//Программное управление SS
			  | SPI_CR1_SSI        			//SS в высоком состоянии
			  | 0x06<<SPI_CR1_BR_Pos        //Делитель частоты
			  | SPI_CR1_MSTR    			//Режим Master (ведущий)
			  | SPI_CR1_SPE; 				//Включаем SPI
}

void STM_ini_SPI1_master_16bit(void)
{
	STM_iniPins_SPI1();

	SPI1->CR1 |= SPI_CR1_SSM       			//Программное управление SS
			  | SPI_CR1_SSI        			//SS в высоком состоянии
			  | SPI_CR1_DFF					//Режим 16 бит
			  | 0x06<<SPI_CR1_BR_Pos        //Делитель частоты
			  | SPI_CR1_MSTR       			//Режим Master (ведущий)
			  |SPI_CR1_SPE; 				//Включаем SPI
}

void STM_ini_SPI1_8bit_NSS(void)
{

	GPIOA->CRL |= GPIO_CRL_CNF4
			   | GPIO_CRL_MODE4

			   | GPIO_CRL_CNF5_1
	           | GPIO_CRL_MODE5

	           | GPIO_CRL_CNF6_0

	           | GPIO_CRL_CNF7_1
               | GPIO_CRL_MODE7;

	SPI1->CR1 |= 0x06<<SPI_CR1_BR_Pos       //Скорость передачи: F_PCLK/32
			  | SPI_CR1_MSTR;				//Режим Master (ведущий)

	SPI1->CR2 |= SPI_CR2_SSOE;
}

void STM_ini_SPI1_16bit_NSS(void)
{

	GPIOA->CRL |= GPIO_CRL_CNF4
			   | GPIO_CRL_MODE4

			   | GPIO_CRL_CNF5_1
	           | GPIO_CRL_MODE5

	           | GPIO_CRL_CNF6_0

	           | GPIO_CRL_CNF7_1
               | GPIO_CRL_MODE7;

	SPI1->CR1 |= SPI_CR1_DFF				//Режим 16 бит
			  | 0x06<<SPI_CR1_BR_Pos        //Скорость передачи: F_PCLK/32
			  | SPI_CR1_MSTR;				//Режим Master (ведущий)

	SPI1->CR2 |= SPI_CR2_SSOE;
}

void STM_write_SPI1(uint16_t data)
{
	while(!(SPI1->SR & SPI_SR_TXE));		//Ждем, пока не освободится буфер передатчика
	SPI1->DR = data;						//Заполняем буфер передатчика
}

uint16_t STM_read_SPI1(void)
{
  SPI1->DR = 0; 							//запускаем обмен
  while(!(SPI1->SR & SPI_SR_RXNE)); 		//Ждем, пока не появится новое значение в буфере приемника
  return SPI1->DR;							//возвращаем значение буфера приемника
}

