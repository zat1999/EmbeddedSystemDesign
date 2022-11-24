int ldr_pin = A0;
int lights_pin = 8;
int ldrVal = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lights_pin, OUTPUT);
  pinMode(ldr_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ldrVal = analogRead(ldr_pin);
  if(ldrVal <= 40)
  {
    digitalWrite(lights_pin, HIGH);
  }
  else
    {
      digitalWrite(lights_pin, LOW);
    }
}
