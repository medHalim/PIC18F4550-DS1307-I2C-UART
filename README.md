# Real Time Clock Monitor Project 

Clock and Calendar monitor using PIC18F4550 and DS1307 RTC and communication via I2C and UART. 

## Project Overview

The project consist of a transmitter PIC18F4550 and a receiver one. The Transmitter microcontroller collects RTC Data through I2C, while the receiver microcontroller gets the RTC Data through UART and decodes it into a redable clock with a calendar that is shown in a 16x2 LCD.

The project was simulated in Proteus v8.10 SP3 and works fine but with a high CPU usage.

## Schematic

![PIC18F4550-DS1307](https://user-images.githubusercontent.com/58752435/135696903-3bb9c3ff-931a-4fcd-ac92-4ef771a00a1f.jpg)
