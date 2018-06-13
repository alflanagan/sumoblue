#include <Arduino.h>
#include <Servo.h>
#include "Wheel.h"

// sheesh. need to find setting for more recent C dialect
#define FALSE 0
#define TRUE -1

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
  static int first_run = TRUE;
  if (first_run) {
    rightWheel.advance(30.0);
    leftWheel.advance(30.0);
    first_run = FALSE;
  }
  rightWheel.update();
  leftWheel.update();
}
