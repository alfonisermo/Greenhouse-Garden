void setup() {
  Serial.begin(9600);
  fanStatus = LOW;
  pinMode(fanPin, OUTPUT);
  pinMode(tpwrPin, OUTPUT);

  initialize();
  run_self_test();
}

void initialize() {
  digitalWrite(fanPin, LOW);
  digitalWrite(tpwrPin, LOW);

  lastWateringTime = 0;
  fanOnTemp = 75;                       //Threshold temp for turning on fan
  fanDelay = MINUTE;                    //Minimum fan-on time
  valveFrequency = HOUR * 12;          //Time between waterings

  DEBUG = 0;
  lastDisplay = 0;
  lastVDisplay = 0;
  displayDelay = SECOND;

  // Input Command Tokenizer
  menuOn = 0;
  menuTemp = 0; newTemp = 0;
  menuFreq = 0; newFreq = 0;
  menuValv = 0; valvSel = 0; newValv = 0;
  decimalOn; divisor = 1;


  for (valveNbr = 0; valveNbr < 3; valveNbr++) {
    valveStatus[valveNbr] = LOW;
    valveOnTime[valveNbr] = 0;
    pinMode(valvePin[valveNbr], OUTPUT);
    digitalWrite(valvePin[valveNbr], LOW);
    valveDelay[valveNbr] = MINUTE / 2;  //Valve-open time
  }
  menuOn = 0;
  valveNbr = 0;
  display_help();
}

