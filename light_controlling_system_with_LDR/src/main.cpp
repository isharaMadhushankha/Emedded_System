#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int red = 13;
int buzzer = 12;
int yellow = 11;
int green = 10;
int button = 2;

void setup() {

  Serial.begin(9600);
  
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT);
  pinMode(A0, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();

}

void loop() {
  int value = analogRead(A0);

  Serial.println(value);

  if(value <=250){
    digitalWrite(red, HIGH);
    tone(buzzer,5000);
    while (digitalRead(button) == LOW) {
      // keep waiting for button press
      delay(50);
    }
    noTone(buzzer);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);

    lcd.setCursor(0,0);
    lcd.print("bright");
    delay(5000);
  }else if (value <= 500 && value > 250){
    digitalWrite(red, LOW);
    tone(buzzer,5000);
    delay(100);
     noTone(buzzer);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);

    lcd.setCursor(0,0);
    lcd.print("Moderate");
    delay(5000);
  }else{
    digitalWrite(red, LOW);
    tone(buzzer,5000);
    delay(100);
    noTone(buzzer);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);

    lcd.setCursor(0,0);
    lcd.print("Dark");
    delay(5000);
  }
  
  lcd.clear();
}
