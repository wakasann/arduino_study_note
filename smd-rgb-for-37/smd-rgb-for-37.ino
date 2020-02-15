int RGB_R = 3;
int RGB_G = 5;
int RGB_B = 6;

int val;

void setup() {
  // put your setup code here, to run once:
  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_G, OUTPUT);
  pinMode(RGB_B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(val = 255; val > 0;val--)
  {
    analogWrite(RGB_R,val);
    analogWrite(RGB_G,255 - val);
    analogWrite(RGB_B,255 - val);
    delay(10);
  }

  for(val = 0; val < 255;val++)
  {
    analogWrite(RGB_R,val);
    analogWrite(RGB_G,255 - val);
    analogWrite(RGB_B,255 - val);
    delay(10);                                     
  }
}
