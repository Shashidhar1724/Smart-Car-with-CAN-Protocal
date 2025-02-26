# CAN Protocol with Arduino Uno and MCP2515 module

This project demonstrates how to use the CAN protocol with an Arduino Uno, MCP2515 CAN Bus Module, DHT sensor (temperature and humidity sensor),Gas sensor(To check quality of air) ,Water Sensor(To check Fuel Quantity),LDR Sensor (For automatic working of Lights of car) and I2C LCD display. The system reads the temperature and humidity from the DHT sensor and sends this data over the CAN bus to other devices, while displaying the current readings on the LCD.

**Components Used**
 - Arduino Uno: Microcontroller for controlling the project.
 - MCP2515 CAN Bus Module: CAN transceiver to send and receive CAN messages.
 - DHT11 or DHT22 Sensor: Measures temperature and humidity.
 - MQ 5 Gas Sensor: Measures the presence of CO2.
 - SEN18 Water Sensor: Measures the quantity of Water.
 - LDR Sensor: Operates on the basis of light rays.
 - I2C LCD Display: Displays the temperature and humidity readings.
 - Jumper Wires: For connections.
 - Breadboard: For connecting components.
 - Power Supply: Typically USB power for Arduino Uno

   
**Features**
 - CAN Communication: Transmits temperature and humidity data via the CAN bus.
 - Sensor DataS: Reads temperature and humidity from the DHT sensor , Reads presence of Co2(air Quality) from MQ 5 Gas sensor, Measures the capacity of fuel from SEN18 sensor, LDR Sensor responses to the change in intensity of light .
 - Real-time Display: Displays current temperature and humidity, Fuel capacity, Air Quality  on an I2C LCD.
 - Modular Design: Easily expand the project to include more sensors or devices communicating over the CAN bus.

**Circuit Diagram**

![Circuit Diagram](circuit-diagram1.jpg)

**Wiring**


**1. MCP2515 CAN Bus Module to Arduino Uno**
 - VCC -> 5V (Arduino Uno)
 - GND -> GND (Arduino Uno)
 - CS -> Pin 10 (Arduino Uno)
 - SCK -> Pin 13 (Arduino Uno)
 - MOSI -> Pin 11 (Arduino Uno)
 - MISO -> Pin 12 (Arduino Uno)
 - INT -> Pin 2 (Arduino Uno)

   
**2. DHT11/DHT22 Sensor to Arduino Uno**
 - VCC -> 5V (Arduino Uno)
 - GND -> GND (Arduino Uno)
 - Data -> Pin 4 (Arduino Uno)

**3. MQ 5 Sensor to Arduino Uno**
 - VCC -> 5V (Arduino Uno)
 - GND -> GND (Arduino Uno)
 - Data -> Pin A0 (Arduino Uno)   

**4. SEN18 Sensor to Arduino Uno**
 - VCC -> 5V (Arduino Uno)
 - GND -> GND (Arduino Uno)
 - Data -> Pin A1 (Arduino Uno)

**5. LDR Sensor to Arduino Uno**
 - VCC -> 5V (Arduino Uno)
 - GND -> GND (Arduino Uno)
 - Data -> Pin 3 (Arduino Uno)

**6. First I2C LCD to Arduino Uno**
 - VCC -> 5V (Arduino Uno)
 - GND -> GND (Arduino Uno)
 - SDA -> SDA (Arduino Uno)
 - SCL -> SCL (Arduino Uno)

**7. Second I2C LCD to Arduino Uno**
 - VCC -> 5V (Arduino Uno)
 - GND -> GND (Arduino Uno)
 - SDA -> A4 (Arduino Uno)
 - SCL -> A5 (Arduino Uno)

**Libraries Used**
 - mcp2515: For interfacing with the MCP2515 CAN Bus module.
 - DHT Sensor Library: For reading data from the DHT sensor.
 - LiquidCrystal_I2C: For controlling the I2C LCD display.

**Code Overview**
This project reads data from the DHT sensor, MQ5 gas sensor, LDR sensor, SEN18 water sensor formats it into a CAN message, and sends it over the CAN bus. Additionally, it displays the temperature, humidity, air quality, light intensity, fuel capacity readings on the I2C LCD 
