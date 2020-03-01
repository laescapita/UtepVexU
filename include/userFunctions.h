#include "vex.h"
#include "robot-config.h"

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

void stopIntake()
{
  // FRightConveyor.stop();
  // FLeftConveyor.stop();
  BRightConveyor.stop();
  BLeftConveyor.stop();
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
  BRightConveyor.spin(vex::directionType::fwd);
  BLeftConveyor.spin(vex::directionType::fwd);
  // FRightConveyor.spin(vex::directionType::fwd);
  // FLeftConveyor.spin(vex::directionType::fwd);

}

void pull()
{
  BRightConveyor.spin(vex::directionType::rev);
  BLeftConveyor.spin(vex::directionType::rev);
  // FRightConveyor.spin(vex::directionType::rev);
  // FLeftConveyor.spin(vex::directionType::rev);
}

void joyStickDrive(int Ax1Pos, int Ax3Pos, int Ax4Pos)
{ 
    FRightMotor.spin(vex::directionType::fwd, (Ax3Pos - Ax1Pos - Ax4Pos)/1.5, vex::velocityUnits::pct);
    FLeftMotor.spin(vex::directionType::fwd, (Ax3Pos + Ax1Pos + Ax4Pos)/1.5, vex::velocityUnits::pct);
    BRightMotor.spin(vex::directionType::fwd, (Ax3Pos - Ax1Pos + Ax4Pos)/1.5, vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::fwd, (Ax3Pos + Ax1Pos - Ax4Pos)/1.5, vex::velocityUnits::pct);
    
    if(Controller1.ButtonDown.pressing())
    {
       shaftUp();
    }

    else if(Controller1.ButtonUp.pressing())
    {
       shaftDown();
    }

    else
    {
        stopShaft();
    }

    if(Controller1.ButtonR2.pressing())
    {
      armDown();
    }

    else if(Controller1.ButtonR1.pressing())
    {
      armUp();
    }

    else
    {
      stopArm();
    }
    
    if(Controller1.ButtonL2.pressing())
    {
      push();
    }

    else if(Controller1.ButtonL1.pressing())
    {
      pull();
    }

    else
    {
      stopIntake();
    }
} 