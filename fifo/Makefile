all: fifo_test

fifo_test: cyclic_fifo.h cyclic_fifo.c fifo_test.c
	gcc -c cyclic_fifo.c -o cyclic_fifo.o
	gcc fifo_test.c cyclic_fifo.o -o fifo_test

clean:
	rm -f fifo_test cyclic_fifo.o
