#include <Servo.h>

const int output_pin = 3;
const int potentiometer_pin = A0;
Servo servo;  //create servo object

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(output_pin, OUTPUT);        //output pin
  pinMode(potentiometer_pin, INPUT);  //set up input pin
  servo.attach(output_pin);           //attach the servo object to the pin
  
}

void loop() {
  int potVal = analogRead(potentiometer_pin); //reads from the potentiometer
  potVal = map(potVal, 0 ,1023,0, 180);       //maps it between 0-180deg instead
  servo.write(potVal);                        //turns servo
}
