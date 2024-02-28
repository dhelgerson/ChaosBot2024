#pragma once

#include <rev/CANSparkMax.h>

class Intake {
    public:
        Intake();

        void Set(double power);
    private:
        rev::CANSparkMax m_intakeMotors;
};