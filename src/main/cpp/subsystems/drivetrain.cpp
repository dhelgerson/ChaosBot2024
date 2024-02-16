#include "Drivetrain.h"

void Drivetrain::Drive(double x, double y, double z) {
    units::meters_per_second_t max_speed{4.877};
    units::radians_per_second_t max_rot{4.877};
    frc::ChassisSpeeds speeds{(x * max_speed), (y * max_speed), (z * max_rot)};
    auto [fl, fr, bl, br] = m_kinematics.ToSwerveModuleStates(speeds);
    frontLeft.setState(fl);
    frontRight.setState(fr);
    rearLeft.setState(bl);
    rearRight.setState(br);
}
