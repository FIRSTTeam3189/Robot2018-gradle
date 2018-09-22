#include "ArmGoToPoint.h"

ArmGoToPoint::ArmGoToPoint(double x_, double y_) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm.get());
	x = x_;
	y = y_;
}

// Called just before this Command runs the first time.
void ArmGoToPoint::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArmGoToPoint::Execute() {
	double new_angles[2];
	arm->GetNewPointOnLine(x, y, new_angles);

	double sDif = new_angles[0] - arm->GetShoulderAngle();
	double eDif = new_angles[1] - arm->GetElbowAngle();

	double shoulder_speed = 0;
	double elbow_speed = 0;

	double temp = sDif < eDif ? eDif : sDif;

	shoulder_speed = (sDif / temp) * 0.75;
	elbow_speed = (eDif / temp) * 0.75;
}

// Make this return true when this Command no longer needs to run execute()
bool ArmGoToPoint::IsFinished() {
	last_position = arm->GetCurrentLocation();
	return !(last_position.x - ARM_POSITION_TOLERANCE < x)
			|| !(last_position.x - ARM_POSITION_TOLERANCE > x)
			|| !(last_position.y - ARM_POSITION_TOLERANCE < y)
			|| !(last_position.y - ARM_POSITION_TOLERANCE > y);
}

// Called once after isFinished returns true
void ArmGoToPoint::End() {
	arm->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run

void ArmGoToPoint::Interrupted() {
	arm->stop();
}
