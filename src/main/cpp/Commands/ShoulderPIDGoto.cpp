#include "ShoulderPIDGoto.h"

ShoulderPIDGoto::ShoulderPIDGoto(double amount) {
	Requires(arm.get());
	this->amount = amount;
}

// Called just before this Command runs the first time
void ShoulderPIDGoto::Initialize() {
	arm->Enable();
	arm->SetSetpoint(amount);
}

// Called repeatedly when this Command is scheduled to run
void ShoulderPIDGoto::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ShoulderPIDGoto::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShoulderPIDGoto::End() {
	arm->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShoulderPIDGoto::Interrupted() {
	arm->Disable();
}
