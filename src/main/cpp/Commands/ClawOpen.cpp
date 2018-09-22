#include "ClawOpen.h"

ClawOpen::ClawOpen() {
	Requires(CommandBase::claw.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ClawOpen::Initialize() {
	claw->ClawOpen();

}

// Called repeatedly when this Command is scheduled to run
void ClawOpen::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ClawOpen::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ClawOpen::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawOpen::Interrupted() {

}
