 
//pin definitions
int ledPin = 8;
int buttonPin = 7;
 
//boolean for toggle state when there is a interrupt or change
bool togglestate = false;
 
void setup() {
 
  //sets data direction to output
  pinMode(ledPin, OUTPUT);
 
  //set switch as input with pullup
  pinMode(buttonPin, INPUT_PULLUP);
 
 
  //enables PCIE2 Bit3 = 1, port D
  PCICR |= B00000100;
  // Select PCINT23 Bit7 = 1, pin d7
  PCMSK2 |= B10000000;
 
}
 
void loop() {
  //
}
 
ISR (PCINT2_vect)
{
  // Interrupt for Port D
  // Invert toggle state
  togglestate = !togglestate;
  // Indicate state on LED
  digitalWrite(ledPin, togglestate);
 
 
}
