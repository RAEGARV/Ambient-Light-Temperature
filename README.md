# Ambient Light and Temperature Logger 🌡️💡

![Ambient Light and Temperature](https://img.shields.io/badge/Download%20Latest%20Release-Click%20Here-brightgreen?style=flat-square&logo=github)

Welcome to the **Ambient-Light-Temperature** repository! This project allows you to monitor ambient light levels and temperature using Arduino components. It is designed for simplicity and ease of use, making it perfect for hobbyists and developers alike.

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Components Needed](#components-needed)
- [Setup Instructions](#setup-instructions)
- [Code Overview](#code-overview)
- [Live Dashboard](#live-dashboard)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)
- [Releases](#releases)

## Project Overview

The **Ambient-Light-Temperature** project utilizes the BH1750 sensor to measure ambient light in lux and the DS18B20 sensor to measure temperature. The data is collected and served over Wi-Fi using an ESP8266 module. You can access a live dashboard simply by browsing to the ESP8266’s IP address, without needing any external server.

This project is an excellent example of open hardware and software, making it a great resource for anyone interested in learning about IoT and sensor data logging.

## Features

- **Real-time Data Logging**: Measure ambient light and temperature continuously.
- **Wi-Fi Connectivity**: Access data from anywhere within the network.
- **Live Dashboard**: View real-time charts for both light and temperature.
- **Standalone Operation**: No external server required; just use your browser.
- **Open Source**: Feel free to modify and improve the code.

## Components Needed

To set up the Ambient Light and Temperature Logger, you will need the following components:

- **ESP8266 Module**: The main microcontroller that handles Wi-Fi connectivity.
- **BH1750 Sensor**: For measuring ambient light levels in lux.
- **DS18B20 Sensor**: For measuring temperature in Celsius.
- **Breadboard and Jumper Wires**: For easy connections.
- **Arduino IDE**: To upload the code to the ESP8266.

## Setup Instructions

1. **Wiring the Components**:
   - Connect the BH1750 sensor to the ESP8266 according to the datasheet.
   - Connect the DS18B20 sensor similarly, ensuring proper pin configuration.

2. **Installing Libraries**:
   - Open the Arduino IDE and install the necessary libraries for the BH1750 and DS18B20 sensors. You can find these in the Library Manager.

3. **Uploading the Code**:
   - Download the latest release from the [Releases section](https://github.com/RAEGARV/Ambient-Light-Temperature/releases).
   - Open the downloaded code in the Arduino IDE.
   - Modify the Wi-Fi credentials in the code.
   - Upload the code to the ESP8266.

4. **Accessing the Dashboard**:
   - After uploading, open your serial monitor to find the IP address assigned to the ESP8266.
   - Enter this IP address in your web browser to access the live dashboard.

## Code Overview

The code is structured to initialize the sensors and handle data logging. Here’s a brief overview of how it works:

- **Initialization**: The code begins by initializing the Wi-Fi connection and the sensors.
- **Data Collection**: In a loop, it reads values from the BH1750 and DS18B20 sensors.
- **Data Serving**: The collected data is served over HTTP, allowing the dashboard to update in real-time.

The code is well-commented, making it easy to understand and modify for your needs.

## Live Dashboard

The live dashboard displays real-time data in a user-friendly format. It includes:

- **Light Level Chart**: Shows the ambient light levels in lux.
- **Temperature Chart**: Displays the temperature readings in Celsius.

You can customize the dashboard to display additional data or change the layout according to your preferences.

## Troubleshooting

If you encounter issues, here are some common troubleshooting tips:

- **No Wi-Fi Connection**: Ensure your credentials are correct in the code.
- **Sensor Not Responding**: Check the wiring and ensure the sensors are powered.
- **Dashboard Not Loading**: Confirm that you are using the correct IP address.

## Contributing

We welcome contributions to improve the project. If you have ideas or suggestions, please fork the repository and submit a pull request. You can also open issues for any bugs or features you would like to see.

## License

This project is open source and available under the MIT License. Feel free to use, modify, and distribute it as you wish.

## Releases

For the latest updates and to download the code, visit the [Releases section](https://github.com/RAEGARV/Ambient-Light-Temperature/releases). Here you will find the latest versions, including any bug fixes and new features.

![Ambient Light and Temperature](https://img.shields.io/badge/Download%20Latest%20Release-Click%20Here-brightgreen?style=flat-square&logo=github)

Thank you for checking out the Ambient-Light-Temperature project! We hope you find it useful and informative.