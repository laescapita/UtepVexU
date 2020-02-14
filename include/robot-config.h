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
extern motor LFrontConveyor;
extern motor LBackConveyor;
extern motor RFrontConveyor;
extern motor RBackConveyor;


extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );