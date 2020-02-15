#define Pot A1
#define LED 13
int PotNumber = 0;

void setup(){
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop(){
  PotNumber = analogRead(Pot);
  Serial.print("val=");
  Serial.println(PotNumber);
  if(PotNumber >= 1020){
    digitalWrite(LED,HIGH);
  }else{
    digitalWrite(LED,LOW);
  }
  delay(500);
}
