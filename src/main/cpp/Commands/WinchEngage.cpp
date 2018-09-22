#include "WinchEngage.h"

WinchEngage::WinchEngage() {
	Requires(CommandBase::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void WinchEngage::Initialize() {
	drivetrain->EngageWinch();

}

// Called repeatedly when this Command is scheduled to run
void WinchEngage::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool WinchEngage::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void WinchEngage::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchEngage::Interrupted() {

}
