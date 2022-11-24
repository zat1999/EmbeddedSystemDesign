int potentiometer = A0;
int led = 5;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(potentiometer, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(potentiometer);
  int brightness = map(val, 0, 1023, 0 , 255);
  analogWrite(led, brightness);
}
