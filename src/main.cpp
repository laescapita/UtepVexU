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

//Globally Initialize Values
vex::brain Brain;

vex::competition Competition;

vex::motor FLeftMotor = vex::motor( vex::PORT1 );
vex::motor BLeftMotor = vex::motor( vex::PORT2 );
vex::motor FRightMotor = vex::motor( vex::PORT3 );
vex::motor BRightMotor = vex::motor( vex::PORT4 );
vex::motor RAngle = vex::motor( vex::PORT5 );
vex::motor LAngle = vex::motor( vex::PORT6 );
vex::motor RArm = vex::motor( vex::PORT7 );
vex::motor LArm = vex::motor( vex::PORT8 );
vex::motor LFrontConveyor = vex::motor( vex::PORT9 );
vex::motor LBackConveyor = vex::motor( vex::PORT10 );
vex::motor RFrontConveyor = vex::motor( vex::PORT11 );
vex::motor RBackConveyor = vex::motor( vex::PORT12 );


vex::controller Controller1 = vex::controller();

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
       moveShaftDown();
    }

    if(Controller1.ButtonX.pressing())
    {
       moveShaftUp();
    }

    if(Controller1.ButtonR1.pressing())
    {
      moveArmDown();
    }

    if(Controller1.ButtonR2.pressing())
    {
      moveArmUp();
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
