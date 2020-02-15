#define Pot A0			//电位器引脚命名
#define WUYUAN 2
int PotBuffer = 0;		//AD读取数据缓存变量


void setup(){
  pinMode(WUYUAN,OUTPUT);
  v
}

void loop(){
  PotBuffer = analogRead(Pot);
  
  for(int i = 0; i < 50;i++){
    digitalWrite(WUYUAN,HIGH);
    delayMicroseconds(PotBuffer);
    digitalWrite(WUYUAN,LOW);
    delayMicroseconds(PotBuffer);
  }
}
