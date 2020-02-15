int Led = 13; //定义LED接口
int buttonPin = 3; //定义避障传感器接口
int val;
void setup() {
  // put your setup code here, to run once:
  pinMode(Led, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(Led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(buttonPin);
  if(val == HIGH)
  {
    digitalWrite(Led, HIGH);
  }
  else
  {
    digitalWrite(Led, LOW);
  }
}
