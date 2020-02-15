#define RIPIN 2
#define LED 13

int val = 0;

void setup(){
  pinMode(RIPIN,INPUT);
  pinMode(LED, OUTPUT);  
  
  digitalWrite(LED, LOW);
  Serial.begin(9600);
}

void loop(){
    val = digitalRead(RIPIN);
    if(val == HIGH){
        digitalWrite(LED, HIGH);
    }else{
      digitalWrite(LED, LOW);
    }
    Serial.println(val);
}
