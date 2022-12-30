int signal;

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2),buttonPressed1,RISING);  //  attaches the interrupt and detects for rising signal
  attachInterrupt(digitalPinToInterrupt(3),buttonPressed2,RISING);  //  for the 2nd function   
}

void loop() {
  Serial.begin(9600);
  delay(500);
  digitalWrite(12, signal);   //will turn on/off the LED regardless of the delay timer
}


void buttonPressed1()           //ISR method is called when button is pressed
{                    
   signal = LOW;                //Change Output value to LOW                                
   Serial.println("Interrupt1");
}

void buttonPressed2()           //for button2
{                    
   signal = HIGH;                //Change Output value to HIGH                                
   Serial.println("Interrupt2");
}
