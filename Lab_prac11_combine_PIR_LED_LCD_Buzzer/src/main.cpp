#include <Arduino.h>

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int ledpin = 13;
int buzzerpin = 12;
int pirPin = 2;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(ledpin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(pirPin, INPUT);

  lcd.setCursor(0,0);
  lcd.print("ready to print");
  lcd.clear();
}

void loop() {
  int value = digitalRead(pirPin);
  if(value){
    digitalWrite(ledpin, HIGH);
    tone(buzzerpin,5000);
    lcd.setCursor(0,0);
    lcd.print("Motion detected");
    delay(500);

  }else{
    digitalWrite(ledpin, LOW);
    noTone(buzzerpin);
    lcd.setCursor(0,0);
    lcd.print("Area Secure");
    delay(500);
  }
  lcd.clear();
}
