#include <Servo.h> //引入lib
Servo myservo;  // 创建一个伺服电机对象

//命令
#define CAR_STOP  0
#define CAR_FORWARD   1
#define CAR_BACKWARD  2
#define CAR_TURNLEFT  3
#define CAR_TURNRIGHT 4

//超声波模块
#define TrigPin 2
#define EchoPin 3

int middle_servo_pos = 89;
int max_servo_pos = 179;
int min_servo_pos = 1;

//小车电机
int motor_speed = 100;
int high_speed = 150;
#define L298N_1 4
#define L298N_2 5 //M1 PWN
#define L298N_3 6 //M2 PWN
#define L298N_4 7


void setup()
{
  Serial.begin(9600);
  myservo.attach(9);  // 9号引脚输出电机控制信号,仅能使用PWM引脚
  
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);

  //电机
  pinMode(L298N_1,OUTPUT);
  pinMode(L298N_2,OUTPUT);
  pinMode(L298N_3,OUTPUT);
  pinMode(L298N_4,OUTPUT);
}
void loop()
{
  avoid();
  // car_move(CAR_FORWARD);
  // delay(2000);
  // car_move(CAR_BACKWARD);
  // delay(2000);
  // car_move(CAR_TURNLEFT);
  // delay(2000);
  // car_move(CAR_TURNRIGHT);
  // delay(2000);
  // car_move(CAR_STOP);
  // delay(2000);
}

void car_move(int motor_command)
{
  Serial.print("car command");
  Serial.println(motor_command);
  switch(motor_command)
  {
    case CAR_FORWARD:
      analogWrite(L298N_1, high_speed);
      analogWrite(L298N_2, motor_speed);

      analogWrite(L298N_3, motor_speed);
      analogWrite(L298N_4, high_speed);
    break;
    case CAR_BACKWARD:
      analogWrite(L298N_1, motor_speed);
      analogWrite(L298N_2, high_speed);

      analogWrite(L298N_3, high_speed);
      analogWrite(L298N_4, motor_speed);
    break;
    case CAR_TURNLEFT:
      analogWrite(L298N_1, high_speed);
      analogWrite(L298N_2, motor_speed);
      analogWrite(L298N_3, 0);
      analogWrite(L298N_4, 0);
    break;
    case CAR_TURNRIGHT:
      analogWrite(L298N_1, 0);
      analogWrite(L298N_2, 0);
      analogWrite(L298N_3, motor_speed);
      analogWrite(L298N_4, high_speed);
    break;
    case CAR_STOP:
      analogWrite(L298N_1, 0);
      analogWrite(L298N_2, 0);
      analogWrite(L298N_3, 0);
      analogWrite(L298N_4, 0);
    break;
    default:
      analogWrite(L298N_1, 0);
      analogWrite(L298N_2, 0);
      analogWrite(L298N_3, 0);
      analogWrite(L298N_4, 0);
    break;
  }
}

void avoid()
{
  int dis[3] = {0};
  int servo_pos = 90;
  car_move(CAR_FORWARD);
  dis[1] = get_distance();//前方距障碍距离
  if(dis[1] < 30)
  {
    car_move(CAR_STOP);
    //获取左边障碍距离
    dis[0] = get_left_distance();

    //再次获取正面的障碍距离
    dis[1] = get_left_back_front_distance();

    // 获取右边边障碍距离
    dis[2] = get_right_distance();

    // 右边转回正面
    right_back_front();

    //当正面距离小于5cm时，后退一点
    if(dis[1] <= 5)
    {
      car_move(CAR_BACKWARD);
      delay(500);
      car_move(CAR_STOP);
    }
    else if(dis[0] >= dis[2])
    {
      car_move(CAR_TURNLEFT);
    }
    else if(dis[0] < dis[2])
    {
      car_move(CAR_TURNRIGHT);
    }   
  }
}

/**
 * 获取左边的最小距离 
 */
int get_left_distance()
{
  int servo_pos = 89;
  //转向左边
  for(servo_pos = middle_servo_pos;servo_pos <= max_servo_pos;servo_pos++)
  {
    myservo.write(servo_pos);
    delay(15);
  }
  int distance_val = get_distance();
    
  for(int i = 0;i < 3;i++)
  {
    myservo.write(max_servo_pos);
    delay(300);
    int val=get_distance();
    distance_val = min(distance_val,val);//左边距障碍距离测三次取最小值
  }
  return distance_val;
}

/**
 * 从左面转回到正面，再次获取正面的距离
 */
int get_left_back_front_distance()
{
  int servo_pos = middle_servo_pos;
  for(servo_pos = max_servo_pos;servo_pos >= 89;servo_pos--)
  {
    myservo.write(servo_pos);
    delay(15);
  }
  int distance_val = get_distance();
    
  for(int i = 0;i < 3;i++)
  {
    myservo.write(middle_servo_pos);
    delay(300);
    int val = get_distance();
    distance_val = min(distance_val,val);//正面距障碍距离测三次取最小值
  }
  return distance_val;
}

/**
 * 从正面转回到右边，获取右边的距离
 */
int get_right_distance()
{
  int servo_pos = middle_servo_pos;
  for(servo_pos;servo_pos >= min_servo_pos;servo_pos--)
  {
    myservo.write(servo_pos);
    delay(15);
  }
  int distance_val = get_distance();
    
  for(int i = 0;i < 3;i++)
  {
    myservo.write(min_servo_pos);
    delay(300);
    int val = get_distance();
    distance_val = min(distance_val,val);//右边距障碍距离测三次取最小值
  }
  return distance_val;
}
/**
 * 右边转回到正面
 */
void right_back_front()
{
  int servo_pos = middle_servo_pos;
  for(servo_pos = min_servo_pos;servo_pos <= middle_servo_pos;servo_pos++)
  {
    myservo.write(servo_pos);
    delay(15);
  }
}


int get_distance()
{
  digitalWrite(TrigPin, LOW); //低高低电平发一个短时间脉冲去TrigPin
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  float Value_cm = float( pulseIn(EchoPin, HIGH) * 17 )/1000; //将回波时间换算成cm
  //读取一个引脚的脉冲（HIGH或LOW）。例如，如果value是HIGH，pulseIn()会等待引脚变为HIGH，开始计时，再等待引脚变为LOW并停止计时。
  //返回脉冲的长度，单位微秒。如果在指定的时间内无脉冲函数返回。
  //此函数的计时功能由经验决定，长时间的脉冲计时可能会出错。计时范围从10微秒至3分钟。（1秒=1000毫秒=1000000微秒）
  //接收到的高电平的时间（us）* 340m/s / 2 = 接收到高电平的时间（us） * 17000 cm / 1000000 us = 接收到高电平的时间 * 17 / 1000  (cm)
//  Serial.println(Value_cm);
  int distance = int(Value_cm);
  //手动遮挡2个孔，调试返回是 1180左右
  if(distance >= 1180)
  {
     return 0;  
  }
  else if(distance >= 50)
  {
    return 50;  
  }
  else
  {
    return distance;  
  }
}
