#define KEY 2 
#define Buzzer 3 //LED
#define SWTICHPIN A5 //钢珠开关

int flag = 0;
int val = 0;
void setup(){

  pinMode(KEY, INPUT_PULLUP);
  pinMode(SWTICHPIN, INPUT_PULLUP);
  pinMode(Buzzer, OUTPUT);
  //attachInterrupt(0,BuzzerDi,FALLING);

  digitalWrite(Buzzer,HIGH);
  delay(500);
  digitalWrite(Buzzer,LOW);
  
  Serial.begin(9600);

}

void loop(){

  val = analogRead(SWTICHPIN);

  if(val > 20){
    val = 0;
    digitalWrite(Buzzer,HIGH);
  }else{
    digitalWrite(Buzzer,LOW);
  }
  
  Serial.println(val);

  if(flag == 1){
    flag = 0;
    digitalWrite(Buzzer,HIGH);
    delay(1500);
  }else{
    digitalWrite(Buzzer,LOW);
  }
}

void BuzzerDi(){
  flag =  1;
}
