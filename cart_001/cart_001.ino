int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

int row_speed = 100; //轮子的转速


void setup() {
  // put your setup code here, to run once:
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  
  car_stop();
}

void loop() {
  // put your main code here, to run repeatedly:
  go();
  delay(2000);
  back();
  delay(2000);
  go_left();
  delay(2000);
  go_right();
  delay(2000);
  car_stop();
  delay(2000);
}

void car_stop()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void go()
{
  digitalWrite(in1,HIGH);
  analogWrite(in2,row_speed);
  //digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  //digitalWrite(in4,HIGH);
  analogWrite(in4,row_speed);
}

void back()
{
  digitalWrite(in1,LOW);
  analogWrite(in2,row_speed);
  digitalWrite(in3,HIGH);
  analogWrite(in4,row_speed);
}

void go_left()
{
  digitalWrite(in1,HIGH);
  analogWrite(in2,row_speed);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void go_right()
{
  digitalWrite(in1,LOW);
  analogWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  analogWrite(in4,row_speed);
}
