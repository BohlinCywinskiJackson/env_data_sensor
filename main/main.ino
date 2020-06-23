/* BCJ Indoor Environment Data Sensor

  YEAR:
    2020

  CONTRIBUTORS:
    David Kitchen <dkitchen@bcj.com>
    Doug Speckhard <dspeckhard@bcj.com>
    Jon Szczesniak <jszczesniak@bcj.com>

  This sketch is for the indoor environmental data sensors developed by those listed above.

  This device is designed to run on a Wemos D1 Mini controller and transfer data to a RaspberryPi data collector via MQTT.
  It is designed to be campatible with the following sensors:
    BH1750 - Illuminance sensor
    DS18B20 - Temperature sensor used to calculate MRT (mean radiant temperature)
    DHT111 - Humidity sensor
    MAX4466 - Sound level sensor

  License: xxx
*/

/* LIBRARIES */
#include <config.h>     // External configuration information
#include <arduino.h>
#include <Wire.h>       // Library for OneWire 12C devices
#include <BH1750.h>
#include <DHT.h>


/* USER CONFIG */
// sensorID will need to be reviewed and set based on the number of sensor stations being deployed at an installation
int sensorID = 1;                   // GUID for the sensor stations (default = 1)

// global variables for calculating MRT
const double gtDia = 0.04;          // diameter of globe thermometer housing in m (default = 0.04 for ping-pong ball )
const double gtEmissivity = 0.97;   // emissivity of globe themometer housing (default = 0.97 for krylon ultra flat black)
// See https://www.infrared-thermography.com/material-1.htm for emissivity information

// global variables for WiFi >> may be better just to pull them from config.h
const char* wifiSSID = "";
const char* wifiPWD = "";


/* PIN ASSIGNMENTS AND DEFINITIONS */
// DHT11
#define DHTPIN D4
#define DHTTYPE DHT11


/* INITIALIZATIONS */
BH1750 lightMeter;
DHT dht(DHTPIN, DHTTYPE);


/* DYNAMIC VARIABLE ASSIGNMENTS */
double lux = 0;
double hum = 0;
double tempC = 0;
double tempF = 0;

int errCounter = 0;    // Counter to restart device upon collected errors


/* FUNCTIONS */
/* CHECK FOR READ ERRORS */
void checkSensor(x) {
  if (isnan(x)) {
    errCounter++;
  else {
    return x;
  }
  }
}
/* READ SENSORS */
void readSensors() {
  // ILLUMINATION SENSOR
  if (isnan(lightMeter.readLightLevel())) {
    Serial.println("[ERROR] FAILED TO READ FROM LIGHT SENSOR")
    errCounter++;
  } else {
    lux = lightMeter.readLightLevel();
  }

  // HUMIDITY SENSOR
  if (isnan(dht.readHumidity()) || isnan(dht.readTemperature()) {
    Serial.println("[ERROR] FAILED TO READ FROM TEMP/HUMIDITY SENSOR");
    errCounter++;
  } else {
    hum = dht.readHumidity();
    tempC = dht.readTemperature();
    tempF = dht.readTemperature(true);
  }

  // MRT (MEAN RADIANT TEMPERATURE) SENSOR

  // SOUND LEVEL SENSOR
}


/* FORMAT AND SEND DATA */
void sendData() {
  // FORMAT DATA
  // SETUP MQTT CONNECTION
  // SEND PAYLOAD
}


void restartDevice() {
  // GRACEFULLY SHUT DOWN DEVICE IF ERROR > 5 times
  if (errCounter > 5) {
    ESP.restart();
  }
}


/* SETUP */
void setup() {
  // SET PINMODES
  // SETUP WIFI

  Wire.begin();       // BEGIN I2C CONNECTIONS
  lightMeter.begin(); // BEGIN ILLUMINATION SENSOR
  dht.begin();        // BEGIN HUMIDITY SENSOR
}


/* MAIN LOOP */
void loop() {
  // SENSORS READINGS CYCLE
  readSensors();
  // CHECK WIFI STATUS
  // SEND DATA CYCLE
  sendData();
  // CHECK ERRCOUNT AND RESTART IF NECESSARY
  restartDevice();
}
