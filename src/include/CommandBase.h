#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "OI.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Arm.h"
#include "Subsystems/Claw.h"
#include "Subsystems/Wrist.h"

class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	static std::unique_ptr<Drivetrain> drivetrain;
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<Arm> arm;
	static std::unique_ptr<Claw> claw;
	static std::unique_ptr<Wrist> wrist;
};

#endif  // COMMAND_BASE_H
