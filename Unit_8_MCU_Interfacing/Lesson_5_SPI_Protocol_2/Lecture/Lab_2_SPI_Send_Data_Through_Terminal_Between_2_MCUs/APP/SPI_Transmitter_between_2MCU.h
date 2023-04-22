/*
 * SPI_Transmitter_between_2MCU.h
 *
 *  Created on: Apr 22, 2023
 *      Author: Abdelrahman Aref
 */

#ifndef SPI_TRANSMITTER_BETWEEN_2MCU_H_
#define SPI_TRANSMITTER_BETWEEN_2MCU_H_

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include "USART.h"
#include "SPI.h"

/*******************************************************************************
                                    Macros
*******************************************************************************/
#define SPI1_Index              0
#define SPI2_Index              1
#define SPIx_NSS_Index          0
#define SPIx_SCK_Index          1
#define SPIx_MISO_Index         2
#define SPIx_MOSI_Index         3

/*******************************************************************************
                                  APP Function
*******************************************************************************/
void SPI1_CallBack(void);
void USART1_CallBack(void);

void SPI_Transmitter_between_2MCU(void);


#endif /* SPI_TRANSMITTER_BETWEEN_2MCU_H_ */
