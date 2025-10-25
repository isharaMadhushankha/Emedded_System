#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
 
}

void loop() {
  double value = analogRead(A0);

  Serial.println(value); 
  delay(500);

}
