#include <AutonomousCommands/AutoEncoderTurn.h>
#include "Constants.h"
AutoEncoderTurn::AutoEncoderTurn(double distance_) {
	Requires(CommandBase::drivetrain.get());
	distance = distance_;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoEncoderTurn::Initialize() {
	drivetrain.reset();
}

// Called repeatedly when this Command is scheduled to run
void AutoEncoderTurn::Execute() {
	if(drivetrain->GetRightEncoderDistance() > distance)
		drivetrain->Drive(AUTO_SPEED,-AUTO_SPEED);
	else if(drivetrain->GetRightEncoderDistance() < distance)
		drivetrain->Drive(-AUTO_SPEED,AUTO_SPEED);
	else
		drivetrain->Drive(0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoEncoderTurn::IsFinished() {
	return (drivetrain->GetDistance() >= -distance - 3)
			&& (drivetrain->GetDistance() <= -distance +3);
}

// Called once after isFinished returns true
void AutoEncoderTurn::End() {
	drivetrain->Drive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoEncoderTurn::Interrupted() {
	drivetrain->Drive(0);
}
