#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int ledpin = 13;
int pirPin = 2;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(ledpin, OUTPUT);
  pinMode(pirPin, INPUT);

  lcd.setCursor(0,0);
  lcd.print("ready to print");
  lcd.clear();
}

void loop() {
  int value = digitalRead(pirPin);
  if(value){
    digitalWrite(ledpin, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Motion detected");
  }else{
    digitalWrite(ledpin, LOW);
    lcd.setCursor(0,0);
    lcd.print("no Motion detected");
  }
  
}
