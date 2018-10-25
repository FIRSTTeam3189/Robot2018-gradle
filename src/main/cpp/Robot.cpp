#include <AutonomousCommands/Autonomous.h>
#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include "AutonomousCommands/AutoGoForwardAndStop.h"
#include "AutonomousCommands/AutoCenter.h"
#include "AutonomousCommands/AutoRight.h"
#include "AutonomousCommands/AutoTest.h"
#include "Robot.h"
#include "CommandBase.h"
#include "AutonomousCommands/AutoLeft.h"
void Robot::RobotInit() {
	CommandBase::drivetrain->InitHardware();
	CommandBase::arm->InitHardware();
	CommandBase::claw->InitHardware();
	CommandBase::wrist->InitHardware();
	CommandBase::oi->InitilizeOI();

	c = new Compressor(0);

	c->SetClosedLoopControl(true);

	CameraServer::GetInstance()->StartAutomaticCapture(0);

	chooser.AddDefault("Default Auto", new Autonomous());
	chooser.AddObject("center", new AutoCenter());
	chooser.AddObject("left", new AutoLeft());
	chooser.AddObject("right",new AutoRight());
	chooser.AddObject("test", new AutoTest());
//	chooser.AddObject("right", new AutoSides());
	//chooser.AddObject("Forward and stop", new AutoGoForwardAndStop());
	// chooser.AddObject("My Auto", new MyAutoCommand());
	SmartDashboard::PutData("Auto Modes", &chooser);
}

/**
 * This function is called once each time the robot enters Disabled mode.
 * You can use it to reset any subsystem information you want to clear when
 * the robot is disabled.
 */
void Robot::DisabledInit() {
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
//	disable periodic
	CommandBase::drivetrain->Log();
	UpdateStatus();
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable
 * chooser code works with the Java SmartDashboard. If you prefer the
 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
 * GetString code to get the auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons
 * to the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit() {
	/* std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
	 if (autoSelected == "My Auto") {
	 autonomousCommand.reset(new MyAutoCommand());
	 }
	 else {
	 autonomousCommand.reset(new ExampleCommand());
	 } */

	autonomousCommand.reset(chooser.GetSelected());

	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (autonomousCommand != nullptr) {
		autonomousCommand->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
	CommandBase::drivetrain->Log();
	UpdateStatus();
}
/**
 * Hacked
 */
void Robot::TestPeriodic() {
	frc::LiveWindow::GetInstance()->Run();
}

void Robot::UpdateStatus(){
	CommandBase::arm->UpdateStatus();
	SmartDashboard::PutData("claw", CommandBase::arm.get());
	CommandBase::wrist->UpdateStatus();
}

START_ROBOT_CLASS(Robot)
