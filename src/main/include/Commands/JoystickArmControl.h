#ifndef JoystickArmControl_H
#define JoystickArmControl_H

#include "../CommandBase.h"

class JoystickArmControl : public CommandBase {
public:
	JoystickArmControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // JoystickArmControl_H
