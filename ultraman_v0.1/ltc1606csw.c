/*
 * ltc1606csw.c
 *
 *  Created on: Oct 30, 2018
 *      Author: ehaengel
 */

#include "ltc1606csw.h"


void ltc1606csw_initialize()
{
    initialize_gpio_pin(LTC1606CSW_D0, 1);
    initialize_gpio_pin(LTC1606CSW_D1, 1);
    initialize_gpio_pin(LTC1606CSW_D2, 1);
    initialize_gpio_pin(LTC1606CSW_D3, 1);
    initialize_gpio_pin(LTC1606CSW_D4, 1);
    initialize_gpio_pin(LTC1606CSW_D5, 1);
    initialize_gpio_pin(LTC1606CSW_D6, 1);
    initialize_gpio_pin(LTC1606CSW_D7, 1);
    initialize_gpio_pin(LTC1606CSW_D8, 1);
    initialize_gpio_pin(LTC1606CSW_D9, 1);
    initialize_gpio_pin(LTC1606CSW_D10, 1);
    initialize_gpio_pin(LTC1606CSW_D11, 1);
    initialize_gpio_pin(LTC1606CSW_D12, 1);
    initialize_gpio_pin(LTC1606CSW_D13, 1);
    initialize_gpio_pin(LTC1606CSW_D14, 1);
    initialize_gpio_pin(LTC1606CSW_D15, 1);
    initialize_gpio_pin(LTC1606CSW_BYTE, 0);
    initialize_gpio_pin(LTC1606CSW_R_NC, 0);
    initialize_gpio_pin(LTC1606CSW_NCS, 0);
    initialize_gpio_pin(LTC1606CSW_BUSY, 1);

    GPIO_WritePin(LTC1606CSW_BYTE, 0);
    GPIO_WritePin(LTC1606CSW_NCS, 0);
    GPIO_WritePin(LTC1606CSW_R_NC, 1);
}

void ltc1606csw_start_conversion()
{
    GPIO_WritePin(LTC1606CSW_R_NC, 0);
    GPIO_WritePin(LTC1606CSW_R_NC, 1);
}

int ltc1606csw_check_busy()
{
    return !GPIO_ReadPin(LTC1606CSW_BUSY);
}

int16_t ltc1606csw_read_output()
{
    int16_t result = 0x00;
    result |= GPIO_ReadPin(LTC1606CSW_D0) << 0;
    result |= GPIO_ReadPin(LTC1606CSW_D1) << 1;
    result |= GPIO_ReadPin(LTC1606CSW_D2) << 2;
    result |= GPIO_ReadPin(LTC1606CSW_D3) << 3;
    result |= GPIO_ReadPin(LTC1606CSW_D4) << 4;
    result |= GPIO_ReadPin(LTC1606CSW_D5) << 5;
    result |= GPIO_ReadPin(LTC1606CSW_D6) << 6;
    result |= GPIO_ReadPin(LTC1606CSW_D7) << 7;
    result |= GPIO_ReadPin(LTC1606CSW_D8) << 8;
    result |= GPIO_ReadPin(LTC1606CSW_D9) << 9;
    result |= GPIO_ReadPin(LTC1606CSW_D10) << 10;
    result |= GPIO_ReadPin(LTC1606CSW_D11) << 11;
    result |= GPIO_ReadPin(LTC1606CSW_D12) << 12;
    result |= GPIO_ReadPin(LTC1606CSW_D13) << 13;
    result |= GPIO_ReadPin(LTC1606CSW_D14) << 14;
    result |= GPIO_ReadPin(LTC1606CSW_D15) << 15;

    return result;
}

int16_t ltc1606csw_get_sample()
{
    ltc1606csw_start_conversion();
    while(ltc1606csw_check_busy());
    return ltc1606csw_read_output();
}
