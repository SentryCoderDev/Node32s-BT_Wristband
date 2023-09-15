#include <BluetoothSerial.h>
#include <LiquidCrystal.h>

BluetoothSerial SerialBT;

// LCD Screen Pins
const int rs = 16; // Digital Pin 16
const int en = 17; // Digital Pin 17
const int d4 = 18; // Digital Pin 18
const int d5 = 19; // Digital Pin 19
const int d6 = 5;  // Digital Pin 20
const int d7 = 21; // Digital Pin 21

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buttonPin = 26; // Digital Pin 26, button pin
bool sendData = false; // Flag to use for sending data

void setup() {
  SerialBT.begin("SentryESP32"); // Bluetooth device name
  Serial.begin(115200);

  // Define GPIO Pins For Potentiometer
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(25, INPUT);

  // Set the button pin as an input with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // Initialize the LCD screen
  lcd.begin(16, 2);
}

void loop() {
  int potValue1 = analogRead(25);
  int potValue2 = analogRead(33);
  int potValue3 = analogRead(32);
  int potValue4 = analogRead(35);
  int potValue5 = analogRead(34);

  // Clear the LCD screen
  lcd.clear();

  // First line
  lcd.setCursor(0, 0);
  lcd.print("k");
  lcd.print(potValue1);
  lcd.print(" ");
  lcd.print(potValue2);
  lcd.print(" ");
  lcd.print("k");
  lcd.print(potValue3);

  // Second line
  lcd.setCursor(0, 1);
  lcd.print("k");
  lcd.print(potValue4);
  lcd.print(" ");
  lcd.print("send");
  lcd.print(" ");
  lcd.print("k");
  lcd.print(potValue5);

  // If a device is connected and the button is pressed, send the data
  if (SerialBT.hasClient() && digitalRead(buttonPin) == LOW) {
    SerialBT.printf("k1: %d, k2: %d, k3: %d, k4: %d, k5: %d\n", potValue1, potValue2, potValue3, potValue4, potValue5);
    sendData = true; // Mark data as sent
  }

  // Reset the flag when the button is released to prevent sending data again
  if (sendData && digitalRead(buttonPin) == HIGH) {
    sendData = false;
  }

  delay(150);
}
