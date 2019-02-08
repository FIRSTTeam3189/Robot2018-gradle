#include "Subsystems/Claw.h"
#include "RobotMap.h"

Claw::Claw() :
		Subsystem("ExampleSubsystem") {

}

void Claw::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands

void Claw::SetPower(double power) {
	Right->Set(ControlMode::PercentOutput, power);
}

void Claw::ClawOpen() {
	TheOneTheOnlyThePiston->Extend();

}

void Claw::ClawClose(){
	TheOneTheOnlyThePiston->Retract();

}
void Claw::InitHardware() {
	Left = new CANTalon(LEFT_CLAW_MOTOR);
	Right = new CANTalon(RIGHT_CLAW_MOTOR);

	TheOneTheOnlyThePiston = new PistonDouble(CLAW_PISTON);

	Right->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
	Left->SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);

	Left->SetInverted(false);
	Left->Set(ControlMode::Follower, Right->GetDeviceID());
}



