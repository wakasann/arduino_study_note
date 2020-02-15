#include <Arduino.h>

#define SEG_a 2				//IO命名
#define SEG_b 3
#define SEG_c 4
#define SEG_d 5
#define SEG_e 6
#define SEG_f 7
#define SEG_g 8
#define SEG_h 9


#define COM1 10
#define COM2 11
#define COM3 12
#define COM4 13

//数码管0-9数字码值
unsigned char table[10][8] =
{
	{0,	1,	0,	1,	1,	1,	1,	1},			//0
	{1,	1,	1,	1,	1,	0,	0,	1},			//1
	{1,	1,	0,	0,	0,	1,	0,	0},			//2
	{1,	1,	0,	1,	0,	0,	0,	0},			//3
	{1,	0,	0,	1,	1,	0,	0,	1},			//4
	{0,	1,	1,	0,	1,	1,	0,	1},			//5
	{0,	1,	1,	1,	1,	1,	0,	1},			//6
	{0,	0,	0,	0,	0,	1,	1,	1},			//7
	{0,	1,	1,	1,	1,	1,	1,	1},			//8
	{0,	1,	1,	0,	1,	1,	1,	1}			//9
};
void displayNum(unsigned char com,unsigned char num);


void setup()
{
  pinMode(SEG_a,OUTPUT);				//设置引脚为输出
 pinMode(SEG_b,OUTPUT);
 pinMode(SEG_c,OUTPUT);
 pinMode(SEG_d,OUTPUT);
 pinMode(SEG_e,OUTPUT);
 pinMode(SEG_f,OUTPUT);
 pinMode(SEG_g,OUTPUT);
 pinMode(SEG_h,OUTPUT);
 pinMode(COM1,OUTPUT);
 pinMode(COM2,OUTPUT);
 pinMode(COM3,OUTPUT);
 pinMode(COM4,OUTPUT);
}

void loop(){
  displayNum(1,1);
  delay(3);
  displayNum(2,2);
  delay(3);
  displayNum(3,4);
  delay(3);
  displayNum(4,4);
  delay(3);
}

void displayNum(unsigned char com,unsigned char num){
  digitalWrite(SEG_a,LOW);
  digitalWrite(SEG_b,LOW);
  digitalWrite(SEG_c,LOW);
  digitalWrite(SEG_d,LOW);
  digitalWrite(SEG_e,LOW);
  digitalWrite(SEG_f,LOW);
  digitalWrite(SEG_g,LOW);
  digitalWrite(SEG_h,LOW);
  
  switch(com){
    case 1:
        digitalWrite(COM1,HIGH);
        digitalWrite(COM2,LOW);
        digitalWrite(COM3,LOW);
        digitalWrite(COM4,LOW);
        break;
    case 2:
        digitalWrite(COM1,LOW);
        digitalWrite(COM2,HIGH);
        digitalWrite(COM3,LOW);
        digitalWrite(COM4,LOW);
        break;
    case 3:
        digitalWrite(COM1,LOW);
        digitalWrite(COM2,LOW);
        digitalWrite(COM3,HIGH);
        digitalWrite(COM4,LOW);
        break;
    case 4:
        digitalWrite(COM1,LOW);
        digitalWrite(COM2,LOW);
        digitalWrite(COM3,LOW);
        digitalWrite(COM4,HIGH);
        break;
  }
   digitalWrite(SEG_a,table[num][7]);	//设置a引脚的电平
   digitalWrite(SEG_b,table[num][6]);
   digitalWrite(SEG_c,table[num][5]);
   digitalWrite(SEG_d,table[num][4]);
   digitalWrite(SEG_e,table[num][3]);
   digitalWrite(SEG_f,table[num][2]);
   digitalWrite(SEG_g,table[num][1]);
   digitalWrite(SEG_h,table[num][0]);
  
}

