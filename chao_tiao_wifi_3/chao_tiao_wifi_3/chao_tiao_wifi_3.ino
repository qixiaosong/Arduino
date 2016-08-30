//2016年8月29号第三次调试

#include <SoftwareSerial.h>
String comdata = "";
SoftwareSerial WIFISerial(8, 9);     // RX, TX
const int TrigPin = 2;                // 设定SR04连接的Arduino引脚
const int EchoPin = 3; 
const int key = 4;
int a = 250;                          //a是光照参考值
float distance, max_t = -20.00; 

void wifi_data(){
      
  while (Serial.available() > 0)  
    {
        comdata += char(Serial.read());
        delay(20);
    }
  if (comdata.length() > 0)
    {
        Serial.println(comdata);
        WIFISerial.println("AT+CIPSEND=0,11"); 
        delay(1000);
        WIFISerial.println(comdata);
        delay(1000);
        comdata = "";
    }  

}
void setup() 
{   // 初始化串口通信及连接SR04的引脚
        Serial.begin(9600);
        pinMode(TrigPin, OUTPUT); 
        pinMode(key,INPUT);
    // 要检测引脚上输入的脉冲宽度，需要先设置为输入状态
        pinMode(EchoPin, INPUT); 
        Serial.println("Ready to receive data：");
    //  以下部分为wifi的配置    
        WIFISerial.begin(9600);
        delay(2000);
        WIFISerial.println("AT+CIPMUX=1");
        delay(2000);
        WIFISerial.println("AT+CIPSTART=0,\"TCP\",\"192.168.1.202\",8080");
        delay(2000);
        WIFISerial.println("AT+CIPSEND=0,11"); 
        delay(2000);
        WIFISerial.println("00000000000");
        delay(3000);                
}
void distance_max()
{
      // 产生一个10us的高脉冲去触发TrigPin 
        digitalWrite(TrigPin, LOW); 
        delayMicroseconds(2); 
        digitalWrite(TrigPin, HIGH); 
        delayMicroseconds(10);
        digitalWrite(TrigPin, LOW); 
    // 检测脉冲宽度，并计算出距离
        distance = 50-(pulseIn(EchoPin, HIGH) / 58.00);
        if(distance>max_t)
        {
          delay(50);
          if(distance>max_t)
          max_t = distance; 
        }   
}
void loop() 
{
 if (WIFISerial.available()){           //软串口
  Serial.write(WIFISerial.read());     //写入软串口读取的数据 ————>  串口
  }
 wifi_data();                           //发送学号信息
 if(analogRead(A0) >= a ) {          
    delay(10); 
    if(analogRead(A0) >= a ){             
    distance_max();                                         
      if(digitalRead(key) == HIGH){
      delay(10);
        if(digitalRead(key) == HIGH){
        delay(10);
        while(digitalRead(key) == HIGH);
//        Serial.print(max_t);
//        Serial.print("cm"); 
//        Serial.println();
        WIFISerial.println("AT+CIPSEND=0,10"); 
        delay(500);
        WIFISerial.println(max_t);
        delay(500); 
        max_t = -20;                
        }
      }
   } 
 }      
delay(100); 
}
