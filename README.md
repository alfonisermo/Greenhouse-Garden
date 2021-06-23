# Greenhouse-Garden
### Arduino-controlled Plant/Pot watering timers for mini-greenhouse and outdoor hanging pots.
#### My first foray (Branch labeled GH-Renton V0.1) was a watering and fan controller for a portable greenhouse, there's a video somewhere (needs link)
#### Second start on this project (also needs checkin) is for a larger greenhouse. Starting with two donated 12V lead-acid batteries, a Zamp Solar Panel w/ charge controller, a (brand-x) Charge/Discharge Controller, DHT11 temp/humidity sensor and some Relays for some higher power switching, we're gonna try to keep the solarium from getting higher than specified temps. This simple fan switches needs to be merged with v0.1 conceptually.
#####   After the fans, I hope to add connection to in-house wifi, data logging either on-board or on a local web service-like service, watering, yadda yadda dreams.
/*  Control greenhouse

1. Cooling fan(s)

        a. Fan-on threshold temp
        b. Fan-off delay
        extensions.. c. fan-speed?

2. Watering

        a. Watering times (hours between)
        b. 3-Valve, sequential operation
        c. independent valve-open delays
        extensions..  Misters? added complexity with pressure pump, maybe

3. extensions: 

        a. Bed Heater

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

6. Extensions

        a. sync greenhouse time to Pacific Time

*/   
