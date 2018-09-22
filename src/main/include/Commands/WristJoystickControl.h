#ifndef ControlWinchwithJoystick_H
#define ControlWinchwithJoystick_H

#include "../CommandBase.h"

class WinchJoystickControl : public CommandBase {
public:
	WinchJoystickControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ControlWinchwithJoystick_H
