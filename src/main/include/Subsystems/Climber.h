#pragma once

#include <rev/CANSparkMax.h>

class Climber {
    public:
        Climber();

        void setClimber(double speed);
    private:
        rev::CANSparkMax m_climbingMotor;
};