#include "JoystickArmControl.h"

JoystickArmControl::JoystickArmControl() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::arm.get());
}

// Called just before this Command runs the first time
void JoystickArmControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void JoystickArmControl::Execute() {
	arm->ControlShoulder(-oi->GetCoPilotY());
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickArmControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void JoystickArmControl::End() {
	arm->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickArmControl::Interrupted() {
	End();
}
