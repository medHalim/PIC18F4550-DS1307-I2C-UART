/*
 * main.c
 *
 * Created: 20/06/2021 
 * Author: Halim
 */ 

#include "main.h"

unsigned char time[] = {"Time: "};
unsigned char date[] = {"Date: "};
unsigned char colon[] = {":"};
unsigned char dash[] = {"-"};
unsigned char point[] = {". "};
unsigned char rx_data[10]; 


void main(void) {
    uart_init();
    lcd_init();
    
    while(1) {
        // Data Reception from UART
        for(unsigned char i=0; i<7; i++) {	 
            rx_data[i]= uart_rx();
        }
        // Time
        lcd_command(0x84);    
        ascii_display(rx_data[2]);    
        lcd_string(colon);
        ascii_display(rx_data[1]);    
        lcd_string(colon);              
        ascii_display(rx_data[0]);    
        
        // Date
        lcd_command(0xC1);   
        days_display(rx_data[3]);     
        lcd_string(point);
        ascii_display(rx_data[4]);    
        lcd_string(dash);
        months_display(rx_data[5]);   
        lcd_string(dash);
        ascii_display(rx_data[6]);    
    }
}
