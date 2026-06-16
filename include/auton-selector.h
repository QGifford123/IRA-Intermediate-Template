/* Helps prevent header files from being included multiple times*/
#pragma once

class autonSelector {

    private:
        int autonNumber;
        int totalAutons;

    public:
        autonSelector(int startingAuton, int TotalAutons);
        int getSelectedAuton();
        void chooseAuton();
};





