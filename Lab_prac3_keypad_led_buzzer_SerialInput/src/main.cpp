#include <Arduino.h>
#include <Keypad.h>


const byte ROWS = 4;
const byte COLS = 5;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','c'},
  {'*','0','#','D'},
};

byte rowpin[ROWS] = {9,8,7,6};
byte colpin[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys),rowpin,colpin,ROWS,COLS);

int ledpin = 13; 
int buzzepin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(buzzepin, OUTPUT);
  
}

void loop() {

char key = keypad.getKey();

 if(key){
    Serial.print("pressed key:");
    Serial.println(key);

    if(key=='1'){
      digitalWrite(ledpin, HIGH);
      Serial.println("LED ON");
      noTone(buzzepin);
      delay(2000);
    }
    if(key == '2'){
      Serial.println("Buzzer on");
      tone(buzzepin,5000);
      digitalWrite(ledpin, LOW);
      delay(2000);
    }
    
 }

}
