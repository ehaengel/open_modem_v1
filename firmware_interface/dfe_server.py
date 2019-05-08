#!/usr/bin/python
import sys, os
import socket
import serial
import select

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
                        self.serial_client = serial.Serial('/dev/' + filename, 115200)
                        break

                    except:
                        continue

        elif self.serial_client in select.select([self.serial_client], [], [], 0.05)[0]:
            try:
                self.control_client.send(self.serial_client.readline())

            except serial.serialutil.SerialException:
                self.serial_client.close()
                self.serial_client = None

if __name__ == '__main__':
    dfe_server = DFE_Server()

    while 1:
        dfe_server.update()
