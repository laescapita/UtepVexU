/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\leono                                            */
/*    Created:      Fri Feb 07 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "autoFunctions.h"
#include "userFunctions.h"

using namespace vex;

vex::competition Competition;

//This will be used to reset any values that have been used for either auton or user control
void preAuton( void )
{
  Brain.Screen.newLine();
  Brain.Screen.print("Pre-Autonmous is Running");
}

//Autonomous method
void auton ( void )
{
  Brain.Screen.newLine();
  Brain.Screen.print("Skills Autonomous");

  testing1();

  Brain.Screen.newLine();
  Brain.Screen.print("Skills Autonomous Ended");
}

//Sets the controls for all the motors
void userControl( void )
{
  Brain.Screen.newLine();
  Brain.Screen.print("Mecanum Drive");

  //Infinite Loop
  while(1)
  {
      int Ax1Pos = Controller1.Axis1.position();
      int Ax3Pos = Controller1.Axis3.position();
      int Ax4Pos = Controller1.Axis4.position();

    //Actual Joystick Drive and Buttons
    joyStickDrive(Ax1Pos, Ax3Pos, Ax4Pos);

    if(Controller1.ButtonLeft.pressing()){
      testing1();
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

  Brain.Screen.newLine();
  Brain.Screen.print("Match Ended");

  while(1)
  {
    vex::task::sleep(100);
  }
  
}
