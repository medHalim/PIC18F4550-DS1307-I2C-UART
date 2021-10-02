/*
 * ds1307_driver.h
 *
 * Created: 20/06/2021 
 * Author: Halim
 */ 

#ifndef DS1307_DRIVER_H_
#define DS1307_DRIVER_H_

#define rtc_read_addr   (0xD1)    // 1101001 R(1) 
#define rtc_write_addr  (0xD0)    // 1101000 W(0) 

void ascii_display (unsigned char bcd);
void days_display(unsigned char bcd);
void months_display(unsigned char bcd);


#endif /* DS1307_DRIVER_H_ */
