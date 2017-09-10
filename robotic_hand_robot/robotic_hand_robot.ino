#include <Servo.h>

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);

Servo one;
Servo two;
Servo three;
Servo four;
Servo five;

//서보 모터
int LeftMotor = 7;
int LeftMotor_pwm = 6;
int RightMotor = 4;
int RightMotor_pwm = 5;


int Value0;
int Value1;
int Value2;
int Value3;
int Value4;

//저항 값

int read0;
int read1;
int read2;
int read3;
int read4;

void setup() {
  // put your setup code here, to run once:
  BTSerial.begin(115200);
  Serial.begin(115200);

  pinMode(LeftMotor, OUTPUT);
  pinMode(LeftMotor_pwm, OUTPUT);
  pinMode(RightMotor, OUTPUT);
  pinMode(RightMotor_pwm, OUTPUT);

  digitalWrite(LeftMotor, LOW);
  analogWrite(LeftMotor_pwm, 255);
  digitalWrite(RightMotor, LOW);
  analogWrite(RightMotor_pwm, value);
  
  one.attach(13);
  two.attach(12);
  three.attach(9);
  four.attach(10);
  five.attach(8);



}

void loop() {
  // put your main code here, to run repeatedly:

  if (BTSerial.available()) {
    
    char a = BTSerial.read();
    if (a == 'A') {
      while (!BTSerial.available());
      Value0 = BTSerial.read();
      one.write(Value0);
      Serial.println(Value0);
    }
    else if (a == 'B') {
      while (!BTSerial.available());
      Value1 = BTSerial.read();
      two.write(Value1);
    }
    else if (a == 'C') {
      while (!BTSerial.available());
      Value2 = BTSerial.read();
      three.write(Value2);
      Serial.println(Value1);
    }
    else if (a == 'D') {
      while (!BTSerial.available());
      Value3 = BTSerial.read();
      four.write(Value3);
      }
    else if (a == 'E') {
      while (!BTSerial.available());
      Value4 = BTSerial.read();
      five.write(Value4);
      }



  }

}

