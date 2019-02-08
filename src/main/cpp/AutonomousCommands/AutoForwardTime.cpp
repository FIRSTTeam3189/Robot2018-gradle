#include <AutonomousCommands/AutoForwardTime.h>
#include <iostream>

AutoForwardTime::AutoForwardTime(double seconds_, double speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::drivetrain.get());
	seconds = seconds_;
	speed_ = speed;
}

// Called just before this Command runs the first time
void AutoForwardTime::Initialize() {
	SetTimeout(seconds);
}

// Called repeatedly when this Command is scheduled to run
void AutoForwardTime::Execute() {
	CommandBase::drivetrain->Drive(speed_);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoForwardTime::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoForwardTime::End() {
	CommandBase::drivetrain->Drive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoForwardTime::Interrupted() {
	CommandBase::drivetrain->Drive(0);
}
