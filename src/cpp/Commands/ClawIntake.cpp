#include "ClawIntake.h"
#include "Constants.h"

ClawIntake::ClawIntake() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

	Requires(CommandBase::claw.get()); //Woah we did it, now we have SOMETHING that does NOTHING .
}

// Called just before this Command runs the first time
void ClawIntake::Initialize() {
	claw->SetPower(CLAW_INTAKE_POWER);
	claw->ClawOpen();
	SetTimeout(1);
}

// Called repeatedly when this Command is scheduled to run
void ClawIntake::Execute() {
	if(IsTimedOut()){
		//claw->ClawClose();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ClawIntake::IsFinished() {
	return false;
	//This is expected to be a when held command.
}

// Called once after isFinished returns true
void ClawIntake::End() {
	(claw->SetPower(0)); //we considered going way faster. Can't stop won't stop
	claw->ClawClose();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawIntake::Interrupted() {
	End();
}
