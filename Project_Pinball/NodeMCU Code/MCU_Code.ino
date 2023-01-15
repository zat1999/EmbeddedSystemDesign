//Libraries for nodeMCU
#if defined(ESP32)
#include <WiFi.h>
#include <FirebaseESP32.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
//#include <SoftwareSerial.h>
#endif

// Provide the token generation process info.
#include <addons/TokenHelper.h>

// Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

//
#include "configMCU.h"
#include <Wire.h>

char rdata;
String myString;
float timerVal;

void i2cLoop();
String getVal(String data, char separator, int index);

void setup()
{
  Serial.begin(9600);
  Wire.begin(D1, D2);
  //For Wifi Connection
  wifiSetup();
}

void loop()
{
  pushPH_Firebase();
}

//Responsbile for getting the value for the Arduinos
void i2cLoop()
{
  if(Serial.available() == 0)  
  {
    rdata = Serial.read();
    myString = myString + rdata;
    
    if(rdata == '\n'){
      String a = getValue(myString, ',', 0);

      timerVal = a.toFloat(); 

      myString = "";
    }
  }
}

//Responsbile for getting the value for the Arduinos
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() -1;

  for(int i=0; i <= maxIndex && found <= index; i++){
    if(data.charAt(i) == separator || i == maxIndex){
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i+1 :i;      
      }      
  } 
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

//Writes to Firebase
void pushPH_Firebase()
{
  i2cLoop();
  float t_val = timerVal;
  infra = infra + 1;

  Firebase.setFloat(fbdo, "/bestTime", t_val);
}
