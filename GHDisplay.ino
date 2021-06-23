void display_change_menu()
{
  Serial.println("---------------------------------------------------");
  Serial.println("CHANGE SETTINGS");
  Serial.println(" Sequence    Action");
  Serial.println("    Tnn      Set fan-on temp to nn degrees");
  Serial.println("    Whh      Set watering delay (hours)");
  Serial.println("    Vnsss    Set Valve(n) On duration (seconds)");
  Serial.println("    R        Reset timers and default settings.");
  Serial.println("    X        Exit Change Menu");
  Serial.println();
  display_greenhouse_time();
  Serial.println("> ");
}
void display_help() {
  Serial.println("---------------------------------------------------");
  Serial.println("Welcome to the Greenhouse's Brain");
  Serial.println("Many settings are customizeable via serial input");
  Serial.println("Commands I can respond to are:");
  Serial.println(" Keystroke   Action");
  Serial.println("    ?        Help - displays these instructions");
  Serial.println("    S        Display Current Settings");
  Serial.println("    C        Enter Change-Settings Menu");
  Serial.println("    D        Toggle Debug output flag");
  Serial.println("    R        Reset timers and default settings.");
  Serial.println("    T        Run through Test Cycle");
  Serial.println();
  display_greenhouse_time();
  Serial.println("> ");
}
void display_greenhouse_time() {
  unsigned long currentClock = millis();
  int currentHour   = currentClock / HOUR;
  int currentMinute = (currentClock % (long) HOUR) / MINUTE;
  int currentSecond = ((currentClock % (long) HOUR) % (long) MINUTE) / (long) SECOND;
  Serial.print("Greenhouse Time - ");
  if (currentHour   < 10) {Serial.print("0");} Serial.print(currentHour);   Serial.print(":");
  if (currentMinute < 10) {Serial.print("0");} Serial.print(currentMinute); Serial.print(":");
  if (currentSecond < 10) {Serial.print("0");} Serial.print(currentSecond); Serial.print(" ");
}

void display_greenhouse_settings() {
  // current temperature
  // Fan start temp
  // Fan delay-off (seconds)
  // Time between waterings (hours)
  // ValveOpenTimes(1..3) (seconds)
  Serial.println("--------------- SETTINGS ---------------------");
  display_greenhouse_time();
  Serial.print("Temperature: "); Serial.println(temperature);
  
  Serial.print("Fans start at "); Serial.print(fanOnTemp); Serial.print(" degrees for minimum ");
  Serial.print(fanDelay / SECOND); Serial.print(" seconds. Status: ");
  if (fanStatus) {Serial.println("ON");
  }else{          Serial.println("OFF"); }
  
  Serial.print("Water every "); Serial.print(valveFrequency / HOUR);Serial.println(" hours.");
  
  for (int i=0;i<3;i++) {
    Serial.print("Valve(");Serial.print(i+1);Serial.print(") ");
    if (valveStatus[i]) {Serial.print("ON  ");} else {Serial.print("OFF ");}
    Serial.print(" open time - ");Serial.print(valveDelay[i] / SECOND);Serial.println(" seconds.");
  }
}

