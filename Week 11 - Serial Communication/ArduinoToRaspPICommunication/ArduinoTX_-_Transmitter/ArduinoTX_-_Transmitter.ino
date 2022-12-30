const int potentiometer_pin = A0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potentiometer_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead(potentiometer_pin); //reads potentiometer value
  //maps the values so the poteotiometer value correlates with the LED pin
  potVal = map(potVal, 0 ,1023,0, 255); 
  Serial.println(potVal); //writes to the serial where the raspberry pi reads it
  
}
