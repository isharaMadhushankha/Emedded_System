#include <Arduino.h>

int ledpin = 12;
int buzzerpin = 13;

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  Serial.begin(9600);
  Serial.println("command:LEDON,LEDOFF,BUZZERON,BUZZEROFF");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); 

    if (command == "LEDON") {
      digitalWrite(ledpin, HIGH);
      Serial.println("LED ON");
    }

    if (command == "LEDOFF") {
      digitalWrite(ledpin, LOW);
      Serial.println("LED OFF");
    }

    if (command == "BUZZERON") {
      tone(buzzerpin,5000);
      Serial.println("Buzzer ON");
    }

    if (command == "BUZZEROFF") {
      noTone(buzzerpin);
      Serial.println("Buzzer OFF");
    }
  }
}
