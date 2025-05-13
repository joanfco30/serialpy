
import serial

import RPi.GPIO as IO
import time
import random
tini = time.time()
tact = 0
tsta = 0
print(tini)

IO.setwarnings(False)
IO.setmode(IO.BOARD)

ser = serial.Serial("/dev/ttyS0",baudrate = 9600)


while True:
    
    data_read = ser.read_until(b'\n').decode()
    
    if data_read[0] == 't':
        print(f'Temperatura: {data_read[1:]}')
    if data_read[0] == 'h':
        print(f'Humedad: {data_read[1:]}')
        
    
    val_array = ['r150', 'g250', 'b255']
    
    tact = time.time()
    tsta = tact - tini
    if tsta > 3:
        print("Dato enviado")
        index = random.randint(0,2)
        val = val_array[index]
        ser.write(val.encode())
        tini = time.time()
