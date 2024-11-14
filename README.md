# Arduino Weather Station with DHT11 and LCD1602

This project uses an **Arduino** to create a simple **Weather Station** that reads **temperature** and **humidity** using a **DHT11 sensor** and displays the data on a **16x2 LCD screen**. The data is also printed to the **Serial Monitor** for debugging purposes.

## Components Used
- **Arduino (Uno)**
- **DHT11 Temperature and Humidity Sensor**
- **16x2 LCD Display (Parallel Connection, No I2C)**
- **10kΩ Potentiometer** (for adjusting the LCD contrast)
- **Jumper Wires**
- **Breadboard** 

## Circuit Diagram
The circuit connects the **DHT11 sensor** and **16x2 LCD** to the Arduino. 

![Circuit Diagram](https://github.com/csabesan/WeatherStation/blob/master/weatherstation.jpg?raw=true)

### **DHT11 Sensor to Arduino:**
- **VCC** -> **5V** (Arduino)
- **GND** -> **GND** (Arduino)
- **DATA** -> **A0** (Arduino)

### **16x2 LCD to Arduino:**
| LCD Pin | Arduino Pin |
|---------|-------------|
| Pin 1 (VSS) | GND         |
| Pin 2 (VCC) | 5V          |
| Pin 3 (VO)  | Potentiometer (contrast) |
| Pin 4 (RS)  | Pin 12      |
| Pin 5 (RW)  | GND         |
| Pin 6 (EN)  | Pin 11      |
| Pin 11 (D4) | Pin 5       |
| Pin 12 (D5) | Pin 4       |
| Pin 13 (D6) | Pin 3       |
| Pin 14 (D7) | Pin 2       |
| Pin 15 (A)  | 5V (backlight) |
| Pin 16 (K)  | GND (backlight) |

---

