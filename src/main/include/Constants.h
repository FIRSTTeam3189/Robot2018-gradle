/*
 * Constants.h
 *
 *  Created on: Jan 14, 2018
 *      Author: Nathaniel Mansfield
 */

#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_
// AUTONOMOUS VARIABLES
constexpr double FORWARD_TIME  = 2.5;
constexpr double FORWARD_POWER = .5;

constexpr double LEFT_TIME = 1;
constexpr double RIGHT_TIME = 1;

constexpr double LEFT_SPEED = .5;
constexpr double RIGHT_SPEED = .5;
//70.7
constexpr int SHOULDER_POT_MAX = 984;
constexpr int SHOULDER_POT_MIN = 0;
constexpr int SHOULDER_POT_RANGE = 5;//------------------------
constexpr int ELBOW_POT_MAX = 991;
constexpr int ELBOW_POT_MIN = 0;
constexpr int WRIST_POT_MIN = 0;
constexpr int WRIST_POT_MAX = 0;

constexpr int TREX_ARM_START = 680;
constexpr int TREX_ARM_HIGH = 300;
constexpr int TREX_ARM_MIDDLE = 73;
constexpr int TREX_ARM_LOW = 0;

constexpr double SHOULDER_ANGLE_MIN = 0;
constexpr double SHOULDER_ANGLE_MAX = 0;
constexpr double ELBOW_ANGLE_MIN = 0;
constexpr double ELBOW_ANGLE_MAX = 0;

constexpr double ARM_ONE_LENGTH = 40;
constexpr double ARM_TWO_LENGTH = 40;
constexpr double ARM_THREE_LENGTH = 10;
constexpr double phi = 0; // It can be 0 to pi/2 (90)
constexpr double ARM_POSITION_TOLERANCE = 3;
constexpr double ARM_SHOULDER_SPEED = 0.35;
constexpr double ARM_EBLOW_START_AT_ZERO_SPEED = 0;

//----------------------------------------------------------------------
constexpr double POT_RANGE = 185;
constexpr double VOLTAGE_LOW = 4.733886234;
constexpr double VOLTAGE_HIGH = 4.893798327;
constexpr double VOLTAGE_RANGE = VOLTAGE_HIGH - VOLTAGE_LOW;

constexpr int AMOUNT_OF_POT_QUEUE = 5;

constexpr double ARM_SPEED_LIMMIT = 0.45;
//constexpr double ARM_SPEED_LIMMIT = 0.50;


constexpr double ARM_ANGLE_RANGE = 0.052;
constexpr double ARM_SWITCH = 15;

constexpr double CLAW_INTAKE_POWER = 0.275;
constexpr double CLAW_OUTAKE_POWER = -0.55;

constexpr double WHEEL_CIRCUMFERENCE= 0;
constexpr int SIGNALS_PER_REVOLUTION = 2;
constexpr int ENCODER_TICKS_PER_INCH = 160;
constexpr double AUTO_SPEED = 0.4;

constexpr double AUTO_DISTANCE_TURN = 12;  // it was 15,  12 makes it turn 90 degrees 5
constexpr double AUTO_DISTANCE_FORWARD = 126;
constexpr double AUTO_AFTER_TURN = 2;

#endif /* SRC_CONSTANTS_H_ */
