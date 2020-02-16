#include "vex.h"
#include "robot-config.h"
 
void moveForward(double velocity, double distance,  rotationUnits rev)
{
  while(FRightMotor.position(rev) <= distance)
  {
    FRightMotor.spin(vex::directionType::fwd);
    FLeftMotor.spin(vex::directionType::fwd);
    BRightMotor.spin(vex::directionType::fwd);
    BLeftMotor.spin(vex::directionType::fwd);
  }
   
} 

void moveBack(double velocity, double distance, rotationUnits rev)
{
  while(FRightMotor.position(rev) >= -distance)
  {
    FRightMotor.spin(vex::directionType::rev);
    FLeftMotor.spin(vex::directionType::rev);
    BRightMotor.spin(vex::directionType::rev);
    BLeftMotor.spin(vex::directionType::rev);
  }

}

void shiftRight(double velocity, double distance, rotationUnits rev)
{
  while(FRightMotor.position(rev) >= -distance)
  {
    FRightMotor.spin(vex::directionType::rev);
    FLeftMotor.spin(vex::directionType::fwd);
    BRightMotor.spin(vex::directionType::fwd);
    BLeftMotor.spin(vex::directionType::rev);
  }
}

void shiftLeft(double velocity, double distance, rotationUnits rev)
{
  while(FRightMotor.position(rev) <= distance)
  {
    FRightMotor.spin(vex::directionType::fwd);
    FLeftMotor.spin(vex::directionType::rev);
    BRightMotor.spin(vex::directionType::rev);
    BLeftMotor.spin(vex::directionType::fwd);
  }
}

void turnLeft(double unit)
{
  while(Balance.heading(degrees) <= unit)
  {
    FRightMotor.spin(vex::directionType::fwd);
    FLeftMotor.spin(vex::directionType::rev);
    BRightMotor.spin(vex::directionType::fwd);
    BLeftMotor.spin(vex::directionType::rev);
  }
}

void turnRight(double unit)
{
  while(Balance.heading(degrees) <= unit)
  {
    FRightMotor.spin(vex::directionType::fwd);
    FLeftMotor.spin(vex::directionType::rev);
    BRightMotor.spin(vex::directionType::fwd);
    BLeftMotor.spin(vex::directionType::rev);
  }
}

void shaftDown(double velocity, double distance, rotationUnits rev)
{
  while(RAngle.position(rev) <= distance)
  {
    RAngle.spin(vex::directionType::fwd);
    LAngle.spin(vex::directionType::fwd);
  }
}

void intakePullInfinite()
{
  FRightConveyor.spin(vex::directionType::rev);
  FLeftConveyor.spin(vex::directionType::rev);
  BRightConveyor.spin(vex::directionType::rev);
  BLeftConveyor.spin(vex::directionType::rev); 
}

void intakePushInfinite()
{
  FRightConveyor.spin(vex::directionType::fwd);
  FLeftConveyor.spin(vex::directionType::fwd);
  BRightConveyor.spin(vex::directionType::fwd);
  BLeftConveyor.spin(vex::directionType::fwd); 
}

void placeStack()
{
  shaftDown(100, .5, rev);
  moveBack(50, 2, rev);
}


