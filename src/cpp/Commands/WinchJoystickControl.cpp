#include <Commands/WristJoystickControl.h>

WinchJoystickControl::WinchJoystickControl() {
	Requires(CommandBase::wrist.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void WinchJoystickControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void WinchJoystickControl::Execute() {
	wrist->ControlWrist(oi->GetCoPilotY());

}

// Make this return true when this Command no longer needs to run execute()
bool WinchJoystickControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void WinchJoystickControl::End() {
	wrist->ControlWrist(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchJoystickControl::Interrupted() {
	wrist->ControlWrist(0);
}
