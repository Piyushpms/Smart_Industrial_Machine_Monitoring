/*
 * LCD.h
 *
 *  Created on: Nov 16, 2025
 *      Author: sunbeam
 */

#ifndef LCD_H_
#define LCD_H_

#include "stm32fxxx_hal.h"

// Change GPIO ports & pins as per your wiring
#define LCD_RS_GPIO_PORT   GPIOA
#define LCD_RS_PIN         GPIO_PIN_0

#define LCD_EN_GPIO_PORT   GPIOA
#define LCD_EN_PIN         GPIO_PIN_1

#define LCD_D4_GPIO_PORT   GPIOA
#define LCD_D4_PIN         GPIO_PIN_4

#define LCD_D5_GPIO_PORT   GPIOA
#define LCD_D5_PIN         GPIO_PIN_5

#define LCD_D6_GPIO_PORT   GPIOA
#define LCD_D6_PIN         GPIO_PIN_6

#define LCD_D7_GPIO_PORT   GPIOA
#define LCD_D7_PIN         GPIO_PIN_7

void LCD_Init(void);
void LCD_Send_Cmd(char cmd);
void LCD_Send_Data(char data);
void LCD_Send_String(char *str);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);


#endif /* LCD_H_ */
