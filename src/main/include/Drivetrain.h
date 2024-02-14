#include <Robot.h>
#include <SwerveModule.h>

class Drivetrain {
    public:
        void Drive(double x, double y, double z);
    private:
        frc::Translation2d fLlocation;
        frc::Translation2d fRlocation;
        frc::Translation2d rLlocation;
        frc::Translation2d rRlocation;

        frc::SwerveDriveKinematics<4> m_kinematics;
        SwerveModule frontLeft;
        SwerveModule frontRight;
        SwerveModule rearLeft;
        SwerveModule rearRight;
};