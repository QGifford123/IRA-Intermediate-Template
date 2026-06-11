#include "vex.h"

class drive {

    private:
        double wheelDiameter;
        double gearRatio;

        //default tuning constants for straight line driving
        double drive_kP = 6;
        double drive_kI = 0.1;
        double drive_kD = 0.5;

        //default tuning constants for turning
        double turn_kP = 1;
        double turn_kI = 0.01;
        double turn_kD = 0.1;
    
    public:
        vex::motor_group driveL;
        vex::motor_group driveR;
        vex::inertial Inertial;

        drive(double WheelDiameter, double GearRatio, vex::motor_group DriveL, vex::motor_group DriveR, int inertialPort);

        void driveStop();

        void driveDistance(double distance);
        void driveDistance(double distance, double tolerance);
        void driveDistance(double distance, double tolerance, double kP, double kI, double kD);

        void turnAngle(double angle);
        void turnAngle(double angle, double tolerance);
        void turnAngle(double angle, double tolerance, double kP, double kI, double kD);

        void turnHeading(double heading);
        void turnHeading(double heading, double tolerance);
        void turnHeading(double heading, double tolerance, double kP, double kI, double kD);
};