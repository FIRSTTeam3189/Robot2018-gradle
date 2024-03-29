#include <AutonomousCommands/DriveEncoders.h>
#include <math.h>
#include <iostream>

DriveEncoders::DriveEncoders(double _power, DriveDirection _dir, double _distance) {
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
	if (dir == DriveDirection::AutoTurn) {
		std::string state = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		DriveDirection side = state[0] == 'L' ? DriveDirection::Left : DriveDirection::Right;

		// Drive the encoders in the proper direction
		dir = side;
	} else if (dir == DriveDirection::AutoTurnOpposite) {
		std::string state = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		DriveDirection side = state[0] == 'L' ? DriveDirection::Right : DriveDirection::Left;

		// Drive the encoders in the proper direction
		dir = side;
	}
	SetTimeout(2);
}

// Called repeatedly when this Command is scheduled to run
void DriveEncoders::Execute() {
	if (distance >= drivetrain->GetDistanceInInches()) drivetrain->DriveEncoders(power, dir);
	std::cout << "MOVING" << '\n';
}

// Make this return true when this Command no longer needs to run execute()

bool DriveEncoders::IsFinished() {
	auto side = dir == DriveDirection::Left ? "Left" : dir == DriveDirection::Right ? "Right" : "Forward/Backward";
	if (distance
	 <= fabs(drivetrain->GetDistanceInInches())) {  //
		std::cout << "!!!DriveEnconders going " << side << " for " << distance << " inches has finished!!!\n";
	} else {
		std::cout << "DriveEncouters has gone " << drivetrain->GetDistanceInInches() << " Inches...\n";
	}

	return IsTimedOut() || distance <= fabs(drivetrain->GetDistanceInInches());// ? true : false;
}

// Called once after isFinished returns true
void DriveEncoders::End() {
	drivetrain->Drive(0);
	drivetrain->Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveEncoders::Interrupted() {
	drivetrain->Drive(0);
	drivetrain->Reset();
}
