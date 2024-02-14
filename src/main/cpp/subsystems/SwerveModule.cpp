#include "SwerveModule.h"

class SwerveModule {

    public:
        SwerveModule(int driveMotorId, int turnMotorId, int turnEncoderId) {
            int driveMotorId = driveMotorId;
            int turnMotorId = turnMotorId;
            int turnEncoderId = turnEncoderId;  
        }

        double getAngle() {
            return turnEncoder.GetAbsolutePosition();
        };

        void setState(frc::SwerveModuleState desiredState) {
            auto optimizedState = frc::SwerveModuleState::Optimize(desiredState,
                units::radian_t(turnEncoder.GetAbsolutePosition()));

            driveMotor.Set(double(optimizedState.speed));
            turnMotor.Set(double(optimizedState.angle.Radians() / (2 * M_PI)));
        };

    private:
        int driveMotorId;
        int turnMotorId;
        int turnEncoderId;

        WPI_TalonFX driveMotor{driveMotorId};
        rev::CANSparkMax turnMotor{turnMotorId, rev::CANSparkMax::MotorType::kBrushless};
        WPI_CANCoder turnEncoder{turnEncoderId};
};