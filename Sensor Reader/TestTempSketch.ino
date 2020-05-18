#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define ONE_WIRE_BUS 12 //defining wire for one wire temperature sensor
#define HumPin 2 //defining humidity data wire
#define DHTTYPE DHT11 //defining sensor type
 
OneWire oneWire(ONE_WIRE_BUS); //starting the onewire 
DallasTemperature sensors(&oneWire); //starting Dallastemperature reading from one wire
DHT dht(HumPin, DHTTYPE); //start DHT sensor (humidity sensor)

void setup() {
  Serial.begin(9600); 
  dht.begin(); //start the sensor for humidity
  sensors.begin(); //start for temperature
}

void loop() {
  float t = sensors.getTempFByIndex(0); //gets temperature
  float h = dht.readHumidity(); //gets the humidity
  String temp = String(t) + "°F"; //everything after this is just for testing and getting it to read out on my computer
  String hum = String(h) + "%";
  Serial.print(temp);
  Serial.print(" ");
  Serial.print(hum);
  Serial.print('\n');
  delay(1000);

}
