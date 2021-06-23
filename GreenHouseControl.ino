#include <dht11.h>
#define DHT11PIN 4
#define FAN1PIN 5
#define FAN2PIN 6

dht11 DHT11;
float threshold1 = 75.0; // Deg.Farenheight that fan1 is engaged
float threshold2 = 80.0; // Deg.Farenheight that fan2 is engaged
float temperatureC, temperatureF, humidity;
int fan1, fan2;


void setup()
{
  Serial.begin(9600);
  pinMode(FAN1PIN, OUTPUT);
  pinMode(FAN2PIN, OUTPUT);
  fan1 = LOW;
  fan2 = LOW;
  digitalWrite(FAN1PIN, LOW);
  digitalWrite(FAN2PIN, LOW);
  
  }

void loop()
{
  Serial.println();

  int chk = DHT11.read(DHT11PIN);

  humidity = (float)DHT11.humidity;
  temperatureC = (float)DHT11.temperature;
  temperatureF = temperatureC*9/5+32;

  Serial.print("Humidity (%): ");
  Serial.println(humidity, 0);

  Serial.print("Temperature (C): ");
  Serial.print(temperatureC, 2);
  Serial.print(" (F) ");
  Serial.println(temperatureF,0);


  if (temperatureF >= threshold1) {
    digitalWrite(FAN1PIN, HIGH);
    Serial.println("Fan1->ON"); 
    if (temperatureF >= threshold2) {
      digitalWrite(FAN2PIN, HIGH);
      Serial.println("Fan2->ON");
    } else {
      digitalWrite(FAN2PIN, LOW);
      Serial.println("Fan2->OFF");
    }
  } else {
    digitalWrite(FAN1PIN, LOW);
    digitalWrite(FAN2PIN, LOW);
    Serial.println("All Fans OFF");
  }
  
  delay(20000);

}
