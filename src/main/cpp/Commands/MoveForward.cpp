#include <Commands/MoveForward.h>

MoveForwardWhileHeld::MoveForwardWhileHeld() {
	Requires(CommandBase::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void MoveForwardWhileHeld::Initialize() {


}

// Called repeatedly when this Command is scheduled to run
void MoveForwardWhileHeld::Execute() {
	drivetrain->Drive(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveForwardWhileHeld::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveForwardWhileHeld::End() {
	CommandBase::drivetrain->Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveForwardWhileHeld::Interrupted() {
	CommandBase::drivetrain->Drive(0, 0);
}
