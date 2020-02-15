#define LED_R 3
#define LED_G 5
#define LED_B 6


int pwmValue = 0;

void setup() {
  // put your setup code here, to run once:
  analogWrite(LED_R, 255);
  analogWrite(LED_G, 255);
  analogWrite(LED_B, 255);
}

void loop() {
    int i;
    pwmValue = 255;
    for(i = 0;i < 255;i++){
        analogWrite(LED_R,pwmValue--);
        analogWrite(LED_G,255);
        analogWrite(LED_B,255);
        delay(10);
    }

    pwmValue = 0;
    for(i = 0;i < 255;i++){
        analogWrite(LED_R,pwmValue++);
        analogWrite(LED_G,255);
        analogWrite(LED_B,255);
        delay(10);
    }

    pwmValue = 255;
    for(i = 0;i < 255;i++){
        analogWrite(LED_R,255);
        analogWrite(LED_G,pwmValue--);
        analogWrite(LED_B,255);
        delay(10);
    }

    pwmValue = 0;
    for(i = 0;i < 255;i++){
        analogWrite(LED_R,255);
        analogWrite(LED_G,pwmValue++);
        analogWrite(LED_B,255);
        delay(10);
    }

    pwmValue = 255;
    for(i = 0;i < 255;i++){
        analogWrite(LED_R,255);
        analogWrite(LED_G,255);
        analogWrite(LED_B,pwmValue--);
        delay(10);
    }

    pwmValue = 0;
    for(i = 0;i < 255;i++){
        analogWrite(LED_R,255);
        analogWrite(LED_G,255);
        analogWrite(LED_B,pwmValue++);
        delay(10);
    }
}

