/*
 * dac5672.h
 *
 *  Created on: May 5, 2019
 *      Author: ehaengel
 */

#include "F28x_Project.h"
#include "serial_communication.h"

#ifndef DAC5672_H_
#define DAC5672_H_

#define DAC5672_D13     65
#define DAC5672_D12     64
#define DAC5672_D11     63
#define DAC5672_D10     62
#define DAC5672_D9      61
#define DAC5672_D8      60
#define DAC5672_D7      59
#define DAC5672_D6      58
#define DAC5672_D5      41
#define DAC5672_D4      99
#define DAC5672_D3      21
#define DAC5672_D2      20
#define DAC5672_D1      19
#define DAC5672_D0      18
#define DAC5672_WRTA    17
#define DAC5672_CLKA    16

void dac5672_initialize();
void dac5672_write(uint16_t value);

#endif /* DAC5672_H_ */
