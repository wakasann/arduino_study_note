int led = 2;

int sensor_pin = 4;

int status = 0;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(sensor_pin,INPUT);
  pinMode(led,OUTPUT);
}

void light_led()
{
  digitalWrite(led,LOW);
  delay(500);
  
}

void loop() {
  int val = digitalRead(sensor_pin);
  if(val == 1)
  {
     digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }

  Serial.println(val);
  delay(500);
}
