import serial
from time import sleep

flag = False

try:
    ser = serial.Serial('/dev/ttyAMA0', 9600); #GPIO TX
except Exception as e:
    print(e);
    

while True:
    val = input("Degrees (0-360): "); #gets inputs
    if(val.isdecimal()):
        ser.write(str(val).encode()); #if number value write, encode it and write it
    else:
        print("Not an Integer");
    
    
