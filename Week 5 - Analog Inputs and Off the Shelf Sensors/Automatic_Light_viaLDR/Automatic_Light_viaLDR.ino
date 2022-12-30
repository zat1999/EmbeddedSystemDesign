

int lamp = 7;               //Pins Numbers
int LDR = A0;
int resisThreshold = 700;  
//Light affects the resistance values, hence the value here indicates when to make the trigger lamp

void setup()
{
  Serial.begin(9600);
  pinMode(lamp, OUTPUT); //pin data directions
  pinMode(LDR, INPUT);
}

void loop()
{
  int ldrVal = analogRead(LDR); //reads the values
  Serial.println(ldrVal);
  
  
  if(ldrVal <= resisThreshold)
  {
    digitalWrite(lamp, HIGH);   //Turns on the Lamps, as LDR receives no light so resistance is high
  }
  else
  {
    digitalWrite(lamp, LOW);    //Turns off the lamp
  }
  
  
}
