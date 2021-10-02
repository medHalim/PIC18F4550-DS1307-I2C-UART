/*
 * lcd16x2_driver.h
 *
 * Created: 20/06/2021 
 * Author: Halim
 */ 

#include "lcd16x2_driver.h"
#include <xc.h>

void lcd_init() {
    LCD_Port = 0;       // PORT as Output 
    __delay_ms(15);     // 15ms,16x2 LCD Power on delay
    lcd_command(0x02);  // initialization of LCD (4-bit) mode 
    lcd_command(0x28);  // use 2 line and initialize 5*8 matrix 
    lcd_command(0x01);  // clear display screen
    lcd_command(0x0c);  // Display ON/OFF control : display on, cursor off
    lcd_command(0x06);  // Cursor or Display shift : increment cursor (shift cursor to right)
}

/*In 4-Bit mode, Instructions and Data are sent from PORTB(PB4-PB7); 
 * since PORTB is 8-bit, to send 4-bit adresses we first send the 
 * higher 4-bit adress then the lower 4-bits shifted by 4 */

void lcd_command(unsigned char cmd ) {
    LCD_Data = (LCD_Data & 0x0f) | (0xF0 & cmd);  // Higher nibble 4-bit masking
    RS = 0;  // Instructions
    EN = 1;  
    NOP();
    EN = 0;
    __delay_ms(1);
    LCD_Data = (LCD_Data & 0x0f) | (cmd<<4);  // Lower nibble 4-bit masking
    EN = 1;
    NOP();
    EN = 0;
    __delay_ms(3);
}

void lcd_data(unsigned char dat) {
    LCD_Data = (LCD_Data & 0x0f) | (0xF0 & dat);  
    RS = 1;  // Data
    EN = 1;  
    NOP();
    EN = 0;
    __delay_ms(1);
    LCD_Data = (LCD_Data & 0x0f) | (dat<<4);  
    EN = 1;  
    NOP();
    EN = 0;
    __delay_ms(3);
}

void lcd_string(const unsigned char *str) {
    while((*str)!=0)
    {       
      lcd_data(*str);
      str++;    
    }
}

void lcd_clear() {
    lcd_command(0x01);  // clear display screen
    __delay_ms(3);
}
