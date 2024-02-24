#include "Robot.h"

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {

    std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    targetOffsetH = table->GetNumber("tx", 0.0);

    // AIM AT TARGET
    if (driver.GetAButton() == true) {
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 0);
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 0);
        m_Drivetrain.Drive(
            -units::meters_per_second_t{deadband(driver.GetLeftY())},
            -units::meters_per_second_t{deadband(driver.GetLeftX())},
            units::radians_per_second_t{0.5 * targetOffsetH / 27},
            false, true);
    } 
    
    // DRIVE NORMALLY
    else {
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 1);
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 1);
        m_Drivetrain.Drive(
            -units::meters_per_second_t{deadband(driver.GetLeftY())},
            -units::meters_per_second_t{deadband(driver.GetLeftX())},
            -units::radians_per_second_t{deadband(driver.GetRightX())},
            false, true);
    }

    // AMP DUMP CONTROLS
    if (copilot.GetAButtonPressed()) {
        m_AmpDump.Dump();
    }
    if (copilot.GetAButtonReleased()) {
        m_AmpDump.Reset();
    }


}