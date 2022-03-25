import socket
import keyboard

port = 1111
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('0.0.0.0', port))
s.listen(0)


def send(y) :
    n = 3
    while n > 0 :
        client, addr = s.accept()
        client.settimeout(200)
        print(y)
        client.send(bytes(y, encoding="utf8"))
        client.close()
        n -= 1

while True :

    while keyboard.is_pressed('w') :
        y = ('w')
        send(y)

    y = 'o'
    send(y)    
    
    while keyboard.is_pressed('s') :
        y = ('s')
        send(y)
    y = 'o'
    send(y) 

    while keyboard.is_pressed('a') :
        y = ('a')
        send(y)

    y = 'o'
    send(y)     
    
    while keyboard.is_pressed('d') :
        y = ('d')
        send(y)
        
    y = 'o'
    send(y) 


