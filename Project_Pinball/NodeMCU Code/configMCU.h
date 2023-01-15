/*
  Config.h - MCU pin assignments + Constants + Firebase definition
  Master = Slave connection
  D1 = SDA(A4)
  D2 = SCL(A5)
  gnd = gnd
*/
//Libraries for nodeMCU
#if defined(ESP32)
#include <WiFi.h>
#include <FirebaseESP32.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#endif

// Provide the token generation process info.
#include <addons/TokenHelper.h>

// Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

//Define Firebase
#define WIFI_SSID "WIFI_NETWORK"
#define WIFI_PASSWORD "PASSWORD"
#define API_KEY "YQWzrMPJ1dktvqDExlx7UZSnohiSUqXFqhgeHDBj"
#define DATABASE_URL "https://pointsystem-c127d-default-rtdb.asia-southeast1.firebasedatabase.app/"


// Define Firebase Data object
FirebaseData fbdo;
FirebaseData stream;
FirebaseAuth auth;
FirebaseConfig config;

void wifiSetup()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to wi-fi");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  
  /* Assign the api key (required) */
  config.api_key = API_KEY;
  
  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  
  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}
