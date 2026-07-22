// src/robot-config.cpp
#include "robot-config.h"

using namespace vex;

//Configuration!

/* 
 * Reminders: 
 * Make sure that all your ports are different and correct! 
 * Make sure all of your motor + piston names are different and not confusing.
 * If it seems like some of your motors are running against eachother in the drivetrain, try switching around the true/false
*/

//DON'T CHANGE THE NAMES OF THE MOTORS OR SENSORS. Changing the ports to reflect your robot is ok.

brain Brain;
controller Controller(controllerType::primary);
motor LB(PORT6, ratio6_1, true); //Left Back Motor
motor LM(PORT5, ratio6_1, true); //Left Middle Motor
motor LF(PORT4, ratio6_1, true); //Left Front Motor
motor RB(PORT1, ratio6_1, false); //Right Back Motor
motor RM(PORT2, ratio6_1, false); //Right Middle Motor
motor RF(PORT3, ratio6_1, false); //Right Front Motor


motor_group leftDrive(LF, LM, LB);
motor_group rightDrive(RF, RM, RB);

motor Lift1(PORT10, gearSetting::ratio18_1, true); //Lift motor
motor Lift2(PORT11, gearSetting::ratio18_1, true); //Lift motor

digital_out DoubleActingPiston(Brain.ThreeWirePort.A);
digital_out SingleActingPiston(Brain.ThreeWirePort.B);

motor intakeMotor(PORT14, ratio18_1, false);
motor middleIntakeMotor(PORT13, ratio18_1, true);
motor  bottomIntakeMotor(PORT12, ratio18_1, false); 

motor_group intakeMotors(intakeMotor, middleIntakeMotor, bottomIntakeMotor);

inertial InertialSensor(PORT7);

optical OpticalSensor(PORT21);

void vexcodeInit() {
  InertialSensor.calibrate();
  DoubleActingPiston.set(false); // retracted
  SingleActingPiston.set(false); // off
  while (InertialSensor.isCalibrating()) {
    task::sleep(100);
  }
  Controller.rumble("...");
}