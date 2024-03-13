#include "Robot.h"

#include "Runtimes/Auto.h"

#include "utils/RecAutos.h"

void Robot::AutonomousInit() {
  m_AmpDump.Init();

  i = 0;

  // RECORDED AUTO OBJECTS
  
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  std::vector<float> input = {3,123,123,123,123,0};
  StandStill.leftY = input;
}

void Robot::AutonomousPeriodic() {

  if (i < (sizeof(leftX) / sizeof(leftX[0]))) {

    std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    targetOffsetH = table->GetNumber("tx", 0.0);

    // AIM AT TARGET
    if (aBtn[i] == true) {
        m_Drivetrain.Drive(
            -units::meters_per_second_t{deadband(leftY[i])},
            -units::meters_per_second_t{deadband(leftX[i])},
            units::radians_per_second_t{0.5 * targetOffsetH / 27},
            false, true);
    } 

    // DRIVE NORMALLY
    else {
        m_Drivetrain.Drive(
            -units::meters_per_second_t{deadband(leftY[i])},
            -units::meters_per_second_t{deadband(leftX[i])},
            -units::radians_per_second_t{deadband(rightX[i])},
            false, true);
    }

    // AMP DUMP CONTROLS
    if (coX[i]) {
        m_AmpDump.Toggle();
    }

    // INTAKE CONTROLS
    if (coA[i]) {
        m_Intake.Set(1);
    } else {
        m_Intake.Set(0);
    }

    // SHOOTER CONTROLS
    if (coB[i]) {
        m_Shooter.load();
    } else if (coY[i]) {
        m_Shooter.shoot();
    } else {
        m_Shooter.zero();
    }      
      i++;
  }
  else {
    m_Drivetrain.Drive(
      units::meters_per_second_t{0},
      units::meters_per_second_t{0}, 
      units::meters_per_second_t{0},
      false, true
    );
    wpi::outs() << "0,0,0\n";
  }
};