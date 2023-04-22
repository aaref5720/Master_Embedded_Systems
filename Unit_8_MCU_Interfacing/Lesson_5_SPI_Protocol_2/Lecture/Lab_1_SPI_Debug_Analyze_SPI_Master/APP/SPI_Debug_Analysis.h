/*
 * SPI_Debug_Analysis.h
 *
 *  Created on: Apr 22, 2023
 *      Author: Abdelrahman Aref
 */

#ifndef SPI_DEBUG_ANALYSIS_H_
#define SPI_DEBUG_ANALYSIS_H_

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

void SPI_Debug_Analysis_Using_UART1_Interrupt(void);


#endif /* SPI_DEBUG_ANALYSIS_H_ */
