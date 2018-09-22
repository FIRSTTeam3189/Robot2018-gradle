#include "ClawClose.h"

ClawClose::ClawClose() {
	Requires(CommandBase::claw.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ClawClose::Initialize() {
	claw->ClawClose();

}

// Called repeatedly when this Command is scheduled to run
void ClawClose::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ClawClose::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ClawClose::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawClose::Interrupted() {

}
