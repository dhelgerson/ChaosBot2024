#include "Robot.h"

void Robot::TestInit() {
    m_AmpDump.Init();
}

void Robot::TestPeriodic() {
    nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 0);
    nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 0);
    std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    targetOffsetH = table->GetNumber("tx", 0.0);
    targetSize = table->GetNumber("ta", 0.0);

    if (targetSize < 5 && targetSize > 1) {
        m_Drivetrain.Drive(
            units::meters_per_second_t{0.5 * targetOffsetH / 27},
            units::meters_per_second_t{0.0},
            units::radians_per_second_t{.15}, false, true);
    } else {
        m_Drivetrain.Drive(
            units::meters_per_second_t{0.5 * targetOffsetH / 27}, 
            units::meters_per_second_t{0.0}, 
            units::radians_per_second_t{0.0}, 
            false, true);
    }
}