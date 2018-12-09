#include <AutonomousCommands/DriveTimed.h>
#include <math.h>
#include <iostream>

DriveTimed::DriveTimed(double _power, DriveDirection _dir, double _time) {
	Requires(CommandBase::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	power = _power;
	dir = _dir;
	length = _time;
}

// Called just before this Command runs the first time
void DriveTimed::Initialize() {
	drivetrain->Reset();
	if (dir == DriveDirection::AutoTurn) {
		std::string state = DriverStation::GetInstance().GetGameSpecificMessage();
		DriveDirection side = state[0] == 'L' ? DriveDirection::Left : DriveDirection::Right;

		// Drive the encoders in the proper direction
		dir = side;
	} else if (dir == DriveDirection::AutoTurnOpposite) {
		std::string state = DriverStation::GetInstance().GetGameSpecificMessage();
		DriveDirection side = state[0] == 'L' ? DriveDirection::Right : DriveDirection::Left;

		// Drive the encoders in the proper direction
		dir = side;
	}
	SetTimeout(length);
}

// Called repeatedly when this Command is scheduled to run
void DriveTimed::Execute() {
	if (!(IsTimedOut())) drivetrain->DriveEncoders(power, dir);
}

// Make this return true when this Command no longer needs to run execute()

bool DriveTimed::IsFinished() {
	auto side = dir == DriveDirection::Left ? "Left" : dir == DriveDirection::Right ? "Right" : "Forward/Backward";
	if (IsTimedOut()) {  //
		std::cout << "!!!DriveEnconders going " << side << " for " << length << " seconds has finished!!!\n";
	} else {
		std::cout << "DriveEncouters has gone " << drivetrain->GetDistanceInInches() << " Inches...\n";
	}

	return IsTimedOut();// ? true : false;
}

// Called once after isFinished returns true
void DriveTimed::End() {
	drivetrain->Drive(0);
	drivetrain->Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTimed::Interrupted() {
	drivetrain->Drive(0);
	drivetrain->Reset();
}
