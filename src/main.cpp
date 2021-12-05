#include <Arduino.h>

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);   // Включаем светодиод в высоком напряжении
  delay(500);              // ждём пол-секунды
  digitalWrite(13, LOW);    // Отключаем светодиот
  delay(500);              // ждём пол-секунды
}