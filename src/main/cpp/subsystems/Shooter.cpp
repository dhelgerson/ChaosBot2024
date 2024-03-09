#include "Subsystems/Shooter.h"
#include "Constants/SubsystemConstants.h"

using namespace ShooterConstants;

Shooter::Shooter() : m_shooterOne{kShooterCANId}, 
    m_shooterTwo{kFollowerOneCANId}, 
    m_shooterThree{kFollowerTwoCANId}
    {};

void Shooter::init() {
}

void Shooter::load() {
    m_shooterOne.Set(-0.1);
    m_shooterTwo.Set(-0.1);
    m_shooterThree.Set(-0.1);
}

void Shooter::shoot() {
    m_shooterOne.Set(-1);
    m_shooterTwo.Set(-1);
    m_shooterThree.Set(-.2);
}

void Shooter::zero() {
    m_shooterOne.Set(0);
    m_shooterTwo.Set(0);
    m_shooterThree.Set(0);
}