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
  rightwheel(1,200);
  leftwheel(1,200);
  delay(50);
  rightwheel(1,110);
  leftwheel(1,110);
}

void goback(){
  //后退
  leftwheel(0,150);
  rightwheel(0,150);
  delay(50);
  leftwheel(0,120);
  rightwheel(0,120);
}

void loop() {
  // put your main code here, to run repeatedly:
  goahead();
  delay(2000);    //4
  
  stop();
  delay(18000);   //22
  
  goback();
  delay(2000);    //24
  
  stop();  
  delay(6000);    //30
  
  goahead();
  delay(2000);    //32
  
  stop();
  delay(8000);    //40
  
  goback();       
  delay(2000);    //42

  stop();
  delay(8000);    //49   之前为6s

  goahead();
  delay(2000);    //51

  stop();
  delay(10000);   //61

  goback();
  delay(2000);    //63

  stop();
  delay(2000);
  while(1);
}
