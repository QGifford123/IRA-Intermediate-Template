#include "vex.h"
#include "util.h"
#include "drive.h"
#include "PID.h"

using namespace vex;

drive::drive(double WheelDiameter, double GearRatio, vex::motor_group driveLeft, vex::motor_group driveRight, int inertialPort) :
driveL(driveLeft), driveR(driveRight), Inertial(inertialPort) {
    wheelDiameter = WheelDiameter;
    gearRatio = GearRatio;
}

void drive::driveStop() {
    driveL.stop(brake);
    driveR.stop(brake);
}

void drive::driveDistance(double distance) {
    driveDistance(distance, 1, drive_kP, drive_kI, drive_kD);
}

void drive::driveDistance(double distance, double tolerance) {
    driveDistance(distance, tolerance, drive_kP, drive_kI, drive_kD);
}

void drive::driveDistance(double distance, double tolerance, double kP, double kI, double kD) {
    setDTPosition(0);
    double error = distance;

    PID drivePID(distance, kP, kI, kD, tolerance);

    double avgPos = degreesToInches((driveL.position(degrees) + driveR.position(degrees))/2);

    while(fabs(error) > tolerance) {
        avgPos = degreesToInches((driveL.position(degrees) + driveR.position(degrees))/2);
        error = distance - avgPos;

        double driveTotal = drivePID.calculateTotal(error);

        driveL.spin(forward, driveTotal, percent);
        driveR.spin(forward, driveTotal, percent);
        wait(drivePID.getUpdateTime(), msec);
    }
}

void drive::turnAngle(double angle) {
    turnAngle(angle, 1, turn_kP, turn_kI, turn_kD);
}

void drive::turnAngle(double angle, double tolerance) {
    turnAngle(angle, tolerance, turn_kP, turn_kI, turn_kD);
}

void drive::turnAngle(double angle, double tolerance, double kP, double kI, double kD) {
    Inertial.setRotation(0, degrees);
    double error = angle;

    PID turnPID(angle, kP, kI, kD, tolerance);

    double measuredAngle = Inertial.rotation(degrees);

    while(fabs(error) > tolerance) {
        measuredAngle = Inertial.rotation(degrees);
        error = angle - measuredAngle;

        double turnTotal = turnPID.calculateTotal(error);

        driveL.spin(forward, turnTotal, percent);
        driveR.spin(reverse, turnTotal, percent);
        wait(turnPID.getUpdateTime(), msec);
    }
}