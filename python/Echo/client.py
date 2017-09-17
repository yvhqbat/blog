import socket
import sys

HOST = '127.0.0.1'
PORT = 8001
SERVER = (HOST, PORT)

c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
c.connect(SERVER)

while True:
    data = raw_input('input data')
    if not data:
        print('client quit.')
        break
    c.send(data)
    data = c.recv(1024)
    print('receive: ', data)
    if data=='shutdown':
        break
c.close()

