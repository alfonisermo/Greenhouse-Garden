void fan_temp_manager () {
    digitalWrite(tpwrPin, HIGH);
    delay(2); //let the thermistor warm up
    temperature = map(analogRead(tempPin), 0, 1023, 50, 100);
    delay(0); //make sure thermistor had time to be read?
    digitalWrite(tpwrPin, LOW);
  delay(1);
  if (temperature > fanOnTemp) {
    fanOnTime = millis();
    fanStatus = HIGH;
    digitalWrite(fanPin, fanStatus);
  } else {
//    if (DEBUG & ((millis() - lastDisplay) > displayDelay)) {
//      Serial.print("Temp = "); delay(2);
//      Serial.print(temperature); delay(2);
//      int countdown = (fanDelay - (millis() - fanOnTime)) / (double) SECOND;
//      if (countdown >= 0) {
//        Serial.print("; countdown = "); delay(4);
//        Serial.print(countdown); delay(4);
//        Serial.print(" seconds");
//      }
//      Serial.println();
//      lastDisplay = millis();
//    }
    if ((millis() - fanOnTime) > fanDelay) {
      fanStatus = LOW;
      digitalWrite(fanPin, fanStatus);
    }
  }
}

