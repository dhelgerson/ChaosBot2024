#include "Robot.h"

void Robot::TestInit() {
    m_AmpDump.Init();
}

void Robot::TestPeriodic() {

    m_Drivetrain.Drive(
    -units::meters_per_second_t{deadband(driver.GetLeftY())},
    -units::meters_per_second_t{deadband(driver.GetLeftX())},
    -units::radians_per_second_t{deadband(driver.GetRightX())},
    false, true);
}