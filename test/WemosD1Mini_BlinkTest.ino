// Jon Szczesniak
// Bohlin Cywinski Jackson

// Quick sanity tests on Wemos D1 mini connectivity from any given IDE.
// Useful to check against that new hardware isn't dead and/or that soldering headers onto the board didn't negatively affect the board's performance.
// You should be able to build then upload with only a USB connection.

// My initial tests were with PlatformIO in Atom Editor.
// I connected with the following settings my my .ini file
// [env:WemosD1Mini]
// board = d1_mini_pro
// framework = arduino
// platform = espressif8266
// upload_port = COMxx << replace xx with the assigned COM port in your device manager

#include <Arduino.h>

// Declares that we are talking to the on-board LED.
// You could alter this declaration to test out commands to other pinouts.
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

// The following will create a double-blink followed by a pause on LED.
// Adjust the delay to check to that various builds are working.
void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
}
