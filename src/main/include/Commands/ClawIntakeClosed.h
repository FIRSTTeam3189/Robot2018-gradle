#ifndef ClawIntakeClosed_H
#define ClawIntakeClosed_H

#include "../CommandBase.h"

class ClawIntakeClosed : public CommandBase {
public:
	ClawIntakeClosed();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClawIntake_H
