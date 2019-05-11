/*
 * ltc1606csw.h
 *
 *  Created on: Oct 30, 2018
 *      Author: ehaengel
 */

#include <stdint.h>

#include "serial_communication.h"
#include "definitions.h"

#ifndef LTC1606CSW_H_
#define LTC1606CSW_H_

#define LTC1606CSW_D0       71
#define LTC1606CSW_D1       73
#define LTC1606CSW_D2       78
#define LTC1606CSW_D3       86
#define LTC1606CSW_D4       87
#define LTC1606CSW_D5       2
#define LTC1606CSW_D6       3
#define LTC1606CSW_D7       4
#define LTC1606CSW_D8       89
#define LTC1606CSW_D9       90
#define LTC1606CSW_D10      91
#define LTC1606CSW_D11      92
#define LTC1606CSW_D12      10
#define LTC1606CSW_D13      11
#define LTC1606CSW_D14      12
#define LTC1606CSW_D15      13
#define LTC1606CSW_BYTE     70
#define LTC1606CSW_R_NC     69
#define LTC1606CSW_NCS      43
#define LTC1606CSW_BUSY     42

void ltc1606csw_initialize();

void ltc1606csw_start_conversion();
int ltc1606csw_check_busy();
int16_t ltc1606csw_read_output();

int16_t ltc1606csw_get_sample();

#endif /* LTC1606CSW_H_ */
