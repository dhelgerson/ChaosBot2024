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
    nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("pipeline", 0);
    nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 0);
    std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    targetOffsetH = table->GetNumber("tx", 0.0);
    targetSize = table->GetNumber("ta", 0.0);

    if (targetSize < 5 && targetSize > 1) {
        m_robotDrive->DriveCartesian(
            (0.5 * targetOffsetH / 27),
            0,
            .15);
    } else {
        m_robotDrive->DriveCartesian(
            (0.5 * targetOffsetH / 27), 0, 0);
    }
  } else if (m_autoSelected == spinnyBoi) {
    m_robotDrive->DriveCartesian(1, 0, 0);
  } else {
    // Default Auto goes here
  }
}