/*
 * serial_communications.c
 *
 *  Created on: Sep 9, 2018
 *      Author: ehaengel
 */

#include "serial_communication.h"

// Initialization
void initialize_gpio_pin(int pin, int dir)
{
    // Output
    if(dir == 0)
    {
        GPIO_SetupPinMux(pin, GPIO_MUX_CPU1, 0);
        GPIO_SetupPinOptions(pin, GPIO_OUTPUT, GPIO_PUSHPULL);
        GPIO_WritePin(pin, 0);
    }

    // Input
    else
    {
        GPIO_SetupPinMux(pin, GPIO_MUX_CPU1, 0);
        GPIO_SetupPinOptions(pin, GPIO_INPUT, GPIO_PUSHPULL);
        GPIO_WritePin(pin, 0);
    }
}

void initialize_uart()
{
    // Setup GPIO pins
    GPIO_SetupPinMux(85, GPIO_MUX_CPU1, 5);
    GPIO_SetupPinMux(84, GPIO_MUX_CPU1, 5);
    GPIO_SetupPinOptions(85, GPIO_INPUT, GPIO_PUSHPULL);
    GPIO_SetupPinOptions(84, GPIO_OUTPUT, GPIO_ASYNC);

    // Setup SCIA
    SciaRegs.SCICCR.all =0x0007;
    SciaRegs.SCICTL1.all =0x0003;
    SciaRegs.SCICTL2.all =0x0003;
    //SciaRegs.SCICTL2.bit.TXINTENA = 1;
    //SciaRegs.SCICTL2.bit.RXBKINTENA = 1;

    SciaRegs.SCIFFTX.bit.SCIFFENA = 0x00;
    SciaRegs.SCIFFRX.bit.RXFFINT = 0x00;

    // Baud rate = 115200
    //SciaRegs.SCIHBAUD.all = 0x0000;
    //SciaRegs.SCILBAUD.all = 0x00D8;

    // Baud rate = 2500000
    SciaRegs.SCIHBAUD.all = 0x0000;
    SciaRegs.SCILBAUD.all = 0x0009;

    // Turn SCIA on
    SciaRegs.SCICTL1.all = 0x0023;

    // Setup tx/rx ISR's
    EALLOW;
    ClkCfgRegs.LOSPCP.bit.LSPCLKDIV = 0x00;
    PieVectTable.SCIA_RX_INT = &scia_rx_isr;
    PieVectTable.SCIA_TX_INT = &scia_tx_isr;
    EDIS;

    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;   // Enable the PIE block
    PieCtrlRegs.PIEIER9.bit.INTx1=1;     // PIE Group 9, INT1
    PieCtrlRegs.PIEIER9.bit.INTx2=1;     // PIE Group 9, INT2

    // Initialize receive buffer
    size_t i=0;
    for(i=0; i<RAMGS11_SIZE; i++)
        receive_buffer[i] = 0x00;
}

// Communication
void send_char_message(char* message)
{
    char* p = message;
    while(*p)
    {
        while (SciaRegs.SCICTL2.bit.TXRDY != 1) {}
        SciaRegs.SCITXBUF.all = *(p++);
    }
}

void send_bin_message(unsigned char* message, size_t message_length)
{
    size_t i=0;
    for(i=0; i<message_length; i++)
    {
        while (SciaRegs.SCICTL2.bit.TXRDY != 1) {}
        SciaRegs.SCITXBUF.all = message[i];
    }
}

void clear_receive_buffer()
{
    int i=0;
    for(i=0; i<=received_character_count; i++)
        receive_buffer[i] = '\0';

    received_character_count = 0;
}


// Interrupts for UART serial communication
interrupt void scia_rx_isr(void)
{
    //if(received_character_count < RAMGS11_SIZE)
    //    receive_buffer[received_character_count++] = (char) (SciaRegs.SCIRXBUF.all & 0xFF);

    cyclic_fifo_write(SciaRegs.SCIRXBUF.all);
    /*if(scia_rx_parity == 0)
    {
        scia_rx_value = ((uint16_t) (SciaRegs.SCIRXBUF.all & 0xFF)) << 8;
        scia_rx_parity = 1;
    }
    else if(scia_rx_parity == 1)
    {
        scia_rx_value += (uint16_t) (SciaRegs.SCIRXBUF.all & 0xFF);
        cyclic_fifo_write(scia_rx_value);
        scia_rx_value = 0x0000;
        scia_rx_parity = 0;
    }*/

    SciaRegs.SCIFFRX.bit.RXFFOVRCLR=1;   // Clear Overflow flag
    SciaRegs.SCIFFRX.bit.RXFFINTCLR=1;   // Clear Interrupt flag

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
}

interrupt void scia_tx_isr(void)
{
    SciaRegs.SCIFFTX.bit.TXFFINTCLR=1;  // Clear SCI Interrupt flag
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;
}

