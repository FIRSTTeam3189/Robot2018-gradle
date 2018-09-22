#include <AutonomousCommands/AutoMove.h>

constexpr double turnSpeed= 0.4;

AutoMove::AutoMove(TurnDirection direction, double seconds) {
	Requires(CommandBase::drivetrain.get());
	this->direction = direction;
	this->seconds = seconds;
	SetTimeout(seconds);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoMove::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoMove::Execute() {
	if(direction == TurnDirection::Left) {
		CommandBase::drivetrain->Drive(-turnSpeed, turnSpeed);
	} else if (direction == TurnDirection::Right) {
		CommandBase::drivetrain->Drive(turnSpeed, -turnSpeed);
	} else if (direction == TurnDirection::Forward) {
		CommandBase::drivetrain->Drive(turnSpeed, turnSpeed);
	} else {
		CommandBase::drivetrain->Drive(-turnSpeed, -turnSpeed);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoMove::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoMove::End() {
	CommandBase::drivetrain->Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoMove::Interrupted() {
	End();
}

