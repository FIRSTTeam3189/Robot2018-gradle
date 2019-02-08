#ifndef Wrist_H
#define Wrist_H

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/AnalogPotentiometer.h>
#include "RobotMap.h"
#include "Utils/Piston.h"



using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
using Pot = frc::AnalogPotentiometer;

class Wrist : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	CANTalon* wristMotor;
	Pot* wristPot;
	PistonDouble* wristPiston;
public:
	/*
	 *Provides control for the wrist of the robot.
	 */
	Wrist();
	/*
	 * Controls the power of the motors.
	 * @param power percentage of total power to the motors.
	 */
	void ControlWrist(double power);
	/*
	 * Gets the potentiometer value from the wrist.
	 */
	void InitDefaultCommand();
	void InitHardware();
	void PistonThingyExtend();
	void PistonThingyRetract();
	void UpdateStatus();
};

#endif  // Wrist_H
