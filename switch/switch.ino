#define LED 13
#define KEY 2

int KEY_NUM = 0;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(KEY, INPUT_PULLUP);
}

void loop(){
  ScanKey();
  if(KEY_NUM == 1){
    digitalWrite(LED,!digitalRead(LED));
  }
}

void ScanKey(){
  KEY_NUM = 0;
  if(digitalRead(KEY) == LOW){
    delay(20);
    if(digitalRead(KEY) == LOW){
      KEY_NUM = 1;
      while(digitalRead(KEY) == LOW);
    }
  }
  
}
