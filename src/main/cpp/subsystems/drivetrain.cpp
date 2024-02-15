#include <Robot.h>
#include <SwerveModule.h>

class Drivetrain {
    public:
        void Drive(double x, double y, double z) {
            auto max_speed = 4.877_mps;
            frc::ChassisSpeeds speeds{(x * max_speed), (y * max_speed), (z * max_speed)};
            auto [fl, fr, bl, br] = m_kinematics.ToSwerveModuleStates(speeds);
            frontLeft.setState(fl);
            frontRight.setState(fr);
            rearLeft.setState(bl);
            rearRight.setState(br);
        }
    private:
        frc::Translation2d fLlocation{.314_m, .306_m};
        frc::Translation2d fRlocation{-.314_m, .306_m};
        frc::Translation2d rLlocation{.314_m, -.306_m};
        frc::Translation2d rRlocation{-.314_m, -.306_m};

        frc::SwerveDriveKinematics<4> m_kinematics{fLlocation, fRlocation, rLlocation, rRlocation};

        SwerveModule frontLeft{20, 59, 10};
        SwerveModule frontRight{21, 60, 11};
        SwerveModule rearLeft{23, 62, 13};
        SwerveModule rearRight{22, 61, 12};
};