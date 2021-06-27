void irrigation_manager () {
    unsigned long timeSinceLastWatering = (millis() - valveOnTime[valveNbr]);

//  if (DEBUG && ((millis() - lastVDisplay) > displayDelay)) {
//    Serial.print(" Pin[");Serial.print(valvePin[valveNbr]);Serial.print("] ");
//    Serial.print("Valve(");
//    Serial.print(valveNbr);
//    Serial.print("); Drytime = ");
//    Serial.print(timeSinceLastWatering / SECOND);
//    Serial.print(" seconds, Status = ");
//    Serial.println(valveStatus[valveNbr]);
//    lastVDisplay = millis();
//  }

  if (timeSinceLastWatering > valveFrequency) {
    valveOnTime[valveNbr] = millis();
    if (DEBUG && (valveStatus[valveNbr] == LOW)) {
      Serial.print("Water(");
      Serial.print(valveNbr+1);
      Serial.println(") ON");
    }
    valveStatus[valveNbr] = HIGH;
    digitalWrite(valvePin[valveNbr], HIGH);
  }
  if (valveStatus[valveNbr] == HIGH) {
    if ((millis() - valveOnTime[valveNbr]) > valveDelay[valveNbr]) {
      valveStatus[valveNbr] = LOW;
      digitalWrite(valvePin[valveNbr], LOW);
      if (DEBUG) {
         Serial.print("Water(");
         Serial.print(valveNbr+1);
         Serial.println(") OFF\n");
      }
      valveNbr++;
      if (valveNbr > 2) {
        valveNbr = 0;
        lastWateringTime = millis();
      }
    }
  }
}

