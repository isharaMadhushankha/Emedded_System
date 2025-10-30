#include <Arduino.h>

#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','c'},
  {'*','0','#','D'},
};

byte rowpin[ROWS] = {9,8,7,6};
byte colpin[COLS] = {5,4,3,2};
Keypad keypad = Keypad(makeKeymap(keys),rowpin,colpin,ROWS,COLS);

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);


String password = "123";
String input = ""; 

int trigpin = 13;
int echopin = 12;
int buzzer = 11;

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

bool alarmActive = false;

void setup() {
 Serial.begin(9600);
 lcd.init();
    lcd.backlight();
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("system ready");

    pinMode(trigpin, OUTPUT);
    pinMode(echopin, INPUT);
    pinMode(buzzer, OUTPUT);

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
     lcd.clear();
}

void loop() {

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  int diuraion = pulseIn(echopin,HIGH);
  int cm = diuraion/ 58;

  display.clearDisplay();                     // Clear the screen
  display.setTextSize(2);                     // Smallest text size
  display.setTextColor(SSD1306_WHITE);        // White text
  display.setCursor(0, 20);                   // Position to start text
  display.println(cm);           
  display.display(); 

  if(cm < 50){
    if(!alarmActive){
    lcd.setCursor(0,0);
    lcd.print("Take a Action");
    delay(1000);
    alarmActive = true;
    }
    }

  else{
    noTone(buzzer);
  }
    
    char key = keypad.getKey();
    if(key){
    
    Serial.print("pressed key:");
    Serial.println(key);

    input += key;

    if(input.length()==3){
        if(input == password){
        Serial.println("password match");
         tone(buzzer,5000);
        input = "";
       }else{
        Serial.println("password not match");
        input = "";
       }
    }

  }
   lcd.clear();
   
}
