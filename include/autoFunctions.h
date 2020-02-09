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
  FLeftMotor.spinFor(vex::directionType::fwd, rotations, revs);
  BLeftMotor.spinFor(vex::directionType::fwd, rotations, revs);
  FRightMotor.spinFor(vex::directionType::fwd, rotations, revs);
  BRightMotor.spinFor(vex::directionType::fwd, rotations, revs);
}

void moveBack(double rotations, rotationUnits revs)
{
  FLeftMotor.spinFor(vex::directionType::rev, rotations, revs);
  BLeftMotor.spinFor(vex::directionType::rev, rotations, revs);
  FRightMotor.spinFor(vex::directionType::rev, rotations, revs);
  BRightMotor.spinFor(vex::directionType::rev, rotations, revs);
}

void turnLeft(double rotations, rotationUnits revs)
{
  FLeftMotor.spinFor(vex::directionType::rev, rotations, revs);
  BLeftMotor.spinFor(vex::directionType::rev, rotations, revs);
  FRightMotor.spinFor(vex::directionType::fwd, rotations, revs);
  BRightMotor.spinFor(vex::directionType::fwd, rotations, revs);
}

void turnRight(double rotations, rotationUnits revs)
{
  FLeftMotor.spinFor(vex::directionType::fwd, rotations, revs);
  BLeftMotor.spinFor(vex::directionType::fwd, rotations, revs);
  FRightMotor.spinFor(vex::directionType::rev, rotations, revs);
  BRightMotor.spinFor(vex::directionType::rev, rotations, revs);
}