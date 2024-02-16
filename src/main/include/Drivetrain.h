#pragma once

#include "SwerveModule.h"

class Drivetrain {
    public:
        void Drive(double x, double y, double z);
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