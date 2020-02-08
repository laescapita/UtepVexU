#include "vex.h"
#include "robot-config.h"

void setDriveSpeed()
{
  FLeftMotor.setVelocity(100, vex::velocityUnits::pct);
  BLeftMotor.setVelocity(100, vex::velocityUnits::pct);
  FRightMotor.setVelocity(100, vex::velocityUnits::pct);
  BRightMotor.setVelocity(100, vex::velocityUnits::pct);
}

void moveForward(double rotations, rotationUnits revs)
{
  FLeftMotor.spinFor(rotations, revs);
  BLeftMotor.spinFor(rotations, revs);
  FRightMotor.spinFor(rotations, revs);
  BRightMotor.spinFor(rotations, revs);
}