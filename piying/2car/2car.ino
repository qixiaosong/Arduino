#include <Servo.h>
Servo myservo;
int pos = 0;
int sp1 = 120;    //前进速度值 -->
int sp2 = 100;     //后退速度值 <--

void setup() {
  // put your setup code here, to run once:
  //2号车
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  myservo.write(pos);
  delay(2000);
  myservo.attach(11);
  //pinMode(6, INPUT_PULLUP);
  //while(analogRead(A1)>500);
}

void leftwheel(int dir,int mspd){
  if(mspd>=255) mspd=255;
  if(mspd<=0) mspd=0;
  if(mspd){//如果mspd不为0，直接写速度，否则 控制两个控制线 刹车
     if(dir==1){
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
    }
    else{
      digitalWrite(8,HIGH);
      digitalWrite(7,LOW);
    }
    analogWrite(6,mspd);  
  }
  else{
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
  }
}

void rightwheel(int dir,int mspd){
  if(mspd>=255) mspd=255;
  if(mspd<=0) mspd=0;
  if(mspd){//如果mspd不为0，直接写速度，否则 控制两个控制线 刹车
     if(dir==1){
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
    }
    else{
      digitalWrite(4,HIGH);
      digitalWrite(2,LOW);
    }
    analogWrite(3,mspd);  
  }
  else{
    digitalWrite(2,HIGH);
    digitalWrite(4,HIGH);
  }
}

void stop(){ 
  leftwheel(0,0);
  rightwheel(0,0);
}

void goahead(){
  //前进
  rightwheel(1,200);
  leftwheel(1,200);
  delay(150);
  rightwheel(1,sp1);    //105sp
  leftwheel(1,sp1);     
}

void goback(){
  //后退
  leftwheel(0,200);
  rightwheel(0,200);
  delay(150);
  leftwheel(0,sp2);   //95sp
  rightwheel(0,sp2);
}

void lift(){
    //myservo.attach(11);
    for (pos = 0; pos <= 90; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                       
  }
    //myservo.detach();
}

void drop(){
    //myservo.attach(11);
    for (pos = 90; pos >= 0; pos -= 1) { 
      myservo.write(pos);              
      delay(15);                       
    }  
    //myservo.detach();
}
void loop() {
  // put your main code here, to run repeatedly:
 
  stop();
  delay(22000);   //24
  
  goahead();                                        //前进
  delay(2000);    //25
  
  stop();  
  delay(1000);    //28

  lift();
  delay(1000);    //30
  
  goback();
  while(analogRead(A0)>300);
  stop();
  delay(11000);    //41
  
  drop();       
  //delay(2000);    //43

  goahead();                                        //前进
  delay(2000);    //44

  stop();
  delay(3000);   //47

  goback();
  while(analogRead(A0)>300);    

  stop();
  delay(18000);   //65

  goahead();                                        //前进
  delay(2000);    //66

  stop();
  delay(10000);
  while(1);
}
