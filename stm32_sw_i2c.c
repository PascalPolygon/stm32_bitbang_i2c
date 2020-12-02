#include "main.h"
#include "dwt_stm32_delay.h"
#include "stm32_sw_i2c.h"

//void I2C_bus_init(uint8_t scl_pin, uint8_t sda_pin, uint8_t port){
//	  /*Configure GPIO pins : SW_I2C_SCL_Pin SW_I2C_SDA_Pin */
//	  GPIO_InitStruct.Pin = SW_I2C_SCL_Pin|SW_I2C_SDA_Pin;
//	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
//	  GPIO_InitStruct.Pull = GPIO_PULLUP;
//	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//}

void I2C_init(void)
{
    I2C_SET_SDA;
    I2C_SET_SCL;
}

void I2C_start_cond(void)
{
    I2C_SET_SCL
    I2C_SET_SDA
    I2C_DELAY
    I2C_CLEAR_SDA
    I2C_DELAY
    I2C_CLEAR_SCL
    I2C_DELAY
}

void I2C_stop_cond(void)
{
    I2C_CLEAR_SDA
    I2C_DELAY
    I2C_SET_SCL
    I2C_DELAY
    I2C_SET_SDA
    I2C_DELAY
}

void I2C_write_bit(uint8_t b)
{
    if (b > 0)
        I2C_SET_SDA
    else
        I2C_CLEAR_SDA

    I2C_DELAY
    I2C_SET_SCL
    I2C_DELAY
    I2C_CLEAR_SCL
}

uint8_t I2C_read_SDA(void)
{
    if (HAL_GPIO_ReadPin(SW_I2C_SDA_GPIO_Port, SW_I2C_SDA_Pin) == GPIO_PIN_SET)
        return 1;
    else
        return 0;
    return 0;
}

// Reading a bit in I2C:
uint8_t I2C_read_bit(void)
{
    uint8_t b;

    I2C_SET_SDA
    I2C_DELAY
    I2C_SET_SCL
    I2C_DELAY

    //    if( I2C_INPORT & SDA ) b = 1;
    //    else b = 0;
    b = I2C_read_SDA();

    I2C_CLEAR_SCL

    return b;
}

_Bool I2C_write_byte(uint8_t B,
                     _Bool start,
                     _Bool stop)
{
    uint8_t ack = 0;

    if (start)
        I2C_start_cond();

    uint8_t i;
    for (i = 0; i < 8; i++)
    {
        I2C_write_bit(B & 0x80); // write the most-significant bit
        B <<= 1;
    }

    ack = I2C_read_bit();

    if (stop)
        I2C_stop_cond();

    return ack;
}
