/*
 * main.c
 *
 * Created: 20/06/2021 
 * Author: Halim
 */ 

#include "main.h"

unsigned char i,j;
unsigned char day;
unsigned char tx_data[10];
unsigned char rtc[]={0x00,0x30,0x08,0x02,0x20,0x06,0x21,'\0'}; 


void main(void) {
    uart_init();
    i2c_init();
    
    i2c_start();
    i2c_write(rtc_write_addr);
    i2c_write(0x00);
    
    // Writing time to RTC
    for (i=0; i<7; i++) {	
        i2c_write(rtc[i]);
        __delay_ms(20);
    }
    i2c_stop();
    
    while(1)
    {
        i2c_start();
        i2c_write(rtc_write_addr);
        i2c_write(0x00);            
        
        i2c_restart();
        i2c_write(rtc_read_addr);
        
        // Reading time from RTC
        tx_data[0] = i2c_read(0);
        tx_data[1] = i2c_read(0);
        tx_data[2] = i2c_read(0);
        tx_data[3] = i2c_read(0);            
        tx_data[4] = i2c_read(0);
        tx_data[5] = i2c_read(0);
        tx_data[6] = i2c_read(1);
        i2c_stop();
        
        // Sending data through UART
        for(j=0; j<7; j++) {	
            uart_byte(tx_data[j]);
            __delay_ms(50); // Without this delay = Packet loss 
        }
        __delay_ms(700); // useful delay while simulating in Proteus
    }
}
