#include <Arduino.h>

const int _pin = 13;
const int _delay = 500;

void setup() {
  pinMode(_pin, OUTPUT);
}

void blink(int _pin, int _delay) {
  digitalWrite(_pin, HIGH);   // Включаем светодиод в высоком напряжении
  delay(_delay);              // ждём пол-секунды
  digitalWrite(_pin, LOW);    // Отключаем светодиот
  delay(_delay);              // ждём пол-секунды

}

void loop() {
  blink(_pin, _delay);
}