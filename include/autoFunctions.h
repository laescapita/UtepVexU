#include "vex.h"
#include "robot-config.h"

void setDriveSpeed()
{
  FLeftMotor.setVelocity(100, vex::velocityUnits::pct);
  BLeftMotor.setVelocity(100, vex::velocityUnits::pct);
  FRightMotor.setVelocity(100, vex::velocityUnits::pct);
  BRightMotor.setVelocity(100, vex::velocityUnits::pct);
  LAngle.setVelocity(100, vex::velocityUnits::pct);
  RAngle.setVelocity(100, vex::velocityUnits::pct);
  LArm.setVelocity(100, vex::velocityUnits::pct);
  RArm.setVelocity(100, vex::velocityUnits::pct);
  LFrontConveyor.setVelocity(100, vex::velocityUnits::pct);
  RFrontConveyor.setVelocity(100, vex::velocityUnits::pct);
  LBackConveyor.setVelocity(100, vex::velocityUnits::pct);
  RBackConveyor.setVelocity(100, vex::velocityUnits::pct);
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

void moveShaftUp(double degrees, rotationUnits deg)
{
  LAngle.spinFor(vex::directionType::fwd, degrees, deg);
  RAngle.spinFor(vex::directionType::fwd, degrees, deg);
}

void moveShaftDown(double degrees, rotationUnits deg)
{
  LAngle.spinFor(vex::directionType::rev, degrees, deg);
  RAngle.spinFor(vex::directionType::rev, degrees, deg);
}

void moveArmUp(double degrees, rotationUnits deg)
{
  LArm.spinFor(vex::directionType::fwd, degrees, deg);
  RArm.spinFor(vex::directionType::fwd, degrees, deg);
}

void moveArmDown(double degrees, rotationUnits deg)
{
  LArm.spinFor(vex::directionType::rev, degrees, deg);
  RArm.spinFor(vex::directionType::rev, degrees, deg);
}

 void pushOut(double rotations, rotationUnits rev)
 {
  RFrontConveyor.spinFor(vex::directionType::fwd, rotations, rev);
  LFrontConveyor.spinFor(vex::directionType::fwd, rotations, rev);
  RBackConveyor.spinFor(vex::directionType::fwd, rotations, rev);
  LBackConveyor.spinFor(vex::directionType::fwd, rotations, rev);
 }

 void pushIn(double rotations, rotationUnits rev)
 {
  RFrontConveyor.spinFor(vex::directionType::rev, rotations, rev);
  LFrontConveyor.spinFor(vex::directionType::rev, rotations, rev);
  RBackConveyor.spinFor(vex::directionType::rev, rotations, rev);
  LBackConveyor.spinFor(vex::directionType::rev, rotations, rev);
 }