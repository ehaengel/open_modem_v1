/*
 * cyclic_fifo.c
 *
 *  Created on: May 5, 2019
 *      Author: ehaengel
 */

#include "cyclic_fifo.h"

void cyclic_fifo_initialize()
{
    //_cyclic_fifo = (struct cyclic_fifo*) malloc(sizeof(struct cyclic_fifo));

    _cyclic_fifo->write_pointer = 0x00;
    _cyclic_fifo->read_pointer = 0x00;

    int i=0;
    for(i=0; i<CYCLIC_FIFO_DEPTH; i++)
        _cyclic_fifo->data[i] = 0x00;
}

char cyclic_fifo_full()
{
    if((_cyclic_fifo->write_pointer+1) % CYCLIC_FIFO_DEPTH == _cyclic_fifo->read_pointer)
        return 1;

    return 0;
}

char cyclic_fifo_empty()
{
    if(_cyclic_fifo->read_pointer == _cyclic_fifo->write_pointer)
        return 1;

    return 0;
}

char cyclic_fifo_write(uint16_t value)
{
    if(cyclic_fifo_full())
        return 0;

    _cyclic_fifo->data[_cyclic_fifo->write_pointer] = value;
    _cyclic_fifo->write_pointer = (_cyclic_fifo->write_pointer + 1) % CYCLIC_FIFO_DEPTH;

     return 1;
}

uint16_t cyclic_fifo_read()
{
    if(cyclic_fifo_empty())
        return 0;

    uint16_t value = _cyclic_fifo->data[_cyclic_fifo->read_pointer];
    _cyclic_fifo->read_pointer = (_cyclic_fifo->read_pointer + 1) % CYCLIC_FIFO_DEPTH;

    return value;
}



