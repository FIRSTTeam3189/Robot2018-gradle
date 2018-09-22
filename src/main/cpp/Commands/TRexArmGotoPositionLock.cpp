#include "TRexArmGotoPositionLock.h"

TRexArmGotoPositionLock::TRexArmGotoPositionLock(double goal) {
	Requires(arm.get());
	this->goal = goal;
}

// Called just before this Command runs the first time
void TRexArmGotoPositionLock::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TRexArmGotoPositionLock::Execute() {
	arm->GotoPot(goal);
}

// Make this return true when this Command no longer needs to run execute()
bool TRexArmGotoPositionLock::IsFinished() {
	return false;//arm->isNearPot(goal);
}

// Called once after isFinished returns true
void TRexArmGotoPositionLock::End() {
	arm->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TRexArmGotoPositionLock::Interrupted() {
	arm->stop();
}
