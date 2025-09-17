IRsend irsend(IR_PIN_OUT);

void initialIrProducer(){
   irsend.begin();
  pinMode(RBUTTON_A, INPUT);
  pinMode(RBUTTON_B, INPUT);
  pinMode(RBUTTON_C, INPUT);
  pinMode(RBUTTON_D, INPUT);
}

void irProducerControl(){
  if (digitalRead(RBUTTON_A) == HIGH) {
    Serial.println("RF command: ON → Sending IR ON state...");
    irsend.sendRaw(cold163, sizeof(cold163) / sizeof(cold163[0]), 38);
    delay(500);
  }
  if (digitalRead(RBUTTON_B) == HIGH) {
    Serial.println("RF command: OFF → Sending IR OFF state...");
    irsend.sendRaw(cold163Time2, sizeof(cold163Time2) / sizeof(cold163Time2[0]), 38);
    delay(500);
  }
   if (digitalRead(RBUTTON_C) == HIGH) {
    irsend.sendRaw(hot303, sizeof(hot303) / sizeof(hot303[0]), 38);
    delay(500);
  }
  if (digitalRead(RBUTTON_D) == HIGH) {
    irsend.sendRaw(AcOff, sizeof(AcOff) / sizeof(AcOff[0]), 38);
    delay(500);
  }
}