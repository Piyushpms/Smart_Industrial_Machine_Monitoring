/*
 * LCD.c
 *
 *  Created on: Nov 16, 2025
 *      Author: sunbeam
 */

#include "LCD.h"
#include "stm32fxxx_hal.h"

// Micro delay
void LCD_Delay(uint32_t Delay)
{
    HAL_Delay(Delay);
}

void LCD_Send_Nibble(char nibble)
{
    HAL_GPIO_WritePin(LCD_D4_GPIO_PORT, LCD_D4_PIN, (nibble & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_D5_GPIO_PORT, LCD_D5_PIN, (nibble & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_D6_GPIO_PORT, LCD_D6_PIN, (nibble & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_D7_GPIO_PORT, LCD_D7_PIN, (nibble & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);

    // EN pulse
    HAL_GPIO_WritePin(LCD_EN_GPIO_PORT, LCD_EN_PIN, GPIO_PIN_SET);
    LCD_Delay(1);
    HAL_GPIO_WritePin(LCD_EN_GPIO_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
    LCD_Delay(1);
}

void LCD_Send_Cmd(char cmd)
{
    HAL_GPIO_WritePin(LCD_RS_GPIO_PORT, LCD_RS_PIN, GPIO_PIN_RESET);

    LCD_Send_Nibble(cmd >> 4);
    LCD_Send_Nibble(cmd & 0x0F);

    LCD_Delay(2);
}

void LCD_Send_Data(char data)
{
    HAL_GPIO_WritePin(LCD_RS_GPIO_PORT, LCD_RS_PIN, GPIO_PIN_SET);

    LCD_Send_Nibble(data >> 4);
    LCD_Send_Nibble(data & 0x0F);

    LCD_Delay(2);
}

void LCD_Init(void)
{
    LCD_Delay(20);

    LCD_Send_Cmd(0x02); // 4-bit mode
    LCD_Send_Cmd(0x28); // 2 line, 5x7
    LCD_Send_Cmd(0x0C); // display on, cursor off
    LCD_Send_Cmd(0x06); // auto increment
    LCD_Send_Cmd(0x01); // clear display

    LCD_Delay(5);
}

void LCD_SetCursor(uint8_t row, uint8_t col)
{
    uint8_t address;

    address = (row == 0) ? (0x80 + col) : (0xC0 + col);
    LCD_Send_Cmd(address);
}

void LCD_Send_String(char *str)
{
    while (*str)
    {
        LCD_Send_Data(*str++);
    }
}

void LCD_Clear(void)
{
    LCD_Send_Cmd(0x01);
    LCD_Delay(2);
}
