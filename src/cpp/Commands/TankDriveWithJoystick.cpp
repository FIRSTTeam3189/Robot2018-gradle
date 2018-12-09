#include "TankDriveWithJoystick.h"

TankDriveWithJoystick::TankDriveWithJoystick() :
		CommandBase("TankDriveWithJoystick") {
	Requires(drivetrain.get());
}

void TankDriveWithJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TankDriveWithJoystick::Execute() {
	//drivetrain->Drive(oi->GetLeftY(), oi->GetRightY());
	drivetrain->Drive(r ? -oi->GetRightY() : oi->GetLeftY(),
			r ? -oi->GetLeftY() : oi->GetRightY());
	if(oi->GetRight1Button() && !flag){
		flag = true;
		r = !r;
	}else if(flag && !oi->GetRight1Button()){
		flag = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TankDriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TankDriveWithJoystick::End() {
	drivetrain->Stop();
}

// Called once after the command is interupted
void TankDriveWithJoystick::Interrupted() {
	drivetrain->Stop();
}
