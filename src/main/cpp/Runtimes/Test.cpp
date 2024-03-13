#include "Robot.h"
#include "Runtimes/Test.h"

// library for file writes
// #include <iostream>
#include <fstream>

void Robot::TestInit() {
    m_AmpDump.Init();
    
    // open file for writing
    f.open("/u/autorec.csv");
    f << "float leftX,float leftY,float rightX,bool aBtn,bool coA,bool coB,bool coX,bool coY" << std::endl;
}

void Robot::TestPeriodic() {
    // read inputs into variables so they're consistent w/
    // inputs sent to subsystem
    leftX = driver.GetLeftX();
    leftY = driver.GetLeftY();
    rightX = driver.GetRightX();
    aBtn = driver.GetAButton();
    coA = copilot.GetAButton();
    coB = copilot.GetBButton();
    coX = copilot.GetXButtonPressed();
    coY = copilot.GetYButton();

    

    std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    targetOffsetH = table->GetNumber("tx", 0.0);

    // AIM AT TARGET
    if (aBtn == true) {
        m_Drivetrain.Drive(
            -units::meters_per_second_t{deadband(leftY)},
            -units::meters_per_second_t{deadband(leftX)},
            units::radians_per_second_t{0.5 * targetOffsetH / 27},
            false, true);
    } 

    // DRIVE NORMALLY
    else {
        m_Drivetrain.Drive(
            -units::meters_per_second_t{deadband(leftY)},
            -units::meters_per_second_t{deadband(leftX)},
            -units::radians_per_second_t{deadband(rightX)},
            false, true);
    }

    // AMP DUMP CONTROLS
    if (coX) {
        m_AmpDump.Toggle();
    }

    // INTAKE CONTROLS
    if (coA) {
        m_Intake.Set(1);
    } else {
        m_Intake.Set(0);
    }

    // SHOOTER CONTROLS
    if (coB) {
        m_Shooter.load();
    } else if (coY) {
        m_Shooter.shoot();
    } else {
        m_Shooter.zero();
    }

    // writing to file after sending th inputs to avoid any problems w/ latency
    f << leftX << "," << leftY << "," << rightX << "," << aBtn << "," << coA << "," << coB << "," << coX << "," << coY << std::endl;

}