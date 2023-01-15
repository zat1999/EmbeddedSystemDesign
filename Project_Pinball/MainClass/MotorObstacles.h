

class MotorObstacles
{
  private:
    int IN_1;
    int IN_2;
    int EN_1;
    int motorSpeed;
    
  public:
    void ChangeMotorSpeed(int);
    void EnableMotor();
    void DisableMotor();  
	  MotorObstacles(int, int, int, int);	

};

MotorObstacles::MotorObstacles(int inputPin_1, int inputPin_2, int enablePin, int pwm)
{
  IN_1 = inputPin_1;
  IN_2 = inputPin_2;
  EN_1 = enablePin;
  motorSpeed = pwm;
  
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(EN_1, OUTPUT);

  //Default Start-up Program is Set to Low to Conserve Battery
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  //Disable Analog Port Code
  analogWrite(EN_1, 0);
};

void MotorObstacles::EnableMotor()
{
  //analogWrite(EN_1, motorSpeed);
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
};

void MotorObstacles::DisableMotor()
{
  analogWrite(EN_1, 0);
  //Disable Analog Port Code
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
};

void MotorObstacles::ChangeMotorSpeed(int newSpeed)
{
  motorSpeed = newSpeed;
};
