#include <AutoCenter.h>
#include <iostream>
#include <DriverStation.h>
//#include "GoForwardWithEncoders.h" not used
//#include "AutoEncoderTurn.h" not used
#include "Commands/ShoulderPIDGoto.h"
#include "Commands/ClawOuttake.h"
#include "Constants.h"
#include "DriveEncoders.h"

AutoCenter::AutoCenter() {
	AddParallel(new ShoulderPIDGoto(TREX_ARM_HIGH));
	AddSequential(new DriveEncoders(AUTO_SPEED,Forward,12));
	AddSequential(new DriveEncoders(AUTO_SPEED,AutoTurn,AUTO_DISTANCE_TURN));
	AddSequential(new DriveEncoders(AUTO_SPEED,Forward,45));
	AddSequential(new DriveEncoders(AUTO_SPEED,AutoTurnOpposite,AUTO_DISTANCE_TURN));
	AddSequential(new DriveEncoders(AUTO_SPEED,Forward,45));
	AddSequential(new ClawOuttake());
/*
	AddSequential(new GoForwardWithEncoders(12));
	AddSequential(new AutoEncoderTurn(17.7*side));
	AddSequential(new GoForwardWithEncoders(90));
	AddSequential(new AutoEncoderTurn(-17.7*side));
	AddSequential(new GoForwardWithEncoders(90.5));
	AddSequential(new TRexArmGotoPosition(TREX_ARM_HIGH));
	AddSequential(new ClawOuttake());

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	 */

}
