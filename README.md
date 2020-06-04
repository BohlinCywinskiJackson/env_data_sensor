# BCJ (Updated) version of the PODD, Post-Occupancy Data Device

At a high-level, the original PODD was created using a full arduino with a wireless shield.
At this point, we are likely able to get the entire device into a smaller form-factor as well all as capture more information and transfer it more efficiently.

The goal would be to use a single board computer - SBC (a Wemos D1 which is a variant of the ESP8266 is the first hypothesis) - in lieu of a full arduino board.
The ESP8266 is a smaller package than a full arduino but uses the same arduino langauge (C++).
This would allow the project to be able to leverage the existing work where available.
We may need to pivot over to the ESP32 if we find that we are running out of GPIO pins on the Wemos Mini.

The new SBCs also has the ability to communicate via onboard WiFi.
This should allow us to run and MQTT broker on a remote device to capture transfered data samples.
The MQTT broker could be as simple as a Raspberry Pi that would then connect to ANY NUMBER of these devices.

This allows everything to be extremely portable and it could isolated onto its own network.

**Make sure to see the OneNote Notebook posted to the Teams channel for additional information**

TODO:
[ ] A much better description of the project is in order
