#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;
  
// VEXcode device constructors 
motor FLeftMotor = motor(PORT1, ratio18_1, false);
motor BLeftMotor = motor(PORT11, ratio18_1, false);
motor FRightMotor = motor(PORT10, ratio18_1, true);
motor BRightMotor = motor(PORT20, ratio18_1, true);
motor RAngle = motor(PORT5, ratio18_1, true);
motor LAngle = motor(PORT6, ratio18_1, false);
motor LArm = motor(PORT4, ratio18_1, false);
motor RArm = motor(PORT7, ratio18_1, true);
motor LFrontConveyor = motor( PORT14, ratio18_1, true );
motor LBackConveyor = motor( PORT15, ratio18_1, true );
motor RFrontConveyor = motor( PORT16, ratio18_1, false );
motor RBackConveyor = motor( PORT17, ratio18_1, false );

controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}