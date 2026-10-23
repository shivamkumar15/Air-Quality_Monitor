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

This project demonstrates embedded systems, sensor interfacing, analog and digital input/output, LCD communication, environmental monitoring, and threshold-based alert systems using an Arduino Uno.
