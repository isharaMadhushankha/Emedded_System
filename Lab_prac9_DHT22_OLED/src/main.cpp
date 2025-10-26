#include <Arduino.h>

#include <DHT.h>

#define DHT22_PIN 2
DHT dht22(DHT22_PIN,DHT22);

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  Serial.begin(9600);
  dht22.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
 float humi = dht22.readHumidity();
 float temp = dht22.readTemperature();

 Serial.print("Humifity is:");
 Serial.print(humi);
 Serial.print(" |  ");
 Serial.print("Temparature is:");
 Serial.println(temp);
 delay(500);

  display.clearDisplay();                     // Clear the screen
  display.setTextSize(1);                     // Smallest text size
  display.setTextColor(SSD1306_WHITE);        // White text
  display.setCursor(0, 10);                   // Position to start text
  display.println(humi);            // Print text
  display.display(); 

}
