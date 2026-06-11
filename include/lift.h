/* Helps prevent header files from being included multiple times*/
#pragma once
#include "vex.h"

class lift {

    public:
        lift(int Lift1Port, int Lift2Port, vex::triport::port pistonPort);

        motor Lift1;
        motor Lift2;
        digital_out DoubleActingPiston;

        void liftArm(double degrees, double speed);
        void clamp();
};
