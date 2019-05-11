#!/usr/bin/python
import sys, os
import socket
import serial
import select
import time
from math import *

class DFE_Server:
    def __init__(self):
        # Socket data
        self.sample_server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sample_server_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.sample_server_sock.bind(('localhost', 12345))
        self.sample_server_sock.listen(1)

        self.control_server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.control_server_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.control_server_sock.bind(('localhost', 54321))
        self.control_server_sock.listen(1)

        self.sample_client = None
        self.control_client = None

        # Serial data
        self.serial_client = None
        self.dac_value = 0x0000

        self.last_update = time.time()

    def update(self):
        # If control client not connected, wait on connection
        if self.control_client == None:
            (self.control_client, address) = self.control_server_sock.accept()
            self.control_client.setblocking(0)

        # Grab any control messages if available
        elif self.control_client in select.select([self.control_client], [], [], 0.05)[0]:
            message = self.control_client.recv(100)
            if len(message) == 0:
                self.control_client.close()
                self.control_client = None

            print message.replace('\n', '').replace('\r', '')

        # If serial not connected, connect serial
        if self.serial_client == None:
            for filename in os.listdir('/dev/'):
                if 'ttyUSB' in filename:
                    try:
                        self.serial_client = serial.Serial('/dev/' + filename, 2500000)
                        break

                    except:
                        continue

        elif self.serial_client in select.select([self.serial_client], [], [], 0.05)[0]:
            try:
                read_count = self.serial_client.in_waiting - (self.serial_client.in_waiting % 3)
                print self.serial_client.in_waiting, read_count
                long_message = self.serial_client.read(read_count)


                send_message = bytearray()
                for n in range(0, read_count/3):
                    message = int(long_message[3*n:3*n+3].encode('hex'), 16)

                    adc_value = message & 0xFFFF
                    #adc_value = (adc_value >> 8) + ((adc_value & 0xFF) << 8)
                    status = (message>>16) & 0xFF
                    #if status & 0x02 == 0x00:

                    if status == 0xab:
                        send_message.append(adc_value >> 8)
                        send_message.append(adc_value & 0xFF)
                    #self.control_client.send('%x, %d\n' % (status, adc_value))

                    x = bytearray()
                    if self.dac_value > 127:
                        x.append(0xFF)
                    else:
                        x.append(0x00)
                    #x.append(0x00)
                    send_value = 100.0*sin(self.dac_value*pi/10.0) + 120
                    if send_value > 255.0:
                        send_value = 255.0
                    elif send_value < 0.0:
                        send_value = 0.0
                    #x.append(int(send_value) & 0xFF)
                    ##x.append(self.dac_value & 0xFF)
                    #x.append((self.dac_value >> 8) & 0xFF)
                    self.serial_client.write(x)
                    self.dac_value = (self.dac_value + 1) % 0xFF
                    #print 'dac_value = %u' % self.dac_value

                if status != 0xab:
                    self.serial_client.read(1)

                self.control_client.send(send_message)

                print 'Sample rate: %.2f Hz' % ((read_count/3) / (time.time() - self.last_update))
                #self.control_client.send('\n')
                #self.control_client.send('%.2f Hz' % ((read_count/3) / (time.time() - self.last_update)))
                #self.control_client.send('\n')

            except serial.serialutil.SerialException:
                self.serial_client.close()
                self.serial_client = None
        self.last_update = time.time()

if __name__ == '__main__':
    dfe_server = DFE_Server()

    while 1:
        dfe_server.update()
