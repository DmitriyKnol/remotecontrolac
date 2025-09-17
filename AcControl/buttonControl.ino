bool modeFlag = false;
int lastRaw = HIGH;
unsigned long lastDebounce = 0;
const unsigned long debounceDelay = 50;

#define LED_TIMER 1000  // Время свечения светодиода при переключении режимов

void initialButton() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  ledOn("green");
  Serial.println("Режим управления кондиционером");
  delay(LED_TIMER);
  ledOff();
}

bool checkMode() {
  int raw = digitalRead(BUTTON_PIN);
  if (raw != lastRaw) lastDebounce = millis();

  if (millis() - lastDebounce > debounceDelay) {
    static int stable = HIGH;
    if (raw != stable) {
      stable = raw;
      if (stable == LOW) {
        modeFlag = !modeFlag;
        updateLEDs();
      }
    }
  }

  lastRaw = raw;
  return modeFlag;
}

void updateLEDs() {
  if (modeFlag) {
    ledOn("red");
    Serial.println("Режим приема сигнала с ИК пульта");
    delay(LED_TIMER);
    ledOff();
  } else {
    ledOn("green");
    Serial.println("Режим управления кондиционером");
    delay(LED_TIMER);
    ledOff();
  }
}
