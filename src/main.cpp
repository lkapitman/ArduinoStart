#include <Arduino.h>

#define PIN_TRIG 12
#define PIN_ECHO 11

long duration, cm;

int pin = 13;
int delayTime = 500;

void setup() {

  // Инициализируем взаимодействие по последовательному порту

  Serial.begin (9600);
  //Определяем вводы и выводы
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(pin, OUTPUT);
}

void blink(int pin, int delayTime) {
  digitalWrite(pin, HIGH);   // Включаем светодиод в высоком напряжении
  delay(delayTime);              // ждём пол-секунды
  digitalWrite(pin, LOW);    // Отключаем светодиот
  delay(delayTime);              // ждём пол-секунды
}

void loop() {

  blink(pin, delayTime);

  // Сначала генерируем короткий импульс длительностью 2-5 микросекунд.

  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);

  // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы. 
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  //  Время задержки акустического сигнала на эхолокаторе.
  duration = pulseIn(PIN_ECHO, HIGH);

  // Теперь осталось преобразовать время в расстояние
  cm = (duration / 2) / 29.1;

  Serial.print("Расстояние до объекта: ");
  Serial.print(cm);
  Serial.println(" см.");

  // Задержка между измерениями для корректной работы скеча
  delay(250);
}