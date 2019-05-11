/*
 * serial_communication.h
 *
 *  Created on: Sep 9, 2018
 *      Author: ehaengel
 */

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "F28x_Project.h"
#include "definitions.h"
#include "cyclic_fifo.h"

#ifndef SERIAL_COMMUNICATION_H_
#define SERIAL_COMMUNICATION_H_

//Initialization
void initialize_uart();
void initialize_gpio_pin(int pin, int dir);

// Communication
volatile static char* receive_buffer = (volatile char*) RAMGS11_START;
volatile static size_t received_character_count = 0;

volatile static uint16_t scia_rx_value = 0x0000;
volatile static char scia_rx_parity = 0;

void send_char_message(char* message);
void send_bin_message(unsigned char* message, size_t message_length);

void clear_receive_buffer();

// Interrupts for UART serial communication
interrupt void scia_rx_isr(void);
interrupt void scia_tx_isr(void);

#endif /* SERIAL_COMMUNICATION_H_ */
