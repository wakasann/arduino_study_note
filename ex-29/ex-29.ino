String inputString = "";
bool stringComplete = false; 

int Relay = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  inputString.reserve(200);

  pinMode(13,OUTPUT);
  pinMode(Relay,OUTPUT);
  
}

void loop() {
  if (stringComplete) {
    Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    Serial.println(inChar);
    if(inChar == "1")
    {
      digitalWrite(Relay, HIGH);
      Serial.println("LED OPEN");
    }
    else if(inChar == "0")
    {
     digitalWrite(Relay, LOW); 
     Serial.println("LED CLOSE");
     }
    
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }else{
      // add it to the inputString:
      inputString += inChar;
    }
  }
}
