/*
 * ds1307_driver.h
 *
 * Created: 20/06/2021 
 * Author: Halim
 */ 

#ifndef LCD16X2_DRIVER_H_
#define LCD16X2_DRIVER_H_

//System Clock Frequency (necessary for using __delay_ms function)
#define _XTAL_FREQ 40000000UL

#define RS LATB0  
#define EN LATB1  
#define LCD_Data LATB  
#define LCD_Port TRISB  

void lcd_init(void);
void lcd_command(unsigned char value);
void lcd_data(unsigned char value);
void lcd_string(const unsigned char *str);
void lcd_clear(void);


#endif /* LCD16X2_DRIVER_H_ */