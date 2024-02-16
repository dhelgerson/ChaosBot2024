#include "Robot.h"

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {

    std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    targetOffsetH = table->GetNumber("tx", 0.0);

    if (driver.GetAButton() == true) {
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 0);
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 0);
        m_Drivetrain.Drive(
            (0.5 * targetOffsetH / 27),
            (driveSpeed * deadband(driver.GetLeftX())),
            (-driveSpeed * deadband(driver.GetLeftY())));
    } else {
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 1);
        nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 1);
        m_Drivetrain.Drive(
            (driveSpeed * deadband(driver.GetRightX())), 
            (driveSpeed * deadband(driver.GetLeftX())),
            (-driveSpeed * deadband(driver.GetLeftY())));
    }
}