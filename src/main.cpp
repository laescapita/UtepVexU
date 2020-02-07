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
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

vex::brain Brain;

vex::competition Competition;

vex::motor FLeftMotor = vex::motor( vex::PORT1 );
vex::motor BLeftMotor = vex::motor( vex::PORT2 );
vex::motor FRightMotor = vex::motor( vex::PORT3 );
vex::motor BRightMotor = vex::motor( vex::PORT4 );


void preAuton( void )
{

}


void auton ( void )
{

}

void userControl( void )
{

}





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
