/*
 * uart_driver.h
 *
 * Created: 20/06/2021 
 * Author: Halim
 */ 

#include "uart_driver.h"
#include <xc.h>

void uart_init() {  
    TRISCbits.RC6 = 0;        // Tx Output
    TRISCbits.RC7 = 1;        // Rx Input
    
    SPBRG = 21;               // baud rate 115200 pour 40 MHz clock 
    TXSTAbits.BRGH = 1;       // low Speed
    TXSTAbits.SYNC = 0;       // asynchronous 
    RCSTAbits.SPEN = 1;       // enable serial port pins 
    RCSTAbits.CREN = 1;       // enable continuous reception 
    TXSTAbits.TX9 = 0;        // 8- not 9-bit transmission 
    RCSTAbits.RX9  = 0;       // 8- not 9-bit reception 
    TXSTAbits.TXEN = 1;       // enable the transmitter 
}

void uart_byte(unsigned char data) {
    while(PIR1bits.TXIF == 0);  //wait for transmit interrupt flag
    TXREG = data;               //wait for transmit interrupt flag to set which indicates TXREG is ready
                                //for another transmission 
}

void uart_str(const unsigned char *str) {
    while((*str)!='\0') {
        uart_byte(*(str));
        str++; //Increment the Pointer
    }
}

unsigned char uart_rx() {
    while(!PIR1bits.RCIF);    // Wait until data is received
    if(RCSTAbits.OERR) {      // if Overrun Error bit
        CREN = 0;             // Disables receiver
        NOP();
        CREN = 1;             // Enables receiver
    }
    return RCREG;             //return RCREG register 
}

