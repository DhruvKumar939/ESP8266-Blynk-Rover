/*
 * ---------------------------------------------------------
 * Project: ESP8266 Wi-Fi Controlled Rover
 * Controller: ESP8266
 * Motor Driver: L298N
 * Control App: Blynk IoT
 * ---------------------------------------------------------
 *
 * Description:
 * This project controls a two-wheel-drive robotic rover
 * wirelessly using the Blynk mobile application.
 *
 * The ESP8266 receives commands from Blynk and controls
 * the direction and speed of the two DC motors through
 * an L298N motor driver.
 * ---------------------------------------------------------
 */

// -------------------------
// Blynk Configuration
// -------------------------
// Replace these values with your own Blynk credentials.

#define BLYNK_TEMPLATE_ID ".............."       // Blynk Template ID
#define BLYNK_TEMPLATE_NAME "............"       // Blynk Template Name
#define BLYNK_AUTH_TOKEN "..............."        // Blynk Authentication Token

// -------------------------
// Required Libraries
// -------------------------

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// -------------------------
// Wi-Fi Credentials
// -------------------------
// Replace these with your Wi-Fi network details.

char ssid[] = "..........";    // Wi-Fi network name
char pass[] = "..........";   // Wi-Fi password

// -------------------------
// Motor Control Pins
// -------------------------
// These pins are connected to the L298N motor driver.

#define left_Front  D1
#define left_Back   D2
#define right_Front D5
#define right_Back  D6

// ENA and ENB control the speed of the two motors
// using PWM signals.

#define ENA D7
#define ENB D8

// Default motor speed.
// ESP8266 analogWrite() uses a PWM range of 0-1023.
int motorSpeed = 450;


// =========================================================
//                 MOTOR CONTROL FUNCTIONS
// =========================================================

// Move the rover forward.
void front(int speed)
{
  // Left motor moves forward
  digitalWrite(left_Front, HIGH);
  digitalWrite(left_Back, LOW);

  // Right motor moves forward
  digitalWrite(right_Front, HIGH);
  digitalWrite(right_Back, LOW);

  // Set speed of both motors
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}


// Move the rover backward.
void back(int speed)
{
  // Left motor moves backward
  digitalWrite(left_Front, LOW);
  digitalWrite(left_Back, HIGH);

  // Right motor moves backward
  digitalWrite(right_Front, LOW);
  digitalWrite(right_Back, HIGH);

  // Set speed of both motors
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}


// Turn the rover right.
void right(int speed)
{
  // Left motor moves backward
  digitalWrite(left_Front, LOW);
  digitalWrite(left_Back, HIGH);

  // Right motor moves forward
  digitalWrite(right_Front, HIGH);
  digitalWrite(right_Back, LOW);

  // The left motor runs slower while the right
  // motor runs at the selected speed.
  analogWrite(ENA, speed / 2);
  analogWrite(ENB, speed);
}


// Turn the rover left.
void left(int speed)
{
  // Left motor moves forward
  digitalWrite(left_Front, HIGH);
  digitalWrite(left_Back, LOW);

  // Right motor moves backward
  digitalWrite(right_Front, LOW);
  digitalWrite(right_Back, HIGH);

  // The right motor runs slower while the left
  // motor runs at the selected speed.
  analogWrite(ENA, speed);
  analogWrite(ENB, speed / 2);
}


// Stop both motors.
void stop()
{
  // Disable all motor direction signals
  digitalWrite(left_Front, LOW);
  digitalWrite(left_Back, LOW);
  digitalWrite(right_Front, LOW);
  digitalWrite(right_Back, LOW);

  // Set motor speed to zero
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}


// =========================================================
//                       SETUP
// =========================================================

void setup()
{
  // Configure motor direction pins as outputs
  pinMode(left_Front, OUTPUT);
  pinMode(left_Back, OUTPUT);
  pinMode(right_Front, OUTPUT);
  pinMode(right_Back, OUTPUT);

  // Configure motor enable pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Connect ESP8266 to Wi-Fi and Blynk Cloud
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}


// =========================================================
//                 BLYNK VIRTUAL PINS
// =========================================================

// V4 controls the motor speed using a Blynk slider.
BLYNK_WRITE(V4)
{
  motorSpeed = param.asInt();
}


// V0 controls forward movement.
BLYNK_WRITE(V0)
{
  int v0 = param.asInt();

  if (v0 == 1)
  {
    front(motorSpeed);
  }
  else
  {
    stop();
  }
}


// V1 controls backward movement.
BLYNK_WRITE(V1)
{
  int v1 = param.asInt();

  if (v1 == 1)
  {
    back(motorSpeed);
  }
  else
  {
    stop();
  }
}


// V2 controls left movement.
BLYNK_WRITE(V2)
{
  int v2 = param.asInt();

  if (v2 == 1)
  {
    left(motorSpeed);
  }
  else
  {
    stop();
  }
}


// V3 controls right movement.
BLYNK_WRITE(V3)
{
  int v3 = param.asInt();

  if (v3 == 1)
  {
    right(motorSpeed);
  }
  else
  {
    stop();
  }
}


// =========================================================
//                        MAIN LOOP
// =========================================================

void loop()
{
  // Continuously process Blynk commands.
  Blynk.run();
}
