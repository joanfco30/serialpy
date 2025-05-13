import serial

ser = serial.Serial("/dev/ttyS0",baudrate = 9600)


while True:
    print(ser.read_until(b'\n').decode())
    val = "Valor recibido"
    ser.write(val.encode())