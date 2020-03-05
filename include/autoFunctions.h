#include "vex.h"
#include "robot-config.h"

void stopAutoShaft() 
{
  LAngle.stop(); 
  RAngle.stop(); 
}

void stopAutoArm() 
{
  LArm.stop();
  RArm.stop();
}

void stopAutoIntake()
{
  // FRightConveyor.stop();
  // FLeftConveyor.stop();
  BRightConveyor.stop();
  BLeftConveyor.stop();
}
  

void moveForward(double velocity, double distance, rotationUnits units) //Examples of single use mentality
{
  FRightMotor.resetPosition();
  while(FRightMotor.position(units) <= distance)
  {
    FRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    FLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    BRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct); 
  }

    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
   
}  


void moveBack(double velocity, double distance, rotationUnits units)
{
  FRightMotor.resetPosition();
  while(FRightMotor.position(units) >= -distance)
  {
    FRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
    FLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
    BRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct); 
  }
    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
}  


void shiftRight(double velocity, double distance, rotationUnits units)
{
  FRightMotor.resetPosition();
  while(FRightMotor.position(units) >= -distance)
  {
    FRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
    FLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    BRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct); 
  }

    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
   
}  


void shiftLeft(double velocity, double distance, rotationUnits units)
{
  FRightMotor.resetPosition();
  while(FRightMotor.position(units) <= distance)
  {
    FRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    FLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
    BRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct); 
  }

    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
   
}  


void turnLeft(double velocity, double distance, rotationUnits units)
{
  FRightMotor.resetPosition();
  while(FRightMotor.position(units) <= distance)
  {
    FRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    FLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
    BRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct); 
  }
}


void turnRight(double velocity, double distance, rotationUnits units)
{
  FRightMotor.resetPosition();
  while(FRightMotor.position(units) >= -distance)
  {
    FRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
    FLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    BRightMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct); 
  }
}

void shaftDown(double velocity, double distance, rotationUnits units)
{
  RAngle.resetPosition();
  while(RArm.position(units) <= distance)
  {
    RAngle.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    LAngle.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
  }
  RAngle.stop();
  LAngle.stop();
}

void shaftUp(double velocity, double distance, rotationUnits units)
{
  RAngle.resetPosition();
  while(RArm.position(units) >= -distance)
  {
    RAngle.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
    LAngle.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
  }
  RAngle.stop();
  LAngle.stop();
}


void intakePullInfinite()
{
  // FRightConveyor.spin(vex::directionType::rev);
  // FLeftConveyor.spin(vex::directionType::rev);
  BRightConveyor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
  BLeftConveyor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct); 
}


void intakePushInfinite()
{
  // FRightConveyor.spin(vex::directionType::fwd);
  // FLeftConveyor.spin(vex::directionType::fwd);
  BRightConveyor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  BLeftConveyor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct); 
}

void placeStack()
{
  moveForward(25, .6, vex::rotationUnits::rev);
  shaftDown(100, 3.8, vex::rotationUnits::rev);
  moveBack(30, 1, vex::rotationUnits::rev); 
}


void armGoUp(double velocity, double distance, rotationUnits units)
{
  RArm.resetPosition();
  while(RArm.position(units) <= distance)
  {
    RArm.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    LArm.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
  }
  RArm.stop();
  LArm.stop();
}


void armGoDown(double velocity, double distance, rotationUnits units)
{
  RArm.resetPosition();
  while(RArm.position(units) >= -distance)
  {
    RArm.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    LArm.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
  }
  RArm.stop();
  LArm.stop();
}

void testing1()
{
  Brain.Screen.newLine();
  Brain.Screen.print("Testing First");

  armGoUp(100, .75, vex::rotationUnits::rev);
  armGoDown(100, .75, vex::rotationUnits::rev);
  int count = 0;

  while (count < 2)
  {
    intakePullInfinite();
    moveForward(75, 4, vex::rotationUnits::rev);
    stopAutoIntake();
    moveBack(75, 4, vex::rotationUnits::rev);
    shiftRight(75, 1, vex::rotationUnits::rev);
    count += 1;
  }

  turnLeft(75, 1, vex::rotationUnits::rev);
  moveForward(75, 4, vex::rotationUnits::rev);
  placeStack();

}

void testing2()
{
  Brain.Screen.newLine();
  Brain.Screen.print("Testing Second");

  armGoUp(100, .75, vex::rotationUnits::rev);
  armGoDown(100, .75, vex::rotationUnits::rev);
  int count = 0;

  while (count < 2)
  {
    intakePullInfinite();
    moveForward(75, 4, vex::rotationUnits::rev);
    stopAutoIntake();
    moveBack(75, 4, vex::rotationUnits::rev);
    shiftLeft(75, 1, vex::rotationUnits::rev);
    count += 1;
  }

  turnRight(75, 1, vex::rotationUnits::rev);
  moveForward(75, 4, vex::rotationUnits::rev);
  placeStack();

}


