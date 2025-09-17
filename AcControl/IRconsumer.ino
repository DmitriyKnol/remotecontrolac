// ВАЖНО для кондиционеров. Настройка ИК приемника для считывания состояния:
#define MY_CAPTURE_BUFFER_SIZE 2000  // большой буфер, чтобы не было overflow
#define MY_TIMEOUT_MS 120            // увеличить gap-таймаут, чтобы два кадра склеились в один
#define MY_TOLERANCE_PERCENT 30      // допускаем разброс длительностей

IRrecv irrecv(IR_PIN_IN, MY_CAPTURE_BUFFER_SIZE, MY_TIMEOUT_MS, true);
decode_results results;

// Метод инициализации ИК приемника
void initialIrConsumer() {
  irrecv.setTolerance(MY_TOLERANCE_PERCENT);
  irrecv.enableIRIn();

  Serial.println(F("IR capture ready."));
  Serial.printf("Buffer=%u, Timeout=%u ms, Tolerance=%u%%\n",
                MY_CAPTURE_BUFFER_SIZE, MY_TIMEOUT_MS, MY_TOLERANCE_PERCENT);
}

// Метод получения сигнала с ИК приемника
void getIrSignal() {
  if (irrecv.decode(&results)) {
    ledOn("red");
    // Полная сводка + исходник массива (удобно сразу вставлять в код отправки)
    Serial.println(resultToHumanReadableBasic(&results));
    Serial.println(resultToSourceCode(&results));

    if (results.overflow) {
      Serial.println(F("WARNING: capture buffer overflow! Увеличьте CAPTURE_BUFFER_SIZE."));
    }
    Serial.println();
    irrecv.resume();
    ledOff();
  }
}