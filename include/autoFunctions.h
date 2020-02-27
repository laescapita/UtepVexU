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

    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
   
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

    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
   
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

    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
   
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
    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
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
    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
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

    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
   
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

    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
   
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

    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
   
}  

void turnLeft(double velocity, double distance, rotationUnits rev)
{
  FRightMotor.resetPosition();
  while(FRightMotor.position(rev) <= distance)
  {
    FRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    FLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    BRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    BLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm); 
  }
}

void turnRight(double velocity, double distance, rotationUnits rev)
{
  FRightMotor.resetPosition();
  while(FRightMotor.position(rev) >= -distance)
  {
    FRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    FLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    BRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    BLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm); 
  }
}

void shaftDown(double velocity, double distance, rotationUnits rev)
{
  RAngle.resetPosition();
  while(RArm.position(rev) <= distance)
  {
    RAngle.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    LAngle.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
  }
  RAngle.stop();
  LAngle.stop();
}

void shaftUp(double velocity, double distance, rotationUnits rev)
{
  RAngle.resetPosition();
  while(RArm.position(rev) >= -distance)
  {
    RAngle.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
    LAngle.spin(vex::directionType::rev, velocity, vex::velocityUnits::rpm);
  }
  RAngle.stop();
  LAngle.stop();
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
  moveForward(25, .6, rev);
  //moveForward(30, 3, rev);
  shaftDown(80, .273, rev);
  //moveForward(25, 1);
  //moveForward(30, 3, rev);
 // moveBack(25, 2);
  moveBack(30, 1, rev);
  
}

void armGoUp(double velocity, double distance, rotationUnits rev)
{
  RArm.resetPosition();
  while(RArm.position(rev) <= distance)
  {
    RArm.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    LArm.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
  }
  RArm.stop();
  LArm.stop();
}

void armGoDown(double velocity, double distance, rotationUnits rev)
{
  RArm.resetPosition();
  while(RArm.position(rev) >= -distance)
  {
    RArm.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
    LArm.spin(vex::directionType::fwd, velocity, vex::velocityUnits::rpm);
  }
  RArm.stop();
  LArm.stop();
}


