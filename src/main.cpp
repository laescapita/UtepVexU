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
void auton ( void )
{
  Brain.Screen.print("Autonmous is-a-go");

  //Sets Speed of every motor 
  setDriveSpeed();

  //Move Forward
  moveForward(5, rev);

  //Turn Right
  turnRight(2, rev);

  //Move Shaft
  moveShaftUp(30, deg);

  Brain.Screen.newLine();
  Brain.Screen.print("Autonmous has ended");
}

//Sets the controls for all the motors
void userControl( void )
{
  Brain.Screen.print("Mecanum Drive");

  //setDriveSpeed();

  //Positions
  int Ax1Pos = Controller1.Axis1.position();
  int Ax3Pos = Controller1.Axis3.position();
  int Ax4Pos = Controller1.Axis4.position();


  //Infinite Loop
  while(1)
  {
    //Actual Joystick Drive
    joyStickDrive(Ax1Pos, Ax3Pos, Ax4Pos);

    if(Controller1.ButtonY.pressing())
    {
       shaftDown();
    }

    if(Controller1.ButtonX.pressing())
    {
       shaftUp();
    }

    if(Controller1.ButtonR1.pressing())
    {
      armDown();
    }

    if(Controller1.ButtonR2.pressing())
    {
      armUp();
    }
    
  }

 vex::task::sleep(20);

}
 
//Where stuff goes down 
int main() 
{
  Competition.autonomous( auton );
  Competition.drivercontrol( userControl );

  preAuton();

  while(1)
  {
    vex::task::sleep(100);
  }
  
}
