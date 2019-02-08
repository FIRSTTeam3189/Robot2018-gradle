#include "CommandBase.h"

#include <Commands/Scheduler.h>


std::unique_ptr<Drivetrain> CommandBase::drivetrain = std::make_unique<
		Drivetrain>();
std::unique_ptr<Arm> CommandBase::arm = std::make_unique<Arm>();
std::unique_ptr<Claw> CommandBase::claw = std::make_unique<Claw>();
std::unique_ptr<Wrist> CommandBase::wrist = std::make_unique<Wrist>();
std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

