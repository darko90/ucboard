/*
 * stm32_llm.h
 *
 *  Created on: 16.09.2016
 *      Author: elenz
 */

#ifndef STM32_LLM_H_
#define STM32_LLM_H_


#include "stm32f3xx.h"


#define __GPIO_SET_BITS(__PORT__, __PINMASK__) ((__PORT__)->BSRR = (__PINMASK__))
#define __GPIO_RESET_BITS(__PORT__, __PINMASK__) ((__PORT__)->BRR = (__PINMASK__))
#define __GPIO_SET_RESET_BITS(__PORT__, __SETPINMASK__, __RESETPINMASK__) ((__PORT__)->BSRR = (__PINMASK__) | ((uint32_t)(__RESETPINMASK__) << 16))




#define __TIM_ENABLE(__HANDLE__) ((__HANDLE__)->CR1 |= TIM_CR1_CEN)
#define __TIM_DISABLE(__HANDLE__) ((__HANDLE__)->CR1 &= ~(uint16_t)(~((uint16_t)TIM_CR1_CEN)))
#define __TIM_SET_COUNTER(__HANDLE__, __COUNT__) ((__HANDLE__)->CNT = (__COUNT__))
#define __TIM_CLEAR_FLAG(__HANDLE__, __FLAG__)       ((__HANDLE__)->SR = ~(__FLAG__))



#define __SPI_ENABLE(__HANDLE__) ((__HANDLE__)->CR1 |= SPI_CR1_SPE)
#define __SPI_DISABLE(__HANDLE__) ((__HANDLE__)->CR1 &= ~SPI_CR1_SPE)
#define __SPI_GET_FLAG(__HANDLE__, __FLAG__) ((((__HANDLE__)->SR) & (__FLAG__)) == (__FLAG__))
#define __SPI_SEND_DATA(__HANDLE__, __DATA__) ((__HANDLE__)->DR = (__DATA__))
#define __SPI_RECEIVE_DATA(__HANDLE__) ((__HANDLE__)->DR)
#define __SPI_GET_FLAG_STATUS(__HANDLE__, __FLAG__) ((((__HANDLE__)->SR & (__FLAG__)) != (uint16_t)RESET) ? SET : RESET)


void __SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct);


#define I2C_IT_ALL ( I2C_IT_ERRI | I2C_IT_RXI | I2C_IT_TXI | I2C_IT_STOPI | I2C_IT_TCI | I2C_IT_ADDRI | I2C_IT_NACKI )
#define I2C_IT_MASTER ( I2C_IT_RXI | I2C_IT_TXI | I2C_IT_STOPI | I2C_IT_TCI | I2C_IT_NACKI )


#define __I2C_ENABLE(__HANDLE__) ((__HANDLE__)->CR1 |= I2C_CR1_PE)
#define __I2C_DISABLE(__HANDLE__) ((__HANDLE__)->CR1 &= ~I2C_CR1_PE)
#define __I2C_ENABLE_IT(__HANDLE__, __INTERRUPT__)          ((__HANDLE__)->CR1 |= (__INTERRUPT__))
#define __I2C_DISABLE_IT(__HANDLE__, __INTERRUPT__)         ((__HANDLE__)->CR1 &= (~(__INTERRUPT__)))

#define __I2C_SEND_START_AND_ADDR(__HANDLE__) ((__HANDLE__)->CR2 |= I2C_CR2_START)
#define __I2C_SEND_STOP(__HANDLE__) ((__HANDLE__)->CR2 |= I2C_CR2_STOP)
#define __I2C_IS_BUSY(__HANDLE__) (((__HANDLE__)->ISR & I2C_ISR_BUSY) != 0)

void __I2C_DeInit(I2C_TypeDef* I2Cx);
void __I2C_Init(I2C_TypeDef* I2Cx, const I2C_InitTypeDef* conf);


#endif /* STM32_LLM_H_ */
