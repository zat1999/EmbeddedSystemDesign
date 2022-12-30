
class LED
{
  public:
    unsigned int delayTime;     //how long the LED remains off(milliseconds)
    unsigned int blinkDuration; //how long the LED remains on (milliseconds)
    int ledPin;                 //pin number the LED is connected to
    unsigned int offset = 0;    //used to calculate when the next time to turn on/off the LED
    int state = 0;        //if the LED is ON or OFF at that time.

    //Constructor to assign the respected values to the class
    LED(int pin, int t, int d)  
    {
      ledPin = pin;
      delayTime = t;
      blinkDuration = d;
      pinMode(ledPin, OUTPUT);  //assigns pinMode to output
    }   
};

//Creating each instances of LED (pin number, delay time, and blink duration are the arguments in milliseconds)
LED led1(7, 100, 700);
LED led2(6, 3000, 4000);
LED led3(5, 2500, 6000);

LED led[3] = {led1, led2, led3}; //Creates LED List

void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(led[i].ledPin, led[i].state); //Initially turns off all LEDs
  }
}

void loop()
{
  unsigned int currentTime = millis();  //gets the system time
  for(int i = 0; i < 3; i++)  //loops for each LED
  {
    //execute code below if difference between system time and offset of that LED is greater than delayTime.
    //needed to prevent interger overflow 
    if(currentTime - led[i].offset > led[i].delayTime && !led[i].state)  
    {
      digitalWrite(led[i].ledPin, HIGH);  //turns on LED
      led[i].offset += led[i].delayTime;  //adds to the offset 
      led[i].state = 1;                   //so the program knows what state the LED is on.
    }
    else if(currentTime - led[i].offset > led[i].blinkDuration && led[i].state)  //same as above but for blink
    {
      digitalWrite(led[i].ledPin, LOW);
      led[i].offset += led[i].blinkDuration;
      led[i].state = 0;
    }
  }
}
