#pragma once

#include <frc/DoubleSolenoid.h>

class AmpDump {
    public:
        AmpDump();

        void Load();
        void Dump();
        void Reset();
    
    private:
        frc::DoubleSolenoid m_solenoid;
};