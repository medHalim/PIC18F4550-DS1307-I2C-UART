/*
 * ds1307_driver.h
 *
 * Created: 20/06/2021 
 * Author: Halim
 */ 

#include "ds1307_driver.h"
#include "lcd16x2_driver.h"
#include <xc.h>

unsigned char months[15][15] = {"Jun", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", '\0'};
unsigned char days[10][10] = {"Mon", "Tue", "Wen", "Thu", "Fri", "Sat", "Sun", '\0'};
unsigned char error[] = {"Error!"};

void ascii_display(unsigned char bcd) {
    unsigned char temp;
    // Convert BCD to ASCII since LCD supports ASCII
    // 0x30 is '0' in ASCII so we always add 0x30
    temp = bcd;                 
    temp = (temp >> 4) | 0x30;  // Add 0x30 to unpacked BCD 
    lcd_data(temp);             // write converted BCD digit
    
    temp = bcd;                 
    temp = temp & 0x0F;         // unpack lower byte
    temp = temp | 0x30;         // Add 0x30 to unpacked BCD 
    lcd_data(temp);             // write converted BCD digit
}

void days_display(unsigned char bcd) {
    unsigned char temp;      
    
    temp = bcd;         
    temp = temp & 0x0F;
    temp = temp | 0x30;        
    
    switch(temp){
        case(0x31):
            lcd_string(days[6]);
            break;
        case(0x32):
            lcd_string(days[0]);
            break;
        case(0x33):
            lcd_string(days[1]);
            break;
        case(0x34):
            lcd_string(days[2]);
            break;
        case(0x35):
            lcd_string(days[3]);
            break;
        case(0x36):
            lcd_string(days[4]);
            break;
        case(0x37):
            lcd_string(days[5]);
            break;
            
        default:
            lcd_string(error);
    }
}

void months_display(unsigned char bcd) {
    unsigned char Ltemp;
    unsigned char Htemp;
    
    Htemp = bcd;                 
    Htemp = (Htemp >> 4) | 0x30;                
    
    Ltemp = bcd;                 
    Ltemp = Ltemp & 0x0F;         
    Ltemp = Ltemp | 0x30;    
    
    switch(Ltemp)
    {
        case (0x30):
            if(Htemp == (0x31)) {
                lcd_string(months[9]);
            } else {
                lcd_string(error);
            }
            break;
        case (0x31):
            if(Htemp == (0x31)) {
                lcd_string(months[10]);
            } else {
                lcd_string(months[0]);
            }
            break;
        case (0x32):
            if(Htemp == (0x31)) {
                lcd_string(months[11]);
            } else {
                lcd_string(months[1]);
            }  
            break;
        case (0x33):
            lcd_string(months[2]);
            break;
        case (0x34):
            lcd_string(months[3]);
            break;
        case (0x35):
            lcd_string(months[4]);
            break;
        case (0x36):
            lcd_string(months[5]);
            break;
        case (0x37):
            lcd_string(months[6]);
            break;
        case (0x38):
            lcd_string(months[7]);
            break;
        case (0x39):
            lcd_string(months[8]);
            break;
       
        default:
            lcd_string(error);
    }
}
