#ifndef ClawIntake_H
#define ClawIntake_H

#include "../CommandBase.h"

class ClawIntake : public CommandBase {
public:
	ClawIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClawIntake_H
