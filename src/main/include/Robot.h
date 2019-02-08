#ifndef ROBOT_H
#define ROBOT_H
#include <AutonomousCommands/Autonomous.h>
#include <memory>

#include <frc/Commands/Command.h>
#include <frc/Commands/Scheduler.h>
#include <frc/IterativeRobot.h>
#include <frc/LiveWindow/LiveWindow.h>
#include <frc/SmartDashboard/SendableChooser.h>
#include <frc/SmartDashboard/SmartDashboard.h>
#include <frc/CameraServer.h>

#include "OI.h"
#include "Subsystems/Drivetrain.h"

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() override;

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override;

	void DisabledPeriodic();

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
	void AutonomousInit();

	void AutonomousPeriodic();

	void TeleopInit();

	void TeleopPeriodic();

	void TestPeriodic();

	void UpdateStatus();

private:
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;

};

#endif //ROBOT_H
