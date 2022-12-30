

import serial
import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM);
flag = False

led_pin = 14
GPIO.setup(led_pin, GPIO.OUT)
pwm1 = GPIO.PWM(led_pin, 100);
pwm1.start(0)                       


try:
    ser = serial.Serial('/dev/ttyAMA0', 9600);  #opens TX-GPIO pin to receive data
except Exception as e:                          #will display any errors if can't connect and reset the pins
    print(e);
    GPIO.output(led_pin, GPIO.LOW);
    GPIO.cleanup();
    

while ser.inWaiting:                            #if the RX-GPIO pin receives any data
    line = ser.readline().strip();              #get the date format it properly and decode it properly
    values = line.decode(); 
    val = int(values);                          #converts to int data-type
    pwm1.ChangeDutyCycle(val);                  #sends a pwm signal to an LED        
