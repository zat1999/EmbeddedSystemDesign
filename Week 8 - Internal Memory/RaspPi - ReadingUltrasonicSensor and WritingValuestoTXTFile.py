import time
import RPi.GPIO as GPIO;


triggerPin = 24;					#pins for trigger and echo
echoPin = 23;
threshold_distance = 100;			#indicates when the object is too close

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(triggerPin, GPIO.OUT)	#data direction for pins
GPIO.setup(echoPin, GPIO.IN)

def GetOutput(self):				#function definition for the ultrasonic sensor to calculate the distance
	GPIO.output(triggerPin, False)
	time.sleep(0.00002)
	GPIO.output(triggerPin, True)
	time.sleep(0.00001)
	GPIO.output(triggerPin, False)
	
	
	startTime = time.time()
	stopTime = time.time()
	while GPIO.input(echoPin) == 0:
		startTime = time.time()

	while GPIO.input(echoPin) == 1:
		stopTime = time.time()

	timeElapsed = stopTime - startTime		##the duration of flight
	#print(timeElapsed)    
	distance = (timeElapsed * 34300 / 2)	##the distance calculated
	print(distance)
	return distance





while True:
	dis = GetOutput();						#calls the function to get the distance
	if dis < threshold_distance:			#compares it to the threshold
		t = time.localtime();				#gets the time in epoch-time
		txt = time.strftime("%Y-%m-%d %H:%M:%S", s);	#formats into a readable format
		logFile = open("log.txt","a")					#opens and appends it to a text file
		logFile.write(txt);				
		logFile.close();
	
	time.sleep(5);							#repeats the cycle every 5 seconds
		
		