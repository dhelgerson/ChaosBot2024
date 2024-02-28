#include "Subsystems/Intake.h"
#include "Constants/SubsystemConstants.h"

using namespace IntakeConstants;

Intake::Intake() : m_intakeMotors{kIntakeCANId, rev::CANSparkMax::MotorType::kBrushed} {};

void Intake::Set(double power) {
    m_intakeMotors.Set(power);
};