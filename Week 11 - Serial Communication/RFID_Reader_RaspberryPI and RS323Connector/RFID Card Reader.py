import serial
import serial.tools.list_ports
import json
import RPi.GPIO as GPIO

redGPIO = 20#gpio pin numbers
greenGPIO = 21

GPIO.setmode(GPIO.BCM)
filePath = "/home/pi/Desktop/PersonnelFile.json" #json location
GPIO.setwarnings(False)
GPIO.setup(redGPIO, GPIO.OUT) #setup mode
GPIO.setup(greenGPIO, GPIO.OUT)
try:
    ser = serial.Serial('/dev/ttyUSB0',9600)
except Exception as e:
    print(e);

finalPayload = ''
packetRead = False
foundUID = False

with open(filePath, 'r') as dataFile:
    data = json.load(dataFile)
    ids = data["personnel"]
try:    
    while True:
        while ser.inWaiting() > 0:
            packetRead = True
            payload = ser.read()
            payload = payload.decode()
            finalPayload += payload
            #print(finalPayload)
            
        if packetRead:
            packetRead = False;
            
            for i in range(len(ids)):
                if finalPayload.find(ids[i]) != -1:
                    foundUID = True
            
            if foundUID: #if the bool is true that means matching pair is found, LED lights are toggled
                print("welcome")
                GPIO.output(greenGPIO, GPIO.HIGH);
                GPIO.output(redGPIO, GPIO.LOW);
                foundUID = False;
            else:
                print("not welcome")
                GPIO.output(redGPIO, GPIO.HIGH);
                GPIO.output(greenGPIO, GPIO.LOW);
                foundUID = False;
            finalPayload = "";
            
            
except KeyboardInterrupt:
    GPIO.output(redGPIO, GPIO.LOW);
    GPIO.output(greenGPIO, GPIO.LOW);
    GPIO.cleanup()

    
