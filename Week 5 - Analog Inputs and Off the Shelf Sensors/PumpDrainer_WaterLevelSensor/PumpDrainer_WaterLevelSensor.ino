
int waterLevelSensor = A0;
int relayPin = 8;
int threshold = 300;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT); //pin data directions
  pinMode(waterLevelSensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int val = analogRead(waterLevelSensor); //reads the values
  Serial.println(val);
  
  
  if(val <= threshold)
  {
    digitalWrite(relayPin, HIGH);   //Turns on the pump  
  }
  else
  {
    digitalWrite(relayPin, LOW);    //Turns off the pump
  }
  

  delay(2000); //to prevent burning out the motor pump if there is fluctuating values 
  
}
