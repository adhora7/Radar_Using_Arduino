# Radar_Using_Arduino


**Project Overview**:
This project demonstrates a **Radar using Arduino** with an ultrasonic sensor and a servo motor. The servo motor sweeps from 0 to 180 degrees, and the ultrasonic sensor measures the distance at each angle. The data is then sent to a laptop where it is visualized in real-time as a radar-like display using the **Processing IDE**.

**Project Components**:
- **Arduino Board** (e.g., Arduino Uno or ESP32)
- **Servo Motor** (for rotating the sensor)
- **Ultrasonic Sensor** (for measuring distances)
- **Processing IDE** (for visualizing the radar data)
- **Laptop/PC** (to display the radar)
- **Breadboard and jumper wires**

## Working Principle

The ultrasonic sensor emits sound waves and measures the time it takes for the waves to return. This time is then converted into a distance. The servo motor rotates the sensor from 0 to 180 degrees, capturing distances at each angle. The data is sent to a laptop, where it is visualized as a radar sweep.

### System Diagram:
![Project Setup](./radar.jpg)

**Figure 1**: The setup shows the ultrasonic sensor and servo motor connected to the Arduino, with the radar visualization displayed on the laptop.

## Features:
- **Servo Motor Sweep**: The servo rotates from 0 to 180 degrees, collecting distance data at each position.
- **Radar Display**: The data is sent to the Processing IDE, creating a radar-style visualization.
- **Real-time Measurement**: The ultrasonic sensor continuously measures distances and updates the radar.

## Code Explanation:
The Arduino code controls the servo motor and the ultrasonic sensor. It sweeps the servo across 180 degrees and measures the distance at each angle. The distance data is sent via serial communication to a connected laptop, where it is visualized in real-time.

```cpp
// Code provided for controlling the servo motor and measuring distances with the ultrasonic sensor.

