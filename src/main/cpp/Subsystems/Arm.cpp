#include "Subsystems/Arm.h"
#include "Constants.h"
#include "../RobotMap.h"
#include <math.h>
#include <iostream>
#include <algorithm>
#include "Commands/JoystickArmControl.h"
#include <SmartDashboard/SmartDashboard.h>
#include <Commands/JoystickArmControl.h>

Arm::Arm() :
	//PIDSubsystem("arm", 0.26, 0.0014, 0.015) {
	PIDSubsystem("arm", 0.19, 0.0005, 0.000) { // Known GOOD
	SetInputRange(0, 180);
	GetPIDController()->SetContinuous(false);
	GetPIDController()->SetAbsoluteTolerance(16);
	//GetPIDController()->Disable();
}

void Arm::InitDefaultCommand() {
	//SetDefaultCommand(new JoystickArmControl());
}

// Put functiom for controlling this subsystem
// here. Call these from Commands.
void Arm::ControlShoulder(double power) {
	shoulderMotor->Set(ControlMode::PercentOutput, power);
	//shoulderMotor2->Set(ControlMode::PercentOutput, power);
}
void Arm::ControlElbow(double power) {
	//elbowMotor->Set(ControlMode::PercentOutput, power);
}

double Arm::GetShoulderPot() {
//	return ((shoulderPot->GetAverageVoltage() - VOLTAGE_LOW) / VOLTAGE_RANGE) * POT_RANGE;

	return shoulderPot->Get();
}
double Arm::GetElbowPot() {
	//return elbowPot->Get();
}

void Arm::GetAnglesForTarget(double x, double y, double angles[3]) {
	//get the distance between the destination and the shoulder joint(origin)
	double length = sqrt(pow(x, 2) + pow(y, 2));
	//calculate the inner elbow angle with law of cosines.
	double inner_elbow_angle = acos(
			(((ARM_TWO_LENGTH * ARM_TWO_LENGTH)
					+ (ARM_ONE_LENGTH * ARM_ONE_LENGTH) - (length * length))
					/ (2 * ARM_TWO_LENGTH * ARM_ONE_LENGTH)));
	//PI - inner_angle to get the angle the arm needs to go to.
	angles[1] = M_PI - inner_elbow_angle;
	// if the point is near the back of the bot negate the angle
	if (x >= ARM_SWITCH)
		angles[1] = -angles[1];
	//Calculate the angle between the line between shoulder(origin)
	// and destination point to go to using the law of sines with the elbow angle.
	double inner_shoulder_angle = asin(
			((ARM_TWO_LENGTH * sin(inner_elbow_angle)) / length));

	// get the unit vector of line between shoulder(origin) and destination point
	// i only do the x because the y will be multiplied out when we dot product by
	// the negative x axis vector.
	double unitx = x / (length);
	double unity = y / (length);

	// cos^-1((A * B)/|A||B|)
	// A = unit vector of line between shoulder(origin) and destination point
	// |A| = length of unit vector of line between shoulder(origin) and destination point(its 1)
	// B = unit vector going down the negative X axis
	// |B| = length of unit vector going down the negative X axis(its 1)
	double subangle = acos(ARM_SWITCH <= x ? unitx : -unity);	// this is simplifies due to a lot of the values being 1 or zero
	//Subtract PI by the angles we got above to find the angle between the Stage 1 arm and the positive X axis.
	angles[0] = ((
			y < 0 && x > ARM_SWITCH ?
					-subangle : subangle) + inner_shoulder_angle);
	if (x <= ARM_SWITCH)
		angles[0] = (3 * M_PI / 2)
				- angles[0];
}
double Arm::GetShoulderAngle(){
	return (((GetShoulderPot()-SHOULDER_POT_MIN)/(SHOULDER_POT_MAX-SHOULDER_POT_MIN))*(SHOULDER_ANGLE_MAX-SHOULDER_ANGLE_MIN)+SHOULDER_ANGLE_MIN);
}

double Arm::GetElbowAngle(){
	return(((GetElbowPot()-ELBOW_POT_MIN)/(ELBOW_POT_MAX-ELBOW_ANGLE_MIN))*(ELBOW_ANGLE_MAX-ELBOW_ANGLE_MIN)+ELBOW_ANGLE_MIN);
}

Point Arm::GetCurrentLocation() {
	return Point( ((cos(GetShoulderAngle()) * ARM_ONE_LENGTH)) + (cos(GetElbowAngle()) * ARM_TWO_LENGTH ),
			((sin(GetShoulderAngle()) * ARM_ONE_LENGTH) + ((sin(GetElbowAngle()) * ARM_TWO_LENGTH))) );
}

/**
 * @param x coordinate to goto.
 * @param y coordinate to goto.
 * @param angles angles of new target posistion. [0] = shoulder angle, [1] = elbow angle.
 */
void Arm::GetNewPointOnLine(double x, double y, double angles[2]) {
	Point current_location = GetCurrentLocation();
	double dis = sqrt(pow(x-current_location.x, 2) + pow(y-current_location.y, 2));
	double ux = ((x-current_location.x)/(dis))+current_location.x;
	double uy = ((y-current_location.y)/(dis))+current_location.y;

	//get the distance between the destination and the shoulder joint(origin)
	double length = sqrt(pow(ux, 2) + pow(uy, 2));
	//calculate the inner elbow angle with law of cosines.
	double inner_elbow_angle = acos(
			(((ARM_TWO_LENGTH * ARM_TWO_LENGTH)
					+ (ARM_ONE_LENGTH * ARM_ONE_LENGTH) - (length * length))
					/ (2 * ARM_TWO_LENGTH * ARM_ONE_LENGTH)));
	//PI - inner_angle to get the angle the arm needs to go to.
	angles[1] = M_PI - inner_elbow_angle;
	// if the point is near the back of the bot negate the angle
	if (ux >= ARM_SWITCH)
		angles[1] = -angles[1];
	//calcultae the angle between the line between shoulder(origin)
	// and destination point to go to using the law of sines with the elbow angle.
	double inner_shoulder_angle = asin(
			((ARM_TWO_LENGTH * sin(inner_elbow_angle)) / length));

	// get the unit vector of line between shoulder(origin) and destination point
	// i only do the x because the y will be multiplied out when we dot product by
	// the negitive x axis vector.
	double unitx = ux / (length);
	double unity = uy / (length);

	// cos^-1((A * B)/|A||B|)
	// A = unit vector of line between shoulder(origin) and destination point
	// |A| = length of unit vector of line between shoulder(origin) and destination point(its 1)
	// B = unit vector going down the negitive X axis
	// |B| = length of unit vector going down the negitive X axis(its 1)
	double subangle = acos(ARM_SWITCH <= ux ? unitx : -unity);	// this is simplifies due to a lot of the values being 1 or zero
	//substract PI by the angles we got above to find the angle between the Stage 1 arm and the positive X axis.
	angles[0] = ((
			uy < 0 && ux > ARM_SWITCH ?
					-subangle : subangle) + inner_shoulder_angle);
	if (x <= ARM_SWITCH)
		angles[0] = (3 * M_PI / 2)
				- angles[0];
}

double Arm::ShoulderToPot(double angle) {
	return (((angle - SHOULDER_ANGLE_MIN)
			/ (SHOULDER_ANGLE_MAX - SHOULDER_ANGLE_MIN))
			* (SHOULDER_POT_MAX - SHOULDER_ANGLE_MIN) + SHOULDER_POT_MIN);
}
double Arm::ElbowToPot(double angle) {
	return (((angle - ELBOW_ANGLE_MIN) / (ELBOW_ANGLE_MAX - ELBOW_ANGLE_MIN))
			* (ELBOW_POT_MAX - ELBOW_POT_MIN) + ELBOW_POT_MIN);
}

void Arm::stop(){
	shoulderMotor->Set(ControlMode::PercentOutput, 0);
	//shoulderMotor2->Set(ControlMode::PercentOutput, 0);
	//elbowMotor->Set(ControlMode::PercentOutput, 0);
	//ElbowBrakePiston->Extend();
}

void Arm::InitHardware() {
	shoulderMotor = new CANTalon(ARM_SHOULDER_MOTOR);
	//shoulderMotor2 = new CANTalon(ARM_SHOULDER_MOTOR_2);
	//elbowMotor = new CANTalon(ARM_ELBOW_MOTOR);
	shoulderPot = new Pot(SHOULDER_POT, 180);
	//elbowPot = new Pot(ELBOW_POT, POT_RANGE);
	//ElbowBrakePiston = new PistonSingle(BRAKES_PISTON);
}

void Arm::ElbowBrake(){
	//ElbowBrakePiston->Extend();
}

void Arm::ElbowRelease(){
	//ElbowBrakePiston->Retract();
}

void Arm::ShoulderBrake(){
	//ElbowBrakePiston->Extend();
}

void Arm::ShoulderRelease(){
	//ElbowBrakePiston->Retract();
}

void Arm::UpdateStatus(){
	//SmartDashboard::PutNumber("Elbow", elbowPot->Get());
	SmartDashboard::PutNumber("Shoulder" , GetShoulderPot());
	//SmartDashboard::PutNumber("Elbow Power", elbowMotor->GetMotorOutputPercent());
	SmartDashboard::PutNumber("Shoulder Power", shoulderMotor->GetMotorOutputPercent());
}

bool Arm::isNearPot(double position){
	double pot = GetShoulderPot();
	//std::cout <<  (pot < position + SHOULDER_POT_RANGE && pot > position + SHOULDER_POT_RANGE) << "\n";
	return pot < position + SHOULDER_POT_RANGE && pot > position + SHOULDER_POT_RANGE;
}

bool Arm::GotoPot(double position){
	double pot = GetShoulderPot();
	auto high = position + SHOULDER_POT_RANGE;
	auto low = position - SHOULDER_POT_RANGE;

	//std::cout << "High: " << high << " Low: " << low << " pot: " << pot << "\n";
	//These magic numbers are the Lowest and highest values of the AnalogPotentiometer
	if(pot < 70 || pot > POT_RANGE) {
		ControlShoulder(0);
		return true;
	}  else if (pot > position + SHOULDER_POT_RANGE) {
		ControlShoulder(pot > TREX_ARM_HIGH ? ARM_SHOULDER_SPEED : ARM_SHOULDER_SPEED * 0.5);
		return false;
	} else if (pot < position - SHOULDER_POT_RANGE) {
		ControlShoulder(-ARM_SHOULDER_SPEED);
		return false;
	} else {
		ControlShoulder(0);
		return true;
	}
}

double Arm::ReturnPIDInput() {

	return shoulderPot->Get();

}

void Arm::UsePIDOutput(double output) {
	//auto asdf = GetSetpoint();
	//if(GetShoulderPot() > asdf+5 || GetShoulderPot() < asdf-5){
	if (ReturnPIDInput() > 78 && GetSetpoint() > ReturnPIDInput()) {
		output *= .5;
	}
	// Slow down if coming to start position
	if (ReturnPIDInput() < 78 && GetSetpoint() < ReturnPIDInput()) {
		output *= .4;
	}
		shoulderMotor->Set(ControlMode::PercentOutput, -output * ARM_SPEED_LIMMIT);
		SmartDashboard::PutNumber("PIDOutput", -output);
	//}

}

void Arm::SetPIDPoint(double amount){
	SetSetpoint(amount);
}
