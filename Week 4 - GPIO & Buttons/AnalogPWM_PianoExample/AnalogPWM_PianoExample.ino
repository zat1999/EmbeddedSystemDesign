int button1 = 11;
int button2 = 10;
int button3 = 9;
int button4 = 8;

int buzzer = 6;
int val = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button1))
  {
    analogWrite(buzzer, 40);
  }
  
  else if(digitalRead(button2))
  {
    analogWrite(buzzer, 80);
  }

  else if(digitalRead(button3))
  {
    analogWrite(buzzer, 180);
  }

  else if(digitalRead(button4))
  {
    analogWrite(buzzer, 250);
  }
  else 
  {
    analogWrite(buzzer, 0);
  }
  
}
