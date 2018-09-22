#ifndef Arm_H
#define Arm_H
//#define ONE_PORT

#include <Commands/PIDSubsystem.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>
#include <ctre/phoenix/MotorControl/ControlMode.h>
#include <SmartDashboard/SmartDashboard.h>
#include <AnalogPotentiometer.h>
#include <AnalogInput.h>
#include <deque>
#include "Utils/Piston.h"
#include "RobotMap.h"
#include "Utils/Point.h"
#include <deque>

using CANTalon = ctre::phoenix::motorcontrol::can::TalonSRX;
using ControlMode = ctre::phoenix::motorcontrol::ControlMode;
using Pot = AnalogPotentiometer;

class Arm: public PIDSubsystem {
private:
	CANTalon* shoulderMotor;
	//CANTalon* shoulderMotor2;
	//CANTalon* elbowMotor;
	//Pot* elbowPot; //= Pot(ELBOW_POT, 359, 0);
	Pot* shoulderPot; // = Pot(SHOULDER_POT, 359, 0);
	//PistonSingle* ElbowBrakePiston;
	std::deque<double> PotQueue;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Arm();
	/**
	 * returns the Current location for the wrist in x y coordinates
	 */
	Point GetCurrentLocation();
	/**
	 * returns the current angles of the shoulder
	 */
	double GetShoulderAngle();
	/**
	 * returns the current angles of the elbow
	 */
	double GetElbowAngle();
	/**
	 * returns angles required for the x y coordinates given returns angles in given double array
	 */
	void GetAnglesForTarget(double x, double y, double angles[2]);
	/**
	 * returns angles required for a close point to current along the line to destination coordinates
	 */
	void GetNewPointOnLine(double x, double y, double angles[2]);
	void InitDefaultCommand();
	/**
	 * controls the shoulder motor of the arm
	 * @param power in range from -1 to 1
	 */
	void ControlShoulder(double power);
	/**
	 * controls the elbow motor of the arm
	 * @param power in range from -1 to 1
	 */
	void ControlElbow(double power);
	/**
	 * gets the value for the potentiometer on the shoulder motor
	 * @returns value from 0 to 1023
	 */

	double GetShoulderPot();
	/**
	 * gets the value for the potentiometer on the elbow motor
	 * @returns value from 0 to 1023
	 */

	double GetElbowPot();
	//
	/**
	 * get
	 * finds percent of the total span from 0-1 then finds the potentiometer value for the given angle value
	 * @param angle in radians of angle value
	 * @return the equivalent potentiometer value for the given angle value
	 */
	double ShoulderToPot(double angle);
	double ElbowToPot(double angle);
	void stop();
	void InitHardware();


	void ElbowBrake();

	void ElbowRelease();

	void ShoulderBrake();

	void ShoulderRelease();
	void UpdateStatus();
	bool isNearPot(double position);
	bool GotoPot(double pot);

	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void SetPIDPoint(double amount);
};



#endif  // Arm_H
