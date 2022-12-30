const int servo_pin = 3;
#include <Servo.h>
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(servo_pin, OUTPUT);
  servo.attach(servo_pin);                          //attach it to a servo
}

void loop() {
  if(Serial.available() > 0)
  {
    String payload = Serial.readStringUntil('\n');  //reads from RX pin
    int val = payload.toInt();                      //converts it to a int data type
    servo.write(val);                               //write it to a servo
  }
  
}
