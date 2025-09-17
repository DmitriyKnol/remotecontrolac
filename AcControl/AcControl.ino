//==============Используемые библиотеки======================

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_NeoPixel.h>
#include <IRsend.h>

//===============Настройки пинов============================

#define IR_PIN_IN 14  // Пин ИК приёмника D5
#define LED_PIN 12    // Пин светодиода D6 (адресный сведодиод)
#define DALLAS_PIN 0  // Пин температурного датчика D3
#define BUTTON_PIN 2  // Пин кнопки переключения режимов D4
#define RBUTTON_A 16  // Пин радиокнопки D0
#define RBUTTON_B 15  // Пин радиокнопки D8
#define RBUTTON_C 5   // Пин радиокнопки D1
#define RBUTTON_D 13  // Пин радиокнопки D7 
#define IR_PIN_OUT 4  // Пин ИК излучателя D2

void setup() {
  Serial.begin(115200);
  initialDallas();
  initialLed();
  testLed();
  initialIrConsumer();
  initialIrProducer();
  initialButton();
}

void loop() {
  getTemperature();
  if (!checkMode()) {  // Проверка режима работы
irProducerControl();
  } else {
    getIrSignal();
  }
}
