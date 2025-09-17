#define NUMPIXELS 1  // Количество светодиодов

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN);  // Создание объекта светодиодной ленты

// Метод для инициализации светодиодной ленты
void initialLed() {
  pixels.begin();
  pixels.setBrightness(20);  // Устанавливается яркость ленты (0-255)
}

// Метод выключения светодиода
void ledOff() {
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.show();
}

// Метод тестирования светодиода на основные цвета (RGB)
void testLed() {
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.show();
  delay(300);
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.show();
  delay(300);
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.show();
  delay(300);
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.show();
  delay(300);
}

// Метод для включения одного из цветов (на входе название цвета в нижнем регистре)
void ledOn(String color) {
  switch (color[0]) {
    case 'r':  // red
      pixels.setPixelColor(0, pixels.Color(255, 0, 0));
      break;
    case 'g':  // green
      pixels.setPixelColor(0, pixels.Color(0, 255, 0));
      break;
    case 'b':  // blue
      pixels.setPixelColor(0, pixels.Color(0, 0, 255));
      break;
    default:
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));
      break;
  }
  pixels.show();
}