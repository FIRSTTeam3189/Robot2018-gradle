#include "Wrist.h"
#include "RobotMap.h"
#include "Constants.h"
#include "RobotMap.h"
#include "Commands/WristJoystickControl.h"
#include <math.h>
#include <SmartDashboard/SmartDashboard.h>
#include "ctre/Phoenix.h"

Wrist::Wrist() : Subsystem("wrist") {

}

void Wrist::InitDefaultCommand() {
	//SetDefaultCommand(new WinchJoystickControl());
}


void Wrist::ControlWrist(double power) {
	SmartDashboard::PutNumber("Thingy", power);
	if(!wristMotor->GetSensorCollection().IsFwdLimitSwitchClosed() || power > 0){
		wristMotor->Set(ControlMode::PercentOutput, power);
	}else{
		wristMotor->Set(ControlMode::PercentOutput, 0);
	}

}
void Wrist::InitHardware(){
	wristMotor = new CANTalon(ARM_SHOULDER_MOTOR_2);
}

void Wrist::PistonThingyExtend(){
	wristPiston -> Extend();
}

void Wrist::PistonThingyRetract(){
	wristPiston -> Retract();
}


void Wrist::UpdateStatus(){
	SmartDashboard::PutBoolean("limit switch", !wristMotor->GetSensorCollection().IsFwdLimitSwitchClosed());
}
