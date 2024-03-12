#include "Robot.h"
#include "Runtimes/Test.h"

// library for file writes
// #include <iostream>
#include <fstream>

void Robot::TestInit() {
    m_AmpDump.Init();
    
    // open file for writing
    f.open("/u/autorec.csv");
    f << "leftX,leftY,rightX,aBtn" << std::endl;
}

void Robot::TestPeriodic() {
    // read inputs into variables so they're consistent w/
    // inputs sent to subsystem
    leftX = driver.GetLeftX();
    leftY = driver.GetLeftY();
    rightX = driver.GetRightX();
    aBtn = driver.GetAButton();

    m_Drivetrain.Drive(
    -units::meters_per_second_t{deadband(leftY)},
    -units::meters_per_second_t{deadband(leftX)},
    -units::radians_per_second_t{deadband(rightX)},
    false, true);

    // writing to file after sending th inputs to avoid any problems w/ latency
    f << leftX << "," << leftY << "," << rightX << "," << aBtn << std::endl;

}