#define LED_R 4
#define LED_G 5
#define LED_B 6
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_R,HIGH);
  digitalWrite(LED_G,LOW);
  digitalWrite(LED_B,LOW);
  delay(2000);
  digitalWrite(LED_R,LOW);
  digitalWrite(LED_G,HIGH);
  digitalWrite(LED_B,LOW);
  delay(2000);
  digitalWrite(LED_R,LOW);
  digitalWrite(LED_G,LOW);
  digitalWrite(LED_B,HIGH);
  delay(2000);
}
