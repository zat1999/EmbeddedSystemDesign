#include <ESP8266WiFi.h>
//#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

const char* ssid     = "Nahkoda Jaring";                          //wifi name and passwords
const char* password =  "6365am94969905nias";

#define FIREBASE_HOST "lights-d6923-default-rtdb.firebaseio.com"  //token for the database server
#define FIREBASE_AUTH "6iN56za2N5xy83mSp9I7BoDkmgzR6AsILM9jitvw"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                                             
  WiFi.begin(ssid, password);                                    //attempts to connect to WIFI

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
      Serial.println(".");
      delay(500);
  }
  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());                               //Successful Wifi Connect and Prints IP  
pinMode(2, OUTPUT);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int value;

void FirebaseReconnect()                                        //Connects to a Firebase Server (Online Database)
{
    Serial.println("connecting...connecting");
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // put your main code here, to run repeatedly: 
 if(Firebase.failed())                                          //If Fails to connect to database will try to connect again
  {

    Serial.println("failure");
    Serial.println(Firebase.error());
    FirebaseReconnect();
    //return;
  }

value = Firebase.getInt("LAMPS/light1");                           //Will get the values store for Lamps
Serial.println(value);
if(value == 0)
{
  digitalWrite(2, LOW);
}else{
  digitalWrite(2,HIGH);
}
     
}
