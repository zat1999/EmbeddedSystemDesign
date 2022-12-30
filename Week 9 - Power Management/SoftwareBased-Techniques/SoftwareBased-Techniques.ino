
int buildinLED = 13;
int interval = 10;
int i = 0;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);     //Only 1 used pin

  //sets all unused GPIO pins to OUTPUT
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);

  //sets all unused analog comparators pins to OUTPUT/OFF.
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);




  
}

// the loop function runs over and over again forever
void loop() {


  while(i <= interval)
  {
    digitalWrite(buildinLED, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(2000);                       // wait for a second
    digitalWrite(buildinLED, LOW);    // turn the LED off by making the voltage LOW
    delay(2000);                       // wait for a second
    i++;
  }
  delay(10000); //set to sleep
  i = 0;
  
}
