#include <Servo.h> //引入lib
Servo myservo;  // 创建一个伺服电机对象
#define potpin  A5  // 设定连接可变电阻的模拟引脚
int val;    // 创建变量，储存从模拟端口读取的值（0到1023）
void setup()
{
  myservo.attach(9);  // 9号引脚输出电机控制信号
                     //仅能使用PWM引脚
}
void loop()
{
  val = analogRead(potpin);
 // 读取来自可变电阻的模拟值（0到1023之间） 
  val = map(val, 0, 1023, 0, 179);     // 利用“map”函数缩放该值，得到伺服电机需要的角度（0到180之间） 
  myservo.write(val);     // 设定伺服电机的位置
  delay(15);             // 等待电机旋转到目标角度
}
