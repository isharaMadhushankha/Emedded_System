#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int cyan = 13;
int green = 12;
int yellow = 11;
int orange = 10;
int buzzerpin = 9;

void setup() {
  pinMode(cyan, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(orange,OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(A0, INPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();

}

void loop() {
  double value = analogRead(A0);
  
  Serial.println("values is:");
  Serial.println(value);

  if(value< 250){
    tone(buzzerpin,5000);
    delay(100);
    noTone(buzzerpin);
    digitalWrite(cyan, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(yellow, LOW);
    lcd.setCursor(0,0);
    lcd.print("Bright");
     delay(1000);

  }else if(value >= 250 && value < 500){
    tone(buzzerpin,5000);
    delay(100);
    noTone(buzzerpin);
    digitalWrite(cyan, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(yellow, LOW);
    lcd.setCursor(0,0);
    lcd.print("Moderate");
      delay(5000);
  }
  else if(value >= 500 && value < 750){
     tone(buzzerpin,5000);
    delay(100);
    noTone(buzzerpin);
    digitalWrite(cyan, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(orange, LOW);
    lcd.setCursor(0,0);
    lcd.print("Dim");
    delay(5000);
     
  }
  else{
     tone(buzzerpin,5000);
    delay(100);
    noTone(buzzerpin);
    digitalWrite(cyan, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(orange, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Dark");
     delay(5000);
  }
   lcd.clear();
  }
 

