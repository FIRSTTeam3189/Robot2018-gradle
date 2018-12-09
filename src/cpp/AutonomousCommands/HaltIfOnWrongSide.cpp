#include <AutonomousCommands/HaltIfOnWrongSide.h>
#include <iostream>
HaltIfOnWrongSide::HaltIfOnWrongSide(char side_) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	side = side_;
	willFinish = false;
}

// Called just before this Command runs the first time
void HaltIfOnWrongSide::Initialize() {
	std::string state = DriverStation::GetInstance().GetGameSpecificMessage();
	willFinish = state[0] == side;
	std::cout << "_____________________" << willFinish << "______" << state[0] << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void HaltIfOnWrongSide::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool HaltIfOnWrongSide::IsFinished() {
	if (willFinish) {
		std::cout << "!!!HALT HAS FINISHED!!!\n";
	}
	return willFinish;
}

// Called once after isFinished returns true
void HaltIfOnWrongSide::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HaltIfOnWrongSide::Interrupted() {

}
