#ifndef Wrist_H
#define Wrist_H

#include <Commands/Subsystem.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/MotorControl/ControlMode.h>
#include <SmartDashboard/SmartDashboard.h>
#include <AnalogPotentiometer.h>
#include "RobotMap.h"
#include "Utils/Piston.h"



using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
using Pot = AnalogPotentiometer;

class Wrist : public Subsystem {
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
	double GetWristPot();
	void InitDefaultCommand();
	void InitHardware();
	void PistonThingyExtend();
	void PistonThingyRetract();
	void PistonThingyToggle();
	void UpdateStatus();
};

#endif  // Wrist_H
