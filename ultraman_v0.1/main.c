#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "F28x_Project.h"
#include "serial_communication.h"
#include "ltc1606csw.h"
#include "dac5672.h"

__interrupt void cpu_timer0_isr(void);

void main(void)
{
    InitSysCtrl();
    InitGpio();

    DINT;
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();
    EALLOW;
    PieVectTable.TIMER2_INT = &cpu_timer0_isr;
    EDIS;
    InitCpuTimers();
    //ConfigCpuTimer(&CpuTimer0, 200, 1000000);
    ConfigCpuTimer(&CpuTimer2, 200, 100);
    CpuTimer2Regs.TCR.all = 0x4000;
    IER |= M_INT1;
    IER |= M_INT13;
    IER |= M_INT14;
    IER |= M_INT9;
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
    EINT;
    ERTM;

    initialize_uart();
    ltc1606csw_initialize();
    dac5672_initialize();

    ltc1606csw_start_conversion();

    //char buffer[50];
    /*int state = 0;
    int16_t result = 0x00;
    unsigned char message[2] = { 0x00, 0x00 };
    while(1)
    {
        ltc1606csw_start_conversion();
        DELAY_US(1);
        while(ltc1606csw_check_busy());

        result = ltc1606csw_read_output();
        message[0] = result & 0xFF;
        message[1] = (result >> 8) & 0xFF;
        if(state == 1)
            send_bin_message(message, 2);

        if(receive_buffer[0] == 'A')
        {
            state = 1;
            DELAY_US(1e6);
            clear_receive_buffer();
        }
        else if(receive_buffer[0] == 'B')
        {
            state = 0;
            clear_receive_buffer();
        }

        //sprintf(buffer, "Hello, World! %d\r\n", result);
        //send_char_message(buffer);
        //DELAY_US(1e5);
    }*/
    while(1)
    {
        /*dac5672_write(0x3FFF);
        DELAY_US(1e2);
        dac5672_write(0x0000);
        DELAY_US(1e2);*/
    }
}

static volatile uint16_t dac_value = 0x0000;
static volatile int16_t adc_value = 0x0000;
static unsigned char message_buffer[3];
__interrupt void cpu_timer0_isr(void)
{
    if(cyclic_fifo_empty() == 0)
        dac_value = cyclic_fifo_read();
    dac5672_write(dac_value);

    //dac5672_write(dac_value >> 2);
    //dac_value = (dac_value + 0x1000) % 0xFFFF;

    if(ltc1606csw_check_busy() == 0)
    {
        adc_value = ltc1606csw_read_output();
        ltc1606csw_start_conversion();
    }

    //message_buffer[0] = cyclic_fifo_empty() + (cyclic_fifo_full() << 1);
    //message_buffer[0] = ((_cyclic_fifo->write_pointer & 0x0F) << 4) + (_cyclic_fifo->read_pointer & 0x0F);
    message_buffer[0] = 0xab;
    message_buffer[1] = (adc_value) & 0xFF;
    message_buffer[2] = (adc_value >> 8) & 0xFF;
    send_bin_message(message_buffer, 3);

    //SciaRegs.SCITXBUF.all = (adc_value>>8) & 0xFF;

    CpuTimer0.InterruptCount++;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
