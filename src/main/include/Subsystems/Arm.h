#ifndef Arm_H
#define Arm_H
//#define ONE_PORT

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/AnalogPotentiometer.h>
#include <frc/AnalogInput.h>
#include <deque>
#include "Utils/Piston.h"
#include "RobotMap.h"
#include "Utils/Point.h"
#include <deque>

using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
using Pot = frc::AnalogPotentiometer;
using feedbackdev = ctre::phoenix::motorcontrol::FeedbackDevice;

class Arm: public frc::Subsystem {
private:
	CANTalon* shoulderMotor;
	//CANTalon* shoulderMotor2;
	//CANTalon* elbowMotor;
	//Pot* elbowPot; //= Pot(ELBOW_POT, 359, 0);
	//Pot* shoulderPot; // = Pot(SHOULDER_POT, 359, 0);
	//PistonSingle* ElbowBrakePiston;
	//std::deque<double> PotQueue;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Arm();
	void InitDefaultCommand();
	/**
	 * controls the shoulder motor of the arm
	 * @param power in range from -1 to 1
	 */
	void ControlShoulder(double power);
	/**
	 * gets the value for the potentiometer on the shoulder motor
	 * @returns value from 0 to 1023
	 */

	//double GetShoulderPot();
	//double ShoulderToPot(double angle);
	void stop();
	void InitHardware();

	void UpdateStatus();

	void GotoPosition(double);

	// double ReturnPIDInput();
};



#endif  // Arm_H
