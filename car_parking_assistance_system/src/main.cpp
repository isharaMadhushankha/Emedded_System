#include<Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);


int trigpin = 13;
int echopin = 12;
int yellow = 11;
int red = 10;
int buzzer = 9;

void setup() {
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(yellow, OUTPUT);
pinMode(red, OUTPUT);
pinMode(buzzer, OUTPUT);

lcd.init();
lcd.backlight();
lcd.clear();

lcd.setCursor(0,0);
lcd.print("System ready..");

}

void loop() {

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  double diuration = pulseIn(echopin,HIGH);

  int cm = diuration / 58;

  lcd.setCursor(0,0);
  lcd.print("distance: ");
  lcd.setCursor(10,0);
  lcd.println(cm);

  if(cm < 10){
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    tone(buzzer,5000);
    lcd.setCursor(0,1);
    lcd.print("Object Very close");
    
  }else if(cm <= 20 && cm > 10){
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    noTone(buzzer);
    lcd.setCursor(0,1);
    lcd.print("Object Nearby");
  }else{
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    noTone(buzzer);
    lcd.setCursor(0,1);
    lcd.print("Safe distance");
  }
  delay(500);
  lcd.clear();


}
