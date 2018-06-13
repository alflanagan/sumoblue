#if !defined(WHEEL_HDR)
#define WHEEL_HDR

#include <Servo.h>

class Wheel {
private:
  Servo motor;
  double radius;
  double circum; // circumference in mm, calcaluted value cached for speed
  int pos; // current servo position in degrees
  int drivePin; //Arduino pin which is connected to this servo
  int degreesFromGoal;  // deg. (pos or neg) by which pos differs from current goal pos.

public:
  Wheel(int pin, double radiusInMM);
  void setup();
  void advance(double distInMM);
  void update();
};
#endif
