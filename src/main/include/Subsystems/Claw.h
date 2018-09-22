#ifndef Claw_H
#define Claw_H

#include <Commands/Subsystem.h>
#include"Utils/Piston.h"
#include<ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include "DigitalInput.h"

using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;


class Claw : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* Left;
	CANTalon* Right;
	Piston* TheOneTheOnlyThePiston;
	DigitalInput* limitSwitch;
//meme

	//"Make the robot do the thing, go" -Alex

public:
	/*
	 * Starts the claw movement
	 * Sets the power and initializes the hardware
	 * Three claw controls, opening, closing,
	 * and toggling the state of the claw
	 */
	Claw();
	void InitDefaultCommand();
	void SetPower(double power);
	void InitHardware();
	void ClawOpen();
	void ClawClose();
	void ClawToggle();
	bool IsBoxIn();
};

#endif  // Claw_H
