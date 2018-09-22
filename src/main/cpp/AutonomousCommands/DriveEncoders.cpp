#include <AutonomousCommands/DriveEncoders.h>
#include <math.h>
#include <iostream>

DriveEncoders::DriveEncoders(double _power, enum DriveDirection _dir, double _distance) {
	Requires(CommandBase::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	power = _power;
	dir = _dir;
	distance = _distance;
}

// Called just before this Command runs the first time
void DriveEncoders::Initialize() {
	drivetrain->Reset();
	if (dir == AutoTurn) {
		std::string state = DriverStation::GetInstance().GetGameSpecificMessage();
		DriveDirection side = state[0] == 'L' ? Left : Right;

		// Drive the encoders in the proper direction
		dir = side;
	}
	SetTimeout(1);
}

// Called repeatedly when this Command is scheduled to run
void DriveEncoders::Execute() {
	if (IsTimedOut()) drivetrain->DriveEncoders(power, dir);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveEncoders::IsFinished() {
	auto side = dir == Left ? "Left" : dir == Right ? "Right" : "Forward/Backward";
	if (distance <= fabs(drivetrain->GetDistanceInInches())) {
		std::cout << "!!!DriveEnconders going " << side << " for " << distance << " inches has finished!!!\n";
	} else {
		std::cout << "DriveEncouters has gone " << drivetrain->GetDistanceInInches() << " Inches...\n";
	}

	return IsTimedOut() && distance <= fabs(drivetrain->GetDistanceInInches());// ? true : false;
}

// Called once after isFinished returns true
void DriveEncoders::End() {
	drivetrain->Drive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveEncoders::Interrupted() {
	drivetrain->Drive(0);
}
