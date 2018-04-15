int sp1 = 90;
int sp2 = 90;
void setup() {
  // put your setup code here, to run once:
  //三号车
    pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  delay(2000);
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
  leftwheel(0,200);
  rightwheel(0,200);
  delay(50);
  leftwheel(0,sp2);
  rightwheel(0,sp2);
}

void goback(){
  //后退
  rightwheel(1,150);
  leftwheel(1,150);
  delay(50);
  rightwheel(1,sp1);
  leftwheel(1,sp1);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(60000);
  delay(11000);               //1'13"开始
  goahead();                  //前进
  delay(4000);    
  stop();
  delay(2000);  
  
  goback();
  delay(400);    
  stop();
  delay(1000);
  
  goahead();                  //前进
  delay(400);
  stop();
  delay(1000);
  goback();
  delay(400); 
  stop();
  delay(1000);
  
  goahead();                  //前进
  delay(400);
  stop();
  delay(1000);

  while(1);
}
