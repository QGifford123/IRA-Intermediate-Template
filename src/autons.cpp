#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "lift.h"
#include "util.h"
#include "autons.h"

using namespace vex;

void rightAuton() {

  Controller.Screen.clearLine(3);
  Controller.Screen.setCursor(3, 1);
  Controller.Screen.print("start auton");

  drive Chassis(3.25, 4.0/3, 24, 0, 0, leftDrive, rightDrive, PORT1);
  intake Intake(intakeMotors);

  Chassis.driveDistance(24, 1, 1, 0, 0.1);
  wait(5, sec);
  Chassis.turnAndDriveToPoint(72, 24, 2, 0.5, 0, 0.05, 1, 1, 0, 0.1);
  wait(5, sec);
}


void leftAuton() {
  
  //Use functions to create an auton for the left side of the field

}

void skillsAuton() {
  
  //Use functions to create a programming skills routine
  
}