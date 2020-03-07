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
    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
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

    FRightMotor.stop();
    FLeftMotor.stop();
    BRightMotor.stop();
    BLeftMotor.stop();
}

void shaftDown(double velocity, double distance, rotationUnits units)
{
  RAngle.resetPosition();
  Brain.Screen.print(RAngle.position(units));
  while(RAngle.position(units) <= distance)
  {
    RAngle.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    LAngle.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
  }
  RAngle.stop();
  LAngle.stop();
  Brain.Screen.print(RAngle.position(units));
}

void shaftUp(double velocity, double distance, rotationUnits units)
{
  RAngle.resetPosition();
  while(RAngle.position(units) >= -distance)
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
  shaftUp(50, 3.2, vex::rotationUnits::rev);
  moveBack(25, 1, vex::rotationUnits::rev); 
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
    RArm.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
    LArm.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct);
  }
  RArm.stop();
  LArm.stop();
}

void swingLeft(double velocity, double distance, rotationUnits units)
{
  BRightMotor.resetPosition();
  while(BRightMotor.position(units) <= distance)
  {
    BRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct); 
  }
    BRightMotor.stop();
    BLeftMotor.stop();
}

void swingRight(double velocity, double distance, rotationUnits units)
{
  BRightMotor.resetPosition();
  while(BRightMotor.position(units) >= -distance)
  {
    BRightMotor.spin(vex::directionType::fwd, velocity, vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::rev, velocity, vex::velocityUnits::pct); 
  }
    BRightMotor.stop();
    BLeftMotor.stop();
}

void testing1()
{
  Brain.Screen.newLine();
  Brain.Screen.print("Testing First");

  armGoUp(100, 1.25, vex::rotationUnits::rev);
  armGoDown(100, .75, vex::rotationUnits::rev);
  int count = 0;

  while (count <= 1)
  {
    intakePullInfinite();
    moveForward(25, 3.75, vex::rotationUnits::rev);
    stopAutoIntake();
    count += 1;
    if(count == 2)
    {
      break;
    }
    moveBack(35, 3.50, vex::rotationUnits::rev);
    shiftRight(25, 2, vex::rotationUnits::rev);
  }
  
  moveBack(35, 3.1, vex::rotationUnits::rev);
  turnLeft(25, 1.15, vex::rotationUnits::rev);
  moveForward(25, 2, vex::rotationUnits::rev);
  swingLeft(25, 1.75, vex::rotationUnits::rev);
  moveForward(25, 1.20, vex::rotationUnits::rev);
  placeStack();

}

void testing2()
{
  Brain.Screen.newLine();
  Brain.Screen.print("Testing Second");

  armGoUp(100, 1.25, vex::rotationUnits::rev);
  armGoDown(100, .75, vex::rotationUnits::rev);
  int count = 0;

  while (count <= 1)
  {
    intakePullInfinite();
    moveForward(25, 3.75, vex::rotationUnits::rev);
    stopAutoIntake();
    count += 1;
    if(count == 2)
    {
      break;
    }
    moveBack(35, 3.50, vex::rotationUnits::rev);
    shiftLeft(25, 2, vex::rotationUnits::rev);
  } 
  moveBack(35, 3.1, vex::rotationUnits::rev);
  turnRight(25, 1.15, vex::rotationUnits::rev);
  moveForward(25, 2, vex::rotationUnits::rev);
  swingRight(25, 1.75, vex::rotationUnits::rev);
  moveForward(25, 1.20, vex::rotationUnits::rev);
  placeStack();
}


