#include "vex.h"
#include "robot-config.h"

void joyStickDrive(int Ax1Pos, int Ax3Pos, int Ax4Pos)
{ 
    FRightMotor.spin(vex::directionType::fwd, (Ax3Pos - Ax1Pos - Ax4Pos), vex::velocityUnits::pct);
    FLeftMotor.spin(vex::directionType::fwd, (Ax3Pos + Ax1Pos + Ax4Pos), vex::velocityUnits::pct);
    BRightMotor.spin(vex::directionType::fwd, (Ax3Pos - Ax1Pos + Ax4Pos), vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::fwd, (Ax3Pos + Ax1Pos - Ax4Pos), vex::velocityUnits::pct);
} 

void stopShaft()
{
  LAngle.stop();
  RAngle.stop();
}

void stopArm()
{
  LArm.stop();
  RArm.stop();
}

void stopConveyor()
{
  RightConveyor.stop();
  LeftConveyor.stop();
}
  
void shaftDown()
{
  LAngle.spin(vex::directionType::fwd);
  RAngle.spin(vex::directionType::fwd);
}

void shaftUp()
{
  LAngle.spin(vex::directionType::rev);
  RAngle.spin(vex::directionType::rev);
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
  RightConveyor.spin(vex::directionType::fwd);
  LeftConveyor.spin(vex::directionType::fwd);

}

void pull()
{
  RightConveyor.spin(vex::directionType::rev);
  LeftConveyor.spin(vex::directionType::rev);
}