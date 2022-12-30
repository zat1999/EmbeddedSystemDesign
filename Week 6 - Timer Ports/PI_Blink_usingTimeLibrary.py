import RPi.GPIO as GPIO             #imports the needed classes
import time

GPIO.setmode(GPIO.BCM);

class LED:                          #define the class
    delayTime = 0;
    blinkDuration = 0;
    ledPin = 0;
    offset = 0;
    state = 0;
    
    def __init__(self, pin, t, d):  #define the constructor
        self.ledPin = pin;          #variable setters
        self.delayTime = t;
        self.blinkDuration = d;
        self.state = 0;
        GPIO.setup(self.ledPin, GPIO.OUT);  #responsible for the output mode
        GPIO.output(self.ledPin,GPIO.LOW);  #outputs to LOW

led1 = LED(14,0.5,0.5)  #creates instances of LEDs
led2 = LED(15,1,1)
led3 = LED(18,3,3)

LED_Array = [led1, led2, led3]  #adds to array
startTime = time.time();        #gets starting time (constant)

try:
    while True:
        currentTime = time.time();          #gets the current time of the system
        runTime = currentTime - startTime;  #calculates the run time
        
        for led in LED_Array:               #same logic as before in Session 1, EXP1
            if(runTime - led.offset > led.delayTime and not led.state):
                GPIO.output(led.ledPin,GPIO.HIGH);
                led.offset += led.delayTime;
                led.state = 1;
            elif(runTime - led.offset > led.blinkDuration and led.state):
                GPIO.output(led.ledPin,GPIO.LOW);
                led.offset += led.delayTime;
                led.state = 0;
except KeyboardInterrupt:
    GPIO.output(led1.ledPin, GPIO.LOW);
    GPIO.output(led2.ledPin, GPIO.LOW);
    GPIO.output(led3.ledPin, GPIO.LOW);
    GPIO.cleanup()
