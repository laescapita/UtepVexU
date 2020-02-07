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

using namespace vex;

//Globally Initialize Values
vex::brain Brain;

vex::competition Competition;

vex::motor FLeftMotor = vex::motor( vex::PORT1 );
vex::motor BLeftMotor = vex::motor( vex::PORT2 );
vex::motor FRightMotor = vex::motor( vex::PORT3 );
vex::motor BRightMotor = vex::motor( vex::PORT4 );

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
  FLeftMotor.setVelocity(100, vex::velocityUnits::pct);
  BLeftMotor.setVelocity(100, vex::velocityUnits::pct);
  FRightMotor.setVelocity(100, vex::velocityUnits::pct);
  BRightMotor.setVelocity(100, vex::velocityUnits::pct);

  FLeftMotor.spin(forward);
  BLeftMotor.spin(forward);
  FRightMotor.spin(forward);
  BRightMotor.spin(forward);

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
    FRightMotor.spin(vex::directionType::fwd, (Ax3Pos - Ax1Pos - Ax4Pos), vex::velocityUnits::pct);
    FLeftMotor.spin(vex::directionType::fwd, (Ax3Pos + Ax1Pos + Ax4Pos), vex::velocityUnits::pct);
    BRightMotor.spin(vex::directionType::fwd, (Ax3Pos - Ax1Pos + Ax4Pos), vex::velocityUnits::pct);
    BLeftMotor.spin(vex::directionType::fwd, (Ax3Pos + Ax1Pos - Ax4Pos), vex::velocityUnits::pct);

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
