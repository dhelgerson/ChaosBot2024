#include "SwerveModule.h"

SwerveModule::SwerveModule(int newDriveId, int newTurnId, int newEncoderId) {
    driveMotorId = newDriveId;
    turnMotorId = newTurnId;
    turnEncoderId = newEncoderId;  
}

double SwerveModule::getAngle() {
    return turnEncoder.GetAbsolutePosition();
};

void SwerveModule::setState(frc::SwerveModuleState desiredState) {
            auto optimizedState = frc::SwerveModuleState::Optimize(desiredState,
                units::radian_t(turnEncoder.GetAbsolutePosition()));

            driveMotor.Set(double(optimizedState.speed / 4.877));
            turnMotor.Set(double(optimizedState.angle.Radians() / (2 * M_PI)));
        };