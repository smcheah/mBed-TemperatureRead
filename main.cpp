#include "mbed.h"   // Basic Library required for onchip peripherals
#include "LM75B.h"  // Library for LM75B I2C based Temperature sensor
#include "C12832.h" // Library for SPI based LCD

/* Create Objects */ 
C12832 lcd(p5, p7, p6, p8, p11);    // Initialize lcd object with SPI pins
LM75B tmp(p28,p27);                 // Initialize I2C pins for Temperature Sensor

/* Main Program */
int main ()
{
    float board_temp;       // Value in float

    while (1) {
        lcd.cls();          // Clear LCD Screen
        lcd.locate(0,0);    // Reset Coordinate
        board_temp = tmp;   // read temperature and store in floating point
        lcd.printf("Board Temperature = %.2f\n\r",board_temp); // Display Temperature Value
        wait(1.0);          // 1 Sec delay
    }
}
