int sensorPin = 2;
int value = 0;
//面向模块引脚有最左边'S'字, 最右边'S'字
//S 1 -> 2, 2 ->VCC,3 -> GND -
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(sensorPin);
  Serial.println(value);
  delay(1000);
}
