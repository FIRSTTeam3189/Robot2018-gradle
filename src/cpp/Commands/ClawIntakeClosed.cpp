#include "ClawIntakeClosed.h"
#include "Constants.h"

ClawIntakeClosed::ClawIntakeClosed() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

	Requires(CommandBase::claw.get()); //Woah we did it, now we have SOMETHING that does NOTHING .
}

// Called just before this Command runs the first time
void ClawIntakeClosed::Initialize() {
	claw->SetPower(CLAW_INTAKE_POWER);
	claw->ClawClose();
	SetTimeout(1);
}

// Called repeatedly when this Command is scheduled to run
void ClawIntakeClosed::Execute() {
	if(IsTimedOut()){
		//claw->ClawClose();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ClawIntakeClosed::IsFinished() {
	return false;
	//This is expected to be a when held command.
}

// Called once after isFinished returns true
void ClawIntakeClosed::End() {
	(claw->SetPower(0)); //we considered going way faster. Can't stop won't stop
	claw->ClawClose();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawIntakeClosed::Interrupted() {
	End();
}
