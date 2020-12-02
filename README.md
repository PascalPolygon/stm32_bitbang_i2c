# stm32_bitbang_i2c
Library to implement I2C on any GPIO for STM32 MCU's. (I2C implemented in software).

Currently only tested on STM32F103, but should work on most STM32 MCU's.

## Important setup
Do define your I2C pins, use STM32CubeMX.
Use the following user labels:

For your SCL pin: **SW_I2C_SCL**

For your SDA pin: **SW_I2C_SDA**

The pins should be Open Drain and pulled-up.
