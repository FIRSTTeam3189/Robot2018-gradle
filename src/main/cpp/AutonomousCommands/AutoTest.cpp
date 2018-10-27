#include <AutoTest.h>
#include <iostream>
#include <DriverStation.h>
//#include "GoForwardWithEncoders.h" not used 
//#include "AutoEncoderTurn.h" not used
#include "Constants.h"
#include "DriveEncoders.h"

AutoTest::AutoTest() {
    AddSequential(new DriveEncoders(AUTO_SPEED, AutoTurnOpposite, AUTO_DISTANCE_TURN));
    AddSequential(new DriveEncoders(AUTO_SPEED, AutoTurnOpposite, AUTO_DISTANCE_TURN));

}
