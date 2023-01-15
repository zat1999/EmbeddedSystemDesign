#include "PinDefinitions.h" //header file
#include "Player.h" //header file
#include "MotorObstacles.h"

#include <Servo.h>
#include <SoftwareSerial.h> //library to communicate with nodemcu


Servo myServo1;
SoftwareSerial espSerial(A4, A5);
Player player1(joystick_1X, joystick_1Y , servoValue); //creates instances of objects
MotorObstacles motor1(motorDriver_IN1,motorDriver_IN2,motorDriver_EN,pwmValue);
double startTime = millis();
double goalTime;
bool checkForBallState = true;

void setup() {

  Serial.begin(9600);

  myServo1.attach(servoValue);
  motor1.EnableMotor();
  DisableUnsedPins();
  pinMode(infaredSensor, INPUT); //Data Direction to accept inputs
  attachInterrupt(digitalPinToInterrupt(infaredSensor),CheckForBall,RISING); //checks if there is a LOW to HIGH signal. Meaning ball triggers the sensor.
}

void loop() 
{
  myServo1.write(player1.SetServo(player1.GetJoyStickAxis())); //Gets Servo Input and Writes the Value to Joystick
}


void CheckForBall()
{
  if(checkForBallState)
  {
    goalTime = millis() - startTime; //difference in time
    goalTime = goalTime/1000; //converts to seconds
    motor1.DisableMotor(); //saves power when the game objective is completed
    checkForBallState = false;
    Serial.println(goalTime); //writes time to MCU can receive it
    
  }

}

// Sets Data Directions to OUTPUT in order to save Power Consumption so it is not constantly checking for an input.
void DisableUnsedPins()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);
}
