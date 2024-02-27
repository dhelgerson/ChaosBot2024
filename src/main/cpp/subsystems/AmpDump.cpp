#include "Subsystems/AmpDump.h"
#include "Constants/AmpDumpConstants.h"

using namespace PneumaticsConstants;

AmpDump::AmpDump() : m_solenoid{frc::PneumaticsModuleType::CTREPCM, kDumpForward, kDumpReverse},
    m_compressor{kPCMCanId, frc::PneumaticsModuleType::CTREPCM} {}

void AmpDump::Init() {
    m_compressor.EnableDigital();
    m_solenoid.Set(frc::DoubleSolenoid::kReverse);
}

void AmpDump::Load() {};

void AmpDump::Toggle() {
    m_solenoid.Toggle();
};
