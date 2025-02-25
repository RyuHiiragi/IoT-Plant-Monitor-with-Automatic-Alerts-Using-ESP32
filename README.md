# IoT Plant Monitor with Automatic Alerts Using ESP32

This repository contains the Arduino code, configuration, and assembly instructions for building an IoT-based plant monitoring system using the ESP32 microcontroller. The system monitors environmental conditions such as soil moisture, temperature, humidity, and light intensity, and sends automatic alerts if the conditions require attention <button class="citation-flag" data-index="8">. This project is ideal for smart gardening, agriculture, or home automation applications.

---

## Table of Contents
1. [Overview](#overview)
2. [Components Used](#components-used)
3. [System Dimensions](#system-dimensions)
4. [Assembly Instructions](#assembly-instructions)
5. [Arduino Code Explanation](#arduino-code-explanation)
6. [Contributing](#contributing)
7. [License](#license)

---

## Overview
The IoT plant monitor uses the ESP32 to collect data from various sensors, including soil moisture, temperature, humidity, and light intensity. If any parameter exceeds predefined thresholds, the system triggers an alert using a buzzer and LED indicators. Additionally, the data is sent to an online platform like Blynk for remote monitoring <button class="citation-flag" data-index="6">. This project helps users maintain optimal growing conditions for their plants.

---

## Components Used
To build this IoT plant monitor, you will need the following components:
- **ESP32 Development Board**
- **Capacitive Soil Moisture Sensor**
- **DHT22 Temperature and Humidity Sensor**
- **BH1750 Light Sensor**
- **Active Buzzer**
- **Red LED**
- **Green LED**
- **220Ω Resistors**
- **Jumper Wires**
- **Breadboard (Optional)**

---

## System Dimensions
For an ideal IoT plant monitor:
- **Height**: 10–15 cm
- **Width**: 10–15 cm
- **Length**: 10–15 cm

These dimensions ensure that the system is compact yet spacious enough to house all components.

---

## Assembly Instructions
Follow these detailed steps to assemble your IoT plant monitor:

1. Connect the soil moisture sensor to the ESP32 for measuring soil moisture levels.
2. Connect the DHT22 sensor to monitor temperature and humidity <button class="citation-flag" data-index="8">.
3. Connect the BH1750 light sensor to measure ambient light intensity <button class="citation-flag" data-index="9">.
4. Connect the buzzer and LEDs to provide audible and visual alerts.
5. Power the system using a USB cable.
6. Secure all components inside a protective enclosure.

---

## Arduino Code Explanation
The provided Arduino code reads data from the sensors and sends it to the Blynk platform for remote monitoring. The code also checks predefined thresholds for each parameter and triggers alerts if conditions are abnormal. Alerts are indicated using a buzzer and LED indicators.

---

## Contributing
Feel free to fork this repository and contribute improvements or new features. If you have suggestions or find bugs, please open an issue.

---

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

By following this guide, you should be able to build and test your own IoT plant monitor using the ESP32. Happy tinkering! 🚀
