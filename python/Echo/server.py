import socket
import sys
import os

HOST = 'localhost'
PORT = 8001
ADDR = (HOST, PORT)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(ADDR)
s.listen(10)

shutdown = 0
while not shutdown:
    conn,addr=s.accept()
    print("connected by ",addr)

    pid = os.fork()

    if pid>0:  #child process.
        while True:
            data = conn.recv(1024)
            if not data:
                 print('client ',addr,' closed.')
                 break
            conn.send(data)
            if data=='shutdown':
                shutdown = 1
                break
        conn.close()
        print('close the client fd.')

    if pid==0:  #corrent process.
        print('corrent process.')
s.close()

