#include <AutonomousCommands/Autonomous.h>
#include <iostream>
#include <DriverStation.h>
//#include "AutoForwardTime.h"   not used
#include "Constants.h"
#include "AutonomousCommands/DriveEncoders.h"

Autonomous::Autonomous() : frc::CommandGroup("Autonomous") {

	AddSequential(new DriveEncoders(AUTO_SPEED, DriveDirection::Forward, AUTO_DISTANCE_FORWARD));

	// the data is three chars defining side of objects from you perspective
	// (L = Left, R = Right, CAPS ARE IMPORTANT) Going closest to farthest
	// ex: "LLR" our switch is first being left from our driverstaion
	/*std::string state = DriverStation::GetInstance().GetGameSpecificMessage();

	if(state[0] == 'L'){

	}else{

	}*/
}
