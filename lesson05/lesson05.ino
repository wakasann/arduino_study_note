#define Pot A0
#define LED 3

int PotBuffer = 0;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW  );
  delay(5000);
}

void loop(){
  PotBuffer = analogRead(Pot);
  PotBuffer = map(PotBuffer,0,1023,0,255);
  //Serial.print("Pot = ");
 // Serial.println(PotBuffer);
  analogWrite(LED, PotBuffer); 
}
