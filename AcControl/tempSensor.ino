OneWire oneWire(DALLAS_PIN);                // Создание объекта OneWire
DallasTemperature dallasSensors(&oneWire);  // Создание объекта DallasTemperature

unsigned long lastTempRequest = 0;  // Переменная для таймера
const long tempInterval = 60000;    // Интервал опроса (1 минута)

void initialDallas() {  // Инициализация датчика температуры
  dallasSensors.begin();
}

void getTemperature() {
  unsigned long now = millis();
  if (now - lastTempRequest >= tempInterval) {       // Определение истек ли интервал опроса датчика
    lastTempRequest = now;
    dallasSensors.requestTemperatures();             // Запрос температуры
    float tempC = dallasSensors.getTempCByIndex(0);  // Опрос первого датчика на шине

    Serial.print("Температура: ");
    Serial.print(tempC);
    Serial.println(" °C");
  }
}