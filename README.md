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
         uint8_t _rxBuffer[6];
         uint8_t _reg[2];

         int main(void){

                  I2C_init();
                  DWT_Delay_us(1000); //1 ms
                  MX_GPIO_Init();
                  
                  //Example transmit
                 _txBuffer[0] = 0x05;
                 _txBuffer[1] = 0x04;
                 _txBuffer[2] = 0x15;
                 _txBuffer[3] = 0x00;
                  I2C_transmit(SLAVE_ADDR, _txBuffer, 4); //4 is the size of the transmission (4 bytes)

                 DWT_Delay_us(5000);
                  //Example receive
                 int reg_size = 2; //Size of reg addr to read 
                 int rx_size = 4; // Number of bytes to receive
                 reg[0] = 0x85;
	             reg[1] = 0x20;

                 for (int i = 0; i < rx_size; i++)
		            _rxBuffer[i] = 0x00; // clear rx buffer

                I2C_receive(SLAVE_ADDR, reg, _rxBuffer, reg_size, rx_size); // Stores received bytes in _rxBuffer
            
         }


## Credit
This was inspired by and adapted from:
https://calcium3000.wordpress.com/2016/08/19/i2c-bit-banging-tutorial-part-i/
and
https://github.com/tobajer/i2cbitbang

