/* BCJ Indoor Environment Data Sensor

  written by:

  This sketch is for the indoor environmental data sensors developed by the authors listed above.

  It is designed to run on a Wemos D1 Mini controller and transfer data to a data collector via MQTT.
  It is designed to be campatible with the following sensors:
    BH1750 - Illuminance sensor
    DS18B20 - Temperature sensor
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

/* PIN ASSIGNMENTS */

/* STATIC CONFIG */

/* VARIABLE ASSIGNMENTS */

/* FUNCTIONS */
/* READ SENSORS */
void readSensors() {
  // LIGHT SENSOR
  // GLOBAL TEMP SENSOR
  // HUMIDITY SENSOR
  // SOUND LEVEL SENSOR
}

/* FORMAT AND SEND DATA */
void sendData() {
  // FORMAT DATA
  // SETUP MQTT CONNECTION
  // SEND PAYLOAD
}

void resetDevice() {
  // GRACEFULLY SHUT DOWN DEVICE IF ERROR > 5 times
  if (resetCounter > 5) {
    ESP.restart();
  }
}


/* SETUP */
void setup() {
  // SET PINMODES
  // SETUP WIFI
  // BEGIN I2C CONNECTIONS
}


/* MAIN LOOP */
void loop() {
  // SENSORS READINGS CYCLE
  // SEND DATA CYCLE
  // CHECK WIFI STATUS
  // CHECK ERRCOUNT AND RESTART IF NECESSARY
}
