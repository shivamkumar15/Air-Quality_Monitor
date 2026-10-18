# Indoor Air Quality Monitoring System

An Arduino Uno-based project that monitors indoor environmental conditions using gas, temperature, and humidity sensors. The system displays sensor readings on an LCD and provides visual and audible alerts when the gas sensor reading exceeds a configurable threshold.

## Features

- **Gas Detection:** Uses the MQ135 gas sensor to detect changes in the presence of certain gases and air contaminants.
- **Temperature Monitoring:** Uses the DHT11 sensor to measure temperature.
- **Humidity Monitoring:** Measures relative humidity using the DHT11 sensor.
- **LCD Display:** Displays gas sensor readings, temperature, humidity, and alert status on a 16x2 LCD.
- **Visual Alert:** Activates a red LED when the gas sensor reading crosses a configured threshold.
- **Audible Alert:** Activates a buzzer when the gas threshold is crossed.

## Hardware Requirements

- Arduino Uno
- MQ135 gas sensor module
- DHT11 temperature and humidity sensor
- 16x2 LCD with I2C adapter
- 1 red LED
- Active 3-pin buzzer module
- Breadboard
- Jumper wires
- 220–330 ohm resistor for a bare LED
- USB cable for programming and power

## Pin Connections

| Component | Pin | Arduino Uno |
|---|---|---|
| MQ135 | AO | A0 |
| MQ135 | VCC | 5V |
| MQ135 | GND | GND |
| DHT11 | DATA | D2 |
| DHT11 | VCC | 5V |
| DHT11 | GND | GND |
| I2C LCD | SDA | A4 |
| I2C LCD | SCL | A5 |
| I2C LCD | VCC | 5V |
| I2C LCD | GND | GND |
| Red LED | Anode (+), through resistor | D7 |
| Red LED | Cathode (-) | GND |
| Active buzzer | I/O | D8 |

**Note:** These connections assume a DHT11 module, an I2C LCD, and a compatible 3-pin buzzer module. Check the labels on your actual components before powering the circuit. All components must share a common ground.

## Software Requirements

- Arduino IDE
- Arduino AVR Boards package
- Adafruit DHT sensor library
- Adafruit Unified Sensor library
- Compatible LiquidCrystal_I2C library

The MQ135 sensor can be read using Arduino's built-in analog input functions.

## How It Works

1. The MQ135 produces an analog signal that changes in response to certain gases.
2. The Arduino reads the sensor's analog value and compares it with a configurable threshold.
3. The DHT11 measures the surrounding temperature and relative humidity.
4. The LCD displays the gas sensor reading, temperature, humidity, and alert status.
5. If the gas sensor reading crosses the configured threshold, the red LED and buzzer activate.
6. When the reading falls below the threshold, the LED and buzzer turn off.

## Setup Instructions

1. Clone or download this repository.
2. Install the required libraries using the Arduino IDE Library Manager.
3. Connect the components according to the pin connection table.
4. Open the Arduino `.ino` sketch.
5. Select **Arduino Uno** under Tools > Board.
6. Select the correct serial port.
7. Verify and upload the sketch.
8. Open the Serial Monitor at the baud rate configured in the code to view sensor readings.
9. Adjust the gas threshold based on observed readings and testing.

## Configuration

The gas alert threshold is configured in the Arduino sketch.

- **Gas threshold:** Determines when the red LED and buzzer activate. Select a suitable demonstration threshold after observing the sensor's baseline and response.

The MQ135 needs warm-up and calibration for meaningful measurements. Its raw analog reading should not be interpreted directly as a certified air-quality value.

## Limitations and Safety

- The MQ135 requires warm-up and calibration.
- Raw MQ135 readings are not a certified Air Quality Index (AQI), CO2 concentration, or PM2.5 measurement.
- This project is an educational prototype and must not replace certified air-quality monitoring or safety equipment.
- The MQ135 heater becomes warm during operation.
- Bare LEDs require current-limiting resistors.
- Disconnect the Arduino from USB before changing circuit connections.

## Future Improvements

- Add data logging using an SD card.
- Add wireless monitoring using an ESP8266 or ESP32.
- Display historical sensor readings on a computer dashboard.
- Improve sensor calibration and measurement accuracy.
- Add an enclosure for a cleaner final presentation.

## Project Purpose

This project demonstrates embedded systems, sensor interfacing, analog and digital input/output, LCD communication, environmental monitoring, and threshold-based alert systems using an Arduino Uno.
