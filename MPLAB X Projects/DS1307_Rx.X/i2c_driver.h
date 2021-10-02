/*
 * i2c_driver.h
 *
 * Created: 20/06/2021 
 * Author: Halim
 */ 


#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

void i2c_init(void);
void i2c_idle(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_restart(void);
void i2c_write(unsigned char data);
unsigned char i2c_read(unsigned char ack);


#endif /* I2C_DRIVER_H_ */
