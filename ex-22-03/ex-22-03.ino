#include <Servo.h> //引入lib
Servo myservo;  // 创建一个伺服电机对象
#define potpin  A5  // 设定连接可变电阻的模拟引脚
int val;    // 创建变量，储存从模拟端口读取的值（0到1023）
void setup()
{
  myservo.attach(9);  // 9号引脚输出电机控制信号
                     //仅能使用PWM引脚
 myservo.write(89);
}
void loop()
{
int delay_s = 1000;
// myservo.write(89);
//  delay(delay_s);
//  myservo.write(0);
//  delay(delay_s);
//  myservo.write(89);
//  delay(delay_s);
//  myservo.write(179);
//  delay(delay_s);
// return ;
  //val = analogRead(potpin);
 // 读取来自可变电阻的模拟值（0到1023之间） 
  //val = map(val, 0, 1023, 0, 179);     // 利用“map”函数缩放该值，得到伺服电机需要的角度（0到180之间） 
  //for(int i = 0;i < 179;i++){
     //myservo.write(i);     // 设定伺服电机的位置
     //delay(2000);             // 等待电机旋转到目标角度
  //}
  int servo_pos = 89;
  int middle_servo_pos = 89;
  int max_servo_pos = 179;
  int min_servo_pos = 1;
  //转向左边
  for(servo_pos = 89;servo_pos <= max_servo_pos;servo_pos++)
  {
    myservo.write(servo_pos);
    delay(15);
  }
  //停留
  for(int i=0;i<3;i++)
  {
    myservo.write(max_servo_pos);
    delay(300);
  }

  //回到正面动作
  for(servo_pos = max_servo_pos;servo_pos >= 89;servo_pos--)
  {
    myservo.write(servo_pos);
    delay(15);
  }

  //暂时停留
  for(int i = 0;i < 3;i++)
  {
    myservo.write(89);
    delay(300);
  }

  //转向右边
  for(servo_pos = 89;servo_pos >= min_servo_pos;servo_pos--)
  {
    myservo.write(servo_pos);
    delay(15);
  }
  //暂时停留
  for(int i = 0;i < 3;i++)
  {
    myservo.write(1);
    delay(300);
  }

  //右边回到正面
  for(servo_pos = min_servo_pos;servo_pos <= 89;servo_pos++)
  {
    myservo.write(servo_pos);
    delay(15);
  }

  //暂时停留
  for(int i = 0;i < 3;i++)
  {
    myservo.write(89);
    delay(300);
  }

  // delay(1000);
 


//  myservo.write(89);
//  delay(delay_s);
//  myservo.write(0);
//  delay(delay_s);
//  myservo.write(89);
//  delay(delay_s);
//  myservo.write(179);
//  delay(delay_s);
}
