#include <S28BYJ48.h>

#define LED_PIN 13

//S28BYJ48 motor(8,9,10,11);
S28BYJ48 motor(4,5,6,7);

void setup(){
  Serial.begin(115200);
  Serial.println("s28byj48_test start");

  motor.setStepDuration(2500);

  pinMode(LED_PIN, OUTPUT);
}

void loop(){
  while (Serial.available() > 0) {
    int serialData = Serial.read();

    digitalWrite(LED_PIN, HIGH);
    Serial.println("rotate");
    
    // clockwise
    // via https://arduino-info.wikispaces.com/SmallSteppers
    // 64 * 64 = 4096[steps]
    motor.step(4096);
    
    // anti-clockwise
    //motor.step(-4096);

    Serial.println("fin");
    
    digitalWrite(LED_PIN, LOW);
  }
}
