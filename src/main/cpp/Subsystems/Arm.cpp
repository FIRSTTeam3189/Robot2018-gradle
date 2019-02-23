#include "Subsystems/Arm.h"
#include "Constants.h"
#include "RobotMap.h"
#include <math.h>
#include <iostream>
#include <algorithm>
#include "Commands/JoystickArmControl.h"
#include <SmartDashboard/SmartDashboard.h>
#include <Commands/JoystickArmControl.h>

Arm::Arm() :
	//PIDSubsystem("arm", 0.26, 0.0014, 0.015) {
	// PIDSubsystem("arm", 0.19, 0.0005, 0.000) { // Known GOOD
	Subsystem("arm"){
	// SetInputRange(0, 180);
	// GetPIDController()->SetContinuous(false);
	// GetPIDController()->SetAbsoluteTolerance(16);
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

void Arm::GotoPosition(double p){
	shoulderMotor->Set(ControlMode::Position
	, p);
}

// double Arm::GetShoulderPot() {
// //	return ((shoulderPot->GetAverageVoltage() - VOLTAGE_LOW) / VOLTAGE_RANGE) * POT_RANGE;

// 	return shoulderPot->Get();
// }

// /**
//  * @param x coordinate to goto.
//  * @param y coordinate to goto.
//  * @param angles angles of new target posistion. [0] = shoulder angle, [1] = elbow angle.
//  */


// double Arm::ShoulderToPot(double angle) {
// 	return (((angle - SHOULDER_ANGLE_MIN)
// 			/ (SHOULDER_ANGLE_MAX - SHOULDER_ANGLE_MIN))
// 			* (SHOULDER_POT_MAX - SHOULDER_ANGLE_MIN) + SHOULDER_POT_MIN);
// }



void Arm::stop(){
	shoulderMotor->Set(ControlMode::PercentOutput, 0);
	//shoulderMotor2->Set(ControlMode::PercentOutput, 0);
	//elbowMotor->Set(ControlMode::PercentOutput, 0);
	//ElbowBrakePiston->Extend();
}

void Arm::InitHardware() {
	shoulderMotor = new CANTalon(ARM_SHOULDER_MOTOR);
	shoulderMotor->ConfigFactoryDefault();
	shoulderMotor->ConfigSelectedFeedbackSensor(feedbackdev::Analog, 0, 10);
	
	shoulderMotor->SetSensorPhase(true);

	    /* Set the peak and nominal outputs */
	shoulderMotor->ConfigNominalOutputForward(0, 10);
    shoulderMotor->ConfigNominalOutputReverse(0, 10);
    shoulderMotor->ConfigPeakOutputForward(0.6, 10);
    shoulderMotor->ConfigPeakOutputReverse(-0.6, 10);

    /* Set Motion Magic gains in slot0 - see documentation */
    shoulderMotor->SelectProfileSlot(0, 0);
    shoulderMotor->Config_kF(0, 0.0, 10);
    shoulderMotor->Config_kP(0, 2.5, 10);
    shoulderMotor->Config_kI(0, 0.0, 10);
    shoulderMotor->Config_kD(0, 2.5, 10);

    // /* Set acceleration and vcruise velocity - see documentation */
    // shoulderMotor->ConfigMotionCruiseVelocity(100, 10);
    // shoulderMotor->ConfigMotionAcceleration(100, 10);

    /* Zero the sensor */
	shoulderMotor->SetSelectedSensorPosition(680, 0, 10);
	//shoulderMotor->Config_IntegralZone(0, 10, 10);
	//shoulderMotor2 = new CANTalon(ARM_SHOULDER_MOTOR_2);
	//elbowMotor = new CANTalon(ARM_ELBOW_MOTOR);
	//shoulderPot = new Pot(SHOULDER_POT, 180);
	//elbowPot = new Pot(ELBOW_POT, POT_RANGE);
	//ElbowBrakePiston = new PistonSingle(BRAKES_PISTON);
}


void Arm::UpdateStatus(){
	//SmartDashboard::PutNumber("Elbow", elbowPot->Get());
	//frc::SmartDashboard::PutNumber("Shoulder" , GetShoulderPot());
	//SmartDashboard::PutNumber("Elbow Power", elbowMotor->GetMotorOutputPercent());
	frc::SmartDashboard::PutNumber("Shoulder Power", shoulderMotor->GetMotorOutputPercent());
	frc::SmartDashboard::PutNumber("Shoulder Pot", shoulderMotor->GetSelectedSensorPosition());
}



// double Arm::ReturnPIDInput() {

// 	return shoulderPot->Get();

// }

// void Arm::UsePIDOutput(double output) {
// 	//auto asdf = GetSetpoint();
// 	//if(GetShoulderPot() > asdf+5 || GetShoulderPot() < asdf-5){
// 	if (ReturnPIDInput() > 78 && GetSetpoint() > ReturnPIDInput()) {
// 		output *= .5;
// 	}
// 	// Slow down if coming to start position
// 	if (ReturnPIDInput() < 78 && GetSetpoint() < ReturnPIDInput()) {
// 		output *= .4;
// 	}
// 		shoulderMotor->Set(ControlMode::PercentOutput, -output * ARM_SPEED_LIMMIT);
// 		frc::SmartDashboard::PutNumber("PIDOutput", -output);
	//}

// }

// void Arm::SetPIDPoint(double amount){
// 	SetSetpoint(amount);
// }
