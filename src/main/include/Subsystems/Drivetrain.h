#ifndef DriveTrain_H
#define DriveTrain_H

#include <frc/AnalogGyro.h>
#include <frc/AnalogInput.h>
#include <frc/AnalogPotentiometer.h>
#include <frc/commands/Subsystem.h>
#include <frc/Encoder.h>
#include <frc/RobotDrive.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"
#include "Utils/Piston.h"


using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;

enum class DriveDirection{
	Forward,
	Left,
	Right,
	Backward,
	AutoTurn,
	AutoTurnOpposite // opposite of AutoTurn
};

/**
 * The DriveTrain subsystem incorporates the sensors and actuators attached to
 * the robots chassis. These include four drive motors, a left and right encoder
 * and a gyro.
 */
class Drivetrain: public frc::Subsystem {
public:
	Drivetrain();

	/**
	 * When no other command is running let the operator drive around
	 * using the PS3 joystick.
	 */
	void InitDefaultCommand() override;

	/**
	 * The log method puts interesting information to the SmartDashboard.
	 */
	void Log();
	/**
	 *straight drive for drivetrain
	 *@param power to run all motors at for the drivetrain
	 */
	void Drive(double power);

	/**
	 * Tank style driving for the DriveTrain.
	 * @param left Speed in range [-1,1]
	 * @param right Speed in range [-1,1]
	 */
	void Drive(double left, double right);

	//TODO make this a thing, it should correct driving to preform straight driving.
	void DriveEncoders(double power, DriveDirection dir);

	void EngageDrivetrain();
	/**
	 * Stops all motors
	 */
	void Stop();


	/**
	 * Reset the robots sensors to the zero states.
	 */
	void Reset();

	/**
	 * @return The distance driven (average of left and right encoders).
	 */
	double GetDistance();

	double GetDistanceInInches();

	double GetRightEncoderDistance();

	double GetLeftEncoderDistance();

	void InitHardware();
private:
	CANTalon* frontLeft;
	CANTalon* rearLeft;
	CANTalon* frontRight;
	CANTalon* rearRight;
	Piston* winchGearboxPiston;
	Piston* winchShaftPiston;
	//Encoder* leftEncoder;
	//Encoder* rightEncoder;

	//frc::Encoder rightEncoder { 3, 4 };
	//frc::AnalogInput rangefinder { 6 };
	//frc::AnalogGyro gyro { 1 };
};

#endif  // DriveTrain_H
