#define DataPot A0

void setup(){
  Serial.begin(9600);
//  pinMode();
}

void loop(){
  
  int num = analogRead(DataPot);
  float temp = num * 0.48876; 
  Serial.print("tmp:");
  Serial.println(temp);
  delay(1000);
}
