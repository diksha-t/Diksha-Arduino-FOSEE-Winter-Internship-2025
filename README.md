# Diksha-Arduino-FOSEE-Winter-Internship-2025
Task 1
*IR Sensor LED Trigger + MPU6050 Servo Control + OLED Display*

This project uses an IR obstacle sensor to trigger an LED and an MPU6050 accelerometer to control a servo motor.  
All sensor values are displayed on both the Serial Monitor and a 0.96" I2C OLED display.

*Features*
1. IR sensor detects objects and activates an LED.  
2. Supports both active-low and active-high IR sensor modules.  
3. MPU6050 reads X-axis acceleration and maps it to servo rotation.  
4. Real-time values are shown on Serial Monitor and OLED.  
5. Works on standard Arduino boards such as Uno or Nano.

*Components Required*
- Arduino Uno or Nano  
- IR obstacle sensor  
- Servo motor (SG90 or similar)  
- MPU6050 sensor  
- OLED display (SSD1306, I2C)  
- LED with 220 ohm resistor  
- Breadboard and jumper wires

## Wiring
IR Sensor  
IR VCC to 5V  
IR GND to GND  
IR OUT to D2  

## LED  
D13 to LED long leg  
LED short leg to 220-ohm resistor  
Resistor to GND  

## Servo  
Signal to D9  
VCC to 5V  
GND to GND  

## MPU6050  
VCC to 5V  
GND to GND  
SDA to A4  
SCL to A5  

## OLED  
VCC to 5V  
GND to GND  
SDA to A4  
SCL to A5  

- Both MPU6050 and OLED share the same I2C lines (A4 and A5).

*Code Behavior*
- IR Sensor  
- The Arduino reads the IR sensor output on D2.  
- If an object is detected, the LED on pin 13 is turned on.  
- The system also prints the IR state to the Serial Monitor and displays it on the OLED.

## MPU6050  
- Accelerometer values are updated continuously.  
- The X-axis value is scaled and mapped to a servo angle from 0 to 180 degrees.  
- The servo position depends on the tilt of the MPU6050.

## OLED Display  
- The OLED shows the IR detection status, the raw IR input reading, accelerometer values, and the current servo angle.
