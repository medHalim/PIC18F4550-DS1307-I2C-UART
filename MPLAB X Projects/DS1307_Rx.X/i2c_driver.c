/*
 * i2c_driver.h
 *
 * Created: 20/06/2021 
 *  Author: Halim
 */ 


#include "i2c_driver.h"
#include <xc.h>


void i2c_init(void) {
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    
    SSPSTATbits.SMP = 1; // 100KHz
    SSPSTATbits.CKE = 0; // Disable SMBus specific inputs
    
    SSPCON1bits.SSPEN = 1; // Enable SDA & SCL pins as Serial Ports
    SSPCON1bits.SSPM = 0b1000;// Mode Master
    
    SSPADD = 99; // 100KHz from 40MHz
}

void i2c_start(void) {
    SSPCON2bits.SEN = 1;    // Start Enable. Automatically cleared by hardware.
    while(SSPCON2bits.SEN == 1);
}

void i2c_stop(void) {
    SSPCON2bits.PEN = 1;    // Stop Enable. Automatically cleared by hardware.
    while(SSPCON2bits.PEN == 1);
}

void i2c_restart(void) {
    SSPCON2bits.RSEN = 1;   // Repeated Start Enable. Automatically cleared by hardware.
    while(SSPCON2bits.RSEN == 1);
}

void i2c_wait(void) {
	while(SSPSTATbits.R_NOT_W == 1)
		continue;
	if(SSPCON2bits.ACKSTAT == 1) { // If Acknowledge was not received from slave
		i2c_stop();
	}
}

void i2c_write(unsigned char data) {
    SSPBUF = data;
    while(SSPSTATbits.BF == 1);  // wait till buffer is empty 
    i2c_wait(); // wait till Acknowledge received from slave 
}

unsigned char i2c_read(unsigned char ack) {
    unsigned char receive = 0;
    SSPCON2bits.RCEN = 1;       // Enables Receive mode for I2C
    while(SSPSTATbits.BF == 0);  // wait till buffer is full 
    receive = SSPBUF;
    i2c_wait();
    SSPCON2bits.ACKDT = ack;   // ACK(0) ou NOT_ACK(1)
    SSPCON2bits.ACKEN=1;      // Transmit ACKDT data bit. Automatically cleared by hardware.
    while(SSPCON2bits.ACKEN == 1);     
    return receive;
}
