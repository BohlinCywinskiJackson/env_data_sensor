# MQTT Proposal

Much of the thought process behind the MQTT data transfer is taken from [this page](https://github.com/mqtt-smarthome/mqtt-smarthome/blob/master/Architecture.md).


## Heirarchy

MQTT is very flexible and allows for a variety of data structures.
In general, the basic structure is a JSON dictionary with the following setup:

```bash
topLevel / function / payload
```

The `topLevel` will be set to identify each of the sensor devices.

Since most of our data transfer will be one-directional (sensor collectors to the MQTT broker) we have very little use for a `set` function, and will mostly use the `state` function descriptor.

The item will be the sensor data collected for each location.


## Syntax Proposal

We will use the following MQTT topics:

```bash
sensorID / data / json      # to publish data in JSON format
sensorID / data / csv       # to publish data in CSV format
sensorID / status / alarm   # to publish alarms about failing sensors
```

## Example

Potential payload for `sensorID / data / json`

```json
{
  "sensorID": 1,
  "location": "main office",
  "captureDate": 20200623,
  "captureTime": 1207,
  "sensor": "humidity",
  "value": 70.40,
  "units": "%",
  }
```

Potential payload for `sensorID / data / csv`

```text
1,main office,20200623,1207,humidity,70.40,%
```
