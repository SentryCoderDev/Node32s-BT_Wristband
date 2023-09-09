#include <BluetoothSerial.h>
#include <LiquidCrystal.h>

BluetoothSerial SerialBT;

// LCD ekranın pin bağlantıları
const int rs = 16; // Dijital Pin 16
const int en = 17; // Dijital Pin 17
const int d4 = 18; // Dijital Pin 18
const int d5 = 19; // Dijital Pin 19
const int d6 = 5;  // Dijital Pin 20
const int d7 = 21; // Dijital Pin 21

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  SerialBT.begin("SentryESP32"); // Bluetooth cihaz adı
  Serial.begin(115200);          // Seri iletişim hızı

  // Potansiyometre için GPIO pinlerini ayarla
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(25, INPUT);

  // LCD ekranın sütun ve satır sayısını ayarla (16x2 için 16 sütun, 2 satır)
  lcd.begin(16, 2);
}

void loop() {
  // Potansiyometre değerlerini oku
  int potValue1 = analogRead(34);
  int potValue2 = analogRead(35);
  int potValue3 = analogRead(32);
  int potValue4 = analogRead(33);
  int potValue5 = analogRead(25);

  // LCD ekranı temizle
  lcd.clear();

  // 1. satır
  lcd.setCursor(0, 0);
  lcd.print("k");
  lcd.print(potValue1);
  lcd.print("    ");
  lcd.print(potValue2);
  lcd.print("    k");
  lcd.print(potValue3);

  // 2. satır
  lcd.setCursor(0, 1);
  lcd.print("k");
  lcd.print(potValue4);
  lcd.print("    ");
  lcd.print("    ");
  lcd.print("    k");
  lcd.print(potValue5);

  // Eğer bir cihaz bağlıysa, cihaz adını ve potansiyometre değerlerini gönder
 if (SerialBT.hasClient()) {
    SerialBT.printf("k1: %d, k2: %d, k3: %d, k4: %d, k5: %d\n", potValue1, potValue2, potValue3, potValue4, potValue5);
  }


  // Gecikme ekleyebilirsiniz
  delay(200);
}
