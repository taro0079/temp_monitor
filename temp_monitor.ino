#include "DHT.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define DATA_PIN 4
#define LED_RED 5
#define LED_YELLOW 6
#define LED_GREEN 7
Adafruit_SSD1306 display(-1);

DHT dht(DATA_PIN, DHT11);

void setup() {
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.begin(9600);
  dht.begin();

  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);




}

void loop() {
  // put your main code here, to run repeatedly:
  delay(3000);
  display.clearDisplay(); // ディスプレイの初期化

  display.setTextSize(2); // テキストの大きさ
  display.setTextColor(WHITE); // テキストの色
  display.setCursor(0, 0); // 出力文字の開始位置

  float h = dht.readHumidity(); // 湿度の読み取り
  float t = dht.readTemperature(); // 温度の読み取り



  display.print("Temp:");
  display.println(t);
  display.print("Hum:");
  display.println(h);
  display.display();

  if (t <= 25) {
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);
  } else if (t > 25 && t < 28) {
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_RED, LOW); 
 } else {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
  }
}
