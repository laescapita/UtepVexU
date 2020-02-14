#include "vex.h"
#include "robot-config.h"
 
void moveForward(double velocity, double distance, rotationUnits units)
{
  while(FRightMotor.position(units) > distance)
  FRightMotor.spin(fwd, velocity, units);
  FLeftMotor.spin(fwd, velocity, units);
  BRightMotor.spin(fwd, velocity, units);
  BLeftMotor.spin(fwd, velocity, units);
}