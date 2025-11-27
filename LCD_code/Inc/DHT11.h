/*
 * DHT11.h
 *
 *  Created on: Nov 16, 2025
 *      Author: sunbeam
 */

#ifndef DHT11_H_
#define DHT11_H_

#include "stm32fxxx_hal.h"

#define DHT11_PORT GPIOA
#define DHT11_PIN  GPIO_PIN_8

void DHT11_Start(void);
uint8_t DHT11_CheckResponse(void);
uint8_t DHT11_ReadByte(void);
uint8_t DHT11_Read(uint8_t *temp, uint8_t *humidity);


#endif /* DHT11_H_ */
