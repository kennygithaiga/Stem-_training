bool start = false;
int startButton = A0;
int resetButton = A1;
int startLed = 5;
int alarm = 11;
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2     
#define DHTTYPE    DHT11   
DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600);
  dht.begin();
  sensor_t sensor;


  pinMode(alarm, OUTPUT);
  pinMode(startButton, INPUT_PULLUP);
  pinMode(resetButton, INPUT_PULLUP);
  pinMode(startLed, OUTPUT);

  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  if(!digitalRead(startButton)){
    start = true;
  }

  while(start){
    digitalWrite(startLed, HIGH);
    delay(delayMS);
    sensors_event_t event;

      if (isnan(event.temperature)) {
      Serial.println(F("Error reading temperature!"));
    }
    
    if (isnan(event.relative_humidity)) {
      Serial.println(F("Error reading humidity!"));
    }

    dht.temperature().getEvent(&event);
    int temperature = event.temperature;//°C

    dht.humidity().getEvent(&event);
    int humidity = event.relative_humidity;//%

    if (temperature >= 30 || humidity >= 70){
      digitalWrite(alarm, HIGH);
    }
    if (!digitalRead(resetButton)){
      digitalWrite(alarm, LOW);
      start = false;
    }
  }
  digitalWrite(startLed, LOW);
 

}
