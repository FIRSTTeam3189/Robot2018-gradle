#include "OI.h"

#include <SmartDashboard/SmartDashboard.h>

#include <AutonomousCommands/Autonomous.h>
#include "Commands/ClawIntake.h"
#include "Commands/ClawOuttake.h"
//#include "Commands/ClawOpen.h" old
//#include "Commands/ClawClose.h" old
#include "Commands/WristLift.h"
#include "Commands/WristLower.h"
#include "Commands/ArmGoToPoint.h"
#include "Commands/JoystickArmControl.h"
#include "Commands/TankDriveWithJoystick.h"
#include <Commands/MoveForward.h>
//#include "Commands/TRexArmGotoPosition.h" old
//#include "Commands/TRexArmGotoPositionLock.h" old
#include "Commands/ClawIntakeClosed.h"
#include "Commands/WristJoystickControl.h"
#include "Constants.h"
#include "Commands/ShoulderPIDGoto.h"
//#include "Commands/EngageDrivetrain.h" old
//#include "Commands/WinchEngage.h" old
OI::OI() {

}

double OI::GetLeftY() {
	return left.GetY(frc::GenericHID::JoystickHand::kLeftHand);
}

double OI::GetRightY() {
	return right.GetY(frc::GenericHID::JoystickHand::kRightHand);
}

double OI::GetCoPilotY() {
	return copilot.GetY(frc::GenericHID::JoystickHand::kRightHand);

}



void OI::InitilizeOI(){
	copilot_2 = new JoystickButton(&copilot, 2);
	copilot_3 = new JoystickButton(&copilot, 3);
	copilot_1 = new JoystickButton(&copilot, 1);
	copilot_4 = new JoystickButton(&copilot, 4);
	copilot_5 = new JoystickButton(&copilot, 5);
	copilot_6 = new JoystickButton(&copilot, 6);
	copilot_7 = new JoystickButton(&copilot, 7);
	copilot_8 = new JoystickButton(&copilot, 8);
	copilot_9 = new JoystickButton(&copilot, 9);
	copilot_10 = new JoystickButton(&copilot, 10);
	copilot_11 = new JoystickButton(&copilot, 11);
	left_1 = new JoystickButton(&left, 1);
	right_1 = new JoystickButton(&right, 1);
	right_2 = new JoystickButton(&right, 2);
	right_3 = new JoystickButton(&right, 3);
	right_7 = new JoystickButton(&right, 7);
	right_8 = new JoystickButton(&right, 8);
	right_9 = new JoystickButton(&right, 9);
	right_10 = new JoystickButton(&right, 10);



	//copilot_6->WhenPressed(new ClawOpen());
	//copilot_11->WhenPressed(new ClawClose());
	//copilot_6->WhileHeld(new JoystickArmControl());

	right_3->WhileHeld(new ClawIntake());
	right_2->WhileHeld(new ClawIntakeClosed());
	right_1->WhileHeld(new ClawOuttake(CLAW_OUTAKE_POWER));
	right_7->WhenPressed(new ShoulderPIDGoto(TREX_ARM_LOW));
	right_8->WhenPressed(new ShoulderPIDGoto(TREX_ARM_MIDDLE));
	right_9->WhenPressed(new ShoulderPIDGoto(TREX_ARM_HIGH));
	right_10->WhenPressed(new ShoulderPIDGoto(TREX_ARM_START));

	copilot_3->WhileHeld(new ClawIntake());
	copilot_2->WhileHeld(new ClawIntakeClosed());
	copilot_1->WhileHeld(new ClawOuttake(CLAW_OUTAKE_POWER));
	copilot_7->WhenPressed(new ShoulderPIDGoto(TREX_ARM_LOW));
	copilot_8->WhenPressed(new ShoulderPIDGoto(TREX_ARM_MIDDLE));
	copilot_9->WhenPressed(new ShoulderPIDGoto(TREX_ARM_HIGH));
	copilot_10->WhenPressed(new ShoulderPIDGoto(TREX_ARM_START));
	copilot_11->WhileHeld(new WinchJoystickControl());
}
bool OI::GetRight1Button(){
return	left_1->Get();
}

void OI::CheckMath() {
	moveArm->WhenPressed(new ArmGoToPoint(15, 50));
}

