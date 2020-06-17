#include <arduino.h>
#include <BH1750.h>   // Library for illuminance module
#include <Wire.h>     // Library for OneWire I2C devices

/*****  WIRING *****/
// BH1750 >> Wemos
// VCC >> 3V3
// GND >> GND
// SCL >> D1 - This is the I2C SCL (clock) line
// SDA >> D2 - This is the I2C SDA (data) line
// ADD >> (not connected) - This will default the I2C address to 0x23

BH1750 lightMeter;

void setup(){
  Serial.begin(9600);
  Wire.begin();        // Initialize the I2C bus
  // I think that there is a way to specify a different SCL/SDA bus by using Wire.begin(D3, D4) or something like that
  lightMeter.begin();  // Initialize the BH1750 library
  // The default is to CONTINUOUS_HIGH_RES_MODE
  // See library examples for more information
  Serial.println("Running...");
}

void loop() {
  float lux = lightMeter.readLightLevel();  // Read light Level

  // Print results with formatting
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");

  delay(1000);   // repeat every second
}
