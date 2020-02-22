#include "vex.h"
#include "robot-config.h"
 
void moveForward(double velocity, double seconds) //These Two were the functions tested on
{
  Brain.resetTimer();
  double startTime = Brain.timer(vex::timeUnits::sec);
  while(startTime <= seconds)
  {
    FRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    FLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    BRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    BLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm); 
  }
   
}   

void moveForward(double velocity, double distance, rotationUnits rev) //Examples of single use mentality
{
  FRightMotor.resetPosition();
  while(FRightMotor.position(rev) <= distance)
  {
    FRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    FLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    BRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    BLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm); 
  }
   
}  

void moveBack(double velocity, double seconds)
{
  Brain.resetTimer();
  double startTime = Brain.timer(vex::timeUnits::sec);
  while(startTime <= seconds)
  {
    FRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    FLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    BRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    BLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm); 
  }
   
}  

void moveBack(double velocity, double distance, rotationUnits rev)
{
  FRightMotor.resetPosition();
  while(FRightMotor.position(rev) >= -distance)
  {
    FRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    FLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    BRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    BLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm); 
  }
   
}  

void shiftRight(double velocity, double seconds)
{
  Brain.resetTimer();
  double startTime = Brain.timer(vex::timeUnits::sec);
  while(startTime <= seconds)
  {
    FRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    FLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    BRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    BLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm); 
  }
   
}  

void shiftRight(double velocity, double distance, rotationUnits rev)
{
  FRightMotor.resetPosition();
  while(FRightMotor.position(rev) >= -distance)
  {
    FRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    FLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    BRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    BLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm); 
  }
   
}  

void shiftLeft(double velocity, double seconds)
{
  Brain.resetTimer();
  double startTime = Brain.timer(vex::timeUnits::sec);
  while(startTime <= seconds)
  {
    FRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    FLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    BRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    BLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm); 
  }
   
}  

void shiftLeft(double velocity, double distance, rotationUnits rev)
{
  FRightMotor.resetPosition();
  while(FRightMotor.position(rev) <= distance)
  {
    FRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    FLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    BRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    BLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm); 
  }
   
}  

void turnLeft(double velocity, double unit)
{
  Balance.resetHeading();
  while(Balance.heading(degrees) <= unit)
  {
    FRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    FLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    BRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    BLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
  }
}

void turnRight(double velocity, double unit)
{
  Balance.resetHeading();
  while(Balance.heading(degrees) <= unit)
  {
    FRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    FLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    BRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    BLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
  }
}

void shaftDown(double velocity, double seconds)
{
  Brain.resetTimer();
  double startTime = Brain.timer(vex::timeUnits::sec);
  while(startTime <= seconds)
  {
    RAngle.spin(vex::directionType::fwd);
    LAngle.spin(vex::directionType::fwd);
  }
}

void shaftUp(double velocity, double seconds)
{
  Brain.resetTimer();
  double startTime = Brain.timer(vex::timeUnits::sec);
  while(startTime <= seconds)
  {
    RAngle.spin(vex::directionType::rev);
    LAngle.spin(vex::directionType::rev);
  }
}

void intakePullInfinite()
{
  // FRightConveyor.spin(vex::directionType::rev);
  // FLeftConveyor.spin(vex::directionType::rev);
  BRightConveyor.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm);
  BLeftConveyor.spin(vex::directionType::rev, 100, vex::velocityUnits::rpm); 
}

void intakePushInfinite()
{
  // FRightConveyor.spin(vex::directionType::fwd);
  // FLeftConveyor.spin(vex::directionType::fwd);
  BRightConveyor.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm);
  BLeftConveyor.spin(vex::directionType::fwd, 100, vex::velocityUnits::rpm); 
}

void placeStack()
{
  moveForward(25, 1);
  //moveForward(30, 3, rev);
  shaftDown(100, 2);
  moveForward(25, 1);
  //moveForward(30, 3, rev);
  moveBack(25, 2);
  //moveBack(30, 3, rev);
  
}

void armGoUp(double velocity, double seconds)
{
  Brain.resetTimer();
  double startTime = Brain.timer(vex::timeUnits::sec);
  while(startTime <= seconds)
  {
    LArm.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    RArm.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
  }
}

void armGoDown(double velocity, double seconds)
{
  Brain.resetTimer();
  double startTime = Brain.timer(vex::timeUnits::sec);
  while(startTime <= seconds)
  {
    LArm.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    RArm.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
  }
}


