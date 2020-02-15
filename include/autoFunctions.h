#include "vex.h"
#include "robot-config.h"
 
void moveForward(double velocity, double distance, velocityUnits units)
{
  while(FRightMotor.position(rev) > distance)
  {
    FRightMotor.spin(fwd, velocity, units);
    FLeftMotor.spin(fwd, velocity, units);
    BRightMotor.spin(fwd, velocity, units);
    BLeftMotor.spin(fwd, velocity, units);
  }
  
}