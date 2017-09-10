#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);

int flex0 = A0;
int flex1 = A1;
int flex2 = A2;
int flex3 = A3;
int flex4 = A4; 

// 플렉시블 센서핀

int Value0;
int Value1;
int Value2;
int Value3;
int Value4;

//센서 angle 값

int read0;
int read1;
int read2;
int read3;
int read4;

//플렉스센서 리딩값

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BTSerial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
     read0 = analogRead(flex0);
         delayMicroseconds(5);
     read1 = analogRead(flex1);
         delayMicroseconds(5);
     read2 = analogRead(flex2);
         delayMicroseconds(5);
     read3 = analogRead(flex3);
         delayMicroseconds(5);
     read4 = analogRead(flex4);
         delayMicroseconds(5);
     
     
     Value0 = map(read0,700,820,0,180);
     if(Value0>180) Value0 = 180;
     if(Value0<0) Value0 = 0;
     Value1 = map(read1,610,810,0,180);
     if(Value1>180) Value1 = 180;
     if(Value1<0) Value1 = 0;
     Value2 = map(read2,640,840,0,180);
     if(Value2>180) Value2 = 180;
     if(Value2<0) Value2 = 0;
     Value3 = map(read3,650,840,0,180);
     if(Value3>180) Value3 = 180;
     if(Value3<0) Value3 = 0;
     Value4 = map(read4,730,860,0,180);
     if(Value4>180) Value4 = 180;
     if(Value4<0) Value4 = 0;

     Serial.print("original_val = ");
     Serial.print(read0);
     Serial.print("########");
     Serial.print("mapping_val = ");
     Serial.println(Value0);
     


    //맵핑 
   
    BTSerial.write('A');
    delayMicroseconds(5);
    BTSerial.write(Value0);
    delayMicroseconds(5);

    BTSerial.write('B');
    delayMicroseconds(5);
    BTSerial.write(Value1);
    delayMicroseconds(5);
    
    BTSerial.write('C');
    delayMicroseconds(5);
    BTSerial.write(Value2);
    delayMicroseconds(5);
    
    BTSerial.write('D');
    delayMicroseconds(5);
    BTSerial.write(Value3);
    delayMicroseconds(5);
    
    BTSerial.write('E');
    delayMicroseconds(5);
    BTSerial.write(Value4);
    delayMicroseconds(5);



}

/*
     //Serial.println(Value3);
     Value0 = map(read0,240,440,0,180);
     if(Value0>180) Value0 = 180;
     if(Value0<0) Value0 = 0;
     Value1 = map(read1,160,350 ,0,180);
     if(Value1>180) Value1 = 180;
     if(Value1<0) Value1 = 0;
     Value2 = map(read2,290,500,0,180);
     if(Value2>180) Value2 = 180;
     if(Value2<0) Value2 = 0;
     Value3 = map(read3,345,550,0,180);
     if(Value3>180) Value3 = 180;
     if(Value3<0) Value3 = 0;
     Value4 = map(read4,360,570,0,180);
     if(Value4>180) Value4 = 180;
     if(Value4<0) Value4 = 0;
  */   
