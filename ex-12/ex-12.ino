#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5


unsigned char table[4][4] = 
{
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
};

void Phase_A();
void Phase_B();
void Phase_C();
void Phase_D();
void Phase();


void setup(){
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    Serial.begin(9600);
    
}

void loop(){

   Phase_A();
   delay(20);
   Phase_B();
   delay(20);
   Phase_C();
   delay(20);
   Phase_D();
   delay(20);

   Phase(1);
}

void Phase_A(){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
void Phase_B(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
void Phase_C(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}
void Phase_D(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void Phase(char in_type){
    unsigned char i;
    if(in_type >= 1 && in_type <=4){
        i = in_type - 1;
        // digitalWrite(IN1, table[in_type][0]);
        // digitalWrite(IN2, table[in_type][1]);
        // digitalWrite(IN3, table[in_type][2]);
        // digitalWrite(IN4, table[in_type][3]);
    }
}
