#include <stdlib.h>
#include <stdio.h>

#include "cyclic_fifo.h"

int main(int argc, char** argv)
{
    printf("Fifo initialize... ");
    cyclic_fifo_initialize();
    printf("Done.\n");

    printf("Fifo empty: %d\n", cyclic_fifo_empty());
    printf("Fifo write: %d\n", cyclic_fifo_write(0xDE));
    printf("Fifo write: %d\n", cyclic_fifo_write(0xAD));
    printf("Fifo write: %d\n", cyclic_fifo_write(0xBE));
    printf("Fifo write: %d\n", cyclic_fifo_write(0xEF));
    printf("Fifo empty: %d\n", cyclic_fifo_empty());
    printf("Fifo full: %d\n\n", cyclic_fifo_full());

    for(int i=0; i<10; i++)
        printf("Fifo read: 0x%x\n", cyclic_fifo_read());
    printf("Fifo empty: %d\n", cyclic_fifo_empty());
    printf("Fifo full: %d\n\n", cyclic_fifo_full());
    printf("\n");

    for(int i=0; i<20; i++)
        cyclic_fifo_write(i);

    printf("Fifo empty: %d\n", cyclic_fifo_empty());
    printf("Fifo full: %d\n\n", cyclic_fifo_full());

    for(int i=0; i<20; i++)
        printf("Fifo read: 0x%x\n", cyclic_fifo_read());
    printf("Fifo empty: %d\n", cyclic_fifo_empty());
    printf("Fifo full: %d\n\n", cyclic_fifo_full());
    printf("\n");

    return 0;
}
