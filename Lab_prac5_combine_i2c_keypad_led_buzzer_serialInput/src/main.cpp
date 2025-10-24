#include <Arduino.h>

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte rowpin[ROWS] = {9,8,7,6};
byte colpin[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys),rowpin,colpin,ROWS,COLS);


LiquidCrystal_I2C lcd(0x27,16,2);

int ledpin = 13;
int buzzerpin = 12;

void setup() {

  Serial.begin(9600);

  pinMode(ledpin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Ready to print..");
  delay(500);
  lcd.clear();
}

void loop() {

  char key = keypad.getKey();

  if(key){
    Serial.print("pressed Key:");
    Serial.println(key);

    if(key == '1'){
      digitalWrite(ledpin,HIGH);
      noTone(buzzerpin);
      Serial.println("LED ON");
      lcd.setCursor(0,0);
      lcd.print("you pressed:");
      lcd.setCursor(0,1);
      lcd.print(key);
      delay(2000);
    }

    if(key=='2'){
      digitalWrite(ledpin, LOW);
      tone(buzzerpin,5000);
      Serial.println("Buzzser on");
      lcd.setCursor(0,0);
      lcd.print("you pressed :");
      lcd.setCursor(0,1);
      lcd.print(key);
      delay(2000);
    }
  }

  lcd.clear();
  
}
