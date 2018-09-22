#include "TRexArmGotoPosition.h"

TRexArmGotoPosition::TRexArmGotoPosition(double goal) {
	Requires(arm.get());
	this->goal = goal;
}

// Called just before this Command runs the first time
void TRexArmGotoPosition::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TRexArmGotoPosition::Execute() {
	arm->GotoPot(goal);
}

// Make this return true when this Command no longer needs to run execute()
bool TRexArmGotoPosition::IsFinished() {
	return arm->isNearPot(goal);
}

// Called once after isFinished returns true
void TRexArmGotoPosition::End() {
	arm->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TRexArmGotoPosition::Interrupted() {
	arm->stop();
}
