/*
 * dac5672.c
 *
 *  Created on: May 5, 2019
 *      Author: ehaengel
 */

#include "dac5672.h"

void dac5672_initialize()
{
    initialize_gpio_pin(DAC5672_D13, 0);
    initialize_gpio_pin(DAC5672_D12, 0);
    initialize_gpio_pin(DAC5672_D11, 0);
    initialize_gpio_pin(DAC5672_D10, 0);
    initialize_gpio_pin(DAC5672_D9, 0);
    initialize_gpio_pin(DAC5672_D8, 0);
    initialize_gpio_pin(DAC5672_D7, 0);
    initialize_gpio_pin(DAC5672_D6, 0);
    initialize_gpio_pin(DAC5672_D5, 0);
    initialize_gpio_pin(DAC5672_D4, 0);
    initialize_gpio_pin(DAC5672_D3, 0);
    initialize_gpio_pin(DAC5672_D2, 0);
    initialize_gpio_pin(DAC5672_D1, 0);
    initialize_gpio_pin(DAC5672_D0, 0);
    initialize_gpio_pin(DAC5672_WRTA, 0);
    initialize_gpio_pin(DAC5672_CLKA, 0);

    GPIO_WritePin(DAC5672_D0, 0);
    GPIO_WritePin(DAC5672_D1, 0);
    GPIO_WritePin(DAC5672_D2, 0);
    GPIO_WritePin(DAC5672_D3, 0);
    GPIO_WritePin(DAC5672_D4, 0);
    GPIO_WritePin(DAC5672_D5, 0);

    dac5672_write(0x0000);
    dac5672_write(0xFFFF >> 4);
}

void dac5672_write(uint16_t value)
{
    //value = 0x3FFF - value;
    /*GpioDataRegs.GPADAT.bit.GPIO18 = (value >> 0) & 0x01;
    GpioDataRegs.GPADAT.bit.GPIO19 = (value >> 1) & 0x01;
    GpioDataRegs.GPADAT.bit.GPIO20 = (value >> 2) & 0x01;
    GpioDataRegs.GPADAT.bit.GPIO21 = (value >> 3) & 0x01;
    GpioDataRegs.GPDDAT.bit.GPIO99 = (value >> 4) & 0x01;
    GpioDataRegs.GPBDAT.bit.GPIO41 = (value >> 5) & 0x01;
    GpioDataRegs.GPBDAT.bit.GPIO58 = (value >> 6) & 0x01;
    GpioDataRegs.GPBDAT.bit.GPIO59 = (value >> 7) & 0x01;
    GpioDataRegs.GPBDAT.bit.GPIO60 = (value >> 8) & 0x01;
    GpioDataRegs.GPBDAT.bit.GPIO61 = (value >> 9) & 0x01;
    GpioDataRegs.GPBDAT.bit.GPIO62 = (value >> 10) & 0x01;
    GpioDataRegs.GPBDAT.bit.GPIO63 = (value >> 11) & 0x01;
    GpioDataRegs.GPCDAT.bit.GPIO64 = (value >> 12) & 0x01;
    GpioDataRegs.GPCDAT.bit.GPIO65 = (value >> 13) & 0x01;*/

    //GpioDataRegs.GPBDAT.all = ((Uint32) (value & 0x3F)) << 26;
    //GpioDataRegs.GPCDAT.all = (value >> 6) & 0x03;

    GPIO_WritePin(DAC5672_D6, (value >> 0) & 0x01);
    GPIO_WritePin(DAC5672_D7, (value >> 1) & 0x01);
    GPIO_WritePin(DAC5672_D8, (value >> 2) & 0x01);
    GPIO_WritePin(DAC5672_D9, (value >> 3) & 0x01);
    GPIO_WritePin(DAC5672_D10, (value >> 4) & 0x01);
    GPIO_WritePin(DAC5672_D11, (value >> 5) & 0x01);
    GPIO_WritePin(DAC5672_D12, (value >> 6) & 0x01);
    GPIO_WritePin(DAC5672_D13, (value >> 7) & 0x01);

    /*GPIO_WritePin(DAC5672_D0, (value >> 0) & 0x01);
    GPIO_WritePin(DAC5672_D1, (value >> 1) & 0x01);
    GPIO_WritePin(DAC5672_D2, (value >> 2) & 0x01);
    GPIO_WritePin(DAC5672_D3, (value >> 3) & 0x01);
    GPIO_WritePin(DAC5672_D4, (value >> 4) & 0x01);
    GPIO_WritePin(DAC5672_D5, (value >> 5) & 0x01);
    GPIO_WritePin(DAC5672_D6, (value >> 6) & 0x01);
    GPIO_WritePin(DAC5672_D7, (value >> 7) & 0x01);
    GPIO_WritePin(DAC5672_D8, (value >> 8) & 0x01);
    GPIO_WritePin(DAC5672_D9, (value >> 9) & 0x01);
    GPIO_WritePin(DAC5672_D10, (value >> 10) & 0x01);
    GPIO_WritePin(DAC5672_D11, (value >> 11) & 0x01);
    GPIO_WritePin(DAC5672_D12, (value >> 12) & 0x01);
    GPIO_WritePin(DAC5672_D13, (value >> 13) & 0x01);*/

    /*GpioDataRegs.GPADAT.bit.GPIO16 = 1;
    GpioDataRegs.GPADAT.bit.GPIO17 = 1;
    GpioDataRegs.GPADAT.bit.GPIO16 = 0;
    GpioDataRegs.GPADAT.bit.GPIO17 = 0;*/

    GPIO_WritePin(DAC5672_CLKA, 1);
    GPIO_WritePin(DAC5672_WRTA, 1);
    GPIO_WritePin(DAC5672_CLKA, 0);
    GPIO_WritePin(DAC5672_WRTA, 0);
}
