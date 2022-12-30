
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2); //address, column and row


//pins definitions
int triggerPin = 9;
int echoPin = 10;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Starts the serial communication
  lcd.begin(16,2);
  lcd.setCursor(0, 0);  //place cursor text point at 0,0
  pinMode(triggerPin, OUTPUT); // to send ultrasonic wave
  pinMode(echoPin, INPUT); // to receive reflected wave back
}

void loop() {


  digitalWrite(triggerPin, LOW); //reset it to zero
  delayMicroseconds(2);


 
  digitalWrite(triggerPin, HIGH); //sends a pulse
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  
  duration = pulseIn(echoPin, HIGH);  //receives that pulse and calculates the time difference
  // Calculating the distance
  distance = duration * 0.034 / 2;  
  //distance = durations * speed of sound divide by 2 since its the forward and backward sound wave



  Serial.print("Distance: ");
  Serial.println(distance);
  lcd.print(distance);
  lcd.clear();
}
