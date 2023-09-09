#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin("Esp32"); // Set the Bluetooth device name here
  Serial.begin(115200); // Serial communication baud rate

  // Set GPIO pins for potentiometers
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(25, INPUT);
}

void loop() {
  // Read potentiometer values
  int potValue1 = analogRead(34);
  int potValue2 = analogRead(35);
  int potValue3 = analogRead(32);
  int potValue4 = analogRead(33);
  int potValue5 = analogRead(25);

  // Print potentiometer values in a single line
  Serial.printf("k1: %d, k2: %d, k3: %d, k4: %d, k5: %d\n", potValue1, potValue2, potValue3, potValue4, potValue5);

  // If a device is connected, print the device name and potentiometer values
  if (SerialBT.hasClient()) {
    SerialBT.printf("k1: %d, k2: %d, k3: %d, k4: %d, k5: %d\n", potValue1, potValue2, potValue3, potValue4, potValue5);
  }

  // Add some delay if needed
  delay(200);
}to
