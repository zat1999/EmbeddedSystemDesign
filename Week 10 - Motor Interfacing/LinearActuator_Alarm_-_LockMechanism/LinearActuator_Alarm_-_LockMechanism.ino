
//Buttons
const int button1_pin = 9;   //Press to Retract
const int button2_pin = 8;   //Press to Extends

//Motor Driver Pins
const int DIR_pin1 = 7; //pin, that determines the direction(via polarity)
const int EN_pin1 = 6;  //speed via pwm
const int actuatorSpeed = 255; //speed

const int relay_pin = 10; //relay pin for the siren
void setup()
{
Serial.begin(9600);

pinMode(button1_pin, INPUT);
pinMode(button2_pin, INPUT);   

pinMode(relay_pin, OUTPUT);

pinMode(DIR_pin1, OUTPUT);
pinMode(EN_pin1, OUTPUT);
}

void loop()
{  
  if(digitalRead(button1_pin) == HIGH) //if retract button pressed, set direction and set speed
  {
    digitalWrite(DIR_pin1, HIGH);         //sets directions
    analogWrite(EN_pin1, actuatorSpeed);  //moves actuator with that speed
    //Serial.println("Retracting");
  }
    else if(digitalRead(button2_pin) == HIGH) //same as above but for extending
  {
    digitalWrite(DIR_pin1, LOW);
    analogWrite(EN_pin1, actuatorSpeed);
    //Serial.println("Extending");
    digitalWrite(relay_pin, HIGH);
  }
  else if(digitalRead(button2_pin) == LOW && digitalRead(button1_pin) == LOW )
  {
    digitalWrite(relay_pin, LOW); //turn off relay for siren
    analogWrite(EN_pin1, 0);      //set speed to zero if no button is pressed
  }
 
}
