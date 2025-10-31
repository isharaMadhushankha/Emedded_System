#include <Arduino.h>
const int segmentPins[8] = {2, 3, 4, 5, 6, 7, 8};
const int commonCathodePin = 9;
int red  = 13;
int yellow = 12;
int green = 11;
int buzzer = 10;

#include <liquidcrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte numbers[11] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110  // 9
};
void displayNumber(int num) {
  
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], HIGH);
  }

  for (int i = 0; i < 8; i++) {
    if (bitRead(numbers[num], i) == LOW) {
      digitalWrite(segmentPins[7-i], LOW);
    }
  }


}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Traffic Light");
  lcd.clear();

  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(commonCathodePin, OUTPUT);

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);  
  pinMode(green, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  digitalWrite(buzzer, LOW);
  for (int i = 0; i < 10; i++) 
  {
    displayNumber(i);
    lcd.setCursor(0,0);
    lcd.print("STOP      ");
    lcd.setCursor(0,1);
    lcd.print("WAIT FOR GREEN"); 
    delay(1000); 
  }
  lcd.clear();

  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(buzzer, LOW);
  
  for (int i = 0; i < 3; i++) 
  {
    displayNumber(i);
    lcd.setCursor(0,0);
    lcd.print("GET READY ");
    lcd.setCursor(0,1);
    lcd.print("WAIT FOR GREEN");
    delay(500); 
  }
    lcd.clear();
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(buzzer, LOW);
  tone(buzzer, 1000); 
  delay(500);
  noTone(buzzer);
  for (int i = 0; i < 10; i++) 
  {
    displayNumber(i);
     lcd.setCursor(0,0);
    lcd.print("GO        ");
    lcd.setCursor(0,1);
    lcd.print("SAFE JOURNEY");
    delay(1000);

  }
  lcd.clear();
}

