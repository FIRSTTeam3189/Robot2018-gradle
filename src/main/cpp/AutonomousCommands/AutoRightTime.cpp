#include <AutonomousCommands/AutoRightTime.h>

AutoRightTime::AutoRightTime(double seconds, double speed_) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::drivetrain.get());

	SetTimeout(seconds);
}

// Called just before this Command runs the first time
void AutoRightTime::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoRightTime::Execute() {
	drivetrain->Drive(speed_, -speed_);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRightTime::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoRightTime::End() {
	drivetrain->Drive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRightTime::Interrupted() {
	drivetrain->Drive(0);
}
