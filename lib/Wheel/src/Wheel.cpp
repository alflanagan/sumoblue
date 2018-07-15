#include "Wheel.h"
#include <Arduino.h>
#include <Servo.h>

Wheel::Wheel(int pin, double radiusInMM /*, int degreesPerPosition */) {
  radius = radiusInMM;
  circum = radiusInMM * PI * 2;
  drivePin = pin;
}

/**
 * We don't want to attach motor to drive pin at time of construction;
 * motor may not be ready.
 */
void Wheel::setup() {
  motor.attach(drivePin);
  pos = 0;   // I think?
}

/**
 * Sets a new goal position for the servo.
 * @param distInMM distance in millimeters wheel should travel forward (or
 *       backward if value is negative).
 */
void Wheel::advance(double distInMM) {
  degreesFromGoal = (int)((distInMM / circum) * 360.0);
}

/**
 * Update wheel and progress toward goal, if we haven't reached it yet. Should
 * be called regularly, hopefully no more often than the time required for motor
 * to advance by one position..
 */
void Wheel::update() {
  // TODO: do we need to check if motor has completed previous action?
  if (degreesFromGoal != 0) {
    int increment = degreesFromGoal > 0 ? -1 : 1;
    pos += increment;
    motor.write(pos);
    degreesFromGoal -= increment;
  }
}
