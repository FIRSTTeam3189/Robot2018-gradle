#ifndef OI_H_
#define OI_H_

#include <Buttons/JoystickButton.h>
#include <Joystick.h>

class OI {
public:
	OI();
	double GetLeftY();
	double GetRightY();
	double GetCoPilotY();
	bool GetRight1Button();
	void InitilizeOI();


private:
	frc::Joystick left { 0 };
	frc::Joystick right { 1 };
	frc::Joystick copilot { 2 };

	frc::JoystickButton* copilot_1;
	frc::JoystickButton* copilot_2;
	frc::JoystickButton* copilot_3;
	frc::JoystickButton* copilot_4;
	frc::JoystickButton* copilot_5;
	frc::JoystickButton* copilot_6;
	frc::JoystickButton* copilot_7;
	frc::JoystickButton* copilot_8;
	frc::JoystickButton* copilot_9;
	frc::JoystickButton* copilot_10;
	frc::JoystickButton* copilot_11;
	frc::JoystickButton* left_1;
	frc::JoystickButton* right_1;
	frc::JoystickButton* right_2;
	frc::JoystickButton* right_3;
	frc::JoystickButton* right_7;
	frc::JoystickButton* right_8;
	frc::JoystickButton* right_9;
	frc::JoystickButton* right_10;

	frc::JoystickButton* leftTwo;
	frc::JoystickButton* moveArm;

};

#endif  // OI_H_
