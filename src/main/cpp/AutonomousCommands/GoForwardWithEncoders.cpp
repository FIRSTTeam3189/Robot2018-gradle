#include <AutonomousCommands/GoForwardWithEncoders.h>

GoForwardWithEncoders::GoForwardWithEncoders(double distance_) {
	Requires(drivetrain.get());
	distance = distance_;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void GoForwardWithEncoders::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void GoForwardWithEncoders::Execute() {
	CommandBase::drivetrain->Drive(AUTO_SPEED, AUTO_SPEED);
}

// Make this return true when this Command no longer needs to run execute()
bool GoForwardWithEncoders::IsFinished() {
	if (((drivetrain->GetDistance() / SIGNALS_PER_REVOLUTION)
			* WHEEL_CIRCUMFERENCE) > distance) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void GoForwardWithEncoders::End() {
	drivetrain->Drive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GoForwardWithEncoders::Interrupted() {
	drivetrain->Drive(0);
}
