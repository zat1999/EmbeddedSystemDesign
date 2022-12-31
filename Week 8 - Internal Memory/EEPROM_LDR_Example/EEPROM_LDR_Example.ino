
//EEPROM header library
#include <EEPROM.h>

int LDR_pin = A0;
int address = 0;
int ldrVal = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ldrVal = analogRead(LDR_pin) / 4; //as EEPROM bytes can hold a value from 0-255 only. the input range is 0-1023 therefore it is divide by 4

  EEPROM.update(address, ldrVal); //will update the EEPROM
 
  address = address + 1;
  if (address == EEPROM.length()) {
    address = 0;
  } 
  delay(100);
}


  
