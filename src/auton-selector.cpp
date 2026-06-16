#include "vex.h"
#include "auton-selector.h"
#include "robot-config.h"

using namespace vex;

autonSelector::autonSelector(int startingAuton, int TotalAutons) {
  autonNumber = startingAuton;
  totalAutons = TotalAutons;
}

int autonSelector::getSelectedAuton() {
  return autonNumber;
}

void autonSelector::chooseAuton() {

  std::string autonNames[] = {"first", "second", "third"};

  Controller.Screen.clearLine(3);
  Controller.Screen.setCursor(3, 1);
  Controller.Screen.print("Auton: %s", autonNames[autonNumber].c_str());

  bool buttonHeld = false;

  while (true) {
  
    if(buttonHeld == true && !(Controller.ButtonLeft.pressing() || Controller.ButtonRight.pressing())) {
      buttonHeld = false;
    }

    if(!buttonHeld && (Controller.ButtonLeft.pressing() || Controller.ButtonRight.pressing())) {
      if (Controller.ButtonLeft.pressing() && autonNumber > 1) {
        autonNumber--;
      }
      else if(Controller.ButtonLeft.pressing()) {
        autonNumber = totalAutons;
      }
      else if(Controller.ButtonRight.pressing() && autonNumber < totalAutons) {
        autonNumber++;
      }
      else if(Controller.ButtonRight.pressing()) {
        autonNumber = 1;
      }
      buttonHeld = true;
      Controller.Screen.clearLine(3);
      Controller.Screen.setCursor(3, 1);
      Controller.Screen.print("Auton: %s", autonNames[autonNumber - 1].c_str());
    } 

    wait(20, msec);
  }

  Controller.Screen.clearLine(3);
  Controller.Screen.setCursor(3, 1);
  Controller.Screen.print("Auton selected: ");
  Controller.Screen.print(autonNumber);
  wait(2, sec);
  Controller.Screen.clearLine(3);
}