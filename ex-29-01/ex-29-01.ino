int LIGHT_PIN = 2;  //设置继电器的控制数字引脚
//LED 正极分开，分开的线接继电器 COM -> 电源正极和继电器NC -> LED正极
//@link https://blog.csdn.net/kindlymouse/article/details/7525096
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //蓝牙的波特率，默认一般是9600根据自己的蓝牙设备设置而定
  pinMode(LIGHT_PIN,OUTPUT);
  digitalWrite(LIGHT_PIN,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  char inChar = (char)Serial.read();         //从串口监视器上读取数据
  Serial.println(inChar);
  if(inChar == 'A'){              //如果为字符1，闭合继电器，灯亮
    digitalWrite(LIGHT_PIN,HIGH);
    Serial.println("Led ON");
  }else if(inChar == 'B'){        //如果为字符0，断开继电器，灯灭
    digitalWrite(LIGHT_PIN,LOW);
    Serial.println("Led OFF");
  }
  delay(2000);                       //做一个保护，避免点击过快，损坏灯
}
