
#include <Servo.h>
//Servo playerServo;


class Player
{
  private:
      int joy_X_pin;
      int joy_Y_pin;
      int servoPin;
      
      
   public:
      Player(int,int,int);
      Servo playerServo;
      //Getters + Setters
      int GetJoyStickAxis();
      int SetServo(int);//Player, int);
	    //Servo playerServo;
      void GetPin(){Serial.println(servoPin);};
	    void InstantiateServo(int);
      
};

Player::Player(int xdir, int ydir, int servo)
{
  
  //Setters
  joy_X_pin = xdir;
  joy_Y_pin = ydir;
  servoPin = servo;
  //Sets Data Direction
  pinMode(joy_X_pin, OUTPUT);
  pinMode(joy_Y_pin, OUTPUT);
  pinMode(servoPin, OUTPUT);
  //Serial.println(servo);
  //playerServo.attach(servo);
  //playerServo.write(84);

};

int Player::GetJoyStickAxis()
{
  int rawAxis = analogRead(joy_X_pin); //reads the raw analog data
  //Serial.println("Raw:");
  //Serial.println(rawAxis);
  int convertedAxis = map(rawAxis, 0, 1024, 0, 255); //converts it to a pwm range
  //Serial.println("Mapped:");
  //Serial.println(convertedAxis);
  return convertedAxis; //returns it from the function
};

int Player::SetServo(int settingAngle)//int settingAngle)
{

    //Gets the PWM signal to and compares it with set values to know which direction to spin the servo.
    
    if(settingAngle > 130)
   {
     return 360; //clockwise rotation
   }
  else if (settingAngle < 124)
   {
     return 0; //anticlockwise rotation
   }
  else {
    return 87; //stationary. Should be 90 however, it is offset due to the inbuilt potentiometers.
 }
 
};
