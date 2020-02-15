#include <Arduino.h>

#define PWM_pin 9

int pulsewidth = 0;    //高电平时间

void setup()
{
  pinMode(PWM_pin,OUTPUT);
}

void loop()
{
    pulse(10);      //设置舵机指向90度
} 

void pulse(int angle)     //设置舵机角度为angle
{
  pulsewidth=int ((angle*11)+500);  //计算高电平时间
  digitalWrite(PWM_pin,HIGH);       //设置高电平
  delayMicroseconds(pulsewidth);    //延时pulsewidth （us）
  digitalWrite(PWM_pin,LOW);        //设置低电平
  delay(20-pulsewidth/1000);        //延时20-pulsewidth/1000 （ms）
}
