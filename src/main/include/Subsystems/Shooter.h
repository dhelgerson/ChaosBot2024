#pragma once

#include "ctre/Phoenix.h"

class Shooter {
    public:
        Shooter();

        void init();

        void load();
        void shoot();
        void zero();
    private:
        WPI_TalonFX m_shooterOne;
        WPI_TalonFX m_shooterTwo;
        WPI_TalonFX m_shooterThree;
};