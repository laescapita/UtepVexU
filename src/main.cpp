/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\leono                                            */
/*    Created:      Fri Feb 07 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FLeftMotor           motor         1               
// BLeftMotor           motor         2               
// FRightMotor          motor         3               
// BRightMotor          motor         4               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "autoFunctions.h"
#include "userFunctions.h"

using namespace vex;

vex::competition Competition;

//This will be used to reset any values that have been used for either auton or user control
void preAuton( void )
{
  Brain.Screen.print("Pre-Autonmous");
}

//Autonomous method
void autonBlue ( void )
{
  Brain.Screen.print("Blue Autonmous is-a-go");

  moveForward(40, .5, rev);

  armGoUp(75, 2.6, rev);

  //armGoDown(75, 2.8, rev);

  wait(2, sec);
         
  intakePullInfinite();

  moveForward(40, 2, rev); //Motor Sensor Based

  moveBack(40, 1.8, rev);

  stopIntake();
 
  turnLeft(30, 2.4, rev);

  placeStack();
}

void autonRed ( void )
{
  Brain.Screen.print("Blue Autonmous is-a-go");

  moveForward(40, .5, rev);

  armGoUp(75, 2.6, rev);

  //armGoDown(75, 2.8, rev);

  wait(2, sec);
         
  intakePullInfinite();

  moveForward(40, 2, rev); //Motor Sensor Based

  moveBack(40, 1.8, rev);

  stopIntake();
 
  turnRight(30, 2.4, rev);

  placeStack();
}

//Sets the controls for all the motors
void userControl( void )
{
  Brain.Screen.newLine();
  Brain.Screen.print("Mecanum Drive");

  //setDriveSpeed();

  //Positions


  //Infinite Loop
  while(1)
  {
      int Ax1Pos = Controller1.Axis1.position();
      int Ax3Pos = Controller1.Axis3.position();
      int Ax4Pos = Controller1.Axis4.position();

    //Actual Joystick Drive
    joyStickDrive(Ax1Pos, Ax3Pos, Ax4Pos);

    if(Controller1.ButtonRight.pressing())
    {
      autonBlue();
    }

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

 vex::task::sleep(20);

}
 
//Where stuff goes down 
int main() 
{
  Competition.autonomous( autonRed );
  
  Competition.drivercontrol( userControl );

  preAuton();

  while(1)
  {
    vex::task::sleep(100);
  }
  
}
