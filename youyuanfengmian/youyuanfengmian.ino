#define MYSOUND 3
#define KEY 2

int KEY_STATE = 0;

void setup(){
  pinMode(MYSOUND,OUTPUT);
  pinMode(KEY,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  
  getKeyState();
  if(KEY_STATE == 1){
    digitalWrite(MYSOUND,HIGH);
    delay(50);
    digitalWrite(MYSOUND,LOW);
  }
  //digitalWrite(MYSOUND,HIGH);
  //delay(20);
  //digitalWrite(MYSOUND,LOW);
  //delay(5000);
}

void getKeyState(){
  KEY_STATE = 0; //init
  if(digitalRead(KEY) == LOW){
    Serial.println("come in");
    delay(20);
    if(digitalRead(KEY) == LOW){
       KEY_STATE = 1;
       //wait key press up
       while(digitalRead(KEY) == LOW);
    }
  }
}
