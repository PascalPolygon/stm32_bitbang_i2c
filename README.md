# stm32_bitbang_i2c
Library to implement I2C on any GPIO for STM32 MCU's. (I2C implemented in software).

Currently only tested on STM32F103, but should work on most STM32 MCU's.

## Important setup
Do define your I2C pins, use STM32CubeMX.
Use the following user labels:

For your SCL pin: **SW_I2C_SCL**

For your SDA pin: **SW_I2C_SDA**

The pins should be Open Drain and Pulled-up.

## Example use
#include "main.h"
#include "stm32_sw_i2c.h"
#include "dwt_stm32_delay.h"

#define SLAVE_ADDR 0x1E

uint8_t _txBuffer[6];

int main(void){

   I2C_init();
   MX_GPIO_Init();
   
  _txBuffer[0] = 0x05;
  _txBuffer[1] = 0x04;
  _txBuffer[2] = 0x15;
  _txBuffer[3] = 0x00;
  
   DWT_Delay_us(300000); //300 ms
   
   I2C_transmit(SLAVE_ADDR, _txBuffer, 4); //4 is the size of the transmission (4 bytes)
   
}


## Credit
This was inspired by and adapted from:
https://calcium3000.wordpress.com/2016/08/19/i2c-bit-banging-tutorial-part-i/
and
https://github.com/tobajer/i2cbitbang

