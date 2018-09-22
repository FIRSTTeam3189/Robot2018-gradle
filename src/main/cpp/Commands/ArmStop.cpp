#include "ArmStop.h"

ArmStop::ArmStop() {
	Requires(arm.get());
}

// Called just before this Command runs the first time
void ArmStop::Initialize() {
	arm->stop();
}

// Called repeatedly when this Command is scheduled to run
void ArmStop::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ArmStop::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmStop::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmStop::Interrupted() {

}
