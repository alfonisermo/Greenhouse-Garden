

void setup() {
  // try to power Bluetooth Module on pinss 11/12
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
digitalWrite(11,LOW);  // Ground
digitalWrite(12,HIGH); // Vcc=5v
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(11,LOW);  // Ground
digitalWrite(12,HIGH); // Vcc=5v
}
