#include "Robot.h"

void Robot::TestInit() {
}

void Robot::TestPeriodic() {
    nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 0);
    nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 0);
    std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    targetOffsetH = table->GetNumber("tx", 0.0);
    targetSize = table->GetNumber("ta", 0.0);

    if (targetSize < 5 && targetSize > 1) {
        Drivetrain.Drive(
            (0.5 * targetOffsetH / 27),
            0,
            .15);
    } else {
        Drivetrain.Drive(
            (0.5 * targetOffsetH / 27), 0, 0);
    }
}