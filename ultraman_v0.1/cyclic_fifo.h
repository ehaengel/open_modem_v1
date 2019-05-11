/*
 * cyclic_fifo.h
 *
 *  Created on: May 5, 2019
 *      Author: ehaengel
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "definitions.h"

#ifndef CYCLIC_FIFO_H_
#define CYCLIC_FIFO_H_

#define CYCLIC_FIFO_DEPTH   0x4000

struct cyclic_fifo
{
    unsigned char write_pointer;
    unsigned char read_pointer;
    uint16_t data[CYCLIC_FIFO_DEPTH];
};
static volatile struct cyclic_fifo* _cyclic_fifo = (struct cyclic_fifo*) RAMGS6_START;
//static volatile struct cyclic_fifo* _cyclic_fifo;

void cyclic_fifo_initialize();
char cyclic_fifo_full();
char cyclic_fifo_empty();
char cyclic_fifo_write(uint16_t value);
uint16_t cyclic_fifo_read();

#endif /* CYCLIC_FIFO_H_ */
