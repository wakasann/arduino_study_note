int inByte = 0;         // incoming serial byte

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available() > 0) {
      // get incoming byte:
      inByte = Serial.read();
      Serial.write(inByte);
    }
}
