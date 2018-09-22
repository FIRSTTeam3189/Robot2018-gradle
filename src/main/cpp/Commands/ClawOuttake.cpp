#include "ClawOuttake.h"

ClawOuttake::ClawOuttake(double speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::claw.get());
	this->speed = speed;
}

// Called just before this Command runs the first time
void ClawOuttake::Initialize() {
	claw->SetPower(speed);
	claw->ClawClose();
	SetTimeout(2);
}

// Called repeatedly when this Command is scheduled to run
void ClawOuttake::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ClawOuttake::IsFinished() {
	return IsTimedOut();
	//Expected to run while held.
}

// Called once after isFinished returns true
void ClawOuttake::End() {
	claw->SetPower(0);
	claw->ClawOpen();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawOuttake::Interrupted() {
	claw->SetPower(0);
}
