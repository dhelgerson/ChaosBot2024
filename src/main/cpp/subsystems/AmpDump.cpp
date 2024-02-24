#include "Subsystems/AmpDump.h"

AmpDump::AmpDump() : m_solenoid{frc::PneumaticsModuleType::CTREPCM, 0, 1} {}

void AmpDump::Load() {};

void AmpDump::Dump() {
    m_solenoid.Set(frc::DoubleSolenoid::kForward);
};

void AmpDump::Reset() {
    m_solenoid.Set(frc::DoubleSolenoid::kReverse);
};