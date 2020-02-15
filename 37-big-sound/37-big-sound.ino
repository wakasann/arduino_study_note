//高感度声音
int Led = 13; //定义LED接口
int sensorPin = A5; //定义D0接口
int val;
void setup() {
  // put your setup code here, to run once:
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(sensorPin);
  digitalWrite(Led, HIGH);
  delay(val);
  digitalWrite(Led, LOW);
  delay(val);
  Serial.println(val, DEC);
}
