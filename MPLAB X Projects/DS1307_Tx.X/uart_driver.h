/*
 * i2c_driver.h
 *
 * Created: 20/06/2021 
 * Author: Halim
 */ 

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

void uart_init(void);
void uart_byte(unsigned char data);
void uart_str(const unsigned char *str);
unsigned char uart_rx(void);


#endif /* UART_DRIVER_H_ */
