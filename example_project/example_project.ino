#include <Wire.h>
#include <LiquidCrystal.h>

const int rs = 12;       // LCD screen pins
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int thumbPotPin = A0;
int indexPotPin = A1;
int middlePotPin = A2;
int ringPotPin = A3;
int littlePotPin = A4;
int rotatePotPin = A5;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  //16 columns and 2 rows
  lcd.print("Gesture Control");
  delay(2000);
  lcd.clear();
}

void loop() {
  int thumbValue = analogRead(thumbPotPin);
  int indexValue = analogRead(indexPotPin);
  int middleValue = analogRead(middlePotPin);
  int ringValue = analogRead(ringPotPin);
  int littleValue = analogRead(littlePotPin);
  int rotateValue = analogRead(rotatePotPin);


  Serial.print("Thumb: ");
  Serial.print(thumbValue);
  Serial.print("\tIndex: ");
  Serial.print(indexValue);
  Serial.print("\tMiddle: ");
  Serial.print(middleValue);
  Serial.print("\tRing: ");
  Serial.print(ringValue);
  Serial.print("\tLittle: ");
  Serial.print(littleValue);
  Serial.print("\tRotate: ");
  Serial.println(rotateValue);

  lcd.clear();
  lcd.setCursor(4  , 0); //Starting position of the first line
  lcd.print("Animate:");

  if (thumbValue == 0 && indexValue == 0 && middleValue == 0 && ringValue == 0 && littleValue == 0 && rotateValue >= 1000) {
    lcd.setCursor(5, 1);
    lcd.print("sleep");
  } else if (thumbValue >= 1000 && indexValue == 0 && middleValue == 0 && ringValue == 0 && littleValue == 0 && rotateValue >= 1000) {
    lcd.setCursor(6, 1);
    lcd.print("wake");
  } else if (thumbValue == 0 && indexValue >= 1000 && middleValue == 0 && ringValue == 0 && littleValue == 0 && rotateValue >= 1000) {
    lcd.setCursor(5, 1);
    lcd.print("look_up");
  } else if (thumbValue == 0 && indexValue == 0 && middleValue >= 1000 && ringValue == 0 && littleValue == 0 && rotateValue >= 1000) {
    lcd.setCursor(3, 1);
    lcd.print("look_down");
  } else if (thumbValue == 0 && indexValue == 0 && middleValue == 0 && ringValue >= 1000 && littleValue == 0 && rotateValue >= 1000) {
    lcd.setCursor(3, 1);
    lcd.print("head_shake");
  } else if (thumbValue == 0 && indexValue == 0 && middleValue == 0 && ringValue == 0 && littleValue >= 1000 && rotateValue >= 1000) {
    lcd.setCursor(5, 1);
    lcd.print("head_nod");
  } else if (thumbValue == 0 && indexValue == 0 && middleValue == 0 && ringValue == 0 && littleValue == 0 && rotateValue >= 1000) {
    lcd.setCursor(4, 1);
    lcd.print("head_right");
  } else if (thumbValue >= 1000 && indexValue >= 1000 && middleValue == 0 && ringValue == 0 && littleValue == 0 && rotateValue >= 1000) {
    lcd.setCursor(4, 1);
    lcd.print("head_left");
  } else if (thumbValue >= 1000 && indexValue >= 1000 && middleValue >= 1000 && ringValue == 0 && littleValue == 0 && rotateValue >= 1000) {
    lcd.setCursor(6, 1);
    lcd.print("sit");
  } else if (thumbValue >= 1000 && indexValue >= 1000 && middleValue >= 1000 && ringValue >= 1000 && littleValue == 0 && rotateValue >= 1000) {
    lcd.setCursor(5, 1);
    lcd.print("stand");
  } else if (thumbValue >= 1000 && indexValue >= 1000 && middleValue >= 1000 && ringValue >= 1000 && littleValue >= 1000 && rotateValue >= 1000) {
    lcd.setCursor(5, 1);
    lcd.print("raised");
  } else if (thumbValue >= 1000 && indexValue >= 1000 && middleValue >= 1000 && ringValue >= 1000 && littleValue >= 1000 && rotateValue == 0) {
    lcd.setCursor(5, 1);
    lcd.print("tiptoes");
  } else if (thumbValue >= 1000 && indexValue >= 1000 && middleValue >= 1000 && ringValue >= 1000 && littleValue == 0 && rotateValue == 0) {
    lcd.setCursor(4, 1);
    lcd.print("speak");
  } else {
    lcd.setCursor(4, 0);
    lcd.print("Unknown");
    lcd.setCursor(4, 1);
    lcd.print("Gesture");
  }

  delay(100);
}
