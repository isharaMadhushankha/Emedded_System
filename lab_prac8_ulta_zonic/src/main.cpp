#include <Arduino.h>

int trigpin = 13;
int echopin  = 12;

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
}

void loop() {
 
 digitalWrite(trigpin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigpin, LOW);

 int diuration = pulseIn(echopin,HIGH);

 int cm = diuration / 58;

 Serial.println(cm);
 delay(500);
}
