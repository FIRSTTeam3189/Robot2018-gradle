/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "EngageDrivetrain.h"
#include "../CommandBase.h"
EngageDrivetrain::EngageDrivetrain() {
	Requires(CommandBase::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void EngageDrivetrain::Initialize() {
	CommandBase::drivetrain->EngageDrivetrain();
}

// Called repeatedly when this Command is scheduled to run
void EngageDrivetrain::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool EngageDrivetrain::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void EngageDrivetrain::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EngageDrivetrain::Interrupted() {

}
