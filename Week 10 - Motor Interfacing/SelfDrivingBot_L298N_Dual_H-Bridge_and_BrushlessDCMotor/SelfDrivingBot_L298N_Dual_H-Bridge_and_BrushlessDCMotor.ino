int motorIN1 = 8;               //defines the motor pins
int motorIN2 = 9;
int motorIN3 = 10;
int motorIN4 = 11;

void forwardDrive()             //functions to define each direction for the motor
{
  digitalWrite(motorIN1, HIGH); //both motors will turn on (forward)
  digitalWrite(motorIN2, LOW);
  digitalWrite(motorIN3, HIGH);
  digitalWrite(motorIN4, LOW);  
}

void reverseDrive()

{
  digitalWrite(motorIN1, LOW);  //both motors will turn on (reverse)
  digitalWrite(motorIN2, HIGH);
  digitalWrite(motorIN3, LOW);
  digitalWrite(motorIN4, HIGH);
}

void tiltLeft()
{
  digitalWrite(motorIN1, HIGH);   //only 1 motor will move forward (left)
  digitalWrite(motorIN2, LOW);
  digitalWrite(motorIN3, LOW);
  digitalWrite(motorIN4, LOW);
}

void tiltRight()
{
  digitalWrite(motorIN1, LOW);    //only 1 motor will move forward (right)
  digitalWrite(motorIN2, LOW);
  digitalWrite(motorIN3, HIGH);
  digitalWrite(motorIN4, LOW);
}

void stopDriving()
{
  digitalWrite(motorIN1, LOW);
  digitalWrite(motorIN2, LOW);
  digitalWrite(motorIN3, LOW);
  digitalWrite(motorIN4, LOW);
}


void setup() {                //pin directions
  Serial.begin(9600);
  pinMode(motorIN1, OUTPUT);
  pinMode(motorIN2, OUTPUT);
  pinMode(motorIN3, OUTPUT);
  pinMode(motorIN4, OUTPUT);

}

void loop()
{
  forwardDrive();
  delay(10000);
  reverseDrive();
  delay(5000);
  tiltLeft();
  delay(5000);
  tiltRight();
  delay(5000);

}
