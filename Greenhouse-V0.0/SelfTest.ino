void run_self_test () {
// cycle == (off 1 sec, on 5 sec, off)
// cycle fan
  Serial.println("TEST1: Run fan 5 seconds");
  digitalWrite(fanPin, LOW);
  delay(1000);
  digitalWrite(fanPin, HIGH);
  delay(5000);
  digitalWrite(fanPin,LOW);

  //cycle water valves
  for (valveNbr = 0; valveNbr < 3; valveNbr++) {
    Serial.print("TEST");Serial.print(valveNbr+2);
    Serial.print(": Open valve ");Serial.print(valveNbr+1);
    Serial.println(" for 5 seconds");
    digitalWrite(valvePin[valveNbr], LOW);
    delay(1000);
    digitalWrite(valvePin[valveNbr], HIGH);
    delay(5000);
    digitalWrite(valvePin[valveNbr], LOW);
  }
  
  //test cycle completed, reset devices to operational status
  Serial.println("Self-test completed, returning to operational status");
  digitalWrite(fanPin, fanStatus);
  for (valveNbr = 0; valveNbr < 3; valveNbr++) {
    digitalWrite(valvePin[valveNbr],valveStatus[valveNbr]);
  }
}

