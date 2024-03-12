// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>
 
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/drive/MecanumDrive.h>
#include <frc/XboxController.h>
#include <frc/Timer.h>
#include <cmath>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <iostream>

#include "Subsystems/Drivetrain.h"
#include "Subsystems/AmpDump.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Climber.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

 private:

  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string followBot = "The Bot Follows";
  const std::string spinnyBoi = "He do a SPIEN";
  std::string m_autoSelected;
  bool targetSeen;
  double targetOffsetH;
  double targetSize;

  Drivetrain m_Drivetrain;
  AmpDump m_AmpDump;
  Intake m_Intake;
  Shooter m_Shooter;
  Climber m_Climber;
  

  double driveSpeed = .5;

  frc::XboxController driver{0};
  frc::XboxController copilot{1};

  double drivespeed = 0.5;
  float deadband(const float input) {
    const float deadbandcutoff = 0.1f;
    if(fabs(input) < deadbandcutoff) {
      return 0;
    } else {
      return input;
    }
  }
};