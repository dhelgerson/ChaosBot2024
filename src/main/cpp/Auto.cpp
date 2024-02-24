#include "Robot.h"

void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == followBot) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == followBot) {
    m_Drivetrain.Drive(
      units::meters_per_second_t{1.0},
      units::meters_per_second_t{0.0}, 
      units::radians_per_second_t{0.0}, 
      false, true);
  } else if (m_autoSelected == spinnyBoi) {
    m_Drivetrain.Drive(
      units::meters_per_second_t{0.0}, 
      units::meters_per_second_t{0.0}, 
      units::radians_per_second_t{1.0}, 
      false, true);
  } else {
    // Default Auto goes here
  }
}