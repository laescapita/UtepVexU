using namespace vex;

extern brain Brain;
 
// VEXcode devices
extern motor FLeftMotor;
extern motor BLeftMotor;
extern motor FRightMotor; 
extern motor BRightMotor; 
extern motor LAngle;
extern motor RAngle;
extern motor RArm; 
extern motor LArm; 
extern motor BLeftConveyor;
extern motor BRightConveyor;
// extern motor FLeftConveyor;
// extern motor FRightConveyor;
extern inertial Balance;
extern vision Color;

extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );