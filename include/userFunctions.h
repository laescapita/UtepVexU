#include "vex.h"
#include "robot-config.h"

void joyStickDrive(int Ax1Pos, int Ax3Pos, int Ax4Pos)
{ 
    FRightMotor.spin(vex::directionType::fwd, (Ax3Pos - Ax1Pos - Ax4Pos), vex::velocityUnits::pct);
    FLeftMotor.spin(vex::directionType::fwd, (Ax3Pos + Ax1Pos + Ax4Pos), vex::velocityUnits::pct);
    BRightMotor.spin(vex::directionType::fwd, (Ax3Pos - Ax1Pos + Ax4Pos), vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::fwd, (Ax3Pos + Ax1Pos - Ax4Pos), vex::velocityUnits::pct);
}
  
void shaftUp()
{
  LAngle.spinFor(vex::directionType::fwd, 30, deg);
  RAngle.spinFor(vex::directionType::fwd, 30, deg);
}

void shaftDown()
{
  LAngle.spinFor(vex::directionType::rev, 30, deg);
  RAngle.spinFor(vex::directionType::rev, 30, deg);
}

void armUp()
{
  LArm.spin(vex::directionType::fwd);
  RArm.spin(vex::directionType::fwd);
}

void armDown()
{
  LArm.spin(vex::directionType::rev);
  RArm.spin(vex::directionType::rev);
}

void push()
{
  RFrontConveyor.spin(vex::directionType::fwd);
  LFrontConveyor.spin(vex::directionType::fwd);
  RBackConveyor.spin(vex::directionType::fwd);
  LBackConveyor.spin(vex::directionType::fwd);
}

void pull()
{
  RFrontConveyor.spin(vex::directionType::rev);
  LFrontConveyor.spin(vex::directionType::rev);
  RBackConveyor.spin(vex::directionType::rev);
  LBackConveyor.spin(vex::directionType::rev);
}