#include "vex.h"
#include "robot-config.h"

void joyStickDrive(int Ax1Pos, int Ax3Pos, int Ax4Pos)
{
    FRightMotor.spin(vex::directionType::fwd, (Ax3Pos - Ax1Pos - Ax4Pos), vex::velocityUnits::pct);
    FLeftMotor.spin(vex::directionType::fwd, (Ax3Pos + Ax1Pos + Ax4Pos), vex::velocityUnits::pct);
    BRightMotor.spin(vex::directionType::fwd, (Ax3Pos - Ax1Pos + Ax4Pos), vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::fwd, (Ax3Pos + Ax1Pos - Ax4Pos), vex::velocityUnits::pct);
}

void moveShaftUp()
{
  LAngle.spinFor(vex::directionType::fwd, 30, deg);
  RAngle.spinFor(vex::directionType::fwd, 30, deg);
}

void moveShaftDown()
{
  LAngle.spinFor(vex::directionType::rev, 30, deg);
  RAngle.spinFor(vex::directionType::rev, 30, deg);
}

void moveArmUp()
{
  LArm.spin(vex::directionType::fwd);
  RArm.spin(vex::directionType::fwd);
}

void moveArmDown()
{
  LArm.spin(vex::directionType::rev);
  RArm.spin(vex::directionType::rev);
}