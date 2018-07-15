#include <Arduino.h>
#include <Servo.h>
#include "Wheel.h"

const int RIGHT_MOTOR = 10;
const int LEFT_MOTOR = 9;

const double WHEEL_RADIUS = 30.0; // mm

const double DIST_PER_DEGREE = (WHEEL_RADIUS * 2.0 * PI) / 360.0;

Wheel rightWheel(RIGHT_MOTOR, WHEEL_RADIUS);
Wheel leftWheel(LEFT_MOTOR, WHEEL_RADIUS);

void setup() {
  rightWheel.setup();
  leftWheel.setup();
}

void loop() {
  static bool first_run = true;
  if (first_run) {
    rightWheel.advance(30.0);
    leftWheel.advance(30.0);
    first_run = false;
  }
  rightWheel.update();
  leftWheel.update();
}
