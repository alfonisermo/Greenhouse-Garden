void serial_manager() {
  if (Serial.available() > 0) {
    byte inByte = Serial.read();

    if (menuOn) { // if Change Menu is active
      process_change_menu(inByte);
    } else {
      // main commands menu
      switch (inByte) {
        case 'T' :
        case 't' : run_self_test(); break;
        case 'R' :
        case 'r' : initialize(); display_greenhouse_settings(); break;
        case '?' : case '/' : case 'h' :
        case 'H' : display_help(); break;
        case 's' :
        case 'S' : display_greenhouse_settings(); break;
        case 'c' :
        case 'C' : menuOn = 1; //set Change menu try
          // initialize Change menu flags/vars
          menuTemp = 0; menuFreq = 0; menuValv = 0; valvSel = 0;
          decimalOn = 0; divisor = 1;
          display_change_menu(); break;
        case 'd' :
        case 'D' : if (DEBUG) {
            DEBUG = 0; Serial.println("DEBUG OFF");
          } else {
            DEBUG = 1; Serial.println("DEBUG ON");
          } break;
        default : process_change_menu(inByte);
      }
    }
  }
}

void process_change_menu(byte inByte) {
  // process menu sub-commands here
  switch (inByte) {
    case 't' :  case 'T' :
      menuTemp = 1; menuFreq = 0; menuValv = 0;
      newTemp = 0; decimalOn = 0;
      break;
    case 'W': case 'w' :
      menuFreq = 1; menuTemp = 0; menuValv = 0;
      newFreq = 0; decimalOn = 0;
      break;
    case 'v' : case 'V' :
      menuValv = 1; menuFreq = 0; menuTemp = 0;
      valvSel = 0; //no valve selected yet;
      newValv = 0; decimalOn = 0;
      break;
    case 'x' : case 'X' :
      menuTemp = 0;  menuFreq = 0;  menuValv = 0;
      menuOn   = 0; //exit menu
      display_greenhouse_settings();
      break;
    default: process_numeric(inByte);
    break;
  }
}
void process_numeric(byte inByte) {
  switch(inByte) {
    case '.': decimalOn = 1;
      divisor = 1;
      if (DEBUG) {
        Serial.println("Decimals on");
      }
      break;
    case '0': case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9':
      int inDigit = inByte - 48;
      if (decimalOn) {
        divisor = divisor * 10;
      }
      if (DEBUG) {
        Serial.print("Digit:");
        Serial.print(inDigit);
        if (decimalOn) {
          Serial.print("/");
          Serial.print((int)divisor);
        }
        Serial.println();
      }
      if (menuTemp) {
        if (decimalOn) {
          newTemp = newTemp + (inDigit / divisor);
        } else {
          newTemp = (10 * newTemp) + inDigit;
        }
        Serial.print("Fantemp = "); Serial.println(newTemp);
        fanOnTemp = newTemp;
      }
      if (menuFreq) {
        if (decimalOn) {
          newFreq = newFreq + ((float) inDigit / divisor);
        } else {
          newFreq = (10 * newFreq) + inDigit;
        }
        Serial.print("Watering cycle = "); Serial.print(newFreq); Serial.println(" hours");
        valveFrequency = newFreq * HOUR;
      }
      if (menuValv) {
        if (valvSel) {
          if (decimalOn) {
            newValv = newValv + (inDigit / divisor);
          } else {
            newValv = (newValv * 10) + inDigit;
          }
          Serial.print("Valve("); Serial.print(valvSel);
          Serial.print(") open time "); Serial.print(newValv);
          Serial.println(" seconds");
          valveDelay[valvSel - 1] = newValv * SECOND;
        } else {
          valvSel = inDigit;
        }
      }
      break;
  }
}

