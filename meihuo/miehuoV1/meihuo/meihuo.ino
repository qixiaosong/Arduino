String comdata = "";  
String compass="";
int comnum=0;
char terminator = ',';  

void motor_run(int motorId,int dir,int speed) {
  if(motorId==1){
  digitalWrite(12,dir);
  analogWrite(11,speed);
  }
  else{
  digitalWrite(8,dir);
  analogWrite(10,speed);
  }
}

void setup() {  
    pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  
  Serial.begin(57600);  
  while(Serial.read()>= 0){} //clear serialbuffer  
}  


   
void loop() {  
  // read data from serial port  
  if(Serial.available()>0){  
      delay(50);  
      comdata =Serial.readStringUntil(terminator);  
     //Serial.print("Serial.readStringUntil: ");
     int IndexofA = comdata.indexOf("=");  
     compass=comdata.substring(IndexofA+1);
      //Serial.println(compass);  
      comnum=compass.toInt();
      Serial.println(comnum);  
    }  
    while(Serial.read()>= 0){} 
//    
//     motor_run(0, 1,250);
//     motor_run(1, 1,250);
//     delay(3000);
//     motor_run(0, 0,250);
//     motor_run(1, 0,250);
//     delay(3000);
     
}  
