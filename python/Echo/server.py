import socket
import sys

HOST = 'localhost'
PORT = 8001
ADDR = (HOST, PORT)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(ADDR)
s.listen(10)

conn,addr = s.accept()
print("connected by ",addr)
while True:
    data = conn.recv(1024)
    if not data:
        print('client closed.')
        break
    conn.send(data)
s.close()
print('close the server.')

