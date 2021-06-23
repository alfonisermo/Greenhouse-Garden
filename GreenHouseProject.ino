
/*  Control greenhouse
     1. Cooling fan(s)
        a. Fan-on threshold temp
        b. Fan-off delay
        extensions.. c. fan-speed?
     2. Watering
        a. Watering times (hours between)
        b. 3-Valve, sequential operation
        b. independent valve-open delays
        extensions.. c. Misters?
     3. extensions: a. Bed Heater
     4. Input/Output
        a. respond to serial input
        b. display on serial output
        c. bluetooth
        extensions.. d. IoT (WiFi)
     5. Command features from 4+
        a. Display command/help page
        b. Display current system status
        EXTENSIONS
          c. Allow change of system parameters
          d. Display recent history (temp info, fancount,)
     6. Estensions
        a. sync greenhouse time to Pacific Time

*/
// Control Constants
const int  tempPin     = A0;
const int  tpwrPin     = 13;
const int  fanPin      = 12;
const int  valvePin[3] = {3, 4, 5};

const int    SECOND      = 100;  //milliseconds, smaller for speed-testing
const double MINUTE      = 60 * (double) SECOND;
const double HOUR        = 60 * MINUTE;
const double DAY         = 24 * HOUR;

// Operating Variables
int           temperature;
int           fanStatus;
unsigned long fanOnTime;
unsigned long lastWateringTime = 0;
int           valveNbr;
unsigned long valveOnTime[3];
int           valveStatus[3];

// Adjustable by input commands
int           fanOnTemp = 75;             //Threshold temp for turning on fan
unsigned long fanDelay = MINUTE;          //Minimum fan-on time
unsigned long valveFrequency = MINUTE * 4; //Time between waterings
unsigned long valveDelay[3];

// Output & slower-downer timers
bool DEBUG = 0;
unsigned long lastDisplay = 0;
unsigned long lastVDisplay = 0;
unsigned long displayDelay = SECOND;

// Input Command Tokenizer Variables
bool menuOn = 0;
bool menuTemp = 0; float newTemp = 0;
bool menuFreq = 0; float newFreq = 0;
bool menuValv = 0; int valvSel = 0; float newValv = 0;
bool decimalOn = 0; float divisor = 1;


void loop() {
  // Check temperature, start fan and delay timer if high
  fan_temp_manager();

  //manage watering
  irrigation_manager();

  // Manage input commands
  //    Settings Commands
  //    Report Commands
  serial_manager();
delay(500);
}
