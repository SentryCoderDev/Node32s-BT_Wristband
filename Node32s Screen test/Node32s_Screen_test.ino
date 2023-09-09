#include <LiquidCrystal.h>

// LCD ekranın pin bağlantıları
const int rs = 16; // Digital Pin 16
const int en = 17; // Digital Pin 17
const int d4 = 18; // Digital Pin 18
const int d5 = 19; // Digital Pin 19
const int d6 = 5; //  Digital Pin 5
const int d7 = 21; // Digital Pin 21

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // LCD display column and row units are set (16 columns, 2 rows for 16x2)
  lcd.begin(16, 2);

  // "Hello, World!" appears on the screen. print
  lcd.print("Hello, World!");
 
}

void loop() {
 // Even if you don't need to do anything else in the loop function
 // The text remains fixed on the LCD screen.
}
