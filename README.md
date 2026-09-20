# ESP8266 Blynk Wi-Fi Controlled Rover

A Wi-Fi controlled robotic rover built using an **ESP8266**, **L298N motor driver**, and **Blynk IoT**.

The rover can be controlled remotely through the Blynk mobile application. The ESP8266 receives commands through Wi-Fi and controls the direction and speed of two DC motors.

## Features

* Wi-Fi-based wireless control
* Forward and backward movement
* Left and right movement
* Adjustable motor speed
* Blynk mobile app control
* ESP8266-based control
* L298N motor driver

## Components Required

* ESP8266 NodeMCU
* L298N Motor Driver
* 4 × DC Motors
* Robot chassis
* Battery
* Jumper wires

## Software Used

* Arduino IDE
* Blynk IoT
* ESP8266 Board Package

## Pin Configuration

| ESP8266 Pin | Function             |
| ----------- | -------------------- |
| D1          | Left motor forward   |
| D2          | Left motor backward  |
| D5          | Right motor forward  |
| D6          | Right motor backward |
| D7          | Motor A speed (ENA)  |
| D8          | Motor B speed (ENB)  |

## Blynk Virtual Pins

| Virtual Pin | Function      |
| ----------- | ------------- |
| V0          | Forward       |
| V1          | Backward      |
| V2          | Left          |
| V3          | Right         |
| V4          | Speed control |

## How It Works

The ESP8266 connects to a Wi-Fi network and communicates with the Blynk IoT platform.

When a control button is pressed in the Blynk application, the corresponding virtual pin sends a command to the ESP8266.

The ESP8266 then controls the L298N motor driver. The direction pins determine the direction of each motor, while ENA and ENB control the motor speed using PWM.

For turning, the motors are operated in opposite directions with different speed values to change the rover's direction.

## Project Structure

```text
ESP8266-Blynk-Rover/
│
├── rover.ino
├── README.md
│
└── images/
    ├── rover.jpg
    ├── wiring.jpg
    └── blynk-app.jpg
```

## Setup

### 1. Install Arduino IDE

Install Arduino IDE and configure it for the ESP8266.

### 2. Install ESP8266 Board Support

Install the ESP8266 board package through the Arduino IDE and select the appropriate ESP8266 board.

### 3. Install Blynk Library

Install the Blynk library using the Arduino IDE Library Manager.

### 4. Configure Blynk

Create a Blynk template and configure the following virtual pins:

* V0 → Forward
* V1 → Backward
* V2 → Left
* V3 → Right
* V4 → Speed

### 5. Configure Credentials

Enter your Blynk and Wi-Fi credentials in the program.

**Do not upload your actual Wi-Fi password or Blynk authentication token to GitHub.**

Use placeholders in the public repository, for example:

```cpp
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";
```

### 6. Upload the Code

Connect the ESP8266 to the computer and upload `rover.ino`.

### 7. Control the Rover

Open the Blynk application and use the configured controls to operate the rover.

## Project Images

Recommended images to add to the repository:

* Completed rover
* ESP8266 and L298N wiring
* Motor connections
* Blynk control interface
* Rover during operation

## Future Improvements

* Add ultrasonic obstacle detection
* Add autonomous navigation
* Add a live camera
* Add battery voltage monitoring
* Add an emergency stop button
* Add line-following capability

## What I Learned

This project helped me understand:

* ESP8266 programming
* Wi-Fi communication
* Blynk IoT
* Motor driver control
* PWM-based motor speed control
* Digital output control
* Blynk virtual pins
* Basic robotics
* Hardware-software integration

## Author

**Dhruv Kumar**

ECE Student
Dayanand Sagar College of Engineering, Bangalore
